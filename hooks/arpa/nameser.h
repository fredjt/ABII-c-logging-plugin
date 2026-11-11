//
// Created by Trent Tanchin on 11/8/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_NAMESER_H
#define ABII_C_LOGGING_PLUGIN_NAMESER_H

#include <abii/libabii.h>
#include <arpa/nameser.h>

namespace abii
{
const defines_map arpa_nameser_ns_packetsz = {
    {512, "NS_PACKETSZ"}
};

const defines_map arpa_nameser_ns_maxdname = {
    {1025, "NS_MAXDNAME"}
};

const defines_map arpa_nameser_ns_maxmsg = {
    {65535, "NS_MAXMSG"}
};

const defines_map arpa_nameser_ns_maxcdname = {
    {255, "NS_MAXCDNAME"}
};

const defines_map arpa_nameser_ns_maxlabel = {
    {63, "NS_MAXLABEL"}
};

const defines_map arpa_nameser_ns_hfixedsz = {
    {12, "NS_HFIXEDSZ"}
};

const defines_map arpa_nameser_ns_qfixedsz = {
    {4, "NS_QFIXEDSZ"}
};

const defines_map arpa_nameser_ns_rrfixedsz = {
    {10, "NS_RRFIXEDSZ"}
};

const defines_map arpa_nameser_ns_int32sz = {
    {4, "NS_INT32SZ"}
};

const defines_map arpa_nameser_ns_int16sz = {
    {2, "NS_INT16SZ"}
};

const defines_map arpa_nameser_ns_int8sz = {
    {1, "NS_INT8SZ"}
};

const defines_map arpa_nameser_ns_inaddrsz = {
    {4, "NS_INADDRSZ"}
};

const defines_map arpa_nameser_ns_in6addrsz = {
    {16, "NS_IN6ADDRSZ"}
};

const defines_map arpa_nameser_ns_cmprsflgs = {
    {0xc0, "NS_CMPRSFLGS"}
};

const defines_map arpa_nameser_ns_defaultport = {
    {53, "NS_DEFAULTPORT"}
};

const defines_map arpa_nameser___ns_sect = {
    {0, "__ns_sect::ns_s_qd"},
    {0, "__ns_sect::ns_s_zn"},
    {1, "__ns_sect::ns_s_an"},
    {1, "__ns_sect::ns_s_pr"},
    {2, "__ns_sect::ns_s_ns"},
    {2, "__ns_sect::ns_s_ud"},
    {3, "__ns_sect::ns_s_ar"},
    {4, "__ns_sect::ns_s_max"}
};

const defines_map arpa_nameser___ns_flag = {
    {0, "__ns_flag::ns_f_qr"},
    {1, "__ns_flag::ns_f_opcode"},
    {2, "__ns_flag::ns_f_aa"},
    {3, "__ns_flag::ns_f_tc"},
    {4, "__ns_flag::ns_f_rd"},
    {5, "__ns_flag::ns_f_ra"},
    {6, "__ns_flag::ns_f_z"},
    {7, "__ns_flag::ns_f_ad"},
    {8, "__ns_flag::ns_f_cd"},
    {9, "__ns_flag::ns_f_rcode"},
    {10, "__ns_flag::ns_f_max"}
};

const defines_map arpa_nameser___ns_opcode = {
    {0, "__ns_opcode::ns_o_query"},
    {1, "__ns_opcode::ns_o_iquery"},
    {2, "__ns_opcode::ns_o_status"},
    {4, "__ns_opcode::ns_o_notify"},
    {5, "__ns_opcode::ns_o_update"},
    {6, "__ns_opcode::ns_o_max"}
};

const defines_map arpa_nameser___ns_rcode = {
    {0, "__ns_rcode::ns_r_noerror"},
    {1, "__ns_rcode::ns_r_formerr"},
    {2, "__ns_rcode::ns_r_servfail"},
    {3, "__ns_rcode::ns_r_nxdomain"},
    {4, "__ns_rcode::ns_r_notimpl"},
    {5, "__ns_rcode::ns_r_refused"},
    {6, "__ns_rcode::ns_r_yxdomain"},
    {7, "__ns_rcode::ns_r_yxrrset"},
    {8, "__ns_rcode::ns_r_nxrrset"},
    {9, "__ns_rcode::ns_r_notauth"},
    {10, "__ns_rcode::ns_r_notzone"},
    {11, "__ns_rcode::ns_r_max"},
    {16, "__ns_rcode::ns_r_badvers"},
    {16, "__ns_rcode::ns_r_badsig"},
    {17, "__ns_rcode::ns_r_badkey"},
    {18, "__ns_rcode::ns_r_badtime"}
};

const defines_map arpa_nameser___ns_update_operation = {
    {0, "__ns_update_operation::ns_uop_delete"},
    {1, "__ns_update_operation::ns_uop_add"},
    {2, "__ns_update_operation::ns_uop_max"}
};

const defines_map arpa_nameser_ns_tsig_fudge = {
    {300, "NS_TSIG_FUDGE"}
};

const defines_map arpa_nameser_ns_tsig_tcp_count = {
    {100, "NS_TSIG_TCP_COUNT"}
};

const defines_map<const char*> arpa_nameser_ns_tsig_alg_hmac_md5 = {
    {"HMAC-MD5.SIG-ALG.REG.INT", "NS_TSIG_ALG_HMAC_MD5"}
};

const defines_map arpa_nameser_ns_tsig_error = {
    {-10, "NS_TSIG_ERROR_NO_TSIG"},
    {-11, "NS_TSIG_ERROR_NO_SPACE"},
    {-12, "NS_TSIG_ERROR_FORMERR"}
};

const defines_map arpa_nameser___ns_type = {
    {0, "__ns_type::ns_t_invalid"},
    {1, "__ns_type::ns_t_a"},
    {2, "__ns_type::ns_t_ns"},
    {3, "__ns_type::ns_t_md"},
    {4, "__ns_type::ns_t_mf"},
    {5, "__ns_type::ns_t_cname"},
    {6, "__ns_type::ns_t_soa"},
    {7, "__ns_type::ns_t_mb"},
    {8, "__ns_type::ns_t_mg"},
    {9, "__ns_type::ns_t_mr"},
    {10, "__ns_type::ns_t_null"},
    {11, "__ns_type::ns_t_wks"},
    {12, "__ns_type::ns_t_ptr"},
    {13, "__ns_type::ns_t_hinfo"},
    {14, "__ns_type::ns_t_minfo"},
    {15, "__ns_type::ns_t_mx"},
    {16, "__ns_type::ns_t_txt"},
    {17, "__ns_type::ns_t_rp"},
    {18, "__ns_type::ns_t_afsdb"},
    {19, "__ns_type::ns_t_x25"},
    {20, "__ns_type::ns_t_isdn"},
    {21, "__ns_type::ns_t_rt"},
    {22, "__ns_type::ns_t_nsap"},
    {23, "__ns_type::ns_t_nsap_ptr"},
    {24, "__ns_type::ns_t_sig"},
    {25, "__ns_type::ns_t_key"},
    {26, "__ns_type::ns_t_px"},
    {27, "__ns_type::ns_t_gpos"},
    {28, "__ns_type::ns_t_aaaa"},
    {29, "__ns_type::ns_t_loc"},
    {30, "__ns_type::ns_t_nxt"},
    {31, "__ns_type::ns_t_eid"},
    {32, "__ns_type::ns_t_nimloc"},
    {33, "__ns_type::ns_t_srv"},
    {34, "__ns_type::ns_t_atma"},
    {35, "__ns_type::ns_t_naptr"},
    {36, "__ns_type::ns_t_kx"},
    {37, "__ns_type::ns_t_cert"},
    {38, "__ns_type::ns_t_a6"},
    {39, "__ns_type::ns_t_dname"},
    {40, "__ns_type::ns_t_sink"},
    {41, "__ns_type::ns_t_opt"},
    {42, "__ns_type::ns_t_apl"},
    {43, "__ns_type::ns_t_ds"},
    {44, "__ns_type::ns_t_sshfp"},
    {45, "__ns_type::ns_t_ipseckey"},
    {46, "__ns_type::ns_t_rrsig"},
    {47, "__ns_type::ns_t_nsec"},
    {48, "__ns_type::ns_t_dnskey"},
    {49, "__ns_type::ns_t_dhcid"},
    {50, "__ns_type::ns_t_nsec3"},
    {51, "__ns_type::ns_t_nsec3param"},
    {52, "__ns_type::ns_t_tlsa"},
    {53, "__ns_type::ns_t_smimea"},
    {55, "__ns_type::ns_t_hip"},
    {56, "__ns_type::ns_t_ninfo"},
    {57, "__ns_type::ns_t_rkey"},
    {58, "__ns_type::ns_t_talink"},
    {59, "__ns_type::ns_t_cds"},
    {60, "__ns_type::ns_t_cdnskey"},
    {61, "__ns_type::ns_t_openpgpkey"},
    {62, "__ns_type::ns_t_csync"},
    {99, "__ns_type::ns_t_spf"},
    {100, "__ns_type::ns_t_uinfo"},
    {101, "__ns_type::ns_t_uid"},
    {102, "__ns_type::ns_t_gid"},
    {103, "__ns_type::ns_t_unspec"},
    {104, "__ns_type::ns_t_nid"},
    {105, "__ns_type::ns_t_l32"},
    {106, "__ns_type::ns_t_l64"},
    {107, "__ns_type::ns_t_lp"},
    {108, "__ns_type::ns_t_eui48"},
    {109, "__ns_type::ns_t_eui64"},
    {249, "__ns_type::ns_t_tkey"},
    {250, "__ns_type::ns_t_tsig"},
    {251, "__ns_type::ns_t_ixfr"},
    {252, "__ns_type::ns_t_axfr"},
    {253, "__ns_type::ns_t_mailb"},
    {254, "__ns_type::ns_t_maila"},
    {255, "__ns_type::ns_t_any"},
    {256, "__ns_type::ns_t_uri"},
    {257, "__ns_type::ns_t_caa"},
    {258, "__ns_type::ns_t_avc"},
    {32768, "__ns_type::ns_t_ta"},
    {32769, "__ns_type::ns_t_dlv"},
    {65536, "__ns_type::ns_t_max"}
};

const defines_map arpa_nameser___ns_class = {
    {0, "__ns_class::ns_c_invalid"},
    {1, "__ns_class::ns_c_in"},
    {2, "__ns_class::ns_c_2"},
    {3, "__ns_class::ns_c_chaos"},
    {4, "__ns_class::ns_c_hs"},
    {254, "__ns_class::ns_c_none"},
    {255, "__ns_class::ns_c_any"},
    {65536, "__ns_class::ns_c_max"}
};

const defines_map arpa_nameser___ns_cert_types = {
    {1, "__ns_cert_types::cert_t_pkix"},
    {2, "__ns_cert_types::cert_t_spki"},
    {3, "__ns_cert_types::cert_t_pgp"},
    {253, "__ns_cert_types::cert_t_url"},
    {254, "__ns_cert_types::cert_t_oid"}
};

const defines_map arpa_nameser_ns_opt_dnssec_ok = {
    {0x8000U, "NS_OPT_DNSSEC_OK"}
};

const defines_map arpa_nameser_ns_opt_nsid = {
    {3, "NS_OPT_NSID"}
};

template <typename T>
std::string print_arpa_nameser_ns_packetsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_packetsz);
}

