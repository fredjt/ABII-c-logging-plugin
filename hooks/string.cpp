//
// Created by Trent Tanchin on 5/16/26.
//

#include <abii/libabii.h>

#include "custom_enum_printers.h"
#include "bits/types/__locale_t.h"

namespace abii
{
// TODO: This appears to be called by dlsym, causing infinite recursion
static __nonnull((1, 2)) void* (*real_memcpy)(void*, const void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2)) void* abii_memcpy(void* dest, const void* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(memcpy)
        pre_fmtd_str pi_str = "memcpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(dest, "__dest");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(src, "__src");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_memcpy(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memcpy, abii_ret)
    return real_memcpy(dest, src, n);
}

static __nonnull((1, 2)) void* (*real_memmove)(void*, const void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2)) void* abii_memmove(void* dest, const void* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(memmove)
        pre_fmtd_str pi_str = "memmove(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(dest, "__dest");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(src, "__src");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_memmove(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memmove, abii_ret)
    return real_memmove(dest, src, n);
}

static __nonnull((1, 2)) __attr_access((__write_only__, 1, 4)) void* (*real_memccpy)(
    void*, const void*, int, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2)) __attr_access((__write_only__, 1, 4))
void* abii_memccpy(void* dest, const void* src, int c, size_t n) __THROW
{
    OVERRIDE_PREFIX(memccpy)
        pre_fmtd_str pi_str = "memccpy(__dest, __src, __c, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(dest, "__dest");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(src, "__src");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_memccpy(dest, src, c, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memccpy, abii_ret)
    return real_memccpy(dest, src, c, n);
}

static __nonnull((1)) void* (*real_memset)(void*, int, size_t) __THROW = nullptr;

extern "C" __nonnull((1)) void* abii_memset(void* s, int c, size_t n) __THROW
{
    OVERRIDE_PREFIX(memset)
        pre_fmtd_str pi_str = "memset(__s, __c, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_memset(s, c, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memset, abii_ret)
    return real_memset(s, c, n);
}

static __nonnull((1)) __fortified_attr_access(__write_only__, 1, 3)
void* (*real_memset_explicit)(void*, int, size_t) __THROW = nullptr;

extern "C" __nonnull((1)) __fortified_attr_access(__write_only__, 1, 3)
void* abii_memset_explicit(void* s, int c, size_t n) __THROW
{
    OVERRIDE_PREFIX(memset_explicit)
        pre_fmtd_str pi_str = "memset_explicit(__s, __c, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_memset_explicit(s, c, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memset_explicit, abii_ret)
    return real_memset_explicit(s, c, n);
}

static __attribute_pure__ __nonnull((1, 2)) int (*real_memcmp)(const void*, const void*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_memcmp(const void* s1, const void* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(memcmp)
        pre_fmtd_str pi_str = "memcmp(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s1, "__s1");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(s2, "__s2");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_memcmp(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memcmp, abii_ret)
    return real_memcmp(s1, s2, n);
}

static __attribute_pure__ __nonnull((1, 2)) int (*real___memcmpeq)(const void*, const void*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii___memcmpeq(const void* s1, const void* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(__memcmpeq)
        pre_fmtd_str pi_str = "__memcmpeq(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s1, "__s1");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(s2, "__s2");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real___memcmpeq(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__memcmpeq, abii_ret)
    return real___memcmpeq(s1, s2, n);
}

static __attribute_pure__ __nonnull((1)) void* (*real_memchr)(const void*, int, size_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1))
void* abii_memchr(const void* s, int c, size_t n) __THROW
{
    OVERRIDE_PREFIX(memchr)
        pre_fmtd_str pi_str = "memchr(__s, __c, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_memchr(s, c, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memchr, abii_ret)
    return real_memchr(s, c, n);
}

static __attribute_pure__ __nonnull((1)) void* (*real_rawmemchr)(const void*, int) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1))
void* abii_rawmemchr(const void* s, int c) __THROW
{
    OVERRIDE_PREFIX(rawmemchr)
        pre_fmtd_str pi_str = "rawmemchr(__s, __c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_rawmemchr(s, c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rawmemchr, abii_ret)
    return real_rawmemchr(s, c);
}

