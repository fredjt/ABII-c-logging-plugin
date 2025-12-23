//
// Created by Trent Tanchin on 5/26/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_STACK_T_H
#define ABII_C_LOGGING_PLUGIN_STACK_T_H

#include <abii/libabii.h>
#include <bits/types/stack_t.h>

#include "include/bits/ss_flags.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, stack_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ss_sp, "ss_sp", &os));

    auto printer = ArgPrinter(obj.ss_flags, "ss_flags", &os);
    printer.set_enum_printer(print_ss_flags_flag, obj.ss_flags);
    abii_args->push_arg(&printer);

    abii_args->push_arg(new ArgPrinter(obj.ss_size, "ss_size", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_STACK_T_H
