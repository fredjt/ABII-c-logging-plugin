//
// Created by Trent Tanchin on 7/3/26.
//

#include <abii/libabii.h>

#include "bits/types/__locale_t.h"

namespace abii
{
static __attribute_pure__ __nonnull((1, 2)) int (*real_bcmp)(const void*, const void*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_bcmp(const void* s1, const void* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(bcmp)
        pre_fmtd_str pi_str = "bcmp(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s1, "__s1");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(s2, "__s2");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_bcmp(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(bcmp, abii_ret)
    return real_bcmp(s1, s2, n);
}

static __nonnull((1, 2)) void (*real_bcopy)(const void*, void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2))
void abii_bcopy(const void* src, void* dest, size_t n) __THROW
{
    OVERRIDE_PREFIX(bcopy)
        pre_fmtd_str pi_str = "bcopy(__src, __dest, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(src, "__src");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(dest, "__dest");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        real_bcopy(src, dest, n);
    OVERRIDE_SUFFIX(bcopy,)
    return real_bcopy(src, dest, n);
}

static __nonnull((1)) void (*real_bzero)(void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_bzero(void* s, size_t n) __THROW
{
    OVERRIDE_PREFIX(bzero)
        pre_fmtd_str pi_str = "bzero(__s, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        real_bzero(s, n);
    OVERRIDE_SUFFIX(bzero,)
    return real_bzero(s, n);
}

static __attribute_pure__ __nonnull((1)) char* (*real_index)(const char*, int) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1))
char* abii_index(const char* s, int c) __THROW
{
    OVERRIDE_PREFIX(index)
        pre_fmtd_str pi_str = "index(__s, __c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_index(s, c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(index, abii_ret)
    return real_index(s, c);
}

static __attribute_pure__ __nonnull((1)) char* (*real_rindex)(const char*, int) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1))
char* abii_rindex(const char* s, int c) __THROW
{
    OVERRIDE_PREFIX(rindex)
        pre_fmtd_str pi_str = "rindex(__s, __c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_rindex(s, c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rindex, abii_ret)
    return real_rindex(s, c);
}

static __attribute_const__ int (*real_ffs)(int) __THROW = nullptr;

extern "C" __attribute_const__
int abii_ffs(int i) __THROW
{
    OVERRIDE_PREFIX(ffs)
        pre_fmtd_str pi_str = "ffs(__i)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(i, "__i"));

        auto abii_ret = real_ffs(i);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ffs, abii_ret)
    return real_ffs(i);
}

static __attribute_const__ int (*real_ffsl)(long int) __THROW = nullptr;

extern "C" __attribute_const__
int abii_ffsl(long int l) __THROW
{
    OVERRIDE_PREFIX(ffsl)
        pre_fmtd_str pi_str = "ffsl(__l)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(l, "__l"));

        auto abii_ret = real_ffsl(l);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ffsl, abii_ret)
    return real_ffsl(l);
}

static __attribute_const__ int (*real_ffsll)(long long int) __THROW = nullptr;

extern "C" __attribute_const__
int abii_ffsll(long long int ll) __THROW
{
    OVERRIDE_PREFIX(ffsll)
        pre_fmtd_str pi_str = "ffsll(__ll)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ll, "__ll"));

        auto abii_ret = real_ffsll(ll);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ffsll, abii_ret)
    return real_ffsll(ll);
}

static __attribute_pure__ __nonnull((1, 2)) int (*real_strcasecmp)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_strcasecmp(const char* s1, const char* s2) __THROW
{
    OVERRIDE_PREFIX(strcasecmp)
        pre_fmtd_str pi_str = "strcasecmp(__s1, __s2)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));

        auto abii_ret = real_strcasecmp(s1, s2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strcasecmp, abii_ret)
    return real_strcasecmp(s1, s2);
}

static __attribute_pure__ __nonnull((1, 2)) int (*real_strncasecmp)(const char*, const char*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_strncasecmp(const char* s1, const char* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(strncasecmp)
        pre_fmtd_str pi_str = "strncasecmp(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_strncasecmp(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strncasecmp, abii_ret)
    return real_strncasecmp(s1, s2, n);
}

static __attribute_pure__ __nonnull((1, 2, 3))
int (*real_strcasecmp_l)(const char*, const char*, locale_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2, 3))
int abii_strcasecmp_l(const char* s1, const char* s2, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strcasecmp_l)
        pre_fmtd_str pi_str = "strcasecmp_l(__s1, __s2, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strcasecmp_l(s1, s2, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strcasecmp_l, abii_ret)
    return real_strcasecmp_l(s1, s2, loc);
}

static __attribute_pure__ __nonnull((1, 2, 4))
int (*real_strncasecmp_l)(const char*, const char*, size_t, locale_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2, 4))
int abii_strncasecmp_l(const char* s1, const char* s2, size_t n, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strncasecmp_l)
        pre_fmtd_str pi_str = "strncasecmp_l(__s1, __s2, __n, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strncasecmp_l(s1, s2, n, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strncasecmp_l, abii_ret)
    return real_strncasecmp_l(s1, s2, n, loc);
}
}
