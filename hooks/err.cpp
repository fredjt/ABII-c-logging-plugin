//
// Created by Trent Tanchin on 8/9/24.
//

#include <abii/libabii.h>

#include "custom_printers.h"

namespace abii
{
static void (*real_warn)(const char*, ...) = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 1, 2))) __COLD
void abii_warn(const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(warn, format)
        pre_fmtd_str str = "warn(__format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_warn), abii_bi_vargs, 1000);
    OVERRIDE_VARIADIC_SUFFIX(warn, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_warn), abii_bi_vargs, 1000));
}

static void (*real_vwarn)(const char*, __gnuc_va_list) = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 1, 0))) __COLD
void abii_vwarn(const char* format, __gnuc_va_list gnuc_va_list)
{
    OVERRIDE_VALIST_PREFIX(vwarn, format, gnuc_va_list)
        pre_fmtd_str str = "vwarn(__format, gnuc_va_list)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, gnuc_va_list, "gnuc_va_list", print_variadic_args_printf)

        real_vwarn(format, gnuc_va_list);
    OVERRIDE_VALIST_SUFFIX(vwarn, , gnuc_va_list)
    return real_vwarn(format, gnuc_va_list);
}

static void (*real_warnx)(const char*, ...) = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 1, 2)))
void abii_warnx(const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(warnx, format)
        pre_fmtd_str str = "warnx(__format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_warnx), abii_bi_vargs, 1000);
    OVERRIDE_VARIADIC_SUFFIX(warnx, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_warnx), abii_bi_vargs, 1000));
}

static void (*real_vwarnx)(const char*, __gnuc_va_list) = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 1, 0)))
void abii_vwarnx(const char* format, __gnuc_va_list gnuc_va_list)
{
    OVERRIDE_VALIST_PREFIX(vwarnx, format, gnuc_va_list)
        pre_fmtd_str str = "vwarnx(__format, gnuc_va_list)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, gnuc_va_list, "gnuc_va_list", print_variadic_args_printf)

        real_vwarnx(format, gnuc_va_list);
    OVERRIDE_VALIST_SUFFIX(vwarnx, , gnuc_va_list)
    return real_vwarnx(format, gnuc_va_list);
}

static void (*real_err)(int, const char*, ...) = nullptr;

extern "C" __attribute__ ((__noreturn__, __format__ (__printf__, 2, 3))) __COLD
void abii_err(int status, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(err, format)
        pre_fmtd_str str = "err(__status, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        va_start(abii_vargs, format);
        abii_args->print_args();
        va_end(abii_vargs);
        abii_stream << std::endl;

        __builtin_apply(reinterpret_cast<void (*)(...)>(real_err), abii_bi_vargs, 1000);
    }
    if (real_err == nullptr)
    {
        real_err = reinterpret_cast<decltype(real_err)>(dlsym(RTLD_NEXT, "err"));
        if (real_err == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    auto bi_vargs = __builtin_apply_args();
    __builtin_apply(reinterpret_cast<void (*)(...)>(real_err), bi_vargs, 1000);
}

static void (*real_verr)(int, const char*, __gnuc_va_list) = nullptr;

extern "C" __attribute__ ((__noreturn__, __format__ (__printf__, 2, 0))) __COLD
void abii_verr(int status, const char* format, __gnuc_va_list gnuc_va_list)
{
    OVERRIDE_VALIST_PREFIX(verr, format, gnuc_va_list)
        pre_fmtd_str str = "verr(__status, __format, gnuc_va_list)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, gnuc_va_list, "gnuc_va_list", print_variadic_args_printf)

        va_copy(abii_vargs, gnuc_va_list);
        abii_args->print_args();
        abii_stream << std::endl;

        real_vwarnx(format, gnuc_va_list);
    }
    if (real_verr == nullptr)
    {
        real_verr = reinterpret_cast<decltype(real_verr)>(dlsym(RTLD_NEXT, "verr"));
        if (real_verr == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real_verr(status, format, gnuc_va_list);
}

static void (*real_errx)(int, const char*, ...) = nullptr;

extern "C" __attribute__ ((__noreturn__, __format__ (__printf__, 2, 3))) __COLD
void abii_errx(int status, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(errx, format)
        pre_fmtd_str str = "errx(__status, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        va_start(abii_vargs, format);
        abii_args->print_args();
        va_end(abii_vargs);
        abii_stream << std::endl;

        __builtin_apply(reinterpret_cast<void (*)(...)>(real_errx), abii_bi_vargs, 1000);
    }
    if (real_errx == nullptr)
    {
        real_errx = reinterpret_cast<decltype(real_errx)>(dlsym(RTLD_NEXT, "errx"));
        if (real_errx == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    auto bi_vargs = __builtin_apply_args();
    __builtin_apply(reinterpret_cast<void (*)(...)>(real_errx), bi_vargs, 1000);
}

static void (*real_verrx)(int, const char*, __gnuc_va_list) = nullptr;

extern "C" __attribute__ ((__noreturn__, __format__ (__printf__, 2, 0)))__COLD
void abii_verrx(int status, const char* format, __gnuc_va_list gnuc_va_list)
{
    OVERRIDE_VALIST_PREFIX(verrx, format, gnuc_va_list)
        pre_fmtd_str str = "verrx(__status, format, gnuc_va_list)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));
        abii_args->push_arg(new ArgPrinter(format, "format"));

        PUSH_VALIST_ARGS(printer, format, gnuc_va_list, "gnuc_va_list", print_variadic_args_printf)

        va_copy(abii_vargs, gnuc_va_list);
        abii_args->print_args();
        abii_stream << std::endl;

        real_vwarnx(format, gnuc_va_list);
    }
    if (real_verrx == nullptr)
    {
        real_verrx = reinterpret_cast<decltype(real_verrx)>(dlsym(RTLD_NEXT, __func__));
        if (real_verrx == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real_verrx(status, format, gnuc_va_list);
}
}
