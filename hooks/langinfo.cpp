//
// Created by Trent Tanchin on 9/30/24.
//

#include "langinfo.h"

#include "bits/types/__locale_t.h"

namespace abii
{
static char*(*real_nl_langinfo)(nl_item) __THROW = nullptr;

extern "C" char* abii_nl_langinfo(nl_item item) __THROW
{
    OVERRIDE_PREFIX(nl_langinfo)
        pre_fmtd_str str = "nl_langinfo(__item)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(item, "__item");
        printer->set_enum_printer(print_langinfo_item, item);
        abii_args->push_arg(printer);

        auto abii_ret = real_nl_langinfo(item);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(nl_langinfo, abii_ret)
    return real_nl_langinfo(item);
}

static char*(*real_nl_langinfo_l)(nl_item, locale_t) = nullptr;

extern "C" char* abii_nl_langinfo_l(nl_item item, locale_t l)
{
    OVERRIDE_PREFIX(nl_langinfo_l)
        pre_fmtd_str str = "nl_langinfo_l(__item, __l)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(item, "__item");
        printer->set_enum_printer(print_langinfo_item, item);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(l, "__l"));

        auto abii_ret = real_nl_langinfo_l(item, l);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(nl_langinfo_l, abii_ret)
    return real_nl_langinfo_l(item, l);
}
}
