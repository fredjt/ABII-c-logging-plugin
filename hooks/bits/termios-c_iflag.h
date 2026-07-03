//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_C_IFLAG_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_C_IFLAG_H

#include <abii/libabii.h>

namespace abii
{
const defines_map termios_c_iflag_flags = {
    {0000001, "IGNBRK"},
    {0000002, "BRKINT"},
    {0000004, "IGNPAR"},
    {0000010, "PARMRK"},
    {0000020, "INPCK"},
    {0000040, "ISTRIP"},
    {0000100, "INLCR"},
    {0000200, "IGNCR"},
    {0000400, "ICRNL"},
    {0001000, "IUCLC"},
    {0002000, "IXON"},
    {0004000, "IXANY"},
    {0010000, "IXOFF"},
    {0020000, "IMAXBEL"},
    {0040000, "IUTF8"}
};

template <typename T>
std::string print_termios_c_iflag_flags(const T v)
{
    return print_or_enum_entries(v, termios_c_iflag_flags);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_C_IFLAG_H
