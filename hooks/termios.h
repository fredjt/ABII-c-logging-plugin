//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_H

#include <abii/libabii.h>

namespace abii
{
const defines_map<unsigned> termios_baud_max = {
    {4294967295U, "BAUD_MAX"}
};

template <typename T>
std::string print_termios_baud_max(const T v)
{
    return print_enum_entry(v, termios_baud_max);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_H
