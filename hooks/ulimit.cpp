//
// Created by Trent Tanchin on 7/4/26.
//

#include "ulimit.h"

#include <ulimit.h>

#include "custom_printers.h"

namespace abii
{
static long int (*real_ulimit)(int, ...) __THROW = nullptr;

extern "C" long int abii_ulimit(int cmd, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(ulimit,)
        pre_fmtd_str pi_str = "ulimit(__cmd, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cmd, "__cmd"));
        if (cmd == UL_SETFSIZE)
        {
            va_start(abii_vargs, cmd);
            long int fsize = va_arg(abii_vargs, long);
            abii_args->push_arg(new ArgPrinter(fsize, "..."));
            va_end(abii_vargs);
        }

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_ulimit), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(*reinterpret_cast<long int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(ulimit, abii_ret, cmd)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_ulimit), abii_bi_vargs, 1000));
}
}