static __attribute_pure__ __nonnull((1)) __attr_access((__read_only__, 1, 3))
void* (*real_memrchr)(const void*, int, size_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1)) __attr_access((__read_only__, 1, 3))
void* abii_memrchr(const void* s, int c, size_t n) __THROW
{
    OVERRIDE_PREFIX(memrchr)
        pre_fmtd_str pi_str = "memrchr(__s, __c, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_memrchr(s, c, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memrchr, abii_ret)
    return real_memrchr(s, c, n);
}

static __nonnull((1, 2)) char* (*real_strcpy)(char*, const char*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
char* abii_strcpy(char* dest, const char* src) __THROW
{
    OVERRIDE_PREFIX(strcpy)
        pre_fmtd_str pi_str = "strcpy(__dest, __src)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));

        auto abii_ret = real_strcpy(dest, src);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strcpy, abii_ret)
    return real_strcpy(dest, src);
}

static __nonnull((1, 2)) char* (*real_strncpy)(char*, const char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2))
char* abii_strncpy(char* dest, const char* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(strncpy)
        pre_fmtd_str pi_str = "strncpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_strncpy(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strncpy, abii_ret)
    return real_strncpy(dest, src, n);
}

static __nonnull((1, 2)) char* (*real_strcat)(char*, const char*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
char* abii_strcat(char* dest, const char* src) __THROW
{
    OVERRIDE_PREFIX(strcat)
        pre_fmtd_str pi_str = "strcat(__dest, __src)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));

        auto abii_ret = real_strcat(dest, src);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strcat, abii_ret)
    return real_strcat(dest, src);
}

static __nonnull((1, 2)) char* (*real_strncat)(char*, const char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2))
char* abii_strncat(char* dest, const char* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(strncat)
        pre_fmtd_str pi_str = "strncat(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_strncat(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strncat, abii_ret)
    return real_strncat(dest, src, n);
}

static __attribute_pure__ __nonnull((1, 2)) int (*real_strcmp)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_strcmp(const char* s1, const char* s2) __THROW
{
    OVERRIDE_PREFIX(strcmp)
        pre_fmtd_str pi_str = "strcmp(__s1, __s2)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));

        auto abii_ret = real_strcmp(s1, s2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strcmp, abii_ret)
    return real_strcmp(s1, s2);
}

static __attribute_pure__ __nonnull((1, 2)) int (*real_strncmp)(const char*, const char*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_strncmp(const char* s1, const char* s2, size_t n) __THROW
{
    OVERRIDE_PREFIX(strncmp)
        pre_fmtd_str pi_str = "strncmp(__s1, __s2, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_strncmp(s1, s2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strncmp, abii_ret)
    return real_strncmp(s1, s2, n);
}

static __attribute_pure__ __nonnull((1, 2)) int (*real_strcoll)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_strcoll(const char* s1, const char* s2) __THROW
{
    OVERRIDE_PREFIX(strcoll)
        pre_fmtd_str pi_str = "strcoll(__s1, __s2)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));

        auto abii_ret = real_strcoll(s1, s2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strcoll, abii_ret)
    return real_strcoll(s1, s2);
}

static __nonnull((2)) __attr_access((__write_only__, 1, 3))
int (*real_strxfrm)(char*, const char*, size_t) __THROW = nullptr;

extern "C" __nonnull((2)) __attr_access((__write_only__, 1, 3))
size_t abii_strxfrm(char* dest, const char* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(strxfrm)
        pre_fmtd_str pi_str = "strxfrm(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_strxfrm(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strxfrm, abii_ret)
    return real_strxfrm(dest, src, n);
}

static __attribute_pure__ __nonnull((1, 2, 3))
int (*real_strcoll_l)(const char*, const char*, locale_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2, 3))
int abii_strcoll_l(const char* s1, const char* s2, locale_t l) __THROW
{
    OVERRIDE_PREFIX(strcoll_l)
        pre_fmtd_str pi_str = "strcoll_l(__s1, __s2, __l)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));
        abii_args->push_arg(new ArgPrinter(l, "__l"));

        auto abii_ret = real_strcoll_l(s1, s2, l);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strcoll_l, abii_ret)
    return real_strcoll_l(s1, s2, l);
}

static __nonnull((2, 4)) __attr_access((__write_only__, 1, 3))
int (*real_strxfrm_l)(char*, const char*, size_t, locale_t) __THROW = nullptr;

