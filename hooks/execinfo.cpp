//
// Created by Trent Tanchin on 8/17/24.
//

#include <abii/libabii.h>

namespace abii
{
static int (*real_backtrace)(void**, int) = nullptr;

extern "C" __nonnull((1))
int abii_backtrace(void** array, int size)
{
    OVERRIDE_PREFIX(backtrace)
        pre_fmtd_str str = "backtrace(__array, __size)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(array, "__array");
        printer->set_len(size);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_backtrace(array, size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(backtrace, abii_ret)
    return real_backtrace(array, size);
}

static char** (*real_backtrace_symbols)(void* const*, int) __THROW = nullptr;

extern "C" __nonnull((1))
char** abii_backtrace_symbols(void* const* array, int size) __THROW
{
    OVERRIDE_PREFIX(backtrace_symbols)
        pre_fmtd_str str = "backtrace_symbols(__array, __size)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(array, "__array");
        printer->set_len(size);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_backtrace_symbols(array, size);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_len(size);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(backtrace_symbols, abii_ret)
    return real_backtrace_symbols(array, size);
}

static void (*real_backtrace_symbols_fd)(void* const*, int, int) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_backtrace_symbols_fd(void* const * array, int size, int fd) __THROW
{
    OVERRIDE_PREFIX(backtrace_symbols_fd)
        pre_fmtd_str str = "backtrace_symbols_fd(__array, __size, __fd)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(array, "__array");
        printer->set_len(size);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        real_backtrace_symbols_fd(array, size, fd);
    OVERRIDE_SUFFIX(backtrace_symbols_fd,)
    return real_backtrace_symbols_fd(array, size, fd);
}
}
