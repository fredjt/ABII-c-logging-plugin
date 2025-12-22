//
// Created by Trent Tanchin on 7/4/24.
//

#include <abii/libabii.h>

namespace abii
{
static void* (*real_alloca)(size_t) __THROW = nullptr;

void* abii_alloca(size_t size) __THROW
{
    OVERRIDE_PREFIX(alloca)
        pre_fmtd_str str = "alloca(__size)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_alloca(size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(alloca, abii_ret)
    return real_alloca(size);
}
}
