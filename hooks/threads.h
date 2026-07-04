//
// Created by Trent Tanchin on 7/4/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_THREADS_H
#define ABII_C_LOGGING_PLUGIN_THREADS_H

#include <threads.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map threads_thrd = {
    {0, "thrd_success"},
    {1, "thrd_busy"},
    {2, "thrd_error"},
    {3, "thrd_nomem"},
    {4, "thrd_timedout"}
};

const defines_map threads_mtx = {
    {0, "mtx_plain"},
    {1, "mtx_recursive"},
    {2, "mtx_timed"}
};

template <typename T>
std::string print_threads_thrd(const T v)
{
    return print_enum_entry(v, threads_thrd);
}

template <typename T>
std::string print_threads_mtx(const T v)
{
    return print_enum_entry(v, threads_mtx);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, mtx_t>
    || std::is_same_v<std::remove_cvref_t<T>, cnd_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__size, "__size", &os));
    abii_args->push_arg(new ArgPrinter(obj.__align, "__align", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_THREADS_H
