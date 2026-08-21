// SPDX-FileCopyrightText: 2025-2026 Yu-Sheng Lin <johnjohnlys@gmail.com>
// SPDX-FileCopyrightText: 2025-2026 Yoda Lee <lc85301@gmail.com>
// SPDX-License-Identifier: MIT
// Project: libfstwriter
// Website: https://github.com/gtkwave/libfstwriter
// direct include
#include "fstcpp/fstcpp_writer.h"
// C system headers
// C++ standard library headers
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
// Other libraries' .h files.
#include <gtest/gtest.h>
// Your project's .h files.
#include "fstcpp/fstcpp_file.h"
#include "fstcpp/fstcpp_stream_write_helper.h"

using namespace std;

namespace fst {

// This test focus on testing the emit functions of Writer
// The name of this test is not unique
// but it is not a problem since Writer_*.test.cpp are individual
// binary files
class WriterTest : public ::testing::Test {
protected:
	// For testing set(Up)Scope/createVar
	// We call Writer API and get the buffer content
	// without inspecting the internal state of Writer
	static const string getHierarchyBuffer(Writer &writer) {
		return string(
			reinterpret_cast<const char *>(writer.m_hierarchy_buffer_.data()),
			writer.m_hierarchy_buffer_.size()
		);
	}

	static const string getGeometryBuffer(Writer &writer) {
		return string(
			reinterpret_cast<const char *>(writer.m_geometry_buffer_.data()),
			writer.m_geometry_buffer_.size()
		);
	}

	static const VariableInfo &getVariableInfo(Writer &writer, Handle handle) {
		return writer.m_value_change_data_.m_variable_infos.at(handle - 1);
	}

	static void writeHeader(const Header &h, ostream &os) { Writer::writeHeader_(h, os); }

	static void appendBlackout(Writer &Writer, std::ostream &os) { Writer.appendBlackout_(os); }
};

TEST_F(WriterTest, createVar) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	// Call createVar
	EXPECT_EQ(
		writer.createVar(
			fst::Hierarchy::VarType::VCD_WIRE,
			fst::Hierarchy::VarDirection::INPUT,
			/*bitwidth =*/8,
			"valid",
			/*alias handle =*/0
		),
		1u
	);

	// Second Call createVar
	EXPECT_EQ(
		writer.createVar(
			fst::Hierarchy::VarType::VCD_PORT,
			fst::Hierarchy::VarDirection::OUTPUT,
			/*bitwidth =*/5566,
			"ready",
			/*alias handle =*/0
		),
		2u
	);

