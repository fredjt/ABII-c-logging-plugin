//
// Created by Trent Tanchin on 11/11/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BAUD_RATE_H
#define ABII_C_LOGGING_PLUGIN_BAUD_RATE_H

#include <abii/libabii.h>

#include "hooks/termios.h"
#include "hooks/bits/termios-baud.h"
#include "hooks/bits/termios.h"

namespace abii
{
template <typename T>
std::string print_baud_rate(const T v)
{
    return print_enum_entry(v, termios_baud_rate, termios_baud_baud_rate, termios_baud_max);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BAUD_RATE_H
