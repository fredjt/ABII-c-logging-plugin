//
// Created by Trent Tanchin on 9/26/26.
//

#include "wchar.h"

#include "bits/types/struct_tm.h"
#include "bits/types/__locale_t.h"
#include "bits/types/__mbstate_t.h"

namespace abii
{
static __nonnull((1, 2)) wchar_t* (*real_wcscpy)(wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
wchar_t* abii_wcscpy(wchar_t* dest, const wchar_t* src) __THROW
{
    OVERRIDE_PREFIX(wcscpy)
        pre_fmtd_str pi_str = "wcscpy(__dest, __src)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));

        auto abii_ret = real_wcscpy(dest, src);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcscpy, abii_ret)
    return real_wcscpy(dest, src);
}

static __nonnull((1, 2)) wchar_t* (*real_wcsncpy)(wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2))
wchar_t* abii_wcsncpy(wchar_t* dest, const wchar_t* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcsncpy)
        pre_fmtd_str pi_str = "wcsncpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcsncpy(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsncpy, abii_ret)
    return real_wcsncpy(dest, src, n);
}

static __nonnull((1, 2)) __attr_access((__write_only__, 1, 3))
size_t (*real_wcslcpy)(wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2)) __attr_access((__write_only__, 1, 3))
size_t abii_wcslcpy(wchar_t* dest, const wchar_t* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcslcpy)
        pre_fmtd_str pi_str = "wcslcpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcslcpy(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcslcpy, abii_ret)
    return real_wcslcpy(dest, src, n);
}

static __nonnull((1, 2)) __attr_access((__read_write__, 1, 3))
size_t (*real_wcslcat)(wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2)) __attr_access((__read_write__, 1, 3))
size_t abii_wcslcat(wchar_t* dest, const wchar_t* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcslcat)
        pre_fmtd_str pi_str = "wcslcat(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcslcat(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcslcat, abii_ret)
    return real_wcslcat(dest, src, n);
}

static __nonnull((1, 2)) wchar_t* (*real_wcscat)(wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
wchar_t* abii_wcscat(wchar_t* dest, const wchar_t* src) __THROW
{
    OVERRIDE_PREFIX(wcscat)
        pre_fmtd_str pi_str = "wcscat(__dest, __src)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));

        auto abii_ret = real_wcscat(dest, src);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcscat, abii_ret)
    return real_wcscat(dest, src);
}

static __nonnull((1, 2)) wchar_t* (*real_wcsncat)(wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2))
wchar_t* abii_wcsncat(wchar_t* dest, const wchar_t* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcsncat)
        pre_fmtd_str pi_str = "wcsncat(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcsncat(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsncat, abii_ret)
    return real_wcsncat(dest, src, n);
}

static __attribute_pure__ __nonnull((1, 2)) int (*real_wcscmp)(const wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_wcscmp(const wchar_t* s1, const wchar_t* s2) __THROW
{
    OVERRIDE_PREFIX(wcscmp)
        pre_fmtd_str pi_str = "wcscmp(__s1, __s2)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));

        auto abii_ret = real_wcscmp(s1, s2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcscmp, abii_ret)
    return real_wcscmp(s1, s2);
}

static __attribute_pure__ __nonnull((1, 2))
int (*real_wcsncmp)(const wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_wcsncmp(const wchar_t* s1, const wchar_t* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcsncmp)
        pre_fmtd_str pi_str = "wcsncmp(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcsncmp(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsncmp, abii_ret)
    return real_wcsncmp(s1, s2, n);
}

static int (*real_wcscasecmp)(const wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" int abii_wcscasecmp(const wchar_t* s1, const wchar_t* s2) __THROW
{
    OVERRIDE_PREFIX(wcscasecmp)
        pre_fmtd_str pi_str = "wcscasecmp(__s1, __s2)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));

        auto abii_ret = real_wcscasecmp(s1, s2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcscasecmp, abii_ret)
    return real_wcscasecmp(s1, s2);
}

static int (*real_wcsncasecmp)(const wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" int abii_wcsncasecmp(const wchar_t* s1, const wchar_t* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcsncasecmp)
        pre_fmtd_str pi_str = "wcsncasecmp(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcsncasecmp(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsncasecmp, abii_ret)
    return real_wcsncasecmp(s1, s2, n);
}

static int (*real_wcscasecmp_l)(const wchar_t*, const wchar_t*, locale_t) __THROW = nullptr;

extern "C" int abii_wcscasecmp_l(const wchar_t* s1, const wchar_t* s2, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcscasecmp_l)
        pre_fmtd_str pi_str = "wcscasecmp_l(__s1, __s2, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcscasecmp_l(s1, s2, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcscasecmp_l, abii_ret)
    return real_wcscasecmp_l(s1, s2, loc);
}

static int (*real_wcsncasecmp_l)(const wchar_t*, const wchar_t*, size_t, locale_t) __THROW = nullptr;

extern "C" int abii_wcsncasecmp_l(const wchar_t* s1, const wchar_t* s2, size_t n, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcsncasecmp_l)
        pre_fmtd_str pi_str = "wcsncasecmp_l(__s1, __s2, __n, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcsncasecmp_l(s1, s2, n, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsncasecmp_l, abii_ret)
    return real_wcsncasecmp_l(s1, s2, n, loc);
}

static int (*real_wcscoll)(const wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" int abii_wcscoll(const wchar_t* s1, const wchar_t* s2) __THROW
{
    OVERRIDE_PREFIX(wcscoll)
        pre_fmtd_str pi_str = "wcscoll(__s1, __s2)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));

        auto abii_ret = real_wcscoll(s1, s2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcscoll, abii_ret)
    return real_wcscoll(s1, s2);
}

static size_t (*real_wcsxfrm)(wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" size_t abii_wcsxfrm(wchar_t* s1, const wchar_t* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcsxfrm)
        pre_fmtd_str pi_str = "wcsxfrm(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcsxfrm(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsxfrm, abii_ret)
    return real_wcsxfrm(s1, s2, n);
}

static int (*real_wcscoll_l)(const wchar_t*, const wchar_t*, locale_t) __THROW = nullptr;

extern "C" int abii_wcscoll_l(const wchar_t* s1, const wchar_t* s2, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcscoll_l)
        pre_fmtd_str pi_str = "wcscoll_l(__s1, __s2, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcscoll_l(s1, s2, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcscoll_l, abii_ret)
    return real_wcscoll_l(s1, s2, loc);
}

static size_t (*real_wcsxfrm_l)(wchar_t*, const wchar_t*, size_t, locale_t) __THROW = nullptr;