extern "C" __nonnull((2, 4)) __attr_access((__write_only__, 1, 3))
size_t abii_strxfrm_l(char* dest, const char* src, size_t n, locale_t l) __THROW
{
    OVERRIDE_PREFIX(strxfrm_l)
        pre_fmtd_str pi_str = "strxfrm_l(__dest, __src, __n, __l)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(l, "__l"));

        auto abii_ret = real_strxfrm_l(dest, src, n, l);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strxfrm_l, abii_ret)
    return real_strxfrm_l(dest, src, n, l);
}

static __attribute_malloc__ __nonnull((1)) char* (*real_strdup)(const char*) __THROW = nullptr;

extern "C" __attribute_malloc__ __nonnull((1))
char* abii_strdup(const char* s) __THROW
{
    OVERRIDE_PREFIX(strdup)
        pre_fmtd_str pi_str = "strdup(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_strdup(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strdup, abii_ret)
    return real_strdup(s);
}

static __attribute_malloc__ __nonnull((1)) char* (*real_strndup)(const char*, size_t) __THROW = nullptr;

extern "C" __attribute_malloc__ __nonnull((1))
char* abii_strndup(const char* string, size_t n) __THROW
{
    OVERRIDE_PREFIX(strndup)
        pre_fmtd_str pi_str = "strndup(__string, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_strndup(string, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strndup, abii_ret)
    return real_strndup(string, n);
}

static __attribute_malloc__ __nonnull((1)) char* (*real_strchr)(const char*, int) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1))
char* abii_strchr(const char* s, int c) __THROW
{
    OVERRIDE_PREFIX(strchr)
        pre_fmtd_str pi_str = "strchr(__s, __c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_strchr(s, c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strchr, abii_ret)
    return real_strchr(s, c);
}

static __attribute_malloc__ __nonnull((1)) char* (*real_strrchr)(const char*, int) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1))
char* abii_strrchr(const char* s, int c) __THROW
{
    OVERRIDE_PREFIX(strrchr)
        pre_fmtd_str pi_str = "strrchr(__s, __c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_strrchr(s, c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strrchr, abii_ret)
    return real_strrchr(s, c);
}

static __attribute_malloc__ __nonnull((1)) char* (*real_strchrnul)(const char*, int) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1))
char* abii_strchrnul(const char* s, int c) __THROW
{
    OVERRIDE_PREFIX(strchrnul)
        pre_fmtd_str pi_str = "strchrnul(__s, __c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_strchrnul(s, c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strchrnul, abii_ret)
    return real_strchrnul(s, c);
}

static __attribute_pure__ __nonnull((1, 2)) size_t (*real_strcspn)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
size_t abii_strcspn(const char* s, const char* reject) __THROW
{
    OVERRIDE_PREFIX(strcspn)
        pre_fmtd_str pi_str = "strcspn(__s, __reject)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(reject, "__reject"));

        auto abii_ret = real_strcspn(s, reject);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strcspn, abii_ret)
    return real_strcspn(s, reject);
}

static __attribute_pure__ __nonnull((1, 2)) size_t (*real_strspn)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
size_t abii_strspn(const char* s, const char* accept) __THROW
{
    OVERRIDE_PREFIX(strspn)
        pre_fmtd_str pi_str = "strspn(__s, __accept)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(accept, "__accept"));

        auto abii_ret = real_strspn(s, accept);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strspn, abii_ret)
    return real_strspn(s, accept);
}

static __attribute_pure__ __nonnull((1, 2)) char* (*real_strpbrk)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
char* abii_strpbrk(const char* s, const char* accept) __THROW
{
    OVERRIDE_PREFIX(strpbrk)
        pre_fmtd_str pi_str = "strpbrk(__s, __accept)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(accept, "__accept"));

        auto abii_ret = real_strpbrk(s, accept);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strpbrk, abii_ret)
    return real_strpbrk(s, accept);
}

static __attribute_pure__ __nonnull((1, 2)) char* (*real_strstr)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
char* abii_strstr(const char* haystack, const char* needle) __THROW
{
    OVERRIDE_PREFIX(strstr)
        pre_fmtd_str pi_str = "strstr(__haystack, __needle)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(haystack, "__haystack"));
        abii_args->push_arg(new ArgPrinter(needle, "__needle"));

        auto abii_ret = real_strstr(haystack, needle);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strstr, abii_ret)
    return real_strstr(haystack, needle);
}

static __nonnull((2)) char* (*real_strtok)(char*, const char*) __THROW = nullptr;

