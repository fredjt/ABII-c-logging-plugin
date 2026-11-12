//
// Created by Trent Tanchin on 11/12/26.
//

#include "fcntl-linux.h"

#include "hooks/linux/falloc.h"
#include "hooks/linux/openat2.h"
#include "types/struct_iovec.h"
#include "utils/custom_enum_printers/fd.h"

namespace abii
{
static __ssize_t (*real_readahead)(int, __off64_t, size_t) __THROW = nullptr;

extern "C" __ssize_t abii_readahead(int fd, __off64_t offset, size_t count) __THROW
{
    OVERRIDE_PREFIX(readahead)
        pre_fmtd_str pi_str = "readahead(__fd, __offset, __count)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(count, "__count"));

        auto abii_ret = real_readahead(fd, offset, count);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(readahead, abii_ret)
    return real_readahead(fd, offset, count);
}

static int (*real_sync_file_range)(int, __off64_t, __off64_t, unsigned int) = nullptr;

extern "C" int abii_sync_file_range(int fd, __off64_t offset, __off64_t count, unsigned int flags)
{
    OVERRIDE_PREFIX(sync_file_range)
        pre_fmtd_str pi_str = "sync_file_range(__fd, __offset, __count, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(count, "__count"));

        auto printer1 = new ArgPrinter(flags, "__flags");
        printer1->set_enum_printer(print_bits_fcntl_linux_sync_file_range, flags);
        abii_args->push_arg(printer1);

        auto abii_ret = real_sync_file_range(fd, offset, count, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sync_file_range, abii_ret)
    return real_sync_file_range(fd, offset, count, flags);
}

static __ssize_t (*real_vmsplice)(int, const iovec*, size_t, unsigned int) = nullptr;

extern "C" __ssize_t abii_vmsplice(int fdout, const iovec* iov, size_t count, unsigned int flags)
{
    OVERRIDE_PREFIX(vmsplice)
        pre_fmtd_str pi_str = "vmsplice(__fdout, __iov, __count, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fdout, "__fdout");
        printer->set_enum_printer(print_fd, fdout);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(iov, "__iov"));
        abii_args->push_arg(new ArgPrinter(count, "__count"));

        auto printer1 = new ArgPrinter(flags, "__flags");
        printer1->set_enum_printer(print_bits_fcntl_linux_splice, flags);
        abii_args->push_arg(printer1);

        auto abii_ret = real_vmsplice(fdout, iov, count, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(vmsplice, abii_ret)
    return real_vmsplice(fdout, iov, count, flags);
}

static __ssize_t (*real_splice)(int, __off64_t*, int, __off64_t*, size_t, unsigned int) = nullptr;

extern "C" __ssize_t abii_splice(int fdin, __off64_t* offin, int fdout, __off64_t* offout, size_t len,
                                 unsigned int flags)
{
    OVERRIDE_PREFIX(splice)
        pre_fmtd_str pi_str = "splice(__fdin, __offin, __fdout, __offout, __len, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fdin, "__fdin");
        printer->set_enum_printer(print_fd, fdin);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(offin, "__offin"));

