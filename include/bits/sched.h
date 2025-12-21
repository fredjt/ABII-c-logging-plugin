//
// Created by Trent Tanchin on 2/6/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SCHED_H
#define ABII_C_LOGGING_PLUGIN_SCHED_H

#include <abii/libabii.h>
#include <bits/sched.h>

namespace abii
{
const defines_map sched_algorithm = {
    {0, "SCHED_OTHER"},
    {1, "SCHED_FIFO"},
    {2, "SCHED_RR"},
    {3, "SCHED_BATCH"},
    {4, "SCHED_ISO"},
    {5, "SCHED_IDLE"},
    {6, "SCHED_DEADLINE"}
};

template <typename T>
std::string print_sched_algorithm(const T v)
{
    return print_enum_entry(v, sched_algorithm);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SCHED_H