extern "C" __nonnull((2))
char* abii_strtok(char* s, const char* delim) __THROW
{
    OVERRIDE_PREFIX(strtok)
        pre_fmtd_str pi_str = "strtok(__s, __delim)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(delim, "__delim"));

        auto abii_ret = real_strtok(s, delim);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtok, abii_ret)
    return real_strtok(s, delim);
}

static __nonnull((2, 3)) char* (*real___strtok_r)(char*, const char*, char**) __THROW = nullptr;

extern "C" __nonnull((2, 3))
char* abii___strtok_r(char* s, const char* delim, char** save_ptr) __THROW
{
    OVERRIDE_PREFIX(__strtok_r)
        pre_fmtd_str pi_str = "__strtok_r(__s, __delim, __save_ptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(delim, "__delim"));
        abii_args->push_arg(new ArgPrinter(save_ptr, "__save_ptr"));

        auto abii_ret = real___strtok_r(s, delim, save_ptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__strtok_r, abii_ret)
    return real___strtok_r(s, delim, save_ptr);
}

static __nonnull((2, 3)) char* (*real_strtok_r)(char*, const char*, char**) __THROW = nullptr;

extern "C" __nonnull((2, 3))
char* abii_strtok_r(char* s, const char* delim, char** save_ptr) __THROW
{
    OVERRIDE_PREFIX(strtok_r)
        pre_fmtd_str pi_str = "strtok_r(__s, __delim, __save_ptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(delim, "__delim"));
        abii_args->push_arg(new ArgPrinter(save_ptr, "__save_ptr"));

        auto abii_ret = real_strtok_r(s, delim, save_ptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtok_r, abii_ret)
    return real_strtok_r(s, delim, save_ptr);
}

static __attribute_pure__ __nonnull((1, 2)) char* (*real_strcasestr)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
char* abii_strcasestr(const char* haystack, const char* needle) __THROW
{
    OVERRIDE_PREFIX(strcasestr)
        pre_fmtd_str pi_str = "strcasestr(__haystack, __needle)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(haystack, "__haystack"));
        abii_args->push_arg(new ArgPrinter(needle, "__needle"));

        auto abii_ret = real_strcasestr(haystack, needle);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strcasestr, abii_ret)
    return real_strcasestr(haystack, needle);
}

static __attribute_pure__ __nonnull((1, 3)) __attr_access((__read_only__, 1, 2)) __attr_access((__read_only__, 3, 4))
char* (*real_memmem)(const void*, size_t, const void*, size_t) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 3)) __attr_access((__read_only__, 1, 2))
__attr_access((__read_only__, 3, 4))
void* abii_memmem(const void* haystack, size_t haystacklen, const void* needle, size_t needlelen) __THROW
{
    OVERRIDE_PREFIX(memmem)
        pre_fmtd_str pi_str = "memmem(__haystack, __haystacklen, __needle, __needlelen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(haystack, "__haystack");
        printer->set_len(haystacklen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(haystacklen, "__haystacklen"));

        auto printer1 = new ArgPrinter(needle, "__needle");
        printer1->set_len(needlelen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(needlelen, "__needlelen"));

        auto abii_ret = real_memmem(haystack, haystacklen, needle, needlelen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memmem, abii_ret)
    return real_memmem(haystack, haystacklen, needle, needlelen);
}

static __nonnull((1, 2)) char* (*real___mempcpy)(void*, const void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2))
void* abii___mempcpy(void* dest, const void* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(__mempcpy)
        pre_fmtd_str pi_str = "__mempcpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real___mempcpy(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__mempcpy, abii_ret)
    return real___mempcpy(dest, src, n);
}

static __nonnull((1, 2)) char* (*real_mempcpy)(void*, const void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2))
void* abii_mempcpy(void* dest, const void* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(mempcpy)
        pre_fmtd_str pi_str = "mempcpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_mempcpy(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mempcpy, abii_ret)
    return real_mempcpy(dest, src, n);
}

// TODO: This appears to be called by dlsym, causing infinite recursion
static __attribute_pure__ __nonnull((1)) size_t (*real_strlen)(const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1))
size_t abii_strlen(const char* s) __THROW
{
    OVERRIDE_PREFIX(strlen)
        pre_fmtd_str pi_str = "strlen(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_strlen(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strlen, abii_ret)
    return real_strlen(s);
}

