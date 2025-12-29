//
// Created by Trent Tanchin on 5/31/25.
//

#include "stdbit.h"

namespace abii
{
static unsigned int (*real_stdc_leading_zeros_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_zeros_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_zeros_uc)
        pre_fmtd_str pi_str = "stdc_leading_zeros_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_zeros_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_zeros_uc, abii_ret)
    return real_stdc_leading_zeros_uc(x);
}

static unsigned int (*real_stdc_leading_zeros_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_zeros_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_zeros_us)
        pre_fmtd_str pi_str = "stdc_leading_zeros_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_zeros_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_zeros_us, abii_ret)
    return real_stdc_leading_zeros_us(x);
}

static unsigned int (*real_stdc_leading_zeros_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_zeros_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_zeros_ui)
        pre_fmtd_str pi_str = "stdc_leading_zeros_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_zeros_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_zeros_ui, abii_ret)
    return real_stdc_leading_zeros_ui(x);
}

static unsigned int (*real_stdc_leading_zeros_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_zeros_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_zeros_ul)
        pre_fmtd_str pi_str = "stdc_leading_zeros_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_zeros_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_zeros_ul, abii_ret)
    return real_stdc_leading_zeros_ul(x);
}

static unsigned int (*real_stdc_leading_zeros_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_zeros_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_zeros_ull)
        pre_fmtd_str pi_str = "stdc_leading_zeros_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_zeros_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_zeros_ull, abii_ret)
    return real_stdc_leading_zeros_ull(x);
}

static unsigned int (*real_stdc_leading_ones_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_ones_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_ones_uc)
        pre_fmtd_str pi_str = "stdc_leading_ones_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_ones_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_ones_uc, abii_ret)
    return real_stdc_leading_ones_uc(x);
}

static unsigned int (*real_stdc_leading_ones_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_ones_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_ones_us)
        pre_fmtd_str pi_str = "stdc_leading_ones_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_ones_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_ones_us, abii_ret)
    return real_stdc_leading_ones_us(x);
}

static unsigned int (*real_stdc_leading_ones_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_ones_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_ones_ui)
        pre_fmtd_str pi_str = "stdc_leading_ones_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_ones_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_ones_ui, abii_ret)
    return real_stdc_leading_ones_ui(x);
}

static unsigned int (*real_stdc_leading_ones_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_ones_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_ones_ul)
        pre_fmtd_str pi_str = "stdc_leading_ones_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_ones_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_ones_ul, abii_ret)
    return real_stdc_leading_ones_ul(x);
}

static unsigned int (*real_stdc_leading_ones_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_leading_ones_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_leading_ones_ull)
        pre_fmtd_str pi_str = "stdc_leading_ones_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_leading_ones_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_leading_ones_ull, abii_ret)
    return real_stdc_leading_ones_ull(x);
}

static unsigned int (*real_stdc_trailing_zeros_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_zeros_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_zeros_uc)
        pre_fmtd_str pi_str = "stdc_trailing_zeros_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_zeros_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_zeros_uc, abii_ret)
    return real_stdc_trailing_zeros_uc(x);
}

static unsigned int (*real_stdc_trailing_zeros_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_zeros_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_zeros_us)
        pre_fmtd_str pi_str = "stdc_trailing_zeros_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_zeros_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_zeros_us, abii_ret)
    return real_stdc_trailing_zeros_us(x);
}

static unsigned int (*real_stdc_trailing_zeros_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_zeros_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_zeros_ui)
        pre_fmtd_str pi_str = "stdc_trailing_zeros_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_zeros_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_zeros_ui, abii_ret)
    return real_stdc_trailing_zeros_ui(x);
}

static unsigned int (*real_stdc_trailing_zeros_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_zeros_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_zeros_ul)
        pre_fmtd_str pi_str = "stdc_trailing_zeros_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_zeros_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_zeros_ul, abii_ret)
    return real_stdc_trailing_zeros_ul(x);
}

