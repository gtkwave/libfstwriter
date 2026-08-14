// SPDX-FileCopyrightText: 2025-2026 Yu-Sheng Lin <johnjohnlys@gmail.com>
// SPDX-FileCopyrightText: 2025-2026 Yoda Lee <lc85301@gmail.com>
// SPDX-License-Identifier: MIT
// Project: libfstwriter
// Website: https://github.com/gtkwave/libfstwriter
// direct include
#include "fstcpp/fstcpp_writer.cpp"
// C system headers
// C++ standard library headers
#include <cstring>
// Other libraries' .h files.
#include <gtest/gtest.h>
// Your project's .h files.

using namespace std;

static const string V2S(vector<uint8_t> &v) {
	return string{reinterpret_cast<const char *>(v.data()), v.size()};
}

namespace fst {

constexpr unsigned kDontCareBitWidth = 1234;

/////////////////////////////
// writeInitialBits
/////////////////////////////
TEST(VariableInfoTest, writeInitialBits_ScalarInt) {
	VariableInfo vi{4};
	vi.emitValueChange(0, 0b1010);
	vi.keepOnlyTheLatestValue();
	vector<uint8_t> buf{};
	vi.dumpInitialBits(buf);
	EXPECT_EQ(V2S(buf), "1010");
}

TEST(VariableInfoTest, writeInitialBits_LongInt) {
	VariableInfo vi{70};
	vi.emitValueChange(0, (1ULL << 63) | 1);
	vi.keepOnlyTheLatestValue();
	vector<uint8_t> buf{};
	vi.dumpInitialBits(buf);
	// Should be 70 bits: 1 at bit 63 and bit 0, rest are 0
	const string expected{string(6, '0') + "1" + string(62, '0') + "1"};
	EXPECT_EQ(V2S(buf), expected);
}

TEST(VariableInfoTest, writeInitialBits_Double) {
	VariableInfo vi{kDontCareBitWidth, true};
	vi.emitValueChange(0, 0x3ff0000000000000ULL);  // 1.0 in IEEE754
	vi.keepOnlyTheLatestValue();
	vector<uint8_t> buf{};
	vi.dumpInitialBits(buf);
	double val{};
	memcpy(&val, buf.data(), sizeof(double));
	EXPECT_DOUBLE_EQ(val, 1.0);
}
/////////////////////////////
// dumpValueChanges
/////////////////////////////
TEST(VariableInfoTest, dumpValueChange_ScalarInt_1bit_Binary) {
	VariableInfo vi{1};
	vi.emitValueChange(1, 0);
	vi.emitValueChange(2, 1);
	vi.emitValueChange(3, 0);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	// Encoding time_index_delta << 2 | (bit << 1) | 0 in binary mode
	// (1-0) << 2 | 0b00
	// (2-1) << 2 | 0b10
	// (3-2) << 2 | 0b00
	EXPECT_EQ(V2S(buf), "\x04\x06\x04"s);
}

TEST(VariableInfoTest, dumpValueChange_ScalarInt_2bit_Binary) {
	VariableInfo vi{2};
	vi.emitValueChange(1, 0);
	vi.emitValueChange(3, 1);
	vi.emitValueChange(5, 2);
	vi.emitValueChange(7, 3);
	vi.emitValueChange(10, 0);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	// 1. Varint encoding of (Time_index_delta << 1) | 0
	// 2. data encoded as raw bits,aligned with MSB and packed into a whole number of bytes
	EXPECT_EQ(V2S(buf), "\x02\x00\x04\x40\x04\x80\x04\xc0\x06\x00"s);
}

TEST(VariableInfoTest, dumpValueChange_ScalarInt_10bit_Binary) {
	VariableInfo vi{10};
	vi.emitValueChange(1, 0);
	vi.emitValueChange(3, 1);
	vi.emitValueChange(5, 2);
	vi.emitValueChange(7, 4);
	vi.emitValueChange(10, 8);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	// 1. Varint encoding of Time_index_delta << 1 | 1 since it contains only 0 and 1
	// 2. data encoded as raw bits,aligned with MSB and packed into a whole number of bytes
	EXPECT_EQ(
		V2S(buf),
		"\x02\x00\x00"
		"\x04\x00\x40"
		"\x04\x00\x80"
		"\x04\x01\x00"
		"\x06\x02\x00"s
	);
}

TEST(VariableInfoTest, dumpValueChange_ScalarInt_1bit_Verilog) {
	VariableInfo vi{1};
	uint32_t val0[2] = {0, 0};  // 0 -> '0'
	uint32_t val1[2] = {1, 0};  // 1 -> '1'
	uint32_t valX[2] = {0, 1};  // 2 -> 'X'
	uint32_t valZ[2] = {1, 1};  // 3 -> 'Z'

	vi.emitValueChange(1, val0, fst::EncodingType::VERILOG);
	vi.emitValueChange(2, val1, fst::EncodingType::VERILOG);
	vi.emitValueChange(3, valX, fst::EncodingType::VERILOG);
	vi.emitValueChange(4, valZ, fst::EncodingType::VERILOG);

	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);

	// Expected LEB128 encodings:
	// '0' (val=0): delta<<2 | (0<<1) | 0 -> (1<<2) | 0 = 4  (\x04)
	// '1' (val=1): delta<<2 | (1<<1) | 0 -> (1<<2) | 2 = 6  (\x06)
	// 'X' (val=2): delta<<4 | (0<<1) | 1 -> (1<<4) | 1 = 17 (\x11)
	// 'Z' (val=3): delta<<4 | (1<<1) | 1 -> (1<<4) | 3 = 19 (\x13)
	EXPECT_EQ(V2S(buf), "\x04\x06\x11\x13"s);
}

TEST(VariableInfoTest, dumpValueChange_ScalarInt_10bit_Verilog) {
	VariableInfo vi{10};

	uint32_t val10_xz[2];
	val10_xz[0] = 0b1010101010;                                   // Low bits (b0)
	val10_xz[1] = 0b1111100000;                                   // High bits (b1)
	vi.emitValueChange(1, val10_xz, fst::EncodingType::VERILOG);  // delta = 1

	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);

	// Expected encoding:
	// delta = 1 - 0 = 1.
	// has_non_binary = 1 (VERILOG encoding for bitwidth > 1).
	// LEB128( (1 << 1) | 1 ) = LEB128(3) = \x03
	// Then the characters are written literally into the stream: "zxzxz01010"
	EXPECT_EQ(V2S(buf), "\x03zxzxz01010"s);
}

TEST(VariableInfoTest, dumpValueChange_LongInt_Binary) {
	VariableInfo vi{68};
	vi.emitValueChange(2, 0);
	vi.emitValueChange(5, 0x1234567890abcdefULL);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	EXPECT_EQ(
		V2S(buf),
		"\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x06\x01\x23\x45\x67\x89\x0a\xbc\xde\xf0"s
	);
}

// LCOV_EXCL_START
TEST(VariableInfoTest, DISABLED_dumpValueChange_Double_Binary) {
	VariableInfo vi(kDontCareBitWidth, true);
	vi.emitValueChange(0, 0x3ff0000000000000ULL);  // 1.0 in IEEE754
	vector<uint8_t> buf;
	vi.dumpValueChanges(buf);
	FAIL() << "TODO";
}
// LCOV_EXCL_STOP

}  // namespace fst
