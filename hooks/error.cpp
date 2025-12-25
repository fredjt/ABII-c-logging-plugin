//
// Created by Trent Tanchin on 8/17/24.
//

#include <abii/libabii.h>

#include "custom_enum_printers.h"
#include "custom_printers.h"

namespace abii
{
static void (*real_error)(int, int, const char*, ...) = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 3, 4))) __COLD
void abii_error(int status, int errnum, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(error, format)
        pre_fmtd_str str = "error(__state, __status, __errnum, __fmt, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));

        auto printer = new ArgPrinter(errnum, "__errnum");
        printer->set_enum_printer(print_error_enum_entry, errnum);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, format, print_variadic_args_printf)

        if (status != 0)
        {
            va_start(abii_vargs, format);
            abii_args->print_args();
            va_end(abii_vargs);
            abii_stream << std::endl;
        }

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_error), abii_bi_vargs, 1000);
    OVERRIDE_VARIADIC_SUFFIX(error, abii_ret, format)
    __builtin_apply(reinterpret_cast<void (*)(...)>(real_error), abii_bi_vargs, 1000);
}

static void (*real_error_at_line)(int, int, const char*, unsigned int, const char*, ...) = nullptr;

__attribute__ ((__format__ (__printf__, 5, 6))) __COLD
void error_at_line(int status, int errnum, const char* fname, unsigned int lineno, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(error_at_line, format)
        pre_fmtd_str str = "error_at_line(__status, __errnum, __fname, __lineno, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));

        auto printer = new ArgPrinter(errnum, "__errnum");
        printer->set_enum_printer(print_error_enum_entry, errnum);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(fname, "__fname"));
        abii_args->push_arg(new ArgPrinter(lineno, "__lineno"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, format, print_variadic_args_printf)

        if (status != 0)
        {
            va_start(abii_vargs, format);
            abii_args->print_args();
            va_end(abii_vargs);
            abii_stream << std::endl;
        }

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_error_at_line), abii_bi_vargs, 1000);
    OVERRIDE_VARIADIC_SUFFIX(error_at_line, abii_ret, format)
    __builtin_apply(reinterpret_cast<void (*)(...)>(real_error_at_line), abii_bi_vargs, 1000);
}
}