static unsigned int (*real_stdc_trailing_zeros_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_zeros_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_zeros_ull)
        pre_fmtd_str pi_str = "stdc_trailing_zeros_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_zeros_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_zeros_ull, abii_ret)
    return real_stdc_trailing_zeros_ull(x);
}

static unsigned int (*real_stdc_trailing_ones_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_ones_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_ones_uc)
        pre_fmtd_str pi_str = "stdc_trailing_ones_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_ones_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_ones_uc, abii_ret)
    return real_stdc_trailing_ones_uc(x);
}

static unsigned int (*real_stdc_trailing_ones_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_ones_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_ones_us)
        pre_fmtd_str pi_str = "stdc_trailing_ones_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_ones_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_ones_us, abii_ret)
    return real_stdc_trailing_ones_us(x);
}

static unsigned int (*real_stdc_trailing_ones_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_ones_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_ones_ui)
        pre_fmtd_str pi_str = "stdc_trailing_ones_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_ones_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_ones_ui, abii_ret)
    return real_stdc_trailing_ones_ui(x);
}

static unsigned int (*real_stdc_trailing_ones_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_ones_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_ones_ul)
        pre_fmtd_str pi_str = "stdc_trailing_ones_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_ones_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_ones_ul, abii_ret)
    return real_stdc_trailing_ones_ul(x);
}

static unsigned int (*real_stdc_trailing_ones_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_trailing_ones_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_trailing_ones_ull)
        pre_fmtd_str pi_str = "stdc_trailing_ones_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_trailing_ones_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_trailing_ones_ull, abii_ret)
    return real_stdc_trailing_ones_ull(x);
}

static unsigned int (*real_stdc_first_leading_zero_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_zero_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_zero_uc)
        pre_fmtd_str pi_str = "stdc_first_leading_zero_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_zero_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_zero_uc, abii_ret)
    return real_stdc_first_leading_zero_uc(x);
}

#undef stdc_first_leading_zero_us
static unsigned int (*real_stdc_first_leading_zero_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_zero_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_zero_us)
        pre_fmtd_str pi_str = "stdc_first_leading_zero_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_zero_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_zero_us, abii_ret)
    return real_stdc_first_leading_zero_us(x);
}

static unsigned int (*real_stdc_first_leading_zero_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_zero_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_zero_ui)
        pre_fmtd_str pi_str = "stdc_first_leading_zero_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_zero_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_zero_ui, abii_ret)
    return real_stdc_first_leading_zero_ui(x);
}

static unsigned int (*real_stdc_first_leading_zero_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_zero_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_zero_ul)
        pre_fmtd_str pi_str = "stdc_first_leading_zero_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_zero_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_zero_ul, abii_ret)
    return real_stdc_first_leading_zero_ul(x);
}

static unsigned int (*real_stdc_first_leading_zero_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_zero_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_zero_ull)
        pre_fmtd_str pi_str = "stdc_first_leading_zero_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_zero_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_zero_ull, abii_ret)
    return real_stdc_first_leading_zero_ull(x);
}

static unsigned int (*real_stdc_first_leading_one_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_one_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_one_uc)
        pre_fmtd_str pi_str = "stdc_first_leading_one_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_one_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_one_uc, abii_ret)
    return real_stdc_first_leading_one_uc(x);
}

static unsigned int (*real_stdc_first_leading_one_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_one_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_one_us)
        pre_fmtd_str pi_str = "stdc_first_leading_one_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_one_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_one_us, abii_ret)
    return real_stdc_first_leading_one_us(x);
}

#undef stdc_first_leading_one_ui
static unsigned int (*real_stdc_first_leading_one_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_one_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_one_ui)
        pre_fmtd_str pi_str = "stdc_first_leading_one_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_one_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_one_ui, abii_ret)
    return real_stdc_first_leading_one_ui(x);
}

static unsigned int (*real_stdc_first_leading_one_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_one_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_one_ul)
        pre_fmtd_str pi_str = "stdc_first_leading_one_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_one_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_one_ul, abii_ret)
    return real_stdc_first_leading_one_ul(x);
}

