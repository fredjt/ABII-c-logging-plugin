//
// Created by Trent Tanchin on 5/31/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_STDBIT_H
#define ABII_C_LOGGING_PLUGIN_STDBIT_H

#include <abii/libabii.h>

namespace abii
{
const defines_map stdbit_stdc_endian = {
    {1234, "__STDC_ENDIAN_LITTLE__"},
    {4321, "__STDC_ENDIAN_BIG__"},
    {1234, "__STDC_ENDIAN_NATIVE__"}
};

template <typename T>
std::string print_stdbit_stdc_endian(const T v)
{
    return print_or_enum_entries(v, stdbit_stdc_endian);
}
}

#endif //ABII_C_LOGGING_PLUGIN_STDBIT_H