	// Get the hierarchy buffer content
	const string buf{getHierarchyBuffer(writer)};
	// expected: Type, Direction, Name, bitwidth, Alias Handle
	// FIXME: in fstapi.c:2598 it writes len, zero, zero for normal variable this may be a bug
	const string expected =
		"\x10\x01valid\x00\x08\x00"s
		"\x12\x02ready\x00\xbe\x2b\x00"s;
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, createVarAlias) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	// Call createVar
	EXPECT_EQ(
		writer.createVar(
			fst::Hierarchy::VarType::VCD_WIRE,
			fst::Hierarchy::VarDirection::INPUT,
			/*bitwidth =*/1,
			"clk",
			/*alias handle =*/0
		),
		1u
	);

	// Second Call createVar
	EXPECT_EQ(
		writer.createVar(
			fst::Hierarchy::VarType::VCD_PORT,
			fst::Hierarchy::VarDirection::OUTPUT,
			/*bitwidth =*/0xd,  // don't care
			"aliasclk",
			/*alias handle =*/1
		),
		1u
	);

	// Get the hierarchy buffer content
	const string buf{getHierarchyBuffer(writer)};
	// expected: Type, Direction, Name, bitwidth, Alias Handle
	// FIXME: in fstapi.c:2598 it writes len, zero, zero for normal variable this may be a bug
	const string expected =
		"\x10\x01"
		"clk\x00\x01\x00"s
		"\x12\x02"
		"aliasclk\x00\x0d\x01"s;
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, createAliasOutOfRange) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	// Call createVar
	EXPECT_EQ(
		writer.createVar(
			fst::Hierarchy::VarType::VCD_WIRE,
			fst::Hierarchy::VarDirection::INPUT,
			/*bitwidth =*/16,
			"mode",
			/*alias handle =*/0
		),
		1u
	);

	// Get the hierarchy buffer content
	const string buf{getHierarchyBuffer(writer)};
	// expected: Type, Direction, Name, bitwidth, Alias Handle
	// FIXME: in fstapi.c:2598 it writes len, zero, zero for normal variable this may be a bug
	const string expected{"\x10\x01mode\x00\x10\x00"s};
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, Scope) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	// set Scope
	writer.setScope(
		fst::Hierarchy::ScopeType::VCD_MODULE,
		"top",
		"component"
	);  // TODO: what is this?
	writer.upscope();

	// Get the hierarchy buffer content
	const string buf{getHierarchyBuffer(writer)};
	// expected: Scope Type, Name, component, Upscope
	const string expected =
		"\xfe\x00top\x00"
		"component\x00"
		"\xff"s;
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, createEnumTable_NoEscape_Padding) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	// Call createEnumTable
	writer.createEnumTable(
		"E1 Hello World",
		3,  // test padding
		{{"A", "0"}, {"B", "001"}, {"C", "1101"}}
	);
	// Get the hierarchy buffer content
	const string buf{getHierarchyBuffer(writer)};
	const string expected = (
		// AttrBegin->Misc->EnumTable
		"\xfc\x00\x07"
		// enum name
		"E1 Hello World "
		// number of entries (in string!)
		"3 "
		// keys
		"A B C "
		// values; padding to at least 3 bytes
		"000 001 1101\x00"
		// LEB128 of 1
		"\x01"s
	);
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, createEnumTable_Escape_NoPadding) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	writer.createEnumTable(
		"E2.hello.world",  // test escape
		0,                 // test no padding
		{
			{"\a", "000"},
			{"\b", "001"},
			{"\f", "010"},
			{"\n", "011"},
			{"\r", "100"},
			{"\t", "101"},
			{"\v", "110"},
			{"\\", "111"},
			{"?", "1000"},
			{"\'", "1001"},
			{"\"", "1010"},
			{"\321", "1011"},
		}
	);

	// Get the hierarchy buffer content
	const string buf{getHierarchyBuffer(writer)};
	const string expected = (
		// AttrBegin->Misc->EnumTable
		"\xfc\x00\x07"
		// enum name; escaped
		"E2.hello.world "
		// number of entries (in string!)
		"12 "
		// keys
		R"(\a \b \f \n \r \t \v \\ \? \' \" \321 )"
		// values; no padding
		"000 001 010 011 100 101 110 111 1000 1001 1010 1011\x00"
		// LEB128 of 1
		"\x01"s
	);
	EXPECT_EQ(buf.size(), expected.size());
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, createEnumTableRef) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	writer.emitEnumTableRef((0x12 << 7) | 0x34);
	const string buf{getHierarchyBuffer(writer)};
	const string expected = (
		// AttrBegin->Misc->EnumTableRef
		"\xFC\x00\x07"
		// null terminated empty string
		"\0"
		// LEB128 of 0x12<<7 | 0x34
		"\xB4\x12"s
	);
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, createVarVcdReal) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	// Call createVar with eVcdReal
	EXPECT_EQ(
		writer.createVar(
			fst::Hierarchy::VarType::VCD_REAL,
			fst::Hierarchy::VarDirection::INPUT,
			/*bitwidth =*/0,  // bitwidth is ignored for real
			"real_val",
			/*alias handle =*/0
		),
		1u
	);

	// Get the hierarchy buffer content
	const string buf{getHierarchyBuffer(writer)};
	// For eVcdReal, bitwidth should be encoded as 8 bytes (64 bits)
	// Type: 0x1a, Direction: 0x01, Name: "real_val", bitwidth: 0x08,  Alias: 0x00
	const string expected{"\x03\x01real_val\x00\x08\x00"s};
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, createVarSvShortreal) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	const Handle handle{writer.createVar(
		fst::Hierarchy::VarType::SV_SHORTREAL,
		fst::Hierarchy::VarDirection::INPUT,
		/*bitwidth =*/32,
		"shortreal_val",
		/*alias handle =*/0
	)};
	EXPECT_EQ(handle, 1u);

	// Preserve the 32-bit shortreal width in the hierarchy.
	const string hierarchy_buf{getHierarchyBuffer(writer)};
	const string hierarchy_expected{"\x1d\x01shortreal_val\x00\x20\x00"s};
	EXPECT_EQ(hierarchy_buf, hierarchy_expected);

	// FST stores real values as doubles, including shortreal values promoted to double.
	const string geometry_buf{getGeometryBuffer(writer)};
	EXPECT_EQ(geometry_buf, "\x00"s);
	const VariableInfo &variable_info{getVariableInfo(writer, handle)};
	EXPECT_TRUE(variable_info.is_real());
	EXPECT_EQ(variable_info.bitwidth(), 8u);
}

TEST_F(WriterTest, GeometryBufferNormalVar) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	EXPECT_EQ(
		writer.createVar(
			fst::Hierarchy::VarType::VCD_WIRE,
			fst::Hierarchy::VarDirection::INPUT,
			/*bitwidth =*/15,
			"data",
			/*alias handle =*/0
		),
		1u
	);
	const string buf{getGeometryBuffer(writer)};
	const string expected{"\x0f"s};
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, GeometryBufferRealVar) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	EXPECT_EQ(
		writer.createVar(
			fst::Hierarchy::VarType::VCD_REAL,
			fst::Hierarchy::VarDirection::INPUT,
			/*bitwidth =*/0,
			"real_data",
			/*alias handle =*/0
		),
		1u
	);
	const string buf{getGeometryBuffer(writer)};
	const string expected{"\x00"s};
	EXPECT_EQ(buf, expected);
}

