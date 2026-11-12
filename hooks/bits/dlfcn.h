//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_DLFCN_H
#define ABII_C_LOGGING_PLUGIN_BITS_DLFCN_H

#include <abii/libabii.h>

namespace abii
{
const defines_map bits_dlfcn_rtld = {
    {0x00001, "RTLD_LAZY"},
    {0x00002, "RTLD_NOW"},
    {0x3, "RTLD_BINDING_MASK"},
    {0x00004, "RTLD_NOLOAD"},
    {0x00008, "RTLD_DEEPBIND"},
    {0x00100, "RTLD_GLOBAL"},
    {0, "RTLD_LOCAL"},
    {0x01000, "RTLD_NODELETE"}
};

template <typename T>
std::string print_bits_dlfcn_rtld(const T v)
{
    return print_enum_entry(v, bits_dlfcn_rtld);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_DLFCN_H
