//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_ERRNO_H
#define ABII_C_LOGGING_PLUGIN_BITS_ERRNO_H

#include <abii/libabii.h>

namespace abii
{
const defines_map bits_errno_error = {
    {ENOTSUP, "ENOTSUP"},
    {ECANCELED, "ECANCELED"},
    {EOWNERDEAD, "EOWNERDEAD"},
    {ENOTRECOVERABLE, "ENOTRECOVERABLE"},
    {ERFKILL, "ERFKILL"},
    {EHWPOISON, "EHWPOISON"}
};

template <typename T>
std::string print_bits_errno_error(const T v)
{
    return print_enum_entry(v, bits_errno_error);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_ERRNO_H
