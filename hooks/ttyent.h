//
// Created by Trent Tanchin on 7/4/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TTYENT_H
#define ABII_C_LOGGING_PLUGIN_TTYENT_H

#include <ttyent.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<const char*> ttyent__path_ttys = {
    {"/etc/ttys", "_PATH_TTYS"}
};

const defines_map<const char*> ttyent__ttys = {
    {"off", "_TTYS_OFF"},
    {"on", "_TTYS_ON"},
    {"secure", "_TTYS_SECURE"},
    {"window", "_TTYS_WINDOW"}
};

const defines_map ttyent_status = {
    {0x01, "TTY_ON"},
    {0x02, "TTY_SECURE"}
};

template <typename T>
std::string print_ttyent__path_ttys(const T v)
{
    return print_enum_entry(v, ttyent__path_ttys);
}

template <typename T>
std::string print_ttyent__ttys(const T v)
{
    return print_enum_entry(v, ttyent__ttys);
}

template <typename T>
std::string print_ttyent_status(const T v)
{
    return print_or_enum_entries(v, ttyent_status);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ttyent>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ty_name, "ty_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.ty_getty, "ty_getty", &os));
    abii_args->push_arg(new ArgPrinter(obj.ty_type, "ty_type", &os));

    auto printer = new ArgPrinter(obj.ty_status, "ty_status", &os);
    printer->set_enum_printer(print_ttyent_status, obj.ty_status);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.ty_window, "ty_window", &os));
    abii_args->push_arg(new ArgPrinter(obj.ty_comment, "ty_comment", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_TTYENT_H
