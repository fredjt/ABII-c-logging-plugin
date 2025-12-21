//
// Created by Trent Tanchin on 6/15/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_COOKIE_IO_FUNCTIONS_T_H
#define ABII_C_LOGGING_PLUGIN_COOKIE_IO_FUNCTIONS_T_H

#include <abii/libabii.h>
#include <bits/types/cookie_io_functions_t.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, cookie_io_functions_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.read, "read", &os));
    abii_args->push_arg(new ArgPrinter(obj.write, "write", &os));
    abii_args->push_arg(new ArgPrinter(obj.seek, "seek", &os));
    abii_args->push_arg(new ArgPrinter(obj.close, "close", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_COOKIE_IO_FUNCTIONS_T_H
