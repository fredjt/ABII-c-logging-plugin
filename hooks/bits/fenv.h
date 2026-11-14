//
// Created by Trent Tanchin on 11/13/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_FENV_H
#define ABII_C_LOGGING_PLUGIN_FENV_H

#include <cfenv>
#include <abii/libabii.h>

namespace abii
{
const defines_map bits_fenv_exception = {
    {FE_INVALID, "FE_INVALID"},
    {__FE_DENORM, "__FE_DENORM"},
    {FE_DIVBYZERO, "FE_DIVBYZERO"},
    {FE_OVERFLOW, "FE_OVERFLOW"},
    {FE_UNDERFLOW, "FE_UNDERFLOW"},
    {FE_INEXACT, "FE_INEXACT"},
    {FE_ALL_EXCEPT, "FE_ALL_EXCEPT"}
};

const defines_map bits_fenv_rounding_mode = {
    {FE_TONEAREST, "FE_TONEAREST"},
    {FE_DOWNWARD, "FE_DOWNWARD"},
    {FE_UPWARD, "FE_UPWARD"},
    {FE_TOWARDZERO, "FE_TOWARDZERO"}
};

const defines_map<const fenv_t*> bits_fenv_dfl_env = {
    {FE_DFL_ENV, "FE_DFL_ENV"},
    {FE_NOMASK_ENV, "FE_NOMASK_ENV"}
};

const defines_map<const femode_t*> bits_fenv_dfl_mode = {
    {FE_DFL_MODE, "FE_DFL_MODE"}
};

template <typename T>
std::string print_bits_fenv_exception(const T v)
{
    return print_or_enum_entries(v, bits_fenv_exception);
}

template <typename T>
std::string print_bits_fenv_rounding_mode(const T v)
{
    return print_or_enum_entries(v, bits_fenv_rounding_mode);
}

template <typename T>
std::string print_bits_fenv_dfl_env(const T v)
{
    return print_enum_entry(v, bits_fenv_dfl_env);
}

template <typename T>
std::string print_bits_fenv_dfl_mode(const T v)
{
    return print_enum_entry(v, bits_fenv_dfl_mode);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, fenv_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__control_word, "__control_word", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved1, "__glibc_reserved1", &os));
    abii_args->push_arg(new ArgPrinter(obj.__status_word, "__status_word", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved2, "__glibc_reserved2", &os));
    abii_args->push_arg(new ArgPrinter(obj.__tags, "__tags", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved3, "__glibc_reserved3", &os));
    abii_args->push_arg(new ArgPrinter(obj.__eip, "__eip", &os));
    abii_args->push_arg(new ArgPrinter(obj.__cs_selector, "__cs_selector", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(fenv_t::__opcode)>(obj.__opcode), "__opcode", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(fenv_t::__glibc_reserved4)>(obj.__glibc_reserved4),
                                       "__glibc_reserved4", &os));
    abii_args->push_arg(new ArgPrinter(obj.__data_offset, "__data_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.__data_selector, "__data_selector", &os));
#ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved5, "__glibc_reserved5", &os));
    abii_args->push_arg(new ArgPrinter(obj.__mxcsr, "__mxcsr", &os, RECURSE));
#else
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved5, "__glibc_reserved5", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, femode_t>
std::ostream& operator<<(std::ostream& os, femode_t&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__control_word, "__control_word", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved, "__glibc_reserved", &os));
    abii_args->push_arg(new ArgPrinter(obj.__mxcsr, "__mxcsr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_FENV_H
