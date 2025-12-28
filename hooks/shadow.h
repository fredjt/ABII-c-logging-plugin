//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SHADOW_H
#define ABII_C_LOGGING_PLUGIN_SHADOW_H

#include <shadow.h>
#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, spwd>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.sp_namp, "sp_namp", &os));
    abii_args->push_arg(new ArgPrinter(obj.sp_pwdp, "sp_pwdp", &os));
    abii_args->push_arg(new ArgPrinter(obj.sp_lstchg, "sp_lstchg", &os));
    abii_args->push_arg(new ArgPrinter(obj.sp_min, "sp_min", &os));
    abii_args->push_arg(new ArgPrinter(obj.sp_max, "sp_max", &os));
    abii_args->push_arg(new ArgPrinter(obj.sp_warn, "sp_warn", &os));
    abii_args->push_arg(new ArgPrinter(obj.sp_inact, "sp_inact", &os));
    abii_args->push_arg(new ArgPrinter(obj.sp_expire, "sp_expire", &os));
    abii_args->push_arg(new ArgPrinter(obj.sp_flag, "sp_flag", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_SHADOW_H
