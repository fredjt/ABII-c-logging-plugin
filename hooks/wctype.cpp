//
// Created by Trent Tanchin on 11/7/26.
//

#include "wctype.h"

#include "bits/types/__locale_t.h"

namespace abii
{
static wctrans_t (*real_wctrans)(const char*) __THROW = nullptr;

extern "C" wctrans_t abii_wctrans(const char* property) __THROW
{
    OVERRIDE_PREFIX(wctrans)
        pre_fmtd_str pi_str = "wctrans(__property)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(property, "__property"));

        auto abii_ret = real_wctrans(property);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wctrans, abii_ret)
    return real_wctrans(property);
}

static wint_t (*real_towctrans)(wint_t, wctrans_t) __THROW = nullptr;

extern "C" wint_t abii_towctrans(wint_t wc, wctrans_t desc) __THROW
{
    OVERRIDE_PREFIX(towctrans)
        pre_fmtd_str pi_str = "towctrans(__wc, __desc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(desc, "__desc"));

        auto abii_ret = real_towctrans(wc, desc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(towctrans, abii_ret)
    return real_towctrans(wc, desc);
}

static int (*real_iswalnum_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswalnum_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswalnum_l)
        pre_fmtd_str pi_str = "iswalnum_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswalnum_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswalnum_l, abii_ret)
    return real_iswalnum_l(wc, locale);
}

static int (*real_iswalpha_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswalpha_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswalpha_l)
        pre_fmtd_str pi_str = "iswalpha_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswalpha_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswalpha_l, abii_ret)
    return real_iswalpha_l(wc, locale);
}

static int (*real_iswcntrl_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswcntrl_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswcntrl_l)
        pre_fmtd_str pi_str = "iswcntrl_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswcntrl_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswcntrl_l, abii_ret)
    return real_iswcntrl_l(wc, locale);
}

static int (*real_iswdigit_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswdigit_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswdigit_l)
        pre_fmtd_str pi_str = "iswdigit_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswdigit_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswdigit_l, abii_ret)
    return real_iswdigit_l(wc, locale);
}

static int (*real_iswgraph_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswgraph_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswgraph_l)
        pre_fmtd_str pi_str = "iswgraph_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswgraph_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswgraph_l, abii_ret)
    return real_iswgraph_l(wc, locale);
}

static int (*real_iswlower_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswlower_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswlower_l)
        pre_fmtd_str pi_str = "iswlower_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswlower_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswlower_l, abii_ret)
    return real_iswlower_l(wc, locale);
}

static int (*real_iswprint_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswprint_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswprint_l)
        pre_fmtd_str pi_str = "iswprint_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswprint_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswprint_l, abii_ret)
    return real_iswprint_l(wc, locale);
}

static int (*real_iswpunct_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswpunct_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswpunct_l)
        pre_fmtd_str pi_str = "iswpunct_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswpunct_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswpunct_l, abii_ret)
    return real_iswpunct_l(wc, locale);
}

static int (*real_iswspace_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswspace_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswspace_l)
        pre_fmtd_str pi_str = "iswspace_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswspace_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswspace_l, abii_ret)
    return real_iswspace_l(wc, locale);
}

static int (*real_iswupper_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswupper_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswupper_l)
        pre_fmtd_str pi_str = "iswupper_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswupper_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswupper_l, abii_ret)
    return real_iswupper_l(wc, locale);
}

static int (*real_iswxdigit_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswxdigit_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswxdigit_l)
        pre_fmtd_str pi_str = "iswxdigit_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswxdigit_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswxdigit_l, abii_ret)
    return real_iswxdigit_l(wc, locale);
}

static int (*real_iswblank_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswblank_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswblank_l)
        pre_fmtd_str pi_str = "iswblank_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswblank_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswblank_l, abii_ret)
    return real_iswblank_l(wc, locale);
}

static wctype_t (*real_wctype_l)(const char*, locale_t) __THROW = nullptr;

extern "C" wctype_t abii_wctype_l(const char* property, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(wctype_l)
        pre_fmtd_str pi_str = "wctype_l(__property, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(property, "__property"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_wctype_l(property, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wctype_l, abii_ret)
    return real_wctype_l(property, locale);
}

static int (*real_iswctype_l)(wint_t, wctype_t, locale_t) __THROW = nullptr;

extern "C" int abii_iswctype_l(wint_t wc, wctype_t desc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(iswctype_l)
        pre_fmtd_str pi_str = "iswctype_l(__wc, __desc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(desc, "__desc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_iswctype_l(wc, desc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iswctype_l, abii_ret)
    return real_iswctype_l(wc, desc, locale);
}

static wint_t (*real_towlower_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" wint_t abii_towlower_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(towlower_l)
        pre_fmtd_str pi_str = "towlower_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_towlower_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(towlower_l, abii_ret)
    return real_towlower_l(wc, locale);
}

static wint_t (*real_towupper_l)(wint_t, locale_t) __THROW = nullptr;

extern "C" wint_t abii_towupper_l(wint_t wc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(towupper_l)
        pre_fmtd_str pi_str = "towupper_l(__wc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_towupper_l(wc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(towupper_l, abii_ret)
    return real_towupper_l(wc, locale);
}

static wctrans_t (*real_wctrans_l)(const char*, locale_t) __THROW = nullptr;

extern "C" wctrans_t abii_wctrans_l(const char* property, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(wctrans_l)
        pre_fmtd_str pi_str = "wctrans_l(__property, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(property, "__property"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_wctrans_l(property, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wctrans_l, abii_ret)
    return real_wctrans_l(property, locale);
}

static wint_t (*real_towctrans_l)(wint_t, wctrans_t, locale_t) __THROW = nullptr;

extern "C" wint_t abii_towctrans_l(wint_t wc, wctrans_t desc, locale_t locale) __THROW
{
    OVERRIDE_PREFIX(towctrans_l)
        pre_fmtd_str pi_str = "towctrans_l(__wc, __desc, __locale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wc, "__wc"));
        abii_args->push_arg(new ArgPrinter(desc, "__desc"));
        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_towctrans_l(wc, desc, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(towctrans_l, abii_ret)
    return real_towctrans_l(wc, desc, locale);
}
}
