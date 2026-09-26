//
// Created by Trent Tanchin on 9/26/26.
//

#include "utmpx.h"
#include "bits/utmpx.h"

#include <utmp.h>

#include "bits/utmp.h"

namespace abii
{
static void (*real_setutxent)() = nullptr;

extern "C" void abii_setutxent()
{
    OVERRIDE_PREFIX(setutxent)
        pre_fmtd_str pi_str = "setutxent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_setutxent();
    OVERRIDE_SUFFIX(setutxent,)
    return real_setutxent();
}

static void (*real_endutxent)() = nullptr;

extern "C" void abii_endutxent()
{
    OVERRIDE_PREFIX(endutxent)
        pre_fmtd_str pi_str = "endutxent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endutxent();
    OVERRIDE_SUFFIX(endutxent,)
    return real_endutxent();
}

static utmpx* (*real_getutxent)() = nullptr;

extern "C" utmpx* abii_getutxent()
{
    OVERRIDE_PREFIX(getutxent)
        pre_fmtd_str pi_str = "getutxent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getutxent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getutxent, abii_ret)
    return real_getutxent();
}

static utmpx* (*real_getutxid)(const utmpx*) = nullptr;

extern "C" utmpx* abii_getutxid(const utmpx* id)
{
    OVERRIDE_PREFIX(getutxid)
        pre_fmtd_str pi_str = "getutxid(__id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(id, "__id"));

        auto abii_ret = real_getutxid(id);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getutxid, abii_ret)
    return real_getutxid(id);
}

static utmpx* (*real_getutxline)(const utmpx*) = nullptr;

extern "C" utmpx* abii_getutxline(const utmpx* line)
{
    OVERRIDE_PREFIX(getutxline)
        pre_fmtd_str pi_str = "getutxline(__line)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(line, "__line"));

        auto abii_ret = real_getutxline(line);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getutxline, abii_ret)
    return real_getutxline(line);
}

static utmpx* (*real_pututxline)(const utmpx*) = nullptr;

extern "C" utmpx* abii_pututxline(const utmpx* utmpx)
{
    OVERRIDE_PREFIX(pututxline)
        pre_fmtd_str pi_str = "pututxline(__utmpx)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(utmpx, "__utmpx"));

        auto abii_ret = real_pututxline(utmpx);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pututxline, abii_ret)
    return real_pututxline(utmpx);
}

static int (*real_utmpxname)(const char*) = nullptr;

extern "C" int abii_utmpxname(const char* file)
{
    OVERRIDE_PREFIX(utmpxname)
        pre_fmtd_str pi_str = "utmpxname(__file)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(file, "__file");
        printer->set_enum_printer(print_utmpx_file, file);
        abii_args->push_arg(printer);

        auto abii_ret = real_utmpxname(file);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(utmpxname, abii_ret)
    return real_utmpxname(file);
}

static void (*real_updwtmpx)(const char*, const utmpx*) = nullptr;

extern "C" void abii_updwtmpx(const char* wtmpx_file, const utmpx* utmpx)
{
    OVERRIDE_PREFIX(updwtmpx)
        pre_fmtd_str pi_str = "updwtmpx(__wtmpx_file, __utmpx)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(wtmpx_file, "__file");
        printer->set_enum_printer(print_utmpx_file, wtmpx_file);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(utmpx, "__utmpx"));

        real_updwtmpx(wtmpx_file, utmpx);
    OVERRIDE_SUFFIX(updwtmpx,)
    return real_updwtmpx(wtmpx_file, utmpx);
}

static void (*real_getutmp)(const utmpx*, utmp*) = nullptr;

extern "C" void abii_getutmp(const utmpx* utmpx, utmp* utmp)
{
    OVERRIDE_PREFIX(getutmp)
        pre_fmtd_str pi_str = "getutmp(__utmpx, __utmp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(utmpx, "__utmpx"));
        abii_args->push_arg(new ArgPrinter(utmp, "__utmp"));

        real_getutmp(utmpx, utmp);
    OVERRIDE_SUFFIX(getutmp,)
    return real_getutmp(utmpx, utmp);
}

static void (*real_getutmpx)(const utmp*, utmpx*) = nullptr;

extern "C" void abii_getutmpx(const utmp* utmp, utmpx* utmpx)
{
    OVERRIDE_PREFIX(getutmpx)
        pre_fmtd_str pi_str = "getutmpx(__utmp, __utmpx)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(utmp, "__utmp"));
        abii_args->push_arg(new ArgPrinter(utmpx, "__utmpx"));

        real_getutmpx(utmp, utmpx);
    OVERRIDE_SUFFIX(getutmpx,)
    return real_getutmpx(utmp, utmpx);
}
}
