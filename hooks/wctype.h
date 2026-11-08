//
// Created by Trent Tanchin on 11/7/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_WCTYPE_H
#define ABII_C_LOGGING_PLUGIN_WCTYPE_H

#include <abii/libabii.h>

namespace abii
{
const defines_map<wint_t> wctype_weof = {
    {0xffffffffu, "WEOF"}
};

template <typename T>
std::string print_wctype_weof(const T v)
{
    return print_enum_entry(v, wctype_weof);
}
}

#endif //ABII_C_LOGGING_PLUGIN_WCTYPE_H
