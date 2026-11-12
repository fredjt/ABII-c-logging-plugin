//
// Created by Trent Tanchin on 11/12/26.
//

#include "cpu-set.h"

namespace abii
{
static int (*real___sched_cpucount)(size_t, const cpu_set_t*) __THROW = nullptr;

extern "C" int abii___sched_cpucount(size_t setsize, const cpu_set_t* setp) __THROW
{
    OVERRIDE_PREFIX(__sched_cpucount)
        pre_fmtd_str pi_str = "__sched_cpucount(__setsize, __setp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(setsize, "__setsize"));
        abii_args->push_arg(new ArgPrinter(setp, "__setp"));

        auto abii_ret = real___sched_cpucount(setsize, setp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__sched_cpucount, abii_ret)
    return real___sched_cpucount(setsize, setp);
}

static __wur cpu_set_t* (*real___sched_cpualloc)(size_t) __THROW = nullptr;

extern "C" __wur
cpu_set_t* abii___sched_cpualloc(size_t count) __THROW
{
    OVERRIDE_PREFIX(__sched_cpualloc)
        pre_fmtd_str pi_str = "__sched_cpualloc(__count)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(count, "__count"));

        auto abii_ret = real___sched_cpualloc(count);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__sched_cpualloc, abii_ret)
    return real___sched_cpualloc(count);
}

static void (*real___sched_cpufree)(cpu_set_t*) __THROW = nullptr;

extern "C" void abii___sched_cpufree(cpu_set_t* set) __THROW
{
    OVERRIDE_PREFIX(__sched_cpufree)
        pre_fmtd_str pi_str = "__sched_cpufree(__set)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        real___sched_cpufree(set);
    OVERRIDE_SUFFIX(__sched_cpufree,)
    return real___sched_cpufree(set);
}
}