extern "C" size_t abii_wcsxfrm_l(wchar_t* s1, const wchar_t* s2, size_t n, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcsxfrm_l)
        pre_fmtd_str pi_str = "wcsxfrm_l(__s1, __s2, __n, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcsxfrm_l(s1, s2, n, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsxfrm_l, abii_ret)
    return real_wcsxfrm_l(s1, s2, n, loc);
}

static __attribute_malloc__ __attr_dealloc_free wchar_t* (*real_wcsdup)(const wchar_t*) __THROW = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_free
wchar_t* abii_wcsdup(const wchar_t* s) __THROW
{
    OVERRIDE_PREFIX(wcsdup)
        pre_fmtd_str pi_str = "wcsdup(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_wcsdup(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsdup, abii_ret)
    return real_wcsdup(s);
}

static __attribute_pure__ wchar_t* (*real_wcschr)(const wchar_t*, wchar_t) __THROW = nullptr;

extern "C" __attribute_pure__
wchar_t* abii_wcschr(const wchar_t* wcs, wchar_t wc) __THROW
{
    OVERRIDE_PREFIX(wcschr)
        pre_fmtd_str pi_str = "wcschr(__wcs, __wc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wcs, "__wcs"));
        abii_args->push_arg(new ArgPrinter(wc, "__wc"));

        auto abii_ret = real_wcschr(wcs, wc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcschr, abii_ret)
    return real_wcschr(wcs, wc);
}

static __attribute_pure__ wchar_t* (*real_wcsrchr)(const wchar_t*, wchar_t) __THROW = nullptr;

extern "C" __attribute_pure__
wchar_t* abii_wcsrchr(const wchar_t* wcs, wchar_t wc) __THROW
{
    OVERRIDE_PREFIX(wcsrchr)
        pre_fmtd_str pi_str = "wcsrchr(__wcs, __wc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wcs, "__wcs"));
        abii_args->push_arg(new ArgPrinter(wc, "__wc"));

        auto abii_ret = real_wcsrchr(wcs, wc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsrchr, abii_ret)
    return real_wcsrchr(wcs, wc);
}

static __attribute_pure__ wchar_t* (*real_wcschrnul)(const wchar_t*, wchar_t) __THROW = nullptr;

extern "C" __attribute_pure__
wchar_t* abii_wcschrnul(const wchar_t* s, wchar_t wc) __THROW
{
    OVERRIDE_PREFIX(wcschrnul)
        pre_fmtd_str pi_str = "wcschrnul(__s, __wc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(wc, "__wc"));

        auto abii_ret = real_wcschrnul(s, wc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcschrnul, abii_ret)
    return real_wcschrnul(s, wc);
}

static __attribute_pure__ size_t (*real_wcscspn)(const wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" __attribute_pure__
size_t abii_wcscspn(const wchar_t* wcs, const wchar_t* reject) __THROW
{
    OVERRIDE_PREFIX(wcscspn)
        pre_fmtd_str pi_str = "wcscspn(__wcs, __reject)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wcs, "__wcs"));
        abii_args->push_arg(new ArgPrinter(reject, "__reject"));

        auto abii_ret = real_wcscspn(wcs, reject);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcscspn, abii_ret)
    return real_wcscspn(wcs, reject);
}

static __attribute_pure__ size_t (*real_wcsspn)(const wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" __attribute_pure__
size_t abii_wcsspn(const wchar_t* wcs, const wchar_t* accept) __THROW
{
    OVERRIDE_PREFIX(wcsspn)
        pre_fmtd_str pi_str = "wcsspn(__wcs, __accept)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wcs, "__wcs"));
        abii_args->push_arg(new ArgPrinter(accept, "__accept"));

        auto abii_ret = real_wcsspn(wcs, accept);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsspn, abii_ret)
    return real_wcsspn(wcs, accept);
}

static __attribute_pure__ wchar_t* (*real_wcspbrk)(const wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" __attribute_pure__
wchar_t* abii_wcspbrk(const wchar_t* wcs, const wchar_t* accept) __THROW
{
    OVERRIDE_PREFIX(wcspbrk)
        pre_fmtd_str pi_str = "wcspbrk(__wcs, __accept)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wcs, "__wcs"));
        abii_args->push_arg(new ArgPrinter(accept, "__accept"));

        auto abii_ret = real_wcspbrk(wcs, accept);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcspbrk, abii_ret)
    return real_wcspbrk(wcs, accept);
}

static __attribute_pure__ wchar_t* (*real_wcsstr)(const wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" __attribute_pure__
wchar_t* abii_wcsstr(const wchar_t* haystack, const wchar_t* needle) __THROW
{
    OVERRIDE_PREFIX(wcsstr)
        pre_fmtd_str pi_str = "wcsstr(__haystack, __needle)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(haystack, "__haystack"));
        abii_args->push_arg(new ArgPrinter(needle, "__needle"));

        auto abii_ret = real_wcsstr(haystack, needle);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsstr, abii_ret)
    return real_wcsstr(haystack, needle);
}

static wchar_t* (*real_wcstok)(wchar_t*, const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" wchar_t* abii_wcstok(wchar_t* s, const wchar_t* delim, wchar_t** ptr) __THROW
{
    OVERRIDE_PREFIX(wcstok)
        pre_fmtd_str pi_str = "wcstok(__s, __delim, __ptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(delim, "__delim"));
        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));

        auto abii_ret = real_wcstok(s, delim, ptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstok, abii_ret)
    return real_wcstok(s, delim, ptr);
}

static __attribute_pure__ size_t (*real_wcslen)(const wchar_t*) __THROW = nullptr;

extern "C" __attribute_pure__
size_t abii_wcslen(const wchar_t* s) __THROW
{
    OVERRIDE_PREFIX(wcslen)
        pre_fmtd_str pi_str = "wcslen(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_wcslen(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcslen, abii_ret)
    return real_wcslen(s);
}

static __attribute_pure__ wchar_t* (*real_wcswcs)(const wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" __attribute_pure__
wchar_t* abii_wcswcs(const wchar_t* haystack, const wchar_t* needle) __THROW
{
    OVERRIDE_PREFIX(wcswcs)
        pre_fmtd_str pi_str = "wcswcs(__haystack, __needle)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(haystack, "__haystack"));
        abii_args->push_arg(new ArgPrinter(needle, "__needle"));

        auto abii_ret = real_wcswcs(haystack, needle);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcswcs, abii_ret)
    return real_wcswcs(haystack, needle);
}

