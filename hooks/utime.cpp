//
// Created by Trent Tanchin on 9/26/26.
//

#include "utime.h"

namespace abii
{
static __nonnull((1)) int (*real_utime)(const char*, const utimbuf*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_utime(const char* file, const utimbuf* file_times) __THROW
{
    OVERRIDE_PREFIX(utime)
        pre_fmtd_str pi_str = "utime(__file, __file_times)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file, "__flags"));
        abii_args->push_arg(new ArgPrinter(file_times, "__flags"));

        auto abii_ret = real_utime(file, file_times);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(utime, abii_ret)
    return real_utime(file, file_times);
}
}
