//
// Created by Trent Tanchin on 9/23/24.
//

#include "ftw.h"

namespace abii
{
static int (*real_ftw)(const char*, __ftw_func_t, int) = nullptr;

extern "C" __nonnull((1, 2))
int abii_ftw(const char* dir, __ftw_func_t func, int descriptors)
{
    OVERRIDE_PREFIX(ftw)
        pre_fmtd_str str = "ftw(__dir, __func, __descriptors)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dir, "__dir"));
        abii_args->push_arg(new ArgPrinter(func, "__func"));
        abii_args->push_arg(new ArgPrinter(descriptors, "__descriptors"));

        auto abii_ret = real_ftw(dir, func, descriptors);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ftw, abii_ret)
    return real_ftw(dir, func, descriptors);
}

static int (*real_ftw64)(const char*, __ftw64_func_t, int) = nullptr;

extern "C" __nonnull((1, 2))
int abii_ftw64(const char* dir, __ftw64_func_t func, int descriptors)
{
    OVERRIDE_PREFIX(ftw64)
        pre_fmtd_str str = "ftw64(__dir, __func, __descriptors)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dir, "__dir"));
        abii_args->push_arg(new ArgPrinter(func, "__func"));
        abii_args->push_arg(new ArgPrinter(descriptors, "__descriptors"));

        auto abii_ret = real_ftw64(dir, func, descriptors);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ftw64, abii_ret)
    return real_ftw64(dir, func, descriptors);
}

static int (*real_nftw)(const char*, __nftw_func_t, int, int) = nullptr;

extern "C" __nonnull((1, 2))
int abii_nftw(const char* dir, __nftw_func_t func, int descriptors, int flag)
{
    OVERRIDE_PREFIX(nftw)
        pre_fmtd_str str = "nftw(__dir, __func, __descriptors, __flag)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dir, "__dir"));
        abii_args->push_arg(new ArgPrinter(func, "__func"));
        abii_args->push_arg(new ArgPrinter(descriptors, "__descriptors"));

        auto printer = new ArgPrinter(flag, "__flag");
        printer->set_enum_printer(print_ftw_flag, flag);
        abii_args->push_arg(printer);

        auto abii_ret = real_nftw(dir, func, descriptors, flag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(nftw, abii_ret)
    return real_nftw(dir, func, descriptors, flag);
}

static int (*real_nftw64)(const char*, __nftw64_func_t, int, int) = nullptr;

extern "C" __nonnull((1, 2))
int abii_nftw64(const char* dir, __nftw64_func_t func, int descriptors, int flag)
{
    OVERRIDE_PREFIX(nftw64)
        pre_fmtd_str str = "nftw64(__dir, __func, __descriptors, __flag)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dir, "__dir"));
        abii_args->push_arg(new ArgPrinter(func, "__func"));
        abii_args->push_arg(new ArgPrinter(descriptors, "__descriptors"));

        auto printer = new ArgPrinter(flag, "__flag");
        printer->set_enum_printer(print_ftw_flag, flag);
        abii_args->push_arg(printer);

        auto abii_ret = real_nftw64(dir, func, descriptors, flag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(nftw64, abii_ret)
    return real_nftw64(dir, func, descriptors, flag);
}
}
