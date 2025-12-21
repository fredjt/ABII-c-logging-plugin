//
// Created by Trent Tanchin on 7/3/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_STRUCT_TIMESPEC_H
#define ABII_C_LOGGING_PLUGIN_STRUCT_TIMESPEC_H

#include <abii/libabii.h>
#include <bits/types/struct_timespec.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, timespec>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.tv_sec, "tv_sec", &os));
    abii_args->push_arg(new ArgPrinter(obj.tv_nsec, "tv_nsec", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_STRUCT_TIMESPEC_H
