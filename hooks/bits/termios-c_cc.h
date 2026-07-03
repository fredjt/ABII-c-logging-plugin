//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_C_CC_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_C_CC_H

#include <abii/libabii.h>

namespace abii
{
const defines_map termios_c_cc_v = {
    {0, "VINTR"},
    {1, "VQUIT"},
    {2, "VERASE"},
    {3, "VKILL"},
    {4, "VEOF"},
    {5, "VTIME"},
    {6, "VMIN"},
    {7, "VSWTC"},
    {8, "VSTART"},
    {9, "VSTOP"},
    {10, "VSUSP"},
    {11, "VEOL"},
    {12, "VREPRINT"},
    {13, "VDISCARD"},
    {14, "VWERASE"},
    {15, "VLNEXT"},
    {16, "VEOL2"}
};

template <typename T>
std::string print_termios_c_cc_v(const T v)
{
    return print_enum_entry(v, termios_c_cc_v);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_C_CC_H
