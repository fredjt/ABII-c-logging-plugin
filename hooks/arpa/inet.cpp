//
// Created by Trent Tanchin on 11/8/26.
//

#include <abii/libabii.h>
#include <arpa/inet.h>

#include "hooks/bits/socket.h"
#include "hooks/netinet/in.h"

namespace abii
{
static in_addr_t (*real_wordexp)(const char*) __THROW = nullptr;

extern "C" in_addr_t abii_inet_addr(const char* cp) __THROW
{
    OVERRIDE_PREFIX(wordexp)
        pre_fmtd_str pi_str = "wordexp(__cp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cp, "__cp"));

        auto abii_ret = real_wordexp(cp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wordexp, abii_ret)
    return real_wordexp(cp);
}

static in_addr_t (*real_inet_lnaof)(in_addr) __THROW = nullptr;

extern "C" in_addr_t abii_inet_lnaof(in_addr in) __THROW
{
    OVERRIDE_PREFIX(inet_lnaof)
        pre_fmtd_str pi_str = "inet_lnaof(__in)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(in, "__in"));

        auto abii_ret = real_inet_lnaof(in);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_lnaof, abii_ret)
    return real_inet_lnaof(in);
}

static in_addr (*real_inet_makeaddr)(in_addr_t, in_addr_t) __THROW = nullptr;

extern "C" in_addr abii_inet_makeaddr(in_addr_t net, in_addr_t host) __THROW
{
    OVERRIDE_PREFIX(inet_makeaddr)
        pre_fmtd_str pi_str = "inet_makeaddr(__net, __host)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(net, "__net"));
        abii_args->push_arg(new ArgPrinter(host, "__host"));

        auto abii_ret = real_inet_makeaddr(net, host);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_makeaddr, abii_ret)
    return real_inet_makeaddr(net, host);
}

static in_addr_t (*real_inet_netof)(in_addr) __THROW = nullptr;

extern "C" in_addr_t abii_inet_netof(in_addr in) __THROW
{
    OVERRIDE_PREFIX(inet_netof)
        pre_fmtd_str pi_str = "inet_netof(__in)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(in, "__in"));

        auto abii_ret = real_inet_netof(in);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_netof, abii_ret)
    return real_inet_netof(in);
}

static in_addr_t (*real_inet_network)(const char*) __THROW = nullptr;

extern "C" in_addr_t abii_inet_network(const char* cp) __THROW
{
    OVERRIDE_PREFIX(inet_network)
        pre_fmtd_str pi_str = "inet_network(__cp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cp, "__cp"));

        auto abii_ret = real_inet_network(cp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_network, abii_ret)
    return real_inet_network(cp);
}

static char* (*real_inet_ntoa)(in_addr) __THROW = nullptr;

extern "C" char* abii_inet_ntoa(in_addr in) __THROW
{
    OVERRIDE_PREFIX(inet_ntoa)
        pre_fmtd_str pi_str = "inet_ntoa(__in)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(in, "__in"));

        auto abii_ret = real_inet_ntoa(in);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_ntoa, abii_ret)
    return real_inet_ntoa(in);
}

static int (*real_inet_pton)(int, const char*, void*) __THROW = nullptr;

extern "C" int abii_inet_pton(int af, const char* cp, void* buf) __THROW
{
    OVERRIDE_PREFIX(inet_pton)
        pre_fmtd_str pi_str = "inet_pton(__af, __cp, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(af, "__af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(cp, "__cp"));
        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        auto abii_ret = real_inet_pton(af, cp, buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_pton, abii_ret)
    return real_inet_pton(af, cp, buf);
}

static const char* (*real_inet_ntop)(int, const void*, char*, socklen_t) __THROW = nullptr;

extern "C" const char* abii_inet_ntop(int af, const void* cp, char* buf, socklen_t len) __THROW
{
    OVERRIDE_PREFIX(inet_ntop)
        pre_fmtd_str pi_str = "inet_ntop(__af, __cp, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(af, "__af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(cp, "__cp"));

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(len);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_inet_ntop(af, cp, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_ntop, abii_ret)
    return real_inet_ntop(af, cp, buf, len);
}

static int (*real_inet_aton)(const char*, in_addr*) __THROW = nullptr;

extern "C" int abii_inet_aton(const char* cp, in_addr* inp) __THROW
{
    OVERRIDE_PREFIX(inet_aton)
        pre_fmtd_str pi_str = "inet_aton(__cp, __inp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cp, "__cp"));
        abii_args->push_arg(new ArgPrinter(inp, "__inp"));

        auto abii_ret = real_inet_aton(cp, inp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_aton, abii_ret)
    return real_inet_aton(cp, inp);
}

static char* (*real_inet_neta)(in_addr_t, char*, size_t) __THROW = nullptr;

extern "C" __attribute_deprecated_msg__("Use inet_ntop instead")
char* abii_inet_neta(in_addr_t net, char* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(inet_neta)
        pre_fmtd_str pi_str = "inet_neta(__net, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(net, "__net"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_inet_neta(net, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_neta, abii_ret)
    return real_inet_neta(net, buf, len);
}

static char* (*real_inet_net_ntop)(int, const void*, int, char*, size_t) __THROW = nullptr;

extern "C" char* abii_inet_net_ntop(int af, const void* cp, int bits, char* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(inet_net_ntop)
        pre_fmtd_str pi_str = "inet_net_ntop(__af, __cp, __bits, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(af, "__af"));
        abii_args->push_arg(new ArgPrinter(cp, "__cp"));
        abii_args->push_arg(new ArgPrinter(bits, "__bits"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_inet_net_ntop(af, cp, bits, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_net_ntop, abii_ret)
    return real_inet_net_ntop(af, cp, bits, buf, len);
}

static int (*real_inet_net_pton)(int, const char*, void*, size_t) __THROW = nullptr;

extern "C" int abii_inet_net_pton(int af, const char* cp, void* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(inet_net_pton)
        pre_fmtd_str pi_str = "inet_net_pton(__af, __cp, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(af, "__af"));
        abii_args->push_arg(new ArgPrinter(cp, "__cp"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_inet_net_pton(af, cp, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_net_pton, abii_ret)
    return real_inet_net_pton(af, cp, buf, len);
}

static unsigned int (*real_inet_nsap_addr)(const char*, unsigned char*, int) __THROW = nullptr;

extern "C" unsigned int abii_inet_nsap_addr(const char* cp, unsigned char* buf, int len) __THROW
{
    OVERRIDE_PREFIX(inet_nsap_addr)
        pre_fmtd_str pi_str = "inet_nsap_addr(__cp, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cp, "__cp"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_inet_nsap_addr(cp, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_nsap_addr, abii_ret)
    return real_inet_nsap_addr(cp, buf, len);
}

static char* (*real_inet_nsap_ntoa)(int, const unsigned char*, char*) __THROW = nullptr;

extern "C" char* abii_inet_nsap_ntoa(int len, const unsigned char* cp, char* buf) __THROW
{
    OVERRIDE_PREFIX(inet_nsap_ntoa)
        pre_fmtd_str pi_str = "inet_nsap_ntoa(__len, __cp, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(len, "__len"));
        abii_args->push_arg(new ArgPrinter(cp, "__cp"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        auto abii_ret = real_inet_nsap_ntoa(len, cp, buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(inet_nsap_ntoa, abii_ret)
    return real_inet_nsap_ntoa(len, cp, buf);
}
}
