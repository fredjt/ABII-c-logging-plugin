//
// Created by Trent Tanchin on 10/4/24.
//

#include <abii/libabii.h>

#include "custom_printers.h"
#include "bits/types/__locale_t.h"

namespace abii
{
static ssize_t (*real_strfmon)(char*, size_t, const char*, ...) __THROW = nullptr;

extern "C" __attribute_format_strfmon__(3, 4) __attr_access((__write_only__, 1, 2))
ssize_t abii_strfmon(char* s, size_t maxsize, const char* format, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(strfmon, format)
        pre_fmtd_str str = "strfmon(__s, __maxsize, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(maxsize);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(maxsize, "__maxsize"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, format, print_variadic_args_strfmon, maxsize)

        const auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_strfmon), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(*reinterpret_cast<ssize_t*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(strfmon, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_strfmon), abii_bi_vargs, 1000));
}

static ssize_t (*real_strfmon_l)(char*, size_t, locale_t, const char*, ...) __THROW = nullptr;

extern "C" __attribute_format_strfmon__(4, 5) __attr_access((__write_only__, 1, 2))
ssize_t abii_strfmon_l(char* s, size_t maxsize, locale_t loc, const char* format, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(strfmon_l, format)
        pre_fmtd_str str = "strfmon_l(__s, __maxsize, __loc, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(maxsize);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(maxsize, "__maxsize"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, format, print_variadic_args_strfmon, maxsize)

        const auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_strfmon_l), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(*reinterpret_cast<ssize_t*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(strfmon_l, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_strfmon_l), abii_bi_vargs, 1000));
}
}
