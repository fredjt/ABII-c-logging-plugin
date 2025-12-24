//
// Created by Trent Tanchin on 8/17/24.
//

#include <abii/libabii.h>

namespace abii
{
static int* (*real___errno_location)() __THROW = nullptr;

extern "C" __attribute_const__
int* abii___errno_location() __THROW
{
    OVERRIDE_PREFIX(__errno_location)
        pre_fmtd_str str = "__errno_location()";
        abii_args->push_func(new ArgPrinter(str));

        const auto abii_ret = real___errno_location();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__errno_location, abii_ret)
    return real___errno_location();
}
}
