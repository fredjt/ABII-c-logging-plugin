//
// Created by Trent Tanchin on 6/1/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_STD_EXT_H
#define ABII_C_LOGGING_PLUGIN_STD_EXT_H

#include <stdio_ext.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map stdio_ext_fsetlocking_type = {
    {0, "FSETLOCKING_QUERY"},
    {1, "FSETLOCKING_INTERNAL"},
    {2, "FSETLOCKING_BYCALLER"}
};

template <typename T>
std::string print_stdio_ext_fsetlocking_type(const T v)
{
    return print_enum_entry(v, stdio_ext_fsetlocking_type);
}
}

#endif //ABII_C_LOGGING_PLUGIN_STD_EXT_H
