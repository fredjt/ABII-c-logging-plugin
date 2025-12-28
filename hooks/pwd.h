//
// Created by Trent Tanchin on 3/10/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_PWD_H
#define ABII_C_LOGGING_PLUGIN_PWD_H

#include <pwd.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map pwd_nss_buflen_passwd = {
    {1024, "NSS_BUFLEN_PASSWD"}
};

template <typename T>
std::string print_pwd_nss_buflen_passwd(const T v)
{
    return print_enum_entry(v, pwd_nss_buflen_passwd);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, passwd>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.pw_name, "pw_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.pw_passwd, "pw_passwd", &os));
    abii_args->push_arg(new ArgPrinter(obj.pw_uid, "pw_uid", &os));
    abii_args->push_arg(new ArgPrinter(obj.pw_gid, "pw_gid", &os));
    abii_args->push_arg(new ArgPrinter(obj.pw_gecos, "pw_gecos", &os));
    abii_args->push_arg(new ArgPrinter(obj.pw_dir, "pw_dir", &os));
    abii_args->push_arg(new ArgPrinter(obj.pw_shell, "pw_shell", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_PWD_H
