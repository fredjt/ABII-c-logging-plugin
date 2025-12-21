//
// Created by Trent Tanchin on 3/7/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_TIME_H
#define ABII_C_LOGGING_PLUGIN_TIME_H

#include <abii/libabii.h>

namespace abii
{
const defines_map time_clock = {
    {0, "CLOCK_REALTIME"},
    {1, "CLOCK_MONOTONIC"},
    {2, "CLOCK_PROCESS_CPUTIME_ID"},
    {3, "CLOCK_THREAD_CPUTIME_ID"},
    {4, "CLOCK_MONOTONIC_RAW"},
    {5, "CLOCK_REALTIME_COARSE"},
    {6, "CLOCK_MONOTONIC_COARSE"},
    {7, "CLOCK_BOOTTIME"},
    {8, "CLOCK_REALTIME_ALARM"},
    {9, "CLOCK_BOOTTIME_ALARM"},
    {11, "CLOCK_TAI"}
};

template <typename T>
std::string print_time_clock(const T v)
{
    return print_enum_entry(v, time_clock);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TIME_H
