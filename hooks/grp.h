//
// Created by Trent Tanchin on 9/23/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_GRP_H
#define ABII_C_LOGGING_PLUGIN_GRP_H

#include <grp.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map grp_nss_buflen_group = {
    {NSS_BUFLEN_GROUP, "NSS_BUFLEN_GROUP"}
};

template <typename T>
std::string print_grp_nss_buflen_group(const T v)
{
    return print_enum_entry(v, grp_nss_buflen_group);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, group>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.gr_name, "gr_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.gr_passwd, "gr_passwd", &os));
    abii_args->push_arg(new ArgPrinter(obj.gr_gid, "gr_gid", &os));
    abii_args->push_arg(new ArgPrinter(obj.gr_mem, "gr_mem", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_GRP_H
