// SPDX-License-Identifier: MIT
#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <istream>
#include <map>
#include <ostream>
#include <vector>

namespace fst_test {

struct Block {
	std::streamoff offset;
	uint64_t length;
};
using Blocks = std::map<unsigned, std::vector<Block>>;

inline bool indexBlocks(std::istream &input, const char *name, Blocks &blocks, std::ostream &error) {
	input.seekg(0, std::ios::end);
	const std::streamoff size = input.tellg();
	if (!input || size <= 0) {
		error << name << ": empty or unreadable file\n";
		return false;
	}
	std::streamoff offset = 0;
	while (offset < size) {
		if (size - offset < 9) {
			error << name << ": incomplete block header at offset " << offset << '\n';
			return false;
		}
		input.seekg(offset);
		std::array<unsigned char, 9> header{};
		input.read(reinterpret_cast<char *>(header.data()), header.size());
		if (!input) {
			error << name << ": cannot read block at offset " << offset << '\n';
			return false;
		}
		uint64_t length = 0;
		for (size_t i = 1; i < header.size(); ++i) length = (length << 8) | header[i];
		if (length < 8 || length > static_cast<uint64_t>(size - offset - 1)) {
			error << name << ": invalid block length " << length << " at offset " << offset << '\n';
			return false;
		}
		blocks[header[0]].push_back({offset, length});
		offset += static_cast<std::streamoff>(length) + 1;
	}
	return true;
}

inline bool compareBlocks(
	std::istream &left, const char *left_name, std::istream &right, const char *right_name,
	std::ostream &error
) {
	Blocks left_blocks, right_blocks;
	if (!indexBlocks(left, left_name, left_blocks, error) ||
		!indexBlocks(right, right_name, right_blocks, error)) return false;

	// Include types present only on the right so extra blocks cannot be missed.
	for (const auto &entry : right_blocks) left_blocks[entry.first];
	std::array<char, 65536> left_bytes{}, right_bytes{};
	for (const auto &entry : left_blocks) {
		const auto &a = entry.second;
		const auto &b = right_blocks[entry.first];
		if (a.size() != b.size()) {
			error << "block type " << entry.first << ": count differs (" << left_name << ": "
				<< a.size() << ", " << right_name << ": " << b.size() << ")\n";
			return false;
		}
		for (size_t i = 0; i < a.size(); ++i) {
			if (a[i].length != b[i].length) {
				error << "block type " << entry.first << ", occurrence " << i + 1
					<< ": length differs (" << a[i].length << " vs " << b[i].length << ")\n";
				return false;
			}
			left.seekg(a[i].offset);
			right.seekg(b[i].offset);
			uint64_t remaining = a[i].length + 1;
			uint64_t position = 0;
			while (remaining) {
				const auto count = static_cast<std::streamsize>(
					std::min<uint64_t>(remaining, left_bytes.size())
				);
				left.read(left_bytes.data(), count);
				right.read(right_bytes.data(), count);
				if (!left || !right) {
					error << "cannot read block type " << entry.first << ", occurrence " << i + 1 << '\n';
					return false;
				}
				const auto mismatch = std::mismatch(
					left_bytes.begin(), left_bytes.begin() + count, right_bytes.begin()
				);
				if (mismatch.first != left_bytes.begin() + count) {
					error << "block type " << entry.first << ", occurrence " << i + 1
						<< ": byte differs at block offset "
						<< position + (mismatch.first - left_bytes.begin()) << '\n';
					return false;
				}
				position += count;
				remaining -= count;
			}
		}
	}
	return true;
}

}  // namespace fst_test
