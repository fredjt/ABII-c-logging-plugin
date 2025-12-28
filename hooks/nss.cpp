//
// Created by Trent Tanchin on 12/27/24.
//

#include "nss.h"

namespace abii
{
static int (*real___nss_configure_lookup)(const char*, const char*) __THROW = nullptr;

extern "C" int abii___nss_configure_lookup(const char* dbname, const char* string) __THROW
{
    OVERRIDE_PREFIX(__nss_configure_lookup)
        pre_fmtd_str pi_str = "__nss_configure_lookup(__dbname, __string)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dbname, "__dbname"));
        abii_args->push_arg(new ArgPrinter(string, "__string"));

        auto abii_ret = real___nss_configure_lookup(dbname, string);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__nss_configure_lookup, abii_ret)
    return real___nss_configure_lookup(dbname, string);
}
}