static __attribute_pure__ size_t (*real_wcsnlen)(const wchar_t*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__
size_t abii_wcsnlen(const wchar_t* s, size_t maxlen) __THROW
{
    OVERRIDE_PREFIX(wcsnlen)
        pre_fmtd_str pi_str = "wcsnlen(__s, __maxlen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(maxlen, "__maxlen"));

        auto abii_ret = real_wcsnlen(s, maxlen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsnlen, abii_ret)
    return real_wcsnlen(s, maxlen);
}

static __attribute_pure__ wchar_t* (*real_wmemchr)(const wchar_t*, wchar_t, size_t) __THROW = nullptr;

extern "C" __attribute_pure__
wchar_t* abii_wmemchr(const wchar_t* s, wchar_t c, size_t n) __THROW
{
    OVERRIDE_PREFIX(wmemchr)
        pre_fmtd_str pi_str = "wmemchr(__s, __c, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wmemchr(s, c, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wmemchr, abii_ret)
    return real_wmemchr(s, c, n);
}

static __attribute_pure__ int (*real_wmemcmp)(const wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__
int abii_wmemcmp(const wchar_t* s1, const wchar_t* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(wmemcmp)
        pre_fmtd_str pi_str = "wmemcmp(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s1, "__s1");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(s2, "__s2");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wmemcmp(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wmemcmp, abii_ret)
    return real_wmemcmp(s1, s2, n);
}

static wchar_t* (*real_wmemcpy)(wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" wchar_t* abii_wmemcpy(wchar_t* s1, const wchar_t* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(wmemcpy)
        pre_fmtd_str pi_str = "wmemcpy(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s1, "__s1");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(s2, "__s2");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wmemcpy(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wmemcpy, abii_ret)
    return real_wmemcpy(s1, s2, n);
}

static wchar_t* (*real_wmemmove)(wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" wchar_t* abii_wmemmove(wchar_t* s1, const wchar_t* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(wmemmove)
        pre_fmtd_str pi_str = "wmemmove(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s1, "__s1");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(s2, "__s2");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wmemmove(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wmemmove, abii_ret)
    return real_wmemmove(s1, s2, n);
}

static wchar_t* (*real_wmemset)(wchar_t*, wchar_t, size_t) __THROW = nullptr;

extern "C" wchar_t* abii_wmemset(wchar_t* s, wchar_t c, size_t n) __THROW
{
    OVERRIDE_PREFIX(wmemset)
        pre_fmtd_str pi_str = "wmemset(__s, __c, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wmemset(s, c, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wmemset, abii_ret)
    return real_wmemset(s, c, n);
}

static wchar_t* (*real_wmempcpy)(wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" wchar_t* abii_wmempcpy(wchar_t* s1, const wchar_t* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(wmempcpy)
        pre_fmtd_str pi_str = "wmempcpy(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s1, "__s1");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(s2, "__s2");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wmempcpy(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wmempcpy, abii_ret)
    return real_wmempcpy(s1, s2, n);
}

static wint_t (*real_btowc)(int) __THROW = nullptr;

extern "C" wint_t abii_btowc(int c) __THROW
{
    OVERRIDE_PREFIX(btowc)
        pre_fmtd_str pi_str = "btowc(__c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_btowc(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(btowc, abii_ret)
    return real_btowc(c);
}

static int (*real_wctob)(wint_t) __THROW = nullptr;

extern "C" int abii_wctob(wint_t c) __THROW
{
    OVERRIDE_PREFIX(wctob)
        pre_fmtd_str pi_str = "wctob(__c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_wctob(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wctob, abii_ret)
    return real_wctob(c);
}

static __attribute_pure__ int (*real_mbsinit)(const mbstate_t*) __THROW = nullptr;

extern "C" __attribute_pure__
int abii_mbsinit(const mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(mbsinit)
        pre_fmtd_str pi_str = "mbsinit(__ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_mbsinit(ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbsinit, abii_ret)
    return real_mbsinit(ps);
}

static size_t (*real_mbrtowc)(wchar_t*, const char*, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_mbrtowc(wchar_t* pwc, const char* s, size_t n, mbstate_t* p) __THROW
{
    OVERRIDE_PREFIX(mbrtowc)
        pre_fmtd_str pi_str = "mbrtowc(__pwc, __s, __n, __p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pwc, "__pwc"));
        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(p, "__p"));

        auto abii_ret = real_mbrtowc(pwc, s, n, p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbrtowc, abii_ret)
    return real_mbrtowc(pwc, s, n, p);
}

static size_t (*real_wcrtomb)(char*, wchar_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_wcrtomb(char* s, wchar_t wc, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(wcrtomb)
        pre_fmtd_str pi_str = "wcrtomb(__s, __wc, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_wcrtomb(s, wc, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcrtomb, abii_ret)
    return real_wcrtomb(s, wc, ps);
}

static size_t (*real___mbrlen)(const char*, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii___mbrlen(const char* s, size_t n, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(__mbrlen)
        pre_fmtd_str pi_str = "__mbrlen(__s, __n, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real___mbrlen(s, n, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__mbrlen, abii_ret)
    return real___mbrlen(s, n, ps);
}

static size_t (*real_mbrlen)(const char*, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_mbrlen(const char* s, size_t n, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(mbrlen)
        pre_fmtd_str pi_str = "mbrlen(__s, __n, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_mbrlen(s, n, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbrlen, abii_ret)
    return real_mbrlen(s, n, ps);
}

static size_t (*real_mbsrtowcs)(wchar_t*, const char**, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_mbsrtowcs(wchar_t* dst, const char** src, size_t len, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(mbsrtowcs)
        pre_fmtd_str pi_str = "mbsrtowcs(__dst, __src, __len, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dst, "__dst"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_mbsrtowcs(dst, src, len, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbsrtowcs, abii_ret)
    return real_mbsrtowcs(dst, src, len, ps);
}

static size_t (*real_wcsrtombs)(char*, const wchar_t**, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_wcsrtombs(char* dst, const wchar_t** src, size_t len, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(wcsrtombs)
        pre_fmtd_str pi_str = "wcsrtombs(__dst, __src, __len, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dst, "__dst"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_wcsrtombs(dst, src, len, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsrtombs, abii_ret)
    return real_wcsrtombs(dst, src, len, ps);
}

static size_t (*real_mbsnrtowcs)(wchar_t*, const char**, size_t, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_mbsnrtowcs(wchar_t* dst, const char** src, size_t nmc, size_t len, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(mbsnrtowcs)
        pre_fmtd_str pi_str = "mbsnrtowcs(__dst, __src, __nmc, __len, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dst, "__dst"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(nmc, "__nmc"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_mbsnrtowcs(dst, src, nmc, len, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbsnrtowcs, abii_ret)
    return real_mbsnrtowcs(dst, src, nmc, len, ps);
}

static size_t (*real_wcsnrtombs)(char*, const wchar_t**, size_t, size_t, mbstate_t*) __THROW = nullptr;

extern "C" size_t abii_wcsnrtombs(char* dst, const wchar_t** src, size_t nwc, size_t len, mbstate_t* ps) __THROW
{
    OVERRIDE_PREFIX(wcsnrtombs)
        pre_fmtd_str pi_str = "wcsnrtombs(__dst, __src, __nwc, __len, __ps)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dst, "__dst"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(nwc, "__nwc"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));
        abii_args->push_arg(new ArgPrinter(ps, "__ps"));

        auto abii_ret = real_wcsnrtombs(dst, src, nwc, len, ps);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsnrtombs, abii_ret)
    return real_wcsnrtombs(dst, src, nwc, len, ps);
}

static int (*real_wcwidth)(wchar_t) __THROW = nullptr;

extern "C" int abii_wcwidth(wchar_t c) __THROW
{
    OVERRIDE_PREFIX(wcwidth)
        pre_fmtd_str pi_str = "wcwidth(__c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_wcwidth(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcwidth, abii_ret)
    return real_wcwidth(c);
}

static int (*real_wcswidth)(const wchar_t*, size_t) __THROW = nullptr;

extern "C" int abii_wcswidth(const wchar_t* s, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcswidth)
        pre_fmtd_str pi_str = "wcswidth(__s, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcswidth(s, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcswidth, abii_ret)
    return real_wcswidth(s, n);
}

static double (*real_wcstod)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" double abii_wcstod(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstod)
        pre_fmtd_str pi_str = "wcstod(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstod(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstod, abii_ret)
    return real_wcstod(nptr, endptr);
}

static float (*real_wcstof)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" float abii_wcstof(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstof)
        pre_fmtd_str pi_str = "wcstof(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstof(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof, abii_ret)
    return real_wcstof(nptr, endptr);
}

static long double (*real_wcstold)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" long double abii_wcstold(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstold)
        pre_fmtd_str pi_str = "wcstold(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstold(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstold, abii_ret)
    return real_wcstold(nptr, endptr);
}

#if __HAVE_FLOAT16
static _Float16 (*real_wcstof16)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" _Float16 abii_wcstof16(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstof16)
        pre_fmtd_str pi_str = "wcstof16(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstof16(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof16, abii_ret)
    return real_wcstof16(nptr, endptr);
}
#endif

#if __HAVE_FLOAT32
static _Float32 (*real_wcstof32)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" _Float32 abii_wcstof32(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstof32)
        pre_fmtd_str pi_str = "wcstof32(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstof32(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof32, abii_ret)
    return real_wcstof32(nptr, endptr);
}
#endif

#if __HAVE_FLOAT64
static _Float64 (*real_wcstof64)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" _Float64 abii_wcstof64(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstof64)
        pre_fmtd_str pi_str = "wcstof64(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstof64(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof64, abii_ret)
    return real_wcstof64(nptr, endptr);
}
#endif

