//
// Created by Trent Tanchin on 7/4/26.
//

#include <abii/libabii.h>

#include "bits/types/__mbstate_t.h"

namespace abii
{
static size_t (*real_mbrtoc8)(char8_t*, const char*, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_mbrtoc8(char8_t* pc8, const char* s, size_t n, mbstate_t* p) __THROW
{
    OVERRIDE_PREFIX(mbrtoc8)
        pre_fmtd_str pi_str = "mbrtoc8(__pc8, __s, __n, __p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pc8, "__pc8"));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(p, "__p"));

        auto abii_ret = real_mbrtoc8(pc8, s, n, p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbrtoc8, abii_ret)
    return real_mbrtoc8(pc8, s, n, p);
}

static size_t (*real_c8rtomb)(char*, char8_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_c8rtomb(char* s, char8_t c8, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(c8rtomb)
        pre_fmtd_str pi_str = "c8rtomb(__s, __c8, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        abii_args->push_arg(new ArgPrinter(c8, "__c8"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_c8rtomb(s, c8, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(c8rtomb, abii_ret)
    return real_c8rtomb(s, c8, ps);
}

static size_t (*real_mbrtoc16)(char16_t*, const char*, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_mbrtoc16(char16_t* pc16, const char* s, size_t n, mbstate_t* p) __THROW
{
    OVERRIDE_PREFIX(mbrtoc16)
        pre_fmtd_str pi_str = "mbrtoc16(__pc16, __s, __n, __p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pc16, "__pc16"));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(p, "__p"));

        auto abii_ret = real_mbrtoc16(pc16, s, n, p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbrtoc16, abii_ret)
    return real_mbrtoc16(pc16, s, n, p);
}

static size_t (*real_c16rtomb)(char*, char16_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_c16rtomb(char* s, char16_t c16, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(c16rtomb)
        pre_fmtd_str pi_str = "c16rtomb(__s, __c16, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        abii_args->push_arg(new ArgPrinter(c16, "__c16"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_c16rtomb(s, c16, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(c16rtomb, abii_ret)
    return real_c16rtomb(s, c16, ps);
}

static size_t (*real_mbrtoc32)(char32_t*, const char*, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_mbrtoc32(char32_t* pc32, const char* s, size_t n, mbstate_t* p) __THROW
{
    OVERRIDE_PREFIX(mbrtoc32)
        pre_fmtd_str pi_str = "mbrtoc32(__pc32, __s, __n, __p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pc32, "__pc32"));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(p, "__p"));

        auto abii_ret = real_mbrtoc32(pc32, s, n, p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbrtoc32, abii_ret)
    return real_mbrtoc32(pc32, s, n, p);
}

static size_t (*real_c32rtomb)(char*, char32_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_c32rtomb(char* s, char32_t c32, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(c32rtomb)
        pre_fmtd_str pi_str = "c32rtomb(__s, __c32, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        abii_args->push_arg(new ArgPrinter(c32, "__c32"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_c32rtomb(s, c32, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(c32rtomb, abii_ret)
    return real_c32rtomb(s, c32, ps);
}
}
