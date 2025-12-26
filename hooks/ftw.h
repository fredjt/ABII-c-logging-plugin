//
// Created by Trent Tanchin on 9/23/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_FTW_H
#define ABII_C_LOGGING_PLUGIN_FTW_H

#include <abii/libabii.h>
#include <ftw.h>

namespace abii
{
const defines_map ftw_descriptor = {
    {0, "FTW_F"},
    {1, "FTW_D"},
    {2, "FTW_DNR"},
    {3, "FTW_NS"},
    {4, "FTW_SL"},
    {5, "FTW_DP"},
    {6, "FTW_SLN"}
};

const defines_map ftw_flag = {
    {1, "FTW_PHYS"},
    {2, "FTW_MOUNT"},
    {4, "FTW_CHDIR"},
    {8, "FTW_DEPTH"},
    {16, "FTW_ACTIONRETVAL"}
};

const defines_map ftw_cb_ret = {
    {0, "FTW_CONTINUE"},
    {1, "FTW_STOP"},
    {2, "FTW_SKIP_SUBTREE"},
    {3, "FTW_SKIP_SIBLINGS"}
};

template <typename T>
std::string print_ftw_descriptor(const T v)
{
    return print_enum_entry(v, ftw_descriptor);
}

template <typename T>
std::string print_ftw_flag(const T v)
{
    return print_or_enum_entries(v, ftw_flag);
}

template <typename T>
std::string print_ftw_cb_ret(const T v)
{
    return print_enum_entry(v, ftw_cb_ret);
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, FTW>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.base, "base", &os));
    abii_args->push_arg(new ArgPrinter(obj.level, "level", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
}

#endif //ABII_C_LOGGING_PLUGIN_FTW_H
