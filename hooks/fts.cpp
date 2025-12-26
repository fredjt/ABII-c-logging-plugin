//
// Created by Trent Tanchin on 9/18/24.
//

#include "fts.h"

namespace abii
{
static FTSENT* (*real_fts_children)(FTS*, int) = nullptr;

extern "C" FTSENT* abii_fts_children(FTS* fts, int flags)
{
    OVERRIDE_PREFIX(fts_children)
        pre_fmtd_str str = "fts_children(__fts, __flags)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fts, "__fts"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_fts_opts, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_fts_children(fts, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts_children, abii_ret)
    return real_fts_children(fts, flags);
}

static int (*real_fts_close)(FTS*) = nullptr;

extern "C" int abii_fts_close(FTS* fts)
{
    OVERRIDE_PREFIX(fts_close)
        pre_fmtd_str str = "fts_close(__fts)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fts, "__fts"));

        auto abii_ret = real_fts_close(fts);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts_close, abii_ret)
    return real_fts_close(fts);
}

static FTS* (*real_fts_open)(char* const*, int, int (*)(const FTSENT**, const FTSENT**)) = nullptr;

extern "C" FTS* abii_fts_open(char* const* dirs, int flags, int (*comp)(const FTSENT**, const FTSENT**))
{
    OVERRIDE_PREFIX(fts_open)
        pre_fmtd_str str = "fts_open(__dirs, __flags, __comp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirs, "__dirs"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_fts_opts, flags);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(comp, "__comp"));

        auto abii_ret = real_fts_open(dirs, flags, comp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts_open, abii_ret)
    return real_fts_open(dirs, flags, comp);
}

static FTSENT* (*real_fts_read)(FTS*) = nullptr;

extern "C" FTSENT* abii_fts_read(FTS* fts)
{
    OVERRIDE_PREFIX(fts_read)
        pre_fmtd_str str = "fts_read(__fts)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fts, "__fts"));

        auto abii_ret = real_fts_read(fts);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts_read, abii_ret)
    return real_fts_read(fts);
}

static int (*real_fts_set)(FTS*, FTSENT*, int) __THROW = nullptr;

extern "C" int abii_fts_set(FTS* fts, FTSENT* ftsent, int instr) __THROW
{
    OVERRIDE_PREFIX(fts_set)
        pre_fmtd_str str = "fts_set(__fts, __ftsent, __instr)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fts, "__fts"));
        abii_args->push_arg(new ArgPrinter(ftsent, "__ftsent"));

        auto printer = new ArgPrinter(instr, "__instr");
        printer->set_enum_printer(print_fts_instr, instr);
        abii_args->push_arg(printer);

        auto abii_ret = real_fts_set(fts, ftsent, instr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts_set, abii_ret)
    return real_fts_set(fts, ftsent, instr);
}

static FTSENT64* (*real_fts64_children)(FTS64*, int) = nullptr;

extern "C" FTSENT64* abii_fts64_children(FTS64* fts, int flags)
{
    OVERRIDE_PREFIX(fts64_children)
        pre_fmtd_str str = "fts64_children(__fts, __flags)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fts, "__fts"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_fts_opts, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_fts64_children(fts, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts64_children, abii_ret)
    return real_fts64_children(fts, flags);
}

static int (*real_fts64_close)(FTS64*) = nullptr;

extern "C" int abii_fts64_close(FTS64* fts)
{
    OVERRIDE_PREFIX(fts64_close)
        pre_fmtd_str str = "fts64_close(__fts)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fts, "__fts"));

        auto abii_ret = real_fts64_close(fts);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts64_close, abii_ret)
    return real_fts64_close(fts);
}

static FTS64* (*real_fts64_open)(char* const*, int, int (*)(const FTSENT64**, const FTSENT64**)) = nullptr;

extern "C" FTS64* abii_fts64_open(char* const* dirs, int flags, int (*comp)(const FTSENT64**, const FTSENT64**))
{
    OVERRIDE_PREFIX(fts64_open)
        pre_fmtd_str str = "fts64_open(__dirs, __flags, __comp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirs, "__dirs"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_fts_opts, flags);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(comp, "__comp"));

        auto abii_ret = real_fts64_open(dirs, flags, comp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts64_open, abii_ret)
    return real_fts64_open(dirs, flags, comp);
}

static FTSENT64* (*real_fts64_read)(FTS64*) = nullptr;

extern "C" FTSENT64* abii_fts64_read(FTS64* fts)
{
    OVERRIDE_PREFIX(fts64_read)
        pre_fmtd_str str = "fts64_read(__fts)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fts, "__fts"));

        auto abii_ret = real_fts64_read(fts);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts64_read, abii_ret)
    return real_fts64_read(fts);
}

static int (*real_fts64_set)(FTS64*, FTSENT64*, int) __THROW = nullptr;

extern "C" int abii_fts64_set(FTS64* fts, FTSENT64* ftsent, int instr) __THROW
{
    OVERRIDE_PREFIX(fts64_set)
        pre_fmtd_str str = "fts64_set(__fts, __ftsent, __instr)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fts, "__fts"));
        abii_args->push_arg(new ArgPrinter(ftsent, "__ftsent"));

        auto printer = new ArgPrinter(instr, "__instr");
        printer->set_enum_printer(print_fts_instr, instr);
        abii_args->push_arg(printer);

        auto abii_ret = real_fts64_set(fts, ftsent, instr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fts64_set, abii_ret)
    return real_fts64_set(fts, ftsent, instr);
}
}
