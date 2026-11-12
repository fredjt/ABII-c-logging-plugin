//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_ELFCLASS_H
#define ABII_C_LOGGING_PLUGIN_BITS_ELFCLASS_H

#include <abii/libabii.h>
#include <bits/elfclass.h>

namespace abii
{
const defines_map bits_elfclass___elf_native_class = {
    {__ELF_NATIVE_CLASS, "__ELF_NATIVE_CLASS"}
};

template <typename T>
std::string print_bits_elfclass___elf_native_class(const T v)
{
    return print_enum_entry(v, bits_elfclass___elf_native_class);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_ELFCLASS_H
