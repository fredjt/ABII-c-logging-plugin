//
// Created by Trent Tanchin on 11/12/26.
//

#include <abii/libabii.h>

#include "utils/custom_enum_printers/fd.h"

namespace abii
{
static __nonnull((2)) __ssize_t (*real_getdents64)(int, void*, size_t) __THROW = nullptr;

extern "C" __nonnull((2))
__ssize_t abii_getdents64(int fd, void* buffer, size_t length) __THROW
{
    OVERRIDE_PREFIX(getdents64)
        pre_fmtd_str pi_str = "getdents64(__fd, __buffer, __length)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buffer, "__buffer");
        printer1->set_len(length);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(length, "__length"));

        auto abii_ret = real_getdents64(fd, buffer, length);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getdents64, abii_ret)
    return real_getdents64(fd, buffer, length);
}
}
