//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_ENDIAN_H
#define ABII_C_LOGGING_PLUGIN_BITS_ENDIAN_H

#include <abii/libabii.h>

namespace abii
{
const defines_map bits_endian_byte_order = {
    {__LITTLE_ENDIAN, "__LITTLE_ENDIAN"},
    {__BIG_ENDIAN, "__BIG_ENDIAN"},
    {__PDP_ENDIAN, "__PDP_ENDIAN"}
};

const defines_map bits_endian___float_word_order = {
    {__FLOAT_WORD_ORDER, "__FLOAT_WORD_ORDER"}
};

template <typename T>
std::string print_bits_endian_byte_order(const T v)
{
    return print_enum_entry(v, bits_endian_byte_order);
}

template <typename T>
std::string print_bits_endian___float_word_order(const T v)
{
    return print_enum_entry(v, bits_endian___float_word_order);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_ENDIAN_H
