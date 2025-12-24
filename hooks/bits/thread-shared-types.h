//
// Created by Trent Tanchin on 3/7/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_THREAD_SHARED_TYPES_H
#define ABII_C_LOGGING_PLUGIN_THREAD_SHARED_TYPES_H

#include <bits/thread-shared-types.h>

#include "atomic_wide_counter.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __pthread_list_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__prev, "__prev", &os));
    abii_args->push_arg(new ArgPrinter(obj.__next, "__next", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __pthread_slist_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__next, "__next", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __pthread_cond_s>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__wseq, "__wseq", &os));
    abii_args->push_arg(new ArgPrinter(obj.__g1_start, "__g1_start", &os));
    abii_args->push_arg(new ArgPrinter(obj.__g_size, "__g_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.__g1_orig_size, "__g1_orig_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.__wrefs, "__wrefs", &os));
    abii_args->push_arg(new ArgPrinter(obj.__g_signals, "__g_signals", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_THREAD_SHARED_TYPES_H
