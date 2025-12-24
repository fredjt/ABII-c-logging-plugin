//
// Created by Trent Tanchin on 11/18/25.
//

#ifndef ABII_C_LOGGING_PLUGIN___FPOS64_T_H
#define ABII_C_LOGGING_PLUGIN___FPOS64_T_H

#include <abii/libabii.h>
#include <bits/types/__fpos64_t.h>

#include "__mbstate_t.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __fpos64_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__pos, "__pos", &os));
    abii_args->push_arg(new ArgPrinter(obj.__state, "__state", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN___FPOS64_T_H
