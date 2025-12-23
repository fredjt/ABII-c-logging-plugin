//
// Created by Trent Tanchin on 9/28/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_SOCKET_H
#define ABII_C_LOGGING_PLUGIN_SOCKET_H

#include <bits/socket.h>

namespace abii
{
const defines_map socket_protocol_family = {
    {0, "PF_UNSPEC"},
    {1, "PF_LOCAL"},
    {1, "PF_UNIX"},
    {1, "PF_FILE"},
    {2, "PF_INET"},
    {3, "PF_AX25"},
    {4, "PF_IPX"},
    {5, "PF_APPLETALK"},
    {6, "PF_NETROM"},
    {7, "PF_BRIDGE"},
    {8, "PF_ATMPVC"},
    {9, "PF_X25"},
    {10, "PF_INET6"},
    {11, "PF_ROSE"},
    {12, "PF_DECnet"},
    {13, "PF_NETBEUI"},
    {14, "PF_SECURITY"},
    {15, "PF_KEY"},
    {16, "PF_NETLINK"},
    {16, "PF_ROUTE"},
    {17, "PF_PACKET"},
    {18, "PF_ASH"},
    {19, "PF_ECONET"},
    {20, "PF_ATMSVC"},
    {21, "PF_RDS"},
    {22, "PF_SNA"},
    {23, "PF_IRDA"},
    {24, "PF_PPPOX"},
    {25, "PF_WANPIPE"},
    {26, "PF_LLC"},
    {27, "PF_IB"},
    {28, "PF_MPLS"},
    {29, "PF_CAN"},
    {30, "PF_TIPC"},
    {31, "PF_BLUETOOTH"},
    {32, "PF_IUCV"},
    {33, "PF_RXRPC"},
    {34, "PF_ISDN"},
    {35, "PF_PHONET"},
    {36, "PF_IEEE802154"},
    {37, "PF_CAIF"},
    {38, "PF_ALG"},
    {39, "PF_NFC"},
    {40, "PF_VSOCK"},
    {41, "PF_KCM"},
    {42, "PF_QIPCRTR"},
    {43, "PF_SMC"},
    {44, "PF_XDP"},
    {45, "PF_MCTP"},
    {46, "PF_MAX"}
};

const defines_map socket_addr_family = {
    {0, "AF_UNSPEC"},
    {1, "AF_LOCAL"},
    {1, "AF_UNIX"},
    {1, "AF_FILE"},
    {2, "AF_INET"},
    {3, "AF_AX25"},
    {4, "AF_IPX"},
    {5, "AF_APPLETALK"},
    {6, "AF_NETROM"},
    {7, "AF_BRIDGE"},
    {8, "AF_ATMPVC"},
    {9, "AF_X25"},
    {10, "AF_INET6"},
    {11, "AF_ROSE"},
    {12, "AF_DECnet"},
    {13, "AF_NETBEUI"},
    {14, "AF_SECURITY"},
    {15, "AF_KEY"},
    {16, "AF_NETLINK"},
    {16, "AF_ROUTE"},
    {17, "AF_PACKET"},
    {18, "AF_ASH"},
    {19, "AF_ECONET"},
    {20, "AF_ATMSVC"},
    {21, "AF_RDS"},
    {22, "AF_SNA"},
    {23, "AF_IRDA"},
    {24, "AF_PPPOX"},
    {25, "AF_WANPIPE"},
    {26, "AF_LLC"},
    {27, "AF_IB"},
    {28, "AF_MPLS"},
    {29, "AF_CAN"},
    {30, "AF_TIPC"},
    {31, "AF_BLUETOOTH"},
    {32, "AF_IUCV"},
    {33, "AF_RXRPC"},
    {34, "AF_ISDN"},
    {35, "AF_PHONET"},
    {36, "AF_IEEE802154"},
    {37, "AF_CAIF"},
    {38, "AF_ALG"},
    {39, "AF_NFC"},
    {40, "AF_VSOCK"},
    {41, "AF_KCM"},
    {42, "AF_QIPCRTR"},
    {43, "AF_SMC"},
    {44, "AF_XDP"},
    {45, "AF_MCTP"},
    {46, "AF_MAX"}
};

template <typename T>
std::string print_socket_protocol_family(const T v)
{
    return print_enum_entry(v, socket_protocol_family);
}

template <typename T>
std::string print_socket_addr_family(const T v)
{
    return print_enum_entry(v, socket_addr_family);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sockaddr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = ArgPrinter(obj.sa_family, "sa_family", &os);
    printer.set_enum_printer(print_socket_addr_family, obj.sa_family);
    abii_args->push_arg(&printer);

    abii_args->push_arg(new ArgPrinter(obj.sa_data, "sa_data", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_SOCKET_H
