//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_TERMIOS_H
#define ABII_C_LOGGING_PLUGIN_BITS_TERMIOS_H

#include <abii/libabii.h>

namespace abii
{
const defines_map termios_baud_rate = {
    {0000000, "__B0"},
    {0000001, "__B50"},
    {0000002, "__B75"},
    {0000003, "__B110"},
    {0000004, "__B134"},
    {0000005, "__B150"},
    {0000006, "__B200"},
    {0000007, "__B300"},
    {0000010, "__B600"},
    {0000011, "__B1200"},
    {0000012, "__B1800"},
    {0000013, "__B2400"},
    {0000014, "__B4800"},
    {0000015, "__B9600"},
    {0000016, "__B19200"},
    {0000017, "__B38400"},
    {0000016, "__EXTA"},
    {0000017, "__EXTB"},
    {0010000, "BOTHER"}
};

const defines_map termios_tiocser_temt = {
    {0x01, "TIOCSER_TEMT"}
};

const defines_map termios_tcio = {
    {0, "TCOOFF"},
    {1, "TCOON"},
    {2, "TCIOFF"},
    {3, "TCION"}
};

const defines_map termios_tcioflush = {
    {0, "TCIFLUSH"},
    {1, "TCOFLUSH"},
    {2, "TCIOFLUSH"}
};

template <typename T>
std::string print_termios_baud_rate(const T v)
{
    return print_enum_entry(v, termios_baud_rate);
}

template <typename T>
std::string print_termios_tiocser_temt(const T v)
{
    return print_enum_entry(v, termios_tiocser_temt);
}

template <typename T>
std::string print_termios_tcio(const T v)
{
    return print_enum_entry(v, termios_tcio);
}

template <typename T>
std::string print_termios_tcioflush(const T v)
{
    return print_enum_entry(v, termios_tcioflush);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_TERMIOS_H
