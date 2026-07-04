//
// Created by Trent Tanchin on 7/4/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_STRUCT_TM_H
#define ABII_C_LOGGING_PLUGIN_STRUCT_TM_H

#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, tm>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.tm_sec, "tm_sec", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_min, "tm_min", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_hour, "tm_hour", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_mday, "tm_mday", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_mon, "tm_mon", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_year, "tm_year", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_wday, "tm_wday", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_yday, "tm_yday", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_isdst, "tm_isdst", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_gmtoff, "tm_gmtoff", &os));
    abii_args->push_arg(new ArgPrinter(obj.tm_zone, "tm_zone", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_STRUCT_TM_H
