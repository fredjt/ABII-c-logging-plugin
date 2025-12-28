//
// Created by Trent Tanchin on 5/23/25.
//

#include "sgtty.h"

namespace abii
{
static int (*real_gtty)(int, sgttyb*) __THROW = nullptr;

extern "C" int abii_gtty(int fd, sgttyb* params) __THROW
{
    OVERRIDE_PREFIX(gtty)
        pre_fmtd_str pi_str = "gtty(__fd, __params)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(params, "__params"));

        auto abii_ret = real_gtty(fd, params);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gtty, abii_ret)
    return real_gtty(fd, params);
}

static int (*real_stty)(int, const sgttyb*) __THROW = nullptr;

extern "C" int abii_stty(int fd, const sgttyb* params) __THROW
{
    OVERRIDE_PREFIX(stty)
        pre_fmtd_str pi_str = "stty(__fd, __params)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(params, "__params"));

        auto abii_ret = real_stty(fd, params);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stty, abii_ret)
    return real_stty(fd, params);
}
}
