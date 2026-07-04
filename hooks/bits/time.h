//
// Created by Trent Tanchin on 3/7/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_TIME_H
#define ABII_C_LOGGING_PLUGIN_BITS_TIME_H

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

const defines_map time_timer_abstime = {
    {1, "TIMER_ABSTIME"}
};

template <typename T>
std::string print_time_clock(const T v)
{
    return print_enum_entry(v, time_clock);
}

template <typename T>
std::string print_time_timer_abstime(const T v)
{
    return print_or_enum_entries(v, time_timer_abstime);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_TIME_H
