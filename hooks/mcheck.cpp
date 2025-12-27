//
// Created by Trent Tanchin on 10/4/24.
//

#include "mcheck.h"

namespace abii
{
static int (*real_mcheck)(void (*)(::mcheck_status)) __THROW = nullptr;

extern "C" int abii_mcheck(void (*abortfunc)(::mcheck_status)) __THROW
{
    OVERRIDE_PREFIX(mcheck)
        pre_fmtd_str str = "mcheck(__abortfunc)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(abortfunc, "__abortfunc"));

        auto abii_ret = real_mcheck(abortfunc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mcheck, abii_ret)
    return real_mcheck(abortfunc);
}

static int (*real_mcheck_pedantic)(void (*)(::mcheck_status)) __THROW = nullptr;

extern "C" int abii_mcheck_pedantic(void (*abortfunc)(::mcheck_status)) __THROW
{
    OVERRIDE_PREFIX(mcheck_pedantic)
        pre_fmtd_str str = "mcheck_pedantic(__abortfunc)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(abortfunc, "__abortfunc"));

        auto abii_ret = real_mcheck_pedantic(abortfunc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mcheck_pedantic, abii_ret)
    return real_mcheck_pedantic(abortfunc);
}

static void (*real_mcheck_check_all)() = nullptr;

extern "C" void abii_mcheck_check_all()
{
    OVERRIDE_PREFIX(mcheck_check_all)
        pre_fmtd_str str = "mcheck_check_all()";
        abii_args->push_func(new ArgPrinter(str));

        real_mcheck_check_all();
    OVERRIDE_SUFFIX(mcheck_check_all,)
    return real_mcheck_check_all();
}

static ::mcheck_status (*real_mprobe)(void*) __THROW = nullptr;

extern "C" ::mcheck_status abii_mprobe(void* ptr) __THROW
{
    OVERRIDE_PREFIX(mprobe)
        pre_fmtd_str str = "mprobe(__ptr)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));

        auto abii_ret = real_mprobe(ptr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_mcheck_status, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(mprobe, abii_ret)
    return real_mprobe(ptr);
}

static void (*real_mtrace)() __THROW = nullptr;

extern "C" void abii_mtrace() __THROW
{
    OVERRIDE_PREFIX(mtrace)
        pre_fmtd_str str = "mtrace()";
        abii_args->push_func(new ArgPrinter(str));

        real_mtrace();
    OVERRIDE_SUFFIX(mtrace,)
    return real_mtrace();
}

static void (*real_muntrace)() __THROW = nullptr;

extern "C" void abii_muntrace() __THROW
{
    OVERRIDE_PREFIX(muntrace)
        pre_fmtd_str str = "muntrace()";
        abii_args->push_func(new ArgPrinter(str));

        real_muntrace();
    OVERRIDE_SUFFIX(muntrace,)
    return real_muntrace();
}
}
