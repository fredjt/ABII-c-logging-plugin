//
// Created by Trent Tanchin on 10/9/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_NETDB_H
#define ABII_C_LOGGING_PLUGIN_NETDB_H

#include <netdb.h>
#include <abii/libabii.h>

#include "bits/socket.h"
#include "bits/socket_type.h"
#include "netinet/in.h"

namespace abii
{
const defines_map<const char*> netdb_path = {
    {"/etc/hosts.equiv", "_PATH_HEQUIV"},
    {"/etc/hosts", "_PATH_HOSTS"},
    {"/etc/networks", "_PATH_NETWORKS"},
    {"/etc/nsswitch.conf", "_PATH_NSSWITCH_CONF"},
    {"/etc/protocols", "_PATH_PROTOCOLS"},
    {"/etc/services", "_PATH_SERVICES"}
};

const defines_map netdb_h_errno = {
    {1, "HOST_NOT_FOUND"},
    {2, "TRY_AGAIN"},
    {3, "NO_RECOVERY"},
    {4, "NO_DATA"},
    {-1, "NETDB_INTERNAL"},
    {0, "NETDB_SUCCESS"},
    {4, "NO_ADDRESS"}
};

const defines_map netdb_ipport_reserved = {
    {1024, "IPPORT_RESERVED"}
};

const defines_map netdb_scope_delimiter = {
    {'%', "SCOPE_DELIMITER"}
};

const defines_map netdb_lookup_mode = {
    {0, "GAI_WAIT"},
    {1, "GAI_NOWAIT"}
};

const defines_map netdb_ai_flag = {
    {0x0001, "AI_PASSIVE"},
    {0x0002, "AI_CANONNAME"},
    {0x0004, "AI_NUMERICHOST"},
    {0x0008, "AI_V4MAPPED"},
    {0x0010, "AI_ALL"},
    {0x0020, "AI_ADDRCONFIG"},
    {0x0040, "AI_IDN"},
    {0x0080, "AI_CANONIDN"},
    {0x0100, "AI_IDN_ALLOW_UNASSIGNED"},
    {0x0200, "AI_IDN_USE_STD3_ASCII_RULES"},
    {0x0400, "AI_NUMERICSERV"}
};

const defines_map netdb_ai_errno = {
    {-1, "EAI_BADFLAGS"},
    {-2, "EAI_NONAME"},
    {-3, "EAI_AGAIN"},
    {-4, "EAI_FAIL"},
    {-6, "EAI_FAMILY"},
    {-7, "EAI_SOCKTYPE"},
    {-8, "EAI_SERVICE"},
    {-10, "EAI_MEMORY"},
    {-11, "EAI_SYSTEM"},
    {-12, "EAI_OVERFLOW"},
    {-5, "EAI_NODATA"},
    {-9, "EAI_ADDRFAMILY"},
    {-100, "EAI_INPROGRESS"},
    {-101, "EAI_CANCELED"},
    {-102, "EAI_NOTCANCELED"},
    {-103, "EAI_ALLDONE"},
    {-104, "EAI_INTR"},
    {-105, "EAI_IDN_ENCODE"}
};

const defines_map netdb_ni_maxhost = {
    {1025, "NI_MAXHOST"}
};

const defines_map netdb_ni_maxserv = {
    {32, "NI_MAXSERV"}
};

const defines_map netdb_ni_flag = {
    {1, "NI_NUMERICHOST"},
    {2, "NI_NUMERICSERV"},
    {4, "NI_NOFQDN"},
    {8, "NI_NAMEREQD"},
    {16, "NI_DGRAM"},
    {32, "NI_IDN"},
    {64, "NI_IDN_ALLOW_UNASSIGNED"},
    {128, "NI_IDN_USE_STD3_ASCII_RULES"}
};

template <typename T>
std::string print_netdb_path(const T v)
{
    return print_enum_entry(v, netdb_path);
}

template <typename T>
std::string print_netdb_h_errno(const T v)
{
    return print_enum_entry(v, netdb_h_errno);
}

template <typename T>
std::string print_netdb_ipport_reserved(const T v)
{
    return print_enum_entry(v, netdb_ipport_reserved);
}

template <typename T>
std::string print_netdb_scope_delimiter(const T v)
{
    return print_enum_entry(v, netdb_scope_delimiter);
}

template <typename T>
std::string print_netdb_lookup_mode(const T v)
{
    return print_enum_entry(v, netdb_lookup_mode);
}

template <typename T>
std::string print_netdb_ai_flag(const T v)
{
    return print_or_enum_entries(v, netdb_ai_flag);
}

template <typename T>
std::string print_netdb_ai_errno(const T v)
{
    return print_enum_entry(v, netdb_ai_errno);
}

template <typename T>
std::string print_netdb_ni_maxhost(const T v)
{
    return print_enum_entry(v, netdb_ni_maxhost);
}

template <typename T>
std::string print_netdb_ni_maxserv(const T v)
{
    return print_enum_entry(v, netdb_ni_maxserv);
}

template <typename T>
std::string print_netdb_ni_flag(const T v)
{
    return print_or_enum_entries(v, netdb_ni_flag);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, hostent>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.h_name, "h_name", &os));

    auto printer = new ArgPrinter(obj.h_aliases, "h_aliases", &os);
    printer->set_end_test([&](const size_t i) { return obj.h_aliases[i] != nullptr; });
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.h_addrtype, "h_addrtype", &os);
    printer1->set_enum_printer(print_socket_addr_family, obj.h_addrtype);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.h_length, "h_length", &os));

    auto printer2 = new ArgPrinter(obj.h_addr_list, "h_addr_list", &os, RECURSE);
    printer2->set_end_test([&](const size_t i) { return obj.h_addr_list[i] != nullptr; });
    // TODO: This is not properly implemented yet.
    // printer2->set_len_with_depth(obj.h_length, 1);
    abii_args->push_arg(printer2);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, servent>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.s_name, "s_name", &os));

    auto printer = new ArgPrinter(obj.s_aliases, "s_aliases", &os);
    printer->set_end_test([&](const size_t i) { return obj.s_aliases[i] != nullptr; });
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.s_port, "s_port", &os));
    abii_args->push_arg(new ArgPrinter(obj.s_proto, "s_proto", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, protoent>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.p_name, "p_name", &os));

    auto printer = new ArgPrinter(obj.p_aliases, "p_aliases", &os);
    printer->set_end_test([&](const size_t i) { return obj.p_aliases[i] != nullptr; });
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.p_proto, "p_proto", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, addrinfo>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.ai_flags, "ai_flags", &os);
    printer->set_enum_printer(print_netdb_ai_flag, obj.ai_flags);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.ai_family, "ai_family", &os);
    printer1->set_enum_printer(print_socket_addr_family, obj.ai_family);
    abii_args->push_arg(printer1);

    auto printer2 = new ArgPrinter(obj.ai_socktype, "ai_socktype", &os);
    printer2->set_enum_printer(print_socket_type___socket_type, obj.ai_socktype);
    abii_args->push_arg(printer2);

    auto printer3 = new ArgPrinter(obj.ai_protocol, "ai_protocol", &os);
    printer3->set_enum_printer(print_in_ipproto, obj.ai_protocol);
    abii_args->push_arg(printer3);

    abii_args->push_arg(new ArgPrinter(obj.ai_addrlen, "ai_addrlen", &os));
    abii_args->push_arg(new ArgPrinter(obj.ai_addr, "ai_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.ai_canonname, "ai_canonname", &os));
    abii_args->push_arg(new ArgPrinter(obj.ai_next, "ai_next", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, gaicb>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ar_name, "ar_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.ar_service, "ar_service", &os));
    abii_args->push_arg(new ArgPrinter(obj.ar_request, "ar_request", &os));
    abii_args->push_arg(new ArgPrinter(obj.ar_result, "ar_result", &os));

    auto printer = new ArgPrinter(obj.__return, "__return", &os);
    printer->set_enum_printer(print_netdb_ai_errno, obj.__return);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved, "__glibc_reserved", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_NETDB_H
