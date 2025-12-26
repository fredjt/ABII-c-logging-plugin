//
// Created by Trent Tanchin on 9/17/24.
//

#include "fnmatch.h"

namespace abii
{
static int (*real_fnmatch)(const char*, const char*, int) = nullptr;

extern "C" int abii_fnmatch(const char* pattern, const char* name, int flags)
{
    OVERRIDE_PREFIX(fnmatch)
        pre_fmtd_str str = "fnmatch(__pattern, __name, __flags)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(pattern, "__pattern"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_fnmatch_flag, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_fnmatch(pattern, name, flags);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_fnmatch_ret, abii_ret);
        abii_args->push_return(printer1);

    OVERRIDE_SUFFIX(fnmatch, abii_ret)
    return real_fnmatch(pattern, name, flags);
}
}
