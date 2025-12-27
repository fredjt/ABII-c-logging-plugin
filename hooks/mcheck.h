//
// Created by Trent Tanchin on 10/4/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_MCHECK_H
#define ABII_C_LOGGING_PLUGIN_MCHECK_H

#include <mcheck.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map mcheck_status = {
    {-1, "MCHECK_DISABLED"},
    {0, "MCHECK_OK"},
    {1, "MCHECK_FREE"},
    {2, "MCHECK_HEAD"},
    {3, "MCHECK_TAIL"}
};

template <typename T>
std::string print_mcheck_status(const T v)
{
    return print_enum_entry(v, mcheck_status);
}
}

#endif //ABII_C_LOGGING_PLUGIN_MCHECK_H
