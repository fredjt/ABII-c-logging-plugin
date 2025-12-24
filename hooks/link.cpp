//
// Created by Trent Tanchin on 10/1/24.
//

#include "link.h"

namespace abii
{
static int (*real_dl_iterate_phdr)(int (*)(dl_phdr_info*, size_t, void*), void*) = nullptr;

extern "C" int abii_dl_iterate_phdr(int (*callback)(dl_phdr_info*, size_t, void*), void* data)
{
    OVERRIDE_PREFIX(dl_iterate_phdr)
        pre_fmtd_str str = "dl_iterate_phdr(__callback, __data)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(callback, "__callback"));
        abii_args->push_arg(new ArgPrinter(data, "__data"));

        auto abii_ret = real_dl_iterate_phdr(callback, data);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dl_iterate_phdr, abii_ret)
    return real_dl_iterate_phdr(callback, data);
}
}
