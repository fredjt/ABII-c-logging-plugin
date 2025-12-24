//
// Created by Trent Tanchin on 7/25/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_DIRENT_H
#define ABII_C_LOGGING_PLUGIN_BITS_DIRENT_H

#include <abii/libabii.h>

#include "hooks/dirent.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, dirent>
    || std::is_same_v<std::remove_cvref_t<T>, dirent64>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.d_ino, "d_ino", &os));
    abii_args->push_arg(new ArgPrinter(obj.d_off, "d_off", &os));
    abii_args->push_arg(new ArgPrinter(obj.d_reclen, "d_reclen", &os));

    auto printer = ArgPrinter(obj.d_type, "d_type", &os);
    printer.set_enum_printer(print_dirent_type, obj.d_type);
    abii_args->push_arg(&printer);

    abii_args->push_arg(new ArgPrinter(obj.d_name, "d_name", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_DIRENT_H
