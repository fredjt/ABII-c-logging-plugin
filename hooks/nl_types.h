//
// Created by Trent Tanchin on 12/26/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_NL_TYPES_H
#define ABII_C_LOGGING_PLUGIN_NL_TYPES_H

#include <abii/libabii.h>

namespace abii
{
const defines_map nl_setd = {
    {1, "NL_SETD"}
};

const defines_map nl_cat_locale = {
    {1, "NL_CAT_LOCALE"}
};

template <typename T>
std::string print_nl_setd(const T v)
{
    return print_enum_entry(v, nl_setd);
}

template <typename T>
std::string print_nl_cat_locale(const T v)
{
    return print_enum_entry(v, nl_cat_locale);
}
}

#endif //ABII_C_LOGGING_PLUGIN_NL_TYPES_H
