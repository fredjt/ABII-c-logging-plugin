//
// Created by Trent Tanchin on 7/14/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_PTHREADTYPES_H
#define ABII_C_LOGGING_PLUGIN_PTHREADTYPES_H

#include <bits/pthreadtypes.h>

#include "struct_mutex.h"
#include "struct_rwlock.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, pthread_mutexattr_t>
    || std::is_same_v<std::remove_cvref_t<T>, pthread_condattr_t>
    || std::is_same_v<std::remove_cvref_t<T>, pthread_attr_t>
    || std::is_same_v<std::remove_cvref_t<T>, pthread_rwlockattr_t>
    || std::is_same_v<std::remove_cvref_t<T>, pthread_barrier_t>
    || std::is_same_v<std::remove_cvref_t<T>, pthread_barrierattr_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__size, "__size", &os));
    abii_args->push_arg(new ArgPrinter(obj.__align, "__align", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, pthread_mutex_t>
    || std::is_same_v<std::remove_cvref_t<T>, pthread_cond_t>
    || std::is_same_v<std::remove_cvref_t<T>, pthread_rwlock_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__data, "__data", &os));
    abii_args->push_arg(new ArgPrinter(obj.__size, "__size", &os));
    abii_args->push_arg(new ArgPrinter(obj.__align, "__align", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

inline bool operator==(const pthread_cond_t& lhs, const pthread_cond_t& rhs)
{
    return std::memcmp(&lhs, &rhs, sizeof(pthread_cond_t)) == 0;
}

#endif //ABII_C_LOGGING_PLUGIN_PTHREADTYPES_H
