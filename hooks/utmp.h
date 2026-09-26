//
// Created by Trent Tanchin on 9/26/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_UTMP_H
#define ABII_C_LOGGING_PLUGIN_UTMP_H

#include <utmp.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<const char*> utmp_file = {
    {"/var/run/utmp", "UTMP_FILE"},
    {"/var/run/utmp", "UTMP_FILENAME"},
    {"/var/log/wtmp", "WTMP_FILE"},
    {"/var/log/wtmp", "WTMP_FILENAME"}
};

template <typename T>
std::string print_utmp_file(const T v)
{
    return print_enum_entry(v, utmp_file);
}
}

#endif //ABII_C_LOGGING_PLUGIN_UTMP_H
