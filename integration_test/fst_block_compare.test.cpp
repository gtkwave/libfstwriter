// SPDX-License-Identifier: MIT
#include "integration_test/fst_block_compare.h"

#include <sstream>
#include <string>
#include <gtest/gtest.h>

namespace {

std::string block(unsigned type, const std::string &payload) {
	std::string result(9, '\0');
	result[0] = static_cast<char>(type);
	uint64_t length = payload.size() + 8;
	for (int i = 8; i > 0; --i) {
		result[i] = static_cast<char>(length & 0xff);
		length >>= 8;
	}
	return result + payload;
}

bool compare(const std::string &a, const std::string &b, std::string &message) {
	std::istringstream left(a), right(b);
	std::ostringstream error;
	const bool equal = fst_test::compareBlocks(left, "left", right, "right", error);
	message = error.str();
	return equal;
}

TEST(BlockCompare, IdenticalAndReorderedTypes) {
	const auto header = block(0, std::string("header\0bytes", 12));
	const auto geometry = block(3, "geometry");
	const auto hierarchy = block(6, "hierarchy");
	// Cross the comparison buffer boundary and exercise multi-byte lengths.
	const auto first = block(8, std::string(70000, 'a'));
	const auto second = block(8, "second");
	const auto a = header + geometry + hierarchy + first + second;
	const auto b = header + first + second + geometry + hierarchy;
	std::string message;
	EXPECT_TRUE(compare(a, a, message)) << message;
	EXPECT_TRUE(compare(a, b, message)) << message;
	EXPECT_TRUE(message.empty());
}

TEST(BlockCompare, RejectsChangedBytesAndSameTypeOrder) {
	std::string message;
	EXPECT_FALSE(compare(block(8, "first") + block(8, "other"),
		block(8, "other") + block(8, "first"), message));
	EXPECT_NE(message.find("block type 8, occurrence 1"), std::string::npos);
	EXPECT_NE(message.find("block offset 9"), std::string::npos);
	EXPECT_FALSE(compare(block(0, "a"), block(0, "b"), message));
	auto payload = std::string(70000, 'a');
	const auto original = block(8, payload);
	payload.back() = 'b';
	EXPECT_FALSE(compare(original, block(8, payload), message));
	EXPECT_NE(message.find("block offset 70008"), std::string::npos);
}

TEST(BlockCompare, RejectsDifferentLengthsAndCounts) {
	const auto header = block(0, "header");
	std::string message;
	EXPECT_FALSE(compare(header, block(0, "longer header"), message));
	EXPECT_NE(message.find("length differs"), std::string::npos);
	for (const auto &extra : {block(3, "geometry"), header}) {
		EXPECT_FALSE(compare(header, header + extra, message));
		EXPECT_NE(message.find("count differs"), std::string::npos);
		EXPECT_FALSE(compare(header + extra, header, message));
	}
}

TEST(BlockCompare, RejectsMalformedFilesOnEitherSide) {
	const auto valid = block(0, "header");
	auto too_short = block(8, "");
	too_short[8] = 7;
	std::string huge(9, static_cast<char>(0xff));
	for (const auto &bad : {std::string(), std::string("\0", 1),
		valid.substr(0, 8), valid.substr(0, valid.size() - 1),
		too_short, huge, valid + "trailing"}) {
		std::string message;
		EXPECT_FALSE(compare(bad, valid, message));
		EXPECT_NE(message.find("left:"), std::string::npos);
		EXPECT_FALSE(compare(valid, bad, message));
		EXPECT_NE(message.find("right:"), std::string::npos);
		if (!bad.empty()) {
			EXPECT_NE(message.find("offset"), std::string::npos);
		}
	}
}

}  // namespace
