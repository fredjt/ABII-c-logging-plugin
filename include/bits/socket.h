//
// Created by Trent Tanchin on 9/28/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_SOCKET_H
#define ABII_C_LOGGING_PLUGIN_SOCKET_H

#include <bits/socket.h>

namespace abii
{
const defines_map socket_enum1 = {
    {PF_UNSPEC, "PF_UNSPEC"},
    {PF_LOCAL, "PF_LOCAL"},
    {PF_UNIX, "PF_UNIX"},
    {PF_FILE, "PF_FILE"},
    {PF_INET, "PF_INET"},
    {PF_AX25, "PF_AX25"},
    {PF_IPX, "PF_IPX"},
    {PF_APPLETALK, "PF_APPLETALK"},
    {PF_NETROM, "PF_NETROM"},
    {PF_BRIDGE, "PF_BRIDGE"},
    {PF_ATMPVC, "PF_ATMPVC"},
    {PF_X25, "PF_X25"},
    {PF_INET6, "PF_INET6"},
    {PF_ROSE, "PF_ROSE"},
    {PF_DECnet, "PF_DECnet"},
    {PF_NETBEUI, "PF_NETBEUI"},
    {PF_SECURITY, "PF_SECURITY"},
    {PF_KEY, "PF_KEY"},
    {PF_NETLINK, "PF_NETLINK"},
    {PF_ROUTE, "PF_ROUTE"},
    {PF_PACKET, "PF_PACKET"},
    {PF_ASH, "PF_ASH"},
    {PF_ECONET, "PF_ECONET"},
    {PF_ATMSVC, "PF_ATMSVC"},
    {PF_RDS, "PF_RDS"},
    {PF_SNA, "PF_SNA"},
    {PF_IRDA, "PF_IRDA"},
    {PF_PPPOX, "PF_PPPOX"},
    {PF_WANPIPE, "PF_WANPIPE"},
    {PF_LLC, "PF_LLC"},
    {PF_IB, "PF_IB"},
    {PF_MPLS, "PF_MPLS"},
    {PF_CAN, "PF_CAN"},
    {PF_TIPC, "PF_TIPC"},
    {PF_BLUETOOTH, "PF_BLUETOOTH"},
    {PF_IUCV, "PF_IUCV"},
    {PF_RXRPC, "PF_RXRPC"},
    {PF_ISDN, "PF_ISDN"},
    {PF_PHONET, "PF_PHONET"},
    {PF_IEEE802154, "PF_IEEE802154"},
    {PF_CAIF, "PF_CAIF"},
    {PF_ALG, "PF_ALG"},
    {PF_NFC, "PF_NFC"},
    {PF_VSOCK, "PF_VSOCK"},
    {PF_KCM, "PF_KCM"},
    {PF_QIPCRTR, "PF_QIPCRTR"},
    {PF_SMC, "PF_SMC"},
    {PF_XDP, "PF_XDP"},
    {PF_MCTP, "PF_MCTP"},
    {PF_MAX, "PF_MAX"}
};

const defines_map socket_enum2 = {
    {AF_UNSPEC, "AF_UNSPEC"},
    {AF_LOCAL, "AF_LOCAL"},
    {AF_UNIX, "AF_UNIX"},
    {AF_FILE, "AF_FILE"},
    {AF_INET, "AF_INET"},
    {AF_AX25, "AF_AX25"},
    {AF_IPX, "AF_IPX"},
    {AF_APPLETALK, "AF_APPLETALK"},
    {AF_NETROM, "AF_NETROM"},
    {AF_BRIDGE, "AF_BRIDGE"},
    {AF_ATMPVC, "AF_ATMPVC"},
    {AF_X25, "AF_X25"},
    {AF_INET6, "AF_INET6"},
    {AF_ROSE, "AF_ROSE"},
    {AF_DECnet, "AF_DECnet"},
    {AF_NETBEUI, "AF_NETBEUI"},
    {AF_SECURITY, "AF_SECURITY"},
    {AF_KEY, "AF_KEY"},
    {AF_NETLINK, "AF_NETLINK"},
    {AF_ROUTE, "AF_ROUTE"},
    {AF_PACKET, "AF_PACKET"},
    {AF_ASH, "AF_ASH"},
    {AF_ECONET, "AF_ECONET"},
    {AF_ATMSVC, "AF_ATMSVC"},
    {AF_RDS, "AF_RDS"},
    {AF_SNA, "AF_SNA"},
    {AF_IRDA, "AF_IRDA"},
    {AF_PPPOX, "AF_PPPOX"},
    {AF_WANPIPE, "AF_WANPIPE"},
    {AF_LLC, "AF_LLC"},
    {AF_IB, "AF_IB"},
    {AF_MPLS, "AF_MPLS"},
    {AF_CAN, "AF_CAN"},
    {AF_TIPC, "AF_TIPC"},
    {AF_BLUETOOTH, "AF_BLUETOOTH"},
    {AF_IUCV, "AF_IUCV"},
    {AF_RXRPC, "AF_RXRPC"},
    {AF_ISDN, "AF_ISDN"},
    {AF_PHONET, "AF_PHONET"},
    {AF_IEEE802154, "AF_IEEE802154"},
    {AF_CAIF, "AF_CAIF"},
    {AF_ALG, "AF_ALG"},
    {AF_NFC, "AF_NFC"},
    {AF_VSOCK, "AF_VSOCK"},
    {AF_KCM, "AF_KCM"},
    {AF_QIPCRTR, "AF_QIPCRTR"},
    {AF_SMC, "AF_SMC"},
    {AF_XDP, "AF_XDP"},
    {AF_MCTP, "AF_MCTP"},
    {AF_MAX, "AF_MAX"}
};

template <typename T>
std::string print_socket_enum1(const T v)
{
    return print_enum_entry(v, socket_enum1);
}

template <typename T>
std::string print_socket_enum2(const T v)
{
    return print_enum_entry(v, socket_enum2);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sockaddr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.sa_family, "sa_family", &os);
    printer->set_enum_printer(print_socket_enum2, obj.sa_family);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.sa_data, "sa_data", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_SOCKET_H
