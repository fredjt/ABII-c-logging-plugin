//
// Created by Trent Tanchin on 3/10/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_STRUCT_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_STRUCT_H

#include <termios.h>
#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, termios>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.c_iflag, "c_iflag", &os));
    abii_args->push_arg(new ArgPrinter(obj.c_oflag, "c_oflag", &os));
    abii_args->push_arg(new ArgPrinter(obj.c_cflag, "c_cflag", &os));
    abii_args->push_arg(new ArgPrinter(obj.c_lflag, "c_lflag", &os));
    abii_args->push_arg(new ArgPrinter(obj.c_line, "c_line", &os));
    abii_args->push_arg(new ArgPrinter(obj.c_cc, "c_cc", &os));
    abii_args->push_arg(new ArgPrinter(obj.c_ispeed, "c_ispeed", &os));
    abii_args->push_arg(new ArgPrinter(obj.c_ospeed, "c_ospeed", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_STRUCT_H
