//
// Created by Trent Tanchin on 9/23/24.
//

#include "glob.h"

namespace abii
{
static int (*real_glob)(const char*, int, int (*)(const char*, int), glob_t*) __THROWNL = nullptr;

extern "C" int abii_glob(const char* pattern, int flags, int (*errfunc)(const char*, int), glob_t* pglob) __THROWNL
{
    OVERRIDE_PREFIX(glob)
        pre_fmtd_str str = "glob(__pattern, __flags, __errfunc, __pglob)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(pattern, "__pattern"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_glob_flag, flags);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(errfunc, "__errfunc"));
        abii_args->push_arg(new ArgPrinter(pglob, "__pglob"));

        auto abii_ret = real_glob(pattern, flags, errfunc, pglob);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(glob, abii_ret)
    return real_glob(pattern, flags, errfunc, pglob);
}

static void (*real_globfree)(glob_t*) __THROW = nullptr;

extern "C" void abii_globfree(glob_t* pglob) __THROW
{
    OVERRIDE_PREFIX(globfree)
        pre_fmtd_str str = "globfree(__pglob)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(pglob, "__pglob"));

        real_globfree(pglob);
    OVERRIDE_SUFFIX(globfree,)
    return real_globfree(pglob);
}

static int (*real_glob64)(const char*, int, int (*)(const char*, int), glob64_t*) __THROWNL = nullptr;

extern "C" int abii_glob64(const char* pattern, int flags, int (*errfunc)(const char*, int), glob64_t* pglob) __THROWNL
{
    OVERRIDE_PREFIX(glob64)
        pre_fmtd_str str = "glob64(__pattern, __flags, __errfunc, __pglob)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(pattern, "__pattern"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_glob_flag, flags);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(errfunc, "__errfunc"));
        abii_args->push_arg(new ArgPrinter(pglob, "__pglob"));

        auto abii_ret = real_glob64(pattern, flags, errfunc, pglob);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(glob64, abii_ret)
    return real_glob64(pattern, flags, errfunc, pglob);
}

static void (*real_globfree64)(glob64_t*) __THROW = nullptr;

extern "C" void abii_globfree64(glob64_t* pglob) __THROW
{
    OVERRIDE_PREFIX(globfree64)
        pre_fmtd_str str = "globfree64(__pglob)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(pglob, "__pglob"));

        real_globfree64(pglob);
    OVERRIDE_SUFFIX(globfree64,)
    return real_globfree64(pglob);
}

static int (*real_glob_pattern_p)(const char*, int) __THROW = nullptr;

extern "C" int abii_glob_pattern_p(const char* pattern, int quote) __THROW
{
    OVERRIDE_PREFIX(glob_pattern_p)
        pre_fmtd_str str = "glob_pattern_p(__pattern, __quote)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(pattern, "__pattern"));

        abii_args->push_arg(new ArgPrinter(quote, "__quote"));

        auto abii_ret = real_glob_pattern_p(pattern, quote);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(glob_pattern_p, abii_ret)
    return real_glob_pattern_p(pattern, quote);
}
}