#if __HAVE_FLOAT128
static _Float128 (*real_wcstof128)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" _Float128 abii_wcstof128(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstof128)
        pre_fmtd_str pi_str = "wcstof128(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstof128(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof128, abii_ret)
    return real_wcstof128(nptr, endptr);
}
#endif

#if __HAVE_FLOAT32X
static _Float32x (*real_wcstof32x)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" _Float32x abii_wcstof32x(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstof32x)
        pre_fmtd_str pi_str = "wcstof32x(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstof32x(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof32x, abii_ret)
    return real_wcstof32x(nptr, endptr);
}
#endif

#if __HAVE_FLOAT64X
static _Float64x (*real_wcstof64x)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" _Float64x abii_wcstof64x(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstof64x)
        pre_fmtd_str pi_str = "wcstof64x(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstof64x(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof64x, abii_ret)
    return real_wcstof64x(nptr, endptr);
}
#endif

#if __HAVE_FLOAT128X
static _Float128x (*real_wcstof128x)(const wchar_t*, wchar_t**) __THROW = nullptr;

extern "C" _Float128x wcstof128x(const wchar_t* nptr, wchar_t** endptr) __THROW
{
    OVERRIDE_PREFIX(wcstof128x)
        pre_fmtd_str pi_str = "wcstof128x(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_wcstof128x(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof128x, abii_ret)
    return real_wcstof128x(nptr, endptr);
}
#endif

static long int (*real_wcstol)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" long int abii_wcstol(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(wcstol)
        pre_fmtd_str pi_str = "wcstol(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_wcstol(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstol, abii_ret)
    return real_wcstol(nptr, endptr, base);
}

static unsigned long int (*real_wcstoul)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" unsigned long int abii_wcstoul(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(wcstoul)
        pre_fmtd_str pi_str = "wcstoul(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_wcstoul(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstoul, abii_ret)
    return real_wcstoul(nptr, endptr, base);
}

static long long int (*real_wcstoll)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" long long int abii_wcstoll(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(wcstoll)
        pre_fmtd_str pi_str = "wcstoll(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_wcstoll(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstoll, abii_ret)
    return real_wcstoll(nptr, endptr, base);
}

static unsigned long long int (*real_wcstoull)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" unsigned long long int abii_wcstoull(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(wcstoull)
        pre_fmtd_str pi_str = "wcstoull(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_wcstoull(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstoull, abii_ret)
    return real_wcstoull(nptr, endptr, base);
}

static long long int (*real_wcstoq)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" long long int abii_wcstoq(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(wcstoq)
        pre_fmtd_str pi_str = "wcstoq(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_wcstoq(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstoq, abii_ret)
    return real_wcstoq(nptr, endptr, base);
}

static unsigned long long int (*real_wcstouq)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" unsigned long long int abii_wcstouq(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(wcstouq)
        pre_fmtd_str pi_str = "wcstouq(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_wcstouq(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstouq, abii_ret)
    return real_wcstouq(nptr, endptr, base);
}

static long int (*real___isoc23_wcstol)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" long int abii___isoc23_wcstol(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstol)
        pre_fmtd_str pi_str = "__isoc23_wcstol(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_wcstol(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_wcstol, abii_ret)
    return real___isoc23_wcstol(nptr, endptr, base);
}

static unsigned long int (*real___isoc23_wcstoul)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" unsigned long int abii___isoc23_wcstoul(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstoul)
        pre_fmtd_str pi_str = "__isoc23_wcstoul(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_wcstoul(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_wcstoul, abii_ret)
    return real___isoc23_wcstoul(nptr, endptr, base);
}

static long long int (*real___isoc23_wcstoll)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" long long int abii___isoc23_wcstoll(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstoll)
        pre_fmtd_str pi_str = "__isoc23_wcstoll(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_wcstoll(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_wcstoll, abii_ret)
    return real___isoc23_wcstoll(nptr, endptr, base);
}

