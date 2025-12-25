//
// Created by Trent Tanchin on 7/2/24.
//

#include "aio.h"

#include "custom_enum_printers.h"
#include "bits/types/sigevent_t.h"
#include "bits/types/struct_timespec.h"

namespace abii
{
static void (*real_aio_init)(const aioinit*) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_aio_init(const aioinit* init) __THROW
{
    OVERRIDE_PREFIX(aio_init)
        pre_fmtd_str str = "aio_init(__init)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(init, "__init"));

        real_aio_init(init);
    OVERRIDE_SUFFIX(aio_init,)
    return real_aio_init(init);
}

static int (*real_aio_read)(aiocb*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_aio_read(aiocb* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_read)
        pre_fmtd_str str = "aio_read(__aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_read(aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_read, abii_ret)
    return real_aio_read(aiocbp);
}

static int (*real_aio_write)(aiocb*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_aio_write(aiocb* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_write)
        pre_fmtd_str str = "aio_write(__aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_write(aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_write, abii_ret)
    return real_aio_write(aiocbp);
}

static int (*real_lio_listio)(int, aiocb* const[__restrict_arr], int, sigevent*) __THROW = nullptr;

extern "C" int abii_lio_listio(int mode, aiocb* const list[__restrict_arr], int nent, sigevent* sig) __THROW
{
    OVERRIDE_PREFIX(lio_listio)
        pre_fmtd_str str = "lio_listio(__mode, __list, __nent, __sig)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mode, "__mode"));

        auto printer = new ArgPrinter(list, "__list");
        printer->set_len(nent);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nent, "__nent"));
        abii_args->push_arg(new ArgPrinter(sig, "__sig"));

        auto abii_ret = real_lio_listio(mode, list, nent, sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lio_listio, abii_ret)
    return real_lio_listio(mode, list, nent, sig);
}

static int (*real_aio_error)(const aiocb*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_aio_error(const aiocb* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_error)
        pre_fmtd_str str = "aio_error(__aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_error(aiocbp);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(aio_error, abii_ret)
    return real_aio_error(aiocbp);
}

static __ssize_t (*real_aio_return)(aiocb*) __THROW = nullptr;

extern "C" __nonnull((1))
__ssize_t abii_aio_return(aiocb* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_return)
        pre_fmtd_str str = "aio_return(__aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_return(aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_return, abii_ret)
    return real_aio_return(aiocbp);
}

static int (*real_aio_cancel)(int, aiocb*) __THROW = nullptr;

extern "C" int abii_aio_cancel(int fildes, aiocb* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_cancel)
        pre_fmtd_str str = "aio_cancel(__fildes, __aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fildes, "__fildes"));
        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_cancel(fildes, aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_cancel, abii_ret)
    return real_aio_cancel(fildes, aiocbp);
}

static int (*real_aio_suspend)(const aiocb* const[], int, const timespec*) = nullptr;

extern "C" __nonnull((1))
int abii_aio_suspend(const aiocb* const list[], int nent, const timespec* timeout)
{
    OVERRIDE_PREFIX(aio_suspend)
        pre_fmtd_str str = "aio_suspend(__list, __nent, __timeout)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(list, "__list");
        printer->set_len(nent);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nent, "__nent"));
        abii_args->push_arg(new ArgPrinter(timeout, "__timeout"));

        auto abii_ret = real_aio_suspend(list, nent, timeout);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_suspend, abii_ret)
    return real_aio_suspend(list, nent, timeout);
}

static int (*real_aio_fsync)(int, aiocb*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_aio_fsync(int operation, aiocb* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_fsync)
        pre_fmtd_str str = "aio_fsync(__operation, __aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(operation, "__operation"));
        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_fsync(operation, aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_fsync, abii_ret)
    return real_aio_fsync(operation, aiocbp);
}

static int (*real_aio_read64)(aiocb64*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_aio_read64(aiocb64* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_read64)
        pre_fmtd_str str = "aio_read64(__aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_read64(aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_read64, abii_ret)
    return real_aio_read64(aiocbp);
}

static int (*real_aio_write64)(aiocb64*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_aio_write64(aiocb64* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_write64)
        pre_fmtd_str str = "aio_write64(__aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_write64(aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_write64, abii_ret)
    return real_aio_write64(aiocbp);
}

static int (*real_lio_listio64)(int, aiocb64* const[__restrict_arr], int, sigevent*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_lio_listio64(int mode, aiocb64* const list[__restrict_arr], int nent, sigevent* sig) __THROW
{
    OVERRIDE_PREFIX(lio_listio64)
        pre_fmtd_str str = "lio_listio64(__mode, __list, __nent, __sig)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mode, "__mode"));

        auto printer = new ArgPrinter(list, "__list");
        printer->set_len(nent);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nent, "__nent"));
        abii_args->push_arg(new ArgPrinter(sig, "__sig"));

        auto abii_ret = real_lio_listio64(mode, list, nent, sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lio_listio64, abii_ret)
    return real_lio_listio64(mode, list, nent, sig);
}

static int (*real_aio_error64)(const aiocb64*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_aio_error64(const aiocb64* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_error64)
        pre_fmtd_str str = "aio_error64(__aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_error64(aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_error64, abii_ret)
    return real_aio_error64(aiocbp);
}

static __ssize_t (*real_aio_return64)(aiocb64*) __THROW = nullptr;

extern "C" __nonnull((1))
__ssize_t abii_aio_return64(aiocb64* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_return64)
        pre_fmtd_str str = "aio_return64(__aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_return64(aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_return64, abii_ret)
    return real_aio_return64(aiocbp);
}

static int (*real_aio_cancel64)(int, aiocb64*) __THROW = nullptr;

extern "C" int abii_aio_cancel64(int fildes, aiocb64* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_cancel64)
        pre_fmtd_str str = "aio_cancel64(__fildes, __aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fildes, "__fildes"));
        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_cancel64(fildes, aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_cancel64, abii_ret)
    return real_aio_cancel64(fildes, aiocbp);
}

static int (*real_aio_suspend64)(const aiocb64* const[], int, const timespec*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_aio_suspend64(const aiocb64* const list[], int nent, const timespec* timeout) __THROW
{
    OVERRIDE_PREFIX(aio_suspend64)
        pre_fmtd_str str = "aio_suspend64(__list, __nent, __timeou)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(list, "__list");
        printer->set_len(nent);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nent, "__nent"));
        abii_args->push_arg(new ArgPrinter(timeout, "__timeout"));

        auto abii_ret = real_aio_suspend64(list, nent, timeout);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_suspend64, abii_ret)
    return real_aio_suspend64(list, nent, timeout);
}

static int (*real_aio_fsync64)(int, aiocb64*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_aio_fsync64(int operation, aiocb64* aiocbp) __THROW
{
    OVERRIDE_PREFIX(aio_fsync64)
        pre_fmtd_str str = "aio_fsync64(__operation, __aiocbp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(operation, "__operation"));
        abii_args->push_arg(new ArgPrinter(aiocbp, "__aiocbp"));

        auto abii_ret = real_aio_fsync64(operation, aiocbp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(aio_fsync64, abii_ret)
    return real_aio_fsync64(operation, aiocbp);
}
}
