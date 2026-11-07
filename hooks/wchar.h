//
// Created by Trent Tanchin on 9/26/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_WCHAR_H
#define ABII_C_LOGGING_PLUGIN_WCHAR_H

#include <abii/libabii.h>

namespace abii
{
const defines_map wchar_minmax = {
    {(-0x7fffffff - 1), "WCHAR_MIN"},
    {0x7fffffff, "WCHAR_MAX"}
};

const defines_map wchar_weof = {
    {0xffffffffu, "WEOF"}
};

template <typename T>
std::string print_wchar_minmax(const T v)
{
    return print_enum_entry(v, wchar_minmax);
}

template <typename T>
std::string print_wchar_weof(const T v)
{
    return print_enum_entry(v, wchar_weof);
}
}

#endif //ABII_C_LOGGING_PLUGIN_WCHAR_H