static unsigned int (*real_stdc_first_leading_one_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_leading_one_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_leading_one_ull)
        pre_fmtd_str pi_str = "stdc_first_leading_one_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_leading_one_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_leading_one_ull, abii_ret)
    return real_stdc_first_leading_one_ull(x);
}

#undef stdc_first_trailing_zero_uc
static unsigned int (*real_stdc_first_trailing_zero_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_zero_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_zero_uc)
        pre_fmtd_str pi_str = "stdc_first_trailing_zero_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_zero_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_zero_uc, abii_ret)
    return real_stdc_first_trailing_zero_uc(x);
}

static unsigned int (*real_stdc_first_trailing_zero_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_zero_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_zero_us)
        pre_fmtd_str pi_str = "stdc_first_trailing_zero_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_zero_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_zero_us, abii_ret)
    return real_stdc_first_trailing_zero_us(x);
}

static unsigned int (*real_stdc_first_trailing_zero_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_zero_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_zero_ui)
        pre_fmtd_str pi_str = "stdc_first_trailing_zero_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_zero_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_zero_ui, abii_ret)
    return real_stdc_first_trailing_zero_ui(x);
}

static unsigned int (*real_stdc_first_trailing_zero_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_zero_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_zero_ul)
        pre_fmtd_str pi_str = "stdc_first_trailing_zero_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_zero_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_zero_ul, abii_ret)
    return real_stdc_first_trailing_zero_ul(x);
}

static unsigned int (*real_stdc_first_trailing_zero_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_zero_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_zero_ull)
        pre_fmtd_str pi_str = "stdc_first_trailing_zero_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_zero_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_zero_ull, abii_ret)
    return real_stdc_first_trailing_zero_ull(x);
}

#undef stdc_first_trailing_one_uc
static unsigned int (*real_stdc_first_trailing_one_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_one_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_one_uc)
        pre_fmtd_str pi_str = "stdc_first_trailing_one_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_one_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_one_uc, abii_ret)
    return real_stdc_first_trailing_one_uc(x);
}

static unsigned int (*real_stdc_first_trailing_one_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_one_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_one_us)
        pre_fmtd_str pi_str = "stdc_first_trailing_one_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_one_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_one_us, abii_ret)
    return real_stdc_first_trailing_one_us(x);
}

static unsigned int (*real_stdc_first_trailing_one_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_one_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_one_ui)
        pre_fmtd_str pi_str = "stdc_first_trailing_one_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_one_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_one_ui, abii_ret)
    return real_stdc_first_trailing_one_ui(x);
}

static unsigned int (*real_stdc_first_trailing_one_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_one_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_one_ul)
        pre_fmtd_str pi_str = "stdc_first_trailing_one_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_one_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_one_ul, abii_ret)
    return real_stdc_first_trailing_one_ul(x);
}

static unsigned int (*real_stdc_first_trailing_one_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_first_trailing_one_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_first_trailing_one_ull)
        pre_fmtd_str pi_str = "stdc_first_trailing_one_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_first_trailing_one_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_first_trailing_one_ull, abii_ret)
    return real_stdc_first_trailing_one_ull(x);
}

static unsigned int (*real_stdc_count_zeros_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_zeros_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_zeros_uc)
        pre_fmtd_str pi_str = "stdc_count_zeros_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_zeros_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_zeros_uc, abii_ret)
    return real_stdc_count_zeros_uc(x);
}

static unsigned int (*real_stdc_count_zeros_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_zeros_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_zeros_us)
        pre_fmtd_str pi_str = "stdc_count_zeros_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_zeros_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_zeros_us, abii_ret)
    return real_stdc_count_zeros_us(x);
}

static unsigned int (*real_stdc_count_zeros_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_zeros_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_zeros_ui)
        pre_fmtd_str pi_str = "stdc_count_zeros_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_zeros_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_zeros_ui, abii_ret)
    return real_stdc_count_zeros_ui(x);
}

