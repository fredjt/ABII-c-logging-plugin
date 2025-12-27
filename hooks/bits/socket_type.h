//
// Created by Trent Tanchin on 12/23/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_SOCKET_TYPE_H
#define ABII_C_LOGGING_PLUGIN_SOCKET_TYPE_H

#include <abii/libabii.h>

namespace abii
{
const defines_map socket_type___socket_type = {
    {1, "SOCK_STREAM"},
    {2, "SOCK_DGRAM"},
    {3, "SOCK_RAW"},
    {4, "SOCK_RDM"},
    {5, "SOCK_SEQPACKET"},
    {6, "SOCK_DCCP"},
    {10, "SOCK_PACKET"}
};

const defines_map socket_type_flag = {
    {02000000, "SOCK_CLOEXEC"},
    {00004000, "SOCK_NONBLOCK"}
};

template <typename T>
std::string print_socket_type___socket_type(const T v)
{
    return print_enum_entry(v, socket_type___socket_type);
}

template <typename T>
std::string print_socket_type_flag(const T v)
{
    return print_or_enum_entries(v, socket_type_flag);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SOCKET_TYPE_H
