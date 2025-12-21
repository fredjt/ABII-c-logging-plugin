//
// Created by Trent Tanchin on 7/3/24.
//

#ifndef ABII_C_LOGGING_PLUGIN___SIGVAL_T_H
#define ABII_C_LOGGING_PLUGIN___SIGVAL_T_H

#include <abii/libabii.h>
#include <bits/types/__sigval_t.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __sigval_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#ifdef __USE_POSIX199309
    abii_args->push_arg(new ArgPrinter(obj.sival_int, "sival_int", &os));
    abii_args->push_arg(new ArgPrinter(obj.sival_ptr, "sival_ptr", &os, RECURSE));
#else
    abii_args->push_single(new ArgPrinter(obj.__sival_int, "__sival_int", &os));
    abii_args->push_single(new ArgPrinter(obj.__sival_ptr, "__sival_ptr", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN___SIGVAL_T_H
