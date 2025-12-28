//
// Created by Trent Tanchin on 12/26/24.
//

#include "nl_types.h"

#include <nl_types.h>

namespace abii
{
static nl_catd (*real_catopen)(const char*, int) = nullptr;

extern "C" __nonnull((1))
nl_catd abii_catopen(const char* cat_name, int flag)
{
    OVERRIDE_PREFIX(catopen)
        pre_fmtd_str pi_str = "catopen(__cat_name, __flag)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cat_name, "__cat_name"));

        auto printer = new ArgPrinter(flag, "__flag");
        printer->set_enum_printer(print_nl_cat_locale, flag);
        abii_args->push_arg(printer);

        auto abii_ret = real_catopen(cat_name, flag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(catopen, abii_ret)
    return real_catopen(cat_name, flag);
}

static char* (*real_catgets)(nl_catd, int, int, const char*) __THROW = nullptr;

extern "C" __nonnull((1))
char* abii_catgets(nl_catd catalog, int set, int number, const char* string) __THROW
{
    OVERRIDE_PREFIX(catgets)
        pre_fmtd_str pi_str = "catgets(__catalog, __set, __number, __string)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(catalog, "__catalog"));

        auto printer = new ArgPrinter(set, "__set");
        printer->set_enum_printer(print_nl_setd, set);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(number, "__number"));
        abii_args->push_arg(new ArgPrinter(string, "__string"));

        auto abii_ret = real_catgets(catalog, set, number, string);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(catgets, abii_ret)
    return real_catgets(catalog, set, number, string);
}

static int (*real_catclose)(nl_catd) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_catclose(nl_catd catalog) __THROW
{
    OVERRIDE_PREFIX(catclose)
        pre_fmtd_str pi_str = "catclose(__catalog)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(catalog, "__catalog"));

        auto abii_ret = real_catclose(catalog);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(catclose, abii_ret)
    return real_catclose(catalog);
}
}
