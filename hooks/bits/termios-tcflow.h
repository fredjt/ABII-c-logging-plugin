//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_TCFLOW_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_TCFLOW_H

#include <abii/libabii.h>

namespace abii
{
const defines_map termios_tcflow_tcsa = {
    {0, "TCSANOW"},
    {1, "TCSADRAIN"},
    {2, "TCSAFLUSH"}
};

template <typename T>
std::string print_termios_tcflow_tcsa(const T v)
{
    return print_or_enum_entries(v, termios_tcflow_tcsa);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_TCFLOW_H
