//
// Created by Trent Tanchin on 5/22/25.
//

#include "bits/sched.h"

#include <abii/libabii.h>

#include "bits/cpu-set.h"
#include "bits/types/struct_sched_param.h"
#include "bits/types/struct_timespec.h"

namespace abii
{
static int (*real_sched_setparam)(__pid_t, const sched_param*) __THROW = nullptr;

extern "C" int abii_sched_setparam(__pid_t pid, const sched_param* param) __THROW
{
    OVERRIDE_PREFIX(sched_setparam)
        pre_fmtd_str pi_str = "sched_setparam(__pid, __param)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));
        abii_args->push_arg(new ArgPrinter(param, "__param"));

        auto abii_ret = real_sched_setparam(pid, param);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_setparam, abii_ret)
    return real_sched_setparam(pid, param);
}

static int (*real_sched_getparam)(__pid_t, sched_param*) __THROW = nullptr;

extern "C" int abii_sched_getparam(__pid_t pid, sched_param* param) __THROW
{
    OVERRIDE_PREFIX(sched_getparam)
        pre_fmtd_str pi_str = "sched_getparam(__pid, __param)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));
        abii_args->push_arg(new ArgPrinter(param, "__param"));

        auto abii_ret = real_sched_getparam(pid, param);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_getparam, abii_ret)
    return real_sched_getparam(pid, param);
}

static int (*real_sched_setscheduler)(__pid_t, int, const sched_param*) __THROW = nullptr;

extern "C" int abii_sched_setscheduler(__pid_t pid, int policy, const sched_param* param) __THROW
{
    OVERRIDE_PREFIX(sched_setscheduler)
        pre_fmtd_str pi_str = "sched_setscheduler(__pid, __policy, __param)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));

        auto printer = new ArgPrinter(policy, "__policy");
        printer->set_enum_printer(print_sched_algorithm, policy);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(param, "__param"));

        auto abii_ret = real_sched_setscheduler(pid, policy, param);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_setscheduler, abii_ret)
    return real_sched_setscheduler(pid, policy, param);
}

static int (*real_sched_getscheduler)(__pid_t) __THROW = nullptr;

extern "C" int abii_sched_getscheduler(__pid_t pid) __THROW
{
    OVERRIDE_PREFIX(sched_getscheduler)
        pre_fmtd_str pi_str = "sched_getscheduler(__pid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));

        auto abii_ret = real_sched_getscheduler(pid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_getscheduler, abii_ret)
    return real_sched_getscheduler(pid);
}

static int (*real_sched_yield)() __THROW = nullptr;

extern "C" int abii_sched_yield() __THROW
{
    OVERRIDE_PREFIX(sched_yield)
        pre_fmtd_str pi_str = "sched_yield()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_sched_yield();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_yield, abii_ret)
    return real_sched_yield();
}

static int (*real_sched_get_priority_max)(int) __THROW = nullptr;

extern "C" int abii_sched_get_priority_max(int algorithm) __THROW
{
    OVERRIDE_PREFIX(sched_get_priority_max)
        pre_fmtd_str pi_str = "sched_get_priority_max(__algorithm)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(algorithm, "__algorithm");
        printer->set_enum_printer(print_sched_algorithm, algorithm);
        abii_args->push_arg(printer);

        auto abii_ret = real_sched_get_priority_max(algorithm);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_get_priority_max, abii_ret)
    return real_sched_get_priority_max(algorithm);
}

static int (*real_sched_get_priority_min)(int) __THROW = nullptr;

extern "C" int abii_sched_get_priority_min(int algorithm) __THROW
{
    OVERRIDE_PREFIX(sched_get_priority_min)
        pre_fmtd_str pi_str = "sched_get_priority_min(__algorithm)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(algorithm, "__algorithm");
        printer->set_enum_printer(print_sched_algorithm, algorithm);
        abii_args->push_arg(printer);

        auto abii_ret = real_sched_get_priority_min(algorithm);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_get_priority_min, abii_ret)
    return real_sched_get_priority_min(algorithm);
}

static int (*real_sched_rr_get_interval)(__pid_t, timespec*) __THROW = nullptr;

extern "C" int abii_sched_rr_get_interval(__pid_t pid, timespec* t) __THROW
{
    OVERRIDE_PREFIX(sched_rr_get_interval)
        pre_fmtd_str pi_str = "sched_rr_get_interval(__pid, __t)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));
        abii_args->push_arg(new ArgPrinter(t, "__t"));

        auto abii_ret = real_sched_rr_get_interval(pid, t);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_rr_get_interval, abii_ret)
    return real_sched_rr_get_interval(pid, t);
}

static int (*real_sched_setaffinity)(__pid_t, size_t, const cpu_set_t*) __THROW = nullptr;

extern "C" int abii_sched_setaffinity(__pid_t pid, size_t cpusetsize, const cpu_set_t* cpuset) __THROW
{
    OVERRIDE_PREFIX(sched_setaffinity)
        pre_fmtd_str pi_str = "sched_setaffinity(__pid, __cpusetsize, __cpuset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));
        abii_args->push_arg(new ArgPrinter(cpusetsize, "__cpusetsize"));
        abii_args->push_arg(new ArgPrinter(cpuset, "__cpuset"));

        auto abii_ret = real_sched_setaffinity(pid, cpusetsize, cpuset);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_setaffinity, abii_ret)
    return real_sched_setaffinity(pid, cpusetsize, cpuset);
}

static int (*real_sched_getaffinity)(__pid_t, size_t, cpu_set_t*) __THROW = nullptr;

extern "C" int abii_sched_getaffinity(__pid_t pid, size_t cpusetsize, cpu_set_t* cpuset) __THROW
{
    OVERRIDE_PREFIX(sched_getaffinity)
        pre_fmtd_str pi_str = "sched_getaffinity(__pid, __cpusetsize, __cpuset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));
        abii_args->push_arg(new ArgPrinter(cpusetsize, "__cpusetsize"));
        abii_args->push_arg(new ArgPrinter(cpuset, "__cpuset"));

        auto abii_ret = real_sched_getaffinity(pid, cpusetsize, cpuset);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sched_getaffinity, abii_ret)
    return real_sched_getaffinity(pid, cpusetsize, cpuset);
}
}
