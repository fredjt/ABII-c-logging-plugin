//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_ENDIANNESS_H
#define ABII_C_LOGGING_PLUGIN_BITS_ENDIANNESS_H

#include <abii/libabii.h>

namespace abii
{
const defines_map bits_endianness___byte_order = {
    {__BYTE_ORDER, "__BYTE_ORDER"}
};

template <typename T>
std::string print_bits_endianness___byte_order(const T v)
{
    return print_enum_entry(v, bits_endianness___byte_order);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_ENDIANNESS_H
