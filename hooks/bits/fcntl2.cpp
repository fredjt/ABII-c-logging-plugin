//
// Created by Trent Tanchin on 11/12/26.
//

#include <abii/libabii.h>

#include "fcntl-linux.h"
#include "utils/custom_enum_printers/fd.h"

namespace abii
{
static __nonnull((1)) int (*real___open_2)(const char*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii___open_2(const char* path, int oflag)
{
    OVERRIDE_PREFIX(__open_2)
        pre_fmtd_str pi_str = "__open_2(__path, __oflag)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        auto abii_ret = real___open_2(path, oflag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__open_2, abii_ret)
    return real___open_2(path, oflag);
}

static __nonnull((1)) int (*real___open64_2)(const char*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii___open64_2(const char* path, int oflag)
{
    OVERRIDE_PREFIX(__open64_2)
        pre_fmtd_str pi_str = "__open64_2(__path, __oflag)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        auto abii_ret = real___open64_2(path, oflag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__open64_2, abii_ret)
    return real___open64_2(path, oflag);
}

static __nonnull((2)) int (*real___openat_2)(int, const char*, int) __THROW = nullptr;

extern "C" __nonnull((2))
int abii___openat_2(int fd, const char* path, int oflag)
{
    OVERRIDE_PREFIX(__openat_2)
        pre_fmtd_str pi_str = "__openat_2(__fd, __path, __oflag)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto printer1 = new ArgPrinter(oflag, "__oflag");
        printer1->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer1);

        auto abii_ret = real___openat_2(fd, path, oflag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__openat_2, abii_ret)
    return real___openat_2(fd, path, oflag);
}

static __nonnull((2)) int (*real___openat64_2)(int, const char*, int) __THROW = nullptr;

extern "C" __nonnull((2))
int abii___openat64_2(int fd, const char* path, int oflag)
{
    OVERRIDE_PREFIX(__openat64_2)
        pre_fmtd_str pi_str = "__openat64_2(__fd, __path, __oflag)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto printer1 = new ArgPrinter(oflag, "__oflag");
        printer1->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer1);

        auto abii_ret = real___openat64_2(fd, path, oflag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__openat64_2, abii_ret)
    return real___openat64_2(fd, path, oflag);
}
}
