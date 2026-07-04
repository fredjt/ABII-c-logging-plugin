//
// Created by Trent Tanchin on 7/4/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TIME_H
#define ABII_C_LOGGING_PLUGIN_TIME_H

#include <abii/libabii.h>

namespace abii
{
const defines_map time_base = {
    {1, "TIME_UTC"},
    {2, "TIME_MONOTONIC"},
    {3, "TIME_ACTIVE"},
    {4, "TIME_THREAD_ACTIVE"}
};

template <typename T>
std::string print_time_base(const T v)
{
    return print_enum_entry(v, time_base);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TIME_H
