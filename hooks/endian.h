//
// Created by Trent Tanchin on 11/8/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_ENDIAN_H
#define ABII_C_LOGGING_PLUGIN_ENDIAN_H

#include <abii/libabii.h>

namespace abii
{
const defines_map endian_byte_order = {
    {LITTLE_ENDIAN, "LITTLE_ENDIAN"},
    {BIG_ENDIAN, "BIG_ENDIAN"},
    {PDP_ENDIAN, "PDP_ENDIAN"},
    {BYTE_ORDER, "BYTE_ORDER"}
};

template <typename T>
std::string print_endian_byte_order(const T v)
{
    return print_enum_entry(v, endian_byte_order);
}
}

#endif //ABII_C_LOGGING_PLUGIN_ENDIAN_H