static unsigned int (*real_stdc_count_zeros_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_zeros_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_zeros_ul)
        pre_fmtd_str pi_str = "stdc_count_zeros_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_zeros_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_zeros_ul, abii_ret)
    return real_stdc_count_zeros_ul(x);
}

static unsigned int (*real_stdc_count_zeros_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_zeros_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_zeros_ull)
        pre_fmtd_str pi_str = "stdc_count_zeros_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_zeros_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_zeros_ull, abii_ret)
    return real_stdc_count_zeros_ull(x);
}

static unsigned int (*real_stdc_count_ones_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_ones_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_ones_uc)
        pre_fmtd_str pi_str = "stdc_count_ones_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_ones_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_ones_uc, abii_ret)
    return real_stdc_count_ones_uc(x);
}

static unsigned int (*real_stdc_count_ones_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_ones_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_ones_us)
        pre_fmtd_str pi_str = "stdc_count_ones_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_ones_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_ones_us, abii_ret)
    return real_stdc_count_ones_us(x);
}

static unsigned int (*real_stdc_count_ones_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_ones_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_ones_ui)
        pre_fmtd_str pi_str = "stdc_count_ones_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_ones_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_ones_ui, abii_ret)
    return real_stdc_count_ones_ui(x);
}

static unsigned int (*real_stdc_count_ones_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_ones_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_ones_ul)
        pre_fmtd_str pi_str = "stdc_count_ones_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_ones_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_ones_ul, abii_ret)
    return real_stdc_count_ones_ul(x);
}

static unsigned int (*real_stdc_count_ones_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_count_ones_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_count_ones_ull)
        pre_fmtd_str pi_str = "stdc_count_ones_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_count_ones_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_count_ones_ull, abii_ret)
    return real_stdc_count_ones_ull(x);
}

static bool (*real_stdc_has_single_bit_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
bool abii_stdc_has_single_bit_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_has_single_bit_uc)
        pre_fmtd_str pi_str = "stdc_has_single_bit_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_has_single_bit_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_has_single_bit_uc, abii_ret)
    return real_stdc_has_single_bit_uc(x);
}

static bool (*real_stdc_has_single_bit_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
bool abii_stdc_has_single_bit_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_has_single_bit_us)
        pre_fmtd_str pi_str = "stdc_has_single_bit_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_has_single_bit_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_has_single_bit_us, abii_ret)
    return real_stdc_has_single_bit_us(x);
}

static bool (*real_stdc_has_single_bit_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
bool abii_stdc_has_single_bit_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_has_single_bit_ui)
        pre_fmtd_str pi_str = "stdc_has_single_bit_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_has_single_bit_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_has_single_bit_ui, abii_ret)
    return real_stdc_has_single_bit_ui(x);
}

static bool (*real_stdc_has_single_bit_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
bool abii_stdc_has_single_bit_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_has_single_bit_ul)
        pre_fmtd_str pi_str = "stdc_has_single_bit_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_has_single_bit_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_has_single_bit_ul, abii_ret)
    return real_stdc_has_single_bit_ul(x);
}

static bool (*real_stdc_has_single_bit_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
bool abii_stdc_has_single_bit_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_has_single_bit_ull)
        pre_fmtd_str pi_str = "stdc_has_single_bit_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_has_single_bit_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_has_single_bit_ull, abii_ret)
    return real_stdc_has_single_bit_ull(x);
}

static unsigned int (*real_stdc_bit_width_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_bit_width_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_width_uc)
        pre_fmtd_str pi_str = "stdc_bit_width_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_width_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_width_uc, abii_ret)
    return real_stdc_bit_width_uc(x);
}

static unsigned int (*real_stdc_bit_width_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_bit_width_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_width_us)
        pre_fmtd_str pi_str = "stdc_bit_width_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_width_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_width_us, abii_ret)
    return real_stdc_bit_width_us(x);
}

static unsigned int (*real_stdc_bit_width_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_bit_width_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_width_ui)
        pre_fmtd_str pi_str = "stdc_bit_width_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_width_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_width_ui, abii_ret)
    return real_stdc_bit_width_ui(x);
}

