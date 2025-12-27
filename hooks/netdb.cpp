//
// Created by Trent Tanchin on 10/9/24.
//

#include "netdb.h"
#include "bits/netdb.h"

#include "bits/types/sigevent_t.h"
#include "bits/types/struct_timespec.h"

namespace abii
{
static int* (*real___h_errno_location)() __THROW = nullptr;

extern "C" __attribute__ ((__const__))
int* abii___h_errno_location() __THROW
{
    OVERRIDE_PREFIX(__h_errno_location)
        pre_fmtd_str str = "__h_errno_location()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real___h_errno_location();

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer_with_depth(print_netdb_h_errno, *abii_ret, 1);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(__h_errno_location, abii_ret)
    return real___h_errno_location();
}

static void (*real_herror)(const char*) __THROW = nullptr;

extern "C" void abii_herror(const char* str) __THROW
{
    OVERRIDE_PREFIX(herror)
        pre_fmtd_str pi_str = "herror(__str)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(str, "__str"));

        real_herror(str);
    OVERRIDE_SUFFIX(herror,)
    return real_herror(str);
}

static const char* (*real_hstrerror)(int) __THROW = nullptr;

extern "C" const char* abii_hstrerror(int err_num) __THROW
{
    OVERRIDE_PREFIX(hstrerror)
        pre_fmtd_str pi_str = "hstrerror(__err_num)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(err_num, "__err_num");
        printer->set_enum_printer(print_netdb_h_errno, err_num);
        abii_args->push_arg(printer);

        auto abii_ret = real_hstrerror(err_num);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(hstrerror, abii_ret)
    return real_hstrerror(err_num);
}

static void (*real_sethostent)(int) = nullptr;

extern "C" void abii_sethostent(int stay_open)
{
    OVERRIDE_PREFIX(sethostent)
        pre_fmtd_str pi_str = "sethostent(__stay_open)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stay_open, "__stay_open"));

        real_sethostent(stay_open);
    OVERRIDE_SUFFIX(sethostent,)
    return real_sethostent(stay_open);
}

static void (*real_endhostent)() = nullptr;

extern "C" void abii_endhostent()
{
    OVERRIDE_PREFIX(endhostent)
        pre_fmtd_str pi_str = "endhostent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endhostent();
    OVERRIDE_SUFFIX(endhostent,)
    return real_endhostent();
}

static hostent* (*real_gethostent)() = nullptr;

extern "C" hostent* abii_gethostent()
{
    OVERRIDE_PREFIX(gethostent)
        pre_fmtd_str pi_str = "gethostent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_gethostent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostent, abii_ret)
    return real_gethostent();
}

static hostent* (*real_gethostbyaddr)(const void*, __socklen_t, int) = nullptr;

extern "C" hostent* abii_gethostbyaddr(const void* addr, __socklen_t len, int type)
{
    OVERRIDE_PREFIX(gethostbyaddr)
        pre_fmtd_str pi_str = "gethostbyaddr(__addr, __len, __type)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(addr, "__addr"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));
        abii_args->push_arg(new ArgPrinter(type, "__type"));

        auto abii_ret = real_gethostbyaddr(addr, len, type);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostbyaddr, abii_ret)
    return real_gethostbyaddr(addr, len, type);
}

static hostent* (*real_gethostbyname)(const char*) = nullptr;

extern "C" hostent* abii_gethostbyname(const char* name)
{
    OVERRIDE_PREFIX(gethostbyname)
        pre_fmtd_str pi_str = "gethostbyname(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_gethostbyname(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostbyname, abii_ret)
    return real_gethostbyname(name);
}

static hostent* (*real_gethostbyname2)(const char*, int) = nullptr;

extern "C" hostent* abii_gethostbyname2(const char* name, int af)
{
    OVERRIDE_PREFIX(gethostbyname2)
        pre_fmtd_str pi_str = "gethostbyname2(__name, __af)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(af, "__af"));

        auto abii_ret = real_gethostbyname2(name, af);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostbyname2, abii_ret)
    return real_gethostbyname2(name, af);
}

static int (*real_gethostent_r)(hostent*, char*, size_t, hostent**, int*) = nullptr;

extern "C" int abii_gethostent_r(hostent* result_buf, char* buf, size_t buflen, hostent** result, int* h_errnop)
{
    OVERRIDE_PREFIX(gethostent_r)
        pre_fmtd_str pi_str = "gethostent_r(__result_buf, __buf, __buflen, __result, __h_errnop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto printer1 = new ArgPrinter(h_errnop, "__h_errnop");
        printer1->set_enum_printer_with_depth(print_netdb_h_errno, *h_errnop, 1);
        abii_args->push_arg(printer1);

        auto abii_ret = real_gethostent_r(result_buf, buf, buflen, result, h_errnop);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostent_r, abii_ret)
    return real_gethostent_r(result_buf, buf, buflen, result, h_errnop);
}

