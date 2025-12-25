//
// Created by Trent Tanchin on 4/17/25.
//

#include "resolv.h"

#include "arpa/nameser_compat.h"
#include "bits/types/res_state.h"

namespace abii
{
static struct __res_state* (*real___res_state)() = nullptr;

extern "C" __attribute__ ((__const__))
struct __res_state* abii___res_state()
{
    OVERRIDE_PREFIX(__res_state)
        pre_fmtd_str pi_str = "__res_state()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real___res_state();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__res_state, abii_ret)
    return real___res_state();
}

static int (*real___res_init)() __THROW = nullptr;

extern "C" int abii___res_init() __THROW
{
    OVERRIDE_PREFIX(__res_init)
        pre_fmtd_str pi_str = "__res_init()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real___res_init();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__res_init, abii_ret)
    return real___res_init();
}

static int (*real_res_mkquery)(int, const char*, int, int, const unsigned char*, int, const unsigned char*,
                               unsigned char*, int) __THROW = nullptr;

extern "C" int abii_res_mkquery(int op, const char* dname, int res_class, int type, const unsigned char* data,
                                int datalen, const unsigned char* newrr, unsigned char* buf, int buflen) __THROW
{
    OVERRIDE_PREFIX(res_mkquery)
        pre_fmtd_str pi_str = "res_mkquery(op, dname, res_class, type, data, datalen, newrr, buf, buflen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(op, "op");
        printer->set_enum_printer(print_nameser_compat_opcode, op);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(dname, "dname"));
        abii_args->push_arg(new ArgPrinter(res_class, "res_class"));
        abii_args->push_arg(new ArgPrinter(type, "type"));

        auto printer1 = new ArgPrinter(data, "data");
        printer1->set_len(datalen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(datalen, "datalen"));
        abii_args->push_arg(new ArgPrinter(newrr, "newrr"));

        auto printer2 = new ArgPrinter(buf, "buf");
        printer2->set_len(buflen);
        abii_args->push_arg(printer2);

        abii_args->push_arg(new ArgPrinter(buflen, "buflen"));

        auto abii_ret = real_res_mkquery(op, dname, res_class, type, data, datalen, newrr, buf, buflen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_mkquery, abii_ret)
    return real_res_mkquery(op, dname, res_class, type, data, datalen, newrr, buf, buflen);
}

static int (*real_res_query)(const char*, int, int, unsigned char*, int) __THROW = nullptr;

extern "C" int abii_res_query(const char* dname, int res_class, int type, unsigned char* answer, int anslen) __THROW
{
    OVERRIDE_PREFIX(res_query)
        pre_fmtd_str pi_str = "res_query(dname, res_class, type, answer, anslen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dname, "dname"));
        abii_args->push_arg(new ArgPrinter(res_class, "res_class"));
        abii_args->push_arg(new ArgPrinter(type, "type"));

        auto printer = new ArgPrinter(answer, "answer");
        printer->set_len(anslen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(anslen, "anslen"));

        auto abii_ret = real_res_query(dname, res_class, type, answer, anslen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_query, abii_ret)
    return real_res_query(dname, res_class, type, answer, anslen);
}

static int (*real_res_querydomain)(const char*, const char*, int, int, unsigned char*, int) __THROW = nullptr;

extern "C" int abii_res_querydomain(const char* name, const char* domain, int res_class, int type,
                                    unsigned char* answer, int anslen) __THROW
{
    OVERRIDE_PREFIX(res_querydomain)
        pre_fmtd_str pi_str = "res_querydomain(name, domain, res_class, type, answer, anslen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "name"));
        abii_args->push_arg(new ArgPrinter(domain, "domain"));
        abii_args->push_arg(new ArgPrinter(res_class, "res_class"));
        abii_args->push_arg(new ArgPrinter(type, "type"));

        auto printer = new ArgPrinter(answer, "answer");
        printer->set_len(anslen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(anslen, "anslen"));

        auto abii_ret = real_res_querydomain(name, domain, res_class, type, answer, anslen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_querydomain, abii_ret)
    return real_res_querydomain(name, domain, res_class, type, answer, anslen);
}

static int (*real_res_search)(const char*, int, int, unsigned char*, int) __THROW = nullptr;

