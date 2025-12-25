//
// Created by Trent Tanchin on 7/4/24.
//

#include "aliases.h"

namespace abii
{
static void (*real_setaliasent)() __THROW = nullptr;

extern "C" void abii_setaliasent() __THROW
{
    OVERRIDE_PREFIX(setaliasent)
        pre_fmtd_str str = "setaliasent()";
        abii_args->push_func(new ArgPrinter(str));

        real_setaliasent();
    OVERRIDE_SUFFIX(setaliasent,)
    return real_setaliasent();
}

static void (*real_endaliasent)() __THROW = nullptr;

extern "C" void abii_endaliasent() __THROW
{
    OVERRIDE_PREFIX(endaliasent)
        pre_fmtd_str str = "endaliasent()";
        abii_args->push_func(new ArgPrinter(str));

        real_endaliasent();
    OVERRIDE_SUFFIX(endaliasent,)
    return real_endaliasent();
}

static aliasent* (*real_getaliasent)() __THROW = nullptr;

extern "C" aliasent* abii_getaliasent() __THROW
{
    OVERRIDE_PREFIX(getaliasent)
        pre_fmtd_str str = "getaliasent()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real_getaliasent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getaliasent, abii_ret)
    return real_getaliasent();
}

static int (*real_getaliasent_r)(aliasent*, char*, size_t, aliasent**) __THROW = nullptr;

extern "C" int abii_getaliasent_r(aliasent* result_buf, char* buffer, size_t buflen, aliasent** result) __THROW
{
    OVERRIDE_PREFIX(getaliasent_r)
        pre_fmtd_str str = "getaliasent_r(__result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getaliasent_r(result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getaliasent, abii_ret)
    return real_getaliasent_r(result_buf, buffer, buflen, result);
}

static aliasent* (*real_getaliasbyname)(const char*) __THROW = nullptr;

extern "C" aliasent* abii_getaliasbyname(const char* name) __THROW
{
    OVERRIDE_PREFIX(getaliasbyname)
        pre_fmtd_str str = "getaliasbyname(__name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getaliasbyname(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getaliasbyname, abii_ret)
    return real_getaliasbyname(name);
}

static int (*real_getaliasbyname_r)(const char*, aliasent*, char*, size_t, aliasent**) __THROW = nullptr;

extern "C" int abii_getaliasbyname_r(const char* name, aliasent* result_buf, char* buffer, size_t buflen,
                                     aliasent** result) __THROW
{
    OVERRIDE_PREFIX(getaliasbyname_r)
        pre_fmtd_str str = "getaliasbyname_r(__name, __result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getaliasbyname_r(name, result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getaliasbyname_r, abii_ret)
    return real_getaliasbyname_r(name, result_buf, buffer, buflen, result);
}
}
