//
// Created by Trent Tanchin on 8/9/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_AR_H
#define ABII_C_LOGGING_PLUGIN_AR_H

#include <ar.h>
#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ar_hdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ar_name, "ar_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.ar_date, "ar_date", &os));
    abii_args->push_arg(new ArgPrinter(obj.ar_uid, "ar_uid", &os));
    abii_args->push_arg(new ArgPrinter(obj.ar_gid, "ar_gid", &os));
    abii_args->push_arg(new ArgPrinter(obj.ar_mode, "ar_mode", &os));
    abii_args->push_arg(new ArgPrinter(obj.ar_size, "ar_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.ar_fmag, "ar_fmag", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_AR_H
