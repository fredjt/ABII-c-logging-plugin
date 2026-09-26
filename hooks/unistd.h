//
// Created by Trent Tanchin on 7/5/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_UNISTD_H
#define ABII_C_LOGGING_PLUGIN_UNISTD_H

#include <abii/libabii.h>

namespace abii
{
const defines_map unistd_fileno = {
    {0, "STDIN_FILENO"},
    {1, "STDOUT_FILENO"},
    {2, "STDERR_FILENO"}
};

const defines_map unistd_access_type = {
    {4, "R_OK"},
    {2, "W_OK"},
    {1, "X_OK"},
    {0, "F_OK"}
};

const defines_map unistd_seek_whence = {
    {0, "SEEK_SET"},
    {1, "SEEK_CUR"},
    {2, "SEEK_END"},
    {3, "SEEK_DATA"},
    {4, "SEEK_HOLE"},
    {0, "L_SET"},
    {1, "L_INCR"},
    {2, "L_XTND"}
};

template <typename T>
std::string print_unistd_fileno(const T v)
{
    return print_enum_entry(v, unistd_fileno);
}

template <typename T>
std::string print_unistd_access_type(const T v)
{
    return print_or_enum_entries(v, unistd_access_type);
}

template <typename T>
std::string print_unistd_seek_whence(const T v)
{
    return print_enum_entry(v, unistd_seek_whence);
}
}

#endif //ABII_C_LOGGING_PLUGIN_UNISTD_H
