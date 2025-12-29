//
// Created by Trent Tanchin on 12/27/24.
//

#include "printf.h"

#include "stdint.h"

namespace abii
{
static int (*real_register_printf_specifier)(int, printf_function, printf_arginfo_size_function) __THROW = nullptr;

extern "C" int abii_register_printf_specifier(int spec, printf_function func,
                                              printf_arginfo_size_function arginfo) __THROW
{
    OVERRIDE_PREFIX(register_printf_specifier)
        pre_fmtd_str pi_str = "register_printf_specifier(__spec, __func, __arginfo)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(spec, "__spec"));
        abii_args->push_arg(new ArgPrinter(func, "__func"));
        abii_args->push_arg(new ArgPrinter(arginfo, "__arginfo"));

        auto abii_ret = real_register_printf_specifier(spec, func, arginfo);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(register_printf_specifier, abii_ret)
    return real_register_printf_specifier(spec, func, arginfo);
}

static int (*real_register_printf_function)(int, printf_function, printf_arginfo_function) __THROW = nullptr;

extern "C" __attribute_deprecated__
int abii_register_printf_function(int spec, printf_function func, printf_arginfo_function arginfo) __THROW
{
    OVERRIDE_PREFIX(register_printf_function)
        pre_fmtd_str pi_str = "register_printf_function(__spec, __func, __arginfo)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(spec, "__spec"));
        abii_args->push_arg(new ArgPrinter(func, "__func"));
        abii_args->push_arg(new ArgPrinter(arginfo, "__arginfo"));

        auto abii_ret = real_register_printf_function(spec, func, arginfo);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(register_printf_function, abii_ret)
    return real_register_printf_function(spec, func, arginfo);
}

static int (*real_register_printf_modifier)(const wchar_t*) __THROW = nullptr;

extern "C" __wur int abii_register_printf_modifier(const wchar_t* str) __THROW
{
    OVERRIDE_PREFIX(register_printf_modifier)
        pre_fmtd_str pi_str = "register_printf_modifier(__str)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(str, "__str");
        printer->set_enum_printer_with_depth(print_stdint_wchar, *str, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_register_printf_modifier(str);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(register_printf_modifier, abii_ret)
    return real_register_printf_modifier(str);
}

static int (*real_register_printf_type)(printf_va_arg_function) __THROW = nullptr;

extern "C" __wur int abii_register_printf_type(printf_va_arg_function fct) __THROW
{
    OVERRIDE_PREFIX(register_printf_type)
        pre_fmtd_str pi_str = "register_printf_type(__fct)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fct, "__fct"));

        auto abii_ret = real_register_printf_type(fct);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(register_printf_type, abii_ret)
    return real_register_printf_type(fct);
}

static size_t (*real_parse_printf_format)(const char*, size_t, int*) __THROW = nullptr;

extern "C" size_t abii_parse_printf_format(const char* fmt, size_t n, int* argtypes) __THROW
{
    OVERRIDE_PREFIX(parse_printf_format)
        pre_fmtd_str pi_str = "parse_printf_format(__fmt, __n, __argtypes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fmt, "__fmt"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(argtypes, "__argtypes"));

        auto abii_ret = real_parse_printf_format(fmt, n, argtypes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(parse_printf_format, abii_ret)
    return real_parse_printf_format(fmt, n, argtypes);
}

static int (*real_printf_size)(FILE*, const printf_info*, const void* const*) __THROW = nullptr;

extern "C" int abii_printf_size(FILE* fp, const printf_info* info, const void* const * args) __THROW
{
    OVERRIDE_PREFIX(printf_size)
        pre_fmtd_str pi_str = "printf_size(__fp, __info, __abii_args)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));
        abii_args->push_arg(new ArgPrinter(info, "__info"));
        abii_args->push_arg(new ArgPrinter(args, "__args"));

        auto abii_ret = real_printf_size(fp, info, args);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(printf_size, abii_ret)
    return real_printf_size(fp, info, args);
}

static int (*real_printf_size_info)(const printf_info*, size_t, int*) __THROW = nullptr;

extern "C" int abii_printf_size_info(const printf_info* info, size_t n, int* argtypes) __THROW
{
    OVERRIDE_PREFIX(printf_size_info)
        pre_fmtd_str pi_str = "printf_size_info(__info, __n, __argtypes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(info, "__info"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(argtypes, "__argtypes"));

        auto abii_ret = real_printf_size_info(info, n, argtypes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(printf_size_info, abii_ret)
    return real_printf_size_info(info, n, argtypes);
}
}
