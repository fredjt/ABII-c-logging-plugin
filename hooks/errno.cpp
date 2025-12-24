//
// Created by Trent Tanchin on 8/17/24.
//

#include <abii/libabii.h>

#include "custom_enum_printers.h"

namespace abii
{
static int* (*real___errno_location)() __THROW = nullptr;

extern "C" __attribute_const__
int* abii___errno_location() __THROW
{
    OVERRIDE_PREFIX(__errno_location)
        pre_fmtd_str str = "__errno_location()";
        abii_args->push_func(new ArgPrinter(str));

        const auto abii_ret = real___errno_location();

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer_with_depth(print_error_enum_entry, *abii_ret, 1);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(__errno_location, abii_ret)
    return real___errno_location();
}
}
