//
// Created by Trent Tanchin on 12/23/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_IN_H
#define ABII_C_LOGGING_PLUGIN_IN_H

#include <abii/libabii.h>
#include <netinet/in.h>

namespace abii
{
const defines_map in_ipproto = {
    {0, "IPPROTO_IP"},
    {1, "IPPROTO_ICMP"},
    {2, "IPPROTO_IGMP"},
    {4, "IPPROTO_IPIP"},
    {6, "IPPROTO_TCP"},
    {8, "IPPROTO_EGP"},
    {12, "IPPROTO_PUP"},
    {17, "IPPROTO_UDP"},
    {22, "IPPROTO_IDP"},
    {29, "IPPROTO_TP"},
    {33, "IPPROTO_DCCP"},
    {41, "IPPROTO_IPV6"},
    {46, "IPPROTO_RSVP"},
    {47, "IPPROTO_GRE"},
    {50, "IPPROTO_ESP"},
    {51, "IPPROTO_AH"},
    {92, "IPPROTO_MTP"},
    {94, "IPPROTO_BEETPH"},
    {98, "IPPROTO_ENCAP"},
    {103, "IPPROTO_PIM"},
    {108, "IPPROTO_COMP"},
    {115, "IPPROTO_L2TP"},
    {132, "IPPROTO_SCTP"},
    {136, "IPPROTO_UDPLITE"},
    {137, "IPPROTO_MPLS"},
    {143, "IPPROTO_ETHERNET"},
    {255, "IPPROTO_RAW"},
    {256, "IPPROTO_SMC"},
    {262, "IPPROTO_MPTCP"},
    {263, "IPPROTO_MAX"}
};

template <typename T>
std::string print_in_ipproto(const T v)
{
    return print_enum_entry(v, in_ipproto);
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
