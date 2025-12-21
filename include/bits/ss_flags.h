//
// Created by Trent Tanchin on 5/26/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SS_FLAGS_H
#define ABII_C_LOGGING_PLUGIN_SS_FLAGS_H

#include <bits/ss_flags.h>

namespace abii
{
const defines_map ss_flags_enum1 = {
    {SS_ONSTACK, "SS_ONSTACK"},
    {SS_DISABLE, "SS_DISABLE"}
};

template<typename T>
std::string print_ss_flags_enum1(const T v)
{
    return print_or_enum_entries(v, ss_flags_enum1);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SS_FLAGS_H
