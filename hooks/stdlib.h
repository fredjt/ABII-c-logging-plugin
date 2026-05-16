//
// Created by Trent Tanchin on 11/18/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_STDLIB_H
#define ABII_C_LOGGING_PLUGIN_STDLIB_H

#include <abii/libabii.h>

#include "stdint.h"

namespace abii
{
const defines_map stdlib_rand_max = {
    {2147483647, "RAND_MAX"}
};

const defines_map stdlib_exit_status = {
    {1, "EXIT_FAILURE"},
    {0, "EXIT_SUCCESS"}
};

// TODO: Why does this not match the output of __ctype_get_mb_cur_max()?
const defines_map<size_t> stdlib_mb_cur_max = {
    {(__ctype_get_mb_cur_max()), "MB_CUR_MAX"}
};

template <typename T>
std::string print_stdlib_enum1(const T v)
{
    return print_enum_entry(v, stdlib_rand_max);
}

template <typename T>
std::string print_stdlib_enum2(const T v)
{
    return print_enum_entry(v, stdlib_exit_status);
}

template <typename T>
std::string print_stdlib_mb_cur_max_(const T v)
{
    return print_enum_entry(v, stdlib_mb_cur_max);
}

template <typename T>
std::string print_stdlib_enum3(const T v)
{
    return print_enum_entry(v, stdlib_mb_cur_max, stdint_size);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, div_t>
    || std::is_same_v<std::remove_cvref_t<T>, ldiv_t> || std::is_same_v<std::remove_cvref_t<T>, lldiv_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.quot, "quot", &os));
    abii_args->push_arg(new ArgPrinter(obj.rem, "rem", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, random_data>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.fptr, "fptr", &os));
    abii_args->push_arg(new ArgPrinter(obj.rptr, "rptr", &os));
    abii_args->push_arg(new ArgPrinter(obj.state, "state", &os));
    abii_args->push_arg(new ArgPrinter(obj.rand_type, "rand_type", &os));
    abii_args->push_arg(new ArgPrinter(obj.rand_deg, "rand_deg", &os));
    abii_args->push_arg(new ArgPrinter(obj.rand_sep, "rand_sep", &os));
    abii_args->push_arg(new ArgPrinter(obj.end_ptr, "end_ptr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, drand48_data>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__x, "__x", &os));
    abii_args->push_arg(new ArgPrinter(obj.__old_x, "__old_x", &os));
    abii_args->push_arg(new ArgPrinter(obj.__c, "__c", &os));
    abii_args->push_arg(new ArgPrinter(obj.__init, "__init", &os));
    abii_args->push_arg(new ArgPrinter(obj.__a, "__a", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_STDLIB_H
