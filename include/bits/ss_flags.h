//
// Created by Trent Tanchin on 5/26/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SS_FLAGS_H
#define ABII_C_LOGGING_PLUGIN_SS_FLAGS_H

#include <bits/ss_flags.h>

namespace abii
{
const defines_map ss_flags_flag = {
    {1, "SS_ONSTACK"},
    {2, "SS_DISABLE"}
};

template <typename T>
std::string print_ss_flags_flag(const T v)
{
    return print_or_enum_entries(v, ss_flags_flag);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SS_FLAGS_H