static int (*real_gethostbyaddr_r)(const void*, __socklen_t, int, hostent*, char*, size_t, hostent**, int*) = nullptr;

extern "C" int abii_gethostbyaddr_r(const void* addr, __socklen_t len, int type, hostent* result_buf, char* buf,
                                    size_t buflen, hostent** result, int* h_errnop)
{
    OVERRIDE_PREFIX(gethostbyaddr_r)
        pre_fmtd_str pi_str =
            "gethostbyaddr_r(__addr, __len, __type, __result_buf, __buf, __buflen, __result, __h_errnop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(addr, "__addr");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto printer1 = new ArgPrinter(type, "__type");
        printer1->set_enum_printer(print_socket_addr_family, type);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer2 = new ArgPrinter(buf, "__buf");
        printer2->set_len(buflen);
        abii_args->push_arg(printer2);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto printer3 = new ArgPrinter(h_errnop, "__h_errnop");
        printer3->set_enum_printer_with_depth(print_netdb_h_errno, *h_errnop, 1);
        abii_args->push_arg(printer3);

        auto abii_ret = real_gethostbyaddr_r(addr, len, type, result_buf, buf, buflen, result, h_errnop);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostbyaddr_r, abii_ret)
    return real_gethostbyaddr_r(addr, len, type, result_buf, buf, buflen, result, h_errnop);
}

static int (*real_gethostbyname_r)(const char*, hostent*, char*, size_t, hostent**, int*) = nullptr;

extern "C" int abii_gethostbyname_r(const char* name, hostent* result_buf, char* buf, size_t buflen, hostent** result,
                                    int* h_errnop)
{
    OVERRIDE_PREFIX(gethostbyname_r)
        pre_fmtd_str pi_str = "gethostbyname_r(__name, __result_buf, __buf, __buflen, __result, __h_errnop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto printer1 = new ArgPrinter(h_errnop, "__h_errnop");
        printer1->set_enum_printer_with_depth(print_netdb_h_errno, *h_errnop, 1);
        abii_args->push_arg(printer1);

        auto abii_ret = real_gethostbyname_r(name, result_buf, buf, buflen, result, h_errnop);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostbyname_r, abii_ret)
    return real_gethostbyname_r(name, result_buf, buf, buflen, result, h_errnop);
}

static int (*real_gethostbyname2_r)(const char*, int, hostent*, char*, size_t, hostent**, int*) = nullptr;

extern "C" int abii_gethostbyname2_r(const char* name, int af, hostent* result_buf, char* buf, size_t buflen,
                                     hostent** result, int* h_errnop)
{
    OVERRIDE_PREFIX(gethostbyname2_r)
        pre_fmtd_str pi_str = "gethostbyname2_r(__name, __af, __result_buf, __buf, __buflen, __result, __h_errnop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto printer = new ArgPrinter(af, "__af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto printer2 = new ArgPrinter(h_errnop, "__h_errnop");
        printer2->set_enum_printer_with_depth(print_netdb_h_errno, *h_errnop, 1);
        abii_args->push_arg(printer2);

        auto abii_ret = real_gethostbyname2_r(name, af, result_buf, buf, buflen, result, h_errnop);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostbyname2_r, abii_ret)
    return real_gethostbyname2_r(name, af, result_buf, buf, buflen, result, h_errnop);
}

static void (*real_setnetent)(int) = nullptr;

extern "C" void abii_setnetent(int stay_open)
{
    OVERRIDE_PREFIX(setnetent)
        pre_fmtd_str pi_str = "setnetent(__stay_open)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stay_open, "__stay_open"));

        real_setnetent(stay_open);
    OVERRIDE_SUFFIX(setnetent,)
    return real_setnetent(stay_open);
}

static void (*real_endnetent)() = nullptr;

extern "C" void abii_endnetent()
{
    OVERRIDE_PREFIX(endnetent)
        pre_fmtd_str pi_str = "endnetent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endnetent();
    OVERRIDE_SUFFIX(endnetent,)
    return real_endnetent();
}

static netent* (*real_getnetent)() = nullptr;

extern "C" netent* abii_getnetent()
{
    OVERRIDE_PREFIX(getnetent)
        pre_fmtd_str pi_str = "getnetent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getnetent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getnetent, abii_ret)
    return real_getnetent();
}

static netent* (*real_getnetbyaddr)(uint32_t, int) = nullptr;

