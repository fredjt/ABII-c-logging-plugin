//
// Created by Trent Tanchin on 12/27/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_PRINTF_H
#define ABII_C_LOGGING_PLUGIN_PRINTF_H

#include <printf.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map printf_format = {
    {0, "PA_INT"},
    {1, "PA_CHAR"},
    {2, "PA_WCHAR"},
    {3, "PA_STRING"},
    {4, "PA_WSTRING"},
    {5, "PA_POINTER"},
    {6, "PA_FLOAT"},
    {7, "PA_DOUBLE"},
    {8, "PA_LAST"}
};

const defines_map printf_flag = {
    {0xff00, "PA_FLAG_MASK"},
    {(1 << 8), "PA_FLAG_LONG_LONG"},
    {(1 << 8), "PA_FLAG_LONG_DOUBLE"},
    {(1 << 9), "PA_FLAG_LONG"},
    {(1 << 10), "PA_FLAG_SHORT"},
    {(1 << 11), "PA_FLAG_PTR"}
};

template <typename T>
std::string print_printf_format(const T v)
{
    return print_enum_entry(v, printf_format);
}

template <typename T>
std::string print_printf_flag(const T v)
{
    return print_or_enum_entries(v, printf_flag);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, printf_info>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.prec, "prec", &os));
    abii_args->push_arg(new ArgPrinter(obj.width, "width", &os));
    abii_args->push_arg(new ArgPrinter(obj.spec, "spec", &os));
    abii_args->push_arg(new ArgPrinter(obj.is_long_double, "is_long_double", &os));
    abii_args->push_arg(new ArgPrinter(obj.is_short, "is_short", &os));
    abii_args->push_arg(new ArgPrinter(obj.is_long, "is_long", &os));
    abii_args->push_arg(new ArgPrinter(obj.alt, "alt", &os));
    abii_args->push_arg(new ArgPrinter(obj.space, "space", &os));
    abii_args->push_arg(new ArgPrinter(obj.left, "left", &os));
    abii_args->push_arg(new ArgPrinter(obj.showsign, "showsign", &os));
    abii_args->push_arg(new ArgPrinter(obj.group, "group", &os));
    abii_args->push_arg(new ArgPrinter(obj.extra, "extra", &os));
    abii_args->push_arg(new ArgPrinter(obj.is_char, "is_char", &os));
    abii_args->push_arg(new ArgPrinter(obj.wide, "wide", &os));
    abii_args->push_arg(new ArgPrinter(obj.i18n, "i18n", &os));
    abii_args->push_arg(new ArgPrinter(obj.is_binary128, "is_binary128", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad, "__pad", &os));
    abii_args->push_arg(new ArgPrinter(obj.user, "user", &os));
    abii_args->push_arg(new ArgPrinter(obj.pad, "pad", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_PRINTF_H
