//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_LINUX_OPENAT2_H
#define ABII_C_LOGGING_PLUGIN_LINUX_OPENAT2_H

#include <abii/libabii.h>

#include "hooks/bits/fcntl-linux.h"

namespace abii
{
const defines_map linux_openat2_resolve = {
    {RESOLVE_NO_XDEV, "RESOLVE_NO_XDEV"},
    {RESOLVE_NO_MAGICLINKS, "RESOLVE_NO_MAGICLINKS"},
    {RESOLVE_NO_SYMLINKS, "RESOLVE_NO_SYMLINKS"},
    {RESOLVE_BENEATH, "RESOLVE_BENEATH"},
    {RESOLVE_IN_ROOT, "RESOLVE_IN_ROOT"},
    {RESOLVE_CACHED, "RESOLVE_CACHED"}
};

template <typename T>
std::string print_linux_openat2_resolve(const T v)
{
    return print_or_enum_entries(v, linux_openat2_resolve);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, open_how>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.flags, "flags", &os);
    printer->set_enum_printer(print_bits_fcntl_linux_oflag, obj.flags);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.mode, "mode", &os);
    printer1->set_enum_printer(print_bits_fcntl_linux_oflag, obj.mode);
    abii_args->push_arg(printer1);

    auto printer2 = new ArgPrinter(obj.resolve, "resolve", &os, RECURSE);
    printer2->set_enum_printer(print_linux_openat2_resolve, obj.resolve);
    abii_args->push_arg(printer2);
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_LINUX_OPENAT2_H