extern "C" netent* abii_getnetbyaddr(uint32_t net, int type)
{
    OVERRIDE_PREFIX(getnetbyaddr)
        pre_fmtd_str pi_str = "getnetbyaddr(__net, __type)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(net, "__net"));

        auto printer = new ArgPrinter(type, "__type");
        printer->set_enum_printer(print_socket_addr_family, type);
        abii_args->push_arg(printer);

        auto abii_ret = real_getnetbyaddr(net, type);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getnetbyaddr, abii_ret)
    return real_getnetbyaddr(net, type);
}

static netent* (*real_getnetbyname)(const char*) = nullptr;

extern "C" netent* abii_getnetbyname(const char* name)
{
    OVERRIDE_PREFIX(getnetbyname)
        pre_fmtd_str pi_str = "getnetbyname(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getnetbyname(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getnetbyname, abii_ret)
    return real_getnetbyname(name);
}

static int (*real_getnetent_r)(netent*, char*, size_t, netent**, int*) = nullptr;

extern "C" int abii_getnetent_r(netent* result_buf, char* buf, size_t buflen, netent** result, int* h_errnop)
{
    OVERRIDE_PREFIX(getnetent_r)
        pre_fmtd_str pi_str = "getnetent_r(__result_buf, __buf, __buflen, __result, __h_errnop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto printer1 = new ArgPrinter(h_errnop, "__h_errnop");
        printer1->set_enum_printer_with_depth(print_netdb_h_errno, *h_errnop, 1);
        abii_args->push_arg(printer1);

        auto abii_ret = real_getnetent_r(result_buf, buf, buflen, result, h_errnop);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getnetent_r, abii_ret)
    return real_getnetent_r(result_buf, buf, buflen, result, h_errnop);
}

static int (*real_getnetbyaddr_r)(uint32_t, int, netent*, char*, size_t, netent**, int*) = nullptr;

extern "C" int abii_getnetbyaddr_r(uint32_t net, int type, netent* result_buf, char* buf, size_t buflen,
                                   netent** result, int* h_errnop)
{
    OVERRIDE_PREFIX(getnetbyaddr_r)
        pre_fmtd_str pi_str = "getnetbyaddr_r(__net, __type, __result_buf, __buf, __buflen, __result, __h_errnop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(net, "__net"));

        auto printer = new ArgPrinter(type, "__type");
        printer->set_enum_printer(print_socket_addr_family, type);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto printer2 = new ArgPrinter(h_errnop, "__h_errnop");
        printer2->set_enum_printer_with_depth(print_netdb_h_errno, *h_errnop, 1);
        abii_args->push_arg(printer2);

        auto abii_ret = real_getnetbyaddr_r(net, type, result_buf, buf, buflen, result, h_errnop);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getnetbyaddr_r, abii_ret)
    return real_getnetbyaddr_r(net, type, result_buf, buf, buflen, result, h_errnop);
}

static int (*real_getnetbyname_r)(const char*, netent*, char*, size_t, netent**, int*) = nullptr;

extern "C" int abii_getnetbyname_r(const char* name, netent* result_buf, char* buf, size_t buflen, netent** result,
                                   int* h_errnop)
{
    OVERRIDE_PREFIX(getnetbyname_r)
        pre_fmtd_str pi_str = "getnetbyname_r(name, __result_buf, __buf, __buflen, __result, __h_errnop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto printer1 = new ArgPrinter(h_errnop, "__h_errnop");
        printer1->set_enum_printer_with_depth(print_netdb_h_errno, *h_errnop, 1);
        abii_args->push_arg(printer1);

        auto abii_ret = real_getnetbyname_r(name, result_buf, buf, buflen, result, h_errnop);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getnetbyname_r, abii_ret)
    return real_getnetbyname_r(name, result_buf, buf, buflen, result, h_errnop);
}

static void (*real_setservent)(int) = nullptr;

extern "C" void abii_setservent(int stay_open)
{
    OVERRIDE_PREFIX(setservent)
        pre_fmtd_str pi_str = "setservent(__stay_open)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stay_open, "__stay_open"));

        real_setservent(stay_open);
    OVERRIDE_SUFFIX(setservent,)
    return real_setservent(stay_open);
}

static void (*real_endservent)() = nullptr;

extern "C" void abii_endservent()
{
    OVERRIDE_PREFIX(endservent)
        pre_fmtd_str pi_str = "endservent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endservent();
    OVERRIDE_SUFFIX(endservent,)
    return real_endservent();
}

static servent* (*real_getservent)() = nullptr;

extern "C" servent* abii_getservent()
{
    OVERRIDE_PREFIX(getservent)
        pre_fmtd_str pi_str = "getservent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getservent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getservent, abii_ret)
    return real_getservent();
}

static servent* (*real_getservbyname)(const char*, const char*) = nullptr;

extern "C" servent* abii_getservbyname(const char* name, const char* proto)
{
    OVERRIDE_PREFIX(getservbyname)
        pre_fmtd_str pi_str = "getservbyname(__name, __proto)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(proto, "__proto"));

        auto abii_ret = real_getservbyname(name, proto);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getservbyname, abii_ret)
    return real_getservbyname(name, proto);
}

