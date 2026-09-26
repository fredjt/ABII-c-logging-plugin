//
// Created by Trent Tanchin on 9/26/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_UTMPX_H
#define ABII_C_LOGGING_PLUGIN_UTMPX_H

#include <utmpx.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<const char*> utmpx_file = {
    {"/var/run/utmp", "UTMPX_FILE"},
    {"/var/run/utmp", "UTMPX_FILENAME"},
    {"/var/log/wtmp", "WTMPX_FILE"},
    {"/var/log/wtmp", "WTMPX_FILENAME"}
};

template <typename T>
std::string print_utmpx_file(const T v)
{
    return print_enum_entry(v, utmpx_file);
}
}

#endif //ABII_C_LOGGING_PLUGIN_UTMPX_H