static unsigned long long int (*real___isoc23_wcstoull)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" unsigned long long int abii___isoc23_wcstoull(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstoull)
        pre_fmtd_str pi_str = "__isoc23_wcstoull(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_wcstoull(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_wcstoull, abii_ret)
    return real___isoc23_wcstoull(nptr, endptr, base);
}

static long int (*real_wcstol_l)(const wchar_t*, wchar_t**, int, locale_t) __THROW = nullptr;

extern "C" long int abii_wcstol_l(const wchar_t* nptr, wchar_t** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstol_l)
        pre_fmtd_str pi_str = "wcstol_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstol_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstol_l, abii_ret)
    return real_wcstol_l(nptr, endptr, base, loc);
}

static unsigned long int (*real_wcstoul_l)(const wchar_t*, wchar_t**, int, locale_t) __THROW = nullptr;

extern "C" unsigned long int abii_wcstoul_l(const wchar_t* nptr, wchar_t** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstoul_l)
        pre_fmtd_str pi_str = "wcstoul_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstoul_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstoul_l, abii_ret)
    return real_wcstoul_l(nptr, endptr, base, loc);
}

static long long int (*real_wcstoll_l)(const wchar_t*, wchar_t**, int, locale_t) __THROW = nullptr;

extern "C" long long int abii_wcstoll_l(const wchar_t* nptr, wchar_t** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstoll_l)
        pre_fmtd_str pi_str = "wcstoll_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstoll_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstoll_l, abii_ret)
    return real_wcstoll_l(nptr, endptr, base, loc);
}

static unsigned long long int (*real_wcstoull_l)(const wchar_t*, wchar_t**, int, locale_t) __THROW = nullptr;

extern "C" unsigned long long int abii_wcstoull_l(const wchar_t* nptr, wchar_t** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstoull_l)
        pre_fmtd_str pi_str = "wcstoull_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstoull_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstoull_l, abii_ret)
    return real_wcstoull_l(nptr, endptr, base, loc);
}

static long int (*real___isoc23_wcstol_l)(const wchar_t*, wchar_t**, int, locale_t) __THROW = nullptr;

extern "C" long int abii___isoc23_wcstol_l(const wchar_t* nptr, wchar_t** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstol_l)
        pre_fmtd_str pi_str = "__isoc23_wcstol_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real___isoc23_wcstol_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_wcstol_l, abii_ret)
    return real___isoc23_wcstol_l(nptr, endptr, base, loc);
}

static unsigned long int (*real___isoc23_wcstoul_l)(const wchar_t*, wchar_t**, int, locale_t) __THROW = nullptr;

extern "C" unsigned long int abii___isoc23_wcstoul_l(const wchar_t* nptr, wchar_t** endptr, int base,
                                                     locale_t loc) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstoul_l)
        pre_fmtd_str pi_str = "__isoc23_wcstoul_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real___isoc23_wcstoul_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_wcstoul_l, abii_ret)
    return real___isoc23_wcstoul_l(nptr, endptr, base, loc);
}

static long long int (*real___isoc23_wcstoll_l)(const wchar_t*, wchar_t**, int, locale_t) __THROW = nullptr;

extern "C" long long int abii___isoc23_wcstoll_l(const wchar_t* nptr, wchar_t** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstoll_l)
        pre_fmtd_str pi_str = "__isoc23_wcstoll_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real___isoc23_wcstoll_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_wcstoll_l, abii_ret)
    return real___isoc23_wcstoll_l(nptr, endptr, base, loc);
}

static unsigned long long int (*real___isoc23_wcstoull_l)(const wchar_t*, wchar_t**, int, locale_t) __THROW = nullptr;

extern "C" unsigned long long int abii___isoc23_wcstoull_l(const wchar_t* nptr, wchar_t** endptr, int base,
                                                           locale_t loc) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstoull_l)
        pre_fmtd_str pi_str = "__isoc23_wcstoull_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real___isoc23_wcstoull_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_wcstoull_l, abii_ret)
    return real___isoc23_wcstoull_l(nptr, endptr, base, loc);
}

static double (*real_wcstod_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" double abii_wcstod_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstod_l)
        pre_fmtd_str pi_str = "wcstod_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstod_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstod_l, abii_ret)
    return real_wcstod_l(nptr, endptr, loc);
}

static float (*real_wcstof_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" float abii_wcstof_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstof_l)
        pre_fmtd_str pi_str = "wcstof_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstof_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof_l, abii_ret)
    return real_wcstof_l(nptr, endptr, loc);
}

static long double (*real_wcstold_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" long double abii_wcstold_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstold_l)
        pre_fmtd_str pi_str = "wcstold_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstold_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstold_l, abii_ret)
    return real_wcstold_l(nptr, endptr, loc);
}

#if __HAVE_FLOAT16
static _Float16 (*real_wcstof16_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" _Float16 abii_wcstof16_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstof16_l)
        pre_fmtd_str pi_str = "wcstof16_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstof16_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof16_l, abii_ret)
    return real_wcstof16_l(nptr, endptr, loc);
}
#endif

#if __HAVE_FLOAT32
static _Float32 (*real_wcstof32_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" _Float32 abii_wcstof32_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstof32_l)
        pre_fmtd_str pi_str = "wcstof32_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstof32_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof32_l, abii_ret)
    return real_wcstof32_l(nptr, endptr, loc);
}
#endif

#if __HAVE_FLOAT64
static _Float64 (*real_wcstof64_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" _Float64 abii_wcstof64_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstof64_l)
        pre_fmtd_str pi_str = "wcstof64_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstof64_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof64_l, abii_ret)
    return real_wcstof64_l(nptr, endptr, loc);
}
#endif

#if __HAVE_FLOAT128
static _Float128 (*real_wcstof128_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" _Float128 abii_wcstof128_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstof128_l)
        pre_fmtd_str pi_str = "wcstof128_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstof128_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof128_l, abii_ret)
    return real_wcstof128_l(nptr, endptr, loc);
}
#endif

#if __HAVE_FLOAT32X
static _Float32x (*real_wcstof32x_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" _Float32x abii_wcstof32x_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstof32x_l)
        pre_fmtd_str pi_str = "wcstof32x_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstof32x_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof32x_l, abii_ret)
    return real_wcstof32x_l(nptr, endptr, loc);
}
#endif

#if __HAVE_FLOAT64X
static _Float64x (*real_wcstof64x_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" _Float64x abii_wcstof64x_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstof64x_l)
        pre_fmtd_str pi_str = "wcstof64x_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstof64x_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof64x_l, abii_ret)
    return real_wcstof64x_l(nptr, endptr, loc);
}
#endif

#if __HAVE_FLOAT128X
static _Float128x (*real_wcstof128x_l)(const wchar_t*, wchar_t**, locale_t) __THROW = nullptr;

