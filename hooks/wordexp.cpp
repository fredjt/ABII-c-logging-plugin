//
// Created by Trent Tanchin on 11/8/26.
//

#include "wordexp.h"

namespace abii
{
static int (*real_wordexp)(const char*, wordexp_t*, int) = nullptr;

extern "C" int abii_wordexp(const char* words, wordexp_t* pwordexp, int flags)
{
    OVERRIDE_PREFIX(wordexp)
        pre_fmtd_str pi_str = "wordexp(__words, __pwordexp, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(words, "__words"));
        abii_args->push_arg(new ArgPrinter(pwordexp, "__pwordexp"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_wordexp_wrde_flags, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_wordexp(words, pwordexp, flags);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_wordexp_wrde_ret, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(wordexp, abii_ret)
    return real_wordexp(words, pwordexp, flags);
}

static void (*real_wordfree)(wordexp_t*) __THROW = nullptr;

extern "C" void abii_wordfree(wordexp_t* wordexp) __THROW
{
    OVERRIDE_PREFIX(wordfree)
        pre_fmtd_str pi_str = "wordfree(__wordexp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(wordexp, "__wordexp"));

        real_wordfree(wordexp);
    OVERRIDE_SUFFIX(wordfree,)
    return real_wordfree(wordexp);
}
}
