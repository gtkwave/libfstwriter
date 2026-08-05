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

TEST(VariableInfoTest, writeInitialVerilog_ScalarInt) {
	VariableInfo vi{4};
	const uint32_t val[] = {0b1010, 0b0011};
	vi.emitValueChange(0, val, fst::EncodingType::VERILOG);
	vi.keepOnlyTheLatestValue();
	vector<uint8_t> buf{};
	vi.dumpInitialBits(buf);
	EXPECT_EQ(V2S(buf), "10xz");
}

TEST(VariableInfoTest, writeInitialVerilog_ScalarInt64) {
	VariableInfo vi{64};
	const uint64_t val[] = {0b1010, 0b0011};
	vi.emitValueChange(0, val, fst::EncodingType::VERILOG);
	vi.keepOnlyTheLatestValue();
	vector<uint8_t> buf{};
	vi.dumpInitialBits(buf);
	EXPECT_EQ(V2S(buf), std::string(60, '0') + "10xz");
}

TEST(VariableInfoTest, writeInitialVerilog_LongInt) {
	VariableInfo vi{70};
	const uint32_t val[] = {0, 0, 0b1010, 0b0011, 0, 0};
	vi.emitValueChange(0, val, fst::EncodingType::VERILOG);
	vi.keepOnlyTheLatestValue();
	vector<uint8_t> buf{};
	vi.dumpInitialBits(buf);
	const string expected{string(34, '0') + "10xz" + string(32, '0')};
	EXPECT_EQ(V2S(buf), expected);
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
TEST(VariableInfoTest, dumpValueChange_ScalarInt_1bit_Verilog) {
	VariableInfo vi{1};
	uint32_t val[] = {0, 0};
	vi.emitValueChange(1, val, fst::EncodingType::VERILOG);
	val[0] = 1;
	vi.emitValueChange(2, val, fst::EncodingType::VERILOG);
	val[1] = 1;
	vi.emitValueChange(3, val, fst::EncodingType::VERILOG);
	val[0] = 0;
	vi.emitValueChange(4, val, fst::EncodingType::VERILOG);
	val[1] = 0;
	vi.emitValueChange(5, val, fst::EncodingType::VERILOG);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	// Encoding time_index_delta << 2 | (bit << 1) | 0 in binary mode
	// (1-0) << 2 | 0b00
	// (2-1) << 2 | 0b10
	// (3-2) << 4 | 0b01
	// (4-3) << 4 | 0b11
	// (5-4) << 2 | 0b00
	EXPECT_EQ(V2S(buf), "\x04\x06\x11\x13\x04"s);
}

TEST(VariableInfoTest, dumpValueChange_ScalarInt_2bit_Verilog) {
	VariableInfo vi{2};
	uint32_t val[] = {0, 0};
	vi.emitValueChange(1, val, fst::EncodingType::VERILOG);
	val[1] = 1;
	vi.emitValueChange(3, val, fst::EncodingType::VERILOG);
	val[1] = 3;
	vi.emitValueChange(5, val, fst::EncodingType::VERILOG);
	val[1] = 2;
	vi.emitValueChange(7, val, fst::EncodingType::VERILOG);
	val[0] = 1;
	vi.emitValueChange(10, val, fst::EncodingType::VERILOG);
	val[1] = 3;
	vi.emitValueChange(11, val, fst::EncodingType::VERILOG);
	val[1] = 1;
	vi.emitValueChange(13, val, fst::EncodingType::VERILOG);
	val[1] = 0;
	vi.emitValueChange(15, val, fst::EncodingType::VERILOG);
	val[0] = 3;
	vi.emitValueChange(17, val, fst::EncodingType::VERILOG);
	val[1] = 1;
	vi.emitValueChange(20, val, fst::EncodingType::VERILOG);
	val[1] = 3;
	vi.emitValueChange(21, val, fst::EncodingType::VERILOG);
	val[1] = 2;
	vi.emitValueChange(23, val, fst::EncodingType::VERILOG);
	val[0] = 2;
	vi.emitValueChange(25, val, fst::EncodingType::VERILOG);
	val[1] = 3;
	vi.emitValueChange(27, val, fst::EncodingType::VERILOG);
	val[1] = 1;
	vi.emitValueChange(30, val, fst::EncodingType::VERILOG);
	val[1] = 0;
	vi.emitValueChange(31, val, fst::EncodingType::VERILOG);
	val[0] = 0;
	vi.emitValueChange(33, val, fst::EncodingType::VERILOG);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	// 1. Varint encoding of (Time_index_delta << 1) | 1
	// 2. Data encoding as chars
	EXPECT_EQ(buf, (std::vector<uint8_t>{0x03, '0', '0', 0x05, '0', 'z', 0x05, 'z', 'z',
										 0x05, 'z', '0', 0x07, 'z', '1', 0x03, 'z', 'x',
										 0x05, '0', 'x', 0x05, '0', '1', 0x05, '1', '1',
										 0x07, '1', 'x', 0x03, 'x', 'x', 0x05, 'x', '1',
										 0x05, 'x', '0', 0x05, 'x', 'z', 0x07, '1', 'z',
										 0x03, '1', '0', 0x05, '0', '0'}));
}

TEST(VariableInfoTest, dumpValueChange_ScalarInt_10bit_Verilog) {
	VariableInfo vi{10};
	uint64_t val[] = {0, 0};
	vi.emitValueChange(1, val, fst::EncodingType::VERILOG);
	val[0] = 1;
	vi.emitValueChange(3, val, fst::EncodingType::VERILOG);
	val[1] = 5;
	vi.emitValueChange(5, val, fst::EncodingType::VERILOG);
	val[0] = 37;
	vi.emitValueChange(7, val, fst::EncodingType::VERILOG);
	val[1] = 0;
	vi.emitValueChange(8, val, fst::EncodingType::VERILOG);
	val[0] = 0;
	vi.emitValueChange(10, val, fst::EncodingType::VERILOG);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	// 1. Varint encoding of Time_index_delta << 1 | 1 since it contains only 0 and 1
	// 2. data encoded as raw bits,aligned with MSB and packed into a whole number of bytes
	EXPECT_EQ(buf, (std::vector<uint8_t>{0x03, '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
										 0x05, '0', '0', '0', '0', '0', '0', '0', '0', '0', '1',
										 0x05, '0', '0', '0', '0', '0', '0', '0', 'z', '0', 'x',
										 0x05, '0', '0', '0', '0', '1', '0', '0', 'x', '0', 'x',
										 0x03, '0', '0', '0', '0', '1', '0', '0', '1', '0', '1',
										 0x05, '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}));
}

TEST(VariableInfoTest, dumpValueChange_ScalarInt_64bit_Verilog) {
	VariableInfo vi{64};
	const uint64_t val[] = {5, 3};
	vi.emitValueChange(1, val, fst::EncodingType::VERILOG);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	// 1. Varint encoding of Time_index_delta << 1 | 1 since it contains only 0 and 1
	// 2. data encoded as raw bits,aligned with MSB and packed into a whole number of bytes
	EXPECT_EQ(V2S(buf), "\x03"s + std::string(61, '0') + "1zx");
}

TEST(VariableInfoTest, dumpValueChange_ScalarInt_64bit_Verilog2) {
	VariableInfo vi{64};
	const uint32_t val[] = {5, 3, 0, 0};
	vi.emitValueChange(1, val, fst::EncodingType::VERILOG);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	// 1. Varint encoding of Time_index_delta << 1 | 1 since it contains only 0 and 1
	// 2. data encoded as raw bits,aligned with MSB and packed into a whole number of bytes
	EXPECT_EQ(V2S(buf), "\x03"s + std::string(61, '0') + "1zx");
}

TEST(VariableInfoTest, dumpValueChange_LongInt_Verilog) {
	VariableInfo vi{68};
	uint32_t val[] = {0, 0, 0, 0, 0, 0};
	vi.emitValueChange(2, val, fst::EncodingType::VERILOG);
	val[2] = 0b0101;
	val[3] = 0b0011;
	vi.emitValueChange(5, val, fst::EncodingType::VERILOG);
	vector<uint8_t> buf{};
	vi.dumpValueChanges(buf);
	std::vector<uint8_t> result(138, '0');
	result[0] = 0x05;
	result[69] = 0x07;
	result[105] = 'x';
	result[104] = 'z';
	result[103] = '1';
	EXPECT_EQ(buf, result);
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
