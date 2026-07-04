//
// Created by Trent Tanchin on 7/4/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_ULIMIT_H
#define ABII_C_LOGGING_PLUGIN_ULIMIT_H

#include <abii/libabii.h>

namespace abii
{
const defines_map ulimit_cmd = {
    {1, "UL_GETFSIZE"},
    {2, "UL_SETFSIZE"},
    {3, "__UL_GETMAXBRK"},
    {4, "__UL_GETOPENMAX"}
};

template <typename T>
std::string print_ulimit_cmd(const T v)
{
    return print_enum_entry(v, ulimit_cmd);
}
}

#endif //ABII_C_LOGGING_PLUGIN_ULIMIT_H
