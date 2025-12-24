//
// Created by Trent Tanchin on 3/4/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_CPU_SET_H
#define ABII_C_LOGGING_PLUGIN_CPU_SET_H

#include <abii/libabii.h>
#include <bits/cpu-set.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, cpu_set_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__bits, "__bits", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_CPU_SET_H
