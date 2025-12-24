//
// Created by Trent Tanchin on 3/9/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_ATOMIC_WIDE_COUNTER_H
#define ABII_C_LOGGING_PLUGIN_ATOMIC_WIDE_COUNTER_H

#include <bits/atomic_wide_counter.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __atomic_wide_counter>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__value64, "__value64", &os));
    abii_args->push_arg(new ArgPrinter(obj.__value32, "__value32", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(__atomic_wide_counter::__value32)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__low, "__low", &os));
    abii_args->push_arg(new ArgPrinter(obj.__high, "__high", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_ATOMIC_WIDE_COUNTER_H