extern "C" _Float128x abii_wcstof128x_l(const wchar_t* nptr, wchar_t** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcstof128x_l)
        pre_fmtd_str pi_str = "wcstof128x_l(__nptr, __endptr, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcstof128x_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstof128x_l, abii_ret)
    return real_wcstof128x_l(nptr, endptr, loc);
}
#endif

static wchar_t* (*real_wcpcpy)(wchar_t*, const wchar_t*) __THROW = nullptr;

extern "C" wchar_t* abii_wcpcpy(wchar_t* dest, const wchar_t* src) __THROW
{
    OVERRIDE_PREFIX(wcpcpy)
        pre_fmtd_str pi_str = "wcpcpy(__dest, __src)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));

        auto abii_ret = real_wcpcpy(dest, src);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcpcpy, abii_ret)
    return real_wcpcpy(dest, src);
}

static wchar_t* (*real_wcpncpy)(wchar_t*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" wchar_t* abii_wcpncpy(wchar_t* dest, const wchar_t* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcpncpy)
        pre_fmtd_str pi_str = "wcpncpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcpncpy(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcpncpy, abii_ret)
    return real_wcpncpy(dest, src, n);
}

extern "C" __attribute_malloc__ __attr_dealloc_fclose
__FILE* abii_open_wmemstream(wchar_t** bufloc, size_t* sizeloc) __THROW;

static int (*real_fwide)(__FILE*, int) __THROW = nullptr;

extern "C" int abii_fwide(__FILE* fp, int mode) __THROW
{
    OVERRIDE_PREFIX(fwide)
        pre_fmtd_str pi_str = "fwide(__fp, __mode)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));
        abii_args->push_arg(new ArgPrinter(mode, "__mode"));

        auto abii_ret = real_fwide(fp, mode);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fwide, abii_ret)
    return real_fwide(fp, mode);
}

// TODO: Parse vargs ...
static int (*real_fwprintf)(__FILE*, const wchar_t*, ...) = nullptr;