static servent* (*real_getservbyport)(int, const char*) = nullptr;

extern "C" servent* abii_getservbyport(int port, const char* proto)
{
    OVERRIDE_PREFIX(getservbyport)
        pre_fmtd_str pi_str = "getservbyport(__port, __proto)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(port, "__port"));
        abii_args->push_arg(new ArgPrinter(proto, "__proto"));

        auto abii_ret = real_getservbyport(port, proto);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getservbyport, abii_ret)
    return real_getservbyport(port, proto);
}

static int (*real_getservent_r)(servent*, char*, size_t, servent**) = nullptr;

extern "C" int abii_getservent_r(servent* result_buf, char* buf, size_t buflen, servent** result)
{
    OVERRIDE_PREFIX(getservent_r)
        pre_fmtd_str pi_str = "getservent_r(__result_buf, __buf, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getservent_r(result_buf, buf, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getservent_r, abii_ret)
    return real_getservent_r(result_buf, buf, buflen, result);
}

static int (*real_getservbyname_r)(const char*, const char*, servent*, char*, size_t, servent**) = nullptr;

extern "C" int abii_getservbyname_r(const char* name, const char* proto, servent* result_buf, char* buf, size_t buflen,
                                    servent** result)
{
    OVERRIDE_PREFIX(getservbyname_r)
        pre_fmtd_str pi_str = "getservbyname_r(__name, __proto, __result_buf, __buf, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(proto, "__proto"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getservbyname_r(name, proto, result_buf, buf, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getservbyname_r, abii_ret)
    return real_getservbyname_r(name, proto, result_buf, buf, buflen, result);
}

static int (*real_getservbyport_r)(int, const char*, servent*, char*, size_t, servent**) = nullptr;

extern "C" int abii_getservbyport_r(int port, const char* proto, servent* result_buf, char* buf, size_t buflen,
                                    servent** result)
{
    OVERRIDE_PREFIX(getservbyport_r)
        pre_fmtd_str pi_str = "getservbyport_r(__port, __proto, __result_buf, __buf, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(port, "__port"));
        abii_args->push_arg(new ArgPrinter(proto, "__proto"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getservbyport_r(port, proto, result_buf, buf, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getservbyport_r, abii_ret)
    return real_getservbyport_r(port, proto, result_buf, buf, buflen, result);
}

static void (*real_setprotoent)(int) = nullptr;

extern "C" void abii_setprotoent(int stay_open)
{
    OVERRIDE_PREFIX(setprotoent)
        pre_fmtd_str pi_str = "setprotoent(__stay_open)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stay_open, "__stay_open"));

        real_setprotoent(stay_open);
    OVERRIDE_SUFFIX(setprotoent,)
    return real_setprotoent(stay_open);
}

static void (*real_endprotoent)() = nullptr;

extern "C" void abii_endprotoent()
{
    OVERRIDE_PREFIX(endprotoent)
        pre_fmtd_str pi_str = "endprotoent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endprotoent();
    OVERRIDE_SUFFIX(endprotoent,)
    return real_endprotoent();
}

static protoent*(*real_getprotoent)() = nullptr;

extern "C" protoent* abii_getprotoent()
{
    OVERRIDE_PREFIX(getprotoent)
        pre_fmtd_str pi_str = "getprotoent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getprotoent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getprotoent, abii_ret)
    return real_getprotoent();
}

static protoent* (*real_getprotobyname)(const char*) = nullptr;

extern "C" protoent* abii_getprotobyname(const char* name)
{
    OVERRIDE_PREFIX(getprotobyname)
        pre_fmtd_str pi_str = "getprotobyname(__name, __proto)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getprotobyname(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getprotobyname, abii_ret)
    return real_getprotobyname(name);
}

static protoent* (*real_getprotobynumber)(int) = nullptr;

extern "C" protoent* abii_getprotobynumber(int proto)
{
    OVERRIDE_PREFIX(getprotobynumber)
        pre_fmtd_str pi_str = "getprotobynumber(__proto)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(proto, "__proto"));

        auto abii_ret = real_getprotobynumber(proto);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getprotobynumber, abii_ret)
    return real_getprotobynumber(proto);
}

static int (*real_getprotoent_r)(protoent*, char*, size_t, protoent**) = nullptr;

extern "C" int abii_getprotoent_r(protoent* result_buf, char* buf, size_t buflen, protoent** result)
{
    OVERRIDE_PREFIX(getprotoent_r)
        pre_fmtd_str pi_str = "getprotoent_r(__result_buf, __buf, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getprotoent_r(result_buf, buf, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getprotoent_r, abii_ret)
    return real_getprotoent_r(result_buf, buf, buflen, result);
}

static int (*real_getprotobyname_r)(const char*, protoent*, char*, size_t, protoent**) = nullptr;

extern "C" int abii_getprotobyname_r(const char* name, protoent* result_buf, char* buf, size_t buflen,
                                     protoent** result)
{
    OVERRIDE_PREFIX(getprotobyname_r)
        pre_fmtd_str pi_str = "getprotobyname_r(__name, __result_buf, __buf, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getprotobyname_r(name, result_buf, buf, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getprotobyname_r, abii_ret)
    return real_getprotobyname_r(name, result_buf, buf, buflen, result);
}

static int (*real_getprotobynumber_r)(int, protoent*, char*, size_t, protoent**) = nullptr;

extern "C" int abii_getprotobynumber_r(int proto, protoent* result_buf, char* buf, size_t buflen, protoent** result)
{
    OVERRIDE_PREFIX(getprotobynumber_r)
        pre_fmtd_str pi_str = "getprotobynumber_r(__proto, __result_buf, __buf, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(proto, "__proto"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getprotobynumber_r(proto, result_buf, buf, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getprotobynumber_r, abii_ret)
    return real_getprotobynumber_r(proto, result_buf, buf, buflen, result);
}

static int (*real_setnetgrent)(const char*) = nullptr;

extern "C" int abii_setnetgrent(const char* netgroup)
{
    OVERRIDE_PREFIX(setnetgrent)
        pre_fmtd_str pi_str = "setnetgrent(__netgroup)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(netgroup, "__netgroup"));

        auto abii_ret = real_setnetgrent(netgroup);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setnetgrent, abii_ret)
    return real_setnetgrent(netgroup);
}

