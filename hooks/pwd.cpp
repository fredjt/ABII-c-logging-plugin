//
// Created by Trent Tanchin on 3/10/25.
//

#include "pwd.h"

namespace abii
{
static void (*real_setpwent)() = nullptr;

extern "C" void abii_setpwent()
{
    OVERRIDE_PREFIX(setpwent)
        pre_fmtd_str pi_str = "setpwent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_setpwent();
    OVERRIDE_SUFFIX(setpwent,)
    return real_setpwent();
}

static void (*real_endpwent)() = nullptr;

extern "C" void abii_endpwent()
{
    OVERRIDE_PREFIX(endpwent)
        pre_fmtd_str pi_str = "endpwent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endpwent();
    OVERRIDE_SUFFIX(endpwent,)
    return real_endpwent();
}

static passwd* (*real_getpwent)() = nullptr;

extern "C" passwd* abii_getpwent()
{
    OVERRIDE_PREFIX(getpwent)
        pre_fmtd_str pi_str = "getpwent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getpwent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpwent, abii_ret)
    return real_getpwent();
}

static passwd* (*real_fgetpwent)(FILE*) = nullptr;

extern "C" __nonnull((1))
passwd* abii_fgetpwent(FILE* stream)
{
    OVERRIDE_PREFIX(fgetpwent)
        pre_fmtd_str pi_str = "fgetpwent(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetpwent(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetpwent, abii_ret)
    return real_fgetpwent(stream);
}

static int (*real_putpwent)(const passwd*, FILE*) = nullptr;

extern "C" int abii_putpwent(const passwd* p, FILE* f)
{
    OVERRIDE_PREFIX(putpwent)
        pre_fmtd_str pi_str = "putpwent(__p, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(p, "__p"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_putpwent(p, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(putpwent, abii_ret)
    return real_putpwent(p, f);
}

static passwd* (*real_getpwuid)(__uid_t) = nullptr;

extern "C" passwd* abii_getpwuid(__uid_t uid)
{
    OVERRIDE_PREFIX(getpwuid)
        pre_fmtd_str pi_str = "getpwuid(__uid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(uid, "__uid"));

        auto abii_ret = real_getpwuid(uid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpwuid, abii_ret)
    return real_getpwuid(uid);
}

static passwd* (*real_getpwnam)(const char*) = nullptr;

extern "C" __nonnull((1))
passwd* abii_getpwnam(const char* name)
{
    OVERRIDE_PREFIX(getpwnam)
        pre_fmtd_str pi_str = "getpwnam(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getpwnam(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpwnam, abii_ret)
    return real_getpwnam(name);
}

static int (*real_getpwent_r)(passwd*, char*, size_t, passwd**) = nullptr;

extern "C" __nonnull((1, 2, 4)) __attr_access((__write_only__, 2, 3))
int abii_getpwent_r(passwd* resultbuf, char* buffer, size_t buflen, passwd** result)
{
    OVERRIDE_PREFIX(getpwent_r)
        pre_fmtd_str pi_str = "getpwent_r(__resultbuf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(resultbuf, "__resultbuf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buflen, "__buflen");
        printer1->set_enum_printer(print_pwd_nss_buflen_passwd, buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getpwent_r(resultbuf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpwent_r, abii_ret)
    return real_getpwent_r(resultbuf, buffer, buflen, result);
}

static int (*real_getpwuid_r)(__uid_t, passwd*, char*, size_t, passwd**) = nullptr;

extern "C" __nonnull((2, 3, 5)) __attr_access((__write_only__, 3, 4))
int abii_getpwuid_r(__uid_t uid, passwd* resultbuf, char* buffer, size_t buflen, passwd** result)
{
    OVERRIDE_PREFIX(getpwuid_r)
        pre_fmtd_str pi_str = "getpwuid_r(__uid, __resultbuf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(uid, "__uid"));
        abii_args->push_arg(new ArgPrinter(resultbuf, "__resultbuf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buflen, "__buflen");
        printer1->set_enum_printer(print_pwd_nss_buflen_passwd, buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getpwuid_r(uid, resultbuf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpwuid_r, abii_ret)
    return real_getpwuid_r(uid, resultbuf, buffer, buflen, result);
}

static int (*real_getpwnam_r)(const char*, passwd*, char*, size_t, passwd**) = nullptr;

extern "C" __nonnull((1, 2, 3, 5)) __attr_access((__write_only__, 3, 4))
int abii_getpwnam_r(const char* name, passwd* resultbuf, char* buffer, size_t buflen, passwd** result)
{
    OVERRIDE_PREFIX(getpwnam_r)
        pre_fmtd_str pi_str = "getpwnam_r(__name, __resultbuf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(resultbuf, "__resultbuf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buflen, "__buflen");
        printer1->set_enum_printer(print_pwd_nss_buflen_passwd, buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getpwnam_r(name, resultbuf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpwnam_r, abii_ret)
    return real_getpwnam_r(name, resultbuf, buffer, buflen, result);
}

static int (*real_fgetpwent_r)(FILE*, passwd*, char*, size_t, passwd**) = nullptr;

extern "C" __nonnull((1, 2, 3, 5)) __attr_access((__write_only__, 3, 4))
int abii_fgetpwent_r(FILE* stream, passwd* resultbuf, char* buffer, size_t buflen, passwd** result)
{
    OVERRIDE_PREFIX(fgetpwent_r)
        pre_fmtd_str pi_str = "fgetpwent_r(__stream, __resultbuf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(resultbuf, "__resultbuf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buflen, "__buflen");
        printer1->set_enum_printer(print_pwd_nss_buflen_passwd, buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_fgetpwent_r(stream, resultbuf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetpwent_r, abii_ret)
    return real_fgetpwent_r(stream, resultbuf, buffer, buflen, result);
}

static int (*real_getpw)(__uid_t, char*) = nullptr;

extern "C" int abii_getpw(__uid_t uid, char* buffer)
{
    OVERRIDE_PREFIX(getpw)
        pre_fmtd_str pi_str = "getpw(__uid, __buffer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(uid, "__uid"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        auto abii_ret = real_getpw(uid, buffer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpw, abii_ret)
    return real_getpw(uid, buffer);
}
}
