//
// Created by Trent Tanchin on 7/4/26.
//

#include "ttyent.h"

namespace abii
{
static ttyent* (*real_getttyent)() __THROW = nullptr;

extern "C" ttyent* abii_getttyent() __THROW
{
    OVERRIDE_PREFIX(getttyent)
        pre_fmtd_str pi_str = "getttyent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getttyent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getttyent, abii_ret)
    return real_getttyent();
}

static ttyent* (*real_getttynam)(const char*) __THROW = nullptr;

extern "C" ttyent* abii_getttynam(const char* tty) __THROW
{
    OVERRIDE_PREFIX(getttynam)
        pre_fmtd_str pi_str = "getttynam(__tty)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tty, "__tty"));

        auto abii_ret = real_getttynam(tty);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getttynam, abii_ret)
    return real_getttynam(tty);
}

static int (*real_setttyent)() __THROW = nullptr;

extern "C" int abii_setttyent() __THROW
{
    OVERRIDE_PREFIX(setttyent)
        pre_fmtd_str pi_str = "setttyent(__tty)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_setttyent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setttyent, abii_ret)
    return real_setttyent();
}

static int (*real_endttyent)() __THROW = nullptr;

extern "C" int abii_endttyent() __THROW
{
    OVERRIDE_PREFIX(endttyent)
        pre_fmtd_str pi_str = "endttyent(__tty)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_endttyent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(endttyent, abii_ret)
    return real_endttyent();
}
}
