//
// Created by Trent Tanchin on 3/10/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_IOCTL_TYPES_H
#define ABII_C_LOGGING_PLUGIN_IOCTL_TYPES_H

#include <abii/libabii.h>
#include <bits/ioctl-types.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, winsize>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ws_row, "ws_row", &os));
    abii_args->push_arg(new ArgPrinter(obj.ws_col, "ws_col", &os));
    abii_args->push_arg(new ArgPrinter(obj.ws_xpixel, "ws_xpixel", &os));
    abii_args->push_arg(new ArgPrinter(obj.ws_ypixel, "ws_ypixel", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_IOCTL_TYPES_H
