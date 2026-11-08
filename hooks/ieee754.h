//
// Created by Trent Tanchin on 11/8/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_IEEE754_H
#define ABII_C_LOGGING_PLUGIN_IEEE754_H

#include <abii/libabii.h>
#include <ieee754.h>

namespace abii
{
const defines_map ieee754_float_bias = {
    {0x7f, "IEEE754_FLOAT_BIAS"}
};

const defines_map ieee754_double_bias = {
    {0x3ff, "IEEE754_DOUBLE_BIAS"}
};

const defines_map ieee754_long_double_bias = {
    {0x3fff, "IEEE854_LONG_DOUBLE_BIAS"}
};

template <typename T>
std::string print_ieee754_float_bias(const T v)
{
    return print_enum_entry(v, ieee754_float_bias);
}

template <typename T>
std::string print_ieee754_double_bias(const T v)
{
    return print_enum_entry(v, ieee754_double_bias);
}

template <typename T>
std::string print_ieee754_long_double_bias(const T v)
{
    return print_enum_entry(v, ieee754_long_double_bias);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ieee754_float>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.f, "f", &os));
    abii_args->push_arg(new ArgPrinter(obj.ieee, "ieee", &os));
    abii_args->push_arg(new ArgPrinter(obj.ieee_nan, "ieee_nan", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(ieee754_float::ieee)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#if __BYTE_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee.negative)>(obj.negative), "negative",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee.exponent)>(obj.exponent), "exponent",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee.mantissa)>(obj.mantissa), "mantissa",
                                       &os, RECURSE));
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee.mantissa)>(obj.mantissa), "mantissa",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee.exponent)>(obj.exponent), "exponent",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee.negative)>(obj.negative), "negative",
                                       &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(ieee754_float::ieee_nan)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#if __BYTE_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee_nan.negative)>(obj.negative),
                                       "negative", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee_nan.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee_nan.quiet_nan)>(obj.quiet_nan),
                                       "quiet_nan", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee_nan.mantissa)>(obj.mantissa),
                                       "mantissa", &os, RECURSE));
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee_nan.mantissa)>(obj.mantissa),
                                       "mantissa", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee_nan.quiet_nan)>(obj.quiet_nan),
                                       "quiet_nan", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee_nan.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_float::ieee_nan.negative)>(obj.negative),
                                       "negative", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ieee754_double>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.d, "d", &os));
    abii_args->push_arg(new ArgPrinter(obj.ieee, "ieee", &os));
    abii_args->push_arg(new ArgPrinter(obj.ieee_nan, "ieee_nan", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(ieee754_double::ieee)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#if __BYTE_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.negative)>(obj.negative), "negative",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.exponent)>(obj.exponent), "exponent",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os, RECURSE));
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
# if __FLOAT_WORD_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.exponent)>(obj.exponent), "exponent",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.negative)>(obj.negative), "negative",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os, RECURSE));
# else
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.exponent)>(obj.exponent), "exponent",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee.negative)>(obj.negative), "negative",
                                       &os, RECURSE));
# endif
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(ieee754_double::ieee_nan)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#if __BYTE_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.negative)>(obj.negative),
                                       "negative", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.quiet_nan)>(obj.quiet_nan),
                                       "quiet_nan", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os, RECURSE));
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
# if __FLOAT_WORD_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.quiet_nan)>(obj.quiet_nan),
                                       "quiet_nan", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.negative)>(obj.negative),
                                       "negative", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os, RECURSE));
# else
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.quiet_nan)>(obj.quiet_nan),
                                       "quiet_nan", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee754_double::ieee_nan.negative)>(obj.negative),
                                       "negative", &os, RECURSE));
# endif
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ieee854_long_double>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.d, "d", &os));
    abii_args->push_arg(new ArgPrinter(obj.ieee, "ieee", &os));
    abii_args->push_arg(new ArgPrinter(obj.ieee_nan, "ieee_nan", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(ieee854_long_double::ieee)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#if __BYTE_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.negative)>(obj.negative),
                                       "negative", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.empty)>(obj.empty), "empty",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os, RECURSE));
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
# if __FLOAT_WORD_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.negative)>(obj.negative),
                                       "negative", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.empty)>(obj.empty), "empty",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os, RECURSE));
# else
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.negative)>(obj.negative),
                                       "negative", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee.empty)>(obj.empty), "empty",
                                       &os, RECURSE));
# endif
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(ieee854_long_double::ieee_nan)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#if __BYTE_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.negative)>(obj.negative),
                                       "negative", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.empty)>(obj.empty), "empty",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.one)>(obj.one), "one", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.quiet_nan)>(obj.quiet_nan),
                                       "quiet_nan", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os, RECURSE));
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
# if __FLOAT_WORD_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.negative)>(obj.negative),
                                       "negative", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.empty)>(obj.empty), "empty",
                                       &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.quiet_nan)>(obj.quiet_nan),
                                       "quiet_nan", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.one)>(obj.one), "one", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os, RECURSE));
# else
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.mantissa1)>(obj.mantissa1),
                                       "mantissa1", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.mantissa0)>(obj.mantissa0),
                                       "mantissa0", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.quiet_nan)>(obj.quiet_nan),
                                       "quiet_nan", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.one)>(obj.one), "one", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.exponent)>(obj.exponent),
                                       "exponent", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.negative)>(obj.negative),
                                       "negative", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(ieee854_long_double::ieee_nan.empty)>(obj.empty), "empty",
                                       &os, RECURSE));
# endif
#endif
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_IEEE754_H
