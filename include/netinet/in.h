//
// Created by Trent Tanchin on 12/23/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_IN_H
#define ABII_C_LOGGING_PLUGIN_IN_H

#include <abii/libabii.h>
#include <netinet/in.h>

namespace abii
{
const defines_map in_enum1 = {
    {IPPROTO_IP, "IPPROTO_IP"},
    {IPPROTO_ICMP, "IPPROTO_ICMP"},
    {IPPROTO_IGMP, "IPPROTO_IGMP"},
    {IPPROTO_IPIP, "IPPROTO_IPIP"},
    {IPPROTO_TCP, "IPPROTO_TCP"},
    {IPPROTO_EGP, "IPPROTO_EGP"},
    {IPPROTO_PUP, "IPPROTO_PUP"},
    {IPPROTO_UDP, "IPPROTO_UDP"},
    {IPPROTO_IDP, "IPPROTO_IDP"},
    {IPPROTO_TP, "IPPROTO_TP"},
    {IPPROTO_DCCP, "IPPROTO_DCCP"},
    {IPPROTO_IPV6, "IPPROTO_IPV6"},
    {IPPROTO_RSVP, "IPPROTO_RSVP"},
    {IPPROTO_GRE, "IPPROTO_GRE"},
    {IPPROTO_ESP, "IPPROTO_ESP"},
    {IPPROTO_AH, "IPPROTO_AH"},
    {IPPROTO_MTP, "IPPROTO_MTP"},
    {IPPROTO_BEETPH, "IPPROTO_BEETPH"},
    {IPPROTO_ENCAP, "IPPROTO_ENCAP"},
    {IPPROTO_PIM, "IPPROTO_PIM"},
    {IPPROTO_COMP, "IPPROTO_COMP"},
    {IPPROTO_L2TP, "IPPROTO_L2TP"},
    {IPPROTO_SCTP, "IPPROTO_SCTP"},
    {IPPROTO_UDPLITE, "IPPROTO_UDPLITE"},
    {IPPROTO_MPLS, "IPPROTO_MPLS"},
    {IPPROTO_ETHERNET, "IPPROTO_ETHERNET"},
    {IPPROTO_RAW, "IPPROTO_RAW"},
    {IPPROTO_SMC, "IPPROTO_SMC"},
    {IPPROTO_MPTCP, "IPPROTO_MPTCP"},
    {IPPROTO_MAX, "IPPROTO_MAX"}
};

template <typename T>
std::string print_in_enum1(const T v)
{
    return print_enum_entry(v, in_enum1);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, in_addr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.s_addr, "s_addr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, in6_addr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__in6_u, "__in6_u", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(in6_addr::__in6_u)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__u6_addr8, "__u6_addr8", &os));
    abii_args->push_arg(new ArgPrinter(obj.__u6_addr16, "__u6_addr16", &os));
    abii_args->push_arg(new ArgPrinter(obj.__u6_addr32, "__u6_addr32", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sockaddr_in>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.sin_family, "sin_family", &os));
    abii_args->push_arg(new ArgPrinter(obj.sin_port, "sin_port", &os));
    abii_args->push_arg(new ArgPrinter(obj.sin_addr, "sin_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.sin_zero, "sin_zero", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#if !__USE_KERNEL_IPV6_DEFS
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sockaddr_in6>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.sin6_family, "sin6_family", &os));
    abii_args->push_arg(new ArgPrinter(obj.sin6_port, "sin6_port", &os));
    abii_args->push_arg(new ArgPrinter(obj.sin6_flowinfo, "sin6_flowinfo", &os));
    abii_args->push_arg(new ArgPrinter(obj.sin6_addr, "sin6_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.sin6_scope_id, "sin6_scope_id", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_IN_H