extern "C" int abii_res_search(const char* dname, int res_class, int type, unsigned char* answer, int anslen) __THROW
{
    OVERRIDE_PREFIX(res_search)
        pre_fmtd_str pi_str = "res_search(name, domain, res_class, type, answer, anslen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dname, "dname"));
        abii_args->push_arg(new ArgPrinter(res_class, "res_class"));
        abii_args->push_arg(new ArgPrinter(type, "type"));

        auto printer = new ArgPrinter(answer, "answer");
        printer->set_len(anslen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(anslen, "anslen"));

        auto abii_ret = real_res_search(dname, res_class, type, answer, anslen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_search, abii_ret)
    return real_res_search(dname, res_class, type, answer, anslen);
}

static int (*real_res_send)(const unsigned char*, int, unsigned char*, int) __THROW = nullptr;

extern "C" int abii_res_send(const unsigned char* msg, int msglen, unsigned char* answer, int anslen) __THROW
{
    OVERRIDE_PREFIX(res_send)
        pre_fmtd_str pi_str = "res_send(msg, msglen, answer, anslen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(msg, "msg");
        printer->set_len(msglen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(msglen, "msglen"));

        auto printer1 = new ArgPrinter(answer, "answer");
        printer1->set_len(anslen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(anslen, "anslen"));

        auto abii_ret = real_res_send(msg, msglen, answer, anslen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_send, abii_ret)
    return real_res_send(msg, msglen, answer, anslen);
}

static int (*real_res_hnok)(const char*) __THROW = nullptr;

extern "C" int abii_res_hnok(const char* dn) __THROW
{
    OVERRIDE_PREFIX(res_hnok)
        pre_fmtd_str pi_str = "res_hnok(dn)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dn, "dn"));

        auto abii_ret = real_res_hnok(dn);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_hnok, abii_ret)
    return real_res_hnok(dn);
}

static int (*real_res_ownok)(const char*) __THROW = nullptr;

extern "C" int abii_res_ownok(const char* dn) __THROW
{
    OVERRIDE_PREFIX(res_ownok)
        pre_fmtd_str pi_str = "res_ownok(dn)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dn, "dn"));

        auto abii_ret = real_res_ownok(dn);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_ownok, abii_ret)
    return real_res_ownok(dn);
}

static int (*real_res_mailok)(const char*) __THROW = nullptr;

extern "C" int abii_res_mailok(const char* dn) __THROW
{
    OVERRIDE_PREFIX(res_mailok)
        pre_fmtd_str pi_str = "res_mailok(dn)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dn, "dn"));

        auto abii_ret = real_res_mailok(dn);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_mailok, abii_ret)
    return real_res_mailok(dn);
}

static int (*real_res_dnok)(const char*) __THROW = nullptr;

extern "C" int abii_res_dnok(const char* dn) __THROW
{
    OVERRIDE_PREFIX(res_dnok)
        pre_fmtd_str pi_str = "res_dnok(dn)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dn, "dn"));

        auto abii_ret = real_res_dnok(dn);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_dnok, abii_ret)
    return real_res_dnok(dn);
}

static int (*real_dn_skipname)(const unsigned char*, const unsigned char*) __THROW = nullptr;

extern "C" int abii_dn_skipname(const unsigned char* comp_dn, const unsigned char* eom) __THROW
{
    OVERRIDE_PREFIX(dn_skipname)
        pre_fmtd_str pi_str = "dn_skipname(comp_dn, eom)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(comp_dn, "comp_dn"));
        abii_args->push_arg(new ArgPrinter(eom, "eom"));

        auto abii_ret = real_dn_skipname(comp_dn, eom);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dn_skipname, abii_ret)
    return real_dn_skipname(comp_dn, eom);
}

static int (*real_dn_comp)(const char*, unsigned char*, int, unsigned char**, unsigned char**) __THROW = nullptr;

