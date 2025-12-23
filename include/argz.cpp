//
// Created by Trent Tanchin on 7/9/24.
//

#include <abii/libabii.h>

#include "custom_enum_printers.h"

namespace abii
{
static error_t (*real_argz_create)(char* const[], char**, size_t*) __THROW = nullptr;

extern "C" error_t abii_argz_create(char* const argv[], char** argz, size_t* len) __THROW
{
    OVERRIDE_PREFIX(argz_create)
        pre_fmtd_str str = "argz_create(__argv, __argz, __len)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = ArgPrinter(argv, "__argv");
        printer.set_end_test([&](const size_t i) { return argv[i] != nullptr; });
        abii_args->push_arg(&printer);

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_argz_create(argv, argz, len);

        auto printer1 = ArgPrinter(abii_ret, "return");
        printer1.set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(&printer1);
    OVERRIDE_SUFFIX(argz_create, abii_ret)
    return real_argz_create(argv, argz, len);
}

static error_t (*real_argz_create_sep)(const char*, int, char**, size_t*) __THROW = nullptr;

extern "C" error_t abii_argz_create_sep(const char* string, int sep, char** argz, size_t* len) __THROW
{
    OVERRIDE_PREFIX(argz_create_sep)
        pre_fmtd_str str = "argz_create_sep(__string, __sep, __argz, __len)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));
        abii_args->push_arg(new ArgPrinter(sep, "__sep"));
        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_argz_create_sep(string, sep, argz, len);

        auto printer = ArgPrinter(abii_ret, "return");
        printer.set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(&printer);
    OVERRIDE_SUFFIX(argz_create_sep, abii_ret)
    return real_argz_create_sep(string, sep, argz, len);
}

static size_t (*real_argz_count)(const char*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__
size_t abii_argz_count(const char* argz, size_t len) __THROW
{
    OVERRIDE_PREFIX(argz_count)
        pre_fmtd_str str = "argz_count(__argz, __len)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_argz_count(argz, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(argz_count, abii_ret)
    return real_argz_count(argz, len);
}

static void (*real_argz_extract)(const char*, size_t, char**) __THROW = nullptr;

extern "C" void abii_argz_extract(const char* argz, size_t len, char** argv) __THROW
{
    OVERRIDE_PREFIX(argz_extract)
        pre_fmtd_str str = "argz_extract(__argz, __len, __argv)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto printer = ArgPrinter(argv, "__argv");
        printer.set_end_test([&](const size_t i) { return argv[i] != nullptr; });
        abii_args->push_arg(&printer);

        real_argz_extract(argz, len, argv);
    OVERRIDE_SUFFIX(argz_extract,)
    return real_argz_extract(argz, len, argv);
}

static void (*real_argz_stringify)(char*, size_t, int) __THROW = nullptr;

extern "C" void abii_argz_stringify(char* argz, size_t len, int sep) __THROW
{
    OVERRIDE_PREFIX(argz_stringify)
        pre_fmtd_str str = "argz_stringify(__argz, __len, __sep)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));
        abii_args->push_arg(new ArgPrinter(sep, "__sep"));

        real_argz_stringify(argz, len, sep);
    OVERRIDE_SUFFIX(argz_stringify,)
    return real_argz_stringify(argz, len, sep);
}

static error_t (*real_argz_append)(char**, size_t*, const char*, size_t) __THROW = nullptr;

extern "C" error_t abii_argz_append(char** argz, size_t* argz_len, const char* buf, size_t buf_len) __THROW
{
    OVERRIDE_PREFIX(argz_append)
        pre_fmtd_str str = "argz_append(__argz, __argz_len, __buf, __buf_len)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(argz_len, "__argz_len"));
        abii_args->push_arg(new ArgPrinter(buf, "__buf"));
        abii_args->push_arg(new ArgPrinter(buf_len, "__buf_len"));

        auto abii_ret = real_argz_append(argz, argz_len, buf, buf_len);

        auto printer = ArgPrinter(abii_ret, "return");
        printer.set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(&printer);
    OVERRIDE_SUFFIX(argz_append, abii_ret)
    return real_argz_append(argz, argz_len, buf, buf_len);
}

static error_t (*real_argz_add)(char**, size_t*, const char*) __THROW = nullptr;

extern "C" error_t abii_argz_add(char** argz, size_t* argz_len, const char* str) __THROW
{
    OVERRIDE_PREFIX(argz_add)
        pre_fmtd_str str1 = "argz_add(__argz, __argz_len, __str)";
        abii_args->push_func(new ArgPrinter(str1));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(argz_len, "__argz_len"));
        abii_args->push_arg(new ArgPrinter(str, "__str"));

        auto abii_ret = real_argz_add(argz, argz_len, str);

        auto printer = ArgPrinter(abii_ret, "return");
        printer.set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(&printer);
    OVERRIDE_SUFFIX(argz_add, abii_ret)
    return real_argz_add(argz, argz_len, str);
}

static error_t (*real_argz_add_sep)(char**, size_t*, const char*, int) __THROW = nullptr;

extern "C" error_t abii_argz_add_sep(char** argz, size_t* argz_len, const char* string, int delim) __THROW
{
    OVERRIDE_PREFIX(argz_add_sep)
        pre_fmtd_str str = "argz_add_sep(__argz, __argz_len, __string, __delim)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(argz_len, "__argz_len"));
        abii_args->push_arg(new ArgPrinter(string, "__string"));
        abii_args->push_arg(new ArgPrinter(delim, "__delim"));

        auto abii_ret = real_argz_add_sep(argz, argz_len, string, delim);

        auto printer = ArgPrinter(abii_ret, "return");
        printer.set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(&printer);
    OVERRIDE_SUFFIX(argz_add_sep, abii_ret)
    return real_argz_add_sep(argz, argz_len, string, delim);
}

static void (*real_argz_delete)(char**, size_t*, char*) __THROW = nullptr;

extern "C" void abii_argz_delete(char** argz, size_t* argz_len, char* entry) __THROW
{
    OVERRIDE_PREFIX(argz_delete)
        pre_fmtd_str str = "argz_delete(__argz, __argz_len, __entry)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(argz_len, "__argz_len"));
        abii_args->push_arg(new ArgPrinter(entry, "__entry"));

        real_argz_delete(argz, argz_len, entry);
    OVERRIDE_SUFFIX(argz_delete,)
    return real_argz_delete(argz, argz_len, entry);
}

static error_t (*real_argz_insert)(char**, size_t*, char*, const char*) __THROW = nullptr;

extern "C" error_t abii_argz_insert(char** argz, size_t* argz_len, char* before, const char* entry) __THROW
{
    OVERRIDE_PREFIX(argz_insert)
        pre_fmtd_str str = "argz_insert(__argz, __argz_len, __before, __entry)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(argz_len, "__argz_len"));
        abii_args->push_arg(new ArgPrinter(before, "__before"));
        abii_args->push_arg(new ArgPrinter(entry, "__entry"));

        auto abii_ret = real_argz_insert(argz, argz_len, before, entry);

        auto printer = ArgPrinter(abii_ret, "return");
        printer.set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(&printer);
    OVERRIDE_SUFFIX(argz_insert, abii_ret)
    return real_argz_insert(argz, argz_len, before, entry);
}

static error_t (*real_argz_replace)(char**, size_t*, const char*, const char*, unsigned int*) = nullptr;

extern "C" error_t abii_argz_replace(char** argz, size_t* argz_len, const char* str, const char* with,
                                     unsigned int* replace_count)
{
    OVERRIDE_PREFIX(argz_replace)
        pre_fmtd_str str1 = "argz_replace(__argz, __argz_len, __str, __with, __replace_count)";
        abii_args->push_func(new ArgPrinter(str1));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(argz_len, "__argz_len"));
        abii_args->push_arg(new ArgPrinter(str, "__str"));
        abii_args->push_arg(new ArgPrinter(with, "__with"));
        abii_args->push_arg(new ArgPrinter(replace_count, "__replace_count"));

        auto abii_ret = real_argz_replace(argz, argz_len, str, with, replace_count);

        auto printer = ArgPrinter(abii_ret, "return");
        printer.set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(&printer);
    OVERRIDE_SUFFIX(argz_replace, abii_ret)
    return real_argz_replace(argz, argz_len, str, with, replace_count);
}

static char* (*real_argz_next)(const char*, size_t, const char*) __THROW = nullptr;

extern "C" char* abii_argz_next(const char* argz, size_t argz_len, const char* entry) __THROW
{
    OVERRIDE_PREFIX(argz_next)
        pre_fmtd_str str = "argz_next(__argz, __argz_len, __entry)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argz, "__argz"));
        abii_args->push_arg(new ArgPrinter(argz_len, "__argz_len"));
        abii_args->push_arg(new ArgPrinter(entry, "__entry"));

        auto abii_ret = real_argz_next(argz, argz_len, entry);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(argz_next, abii_ret)
    return real_argz_next(argz, argz_len, entry);
}
}
