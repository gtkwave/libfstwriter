// SPDX-FileCopyrightText: 2025-2026 Yu-Sheng Lin <johnjohnlys@gmail.com>
// SPDX-License-Identifier: MIT
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include "gtkwave/fstapi.h"

using namespace std;

int main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <output.fst>" << endl;
		return 1;
	}

	fstWriterContext *ctx = fstWriterCreate(argv[1], 1);
	assert(ctx != nullptr);

	fstWriterSetPackType(ctx, FST_WR_PT_LZ4);
	fstWriterSetDate(ctx, "Sat Jan 01 01:23:45 2000\x0a");
	fstWriterSetVersion(ctx, "Verilator");
	fstWriterSetTimescale(ctx, -9);  // 1ns

	// Set Top Scope
	fstWriterSetScope(ctx, FST_ST_VCD_MODULE, "top", "top");

	// 1. Single-bit variables
	fstHandle wire_1bit_a =
		fstWriterCreateVar(ctx, FST_VT_VCD_WIRE, FST_VD_INPUT, 1, "wire_1bit_a", 0);
	fstHandle wire_1bit_b =
		fstWriterCreateVar(ctx, FST_VT_VCD_WIRE, FST_VD_OUTPUT, 1, "wire_1bit_b", 0);

	// 2. Multi-bit variables (<= 32 bits)
	fstHandle bus_8bit =
		fstWriterCreateVar(ctx, FST_VT_VCD_WIRE, FST_VD_IMPLICIT, 8, "bus_8bit", 0);
	fstHandle bus_10bit =
		fstWriterCreateVar(ctx, FST_VT_VCD_WIRE, FST_VD_IMPLICIT, 10, "bus_10bit", 0);
	fstHandle bus_32bit =
		fstWriterCreateVar(ctx, FST_VT_VCD_WIRE, FST_VD_IMPLICIT, 32, "bus_32bit", 0);

	// Submodule Scope
	fstWriterSetScope(ctx, FST_ST_VCD_MODULE, "sub_module", "sub_module");

	// 3. 64-bit variable
	fstHandle bus_64bit =
		fstWriterCreateVar(ctx, FST_VT_VCD_WIRE, FST_VD_IMPLICIT, 64, "bus_64bit", 0);

	// 4. Wide variable (> 64 bits, e.g., 128 bits)
	fstHandle bus_128bit =
		fstWriterCreateVar(ctx, FST_VT_VCD_WIRE, FST_VD_IMPLICIT, 128, "bus_128bit", 0);

	fstWriterSetUpscope(ctx);  // Back to top
	fstWriterSetUpscope(ctx);  // Close top scope

	// ==================== TIME 0: Initial states ====================
	fstWriterEmitTimeChange(ctx, 0);

	// 1-bit: initial X / Z using string emit
	fstWriterEmitValueChange(ctx, wire_1bit_a, "x");
	fstWriterEmitValueChange(ctx, wire_1bit_b, "z");

	// 8-bit: initial state
	fstWriterEmitValueChange(ctx, bus_8bit, "01xz01xz");

	// 10-bit: all Z
	fstWriterEmitValueChange(ctx, bus_10bit, "zzzzzzzzzz");

	// 32-bit: mixed 0, 1, X, Z pattern
	fstWriterEmitValueChange(ctx, bus_32bit, "zzzzzzzzxxxxxxxx1111111100000000");

	// 64-bit: mixed X and Z
	fstWriterEmitValueChange(
		ctx, bus_64bit, "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
	);

	// 128-bit: mixed string pattern
	fstWriterEmitValueChange(
		ctx,
		bus_128bit,
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx11111111111111111111111111111111"
		"00000000000000000000000000000000zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
	);

	// ==================== TIME 10: State transitions ====================
	fstWriterEmitTimeChange(ctx, 10);

	// 1-bit: transition X -> 1, Z -> 0
	fstWriterEmitValueChange64(ctx, wire_1bit_a, 1, 1);
	fstWriterEmitValueChange64(ctx, wire_1bit_b, 1, 0);

	// 8-bit: transition to pattern 01xz01xz
	fstWriterEmitValueChange(ctx, bus_8bit, "01xz01xz");

	// 10-bit: transition Z -> binary 0x2A5 using 64-bit emit
	fstWriterEmitValueChange64(ctx, bus_10bit, 10, 0x2A5ULL);

	// 32-bit: transition with all X
	fstWriterEmitValueChange(ctx, bus_32bit, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

	// 64-bit: transition using 64-bit emit
	fstWriterEmitValueChange64(ctx, bus_64bit, 64, 0x1234567890ABCDEFULL);

	// 128-bit: transition using Vec32 (4 uint32_t words)
	uint32_t val128_bin[4] = {0x89ABCDEF, 0x01234567, 0x76543210, 0xFEDCBA98};
	fstWriterEmitValueChangeVec32(ctx, bus_128bit, 128, val128_bin);

	// ==================== TIME 20: More transitions ====================
	fstWriterEmitTimeChange(ctx, 20);

	// 1-bit: 1 -> Z, 0 -> X
	fstWriterEmitValueChange(ctx, wire_1bit_a, "z");
	fstWriterEmitValueChange(ctx, wire_1bit_b, "x");

	// 8-bit: all 0s
	fstWriterEmitValueChange64(ctx, bus_8bit, 8, 0x00ULL);

	// 128-bit: all X
	fstWriterEmitValueChange(
		ctx,
		bus_128bit,
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
		"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
	);

	// ==================== TIME 30: All Z on wide buses ====================
	fstWriterEmitTimeChange(ctx, 30);

	// 128-bit: set all 128 bits to Z
	fstWriterEmitValueChange(
		ctx,
		bus_128bit,
		"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
		"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
	);

	// ==================== TIME 40: End simulation ====================
	fstWriterEmitTimeChange(ctx, 40);

	fstWriterClose(ctx);
	cout << "FST trace generated successfully." << endl;
	return 0;
}