static char* (*real_strerror)(int) __THROW = nullptr;

extern "C" char* abii_strerror(int errnum) __THROW
{
    OVERRIDE_PREFIX(strerror)
        pre_fmtd_str pi_str = "strerror(__errnum)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(errnum, "__errnum");
        printer->set_enum_printer(print_error_enum_entry, errnum);
        abii_args->push_arg(printer);

        auto abii_ret = real_strerror(errnum);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strerror, abii_ret)
    return real_strerror(errnum);
}

static char* (*real_strerror_r)(int, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((2)) __wur __attr_access((__write_only__, 2, 3))
char* abii_strerror_r(int errnum, char* buf, size_t buflen) __THROW
{
    OVERRIDE_PREFIX(strerror_r)
        pre_fmtd_str pi_str = "strerror_r(__errnum, __buf, __buflen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(errnum, "__errnum");
        printer->set_enum_printer(print_error_enum_entry, errnum);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));

        auto abii_ret = real_strerror_r(errnum, buf, buflen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strerror_r, abii_ret)
    return real_strerror_r(errnum, buf, buflen);
}

static const char* (*real_strerrordesc_np)(int) __THROW = nullptr;

extern "C" const char* abii_strerrordesc_np(int err) __THROW
{
    OVERRIDE_PREFIX(strerrordesc_np)
        pre_fmtd_str pi_str = "strerrordesc_np(__err)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(err, "__err");
        printer->set_enum_printer(print_error_enum_entry, err);
        abii_args->push_arg(printer);

        auto abii_ret = real_strerrordesc_np(err);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strerrordesc_np, abii_ret)
    return real_strerrordesc_np(err);
}

static const char* (*real_strerrorname_np)(int) __THROW = nullptr;

extern "C" const char* abii_strerrorname_np(int err) __THROW
{
    OVERRIDE_PREFIX(strerrorname_np)
        pre_fmtd_str pi_str = "strerrorname_np(__err)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(err, "__err");
        printer->set_enum_printer(print_error_enum_entry, err);
        abii_args->push_arg(printer);

        auto abii_ret = real_strerrorname_np(err);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strerrorname_np, abii_ret)
    return real_strerrorname_np(err);
}

static char* (*real_strerror_l)(int, locale_t) __THROW = nullptr;

extern "C" char* abii_strerror_l(int errnum, locale_t l) __THROW
{
    OVERRIDE_PREFIX(strerror_l)
        pre_fmtd_str pi_str = "strerror_l(__errnum, __l)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(errnum, "__errnum");
        printer->set_enum_printer(print_error_enum_entry, errnum);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(l, "__l"));

        auto abii_ret = real_strerror_l(errnum, l);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strerror_l, abii_ret)
    return real_strerror_l(errnum, l);
}

static void (*real_explicit_bzero)(void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1)) __fortified_attr_access(__write_only__, 1, 2)
void abii_explicit_bzero(void* s, size_t n) __THROW
{
    OVERRIDE_PREFIX(explicit_bzero)
        pre_fmtd_str pi_str = "explicit_bzero(__s, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        real_explicit_bzero(s, n);
    OVERRIDE_SUFFIX(explicit_bzero,)
    return real_explicit_bzero(s, n);
}

static char* (*real_strsep)(char**, const char*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
char* abii_strsep(char** stringp, const char* delim) __THROW
{
    OVERRIDE_PREFIX(strsep)
        pre_fmtd_str pi_str = "strsep(__stringp, __delim)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stringp, "__stringp"));
        abii_args->push_arg(new ArgPrinter(delim, "__delim"));

        auto abii_ret = real_strsep(stringp, delim);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strsep, abii_ret)
    return real_strsep(stringp, delim);
}

static char* (*real_strsignal)(int) __THROW = nullptr;

extern "C" char* abii_strsignal(int sig) __THROW
{
    OVERRIDE_PREFIX(strsignal)
        pre_fmtd_str pi_str = "strsignal(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_strsignal(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strsignal, abii_ret)
    return real_strsignal(sig);
}

static const char* (*real_sigabbrev_np)(int) __THROW = nullptr;

extern "C" const char* abii_sigabbrev_np(int sig) __THROW
{
    OVERRIDE_PREFIX(sigabbrev_np)
        pre_fmtd_str pi_str = "sigabbrev_np(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_sigabbrev_np(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigabbrev_np, abii_ret)
    return real_sigabbrev_np(sig);
}

