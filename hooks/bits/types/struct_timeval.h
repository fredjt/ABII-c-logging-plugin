//
// Created by Trent Tanchin on 7/4/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_STRUCT_TIMEVAL_H
#define ABII_C_LOGGING_PLUGIN_STRUCT_TIMEVAL_H

#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, timeval>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.tv_sec, "tv_sec", &os));
    abii_args->push_arg(new ArgPrinter(obj.tv_usec, "tv_usec", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_STRUCT_TIMEVAL_H
