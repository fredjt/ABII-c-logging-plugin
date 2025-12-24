//
// Created by Trent Tanchin on 7/3/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGEVENT_T_H
#define ABII_C_LOGGING_PLUGIN_SIGEVENT_T_H

#include <abii/libabii.h>
#include <bits/types/sigevent_t.h>

#include "__sigval_t.h"
#include "hooks/bits/pthreadtypes.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sigevent>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.sigev_value, "sigev_value", &os));
    abii_args->push_arg(new ArgPrinter(obj.sigev_signo, "sigev_signo", &os));
    abii_args->push_arg(new ArgPrinter(obj.sigev_notify, "sigev_notify", &os));
    abii_args->push_arg(new ArgPrinter(obj._sigev_un, "sigev_un", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(sigevent::_sigev_un)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj._pad, "_pad", &os));
    abii_args->push_arg(new ArgPrinter(obj._tid, "_tid", &os));
    abii_args->push_arg(new ArgPrinter(obj._sigev_thread, "_sigev_thread", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(sigevent::_sigev_un._sigev_thread)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj._function, "_function", &os));
    abii_args->push_arg(new ArgPrinter(obj._attribute, "_attribute", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_SIGEVENT_T_H