template <typename T>
std::string print_arpa_nameser_ns_maxdname(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_maxdname);
}

template <typename T>
std::string print_arpa_nameser_ns_maxmsg(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_maxmsg);
}

template <typename T>
std::string print_arpa_nameser_ns_maxcdname(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_maxcdname);
}

template <typename T>
std::string print_arpa_nameser_ns_maxlabel(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_maxlabel);
}

template <typename T>
std::string print_arpa_nameser_ns_hfixedsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_hfixedsz);
}

template <typename T>
std::string print_arpa_nameser_ns_qfixedsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_qfixedsz);
}

template <typename T>
std::string print_arpa_nameser_ns_rrfixedsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_rrfixedsz);
}

template <typename T>
std::string print_arpa_nameser_ns_int32sz(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_int32sz);
}

template <typename T>
std::string print_arpa_nameser_ns_int16sz(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_int16sz);
}

template <typename T>
std::string print_arpa_nameser_ns_int8sz(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_int8sz);
}

template <typename T>
std::string print_arpa_nameser_ns_inaddrsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_inaddrsz);
}

template <typename T>
std::string print_arpa_nameser_ns_in6addrsz(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_in6addrsz);
}

template <typename T>
std::string print_arpa_nameser_ns_cmprsflgs(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_cmprsflgs);
}

