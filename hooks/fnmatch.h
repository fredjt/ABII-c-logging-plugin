//
// Created by Trent Tanchin on 9/17/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_FNMATCH_H
#define ABII_C_LOGGING_PLUGIN_FNMATCH_H

#include <abii/libabii.h>

namespace abii
{
const defines_map fnmatch_flag = {
    {(1 << 0), "FNM_PATHNAME"},
    {(1 << 1), "FNM_NOESCAPE"},
    {(1 << 2), "FNM_PERIOD"},
    {(1 << 0), "FNM_FILE_NAME"},
    {(1 << 3), "FNM_LEADING_DIR"},
    {(1 << 4), "FNM_CASEFOLD"},
    {(1 << 5), "FNM_EXTMATCH"}
};

const defines_map fnmatch_ret = {
    {1, "FNM_NOMATCH"},
    {(-1), "FNM_NOSYS"}
};

template <typename T>
std::string print_fnmatch_flag(const T v)
{
    return print_or_enum_entries(v, fnmatch_flag);
}

template <typename T>
std::string print_fnmatch_ret(const T v)
{
    return print_enum_entry(v, fnmatch_ret);
}
}

#endif //ABII_C_LOGGING_PLUGIN_FNMATCH_H
