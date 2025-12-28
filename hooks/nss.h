//
// Created by Trent Tanchin on 12/27/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_NSS_H
#define ABII_C_LOGGING_PLUGIN_NSS_H

#include <nss.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map nss_status = {
    {-2, "NSS_STATUS_TRYAGAIN"},
    {-1, "NSS_STATUS_UNAVAIL"},
    {0, "NSS_STATUS_NOTFOUND"},
    {1, "NSS_STATUS_SUCCESS"},
    {2, "NSS_STATUS_RETURN"}
};

template <typename T>
std::string print_nss_status(const T v)
{
    return print_enum_entry(v, nss_status);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, gaih_addrtuple>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.next, "next", &os));
    abii_args->push_arg(new ArgPrinter(obj.name, "name", &os));
    abii_args->push_arg(new ArgPrinter(obj.family, "family", &os));
    abii_args->push_arg(new ArgPrinter(obj.addr, "addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.scopeid, "scopeid", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_NSS_H
