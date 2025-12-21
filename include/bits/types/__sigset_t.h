//
// Created by Trent Tanchin on 3/6/25.
//

#ifndef ABII_C_LOGGING_PLUGIN___SIGSET_T_H
#define ABII_C_LOGGING_PLUGIN___SIGSET_T_H

#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __sigset_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__val, "__val", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN___SIGSET_T_H
