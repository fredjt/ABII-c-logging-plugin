//
// Created by Trent Tanchin on 4/17/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_NAMESER_COMPAT_H
#define ABII_C_LOGGING_PLUGIN_NAMESER_COMPAT_H

#include <abii/libabii.h>

namespace abii
{
const defines_map nameser_compat_opcode = {
    {0, "QUERY"},
    {1, "IQUERY"},
    {2, "STATUS"},
    {4, "NS_NOTIFY_OP"},
    {5, "NS_UPDATE_OP"}
};

template <typename T>
std::string print_nameser_compat_opcode(const T v)
{
    return print_enum_entry(v, nameser_compat_opcode);
}
}

#endif //ABII_C_LOGGING_PLUGIN_NAMESER_COMPAT_H
