//
// Created by Trent Tanchin on 7/4/26.
//

#include "time.h"

#include "timex.h"

namespace abii
{
static __nonnull((2)) int (*real_clock_adjtime)(__clockid_t, timex*) = nullptr;

extern "C" __nonnull((2))
int abii_clock_adjtime(__clockid_t clock_id, timex* utx) __THROW
{
    OVERRIDE_PREFIX(clock_adjtime)
        pre_fmtd_str pi_str = "clock_adjtime(__clock_id, __utx)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer(print_time_clock, clock_id);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(utx, "__utx"));

        auto abii_ret = real_clock_adjtime(clock_id, utx);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(clock_adjtime, abii_ret)
    return real_clock_adjtime(clock_id, utx);
}
}
