//
// Created by Trent Tanchin on 11/13/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_IN_H
#define ABII_C_LOGGING_PLUGIN_IN_H

#include <abii/libabii.h>
#include <netinet/in.h>

namespace abii
{
const defines_map bits_in_sockopt = {
    {IP_OPTIONS, "IP_OPTIONS"},
    {IP_HDRINCL, "IP_HDRINCL"},
    {IP_TOS, "IP_TOS"},
    {IP_TTL, "IP_TTL"},
    {IP_RECVOPTS, "IP_RECVOPTS"},
    {IP_RECVRETOPTS, "IP_RECVRETOPTS"},
    {IP_RETOPTS, "IP_RETOPTS"},
    {IP_MULTICAST_IF, "IP_MULTICAST_IF"},
    {IP_MULTICAST_TTL, "IP_MULTICAST_TTL"},
    {IP_MULTICAST_LOOP, "IP_MULTICAST_LOOP"},
    {IP_ADD_MEMBERSHIP, "IP_ADD_MEMBERSHIP"},
    {IP_DROP_MEMBERSHIP, "IP_DROP_MEMBERSHIP"},
    {IP_UNBLOCK_SOURCE, "IP_UNBLOCK_SOURCE"},
    {IP_BLOCK_SOURCE, "IP_BLOCK_SOURCE"},
    {IP_ADD_SOURCE_MEMBERSHIP, "IP_ADD_SOURCE_MEMBERSHIP"},
    {IP_DROP_SOURCE_MEMBERSHIP, "IP_DROP_SOURCE_MEMBERSHIP"},
    {IP_MSFILTER, "IP_MSFILTER"},
    {MCAST_JOIN_GROUP, "MCAST_JOIN_GROUP"},
    {MCAST_BLOCK_SOURCE, "MCAST_BLOCK_SOURCE"},
    {MCAST_UNBLOCK_SOURCE, "MCAST_UNBLOCK_SOURCE"},
    {MCAST_LEAVE_GROUP, "MCAST_LEAVE_GROUP"},
    {MCAST_JOIN_SOURCE_GROUP, "MCAST_JOIN_SOURCE_GROUP"},
    {MCAST_LEAVE_SOURCE_GROUP, "MCAST_LEAVE_SOURCE_GROUP"},
    {MCAST_MSFILTER, "MCAST_MSFILTER"},
    {IP_MULTICAST_ALL, "IP_MULTICAST_ALL"},
    {IP_UNICAST_IF, "IP_UNICAST_IF"},
    {MCAST_EXCLUDE, "MCAST_EXCLUDE"},
    {MCAST_INCLUDE, "MCAST_INCLUDE"},
    {IP_ROUTER_ALERT, "IP_ROUTER_ALERT"},
    {IP_PKTINFO, "IP_PKTINFO"},
    {IP_PKTOPTIONS, "IP_PKTOPTIONS"},
    {IP_PMTUDISC, "IP_PMTUDISC"},
    {IP_MTU_DISCOVER, "IP_MTU_DISCOVER"},
    {IP_RECVERR, "IP_RECVERR"},
    {IP_RECVTTL, "IP_RECVTTL"},
    {IP_RECVTOS, "IP_RECVTOS"},
    {IP_MTU, "IP_MTU"},
    {IP_FREEBIND, "IP_FREEBIND"},
    {IP_IPSEC_POLICY, "IP_IPSEC_POLICY"},
    {IP_XFRM_POLICY, "IP_XFRM_POLICY"},
    {IP_PASSSEC, "IP_PASSSEC"},
    {IP_TRANSPARENT, "IP_TRANSPARENT"},
    {IP_MULTICAST_ALL, "IP_MULTICAST_ALL"},
    {IP_ORIGDSTADDR, "IP_ORIGDSTADDR"},
    {IP_RECVORIGDSTADDR, "IP_RECVORIGDSTADDR"},
    {IP_MINTTL, "IP_MINTTL"},
    {IP_NODEFRAG, "IP_NODEFRAG"},
    {IP_CHECKSUM, "IP_CHECKSUM"},
    {IP_BIND_ADDRESS_NO_PORT, "IP_BIND_ADDRESS_NO_PORT"},
    {IP_RECVFRAGSIZE, "IP_RECVFRAGSIZE"},
    {IP_RECVERR_RFC4884, "IP_RECVERR_RFC4884"}
};

const defines_map bits_in_ip_mtu_discover_arg = {
    {IP_PMTUDISC_DONT, "IP_PMTUDISC_DONT"},
    {IP_PMTUDISC_WANT, "IP_PMTUDISC_WANT"},
    {IP_PMTUDISC_DO, "IP_PMTUDISC_DO"},
    {IP_PMTUDISC_PROBE, "IP_PMTUDISC_PROBE"},
    {IP_PMTUDISC_INTERFACE, "IP_PMTUDISC_INTERFACE"},
    {IP_PMTUDISC_OMIT, "IP_PMTUDISC_OMIT"},
    {IP_MULTICAST_IF, "IP_MULTICAST_IF"},
    {IP_MULTICAST_TTL, "IP_MULTICAST_TTL"},
    {IP_MULTICAST_LOOP, "IP_MULTICAST_LOOP"},
    {IP_ADD_MEMBERSHIP, "IP_ADD_MEMBERSHIP"},
    {IP_DROP_MEMBERSHIP, "IP_DROP_MEMBERSHIP"},
    {IP_UNBLOCK_SOURCE, "IP_UNBLOCK_SOURCE"},
    {IP_BLOCK_SOURCE, "IP_BLOCK_SOURCE"},
    {IP_ADD_SOURCE_MEMBERSHIP, "IP_ADD_SOURCE_MEMBERSHIP"},
    {IP_DROP_SOURCE_MEMBERSHIP, "IP_DROP_SOURCE_MEMBERSHIP"},
    {IP_MSFILTER, "IP_MSFILTER"},
    {IP_MULTICAST_ALL, "IP_MULTICAST_ALL"},
    {IP_UNICAST_IF, "IP_UNICAST_IF"},
    {IP_LOCAL_PORT_RANGE, "IP_LOCAL_PORT_RANGE"},
    {IP_PROTOCOL, "IP_PROTOCOL"}
};

const defines_map bits_in_solevel = {
    {SOL_IP, "SOL_IP"}
};

const defines_map bits_in_ip_default_multicast_ttl = {
    {IP_DEFAULT_MULTICAST_TTL, "IP_DEFAULT_MULTICAST_TTL"}
};

const defines_map bits_in_ip_default_multicast_loop = {
    {IP_DEFAULT_MULTICAST_LOOP, "IP_DEFAULT_MULTICAST_LOOP"}
};

const defines_map bits_in_ip_max_memberships = {
    {IP_MAX_MEMBERSHIPS, "IP_MAX_MEMBERSHIPS"}
};

const defines_map bits_in_sockopt_ipv6 = {
    {IPV6_ADDRFORM, "IPV6_ADDRFORM"},
    {IPV6_2292PKTINFO, "IPV6_2292PKTINFO"},
    {IPV6_2292HOPOPTS, "IPV6_2292HOPOPTS"},
    {IPV6_2292DSTOPTS, "IPV6_2292DSTOPTS"},
    {IPV6_2292RTHDR, "IPV6_2292RTHDR"},
    {IPV6_2292PKTOPTIONS, "IPV6_2292PKTOPTIONS"},
    {IPV6_CHECKSUM, "IPV6_CHECKSUM"},
    {IPV6_2292HOPLIMIT, "IPV6_2292HOPLIMIT"},
    {SCM_SRCRT, "SCM_SRCRT"},
    {IPV6_NEXTHOP, "IPV6_NEXTHOP"},
    {IPV6_AUTHHDR, "IPV6_AUTHHDR"},
    {IPV6_UNICAST_HOPS, "IPV6_UNICAST_HOPS"},
    {IPV6_MULTICAST_IF, "IPV6_MULTICAST_IF"},
    {IPV6_MULTICAST_HOPS, "IPV6_MULTICAST_HOPS"},
    {IPV6_MULTICAST_LOOP, "IPV6_MULTICAST_LOOP"},
    {IPV6_JOIN_GROUP, "IPV6_JOIN_GROUP"},
    {IPV6_LEAVE_GROUP, "IPV6_LEAVE_GROUP"},
    {IPV6_ROUTER_ALERT, "IPV6_ROUTER_ALERT"},
    {IPV6_MTU_DISCOVER, "IPV6_MTU_DISCOVER"},
    {IPV6_MTU, "IPV6_MTU"},
    {IPV6_RECVERR, "IPV6_RECVERR"},
    {IPV6_V6ONLY, "IPV6_V6ONLY"},
    {IPV6_JOIN_ANYCAST, "IPV6_JOIN_ANYCAST"},
    {IPV6_LEAVE_ANYCAST, "IPV6_LEAVE_ANYCAST"},
    {IPV6_MULTICAST_ALL, "IPV6_MULTICAST_ALL"},
    {IPV6_ROUTER_ALERT_ISOLATE, "IPV6_ROUTER_ALERT_ISOLATE"},
    {IPV6_RECVERR_RFC4884, "IPV6_RECVERR_RFC4884"},
    {IPV6_IPSEC_POLICY, "IPV6_IPSEC_POLICY"},
    {IPV6_XFRM_POLICY, "IPV6_XFRM_POLICY"},
    {IPV6_HDRINCL, "IPV6_HDRINCL"},
    {IPV6_RECVPKTINFO, "IPV6_RECVPKTINFO"},
    {IPV6_PKTINFO, "IPV6_PKTINFO"},
    {IPV6_RECVHOPLIMIT, "IPV6_RECVHOPLIMIT"},
    {IPV6_HOPLIMIT, "IPV6_HOPLIMIT"},
    {IPV6_RECVHOPOPTS, "IPV6_RECVHOPOPTS"},
    {IPV6_HOPOPTS, "IPV6_HOPOPTS"},
    {IPV6_RTHDRDSTOPTS, "IPV6_RTHDRDSTOPTS"},
    {IPV6_RECVRTHDR, "IPV6_RECVRTHDR"},
    {IPV6_RTHDR, "IPV6_RTHDR"},
    {IPV6_RECVDSTOPTS, "IPV6_RECVDSTOPTS"},
    {IPV6_DSTOPTS, "IPV6_DSTOPTS"},
    {IPV6_RECVPATHMTU, "IPV6_RECVPATHMTU"},
    {IPV6_PATHMTU, "IPV6_PATHMTU"},
    {IPV6_DONTFRAG, "IPV6_DONTFRAG"},
    {IPV6_RECVTCLASS, "IPV6_RECVTCLASS"},
    {IPV6_TCLASS, "IPV6_TCLASS"},
    {IPV6_AUTOFLOWLABEL, "IPV6_AUTOFLOWLABEL"},
    {IPV6_ADDR_PREFERENCES, "IPV6_ADDR_PREFERENCES"},
    {IPV6_MINHOPCOUNT, "IPV6_MINHOPCOUNT"},
    {IPV6_ORIGDSTADDR, "IPV6_ORIGDSTADDR"},
    {IPV6_RECVORIGDSTADDR, "IPV6_RECVORIGDSTADDR"},
    {IPV6_TRANSPARENT, "IPV6_TRANSPARENT"},
    {IPV6_UNICAST_IF, "IPV6_UNICAST_IF"},
    {IPV6_RECVFRAGSIZE, "IPV6_RECVFRAGSIZE"},
    {IPV6_FREEBIND, "IPV6_FREEBIND"},
    {IPV6_ADD_MEMBERSHIP, "IPV6_ADD_MEMBERSHIP"},
    {IPV6_DROP_MEMBERSHIP, "IPV6_DROP_MEMBERSHIP"},
    {IPV6_RXHOPOPTS, "IPV6_RXHOPOPTS"},
    {IPV6_RXDSTOPTS, "IPV6_RXDSTOPTS"}
};

const defines_map bits_in_ipv6_mtu_discover_arg = {
    {IPV6_PMTUDISC_DONT, "IPV6_PMTUDISC_DONT"},
    {IPV6_PMTUDISC_WANT, "IPV6_PMTUDISC_WANT"},
    {IPV6_PMTUDISC_DO, "IPV6_PMTUDISC_DO"},
    {IPV6_PMTUDISC_PROBE, "IPV6_PMTUDISC_PROBE"},
    {IPV6_PMTUDISC_INTERFACE, "IPV6_PMTUDISC_INTERFACE"},
    {IPV6_PMTUDISC_OMIT, "IPV6_PMTUDISC_OMIT"}
};

const defines_map bits_in_solevel_ipv6 = {
    {SOL_IPV6, "SOL_IPV6"},
    {SOL_ICMPV6, "SOL_ICMPV6"}
};

const defines_map bits_in_rh_opts_ipv6 = {
    {IPV6_RTHDR_LOOSE, "IPV6_RTHDR_LOOSE"},
    {IPV6_RTHDR_STRICT, "IPV6_RTHDR_STRICT"}
};

const defines_map bits_in_ipv6_trhdr_type = {
    {IPV6_RTHDR_TYPE_0, "IPV6_RTHDR_TYPE_0"}
};

template <typename T>
std::string print_bits_in_sockopt(const T v)
{
    return print_enum_entry(v, bits_in_sockopt);
}

template <typename T>
std::string print_bits_in_ip_mtu_discover_arg(const T v)
{
    return print_enum_entry(v, bits_in_ip_mtu_discover_arg);
}

template <typename T>
std::string print_bits_in_solevel(const T v)
{
    return print_enum_entry(v, bits_in_solevel);
}

template <typename T>
std::string print_bits_in_ip_default_multicast_ttl(const T v)
{
    return print_enum_entry(v, bits_in_ip_default_multicast_ttl);
}

template <typename T>
std::string print_bits_in_ip_default_multicast_loop(const T v)
{
    return print_enum_entry(v, bits_in_ip_default_multicast_loop);
}

template <typename T>
std::string print_bits_in_ip_max_memberships(const T v)
{
    return print_enum_entry(v, bits_in_ip_max_memberships);
}

template <typename T>
std::string print_bits_in_sockopt_ipv6(const T v)
{
    return print_enum_entry(v, bits_in_sockopt_ipv6);
}

template <typename T>
std::string print_bits_in_ipv6_mtu_discover_arg(const T v)
{
    return print_enum_entry(v, bits_in_ipv6_mtu_discover_arg);
}

template <typename T>
std::string print_bits_in_solevel_ipv6(const T v)
{
    return print_enum_entry(v, bits_in_solevel_ipv6);
}

template <typename T>
std::string print_bits_in_rh_opts_ipv6(const T v)
{
    return print_enum_entry(v, bits_in_rh_opts_ipv6);
}

template <typename T>
std::string print_bits_in_ipv6_trhdr_type(const T v)
{
    return print_enum_entry(v, bits_in_ipv6_trhdr_type);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ip_opts>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ip_dst, "ip_dst", &os));
    abii_args->push_arg(new ArgPrinter(obj.ip_opts, "ip_opts", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, in_pktinfo>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ipi_ifindex, "ipi_ifindex", &os));
    abii_args->push_arg(new ArgPrinter(obj.ipi_spec_dst, "ipi_spec_dst", &os));
    abii_args->push_arg(new ArgPrinter(obj.ipi_addr, "ipi_addr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_IN_H
