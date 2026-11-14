//
// Created by Trent Tanchin on 11/13/26.
//

#include <abii/libabii.h>

namespace abii
{
static __nonnull((2, 3)) int (*real_getopt)(int, char* const *, const char*) __THROW = nullptr;

extern "C" __nonnull((2, 3))
int abii_getopt(int argc, char* const * argv, const char* shortopts) __THROW

{
    OVERRIDE_PREFIX(getopt)
        pre_fmtd_str pi_str = "getopt(___argc, ___argv, __shortopts)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(argc, "___argc"));

        auto printer = new ArgPrinter(argv, "___argv");
        printer->set_len(argc);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(shortopts, "__shortopts"));

        auto abii_ret = real_getopt(argc, argv, shortopts);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getopt, abii_ret)
    return real_getopt(argc, argv, shortopts);
}
}
