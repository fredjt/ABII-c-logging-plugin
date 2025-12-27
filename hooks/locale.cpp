//
// Created by Trent Tanchin on 12/27/25.
//

#include "locale.h"

#include "bits/types/__locale_t.h"

namespace abii
{
static char* (*real_setlocale)(int, const char*) __THROW = nullptr;

extern "C" char* abii_setlocale(int category, const char* locale) __THROW
{
    OVERRIDE_PREFIX(setlocale)
        pre_fmtd_str str = "setlocale(__category, __locale)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(category, "__category");
        printer->set_enum_printer(print_locale_category, category);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(locale, "__locale"));

        auto abii_ret = real_setlocale(category, locale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setlocale, abii_ret)
    return real_setlocale(category, locale);
}

static lconv* (*real_localeconv)() __THROW = nullptr;

extern "C" lconv* abii_localeconv() __THROW
{
    OVERRIDE_PREFIX(localeconv)
        pre_fmtd_str str = "localeconv()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real_localeconv();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(localeconv, abii_ret)
    return real_localeconv();
}

static locale_t (*real_newlocale)(int, const char*, locale_t) __THROW = nullptr;

extern "C" locale_t abii_newlocale(int category_mask, const char* locale, locale_t base) __THROW
{
    OVERRIDE_PREFIX(newlocale)
        pre_fmtd_str str = "newlocale(__category_mask, __locale, __base)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(category_mask, "__category_mask");
        printer->set_enum_printer(print_locale_category_mask, category_mask);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(locale, "__locale"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_newlocale(category_mask, locale, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(newlocale, abii_ret)
    return real_newlocale(category_mask, locale, base);
}

static locale_t (*real_duplocale)(locale_t) __THROW = nullptr;

extern "C" locale_t abii_duplocale(locale_t dataset) __THROW
{
    OVERRIDE_PREFIX(duplocale)
        pre_fmtd_str str = "duplocale(__dataset)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dataset, "__dataset"));

        auto abii_ret = real_duplocale(dataset);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(duplocale, abii_ret)
    return real_duplocale(dataset);
}

static void (*real_freelocale)(locale_t) __THROW = nullptr;

extern "C" void abii_freelocale(locale_t dataset) __THROW
{
    OVERRIDE_PREFIX(freelocale)
        pre_fmtd_str str = "freelocale(__dataset)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dataset, "__dataset"));

        real_freelocale(dataset);
    OVERRIDE_SUFFIX(freelocale,)
    return real_freelocale(dataset);
}

static locale_t (*real_uselocale)(locale_t) __THROW = nullptr;

extern "C" locale_t abii_uselocale(locale_t dataset) __THROW
{
    OVERRIDE_PREFIX(uselocale)
        pre_fmtd_str str = "uselocale(__dataset)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(dataset, "__dataset");
        printer->set_enum_printer(print_locale_global_locale, dataset);
        abii_args->push_arg(printer);

        auto abii_ret = real_uselocale(dataset);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_locale_global_locale, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(uselocale, abii_ret)
    return real_uselocale(dataset);
}
}