static void (*real_endnetgrent)() = nullptr;

extern "C" void abii_endnetgrent()
{
    OVERRIDE_PREFIX(endnetgrent)
        pre_fmtd_str pi_str = "endnetgrent()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endnetgrent();
    OVERRIDE_SUFFIX(endnetgrent,)
    return real_endnetgrent();
}

static int (*real_getnetgrent)(char**, char**, char**) = nullptr;

extern "C" int abii_getnetgrent(char** hostp, char** userp, char** domainp)
{
    OVERRIDE_PREFIX(getnetgrent)
        pre_fmtd_str pi_str = "getnetgrent(__hostp, __userp, __domainp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(hostp, "__hostp"));
        abii_args->push_arg(new ArgPrinter(userp, "__userp"));
        abii_args->push_arg(new ArgPrinter(domainp, "__domainp"));

        auto abii_ret = real_getnetgrent(hostp, userp, domainp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getnetgrent, abii_ret)
    return real_getnetgrent(hostp, userp, domainp);
}

static int (*real_innetgr)(const char*, const char*, const char*, const char*) = nullptr;

extern "C" int abii_innetgr(const char* netgroup, const char* host, const char* user, const char* domain)
{
    OVERRIDE_PREFIX(innetgr)
        pre_fmtd_str pi_str = "innetgr(__netgroup, __host, __user, __domain)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(netgroup, "__netgroup"));
        abii_args->push_arg(new ArgPrinter(host, "__host"));
        abii_args->push_arg(new ArgPrinter(user, "__user"));
        abii_args->push_arg(new ArgPrinter(domain, "__domain"));

        auto abii_ret = real_innetgr(netgroup, host, user, domain);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(innetgr, abii_ret)
    return real_innetgr(netgroup, host, user, domain);
}

static int (*real_getnetgrent_r)(char**, char**, char**, char*, size_t) = nullptr;

extern "C" int abii_getnetgrent_r(char** hostp, char** userp, char** domainp, char* buffer, size_t buflen)
{
    OVERRIDE_PREFIX(getnetgrent_r)
        pre_fmtd_str pi_str = "getnetgrent_r(__hostp, __userp, __domainp, __buffer, __buflen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(hostp, "__hostp"));
        abii_args->push_arg(new ArgPrinter(userp, "__userp"));
        abii_args->push_arg(new ArgPrinter(domainp, "__domainp"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));

        auto abii_ret = real_getnetgrent_r(hostp, userp, domainp, buffer, buflen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getnetgrent_r, abii_ret)
    return real_getnetgrent_r(hostp, userp, domainp, buffer, buflen);
}

static int (*real_rcmd)(char**, unsigned short int, const char*, const char*, const char*, int*) = nullptr;