        auto printer1 = new ArgPrinter(fdout, "__fdout");
        printer1->set_enum_printer(print_fd, fdout);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(offout, "__offout"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto printer2 = new ArgPrinter(flags, "__flags");
        printer2->set_enum_printer(print_bits_fcntl_linux_splice, flags);
        abii_args->push_arg(printer2);

        auto abii_ret = real_splice(fdin, offin, fdout, offout, len, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(splice, abii_ret)
    return real_splice(fdin, offin, fdout, offout, len, flags);
}

static __ssize_t (*real_tee)(int, int, size_t, unsigned int) = nullptr;

extern "C" __ssize_t abii_tee(int fdin, int fdout, size_t len, unsigned int flags)
{
    OVERRIDE_PREFIX(tee)
        pre_fmtd_str pi_str = "tee(__fdin, __fdout, __len, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fdin, "__fdin");
        printer->set_enum_printer(print_fd, fdin);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(fdout, "__fdout");
        printer1->set_enum_printer(print_fd, fdout);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto printer2 = new ArgPrinter(flags, "__flags");
        printer2->set_enum_printer(print_bits_fcntl_linux_splice, flags);
        abii_args->push_arg(printer2);

        auto abii_ret = real_tee(fdin, fdout, len, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tee, abii_ret)
    return real_tee(fdin, fdout, len, flags);
}

static int (*real_fallocate)(int, int, __off_t, __off_t) = nullptr;

extern "C" int abii_fallocate(int fd, int mode, __off_t offset, __off_t len)
{
    OVERRIDE_PREFIX(fallocate)
        pre_fmtd_str pi_str = "fallocate(__fd, __mode, __offset, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(mode, "__mode");
        printer1->set_enum_printer(print_linux_falloc_fl, mode);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_fallocate(fd, mode, offset, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fallocate, abii_ret)
    return real_fallocate(fd, mode, offset, len);
}

static int (*real_fallocate64)(int, int, __off64_t, __off64_t) = nullptr;

extern "C" int abii_fallocate64(int fd, int mode, __off64_t offset, __off64_t len)
{
    OVERRIDE_PREFIX(fallocate64)
        pre_fmtd_str pi_str = "fallocate64(__fd, __mode, __offset, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(mode, "__mode");
        printer1->set_enum_printer(print_linux_falloc_fl, mode);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_fallocate64(fd, mode, offset, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fallocate64, abii_ret)
    return real_fallocate64(fd, mode, offset, len);
}

static int (*real_name_to_handle_at)(int, const char*, file_handle*, int*, int) __THROW = nullptr;

extern "C" int abii_name_to_handle_at(int dfd, const char* name, file_handle* handle, int* mnt_id, int flags) __THROW
{
    OVERRIDE_PREFIX(name_to_handle_at)
        pre_fmtd_str pi_str = "name_to_handle_at(__dfd, __name, __handle, __mnt_id, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(dfd, "__dfd");
        printer->set_enum_printer(print_fd, dfd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(handle, "__handle"));
        abii_args->push_arg(new ArgPrinter(mnt_id, "__mnt_id"));

        auto printer1 = new ArgPrinter(flags, "__flags");
        printer1->set_enum_printer(print_bits_fcntl_linux_at_handle, flags);
        abii_args->push_arg(printer1);

        auto abii_ret = real_name_to_handle_at(dfd, name, handle, mnt_id, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(name_to_handle_at, abii_ret)
    return real_name_to_handle_at(dfd, name, handle, mnt_id, flags);
}

static int (*real_open_by_handle_at)(int, file_handle*, int) = nullptr;

extern "C" int abii_open_by_handle_at(int mountdirfd, file_handle* handle, int flags)
{
    OVERRIDE_PREFIX(open_by_handle_at)
        pre_fmtd_str pi_str = "open_by_handle_at(__mountdirfd, __handle, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(mountdirfd, "__mountdirfd");
        printer->set_enum_printer(print_fd, mountdirfd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(handle, "__handle"));

        auto printer1 = new ArgPrinter(flags, "__flags");
        printer1->set_enum_printer(print_bits_fcntl_linux_oflag, flags);
        abii_args->push_arg(printer1);

        auto abii_ret = real_open_by_handle_at(mountdirfd, handle, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(open_by_handle_at, abii_ret)
    return real_open_by_handle_at(mountdirfd, handle, flags);
}

static __nonnull((2, 3)) int (*real_openat2)(int, const char*, const open_how*, __SIZE_TYPE__) = nullptr;

extern "C" __nonnull((2, 3))
int abii_openat2(int dfd, const char* filename, const open_how* how, __SIZE_TYPE__ usize)

{
    OVERRIDE_PREFIX(openat2)
        pre_fmtd_str pi_str = "openat2(__dfd, __filename, __how, __usize)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(dfd, "__dfd");
        printer->set_enum_printer(print_fd, dfd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(filename, "__filename"));
        abii_args->push_arg(new ArgPrinter(how, "__how"));
        abii_args->push_arg(new ArgPrinter(usize, "__usize"));

        auto abii_ret = real_openat2(dfd, filename, how, usize);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(openat2, abii_ret)
    return real_openat2(dfd, filename, how, usize);
}
}
