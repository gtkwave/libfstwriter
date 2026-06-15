// SPDX-FileCopyrightText: 2025-2026 Yu-Sheng Lin <johnjohnlys@gmail.com>
// SPDX-FileCopyrightText: 2025-2026 Yoda Lee <lc85301@gmail.com>
// SPDX-License-Identifier: MIT
// direct include
#include "gtkwave/fstapi.h"
// C system headers
// C++ standard library headers
#include <cstdlib>
#include <iostream>
#include <string>
// Other libraries' .h files.
// Your project's .h files.
#include "fstcpp/fstcpp_writer.h"
// #include "fstcpp/fstcpp_string_view.h"

using namespace std;

struct fstWriterContext {
	fst::Writer writer;
	fstWriterContext() = default;
	explicit fstWriterContext(const char *name) : writer(name) {}
};

extern "C" {

[[maybe_unused]]
static inline void NotImplementedWarning(const char *func_name) {
#ifndef FSTCPP_IGNORE_NO_EFFECT_API
	cerr << string(func_name) +
				(" is not implemented and ignored in fstcpp backend "
				 "(#define FSTCPP_IGNORE_NO_EFFECT_API and re-compile to suppress this warning)")
		 << endl;
#endif
}

[[maybe_unused]]
static inline void TODO(const char *func_name) {
	FST_FAIL_STRING(string(func_name) + " is a TODO");
}

// File open/close
fstWriterContext *fstWriterCreate(const char *name, int use_compressed_hier) {
	(void)use_compressed_hier;
	// allocate context which constructs writer via forwarding ctor
	return new fstWriterContext(name);
}

void fstWriterClose(fstWriterContext *ctx) {
	if (! ctx) return;
	ctx->writer.close();
	delete ctx;
}

void fstWriterFlushContext(fstWriterContext *ctx) {
	if (! ctx) return;
	ctx->writer.flushValueChangeData();
}

// Header related
void fstWriterSetTimescale(fstWriterContext *ctx, int ts) {
	if (! ctx) return;
	ctx->writer.setTimecale(static_cast<int8_t>(ts));
}

void fstWriterSetTimescaleFromString(fstWriterContext *ctx, const char *s) {
	if (! ctx or ! s) return;
	// Just use the original parsing logic from fstapi.c
	int mat = 0;
	int seconds_exp = -9;
	int tv = atoi(s);
	const char *pnt = s;

	while (*pnt) {
		switch (*pnt) {
			// clang-format off
			case 'm': seconds_exp = -3; mat = 1; break;
			case 'u': seconds_exp = -6; mat = 1; break;
			case 'n': seconds_exp = -9; mat = 1; break;
			case 'p': seconds_exp = -12; mat = 1; break;
			case 'f': seconds_exp = -15; mat = 1; break;
			case 'a': seconds_exp = -18; mat = 1; break;
			case 'z': seconds_exp = -21; mat = 1; break;
			case 's': seconds_exp = 0; mat = 1; break;
			default: break;
			// clang-format on
		}

		if (mat) break;
		pnt++;
	}

	if (tv == 10) {
		seconds_exp++;
	} else if (tv == 100) {
		seconds_exp += 2;
	}

	fstWriterSetTimescale(ctx, seconds_exp);
}

void fstWriterSetTimezero(fstWriterContext *ctx, int64_t tim) {
	if (! ctx) return;
	ctx->writer.setTimezero(tim);
}

void fstWriterSetVersion(fstWriterContext *ctx, const char *vers) {
	if (! ctx) return;
	ctx->writer.setWriter(vers);
}

void fstWriterSetDate(fstWriterContext *ctx, const char *dat) {
	if (! ctx) return;
	ctx->writer.setDate(dat);
}

// Hierarchy related
void fstWriterSetScope(
	fstWriterContext *ctx, enum fstScopeType scopetype, const char *scopename, const char *scopecomp
) {
	if (! ctx) return;
	ctx->writer.setScope(static_cast<fst::Hierarchy::ScopeType>(scopetype), scopename, scopecomp);
}

void fstWriterSetUpscope(fstWriterContext *ctx) {
	if (! ctx) return;
	ctx->writer.upscope();
}

fstHandle fstWriterCreateVar(
	fstWriterContext *ctx,
	enum fstVarType vt,
	enum fstVarDir vd,
	uint32_t bitwidth,
	const char *nam,
	fstHandle aliasHandle
) {
	if (! ctx) return 0;
	return ctx->writer.createVar(
		static_cast<fst::Hierarchy::VarType>(vt),
		static_cast<fst::Hierarchy::VarDirection>(vd),
		bitwidth,
		nam,
		aliasHandle
	);
}

fstHandle fstWriterCreateVar2(
	fstWriterContext *ctx,
	enum fstVarType vt,
	enum fstVarDir vd,
	uint32_t bitwidth,
	const char *nam,
	fstHandle aliasHandle,
	const char *type,
	enum fstSupplementalVarType svt,
	enum fstSupplementalDataType sdt
) {
	(void)ctx;
	(void)vt;
	(void)vd;
	(void)bitwidth;
	(void)nam;
	(void)aliasHandle;
	(void)type;
	(void)svt;
	(void)sdt;
	TODO(__func__);
	return 0;
}

void fstWriterSetValueList(fstWriterContext *ctx, const char *vl) {
	(void)ctx;
	(void)vl;
	TODO(__func__);
}

fstEnumHandle fstWriterCreateEnumTable(
	fstWriterContext *ctx,
	const char *name,
	uint32_t elem_count,
	unsigned int min_valbits,
	const char **literal_arr,
	const char **val_arr
) {
	if (! ctx or ! name or ! literal_arr or ! val_arr) return 0;
	vector<pair<fst::string_view_pair, fst::string_view_pair>> literal_val_arr;
	literal_val_arr.reserve(elem_count);
	for (uint32_t i = 0; i < elem_count; ++i) {
		literal_val_arr.emplace_back(
			fst::make_string_view_pair(literal_arr[i]), fst::make_string_view_pair(val_arr[i])
		);
	}
	return ctx->writer.createEnumTable(
		fst::make_string_view_pair(name), min_valbits, literal_val_arr
	);
}

void fstWriterEmitEnumTableRef(fstWriterContext *ctx, fstEnumHandle handle) {
	if (! ctx) return;
	ctx->writer.emitEnumTableRef(handle);
}

void fstWriterSetAttrBegin(
	fstWriterContext *ctx,
	enum fstAttrType attrtype,
	int subtype,
	const char *attrname,
	uint64_t arg
) {
	if (! ctx) return;
	ctx->writer.setAttrBegin(
		static_cast<fst::Hierarchy::AttrType>(attrtype),
		static_cast<fst::Hierarchy::AttrSubType>(subtype),
		fst::make_string_view_pair(attrname),
		arg
	);
}

void fstWriterSetAttrEnd(fstWriterContext *ctx) {
	if (! ctx) return;
	ctx->writer.setAttrEnd();
}

void fstWriterSetComment(fstWriterContext *ctx, const char *comm) {
	(void)ctx;
	(void)comm;
	TODO(__func__);
}

void fstWriterSetEnvVar(fstWriterContext *ctx, const char *envvar) {
	(void)ctx;
	(void)envvar;
	TODO(__func__);
}

void fstWriterSetSourceInstantiationStem(
	fstWriterContext *ctx, const char *path, unsigned int line, unsigned int use_realpath
) {
	(void)ctx;
	(void)path;
	(void)line;
	(void)use_realpath;
	TODO(__func__);
}

void fstWriterSetSourceStem(
	fstWriterContext *ctx, const char *path, unsigned int line, unsigned int use_realpath
) {
	(void)ctx;
	(void)path;
	(void)line;
	(void)use_realpath;
	TODO(__func__);
}

// Waveform related
void fstWriterEmitTimeChange(fstWriterContext *ctx, uint64_t tim) {
	if (! ctx) return;
	ctx->writer.emitTimeChange(tim);
}

void fstWriterEmitDumpActive(fstWriterContext *ctx, int enable) {
	(void)ctx;
	(void)enable;
	TODO(__func__);
}

void fstWriterEmitValueChange32(
	fstWriterContext *ctx, fstHandle handle, uint32_t bits, uint32_t val
) {
	(void)bits;
	if (! ctx) return;
	ctx->writer.emitValueChange(handle, (uint64_t)val);
}

void fstWriterEmitValueChange64(
	fstWriterContext *ctx, fstHandle handle, uint32_t bits, uint64_t val
) {
	(void)bits;
	if (! ctx) return;
	ctx->writer.emitValueChange(handle, val);
}

void fstWriterEmitValueChangeVec32(
	fstWriterContext *ctx, fstHandle handle, uint32_t bits, const uint32_t *val
) {
	(void)bits;
	if (! ctx) return;
	ctx->writer.emitValueChange(handle, val);
}

void fstWriterEmitValueChangeVec64(
	fstWriterContext *ctx, fstHandle handle, uint32_t bits, const uint64_t *val
) {
	(void)bits;
	if (! ctx) return;
	ctx->writer.emitValueChange(handle, val);
}

void fstWriterEmitValueChange(fstWriterContext *ctx, fstHandle handle, const void *val) {
	if (! ctx) return;
	ctx->writer.emitValueChange(handle, static_cast<const char *>(val));
}

void fstWriterEmitVariableLengthValueChange(
	fstWriterContext *ctx, fstHandle handle, const void *val, uint32_t len
) {
	(void)ctx;
	(void)handle;
	(void)val;
	(void)len;
	TODO(__func__);
}

// Misc (Ignored API calls, raise warnings if used)
int fstWriterGetFlushContextPending(fstWriterContext *) {
	NotImplementedWarning(__func__);
	return 0;
}
int fstWriterGetFseekFailed(fstWriterContext *) {
	NotImplementedWarning(__func__);
	return 0;
}
void fstWriterSetDumpSizeLimit(fstWriterContext *, uint64_t) {
	NotImplementedWarning(__func__);
}
void fstWriterSetFileType(fstWriterContext *, enum fstFileType) {
	NotImplementedWarning(__func__);
}
void fstWriterSetParallelMode(fstWriterContext *, int) {
	NotImplementedWarning(__func__);
}
void fstWriterSetRepackOnClose(fstWriterContext *, int) {
	NotImplementedWarning(__func__);
}
void fstWriterSetPackType(fstWriterContext *ctx, enum fstWriterPackType pack_type) {
	if (! ctx) return;
	switch (pack_type) {
	case FST_WR_PT_ZLIB:
		ctx->writer.setWriterPackType(fst::WriterPackType::ZLIB);
		return;
	case FST_WR_PT_FASTLZ:
		ctx->writer.setWriterPackType(fst::WriterPackType::FASTLZ);
		return;
	case FST_WR_PT_LZ4:
		ctx->writer.setWriterPackType(fst::WriterPackType::LZ4);
		return;
	}
	FST_UNREACHABLE;
}

}  // extern "C"
