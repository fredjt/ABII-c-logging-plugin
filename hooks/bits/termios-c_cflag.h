//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_C_CFLAG_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_C_CFLAG_H

#include <abii/libabii.h>

namespace abii
{
const defines_map termios_c_cflag_flags = {
    {0000060, "CSIZE"},
    {0000000, "CS5"},
    {0000020, "CS6"},
    {0000040, "CS7"},
    {0000060, "CS8"},
    {0000100, "CSTOPB"},
    {0000200, "CREAD"},
    {0000400, "PARENB"},
    {0001000, "PARODD"},
    {0002000, "HUPCL"},
    {0004000, "CLOCAL"},
    {04000000000, "ADDRB"},
    {010000000000, "CMSPAR"},
    {020000000000, "CRTSCTS"}
};

template <typename T>
std::string print_termios_c_cflag_flags(const T v)
{
    return print_or_enum_entries(v, termios_c_cflag_flags);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_C_CFLAG_H
