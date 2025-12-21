//
// Created by Trent Tanchin on 3/7/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_STRUCT_MUTEX_H
#define ABII_C_LOGGING_PLUGIN_STRUCT_MUTEX_H

#include <bits/struct_mutex.h>

#include "include/pthread.h"
#include "thread-shared-types.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __pthread_mutex_s>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__lock, "__lock", &os));
    abii_args->push_arg(new ArgPrinter(obj.__count, "__count", &os));
    abii_args->push_arg(new ArgPrinter(obj.__owner, "__owner", &os));
#ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__nusers, "__nusers", &os));
#endif
    auto printer = new ArgPrinter(obj.__kind, "__kind", &os);
    printer->set_enum_printer(print_pthread_mutex_type, obj.__kind);
    abii_args->push_arg(printer);
#ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__spins, "__spins", &os));
    abii_args->push_arg(new ArgPrinter(obj.__elision, "__elision", &os));
    abii_args->push_arg(new ArgPrinter(obj.__list, "__list", &os, RECURSE));
#else
    abii_args->push_arg(new ArgPrinter(obj.__nusers, "__nusers", &os));
    abii_args->push_arg(new ArgPrinter(obj.__elision_data, "__elision_data", &os));
    abii_args->push_arg(new ArgPrinter(obj.__list, "__list", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

#ifndef __x86_64__
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(__pthread_mutex_s::__elision_data)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__espins, "__espins", &os));
    abii_args->push_arg(new ArgPrinter(obj.__eelision, "__eelision", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_STRUCT_MUTEX_H
