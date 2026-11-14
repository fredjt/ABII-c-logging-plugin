//
// Created by Trent Tanchin on 11/13/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_GETOPT_EXT_H
#define ABII_C_LOGGING_PLUGIN_GETOPT_EXT_H

#include <getopt.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map bits_getopt_ext_has_arg = {
    {no_argument, "no_argument"},
    {required_argument, "required_argument"},
    {optional_argument, "optional_argument"}
};

template <typename T>
std::string print_bits_getopt_ext_has_arg(const T v)
{
    return print_enum_entry(v, bits_getopt_ext_has_arg);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, option>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.name, "name", &os));

    auto printer = new ArgPrinter(obj.has_arg, "has_arg", &os);
    printer->set_enum_printer(print_bits_getopt_ext_has_arg, obj.has_arg);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.flag, "flag", &os));
    abii_args->push_arg(new ArgPrinter(obj.val, "val", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_GETOPT_EXT_H
