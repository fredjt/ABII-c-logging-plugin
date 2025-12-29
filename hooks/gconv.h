//
// Created by Trent Tanchin on 9/23/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_GCONV_H
#define ABII_C_LOGGING_PLUGIN_GCONV_H

#include <abii/libabii.h>
#include <gconv.h>

#include "stdint.h"

namespace abii
{
const defines_map<wchar_t> gconv___unknown_10646_char = {
    {static_cast<wchar_t>(0xfffd), "__UNKNOWN_10646_CHAR"}
};

const defines_map gconv_error = {
    {0, "__GCONV_OK"},
    {1, "__GCONV_NOCONV"},
    {2, "__GCONV_NODB"},
    {3, "__GCONV_NOMEM"},
    {4, "__GCONV_EMPTY_INPUT"},
    {5, "__GCONV_FULL_OUTPUT"},
    {6, "__GCONV_ILLEGAL_INPUT"},
    {7, "__GCONV_INCOMPLETE_INPUT"},
    {8, "__GCONV_ILLEGAL_DESCRIPTOR"},
    {9, "__GCONV_INTERNAL_ERROR"}
};

const defines_map gconv_flag = {
    {0x0001, "__GCONV_IS_LAST"},
    {0x0002, "__GCONV_IGNORE_ERRORS"},
    {0x0004, "__GCONV_SWAP"},
    {0x0008, "__GCONV_TRANSLIT"}
};

template <typename T>
std::string print_gconv___unknown_10646_char_(const T v)
{
    return print_enum_entry(v, gconv___unknown_10646_char);
}

template <typename T>
std::string print_gconv_error(const T v)
{
    return print_enum_entry(v, gconv_error);
}

template <typename T>
std::string print_gconv_flag(const T v)
{
    return print_or_enum_entries(v, gconv_flag);
}

template <typename T>
std::string print_gconv___unknown_10646_char(const T v)
{
    return print_enum_entry(v, gconv___unknown_10646_char, stdint_wchar);
}
}

using namespace abii;

struct __gconv_loaded_object {};

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __gconv_step>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__shlib_handle, "__shlib_handle", &os));
    abii_args->push_arg(new ArgPrinter(obj.__modname, "__modname", &os));
    abii_args->push_arg(new ArgPrinter(obj.__counter, "__counter", &os));
    abii_args->push_arg(new ArgPrinter(obj.__from_name, "__from_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.__to_name, "__to_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.__fct, "__fct", &os));
    abii_args->push_arg(new ArgPrinter(obj.__btowc_fct, "__btowc_fct", &os));
    abii_args->push_arg(new ArgPrinter(obj.__init_fct, "__init_fct", &os));
    abii_args->push_arg(new ArgPrinter(obj.__end_fct, "__end_fct", &os));
    abii_args->push_arg(new ArgPrinter(obj.__min_needed_from, "__min_needed_from", &os));
    abii_args->push_arg(new ArgPrinter(obj.__max_needed_from, "__max_needed_from", &os));
    abii_args->push_arg(new ArgPrinter(obj.__min_needed_to, "__min_needed_to", &os));
    abii_args->push_arg(new ArgPrinter(obj.__max_needed_to, "__max_needed_to", &os));
    abii_args->push_arg(new ArgPrinter(obj.__stateful, "__stateful", &os));
    abii_args->push_arg(new ArgPrinter(obj.__data, "__data", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __gconv_step_data>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__outbuf, "__outbuf", &os));
    abii_args->push_arg(new ArgPrinter(obj.__outbufend, "__outbufend", &os));
    abii_args->push_arg(new ArgPrinter(obj.__flags, "__flags", &os));
    abii_args->push_arg(new ArgPrinter(obj.__invocation_counter, "__invocation_counter", &os));
    abii_args->push_arg(new ArgPrinter(obj.__internal_use, "__internal_use", &os));
    abii_args->push_arg(new ArgPrinter(obj.__statep, "__statep", &os));
    abii_args->push_arg(new ArgPrinter(obj.__state, "__state", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __gconv_info>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__nsteps, "__nsteps", &os));
    abii_args->push_arg(new ArgPrinter(obj.__steps, "__steps", &os));
    abii_args->push_arg(new ArgPrinter(obj.__data, "__data", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_GCONV_H
