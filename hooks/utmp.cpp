//
// Created by Trent Tanchin on 9/26/26.
//

#include "utmp.h"
#include "bits/utmp.h"

#include "custom_enum_printers.h"

namespace abii
{
static int (*real_login_tty)(int) __THROW = nullptr;

extern "C" int abii_login_tty(int fd) __THROW
{
    OVERRIDE_PREFIX(login_tty)
        pre_fmtd_str pi_str = "login_tty(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto abii_ret = real_login_tty(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(login_tty, abii_ret)
    return real_login_tty(fd);
}

static void (*real_login)(const utmp*) __THROW = nullptr;

extern "C" void abii_login(const utmp* entry) __THROW
{
    OVERRIDE_PREFIX(login)
        pre_fmtd_str pi_str = "login(__entry)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(entry, "__entry"));

        real_login(entry);
    OVERRIDE_SUFFIX(login,)
    return real_login(entry);
}

static int (*real_logout)(const char*) __THROW = nullptr;

extern "C" int abii_logout(const char* ut_line) __THROW
{
    OVERRIDE_PREFIX(logout)
        pre_fmtd_str pi_str = "logout(__ut_line)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ut_line, "__ut_line"));

        auto abii_ret = real_logout(ut_line);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(logout, abii_ret)
    return real_logout(ut_line);
}

static void (*real_logwtmp)(const char*, const char*, const char*) __THROW = nullptr;

extern "C" void abii_logwtmp(const char* ut_line, const char* ut_name, const char* ut_host) __THROW
{
    OVERRIDE_PREFIX(logwtmp)
        pre_fmtd_str pi_str = "logwtmp(__ut_line, __ut_name, __ut_host)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ut_line, "__ut_line"));
        abii_args->push_arg(new ArgPrinter(ut_name, "__ut_name"));
        abii_args->push_arg(new ArgPrinter(ut_host, "__ut_host"));

        real_logwtmp(ut_line, ut_name, ut_host);
    OVERRIDE_SUFFIX(logwtmp,)
    return real_logwtmp(ut_line, ut_name, ut_host);
}

static void (*real_updwtmp)(const char*, const utmp*) __THROW = nullptr;

extern "C" void abii_updwtmp(const char* wtmp_file, const utmp* utmp) __THROW
{
    OVERRIDE_PREFIX(updwtmp)
        pre_fmtd_str pi_str = "updwtmp(__wtmp_file, __utmp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(wtmp_file, "__wtmp_file");
        printer->set_enum_printer(print_utmp_file, wtmp_file);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(utmp, "__utmp"));

        real_updwtmp(wtmp_file, utmp);
    OVERRIDE_SUFFIX(updwtmp,)
    return real_updwtmp(wtmp_file, utmp);
}

static int (*real_utmpname)(const char*) __THROW = nullptr;

extern "C" int abii_utmpname(const char* file) __THROW
{
    OVERRIDE_PREFIX(utmpname)
        pre_fmtd_str pi_str = "utmpname(__file)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(file, "__file");
        printer->set_enum_printer(print_utmp_file, file);
        abii_args->push_arg(printer);

        auto abii_ret = real_utmpname(file);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(utmpname, abii_ret)
    return real_utmpname(file);
}

static utmp* (*real_getutent)() __THROW = nullptr;

extern "C" utmp* abii_getutent() __THROW
{
    OVERRIDE_PREFIX(getutent)
        pre_fmtd_str pi_str = "getutent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getutent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getutent, abii_ret)
    return real_getutent();
}

static void (*real_setutent)() __THROW = nullptr;

extern "C" void abii_setutent() __THROW
{
    OVERRIDE_PREFIX(setutent)
        pre_fmtd_str pi_str = "setutent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_setutent();
    OVERRIDE_SUFFIX(setutent,)
    return real_setutent();
}

static void (*real_endutent)() __THROW = nullptr;

extern "C" void abii_endutent() __THROW
{
    OVERRIDE_PREFIX(endutent)
        pre_fmtd_str pi_str = "endutent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endutent();
    OVERRIDE_SUFFIX(endutent,)
    return real_endutent();
}

static utmp* (*real_getutid)(const utmp*) __THROW = nullptr;

extern "C" utmp* abii_getutid(const utmp* id) __THROW
{
    OVERRIDE_PREFIX(getutid)
        pre_fmtd_str pi_str = "getutid(__id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(id, "__id"));

        auto abii_ret = real_getutid(id);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getutid, abii_ret)
    return real_getutid(id);
}

static utmp* (*real_getutline)(const utmp*) __THROW = nullptr;

extern "C" utmp* abii_getutline(const utmp* line) __THROW
{
    OVERRIDE_PREFIX(getutline)
        pre_fmtd_str pi_str = "getutline(__line)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(line, "__line"));

        auto abii_ret = real_getutline(line);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getutline, abii_ret)
    return real_getutline(line);
}

static utmp* (*real_pututline)(const utmp*) __THROW = nullptr;

extern "C" utmp* abii_pututline(const utmp* utmp_ptr) __THROW
{
    OVERRIDE_PREFIX(pututline)
        pre_fmtd_str pi_str = "pututline(__utmp_ptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(utmp_ptr, "__utmp_ptr"));

        auto abii_ret = real_pututline(utmp_ptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pututline, abii_ret)
    return real_pututline(utmp_ptr);
}

static int (*real_getutent_r)(utmp*, utmp**) __THROW = nullptr;

extern "C" int abii_getutent_r(utmp* buffer, utmp** result) __THROW
{
    OVERRIDE_PREFIX(getutent_r)
        pre_fmtd_str pi_str = "getutent_r(__buffer, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getutent_r(buffer, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getutent_r, abii_ret)
    return real_getutent_r(buffer, result);
}

static int (*real_getutid_r)(const utmp*, utmp*, utmp**) __THROW = nullptr;

extern "C" int abii_getutid_r(const utmp* id, utmp* buffer, utmp** result) __THROW
{
    OVERRIDE_PREFIX(getutid_r)
        pre_fmtd_str pi_str = "getutid_r(__id, __buffer, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(id, "__id"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getutid_r(id, buffer, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getutid_r, abii_ret)
    return real_getutid_r(id, buffer, result);
}

static int (*real_getutline_r)(const utmp*, utmp*, utmp**) __THROW = nullptr;

extern "C" int abii_getutline_r(const utmp* line, utmp* buffer, utmp** result) __THROW
{
    OVERRIDE_PREFIX(getutline_r)
        pre_fmtd_str pi_str = "getutline_r(__line, __buffer, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(line, "__line"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getutline_r(line, buffer, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getutline_r, abii_ret)
    return real_getutline_r(line, buffer, result);
}
}
