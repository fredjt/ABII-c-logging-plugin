//
// Created by Trent Tanchin on 11/13/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_INOTIFY_H
#define ABII_C_LOGGING_PLUGIN_INOTIFY_H

#include <abii/libabii.h>
#include <sys/inotify.h>

namespace abii
{
const defines_map bits_inotify_init1_flags = {
    {IN_CLOEXEC, "IN_CLOEXEC"},
    {IN_NONBLOCK, "IN_NONBLOCK"}
};

template <typename T>
std::string print_bits_inotify_init1_flags(const T v)
{
    return print_enum_entry(v, bits_inotify_init1_flags);
}
}

#endif //ABII_C_LOGGING_PLUGIN_INOTIFY_H
