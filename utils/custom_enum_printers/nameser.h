//
// Created by Trent Tanchin on 11/11/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_UTILS_CUSTOM_ENUM_PRINTERS_NAMESER_H
#define ABII_C_LOGGING_PLUGIN_UTILS_CUSTOM_ENUM_PRINTERS_NAMESER_H

#include <abii/libabii.h>

#include "hooks/arpa/nameser.h"
#include "hooks/arpa/nameser_compat.h"

namespace abii
{
template <typename T>
std::string print_nameser_section(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_sect, nameser_compat_section);
}

template <typename T>
std::string print_nameser_opcode(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_opcode, nameser_compat_opcode);
}

template <typename T>
std::string print_nameser_rcode(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_rcode, nameser_compat_rcode);
}
}

#endif //ABII_C_LOGGING_PLUGIN_UTILS_CUSTOM_ENUM_PRINTERS_NAMESER_H