static unsigned int (*real_stdc_bit_width_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_bit_width_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_width_ul)
        pre_fmtd_str pi_str = "stdc_bit_width_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_width_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_width_ul, abii_ret)
    return real_stdc_bit_width_ul(x);
}

static unsigned int (*real_stdc_bit_width_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_bit_width_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_width_ull)
        pre_fmtd_str pi_str = "stdc_bit_width_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_width_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_width_ull, abii_ret)
    return real_stdc_bit_width_ull(x);
}

static unsigned char (*real_stdc_bit_floor_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned char abii_stdc_bit_floor_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_floor_uc)
        pre_fmtd_str pi_str = "stdc_bit_floor_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_floor_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_floor_uc, abii_ret)
    return real_stdc_bit_floor_uc(x);
}

static unsigned short (*real_stdc_bit_floor_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned short abii_stdc_bit_floor_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_floor_us)
        pre_fmtd_str pi_str = "stdc_bit_floor_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_floor_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_floor_us, abii_ret)
    return real_stdc_bit_floor_us(x);
}

static unsigned int (*real_stdc_bit_floor_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_bit_floor_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_floor_ui)
        pre_fmtd_str pi_str = "stdc_bit_floor_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_floor_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_floor_ui, abii_ret)
    return real_stdc_bit_floor_ui(x);
}

static unsigned long int (*real_stdc_bit_floor_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned long int abii_stdc_bit_floor_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_floor_ul)
        pre_fmtd_str pi_str = "stdc_bit_floor_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_floor_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_floor_ul, abii_ret)
    return real_stdc_bit_floor_ul(x);
}

static unsigned long long int (*real_stdc_bit_floor_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned long long int abii_stdc_bit_floor_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_floor_ull)
        pre_fmtd_str pi_str = "stdc_bit_floor_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_floor_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_floor_ull, abii_ret)
    return real_stdc_bit_floor_ull(x);
}

static unsigned char (*real_stdc_bit_ceil_uc)(unsigned char) __THROW = nullptr;

extern "C" __attribute_const__
unsigned char abii_stdc_bit_ceil_uc(unsigned char x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_ceil_uc)
        pre_fmtd_str pi_str = "stdc_bit_ceil_uc(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_ceil_uc(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_ceil_uc, abii_ret)
    return real_stdc_bit_ceil_uc(x);
}

static unsigned short (*real_stdc_bit_ceil_us)(unsigned short) __THROW = nullptr;

extern "C" __attribute_const__
unsigned short abii_stdc_bit_ceil_us(unsigned short x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_ceil_us)
        pre_fmtd_str pi_str = "stdc_bit_ceil_us(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_ceil_us(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_ceil_us, abii_ret)
    return real_stdc_bit_ceil_us(x);
}

static unsigned int (*real_stdc_bit_ceil_ui)(unsigned int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned int abii_stdc_bit_ceil_ui(unsigned int x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_ceil_ui)
        pre_fmtd_str pi_str = "stdc_bit_ceil_ui(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_ceil_ui(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_ceil_ui, abii_ret)
    return real_stdc_bit_ceil_ui(x);
}

static unsigned long int (*real_stdc_bit_ceil_ul)(unsigned long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned long int abii_stdc_bit_ceil_ul(unsigned long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_ceil_ul)
        pre_fmtd_str pi_str = "stdc_bit_ceil_ul(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_ceil_ul(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_ceil_ul, abii_ret)
    return real_stdc_bit_ceil_ul(x);
}

static unsigned long long int (*real_stdc_bit_ceil_ull)(unsigned long long int) __THROW = nullptr;

extern "C" __attribute_const__
unsigned long long int abii_stdc_bit_ceil_ull(unsigned long long int x) __THROW
{
    OVERRIDE_PREFIX(stdc_bit_ceil_ull)
        pre_fmtd_str pi_str = "stdc_bit_ceil_ull(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_stdc_bit_ceil_ull(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(stdc_bit_ceil_ull, abii_ret)
    return real_stdc_bit_ceil_ull(x);
}
}
