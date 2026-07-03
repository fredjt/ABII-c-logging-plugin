//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_C_OFLAG_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_C_OFLAG_H

#include <abii/libabii.h>

namespace abii
{
const defines_map termios_c_oflag_flags = {
    {0000001, "OPOST"},
    {0000002, "OLCUC"},
    {0000004, "ONLCR"},
    {0000010, "OCRNL"},
    {0000020, "ONOCR"},
    {0000040, "ONLRET"},
    {0000100, "OFILL"},
    {0000200, "OFDEL"},
    {0000400, "NLDLY"},
    {0000000, "NL0"},
    {0000400, "NL1"},
    {0003000, "CRDLY"},
    {0000000, "CR0"},
    {0001000, "CR1"},
    {0002000, "CR2"},
    {0003000, "CR3"},
    {0014000, "TABDLY"},
    {0000000, "TAB0"},
    {0004000, "TAB1"},
    {0010000, "TAB2"},
    {0014000, "TAB3"},
    {0020000, "BSDLY"},
    {0000000, "BS0"},
    {0020000, "BS1"},
    {0100000, "FFDLY"},
    {0000000, "FF0"},
    {0100000, "FF1"},
    {0040000, "VTDLY"},
    {0000000, "VT0"},
    {0040000, "VT1"},
    {0014000, "XTABS"}
};

template <typename T>
std::string print_termios_c_oflag_flags(const T v)
{
    return print_or_enum_entries(v, termios_c_oflag_flags);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_C_OFLAG_H
