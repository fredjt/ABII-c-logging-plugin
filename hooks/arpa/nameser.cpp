//
// Created by Trent Tanchin on 11/8/26.
//

#include "nameser.h"

namespace abii
{
static int (*real_ns_name_ntop)(const unsigned char*, char*, size_t) __THROW = nullptr;

extern "C" int abii_ns_name_ntop(const unsigned char* src, char* dst, size_t dstsiz) __THROW
{
    OVERRIDE_PREFIX(ns_name_ntop)
        pre_fmtd_str pi_str = "ns_name_ntop(src, dst, dstsiz)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(src, "src"));

        auto printer = new ArgPrinter(dst, "dst");
        printer->set_len(dstsiz);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(dstsiz, "dstsiz"));

        auto abii_ret = real_ns_name_ntop(src, dst, dstsiz);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ns_name_ntop, abii_ret)
    return real_ns_name_ntop(src, dst, dstsiz);
}

static int (*real_ns_name_pton)(const char*, unsigned char*, size_t) __THROW = nullptr;

extern "C" int abii_ns_name_pton(const char* src, unsigned char* dst, size_t dstsiz) __THROW
{
    OVERRIDE_PREFIX(ns_name_pton)
        pre_fmtd_str pi_str = "ns_name_pton(src, dst, dstsiz)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(src, "src"));

        auto printer = new ArgPrinter(dst, "dst");
        printer->set_len(dstsiz);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(dstsiz, "dstsiz"));

        auto abii_ret = real_ns_name_pton(src, dst, dstsiz);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ns_name_pton, abii_ret)
    return real_ns_name_pton(src, dst, dstsiz);
}

static int (*real_ns_name_unpack)(const unsigned char*, const unsigned char*, const unsigned char*, unsigned char*,
                                  size_t) __THROW = nullptr;

extern "C" int abii_ns_name_unpack(const unsigned char* msg, const unsigned char* eom, const unsigned char* src,
                                   unsigned char* dst, size_t dstsiz) __THROW
{
    OVERRIDE_PREFIX(ns_name_unpack)
        pre_fmtd_str pi_str = "ns_name_unpack(msg, eom, src, dst, dstsiz)";
        abii_args->push_func(new ArgPrinter(pi_str));

        const auto len = eom - msg;
        auto printer = new ArgPrinter(msg, "msg");
        printer->set_len(len);
        abii_args->push_arg(printer);

        constexpr auto zerolen = 0;
        auto printer1 = new ArgPrinter(eom, "eom");
        printer1->set_len(zerolen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(src, "src"));

        auto printer2 = new ArgPrinter(dst, "dst");
        printer2->set_len(dstsiz);
        abii_args->push_arg(printer2);

        abii_args->push_arg(new ArgPrinter(dstsiz, "dstsiz"));

        auto abii_ret = real_ns_name_unpack(msg, eom, src, dst, dstsiz);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ns_name_unpack, abii_ret)
    return real_ns_name_unpack(msg, eom, src, dst, dstsiz);
}

static int (*real_ns_name_pack)(const unsigned char*, unsigned char*, int, const unsigned char**,
                                const unsigned char**) __THROW = nullptr;

extern "C" int abii_ns_name_pack(const unsigned char* src, unsigned char* dst, int dstsiz, const unsigned char** dnptrs,
                                 const unsigned char** lastdnptr) __THROW
{
    OVERRIDE_PREFIX(ns_name_pack)
        pre_fmtd_str pi_str = "ns_name_pack(src, dst, dstsiz, dnptrs, lastdnptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(src, "src"));

        auto printer = new ArgPrinter(dst, "dst");
        printer->set_len(dstsiz);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(dstsiz, "dstsiz"));

        const auto ndnptrs = lastdnptr - dnptrs + 1;
        auto printer1 = new ArgPrinter(dnptrs, "dnptrs");
        printer1->set_len(ndnptrs);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(lastdnptr, "lastdnptr"));

        auto abii_ret = real_ns_name_pack(src, dst, dstsiz, dnptrs, lastdnptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ns_name_pack, abii_ret)
    return real_ns_name_pack(src, dst, dstsiz, dnptrs, lastdnptr);
}

static int (*real_ns_name_uncompress)(const unsigned char*, const unsigned char*, const unsigned char*, char*,
                                      size_t) __THROW = nullptr;

extern "C" int abii_ns_name_uncompress(const unsigned char* msg, const unsigned char* eom, const unsigned char* src,
                                       char* dst, size_t dstsiz) __THROW
{
    OVERRIDE_PREFIX(ns_name_uncompress)
        pre_fmtd_str pi_str = "ns_name_uncompress(msg, eom, src, dst, dstsiz)";
        abii_args->push_func(new ArgPrinter(pi_str));

        const auto len = eom - msg;
        auto printer = new ArgPrinter(msg, "msg");
        printer->set_len(len);
        abii_args->push_arg(printer);

        constexpr auto zerolen = 0;
        auto printer1 = new ArgPrinter(eom, "eom");
        printer1->set_len(zerolen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(src, "src"));

        auto printer2 = new ArgPrinter(dst, "dst");
        printer2->set_len(dstsiz);
        abii_args->push_arg(printer2);

        abii_args->push_arg(new ArgPrinter(dstsiz, "dstsiz"));

        auto abii_ret = real_ns_name_uncompress(msg, eom, src, dst, dstsiz);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ns_name_uncompress, abii_ret)
    return real_ns_name_uncompress(msg, eom, src, dst, dstsiz);
}

static int (*real_ns_name_compress)(const char*, unsigned char*, size_t, const unsigned char**,
                                    const unsigned char**) __THROW = nullptr;

extern "C" int abii_ns_name_compress(const char* src, unsigned char* dst, size_t dstsiz, const unsigned char** dnptrs,
                                     const unsigned char** lastdnptr) __THROW
{
    OVERRIDE_PREFIX(ns_name_compress)
        pre_fmtd_str pi_str = "ns_name_compress(src, dst, dstsiz, dnptrs, lastdnptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(src, "src"));

        auto printer = new ArgPrinter(dst, "dst");
        printer->set_len(dstsiz);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(dstsiz, "dstsiz"));

        const auto ndnptrs = lastdnptr - dnptrs + 1;
        auto printer1 = new ArgPrinter(dnptrs, "dnptrs");
        printer1->set_len(ndnptrs);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(lastdnptr, "lastdnptr"));

        auto abii_ret = real_ns_name_compress(src, dst, dstsiz, dnptrs, lastdnptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ns_name_compress, abii_ret)
    return real_ns_name_compress(src, dst, dstsiz, dnptrs, lastdnptr);
}

static int (*real_ns_name_skip)(const unsigned char**, const unsigned char*) __THROW = nullptr;

extern "C" int abii_ns_name_skip(const unsigned char** ptrptr, const unsigned char* eom) __THROW
{
    OVERRIDE_PREFIX(ns_name_skip)
        pre_fmtd_str pi_str = "ns_name_skip(ptrptr, eom)";
        abii_args->push_func(new ArgPrinter(pi_str));

        // const auto len = eom - *ptrptr;
        auto printer = new ArgPrinter(ptrptr, "ptrptr");
        // TODO: This is not implemented yet
        // printer->set_len_with_depth(len, 1);
        abii_args->push_arg(printer);

        constexpr auto zerolen = 0;
        auto printer1 = new ArgPrinter(eom, "eom");
        printer1->set_len(zerolen);
        abii_args->push_arg(printer1);

        auto abii_ret = real_ns_name_skip(ptrptr, eom);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ns_name_skip, abii_ret)
    return real_ns_name_skip(ptrptr, eom);
}
}
