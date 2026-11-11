//
// Created by Trent Tanchin on 4/17/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_ARPA_NAMESER_COMPAT_H
#define ABII_C_LOGGING_PLUGIN_ARPA_NAMESER_COMPAT_H

#include <abii/libabii.h>

namespace abii
{
const defines_map arpa_nameser_compat_packetsz = {
    {512, "PACKETSZ"}
};

const defines_map arpa_nameser_compat_maxdname = {
    {1025, "MAXDNAME"}
};

const defines_map arpa_nameser_compat_maxcdname = {
    {255, "MAXCDNAME"}
};

const defines_map arpa_nameser_compat_maxlabel = {
    {63, "MAXLABEL"}
};

const defines_map arpa_nameser_compat_hfixedsz = {
    {12, "HFIXEDSZ"}
};

const defines_map arpa_nameser_compat_qfixedsz = {
    {4, "QFIXEDSZ"}
};

const defines_map arpa_nameser_compat_rrfixedsz = {
    {10, "RRFIXEDSZ"}
};

const defines_map arpa_nameser_compat_int32sz = {
    {4, "INT32SZ"}
};

const defines_map arpa_nameser_compat_int16sz = {
    {2, "INT16SZ"}
};

const defines_map arpa_nameser_compat_int8sz = {
    {1, "INT8SZ"}
};

const defines_map arpa_nameser_compat_inaddrsz = {
    {4, "INADDRSZ"}
};

const defines_map arpa_nameser_compat_in6addrsz = {
    {16, "IN6ADDRSZ"}
};

const defines_map arpa_nameser_compat_cmprsflgs = {
    {0xc0, "CMPRSFLGS"}
};

const defines_map arpa_nameser_compat_defaultport = {
    {53, "DEFAULTPORT"}
};

const defines_map nameser_compat_section = {
    {0, "S_ZONE"},
    {1, "S_PREREQ"},
    {2, "S_UPDATE"},
    {3, "S_ADDT"}
};

const defines_map nameser_compat_opcode = {
    {0, "QUERY"},
    {1, "IQUERY"},
    {2, "STATUS"},
    {4, "NS_NOTIFY_OP"},
    {5, "NS_UPDATE_OP"}
};

const defines_map nameser_compat_rcode = {
    {0, "NOERROR"},
    {1, "FORMERR"},
    {2, "SERVFAIL"},
    {3, "NXDOMAIN"},
    {4, "NOTIMP"},
    {5, "REFUSED"},
    {6, "YXDOMAIN"},
    {7, "YXRRSET"},
    {8, "NXRRSET"},
    {9, "NOTAUTH"},
    {10, "NOTZONE"}
};

const defines_map nameser_compat_update_operation = {
    {0, "DELETE"},
    {1, "ADD"}
};

const defines_map nameser_compat_type = {
    {1, "T_A"},
    {2, "T_NS"},
    {3, "T_MD"},
    {4, "T_MF"},
    {5, "T_CNAME"},
    {6, "T_SOA"},
    {7, "T_MB"},
    {8, "T_MG"},
    {9, "T_MR"},
    {10, "T_NULL"},
    {11, "T_WKS"},
    {12, "T_PTR"},
    {13, "T_HINFO"},
    {14, "T_MINFO"},
    {15, "T_MX"},
    {16, "T_TXT"},
    {17, "T_RP"},
    {18, "T_AFSDB"},
    {19, "T_X25"},
    {20, "T_ISDN"},
    {21, "T_RT"},
    {22, "T_NSAP"},
    {23, "T_NSAP_PTR"},
    {24, "T_SIG"},
    {25, "T_KEY"},
    {26, "T_PX"},
    {27, "T_GPOS"},
    {28, "T_AAAA"},
    {29, "T_LOC"},
    {30, "T_NXT"},
    {31, "T_EID"},
    {32, "T_NIMLOC"},
    {33, "T_SRV"},
    {34, "T_ATMA"},
    {35, "T_NAPTR"},
    {36, "T_KX"},
    {37, "T_CERT"},
    {38, "T_A6"},
    {39, "T_DNAME"},
    {40, "T_SINK"},
    {41, "T_OPT"},
    {42, "T_APL"},
    {43, "T_DS"},
    {44, "T_SSHFP"},
    {45, "T_IPSECKEY"},
    {46, "T_RRSIG"},
    {47, "T_NSEC"},
    {48, "T_DNSKEY"},
    {49, "T_DHCID"},
    {50, "T_NSEC3"},
    {51, "T_NSEC3PARAM"},
    {52, "T_TLSA"},
    {53, "T_SMIMEA"},
    {55, "T_HIP"},
    {56, "T_NINFO"},
    {57, "T_RKEY"},
    {58, "T_TALINK"},
    {59, "T_CDS"},
    {60, "T_CDNSKEY"},
    {61, "T_OPENPGPKEY"},
    {62, "T_CSYNC"},
    {99, "T_SPF"},
    {100, "T_UINFO"},
    {101, "T_UID"},
    {102, "T_GID"},
    {103, "T_UNSPEC"},
    {104, "T_NID"},
    {105, "T_L32"},
    {106, "T_L64"},
    {107, "T_LP"},
    {108, "T_EUI48"},
    {109, "T_EUI64"},
    {249, "T_TKEY"},
    {250, "T_TSIG"},
    {251, "T_IXFR"},
    {252, "T_AXFR"},
    {253, "T_MAILB"},
    {254, "T_MAILA"},
    {255, "T_ANY"},
    {256, "T_URI"},
    {257, "T_CAA"},
    {258, "T_AVC"},
    {32768, "T_TA"},
    {32769, "T_DLV"}
};

const defines_map nameser_compat_class = {
    {1, "C_IN"},
    {3, "C_CHAOS"},
    {4, "C_HS"},
    {254, "C_NONE"},
    {255, "C_ANY"}
};

template <typename T>
std::string print_arpa_nameser_compat_packetsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_packetsz);
}