static const char* (*real_sigdescr_np)(int) __THROW = nullptr;

extern "C" const char* abii_sigdescr_np(int sig) __THROW
{
    OVERRIDE_PREFIX(sigdescr_np)
        pre_fmtd_str pi_str = "sigdescr_np(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_sigdescr_np(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigdescr_np, abii_ret)
    return real_sigdescr_np(sig);
}

static char* (*real___stpcpy)(char*, const char*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
char* abii___stpcpy(char* dest, const char* src) __THROW
{
    OVERRIDE_PREFIX(__stpcpy)
        pre_fmtd_str pi_str = "__stpcpy(__dest, __src)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));

        auto abii_ret = real___stpcpy(dest, src);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__stpcpy, abii_ret)
    return real___stpcpy(dest, src);
}

static char* (*real_stpcpy)(char*, const char*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
char* abii_stpcpy(char* dest, const char* src) __THROW
{
    OVERRIDE_PREFIX(stpcpy)
        pre_fmtd_str pi_str = "stpcpy(__dest, __src)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));

        auto abii_ret = real_stpcpy(dest, src);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stpcpy, abii_ret)
    return real_stpcpy(dest, src);
}

static char* (*real___stpncpy)(char*, const char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2))
char* abii___stpncpy(char* dest, const char* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(__stpncpy)
        pre_fmtd_str pi_str = "__stpncpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real___stpncpy(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__stpncpy, abii_ret)
    return real___stpncpy(dest, src, n);
}

static char* (*real_stpncpy)(char*, const char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2))
char* abii_stpncpy(char* dest, const char* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(stpncpy)
        pre_fmtd_str pi_str = "stpncpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_stpncpy(dest, src, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stpncpy, abii_ret)
    return real_stpncpy(dest, src, n);
}

static size_t (*real_strlcpy)(char*, const char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2)) __attr_access((__write_only__, 1, 3))
size_t abii_strlcpy(char* dest, const char* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(strlcpy)
        pre_fmtd_str pi_str = "strlcpy(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(dest, "__dest");
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_strlcpy(dest, src, n);

        printer->set_len(abii_ret);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strlcpy, abii_ret)
    return real_strlcpy(dest, src, n);
}

static size_t (*real_strlcat)(char*, const char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2)) __attr_access((__read_write__, 1, 3))
size_t abii_strlcat(char* dest, const char* src, size_t n) __THROW
{
    OVERRIDE_PREFIX(strlcat)
        pre_fmtd_str pi_str = "strlcat(__dest, __src, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(dest, "__dest");
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(src, "__src"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_strlcat(dest, src, n);

        printer->set_len(abii_ret);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strlcat, abii_ret)
    return real_strlcat(dest, src, n);
}

static int (*real_strverscmp)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_strverscmp(const char* s1, const char* s2) __THROW
{
    OVERRIDE_PREFIX(strverscmp)
        pre_fmtd_str pi_str = "strverscmp(__s1, __s2)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s1, "__s1"));
        abii_args->push_arg(new ArgPrinter(s2, "__s2"));

        auto abii_ret = real_strverscmp(s1, s2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strverscmp, abii_ret)
    return real_strverscmp(s1, s2);
}

static char* (*real_strfry)(char*) __THROW = nullptr;

extern "C" __nonnull((1))
char* abii_strfry(char* string) __THROW
{
    OVERRIDE_PREFIX(strfry)
        pre_fmtd_str pi_str = "strfry(__string)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));

        auto abii_ret = real_strfry(string);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfry, abii_ret)
    return real_strfry(string);
}

static void* (*real_memfrob)(void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1)) __attr_access((__read_write__, 1, 2))
void* abii_memfrob(void* s, size_t n) __THROW
{
    OVERRIDE_PREFIX(memfrob)
        pre_fmtd_str pi_str = "memfrob(__s, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(n);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_memfrob(s, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memfrob, abii_ret)
    return real_memfrob(s, n);
}

static char* (*real_basename)(const char*) __THROW = nullptr;

extern "C" __nonnull((1))
char* abii_basename(const char* filename) __THROW
{
    OVERRIDE_PREFIX(basename)
        pre_fmtd_str pi_str = "basename(__filename)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(filename, "__filename"));

        auto abii_ret = real_basename(filename);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(basename, abii_ret)
    return real_basename(filename);
}
}
