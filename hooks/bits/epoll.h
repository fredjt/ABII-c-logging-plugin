//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_EPOLL_H
#define ABII_C_LOGGING_PLUGIN_BITS_EPOLL_H

#include <abii/libabii.h>
#include <sys/epoll.h>

namespace abii
{
const defines_map bits_epoll_cloexec = {
    {EPOLL_CLOEXEC, "EPOLL_CLOEXEC"}
};

template <typename T>
std::string print_bits_epoll_cloexec(const T v)
{
    return print_or_enum_entries(v, bits_epoll_cloexec);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_EPOLL_H
