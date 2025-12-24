//
// Created by Trent Tanchin on 7/23/24.
//

#include "ctype.h"

#include "bits/types/__locale_t.h"

namespace abii
{
static const unsigned short int** (*real___ctype_b_loc)() __THROW = nullptr;

extern "C" __attribute__ ((__const__))
const unsigned short int** abii___ctype_b_loc() __THROW
{
    OVERRIDE_PREFIX(__ctype_b_loc)
        pre_fmtd_str str = "__ctype_b_loc()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real___ctype_b_loc();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__ctype_b_loc, abii_ret)
    return real___ctype_b_loc();
}

static const __int32_t** (*real___ctype_tolower_loc)() __THROW = nullptr;

extern "C" __attribute__ ((__const__))
const __int32_t** abii___ctype_tolower_loc() __THROW
{
    OVERRIDE_PREFIX(__ctype_tolower_loc)
        pre_fmtd_str str = "__ctype_tolower_loc()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real___ctype_tolower_loc();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__ctype_tolower_loc, abii_ret)
    return real___ctype_tolower_loc();
}

static const __int32_t** (*real___ctype_toupper_loc)() __THROW = nullptr;

extern "C" __attribute__ ((__const__))
const __int32_t** abii___ctype_toupper_loc() __THROW
{
    OVERRIDE_PREFIX(__ctype_toupper_loc)
        pre_fmtd_str str = "__ctype_toupper_loc()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real___ctype_toupper_loc();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__ctype_toupper_loc, abii_ret)
    return real___ctype_toupper_loc();
}

static int (*real_isalnum)(int) __THROW = nullptr;

extern "C" int abii_isalnum(int c) __THROW
{
    OVERRIDE_PREFIX(isalnum)
        pre_fmtd_str str = "isalnum(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_isalnum(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isalnum, abii_ret)
    return real_isalnum(c);
}

static int (*real_isalpha)(int) __THROW = nullptr;

extern "C" int abii_isalpha(int c) __THROW
{
    OVERRIDE_PREFIX(isalpha)
        pre_fmtd_str str = "isalpha(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_isalpha(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isalpha, abii_ret)
    return real_isalpha(c);
}

static int (*real_iscntrl)(int) __THROW = nullptr;

extern "C" int abii_iscntrl(int c) __THROW
{
    OVERRIDE_PREFIX(iscntrl)
        pre_fmtd_str str = "iscntrl(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_iscntrl(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iscntrl, abii_ret)
    return real_iscntrl(c);
}

static int (*real_isdigit)(int) __THROW = nullptr;

extern "C" int abii_isdigit(int c) __THROW
{
    OVERRIDE_PREFIX(isdigit)
        pre_fmtd_str str = "isdigit(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_isdigit(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isdigit, abii_ret)
    return real_isdigit(c);
}

static int (*real_islower)(int) __THROW = nullptr;

extern "C" int abii_islower(int c) __THROW
{
    OVERRIDE_PREFIX(islower)
        pre_fmtd_str str = "islower(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_islower(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(islower, abii_ret)
    return real_islower(c);
}

static int (*real_isgraph)(int) __THROW = nullptr;

extern "C" int abii_isgraph(int c) __THROW
{
    OVERRIDE_PREFIX(isgraph)
        pre_fmtd_str str = "isgraph(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_isgraph(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isgraph, abii_ret)
    return real_isgraph(c);
}

static int (*real_isprint)(int) __THROW = nullptr;

extern "C" int abii_isprint(int c) __THROW
{
    OVERRIDE_PREFIX(isprint)
        pre_fmtd_str str = "isprint(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_isprint(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isprint, abii_ret)
    return real_isprint(c);
}

static int (*real_ispunct)(int) __THROW = nullptr;

extern "C" int abii_ispunct(int c) __THROW
{
    OVERRIDE_PREFIX(ispunct)
        pre_fmtd_str str = "ispunct(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_ispunct(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ispunct, abii_ret)
    return real_ispunct(c);
}

static int (*real_isspace)(int) __THROW = nullptr;

extern "C" int abii_isspace(int c) __THROW
{
    OVERRIDE_PREFIX(isspace)
        pre_fmtd_str str = "isspace(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_isspace(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isspace, abii_ret)
    return real_isspace(c);
}

static int (*real_isupper)(int) __THROW = nullptr;

extern "C" int abii_isupper(int c) __THROW
{
    OVERRIDE_PREFIX(isupper)
        pre_fmtd_str str = "isupper(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_isupper(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isupper, abii_ret)
    return real_isupper(c);
}

static int (*real_isxdigit)(int) __THROW = nullptr;

extern "C" int abii_isxdigit(int c) __THROW
{
    OVERRIDE_PREFIX(isxdigit)
        pre_fmtd_str str = "isxdigit(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_isxdigit(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isxdigit, abii_ret)
    return real_isxdigit(c);
}

static int (*real_tolower)(int) __THROW = nullptr;

extern "C" int abii_tolower(int c) __THROW
{
    OVERRIDE_PREFIX(tolower)
        pre_fmtd_str str = "tolower(__c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_tolower(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tolower, abii_ret)
    return real_tolower(c);
}

static int (*real_toupper)(int) __THROW = nullptr;

extern "C" int abii_toupper(int c) __THROW
{
    OVERRIDE_PREFIX(toupper)
        pre_fmtd_str str = "toupper(__c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_toupper(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(toupper, abii_ret)
    return real_toupper(c);
}

static int (*real_isblank)(int) __THROW = nullptr;

extern "C" int abii_isblank(int c) __THROW
{
    OVERRIDE_PREFIX(isblank)
        pre_fmtd_str str = "isblank(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real_isblank(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isblank, abii_ret)
    return real_isblank(c);
}

static int (*real_isctype)(int, int) __THROW = nullptr;

extern "C" int abii_isctype(int c, int mask) __THROW
{
    OVERRIDE_PREFIX(isctype)
        pre_fmtd_str str = "isctype(__c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(mask, "__mask"));

        auto abii_ret = real_isctype(c, mask);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isctype, abii_ret)
    return real_isctype(c, mask);
}

