//
// Created by Trent Tanchin on 4/17/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_RESOLV_H
#define ABII_C_LOGGING_PLUGIN_RESOLV_H

#include <resolv.h>
#include <abii/libabii.h>

#include "netinet/in.h"

namespace abii
{
const defines_map resolv_localdomainparts = {
    {2, "LOCALDOMAINPARTS"}
};

const defines_map resolv_timeout = {
    {5, "RES_TIMEOUT"}
};

const defines_map resolv_maxndots = {
    {15, "RES_MAXNDOTS"}
};

const defines_map resolv_maxretrans = {
    {30, "RES_MAXRETRANS"}
};

const defines_map resolv_maxretry = {
    {5, "RES_MAXRETRY"}
};

const defines_map resolv_dflretry = {
    {2, "RES_DFLRETRY"}
};

const defines_map resolv_maxtime = {
    {65535, "RES_MAXTIME"}
};

const defines_map<const char*> resolv_path_resconf = {
    {"/etc/resolv.conf", "_PATH_RESCONF"}
};

const defines_map resolv_option = {
    {0x00000001, "RES_INIT"},
    {0x00000002, "RES_DEBUG"},
    {0x00000004, "RES_AAONLY"},
    {0x00000008, "RES_USEVC"},
    {0x00000010, "RES_PRIMARY"},
    {0x00000020, "RES_IGNTC"},
    {0x00000040, "RES_RECURSE"},
    {0x00000080, "RES_DEFNAMES"},
    {0x00000100, "RES_STAYOPEN"},
    {0x00000200, "RES_DNSRCH"},
    {0x00001000, "RES_NOALIASES"},
    {0x00004000, "RES_ROTATE"},
    {0x00008000, "RES_NOCHECKNAME"},
    {0x00010000, "RES_KEEPTSIG"},
    {0x00020000, "RES_BLAST"},
    {0x00100000, "RES_USE_EDNS0"},
    {0x00200000, "RES_SNGLKUP"},
    {0x00400000, "RES_SNGLKUPREOP"},
    {0x00800000, "RES_USE_DNSSEC"},
    {0x01000000, "RES_NOTLDQUERY"},
    {0x02000000, "RES_NORELOAD"},
    {0x04000000, "RES_TRUSTAD"},
    {0x08000000, "RES_NOAAAA"},
    {0x10000000, "RES_STRICTERR"},
    {(0x00000040 | 0x00000080 | 0x00000200), "RES_DEFAULT"}
};

const defines_map resolv_pfcode = {
    {0x00000001, "RES_PRF_STATS"},
    {0x00000002, "RES_PRF_UPDATE"},
    {0x00000004, "RES_PRF_CLASS"},
    {0x00000008, "RES_PRF_CMD"},
    {0x00000010, "RES_PRF_QUES"},
    {0x00000020, "RES_PRF_ANS"},
    {0x00000040, "RES_PRF_AUTH"},
    {0x00000080, "RES_PRF_ADD"},
    {0x00000100, "RES_PRF_HEAD1"},
    {0x00000200, "RES_PRF_HEAD2"},
    {0x00000400, "RES_PRF_TTLID"},
    {0x00000800, "RES_PRF_HEADX"},
    {0x00001000, "RES_PRF_QUERY"},
    {0x00002000, "RES_PRF_REPLY"},
    {0x00004000, "RES_PRF_INIT"}
};

template <typename T>
std::string print_resolv_localdomainparts(const T v)
{
    return print_enum_entry(v, resolv_localdomainparts);
}

template <typename T>
std::string print_resolv_timeout(const T v)
{
    return print_enum_entry(v, resolv_timeout);
}

template <typename T>
std::string print_resolv_maxndots(const T v)
{
    return print_enum_entry(v, resolv_maxndots);
}

template <typename T>
std::string print_resolv_maxretrans(const T v)
{
    return print_enum_entry(v, resolv_maxretrans);
}

template <typename T>
std::string print_resolv_maxretry(const T v)
{
    return print_enum_entry(v, resolv_maxretry);
}

template <typename T>
std::string print_resolv_dflretry(const T v)
{
    return print_enum_entry(v, resolv_dflretry);
}

template <typename T>
std::string print_resolv_maxtime(const T v)
{
    return print_enum_entry(v, resolv_maxtime);
}

template <typename T>
std::string print_resolv_path_resconf(const T v)
{
    return print_enum_entry(v, resolv_path_resconf);
}

template <typename T>
std::string print_resolv_option(const T v)
{
    return print_or_enum_entries(v, resolv_option);
}

template <typename T>
std::string print_resolv_pfcode(const T v)
{
    return print_or_enum_entries(v, resolv_pfcode);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, res_sym>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.number, "number", &os));
    abii_args->push_arg(new ArgPrinter(obj.name, "name", &os));
    abii_args->push_arg(new ArgPrinter(obj.humanname, "humanname", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_RESOLV_H
