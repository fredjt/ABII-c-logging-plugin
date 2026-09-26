//
// Created by Trent Tanchin on 9/26/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_CLOSE_RANGE_H
#define ABII_C_LOGGING_PLUGIN_CLOSE_RANGE_H

#include <abii/libabii.h>

namespace abii
{
const defines_map<unsigned> close_range_close_range = {
    {(1U << 1), "CLOSE_RANGE_UNSHARE"},
    {(1U << 2), "CLOSE_RANGE_CLOEXEC"}
};

template <typename T>
std::string print_close_range_close_range(const T v)
{
    return print_or_enum_entries(v, close_range_close_range);
}
}

#endif //ABII_C_LOGGING_PLUGIN_CLOSE_RANGE_H