extern "C" int abii_dn_comp(const char* exp_dn, unsigned char* comp_dn, int length, unsigned char** dnptrs,
                            unsigned char** lastdnptr) __THROW
{
    OVERRIDE_PREFIX(dn_comp)
        pre_fmtd_str pi_str = "dn_comp(exp_dn, comp_dn, length, dnptrs, lastdnptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(exp_dn, "exp_dn"));

        auto printer = new ArgPrinter(comp_dn, "comp_dn");
        printer->set_len(length);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(length, "length"));
        abii_args->push_arg(new ArgPrinter(dnptrs, "dnptrs"));
        abii_args->push_arg(new ArgPrinter(lastdnptr, "lastdnptr"));

        auto abii_ret = real_dn_comp(exp_dn, comp_dn, length, dnptrs, lastdnptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dn_comp, abii_ret)
    return real_dn_comp(exp_dn, comp_dn, length, dnptrs, lastdnptr);
}

static int (*real_dn_expand)(const unsigned char*, const unsigned char*, const unsigned char*, char*, int) __THROW =
    nullptr;

extern "C" int abii_dn_expand(const unsigned char* msg, const unsigned char* eomorig, const unsigned char* comp_dn,
                              char* exp_dn, int length) __THROW
{
    OVERRIDE_PREFIX(dn_expand)
        pre_fmtd_str pi_str = "dn_expand(msg, eomorig, comp_dn, exp_dn, length)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(msg, "msg"));
        abii_args->push_arg(new ArgPrinter(eomorig, "eomorig"));
        abii_args->push_arg(new ArgPrinter(comp_dn, "comp_dn"));

        auto printer = new ArgPrinter(exp_dn, "exp_dn");
        printer->set_len(length);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(length, "length"));

        auto abii_ret = real_dn_expand(msg, eomorig, comp_dn, exp_dn, length);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dn_expand, abii_ret)
    return real_dn_expand(msg, eomorig, comp_dn, exp_dn, length);
}

static unsigned int (*real___res_randomid)() __THROW = nullptr;

extern "C" __RESOLV_DEPRECATED_MSG("use getentropy instead")
unsigned int abii___res_randomid() __THROW
{
    OVERRIDE_PREFIX(__res_randomid)
        pre_fmtd_str pi_str = "__res_randomid()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real___res_randomid();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__res_randomid, abii_ret)
    return real___res_randomid();
}

static int (*real___res_ninit)(res_state) __THROW = nullptr;

extern "C" int abii___res_ninit(res_state statep) __THROW
{
    OVERRIDE_PREFIX(__res_ninit)
        pre_fmtd_str pi_str = "__res_ninit(statep)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(statep, "statep"));

        auto abii_ret = real___res_ninit(statep);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__res_ninit, abii_ret)
    return real___res_ninit(statep);
}

static int (*real_res_nquery)(res_state, const char*, int, int, unsigned char*, int) __THROW = nullptr;

extern "C" int abii_res_nquery(res_state statep, const char* dname, int _class, int type, unsigned char* answer,
                               int anslen) __THROW
{
    OVERRIDE_PREFIX(res_nquery)
        pre_fmtd_str pi_str = "res_nquery(statep, dname, class, type, answer, anslen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(statep, "statep"));
        abii_args->push_arg(new ArgPrinter(dname, "dname"));
        abii_args->push_arg(new ArgPrinter(_class, "class"));
        abii_args->push_arg(new ArgPrinter(type, "type"));

        auto printer = new ArgPrinter(answer, "answer");
        printer->set_len(anslen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(anslen, "anslen"));

        auto abii_ret = real_res_nquery(statep, dname, _class, type, answer, anslen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_nquery, abii_ret)
    return real_res_nquery(statep, dname, _class, type, answer, anslen);
}

static int (*real_res_nsearch)(res_state, const char*, int, int, unsigned char*, int) __THROW = nullptr;

extern "C" int abii_res_nsearch(res_state statep, const char* dname, int _class, int type, unsigned char* answer,
                                int anslen) __THROW
{
    OVERRIDE_PREFIX(res_nsearch)
        pre_fmtd_str pi_str = "res_nsearch(statep, dname, class, type, answer, anslen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(statep, "statep"));
        abii_args->push_arg(new ArgPrinter(dname, "dname"));
        abii_args->push_arg(new ArgPrinter(_class, "class"));
        abii_args->push_arg(new ArgPrinter(type, "type"));

        auto printer = new ArgPrinter(answer, "answer");
        printer->set_len(anslen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(anslen, "anslen"));

        auto abii_ret = real_res_nsearch(statep, dname, _class, type, answer, anslen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_nsearch, abii_ret)
    return real_res_nsearch(statep, dname, _class, type, answer, anslen);
}

