//
// Created by Trent Tanchin on 11/13/26.
//

#include "getopt_ext.h"

namespace abii
{
static __nonnull((2, 3))
int (*real_getopt_long)(int, char* __getopt_argv_const*, const char*, const option*, int*) __THROW = nullptr;

extern "C" __nonnull((2, 3))
int abii_getopt_long(int argc, char* __getopt_argv_const* argv, const char* shortopts, const option* longopts,
                     int* longind) __THROW

{
    OVERRIDE_PREFIX(getopt_long)
        pre_fmtd_str pi_str = "getopt_long(___argc, ___argv, __shortopts, __longopts, __longind)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(argc, "___argc"));

        auto printer = new ArgPrinter(argv, "___argv");
        printer->set_len(argc);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(shortopts, "__shortopts"));
        abii_args->push_arg(new ArgPrinter(longopts, "__longopts"));
        abii_args->push_arg(new ArgPrinter(longind, "__longind"));

        auto abii_ret = real_getopt_long(argc, argv, shortopts, longopts, longind);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getopt_long, abii_ret)
    return real_getopt_long(argc, argv, shortopts, longopts, longind);
}

static __nonnull((2, 3))
int (*real_getopt_long_only)(int, char* __getopt_argv_const*, const char*, const option*, int*) __THROW = nullptr;

extern "C" __nonnull((2, 3))
int abii_getopt_long_only(int argc, char* __getopt_argv_const* argv, const char* shortopts, const option* longopts,
                          int* longind) __THROW

{
    OVERRIDE_PREFIX(getopt_long_only)
        pre_fmtd_str pi_str = "getopt_long_only(___argc, ___argv, __shortopts, __longopts, __longind)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(argc, "___argc"));

        auto printer = new ArgPrinter(argv, "___argv");
        printer->set_len(argc);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(shortopts, "__shortopts"));
        abii_args->push_arg(new ArgPrinter(longopts, "__longopts"));
        abii_args->push_arg(new ArgPrinter(longind, "__longind"));

        auto abii_ret = real_getopt_long_only(argc, argv, shortopts, longopts, longind);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getopt_long_only, abii_ret)
    return real_getopt_long_only(argc, argv, shortopts, longopts, longind);
}
}
