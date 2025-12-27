//
// Created by Trent Tanchin on 9/28/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_IFADDRS_H
#define ABII_C_LOGGING_PLUGIN_IFADDRS_H

#include <ifaddrs.h>
#include <abii/libabii.h>

#include "bits/socket.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ifaddrs>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ifa_next, "ifa_next", &os, PRINT_ENDL));
    abii_args->push_arg(new ArgPrinter(obj.ifa_name, "ifa_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.ifa_flags, "ifa_flags", &os));
    abii_args->push_arg(new ArgPrinter(obj.ifa_addr, "ifa_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.ifa_netmask, "ifa_netmask", &os));
    abii_args->push_arg(new ArgPrinter(obj.ifa_ifu, "ifa_ifu", &os));
    abii_args->push_arg(new ArgPrinter(obj.ifa_data, "ifa_data", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(ifaddrs::ifa_ifu)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ifu_broadaddr, "ifu_broadaddr", &os));
    abii_args->push_arg(new ArgPrinter(obj.ifu_dstaddr, "ifu_dstaddr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_IFADDRS_H
