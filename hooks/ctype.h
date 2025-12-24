//
// Created by Trent Tanchin on 7/27/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_CTYPE_H
#define ABII_C_LOGGING_PLUGIN_CTYPE_H

#include <abii/libabii.h>

namespace abii
{
const defines_map ctype_type = {
    {256, "_ISupper"},
    {512, "_ISlower"},
    {1024, "_ISalpha"},
    {2048, "_ISdigit"},
    {4096, "_ISxdigit"},
    {8192, "_ISspace"},
    {16384, "_ISprint"},
    {32768, "_ISgraph"},
    {1, "_ISblank"},
    {2, "_IScntrl"},
    {4, "_ISpunct"},
    {8, "_ISalnum"}
};

template <typename T>
std::string print_ctype_enum(const T v)
{
    return print_enum_entry(v, ctype_type);
}
}

#endif //ABII_C_LOGGING_PLUGIN_CTYPE_H
