//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_C_LFLAG_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_C_LFLAG_H

#include <abii/libabii.h>

namespace abii
{
const defines_map termios_c_lflag_flags = {
    {0000001, "ISIG"},
    {0000002, "ICANON"},
    {0000004, "XCASE"},
    {0000010, "ECHO"},
    {0000020, "ECHOE"},
    {0000040, "ECHOK"},
    {0000100, "ECHONL"},
    {0000200, "NOFLSH"},
    {0000400, "TOSTOP"},
    {0001000, "ECHOCTL"},
    {0002000, "ECHOPRT"},
    {0004000, "ECHOKE"},
    {0010000, "FLUSHO"},
    {0040000, "PENDIN"},
    {0100000, "IEXTEN"},
    {0200000, "EXTPROC"}
};

template <typename T>
std::string print_termios_c_lflag_flags(const T v)
{
    return print_or_enum_entries(v, termios_c_lflag_flags);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_C_LFLAG_H
