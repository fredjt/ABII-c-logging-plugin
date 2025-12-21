//
// Created by Trent Tanchin on 3/7/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_TIME_H
#define ABII_C_LOGGING_PLUGIN_TIME_H

#include <abii/libabii.h>
#include <bits/time.h>

namespace abii
{
const defines_map time_enum1 = {
#ifdef __USE_POSIX199309
    {CLOCK_REALTIME, "CLOCK_REALTIME"},
    {CLOCK_MONOTONIC, "CLOCK_MONOTONIC"},
    {CLOCK_PROCESS_CPUTIME_ID, "CLOCK_PROCESS_CPUTIME_ID"},
    {CLOCK_THREAD_CPUTIME_ID, "CLOCK_THREAD_CPUTIME_ID"},
    {CLOCK_MONOTONIC_RAW, "CLOCK_MONOTONIC_RAW"},
    {CLOCK_REALTIME_COARSE, "CLOCK_REALTIME_COARSE"},
    {CLOCK_MONOTONIC_COARSE, "CLOCK_MONOTONIC_COARSE"},
    {CLOCK_BOOTTIME, "CLOCK_BOOTTIME"},
    {CLOCK_REALTIME_ALARM, "CLOCK_REALTIME_ALARM"},
    {CLOCK_BOOTTIME_ALARM, "CLOCK_BOOTTIME_ALARM"},
    {CLOCK_TAI, "CLOCK_TAI"}
#endif
};

template <typename T>
std::string print_time_enum1(const T v)
{
    return print_enum_entry(v, time_enum1);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TIME_H