template <typename T>
std::string print_arpa_nameser_ns_defaultport(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_defaultport);
}

template <typename T>
std::string print_arpa_nameser___ns_sect(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_sect);
}

template <typename T>
std::string print_arpa_nameser___ns_flag(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_flag);
}

template <typename T>
std::string print_arpa_nameser___ns_opcode(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_opcode);
}

template <typename T>
std::string print_arpa_nameser___ns_rcode(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_rcode);
}

template <typename T>
std::string print_arpa_nameser___ns_update_operation(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_update_operation);
}

template <typename T>
std::string print_arpa_nameser_ns_tsig_fudge(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_tsig_fudge);
}

template <typename T>
std::string print_arpa_nameser_ns_tsig_tcp_count(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_tsig_tcp_count);
}

template <typename T>
std::string print_arpa_nameser_ns_tsig_alg_hmac_md5(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_tsig_alg_hmac_md5);
}

template <typename T>
std::string print_arpa_nameser_ns_tsig_error(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_tsig_error);
}

template <typename T>
std::string print_arpa_nameser___ns_type(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_type);
}

template <typename T>
std::string print_arpa_nameser___ns_class(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_class);
}

template <typename T>
std::string print_arpa_nameser___ns_cert_types(const T v)
{
    return print_enum_entry(v, arpa_nameser___ns_cert_types);
}

