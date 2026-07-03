//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_SYSEXITS_H
#define ABII_C_LOGGING_PLUGIN_SYSEXITS_H

#include <abii/libabii.h>

namespace abii
{
const defines_map sysexits_ex = {
    {0, "EX_OK"},
    {64, "EX__BASE"},
    {64, "EX_USAGE"},
    {65, "EX_DATAERR"},
    {66, "EX_NOINPUT"},
    {67, "EX_NOUSER"},
    {68, "EX_NOHOST"},
    {69, "EX_UNAVAILABLE"},
    {70, "EX_SOFTWARE"},
    {71, "EX_OSERR"},
    {72, "EX_OSFILE"},
    {73, "EX_CANTCREAT"},
    {74, "EX_IOERR"},
    {75, "EX_TEMPFAIL"},
    {76, "EX_PROTOCOL"},
    {77, "EX_NOPERM"},
    {78, "EX_CONFIG"},
    {78, "EX__MAX"}
};

template <typename T>
std::string print_sysexits_ex(const T v)
{
    return print_enum_entry(v, sysexits_ex);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SYSEXITS_H
