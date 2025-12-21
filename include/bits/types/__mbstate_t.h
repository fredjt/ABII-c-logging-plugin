//
// Created by Trent Tanchin on 11/4/25.
//

#ifndef ABII_C_LOGGING_PLUGIN___MBSTATE_T_H
#define ABII_C_LOGGING_PLUGIN___MBSTATE_T_H

#include <abii/libabii.h>
#include <bits/types/__mbstate_t.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __mbstate_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__count, "__count", &os));
    abii_args->push_arg(new ArgPrinter(obj.__value, "__value", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(__mbstate_t::__value)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__wch, "__wch", &os));
    abii_args->push_arg(new ArgPrinter(obj.__wchb, "__wchb", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN___MBSTATE_T_H