template <typename T>
std::string print_arpa_nameser_ns_opt_dnssec_ok(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_opt_dnssec_ok);
}

template <typename T>
std::string print_arpa_nameser_ns_opt_nsid(const T v)
{
    return print_enum_entry(v, arpa_nameser_ns_opt_nsid);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __ns_msg>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    const auto size = ns_msg_size(obj);
    auto printer = new ArgPrinter(obj._msg, "_msg", &os);
    printer->set_len(size);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj._eom, "_eom", &os));
    abii_args->push_arg(new ArgPrinter(obj._id, "_id", &os));
    abii_args->push_arg(new ArgPrinter(obj._flags, "_flags", &os));
    abii_args->push_arg(new ArgPrinter(obj._counts, "_counts", &os));
    abii_args->push_arg(new ArgPrinter(obj._sections, "_sections", &os));
    abii_args->push_arg(new ArgPrinter(obj._sect, "_sect", &os));
    abii_args->push_arg(new ArgPrinter(obj._rrnum, "_rrnum", &os));
    abii_args->push_arg(new ArgPrinter(obj._msg_ptr, "_msg_ptr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, struct _ns_flagdata>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.mask, "mask", &os));
    abii_args->push_arg(new ArgPrinter(obj.shift, "shift", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __ns_rr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.name, "name", &os));

    auto printer = new ArgPrinter(obj.type, "type", &os);
    printer->set_enum_printer(print_arpa_nameser___ns_type, obj.type);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.rr_class, "rr_class", &os);
    printer1->set_enum_printer(print_arpa_nameser___ns_class, obj.rr_class);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.ttl, "ttl", &os));
    abii_args->push_arg(new ArgPrinter(obj.rdlength, "rdlength", &os));

    auto printer2 = new ArgPrinter(obj.rdata, "rdata", &os, RECURSE);
    printer2->set_len(obj.rdlength);
    abii_args->push_arg(printer2);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ns_tsig_key>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.name, "name", &os));

    auto printer = new ArgPrinter(obj.alg, "alg", &os);
    printer->set_enum_printer(print_arpa_nameser_ns_tsig_alg_hmac_md5, obj.alg);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.data, "data", &os);
    printer1->set_len(obj.len);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.len, "len", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ns_tcp_tsig_state>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.counter, "counter", &os));
    abii_args->push_arg(new ArgPrinter(obj.key, "key", &os));
    abii_args->push_arg(new ArgPrinter(obj.ctx, "ctx", &os));
    abii_args->push_arg(new ArgPrinter(obj.sig, "sig", &os));
    abii_args->push_arg(new ArgPrinter(obj.siglen, "siglen", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_NAMESER_H