static int (*real_isascii)(int) __THROW = nullptr;

extern "C" int abii_isascii(int c) __THROW
{
    OVERRIDE_PREFIX(isascii)
        pre_fmtd_str str = "isascii(__c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_isascii(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isascii, abii_ret)
    return real_isascii(c);
}

static int (*real_toascii)(int) __THROW = nullptr;

extern "C" int abii_toascii(int c) __THROW
{
    OVERRIDE_PREFIX(toascii)
        pre_fmtd_str str = "toascii(__c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_toascii(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(toascii, abii_ret)
    return real_toascii(c);
}

static int (*real__toupper)(int) __THROW = nullptr;

extern "C" int abii__toupper(int c) __THROW
{
    OVERRIDE_PREFIX(_toupper)
        pre_fmtd_str str = "_toupper(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real__toupper(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(_toupper, abii_ret)
    return real__toupper(c);
}

static int (*real__tolower)(int) __THROW = nullptr;

extern "C" int abii__tolower(int c) __THROW
{
    OVERRIDE_PREFIX(_tolower)
        pre_fmtd_str str = "_tolower(c)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));

        auto abii_ret = real__tolower(c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(_tolower, abii_ret)
    return real__tolower(c);
}

static int (*real_isalnum_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_isalnum_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(isalnum_l)
        pre_fmtd_str str = "isalnum_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_isalnum_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isalnum_l, abii_ret)
    return real_isalnum_l(c, locale);
}

static int (*real_isalpha_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_isalpha_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(isalpha_l)
        pre_fmtd_str str = "isalpha_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_isalpha_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isalpha_l, abii_ret)
    return real_isalpha_l(c, locale);
}

static int (*real_iscntrl_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_iscntrl_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iscntrl_l)
        pre_fmtd_str str = "iscntrl_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_iscntrl_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iscntrl_l, abii_ret)
    return real_iscntrl_l(c, locale);
}

static int (*real_isdigit_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_isdigit_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(isdigit_l)
        pre_fmtd_str str = "isdigit_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_isdigit_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isdigit_l, abii_ret)
    return real_isdigit_l(c, locale);
}

static int (*real_islower_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_islower_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(islower_l)
        pre_fmtd_str str = "islower_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_islower_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(islower_l, abii_ret)
    return real_islower_l(c, locale);
}

static int (*real_isgraph_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_isgraph_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(isgraph_l)
        pre_fmtd_str str = "isgraph_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_isgraph_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isgraph_l, abii_ret)
    return real_isgraph_l(c, locale);
}

static int (*real_isprint_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_isprint_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(isprint_l)
        pre_fmtd_str str = "isprint_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_isprint_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isprint_l, abii_ret)
    return real_isprint_l(c, locale);
}

static int (*real_ispunct_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_ispunct_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(ispunct_l)
        pre_fmtd_str str = "ispunct_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_ispunct_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ispunct_l, abii_ret)
    return real_ispunct_l(c, locale);
}

static int (*real_isspace_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_isspace_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(isspace_l)
        pre_fmtd_str str = "isspace_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_isspace_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isspace_l, abii_ret)
    return real_isspace_l(c, locale);
}

static int (*real_isupper_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_isupper_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(isupper_l)
        pre_fmtd_str str = "isupper_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_isupper_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isupper_l, abii_ret)
    return real_isupper_l(c, locale);
}

static int (*real_isxdigit_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_isxdigit_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(isxdigit_l)
        pre_fmtd_str str = "isxdigit_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_isxdigit_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isxdigit_l, abii_ret)
    return real_isxdigit_l(c, locale);
}

static int (*real_isblank_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_isblank_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(isblank_l)
        pre_fmtd_str str = "isblank_l(c, locale)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "c"));
        abii_args->push_arg(new ArgPrinter(locale, "locale"));

        auto abii_ret = real_isblank_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isblank_l, abii_ret)
    return real_isblank_l(c, locale);
}

static int (*real___tolower_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii___tolower_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(__tolower_l)
        pre_fmtd_str str = "__tolower_l(__c, __l)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(locale, "__l"));

        auto abii_ret = real___tolower_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__tolower_l, abii_ret)
    return real___tolower_l(c, locale);
}

static int (*real_tolower_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_tolower_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(tolower_l)
        pre_fmtd_str str = "tolower_l(__c, __l)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(locale, "__l"));

        auto abii_ret = real_tolower_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tolower_l, abii_ret)
    return real_tolower_l(c, locale);
}

static int (*real___toupper_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii___toupper_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(__toupper_l)
        pre_fmtd_str str = "__toupper_l(__c, __l)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(locale, "__l"));

        auto abii_ret = real___toupper_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__toupper_l, abii_ret)
    return real___toupper_l(c, locale);
}

static int (*real_toupper_l)(int, locale_t) __THROW = nullptr;

extern "C" int abii_toupper_l(int c, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(toupper_l)
        pre_fmtd_str str = "toupper_l(__c, __l)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(locale, "__l"));

        auto abii_ret = real_toupper_l(c, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(toupper_l, abii_ret)
    return real_toupper_l(c, locale);
}
}