extern "C" int abii_fwprintf(__FILE* stream, const wchar_t* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(fwprintf, format)
        pre_fmtd_str pi_str = "fwprintf(__stream, __format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_fwprintf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(*static_cast<int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(fwprintf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_fwprintf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real_wprintf)(const wchar_t*, ...) = nullptr;

extern "C" int abii_wprintf(const wchar_t* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(wprintf, format)
        pre_fmtd_str pi_str = "wprintf(__format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_wprintf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(*static_cast<int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(wprintf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_wprintf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real_swprintf)(wchar_t*, size_t, const wchar_t*, ...) __THROW = nullptr;

extern "C" int abii_swprintf(wchar_t* s, size_t n, const wchar_t* format, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(swprintf, format)
        pre_fmtd_str pi_str = "swprintf(__s, __n, __format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_swprintf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(swprintf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_swprintf), abii_bi_vargs, 1000));
}

// TODO: Parse __gnuc_va_list
static int (*real_vfwprintf)(__FILE*, const wchar_t*, __gnuc_va_list) = nullptr;

extern "C" int abii_vfwprintf(__FILE* s, const wchar_t* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(vfwprintf, format, arg)
        pre_fmtd_str pi_str = "vfwprintf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real_vfwprintf(s, format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vfwprintf, abii_ret, arg)
    return real_vfwprintf(s, format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real_vwprintf)(const wchar_t*, __gnuc_va_list) = nullptr;

extern "C" int abii_vwprintf(const wchar_t* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(vwprintf, format, arg)
        pre_fmtd_str pi_str = "vwprintf(__format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real_vwprintf(format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vwprintf, abii_ret, arg)
    return real_vwprintf(format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real_vswprintf)(wchar_t*, size_t, const wchar_t*, __gnuc_va_list) __THROW = nullptr;

extern "C" int abii_vswprintf(wchar_t* s, size_t n, const wchar_t* format, __gnuc_va_list arg) __THROW
{
    OVERRIDE_VALIST_PREFIX(vswprintf, format, arg)
        pre_fmtd_str pi_str = "vswprintf(__s, __n, __format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real_vswprintf(s, n, format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vswprintf, abii_ret, arg)
    return real_vswprintf(s, n, format, arg);
}

// TODO: Parse vargs ...
static int (*real_fwscanf)(__FILE*, const wchar_t*, ...) = nullptr;

extern "C" int abii_fwscanf(__FILE* stream, const wchar_t* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(fwscanf, format)
        pre_fmtd_str pi_str = "fwscanf(__stream, __format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_fwscanf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(fwscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_fwscanf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real_wscanf)(const wchar_t*, ...) = nullptr;

extern "C" int abii_wscanf(const wchar_t* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(wscanf, format)
        pre_fmtd_str pi_str = "wscanf(__format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_wscanf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(wscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_wscanf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real_swscanf)(const wchar_t*, ...) __THROW = nullptr;

extern "C" int abii_swscanf(const wchar_t* s, const wchar_t* format, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(swscanf, format)
        pre_fmtd_str pi_str = "swscanf(__s, __format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_swscanf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(swscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_swscanf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real___isoc23_fwscanf)(__FILE*, const wchar_t*, ...) = nullptr;

extern "C" int abii___isoc23_fwscanf(__FILE* stream, const wchar_t* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc23_fwscanf, format)
        pre_fmtd_str pi_str = "__isoc23_fwscanf(__stream, __format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_fwscanf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(__isoc23_fwscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_fwscanf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real___isoc23_wscanf)(const wchar_t*, ...) = nullptr;

extern "C" int abii___isoc23_wscanf(const wchar_t* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc23_wscanf, format)
        pre_fmtd_str pi_str = "__isoc23_wscanf(__format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_wscanf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(__isoc23_wscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_wscanf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real___isoc23_swscanf)(const wchar_t*, ...) __THROW = nullptr;

extern "C" int abii___isoc23_swscanf(const wchar_t* s, const wchar_t* format, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(__isoc23_swscanf, format)
        pre_fmtd_str pi_str = "__isoc23_swscanf(__s, __format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_swscanf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(__isoc23_swscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_swscanf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real___isoc99_fwscanf)(__FILE*, const wchar_t*, ...) = nullptr;

extern "C" int abii___isoc99_fwscanf(__FILE* stream, const wchar_t* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc99_fwscanf, format)
        pre_fmtd_str pi_str = "__isoc99_fwscanf(__stream, __format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_fwscanf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(__isoc99_fwscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_fwscanf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real___isoc99_wscanf)(const wchar_t*, ...) = nullptr;

extern "C" int abii___isoc99_wscanf(const wchar_t* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc99_wscanf, format)
        pre_fmtd_str pi_str = "__isoc99_wscanf(__format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_wscanf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(__isoc99_wscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_wscanf), abii_bi_vargs, 1000));
}

// TODO: Parse vargs ...
static int (*real___isoc99_swscanf)(const wchar_t*, ...) __THROW = nullptr;

extern "C" int abii___isoc99_swscanf(const wchar_t* s, const wchar_t* format, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(__isoc99_swscanf, format)
        pre_fmtd_str pi_str = "__isoc99_swscanf(__s, __format, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer1, reinterpret_cast<const char*>(format),
                           [](const char*, va_list, size_t) {return "";})

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_swscanf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VARIADIC_SUFFIX(__isoc99_swscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_swscanf), abii_bi_vargs, 1000));
}

// TODO: Parse __gnuc_va_list
static int (*real_vfwscanf)(__FILE*, const wchar_t*, __gnuc_va_list) = nullptr;

extern "C" int abii_vfwscanf(__FILE* s, const wchar_t* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(vfwscanf, format, arg)
        pre_fmtd_str pi_str = "vfwscanf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real_vfwscanf(s, format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vfwscanf, abii_ret, arg)
    return real_vfwscanf(s, format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real_vwscanf)(const wchar_t*, __gnuc_va_list) = nullptr;

extern "C" int abii_vwscanf(const wchar_t* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(vwscanf, format, arg)
        pre_fmtd_str pi_str = "vwscanf(__format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real_vwscanf(format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vwscanf, abii_ret, arg)
    return real_vwscanf(format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real_vswscanf)(const wchar_t*, const wchar_t*, __gnuc_va_list) __THROW = nullptr;

extern "C" int abii_vswscanf(const wchar_t* s, const wchar_t* format, __gnuc_va_list arg) __THROW
{
    OVERRIDE_VALIST_PREFIX(vswscanf, format, arg)
        pre_fmtd_str pi_str = "vswscanf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real_vswscanf(s, format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vswscanf, abii_ret, arg)
    return real_vswscanf(s, format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real___isoc23_vfwscanf)(__FILE*, const wchar_t*, __gnuc_va_list) = nullptr;

extern "C" int abii___isoc23_vfwscanf(__FILE* s, const wchar_t* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(__isoc23_vfwscanf, format, arg)
        pre_fmtd_str pi_str = "__isoc23_vfwscanf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real___isoc23_vfwscanf(s, format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(__isoc23_vfwscanf, abii_ret, arg)
    return real___isoc23_vfwscanf(s, format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real___isoc23_vwscanf)(const wchar_t*, __gnuc_va_list) = nullptr;

extern "C" int abii___isoc23_vwscanf(const wchar_t* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(__isoc23_vwscanf, format, arg)
        pre_fmtd_str pi_str = "__isoc23_vwscanf(__format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real___isoc23_vwscanf(format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(__isoc23_vwscanf, abii_ret, arg)
    return real___isoc23_vwscanf(format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real___isoc23_vswscanf)(const wchar_t*, const wchar_t*, __gnuc_va_list) __THROW = nullptr;

extern "C" int abii___isoc23_vswscanf(const wchar_t* s, const wchar_t* format, __gnuc_va_list arg) __THROW
{
    OVERRIDE_VALIST_PREFIX(__isoc23_vswscanf, format, arg)
        pre_fmtd_str pi_str = "__isoc23_vswscanf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real___isoc23_vswscanf(s, format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(__isoc23_vswscanf, abii_ret, arg)
    return real___isoc23_vswscanf(s, format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real___isoc99_vfwscanf)(__FILE*, const wchar_t*, __gnuc_va_list) = nullptr;

extern "C" int abii___isoc99_vfwscanf(__FILE* s, const wchar_t* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(__isoc99_vfwscanf, format, arg)
        pre_fmtd_str pi_str = "__isoc99_vfwscanf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real___isoc99_vfwscanf(s, format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(__isoc99_vfwscanf, abii_ret, arg)
    return real___isoc99_vfwscanf(s, format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real___isoc99_vwscanf)(const wchar_t*, __gnuc_va_list) = nullptr;

extern "C" int abii___isoc99_vwscanf(const wchar_t* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(__isoc99_vwscanf, format, arg)
        pre_fmtd_str pi_str = "__isoc99_vwscanf(__format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real___isoc99_vwscanf(format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(__isoc99_vwscanf, abii_ret, arg)
    return real___isoc99_vwscanf(format, arg);
}

// TODO: Parse __gnuc_va_list
static int (*real___isoc99_vswscanf)(const wchar_t*, const wchar_t*, __gnuc_va_list) __THROW = nullptr;

extern "C" int abii___isoc99_vswscanf(const wchar_t* s, const wchar_t* format, __gnuc_va_list arg) __THROW
{
    OVERRIDE_VALIST_PREFIX(__isoc99_vswscanf, format, arg)
        pre_fmtd_str pi_str = "__isoc99_vswscanf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VALIST_ARGS(printer1, reinterpret_cast<const char*>(format), arg, "arg",
                         [](const char*, va_list, size_t) {return "";})

        auto abii_ret = real___isoc99_vswscanf(s, format, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(__isoc99_vswscanf, abii_ret, arg)
    return real___isoc99_vswscanf(s, format, arg);
}

static int (*real_fgetwc)(__FILE*) = nullptr;

extern "C" wint_t abii_fgetwc(__FILE* stream)
{
    OVERRIDE_PREFIX(fgetwc)
        pre_fmtd_str pi_str = "fgetwc(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetwc(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetwc, abii_ret)
    return real_fgetwc(stream);
}

static int (*real_getwc)(__FILE*) = nullptr;

extern "C" wint_t abii_getwc(__FILE* stream)
{
    OVERRIDE_PREFIX(getwc)
        pre_fmtd_str pi_str = "getwc(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_getwc(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getwc, abii_ret)
    return real_getwc(stream);
}

static int (*real_getwchar)() = nullptr;

extern "C" wint_t abii_getwchar()
{
    OVERRIDE_PREFIX(getwchar)
        pre_fmtd_str pi_str = "getwchar()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getwchar();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getwchar, abii_ret)
    return real_getwchar();
}

static int (*real_fputwc)(wchar_t, __FILE*) = nullptr;

extern "C" wint_t abii_fputwc(wchar_t wc, __FILE* stream)
{
    OVERRIDE_PREFIX(fputwc)
        pre_fmtd_str pi_str = "fputwc(__wc, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fputwc(wc, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fputwc, abii_ret)
    return real_fputwc(wc, stream);
}

static int (*real_putwc)(wchar_t, __FILE*) = nullptr;

extern "C" wint_t abii_putwc(wchar_t wc, __FILE* stream)
{
    OVERRIDE_PREFIX(putwc)
        pre_fmtd_str pi_str = "putwc(__wc, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_putwc(wc, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(putwc, abii_ret)
    return real_putwc(wc, stream);
}

static int (*real_putwchar)(wchar_t) = nullptr;

extern "C" wint_t abii_putwchar(wchar_t wc)
{
    OVERRIDE_PREFIX(putwchar)
        pre_fmtd_str pi_str = "putwchar(__wc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));

        auto abii_ret = real_putwchar(wc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(putwchar, abii_ret)
    return real_putwchar(wc);
}

static wchar_t* (*real_fgetws)(wchar_t*, int, __FILE*) = nullptr;

extern "C" wchar_t* abii_fgetws(wchar_t* ws, int n, __FILE* stream)
{
    OVERRIDE_PREFIX(fgetws)
        pre_fmtd_str pi_str = "fgetws(__ws, __n, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(ws, "__ws");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetws(ws, n, stream);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_len(n);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(fgetws, abii_ret)
    return real_fgetws(ws, n, stream);
}

static int (*real_fputws)(const wchar_t*, __FILE*) = nullptr;

extern "C" int abii_fputws(const wchar_t* ws, __FILE* stream)
{
    OVERRIDE_PREFIX(fputws)
        pre_fmtd_str pi_str = "fputws(__ws, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ws, "__ws"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fputws(ws, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fputws, abii_ret)
    return real_fputws(ws, stream);
}

static wint_t (*real_ungetwc)(wint_t, __FILE*) = nullptr;

extern "C" wint_t abii_ungetwc(wint_t wc, __FILE* stream)
{
    OVERRIDE_PREFIX(ungetwc)
        pre_fmtd_str pi_str = "ungetwc(__wc, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_ungetwc(wc, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ungetwc, abii_ret)
    return real_ungetwc(wc, stream);
}

static wint_t (*real_getwc_unlocked)(__FILE*) = nullptr;

extern "C" wint_t abii_getwc_unlocked(__FILE* stream)
{
    OVERRIDE_PREFIX(getwc_unlocked)
        pre_fmtd_str pi_str = "getwc_unlocked(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_getwc_unlocked(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getwc_unlocked, abii_ret)
    return real_getwc_unlocked(stream);
}

static wint_t (*real_getwchar_unlocked)() = nullptr;

extern "C" wint_t abii_getwchar_unlocked()
{
    OVERRIDE_PREFIX(getwchar_unlocked)
        pre_fmtd_str pi_str = "getwchar_unlocked()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getwchar_unlocked();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getwchar_unlocked, abii_ret)
    return real_getwchar_unlocked();
}

static wint_t (*real_fgetwc_unlocked)(__FILE*) = nullptr;

extern "C" wint_t abii_fgetwc_unlocked(__FILE* stream)
{
    OVERRIDE_PREFIX(fgetwc_unlocked)
        pre_fmtd_str pi_str = "fgetwc_unlocked(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetwc_unlocked(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetwc_unlocked, abii_ret)
    return real_fgetwc_unlocked(stream);
}

static wint_t (*real_fputwc_unlocked)(wchar_t, __FILE*) = nullptr;

extern "C" wint_t abii_fputwc_unlocked(wchar_t wc, __FILE* stream)
{
    OVERRIDE_PREFIX(fputwc_unlocked)
        pre_fmtd_str pi_str = "fputwc_unlocked(__wc, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fputwc_unlocked(wc, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fputwc_unlocked, abii_ret)
    return real_fputwc_unlocked(wc, stream);
}

static wint_t (*real_putwc_unlocked)(wchar_t, __FILE*) = nullptr;

extern "C" wint_t abii_putwc_unlocked(wchar_t wc, __FILE* stream)
{
    OVERRIDE_PREFIX(putwc_unlocked)
        pre_fmtd_str pi_str = "putwc_unlocked(__wc, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_putwc_unlocked(wc, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(putwc_unlocked, abii_ret)
    return real_putwc_unlocked(wc, stream);
}

static wint_t (*real_putwchar_unlocked)(wchar_t) = nullptr;

extern "C" wint_t abii_putwchar_unlocked(wchar_t wc)
{
    OVERRIDE_PREFIX(putwchar_unlocked)
        pre_fmtd_str pi_str = "putwchar_unlocked(__wc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));

        auto abii_ret = real_putwchar_unlocked(wc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(putwchar_unlocked, abii_ret)
    return real_putwchar_unlocked(wc);
}

static wchar_t* (*real_fgetws_unlocked)(wchar_t*, int, __FILE*) = nullptr;

extern "C" wchar_t* abii_fgetws_unlocked(wchar_t* ws, int n, __FILE* stream)
{
    OVERRIDE_PREFIX(fgetws_unlocked)
        pre_fmtd_str pi_str = "fgetws_unlocked(__ws, __n, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(ws, "__ws");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetws_unlocked(ws, n, stream);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_len(n);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(fgetws_unlocked, abii_ret)
    return real_fgetws_unlocked(ws, n, stream);
}

static int (*real_fputws_unlocked)(const wchar_t*, __FILE*) = nullptr;

extern "C" int abii_fputws_unlocked(const wchar_t* ws, __FILE* stream)
{
    OVERRIDE_PREFIX(fputws_unlocked)
        pre_fmtd_str pi_str = "fputws_unlocked(__ws, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ws, "__ws"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fputws_unlocked(ws, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fputws_unlocked, abii_ret)
    return real_fputws_unlocked(ws, stream);
}

static int (*real_wcsftime)(wchar_t*, size_t, const wchar_t*, const tm*) __THROW = nullptr;

extern "C" size_t abii_wcsftime(wchar_t* s, size_t maxsize, const wchar_t* format, const tm* tp) __THROW
{
    OVERRIDE_PREFIX(wcsftime)
        pre_fmtd_str pi_str = "wcsftime(__s, __maxsize, __format, __tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(maxsize);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(maxsize, "__maxsize"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_wcsftime(s, maxsize, format, tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsftime, abii_ret)
    return real_wcsftime(s, maxsize, format, tp);
}

static int (*real_wcsftime_l)(wchar_t*, size_t, const wchar_t*, const tm*, locale_t) __THROW = nullptr;

extern "C" size_t abii_wcsftime_l(wchar_t* s, size_t maxsize, const wchar_t* format, const tm* tp, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(wcsftime_l)
        pre_fmtd_str pi_str = "wcsftime_l(__s, __maxsize, __format, __tp, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(maxsize);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(maxsize, "__maxsize"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(tp, "__tp"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_wcsftime_l(s, maxsize, format, tp, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcsftime_l, abii_ret)
    return real_wcsftime_l(s, maxsize, format, tp, loc);
}
}
