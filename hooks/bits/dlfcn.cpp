//
// Created by Trent Tanchin on 11/12/26.
//

#include "dlfcn.h"

namespace abii
{
static void (*real__dl_mcount_wrapper_check)(void*) __THROW = nullptr;

extern "C" void abii__dl_mcount_wrapper_check(void* selfpc) __THROW
{
    OVERRIDE_PREFIX(_dl_mcount_wrapper_check)
        pre_fmtd_str pi_str = "_dl_mcount_wrapper_check(__selfpc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(selfpc, "__selfpc"));

        real__dl_mcount_wrapper_check(selfpc);
    OVERRIDE_SUFFIX(_dl_mcount_wrapper_check,)
    return real__dl_mcount_wrapper_check(selfpc);
}
}
