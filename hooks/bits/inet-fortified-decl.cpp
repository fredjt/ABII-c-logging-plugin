//
// Created by Trent Tanchin on 11/13/26.
//

#include <abii/libabii.h>

#include "socket.h"

namespace abii
{
static const char* (*real___inet_ntop_chk)(int, const void*, char*, socklen_t, size_t) = nullptr;

extern "C" const char* abii___inet_ntop_chk(int af, const void* src, char* dst, socklen_t size, size_t dst_size)
{
    OVERRIDE_PREFIX(__inet_ntop_chk)
        pre_fmtd_str pi_str = "__inet_ntop_chk(af, src, dst, size, dst_size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(af, "af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(src, "src");
        printer1->set_len(size);
        abii_args->push_arg(printer1);

        auto printer2 = new ArgPrinter(dst, "dst");
        printer2->set_len(dst_size);
        abii_args->push_arg(printer2);

        abii_args->push_arg(new ArgPrinter(size, "size"));
        abii_args->push_arg(new ArgPrinter(dst_size, "dst_size"));

        auto abii_ret = real___inet_ntop_chk(af, src, dst, size, dst_size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__inet_ntop_chk, abii_ret)
    return real___inet_ntop_chk(af, src, dst, size, dst_size);
}

static int (*real___inet_pton_chk)(int, const char*, void*, size_t) = nullptr;

extern "C" int abii___inet_pton_chk(int af, const char* src, void* dst, size_t dst_size)
{
    OVERRIDE_PREFIX(__inet_pton_chk)
        pre_fmtd_str pi_str = "__inet_pton_chk(af, src, dst, size, dst_size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(af, "af");
        printer->set_enum_printer(print_socket_addr_family, af);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(src, "src"));

        auto printer1 = new ArgPrinter(dst, "dst");
        printer1->set_len(dst_size);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(dst_size, "dst_size"));

        auto abii_ret = real___inet_pton_chk(af, src, dst, dst_size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__inet_pton_chk, abii_ret)
    return real___inet_pton_chk(af, src, dst, dst_size);
}
}
