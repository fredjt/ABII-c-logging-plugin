//
// Created by Trent Tanchin on 2/6/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SCHED_H
#define ABII_C_LOGGING_PLUGIN_SCHED_H

#include <abii/libabii.h>
#include <bits/sched.h>

namespace abii
{
const defines_map sched_enum1 = {
    {SCHED_OTHER, "SCHED_OTHER"},
    {SCHED_FIFO, "SCHED_FIFO"},
    {SCHED_RR, "SCHED_RR"}
#ifdef __USE_GNU
    ,
    {SCHED_BATCH, "SCHED_BATCH"},
    {SCHED_ISO, "SCHED_ISO"},
    {SCHED_IDLE, "SCHED_IDLE"},
    {SCHED_DEADLINE, "SCHED_DEADLINE"}
#endif
};

template <typename T>
std::string print_sched_enum1(const T v)
{
    return print_enum_entry(v, sched_enum1);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SCHED_H
