//
// Created by Trent Tanchin on 8/8/24.
//

#include <abii/libabii.h>

#include "custom_enum_printers.h"

namespace abii
{
static char* (*real_envz_entry)(const char*, size_t, const char*) __THROW = nullptr;

extern "C" __attribute_pure__
char* abii_envz_entry(const char* envz, size_t envz_len, const char* name) __THROW
{
    OVERRIDE_PREFIX(envz_entry)
        pre_fmtd_str str = "envz_entry(__envz, __envz_len, __name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(envz, "__envz"));
        abii_args->push_arg(new ArgPrinter(envz_len, "__envz_len"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto pi_ret = real_envz_entry(envz, envz_len, name);

        abii_args->push_return(new ArgPrinter(pi_ret, "return"));
    OVERRIDE_SUFFIX(envz_entry, pi_ret)
    return real_envz_entry(envz, envz_len, name);
}

static char* (*real_envz_get)(const char*, size_t, const char*) __THROW = nullptr;

extern "C" __attribute_pure__
char* abii_envz_get(const char* envz, size_t envz_len, const char* name) __THROW
{
    OVERRIDE_PREFIX(envz_get)
        pre_fmtd_str str = "envz_get(__envz, __envz_len, __name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(envz, "__envz"));
        abii_args->push_arg(new ArgPrinter(envz_len, "__envz_len"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto pi_ret = real_envz_get(envz, envz_len, name);

        abii_args->push_return(new ArgPrinter(pi_ret, "return"));
    OVERRIDE_SUFFIX(envz_get, pi_ret)
    return real_envz_get(envz, envz_len, name);
}

static error_t (*real_envz_add)(char**, size_t*, const char*, const char*) __THROW = nullptr;

extern "C" error_t abii_envz_add(char** envz, size_t* envz_len, const char* name, const char* value) __THROW
{
    OVERRIDE_PREFIX(envz_add)
        pre_fmtd_str str = "envz_add(__envz, __envz_len, __name, __value)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(envz, "__envz"));
        abii_args->push_arg(new ArgPrinter(envz_len, "__envz_len"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(value, "__value"));

        auto pi_ret = real_envz_add(envz, envz_len, name, value);

        auto printer = ArgPrinter(pi_ret, "return");
        printer.set_enum_printer(print_error_enum_entry, pi_ret);
        abii_args->push_return(&printer);
    OVERRIDE_SUFFIX(envz_add, pi_ret)
    return real_envz_add(envz, envz_len, name, value);
}

static error_t (*real_envz_merge)(char**, size_t*, const char*, size_t, int) __THROW = nullptr;

extern "C" error_t abii_envz_merge(char** envz, size_t* envz_len, const char* envz2, size_t envz2_len,
                                   int override) __THROW
{
    OVERRIDE_PREFIX(envz_merge)
        pre_fmtd_str str = "envz_merge(__envz, __envz_len, __envz2, __envz2_len, __override)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(envz, "__envz"));
        abii_args->push_arg(new ArgPrinter(envz_len, "__envz_len"));
        abii_args->push_arg(new ArgPrinter(envz2, "__envz2"));
        abii_args->push_arg(new ArgPrinter(envz2_len, "__envz2_len"));
        abii_args->push_arg(new ArgPrinter(override, "__override"));

        auto pi_ret = real_envz_merge(envz, envz_len, envz2, envz2_len, override);

        auto printer = ArgPrinter(pi_ret, "return");
        printer.set_enum_printer(print_error_enum_entry, pi_ret);
        abii_args->push_return(&printer);
    OVERRIDE_SUFFIX(envz_merge, pi_ret)
    return real_envz_merge(envz, envz_len, envz2, envz2_len, override);
}

static void (*real_envz_remove)(char**, size_t*, const char*) __THROW = nullptr;

extern "C" void abii_envz_remove(char** envz, size_t* envz_len, const char* name) __THROW
{
    OVERRIDE_PREFIX(envz_remove)
        pre_fmtd_str str = "envz_remove(__envz, __envz_len, __name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(envz, "__envz"));
        abii_args->push_arg(new ArgPrinter(envz_len, "__envz_len"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));

        real_envz_remove(envz, envz_len, name);
    OVERRIDE_SUFFIX(envz_remove,)
    return real_envz_remove(envz, envz_len, name);
}

static void (*real_envz_strip)(char**, size_t*) __THROW = nullptr;

extern "C" void abii_envz_strip(char** envz, size_t* envz_len) __THROW
{
    OVERRIDE_PREFIX(envz_strip)
        pre_fmtd_str str = "envz_strip(__envz, __envz_len)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(envz, "__envz"));
        abii_args->push_arg(new ArgPrinter(envz_len, "__envz_len"));

        real_envz_strip(envz, envz_len);
    OVERRIDE_SUFFIX(envz_strip,)
    return real_envz_strip(envz, envz_len);
}
}
