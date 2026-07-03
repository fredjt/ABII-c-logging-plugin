//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_BAUD_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_BAUD_H

#include <abii/libabii.h>

namespace abii
{
const defines_map<unsigned> termios_baud_rate = {
    {0U, "B0"},
    {50U, "B50"},
    {75U, "B75"},
    {110U, "B110"},
    {134U, "B134"},
    {150U, "B150"},
    {200U, "B200"},
    {300U, "B300"},
    {600U, "B600"},
    {1200U, "B1200"},
    {1800U, "B1800"},
    {2400U, "B2400"},
    {4800U, "B4800"},
    {9600U, "B9600"},
    {19200U, "B19200"},
    {38400U, "B38400"},
    {19200U, "EXTA"},
    {38400U, "EXTB"},
    {7200U, "B7200"},
    {14400U, "B14400"},
    {28800U, "B28800"},
    {33600U, "B33600"},
    {57600U, "B57600"},
    {76800U, "B76800"},
    {115200U, "B115200"},
    {153600U, "B153600"},
    {230400U, "B230400"},
    {307200U, "B307200"},
    {460800U, "B460800"},
    {500000U, "B500000"},
    {576000U, "B576000"},
    {614400U, "B614400"},
    {921600U, "B921600"},
    {1000000U, "B1000000"},
    {1152000U, "B1152000"},
    {1500000U, "B1500000"},
    {2000000U, "B2000000"},
    {2500000U, "B2500000"},
    {3000000U, "B3000000"},
    {3500000U, "B3500000"},
    {4000000U, "B4000000"},
    {5000000U, "B5000000"},
    {10000000U, "B10000000"},
    {4294967295U, "SPEED_MAX"},
    {4294967295U, "__MAX_BAUD"}
};

template <typename T>
std::string print_termios_baud_rate(const T v)
{
    return print_enum_entry(v, termios_baud_rate);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_BAUD_H
