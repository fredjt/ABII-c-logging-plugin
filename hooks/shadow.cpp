//
// Created by Trent Tanchin on 5/23/25.
//

#include "shadow.h"

namespace abii
{
static void (*real_setspent)() = nullptr;

extern "C" void abii_setspent()
{
    OVERRIDE_PREFIX(setspent)
        pre_fmtd_str pi_str = "setspent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_setspent();
    OVERRIDE_SUFFIX(setspent,)
    return real_setspent();
}

static void (*real_endspent)() = nullptr;

extern "C" void abii_endspent()
{
    OVERRIDE_PREFIX(endspent)
        pre_fmtd_str pi_str = "endspent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endspent();
    OVERRIDE_SUFFIX(endspent,)
    return real_endspent();
}

static spwd* (*real_getspent)() = nullptr;

extern "C" spwd* abii_getspent()
{
    OVERRIDE_PREFIX(getspent)
        pre_fmtd_str pi_str = "getspent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getspent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getspent, abii_ret)
    return real_getspent();
}

static spwd* (*real_getspnam)(const char*) = nullptr;

extern "C" spwd* abii_getspnam(const char* name)
{
    OVERRIDE_PREFIX(getspnam)
        pre_fmtd_str pi_str = "getspnam(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getspnam(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getspnam, abii_ret)
    return real_getspnam(name);
}

static spwd* (*real_sgetspent)(const char*) = nullptr;

extern "C" spwd* abii_sgetspent(const char* string)
{
    OVERRIDE_PREFIX(sgetspent)
        pre_fmtd_str pi_str = "sgetspent(__string)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));

        auto abii_ret = real_sgetspent(string);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sgetspent, abii_ret)
    return real_sgetspent(string);
}

static spwd* (*real_fgetspent)(FILE*) = nullptr;

extern "C" spwd* abii_fgetspent(FILE* stream)
{
    OVERRIDE_PREFIX(fgetspent)
        pre_fmtd_str pi_str = "fgetspent(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetspent(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetspent, abii_ret)
    return real_fgetspent(stream);
}

static int (*real_putspent)(const spwd*, FILE*) = nullptr;

extern "C" int abii_putspent(const spwd* p, FILE* stream)
{
    OVERRIDE_PREFIX(putspent)
        pre_fmtd_str pi_str = "putspent(__p, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(p, "__p"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_putspent(p, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(putspent, abii_ret)
    return real_putspent(p, stream);
}

static int (*real_getspent_r)(spwd*, char*, size_t, spwd**) = nullptr;

extern "C" __attr_access((__write_only__, 2, 3))
int abii_getspent_r(spwd* result_buf, char* buffer, size_t buflen, spwd** result)
{
    OVERRIDE_PREFIX(getspent_r)
        pre_fmtd_str pi_str = "getspent_r(__result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getspent_r(result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getspent_r, abii_ret)
    return real_getspent_r(result_buf, buffer, buflen, result);
}

static int (*real_getspnam_r)(const char*, spwd*, char*, size_t, spwd**) = nullptr;

extern "C" __attr_access((__write_only__, 3, 4))
int abii_getspnam_r(const char* name, spwd* result_buf, char* buffer, size_t buflen, spwd** result)
{
    OVERRIDE_PREFIX(getspnam_r)
        pre_fmtd_str pi_str = "getspnam_r(__name, __result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getspnam_r(name, result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getspnam_r, abii_ret)
    return real_getspnam_r(name, result_buf, buffer, buflen, result);
}

static int (*real_sgetspent_r)(const char*, spwd*, char*, size_t, spwd**) = nullptr;

extern "C" __attr_access((__write_only__, 3, 4))
int abii_sgetspent_r(const char* string, spwd* result_buf, char* buffer, size_t buflen, spwd** result)
{
    OVERRIDE_PREFIX(sgetspent_r)
        pre_fmtd_str pi_str = "sgetspent_r(__string, __result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_sgetspent_r(string, result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sgetspent_r, abii_ret)
    return real_sgetspent_r(string, result_buf, buffer, buflen, result);
}

static int (*real_fgetspent_r)(FILE*, spwd*, char*, size_t, spwd**) = nullptr;

extern "C" __attr_access((__write_only__, 3, 4))
int abii_fgetspent_r(FILE* stream, spwd* result_buf, char* buffer, size_t buflen, spwd** result)
{
    OVERRIDE_PREFIX(fgetspent_r)
        pre_fmtd_str pi_str = "fgetspent_r(__stream, __result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_fgetspent_r(stream, result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetspent_r, abii_ret)
    return real_fgetspent_r(stream, result_buf, buffer, buflen, result);
}

static int (*real_lckpwdf)() __THROW = nullptr;

extern "C" int abii_lckpwdf() __THROW
{
    OVERRIDE_PREFIX(lckpwdf)
        pre_fmtd_str pi_str = "lckpwdf()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_lckpwdf();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lckpwdf, abii_ret)
    return real_lckpwdf();
}

static int (*real_ulckpwdf)() __THROW = nullptr;

extern "C" int abii_ulckpwdf() __THROW
{
    OVERRIDE_PREFIX(ulckpwdf)
        pre_fmtd_str pi_str = "ulckpwdf()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_ulckpwdf();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ulckpwdf, abii_ret)
    return real_ulckpwdf();
}
}
