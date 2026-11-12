//
// Created by Trent Tanchin on 3/4/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_CPU_SET_H
#define ABII_C_LOGGING_PLUGIN_BITS_CPU_SET_H

#include <abii/libabii.h>
#include <bits/cpu-set.h>

namespace abii
{
const defines_map bits_cpu_set___cpu_setsize = {
    {1024, "__CPU_SETSIZE"}
};

const defines_map bits_cpu_set___ncpubits = {
    {8 * sizeof(__cpu_mask), "__NCPUBITS"}
};

template <typename T>
std::string print_bits_cpu_set___cpu_setsize(const T v)
{
    return print_enum_entry(v, bits_cpu_set___cpu_setsize);
}

template <typename T>
std::string print_bits_cpu_set___ncpubits(const T v)
{
    return print_enum_entry(v, bits_cpu_set___ncpubits);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, cpu_set_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__bits, "__bits", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_CPU_SET_H
