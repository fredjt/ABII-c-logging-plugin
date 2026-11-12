//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_EVENTFD_H
#define ABII_C_LOGGING_PLUGIN_BITS_EVENTFD_H

#include <abii/libabii.h>
#include <sys/eventfd.h>

namespace abii
{
const defines_map bits_eventfd_efd = {
    {EFD_SEMAPHORE, "EFD_SEMAPHORE"},
    {EFD_CLOEXEC, "EFD_CLOEXEC"},
    {EFD_NONBLOCK, "EFD_NONBLOCK"}
};

template <typename T>
std::string print_bits_eventfd_efd(const T v)
{
    return print_or_enum_entries(v, bits_eventfd_efd);
}
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_EVENTFD_H
