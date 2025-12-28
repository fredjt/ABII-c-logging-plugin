//
// Created by Trent Tanchin on 3/10/25.
//

#include <abii/libabii.h>

#include "bits/ioctl-types.h"
#include "bits/termios-struct.h"

namespace abii
{
static int (*real_openpty)(int*, int*, char*, const termios*, const winsize*) __THROW = nullptr;

extern "C" int abii_openpty(int* amaster, int* aslave, char* name, const termios* termp, const winsize* winp) __THROW
{
    OVERRIDE_PREFIX(openpty)
        pre_fmtd_str pi_str = "openpty(__amaster, __aslave, __name, __termp, __winp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(amaster, "__amaster"));
        abii_args->push_arg(new ArgPrinter(aslave, "__aslave"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(termp, "__termp"));
        abii_args->push_arg(new ArgPrinter(winp, "__winp"));

        auto abii_ret = real_openpty(amaster, aslave, name, termp, winp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(openpty, abii_ret)
    return real_openpty(amaster, aslave, name, termp, winp);
}

static int (*real_forkpty)(int*, char*, const termios*, const winsize*) __THROW = nullptr;

extern "C" int abii_forkpty(int* amaster, char* name, const termios* termp, const winsize* winp) __THROW
{
    OVERRIDE_PREFIX(forkpty)
        pre_fmtd_str pi_str = "forkpty(__amaster, __name, __termp, __winp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(amaster, "__amaster"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(termp, "__termp"));
        abii_args->push_arg(new ArgPrinter(winp, "__winp"));

        auto abii_ret = real_forkpty(amaster, name, termp, winp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(forkpty, abii_ret)
    return real_forkpty(amaster, name, termp, winp);
}
}
