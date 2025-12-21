//
// Created by Trent Tanchin on 12/23/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_SOCKET_TYPE_H
#define ABII_C_LOGGING_PLUGIN_SOCKET_TYPE_H

#include <abii/libabii.h>
#include <bits/socket_type.h>

namespace abii
{
const defines_map socket_type_enum1 = {
    {SOCK_STREAM, "SOCK_STREAM"},
    {SOCK_DGRAM, "SOCK_DGRAM"},
    {SOCK_RAW, "SOCK_RAW"},
    {SOCK_RDM, "SOCK_RDM"},
    {SOCK_SEQPACKET, "SOCK_SEQPACKET"},
    {SOCK_DCCP, "SOCK_DCCP"},
    {SOCK_PACKET, "SOCK_PACKET"}
};

const defines_map socket_type_enum2 = {
    {SOCK_CLOEXEC, "SOCK_CLOEXEC"},
    {SOCK_NONBLOCK, "SOCK_NONBLOCK"}
};

template<typename T>
std::string print_socket_type_enum1(const T v)
{
    return print_enum_entry(v, socket_type_enum1);
}

template<typename T>
std::string print_socket_type_enum2(const T v)
{
    return print_or_enum_entries(v, socket_type_enum2);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SOCKET_TYPE_H
