//
// Created by Trent Tanchin on 7/23/24.
//

#ifndef ABII_C_LOGGING_PLUGIN___LOCALE_T_H
#define ABII_C_LOGGING_PLUGIN___LOCALE_T_H

#include <abii/libabii.h>
#include <bits/types/__locale_t.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __locale_struct>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__locales, "__locales", &os));
    abii_args->push_arg(new ArgPrinter(obj.__ctype_b, "__ctype_b", &os));
    abii_args->push_arg(new ArgPrinter(obj.__ctype_tolower, "__ctype_tolower", &os));
    abii_args->push_arg(new ArgPrinter(obj.__ctype_toupper, "__ctype_toupper", &os));
    abii_args->push_arg(new ArgPrinter(obj.__names, "__names", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN___LOCALE_T_H