template <typename T>
std::string print_arpa_nameser_compat_maxdname(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_maxdname);
}

template <typename T>
std::string print_arpa_nameser_compat_maxcdname(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_maxcdname);
}

template <typename T>
std::string print_arpa_nameser_compat_maxlabel(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_maxlabel);
}

template <typename T>
std::string print_arpa_nameser_compat_hfixedsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_hfixedsz);
}

template <typename T>
std::string print_arpa_nameser_compat_qfixedsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_qfixedsz);
}

template <typename T>
std::string print_arpa_nameser_compat_rrfixedsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_rrfixedsz);
}

template <typename T>
std::string print_arpa_nameser_compat_int32sz(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_int32sz);
}

template <typename T>
std::string print_arpa_nameser_compat_int16sz(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_int16sz);
}

template <typename T>
std::string print_arpa_nameser_compat_int8sz(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_int8sz);
}

template <typename T>
std::string print_arpa_nameser_compat_inaddrsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_inaddrsz);
}

template <typename T>
std::string print_arpa_nameser_compat_in6addrsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_in6addrsz);
}

template <typename T>
std::string print_arpa_nameser_compat_cmprsflgs(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_cmprsflgs);
}

template <typename T>
std::string print_arpa_nameser_compat_defaultport(const T v)
{
    return print_enum_entry(v, arpa_nameser_compat_defaultport);
}

template <typename T>
std::string print_nameser_compat_section(const T v)
{
    return print_enum_entry(v, nameser_compat_section);
}

template <typename T>
std::string print_nameser_compat_opcode(const T v)
{
    return print_enum_entry(v, nameser_compat_opcode);
}

template <typename T>
std::string print_nameser_compat_rcode(const T v)
{
    return print_enum_entry(v, nameser_compat_rcode);
}

template <typename T>
std::string print_nameser_compat_update_operation(const T v)
{
    return print_enum_entry(v, nameser_compat_update_operation);
}

template <typename T>
std::string print_nameser_compat_type(const T v)
{
    return print_enum_entry(v, nameser_compat_type);
}

template <typename T>
std::string print_nameser_compat_class(const T v)
{
    return print_enum_entry(v, nameser_compat_class);
}
}

#include "utils/custom_enum_printers/nameser.h"

using namespace abii;

template <typename T>
std::string print_nameser_opcode(T v);

template <typename T>
std::string print_nameser_rcode(T v);

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, HEADER>
std::ostream& operator<<(std::ostream& os, HEADER&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::id)>(obj.id), "id", &os));
#if __BYTE_ORDER == __BIG_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::qr)>(obj.qr), "qr", &os));

    auto printer = new ArgPrinter(static_cast<decltype(HEADER::opcode)>(obj.opcode), "opcode", &os);
    printer->set_enum_printer(print_nameser_opcode, obj.opcode);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::aa)>(obj.aa), "aa", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::tc)>(obj.tc), "tc", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::rd)>(obj.rd), "rd", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::ra)>(obj.ra), "ra", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::unused)>(obj.unused), "unused", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::ad)>(obj.ad), "ad", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::cd)>(obj.cd), "cd", &os));

    auto printer1 = new ArgPrinter(static_cast<decltype(HEADER::rcode)>(obj.rcode), "rcode", &os);
    printer1->set_enum_printer(print_nameser_rcode, obj.rcode);
    abii_args->push_arg(printer1);
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN || __BYTE_ORDER == __PDP_ENDIAN
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::rd)>(obj.rd), "rd", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::tc)>(obj.tc), "tc", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::aa)>(obj.aa), "aa", &os));

    auto printer = new ArgPrinter(static_cast<decltype(HEADER::opcode)>(obj.opcode), "opcode", &os);
    printer->set_enum_printer(print_nameser_opcode, obj.opcode);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::qr)>(obj.qr), "qr", &os));

    auto printer1 = new ArgPrinter(static_cast<decltype(HEADER::rcode)>(obj.rcode), "rcode", &os);
    printer1->set_enum_printer(print_nameser_rcode, obj.rcode);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::cd)>(obj.cd), "cd", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::ad)>(obj.ad), "ad", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::unused)>(obj.unused), "unused", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::ra)>(obj.ra), "ra", &os));
#endif
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::qdcount)>(obj.qdcount), "qdcount", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::ancount)>(obj.ancount), "ancount", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::nscount)>(obj.nscount), "nscount", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<decltype(HEADER::arcount)>(obj.arcount), "arcount", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_ARPA_NAMESER_COMPAT_H
