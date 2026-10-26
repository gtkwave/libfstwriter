// SPDX-License-Identifier: MIT
#include "integration_test/fst_block_compare.h"

#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <left.fst> <right.fst>\n";
		return 1;
	}
	std::ifstream left(argv[1], std::ios::binary), right(argv[2], std::ios::binary);
	if (!left || !right) {
		std::cerr << "Cannot open " << (!left ? argv[1] : argv[2]) << '\n';
		return 1;
	}
	return fst_test::compareBlocks(left, argv[1], right, argv[2], std::cerr) ? 0 : 1;
}
