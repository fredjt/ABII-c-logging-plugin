//
// Created by Trent Tanchin on 8/17/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_FCNTL_H
#define ABII_C_LOGGING_PLUGIN_FCNTL_H

#include <abii/libabii.h>

#include "fcntl-linux.h"
#include "include/stdio.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, flock>
    || std::is_same_v<std::remove_cvref_t<T>, flock64>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.l_type, "l_type", &os);
    printer->set_enum_printer(print_fcntl_linux_enum6, obj.l_type);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.l_whence, "l_whence", &os);
    printer1->set_enum_printer(print_stdio_seek_whence, obj.l_whence);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.l_start, "l_start", &os));
    abii_args->push_arg(new ArgPrinter(obj.l_len, "l_len", &os));
    abii_args->push_arg(new ArgPrinter(obj.l_pid, "l_pid", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_FCNTL_H