static int (*real_res_nquerydomain)(res_state, const char*, const char*, int, int, unsigned char*, int) __THROW =
    nullptr;

extern "C" int abii_res_nquerydomain(res_state statep, const char* name, const char* domain, int _class, int type,
                                     unsigned char* answer, int anslen) __THROW
{
    OVERRIDE_PREFIX(res_nquerydomain)
        pre_fmtd_str pi_str = "res_nquerydomain(statep, name, domain, class, type, answer, anslen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(statep, "statep"));
        abii_args->push_arg(new ArgPrinter(name, "name"));
        abii_args->push_arg(new ArgPrinter(domain, "domain"));
        abii_args->push_arg(new ArgPrinter(_class, "class"));
        abii_args->push_arg(new ArgPrinter(type, "type"));

        auto printer = new ArgPrinter(answer, "answer");
        printer->set_len(anslen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(anslen, "anslen"));

        auto abii_ret = real_res_nquerydomain(statep, name, domain, _class, type, answer, anslen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_nquerydomain, abii_ret)
    return real_res_nquerydomain(statep, name, domain, _class, type, answer, anslen);
}

static int (*real_res_nmkquery)(res_state, int, const char*, int, int, const unsigned char*, int, const unsigned char*,
                                unsigned char*, int) __THROW = nullptr;

extern "C" int abii_res_nmkquery(res_state statep, int op, const char* dname, int _class, int type,
                                 const unsigned char* data, int datalen, const unsigned char* newrr, unsigned char* buf,
                                 int buflen) __THROW
{
    OVERRIDE_PREFIX(res_nmkquery)
        pre_fmtd_str pi_str = "res_nmkquery(statep, op, dname, class, type, data, datalen, newrr, buf, buflen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(statep, "statep"));
        abii_args->push_arg(new ArgPrinter(op, "op"));
        abii_args->push_arg(new ArgPrinter(dname, "dname"));
        abii_args->push_arg(new ArgPrinter(_class, "class"));
        abii_args->push_arg(new ArgPrinter(type, "type"));

        auto printer = new ArgPrinter(data, "data");
        printer->set_len(datalen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(datalen, "datalen"));
        abii_args->push_arg(new ArgPrinter(newrr, "newrr"));

        auto printer1 = new ArgPrinter(buf, "buf");
        printer1->set_len(buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(buflen, "buflen"));

        auto abii_ret = real_res_nmkquery(statep, op, dname, _class, type, data, datalen, newrr, buf, buflen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_nmkquery, abii_ret)
    return real_res_nmkquery(statep, op, dname, _class, type, data, datalen, newrr, buf, buflen);
}

static int (*real_res_nsend)(res_state, const unsigned char*, int, unsigned char*, int) __THROW = nullptr;

extern "C" int abii_res_nsend(res_state statep, const unsigned char* msg, int msglen, unsigned char* answer,
                              int anslen) __THROW
{
    OVERRIDE_PREFIX(res_nsend)
        pre_fmtd_str pi_str = "res_nsend(statep, msg, msglen, answer, anslen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(statep, "statep"));

        auto printer = new ArgPrinter(msg, "msg");
        printer->set_len(msglen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(msglen, "msglen"));

        auto printer1 = new ArgPrinter(answer, "answer");
        printer1->set_len(anslen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(anslen, "anslen"));

        auto abii_ret = real_res_nsend(statep, msg, msglen, answer, anslen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(res_nsend, abii_ret)
    return real_res_nsend(statep, msg, msglen, answer, anslen);
}

static void (*real___res_nclose)(res_state) __THROW = nullptr;

extern "C" void abii___res_nclose(res_state statep) __THROW
{
    OVERRIDE_PREFIX(__res_nclose)
        pre_fmtd_str pi_str = "__res_nclose(statep)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(statep, "statep"));

        real___res_nclose(statep);
    OVERRIDE_SUFFIX(__res_nclose,)
    return real___res_nclose(statep);
}
}