extern "C" int abii_rcmd(char** ahost, unsigned short int rport, const char* locuser, const char* remuser,
                         const char* cmd, int* fd2p)
{
    OVERRIDE_PREFIX(rcmd)
        pre_fmtd_str pi_str = "rcmd(__ahost, __rport, __locuser, __remuser, __cmd, __fd2p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ahost, "__ahost"));
        abii_args->push_arg(new ArgPrinter(rport, "__rport"));
        abii_args->push_arg(new ArgPrinter(locuser, "__locuser"));
        abii_args->push_arg(new ArgPrinter(remuser, "__remuser"));
        abii_args->push_arg(new ArgPrinter(cmd, "__cmd"));
        abii_args->push_arg(new ArgPrinter(fd2p, "__fd2p"));

        auto abii_ret = real_rcmd(ahost, rport, locuser, remuser, cmd, fd2p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rcmd, abii_ret)
    return real_rcmd(ahost, rport, locuser, remuser, cmd, fd2p);
}

static int (*real_rcmd_af)(char**, unsigned short int, const char*, const char*, const char*, int*, sa_family_t) =
    nullptr;

extern "C" int abii_rcmd_af(char** ahost, unsigned short int rport, const char* locuser, const char* remuser,
                            const char* cmd, int* fd2p, sa_family_t af)
{
    OVERRIDE_PREFIX(rcmd_af)
        pre_fmtd_str pi_str = "rcmd_af(__ahost, __rport, __locuser, __remuser, __cmd, __fd2p, __af)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ahost, "__ahost"));
        abii_args->push_arg(new ArgPrinter(rport, "__rport"));
        abii_args->push_arg(new ArgPrinter(locuser, "__locuser"));
        abii_args->push_arg(new ArgPrinter(remuser, "__remuser"));
        abii_args->push_arg(new ArgPrinter(cmd, "__cmd"));
        abii_args->push_arg(new ArgPrinter(fd2p, "__fd2p"));

        auto printer = new ArgPrinter(af, "__af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        auto abii_ret = real_rcmd_af(ahost, rport, locuser, remuser, cmd, fd2p, af);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rcmd_af, abii_ret)
    return real_rcmd_af(ahost, rport, locuser, remuser, cmd, fd2p, af);
}

static int (*real_rexec)(char**, int, const char*, const char*, const char*, int*) = nullptr;

extern "C" int abii_rexec(char** ahost, int rport, const char* name, const char* pass, const char* cmd, int* fd2p)
{
    OVERRIDE_PREFIX(rexec)
        pre_fmtd_str pi_str = "rexec(__ahost, __rport, __name, __pass, __cmd, __fd2p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ahost, "__ahost"));
        abii_args->push_arg(new ArgPrinter(rport, "__rport"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(pass, "__pass"));
        abii_args->push_arg(new ArgPrinter(cmd, "__cmd"));
        abii_args->push_arg(new ArgPrinter(fd2p, "__fd2p"));

        auto abii_ret = real_rexec(ahost, rport, name, pass, cmd, fd2p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rexec, abii_ret)
    return real_rexec(ahost, rport, name, pass, cmd, fd2p);
}

static int (*real_rexec_af)(char**, int, const char*, const char*, const char*, int*, sa_family_t) = nullptr;

extern "C" int abii_rexec_af(char** ahost, int rport, const char* name, const char* pass, const char* cmd, int* fd2p,
                             sa_family_t af)
{
    OVERRIDE_PREFIX(rexec_af)
        pre_fmtd_str pi_str = "rexec_af(__ahost, __rport, __name, __pass, __cmd, __fd2p, __af)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ahost, "__ahost"));
        abii_args->push_arg(new ArgPrinter(rport, "__rport"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(pass, "__pass"));
        abii_args->push_arg(new ArgPrinter(cmd, "__cmd"));
        abii_args->push_arg(new ArgPrinter(fd2p, "__fd2p"));

        auto printer = new ArgPrinter(af, "__af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        auto abii_ret = real_rexec_af(ahost, rport, name, pass, cmd, fd2p, af);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rexec_af, abii_ret)
    return real_rexec_af(ahost, rport, name, pass, cmd, fd2p, af);
}

static int (*real_ruserok)(const char*, int, const char*, const char*) = nullptr;

extern "C" int abii_ruserok(const char* rhost, int suser, const char* remuser, const char* locuser)
{
    OVERRIDE_PREFIX(ruserok)
        pre_fmtd_str pi_str = "ruserok(__rhost, __suser, __remuser, __locuser)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rhost, "__rhost"));
        abii_args->push_arg(new ArgPrinter(suser, "__suser"));
        abii_args->push_arg(new ArgPrinter(remuser, "__remuser"));
        abii_args->push_arg(new ArgPrinter(locuser, "__locuser"));

        auto abii_ret = real_ruserok(rhost, suser, remuser, locuser);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ruserok, abii_ret)
    return real_ruserok(rhost, suser, remuser, locuser);
}

static int (*real_ruserok_af)(const char*, int, const char*, const char*, sa_family_t) = nullptr;

extern "C" int abii_ruserok_af(const char* rhost, int suser, const char* remuser, const char* locuser, sa_family_t af)
{
    OVERRIDE_PREFIX(ruserok_af)
        pre_fmtd_str pi_str = "ruserok_af(__rhost, __suser, __remuser, __locuser, __af)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rhost, "__rhost"));
        abii_args->push_arg(new ArgPrinter(suser, "__suser"));
        abii_args->push_arg(new ArgPrinter(remuser, "__remuser"));
        abii_args->push_arg(new ArgPrinter(locuser, "__locuser"));

        auto printer = new ArgPrinter(af, "__af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        auto abii_ret = real_ruserok_af(rhost, suser, remuser, locuser, af);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ruserok_af, abii_ret)
    return real_ruserok_af(rhost, suser, remuser, locuser, af);
}

static int (*real_iruserok)(uint32_t, int, const char*, const char*) = nullptr;

extern "C" int abii_iruserok(uint32_t raddr, int suser, const char* remuser, const char* locuser)
{
    OVERRIDE_PREFIX(iruserok)
        pre_fmtd_str pi_str = "iruserok(__raddr, __suser, __remuser, __locuser)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(raddr, "__raddr"));
        abii_args->push_arg(new ArgPrinter(suser, "__suser"));
        abii_args->push_arg(new ArgPrinter(remuser, "__remuser"));
        abii_args->push_arg(new ArgPrinter(locuser, "__locuser"));

        auto abii_ret = real_iruserok(raddr, suser, remuser, locuser);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iruserok, abii_ret)
    return real_iruserok(raddr, suser, remuser, locuser);
}

static int (*real_iruserok_af)(const void*, int, const char*, const char*, sa_family_t) = nullptr;

extern "C" int abii_iruserok_af(const void* raddr, int suser, const char* remuser, const char* locuser, sa_family_t af)
{
    OVERRIDE_PREFIX(iruserok_af)
        pre_fmtd_str pi_str = "iruserok_af(__raddr, __suser, __remuser, __locuser)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(raddr, "__raddr"));
        abii_args->push_arg(new ArgPrinter(suser, "__suser"));
        abii_args->push_arg(new ArgPrinter(remuser, "__remuser"));
        abii_args->push_arg(new ArgPrinter(locuser, "__locuser"));

        auto printer = new ArgPrinter(af, "__af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        auto abii_ret = real_iruserok_af(raddr, suser, remuser, locuser, af);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iruserok_af, abii_ret)
    return real_iruserok_af(raddr, suser, remuser, locuser, af);
}

static int (*real_rresvport)(int*) = nullptr;

extern "C" int abii_rresvport(int* alport)
{
    OVERRIDE_PREFIX(rresvport)
        pre_fmtd_str pi_str = "rresvport(__alport)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(alport, "__alport"));

        auto abii_ret = real_rresvport(alport);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rresvport, abii_ret)
    return real_rresvport(alport);
}

static int (*real_rresvport_af)(int*, sa_family_t) = nullptr;

extern "C" int abii_rresvport_af(int* alport, sa_family_t af)
{
    OVERRIDE_PREFIX(rresvport_af)
        pre_fmtd_str pi_str = "rresvport_af(__alport, __af)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(alport, "__alport"));

        auto printer = new ArgPrinter(af, "__af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        auto abii_ret = real_rresvport_af(alport, af);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rresvport_af, abii_ret)
    return real_rresvport_af(alport, af);
}

static int (*real_getaddrinfo)(const char*, const char*, const addrinfo*, addrinfo**) = nullptr;

extern "C" int abii_getaddrinfo(const char* name, const char* service, const addrinfo* req, addrinfo** pai)
{
    OVERRIDE_PREFIX(getaddrinfo)
        pre_fmtd_str pi_str = "getaddrinfo(__name, __service, __req, __pai)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(service, "__service"));
        abii_args->push_arg(new ArgPrinter(req, "__req"));
        abii_args->push_arg(new ArgPrinter(pai, "__pai"));

        auto abii_ret = real_getaddrinfo(name, service, req, pai);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_netdb_ai_errno, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(getaddrinfo, abii_ret)
    return real_getaddrinfo(name, service, req, pai);
}

static void (*real_freeaddrinfo)(addrinfo*) __THROW = nullptr;

extern "C" void abii_freeaddrinfo(addrinfo* ai) __THROW
{
    OVERRIDE_PREFIX(freeaddrinfo)
        pre_fmtd_str pi_str = "freeaddrinfo(__ai)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ai, "__ai"));

        real_freeaddrinfo(ai);
    OVERRIDE_SUFFIX(freeaddrinfo,)
    return real_freeaddrinfo(ai);
}

static const char* (*real_gai_strerror)(int) __THROW = nullptr;

extern "C" const char* abii_gai_strerror(int ecode) __THROW
{
    OVERRIDE_PREFIX(gai_strerror)
        pre_fmtd_str pi_str = "gai_strerror(__ecode)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(ecode, "__ecode");
        printer->set_enum_printer(print_netdb_ai_errno, ecode);
        abii_args->push_arg(printer);

        auto abii_ret = real_gai_strerror(ecode);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gai_strerror, abii_ret)
    return real_gai_strerror(ecode);
}

static int (*real_getnameinfo)(const sockaddr*, socklen_t, char*, socklen_t, char*, socklen_t, int) = nullptr;

extern "C" int abii_getnameinfo(const sockaddr* sa, socklen_t salen, char* host, socklen_t hostlen, char* serv,
                                socklen_t servlen, int flags)
{
    OVERRIDE_PREFIX(getnameinfo)
        pre_fmtd_str pi_str = "getnameinfo(__sa, __salen, __host, __hostlen, __serv, __servlen, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sa, "__sa"));
        abii_args->push_arg(new ArgPrinter(salen, "__salen"));
        abii_args->push_arg(new ArgPrinter(host, "__host"));

        auto printer = new ArgPrinter(hostlen, "__hostlen");
        printer->set_enum_printer(print_netdb_ni_maxhost, hostlen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(serv, "__serv"));

        auto printer1 = new ArgPrinter(servlen, "__servlen");
        printer1->set_enum_printer(print_netdb_ni_maxserv, servlen);
        abii_args->push_arg(printer1);

        auto printer2 = new ArgPrinter(flags);
        printer2->set_enum_printer(print_netdb_ni_flag, flags);
        abii_args->push_arg(printer2);

        auto abii_ret = real_getnameinfo(sa, salen, host, hostlen, serv, servlen, flags);

        auto printer3 = new ArgPrinter(abii_ret, "return");
        printer3->set_enum_printer(print_netdb_ai_errno, abii_ret);
        abii_args->push_return(printer3);
    OVERRIDE_SUFFIX(getnameinfo, abii_ret)
    return real_getnameinfo(sa, salen, host, hostlen, serv, servlen, flags);
}

static int (*real_getaddrinfo_a)(int, gaicb*[__restrict_arr], int, sigevent*) = nullptr;

extern "C" int abii_getaddrinfo_a(int mode, gaicb* list[__restrict_arr], int ent, sigevent* sig)
{
    OVERRIDE_PREFIX(getaddrinfo_a)
        pre_fmtd_str pi_str = "getaddrinfo_a(__mode, __list, __ent, __sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(mode, "__mode");
        printer->set_enum_printer(print_netdb_lookup_mode, mode);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(list, "__list");
        printer1->set_len(ent);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(ent, "__ent"));
        abii_args->push_arg(new ArgPrinter(sig, "__sig"));

        auto abii_ret = real_getaddrinfo_a(mode, list, ent, sig);

        auto printer2 = new ArgPrinter(abii_ret, "return");
        printer2->set_enum_printer(print_netdb_ai_errno, abii_ret);
        abii_args->push_return(printer2);
    OVERRIDE_SUFFIX(getaddrinfo_a, abii_ret)
    return real_getaddrinfo_a(mode, list, ent, sig);
}

static int (*real_gai_suspend)(const gaicb* const[], int, const timespec*) = nullptr;

extern "C" int abii_gai_suspend(const gaicb* const list[], int ent, const timespec* timeout)
{
    OVERRIDE_PREFIX(gai_suspend)
        pre_fmtd_str pi_str = "gai_suspend(__list, __ent, __timeout)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(list, "__list");
        printer->set_len(ent);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(ent, "__ent"));
        abii_args->push_arg(new ArgPrinter(timeout, "__timeout"));

        auto abii_ret = real_gai_suspend(list, ent, timeout);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_netdb_ai_errno, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(gai_suspend, abii_ret)
    return real_gai_suspend(list, ent, timeout);
}

static int (*real_gai_error)(gaicb*) __THROW = nullptr;

extern "C" int abii_gai_error(gaicb* req) __THROW
{
    OVERRIDE_PREFIX(gai_error)
        pre_fmtd_str pi_str = "gai_error(__req)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(req, "__req"));

        auto abii_ret = real_gai_error(req);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_netdb_ai_errno, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(gai_error, abii_ret)
    return real_gai_error(req);
}

static int (*real_gai_cancel)(gaicb*) __THROW = nullptr;

extern "C" int abii_gai_cancel(gaicb* gaicbp) __THROW
{
    OVERRIDE_PREFIX(gai_cancel)
        pre_fmtd_str pi_str = "gai_cancel(__gaicbp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(gaicbp, "__gaicbp"));

        auto abii_ret = real_gai_cancel(gaicbp);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_netdb_ai_errno, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(gai_cancel, abii_ret)
    return real_gai_cancel(gaicbp);
}
}
