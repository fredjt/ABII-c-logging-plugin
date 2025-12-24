//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SEMAPHORE_H
#define ABII_C_LOGGING_PLUGIN_SEMAPHORE_H

#include <abii/libabii.h>
#include <bits/semaphore.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sem_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__size, "__size", &os));
    abii_args->push_arg(new ArgPrinter(obj.__align, "__align", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_SEMAPHORE_H