TEST_F(WriterTest, GeometryBufferZerobitwidthVar) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	EXPECT_EQ(
		writer.createVar(
			fst::Hierarchy::VarType::VCD_WIRE,
			fst::Hierarchy::VarDirection::INPUT,
			/*bitwidth =*/0,
			"zero",
			/*alias handle =*/0
		),
		1u
	);
	const string buf{getGeometryBuffer(writer)};
	// leb128 encoding of 0xffffffff
	const string expected{"\xFF\xFF\xFF\xFF\x0F"s};
	EXPECT_EQ(buf, expected);
}

////////////////////////////////////////////////
// Tests for Blackout (Disabled since emitDumpActive is not implemented yet)
////////////////////////////////////////////////
TEST_F(WriterTest, DISABLED_WriteBlackout_Short) {
	Writer writer;
	writer.setWriterPackType(WriterPackType::NO_COMPRESSION);
	// 1. Blackout between 10 to 20
	writer.emitTimeChange(10);
	// writer.emitDumpActive(false);
	writer.emitTimeChange(20);
	// writer.emitDumpActive(true);
	// Check output
	std::string ss(9, '\0');  // need some buffer to allow AppendBlackout to seek
	std::stringstream os(ss);
	appendBlackout(writer, os);
	std::string out = os.str();

	// Verify block type and size
	EXPECT_EQ(static_cast<uint8_t>(out[0]), static_cast<uint8_t>(BlockType::BLACKOUT));
	// block size field (8 bytes, big-endian) contains value of 13
	EXPECT_EQ(out.substr(1, 8), "\x00\x00\x00\x00\x00\x00\x00\x0d"s);
	// Next 5 bytes: 0x04 0x00 0x0a 0x01 0x14
	EXPECT_EQ(out.substr(9, 5), "\x04\x00\x0a\x01\x14"s);
}

////////////////////////////////////////////////
// Tests for writeHeader
////////////////////////////////////////////////
TEST_F(WriterTest, writeHeader) {
	// 1. setup Header struct manually with unique values
	Header h_struct{};
	h_struct.m_start_time = 10;
	h_struct.m_end_time = 1000;
	h_struct.m_writer_memory_use = 4096;
	h_struct.m_num_scopes = 5;
	h_struct.m_num_vars = 42;
	h_struct.m_num_handles = 100;
	h_struct.m_num_value_change_data_blocks = 3;
	h_struct.m_timezero = 123456789;
	h_struct.m_timescale = -9;
	h_struct.m_filetype = FileType::VERILOG;

	const string writer_name{"Verilator FST Writer Test"};
	// safe copy
	const size_t wlen{min(writer_name.size(), sizeof(h_struct.m_writer))};
	copy_n(writer_name.data(), wlen, h_struct.m_writer);
	if (wlen < sizeof(h_struct.m_writer)) h_struct.m_writer[wlen] = '\0';

	// Date must be exactly 25 chars (asctime format with \n)
	const string date_str{"Fri Dec 13 01:21:40 2024\n"};
	const size_t dlen{min(date_str.size(), sizeof(h_struct.m_date))};
	copy_n(date_str.data(), dlen, h_struct.m_date);
	// note: date is not null terminated in struct if full, but our test string
	// fits with null if we want
	if (dlen < sizeof(h_struct.m_date)) h_struct.m_date[dlen] = '\0';

	// 2. Call static writeHeader_ to stringstream
	ostringstream os;
	writeHeader(h_struct, os);

	// 3. Generate Golden Reference
	std::vector<uint8_t> expected_vec;
	StreamVectorWriteHelper h(expected_vec);

	// Helper to pad strings with nulls
	auto write_padded = [&](const string &s, size_t len) {
		size_t n = min(s.size(), len);
		if (n > 0) h.writeString(make_string_view_pair(s.data(), n));
		if (len > n) h.fill<char>(0, len - n);
	};

	h.writeBlockHeader(BlockType::HEADER, HeaderInfo::total_size)
		.writeUIntBE(uint64_t(10))    // start_time
		.writeUIntBE(uint64_t(1000))  // end_time
		.write(HeaderInfo::kEndianessMagicIdentifier)
		.writeUIntBE(uint64_t(4096))  // Writer_memory_use
		.writeUIntBE(uint64_t(5))     // num_scopes
		.writeUIntBE(uint64_t(42))    // num_vars
		.writeUIntBE(uint64_t(100))   // num_handles
		.writeUIntBE(uint64_t(3))     // num_value_change_data_blocks
		.writeUIntBE(int8_t(-9));     // timescale

	write_padded(writer_name, sizeof(h_struct.m_writer));
	write_padded(date_str, sizeof(h_struct.m_date));

	h.fill<char>(0, HeaderInfo::Size::reserved)                // reserved
		.writeUIntBE(static_cast<uint8_t>(FileType::VERILOG))  // filetype (default)
		.writeUIntBE(int64_t(123456789));                      // timezero

	// 4. Compare
	// Since stream includes binary 0s, we compare underlying strings
	std::string expected_str(expected_vec.begin(), expected_vec.end());
	EXPECT_EQ(os.str().size(), expected_str.size());
	EXPECT_EQ(os.str(), expected_str);
}

}  // namespace fst
