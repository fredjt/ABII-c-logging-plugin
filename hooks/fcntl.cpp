//
// Created by Trent Tanchin on 8/17/24.
//

#include "fcntl.h"

#include "bits/fcntl.h"
#include "custom_enum_printers.h"

namespace abii
{
static int (*real_fcntl)(int, int, ...) = nullptr;

extern "C" int abii_fcntl(int fd, int cmd, ...)
{
    OVERRIDE_PREFIX(fcntl)
        pre_fmtd_str str = "fcntl(__fd, __cmd, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(cmd, "__cmd");
        printer->set_enum_printer(print_fcntl_linux_cmd, cmd);
        abii_args->push_arg(printer);

        va_list vargs;
        va_start(vargs, cmd);
        int abii_ret = 0;
        switch (cmd)
        {
        case F_DUPFD:
        case F_DUPFD_CLOEXEC:
        case F_SETFD:
        case F_SETFL:
        case F_SETOWN:
        case F_SETSIG:
        case F_SETPIPE_SZ:
        case F_ADD_SEALS:
        case F_NOTIFY:
            {
                auto arg = va_arg(vargs, int);
                auto printer1 = new ArgPrinter(arg, "...");
                switch (cmd)
                {
                case F_SETFD:
                    printer1->set_enum_printer(print_fcntl_linux_fd_cloexec, arg);
                    break;
                case F_SETFL:
                    printer1->set_enum_printer(print_fcntl_linux_oflag, arg);
                    break;
                case F_SETSIG:
                    printer1->set_enum_printer(print_signum_enum_entry, arg);
                    break;
                case F_ADD_SEALS:
                    printer1->set_enum_printer(print_fcntl_linux_seal, arg);
                    break;
                case F_NOTIFY:
                    printer1->set_enum_printer(print_fcntl_linux_dir_notification, arg);
                    break;
                default:
                    break;
                }
                abii_args->push_arg(printer1);
                abii_ret = real_fcntl(fd, cmd, arg);
                break;
            }
        case F_SETLK:
        case F_GETLK:
        case F_SETLKW:
            {
                auto arg = va_arg(vargs, flock *);
                abii_args->push_arg(new ArgPrinter(arg, "..."));
                abii_ret = real_fcntl(fd, cmd, arg);
                break;
            }
        case F_SETOWN_EX:
        case F_GETOWN_EX:
            {
                auto arg = va_arg(vargs, f_owner_ex *);
                abii_args->push_arg(new ArgPrinter(arg, "..."));
                abii_ret = real_fcntl(fd, cmd, arg);
                break;
            }
        case F_GET_RW_HINT:
        case F_SET_RW_HINT:
        case F_GET_FILE_RW_HINT:
        case F_SET_FILE_RW_HINT:
            {
                auto arg = va_arg(vargs, uint64_t *);

                auto printer1 = new ArgPrinter(arg, "...");
                printer1->set_enum_printer_with_depth(print_fcntl_linux_rw_hint, *arg, 1);
                abii_args->push_arg(printer1);

                abii_ret = real_fcntl(fd, cmd, arg);
                break;
            }
        default:
            abii_ret = real_fcntl(fd, cmd);
            break;
        }
        va_end(vargs);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        switch (cmd)
        {
        case F_GETFD:
            {
                printer1->set_enum_printer(print_fcntl_linux_fd_cloexec, abii_ret);
                break;
            }
        case F_GETFL:
            printer1->set_enum_printer(print_fcntl_linux_oflag, abii_ret);
            break;
        case F_GETSIG:
            printer1->set_enum_printer(print_signum_enum_entry, abii_ret);
            break;
        case F_GET_SEALS:
            printer1->set_enum_printer(print_fcntl_linux_seal, abii_ret);
            break;
        default:
            break;
        }
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(fcntl, abii_ret)
    return real_fcntl(fd, cmd);
}

static int (*real_fcntl64)(int, int, ...) = nullptr;

extern "C" int abii_fcntl64(int fd, int cmd, ...)
{
    OVERRIDE_PREFIX(fcntl64)
        pre_fmtd_str str = "fcntl64(__fd, __cmd, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(cmd, "__cmd");
        printer->set_enum_printer(print_fcntl_linux_cmd, cmd);
        abii_args->push_arg(printer);

        va_list vargs;
        va_start(vargs, cmd);
        int abii_ret = 0;
        switch (cmd)
        {
        case F_DUPFD:
        case F_DUPFD_CLOEXEC:
        case F_SETFD:
        case F_SETFL:
        case F_SETOWN:
        case F_SETSIG:
        case F_SETPIPE_SZ:
        case F_ADD_SEALS:
        case F_NOTIFY:
            {
                auto arg = va_arg(vargs, int);
                auto printer1 = new ArgPrinter(arg, "...");
                switch (cmd)
                {
                case F_SETFD:
                    printer1->set_enum_printer(print_fcntl_linux_fd_cloexec, arg);
                    break;
                case F_SETFL:
                    printer1->set_enum_printer(print_fcntl_linux_oflag, arg);
                    break;
                case F_SETSIG:
                    printer1->set_enum_printer(print_signum_enum_entry, arg);
                    break;
                case F_ADD_SEALS:
                    printer1->set_enum_printer(print_fcntl_linux_seal, arg);
                    break;
                case F_NOTIFY:
                    printer1->set_enum_printer(print_fcntl_linux_dir_notification, arg);
                    break;
                default:
                    break;
                }
                abii_args->push_arg(printer1);
                abii_ret = real_fcntl64(fd, cmd, arg);
                break;
            }
        case F_SETLK:
        case F_GETLK:
        case F_SETLKW:
            {
                auto arg = va_arg(vargs, flock64 *);
                abii_args->push_arg(new ArgPrinter(arg, "..."));
                abii_ret = real_fcntl64(fd, cmd, arg);
                break;
            }
        case F_SETOWN_EX:
        case F_GETOWN_EX:
            {
                auto arg = va_arg(vargs, f_owner_ex *);
                abii_args->push_arg(new ArgPrinter(arg, "..."));
                abii_ret = real_fcntl64(fd, cmd, arg);
                break;
            }
        case F_GET_RW_HINT:
        case F_SET_RW_HINT:
        case F_GET_FILE_RW_HINT:
        case F_SET_FILE_RW_HINT:
            {
                auto arg = va_arg(vargs, uint64_t *);

                auto printer1 = new ArgPrinter(arg, "...");
                printer1->set_enum_printer_with_depth(print_fcntl_linux_rw_hint, *arg, 1);
                abii_args->push_arg(printer1);

                abii_ret = real_fcntl64(fd, cmd, arg);
                break;
            }
        default:
            abii_ret = real_fcntl64(fd, cmd);
            break;
        }
        va_end(vargs);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        switch (cmd)
        {
        case F_GETFD:
            {
                printer1->set_enum_printer(print_fcntl_linux_fd_cloexec, abii_ret);
                break;
            }
        case F_GETFL:
            printer1->set_enum_printer(print_fcntl_linux_oflag, abii_ret);
            break;
        case F_GETSIG:
            printer1->set_enum_printer(print_signum_enum_entry, abii_ret);
            break;
        case F_GET_SEALS:
            printer1->set_enum_printer(print_fcntl_linux_seal, abii_ret);
            break;
        default:
            break;
        }
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(fcntl64, abii_ret)
    return real_fcntl64(fd, cmd);
}

static int (*real_open)(const char*, int, ...) = nullptr;

extern "C" __nonnull((1))
int abii_open(const char* file, int oflag, ...)
{
    OVERRIDE_PREFIX(open)
        pre_fmtd_str str = "open(__file, __oflag, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        va_list vargs;
        va_start(vargs, oflag);
        int abii_ret = 0;
        if (oflag & O_CREAT || oflag & O_TMPFILE)
        {
            auto arg = va_arg(vargs, mode_t);

            auto printer1 = new ArgPrinter(arg, "...");
            printer1->set_enum_printer(print_fcntl_protection, arg);
            abii_args->push_arg(printer1);

            abii_ret = real_open(file, oflag, arg);
        }
        else
            abii_ret = real_open(file, oflag);
        va_end(vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(open, abii_ret)
    return real_open(file, oflag);
}

static int (*real_open64)(const char*, int, ...) = nullptr;

extern "C" __nonnull((1))
int abii_open64(const char* file, int oflag, ...)
{
    OVERRIDE_PREFIX(open64)
        pre_fmtd_str str = "open64(__file, __oflag, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        va_list vargs;
        va_start(vargs, oflag);
        int abii_ret = 0;
        if (oflag & O_CREAT || oflag & O_TMPFILE)
        {
            auto arg = va_arg(vargs, mode_t);

            auto printer1 = new ArgPrinter(arg, "...");
            printer1->set_enum_printer(print_fcntl_protection, arg);
            abii_args->push_arg(printer1);

            abii_ret = real_open64(file, oflag, arg);
        }
        else
            abii_ret = real_open64(file, oflag);
        va_end(vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(open64, abii_ret)
    return real_open64(file, oflag);
}

static int (*real_openat)(int __fd, const char* __file, int __oflag, ...) = nullptr;

extern "C" __nonnull((2))
int abii_openat(int fd, const char* file, int oflag, ...)
{
    OVERRIDE_PREFIX(openat)
        pre_fmtd_str str = "openat(__fd, __file, __oflag, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(file, "__file"));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        va_list vargs;
        va_start(vargs, oflag);
        int abii_ret = 0;
        if (oflag & O_CREAT || oflag & O_TMPFILE)
        {
            auto arg = va_arg(vargs, mode_t);

            auto printer1 = new ArgPrinter(arg, "...");
            printer1->set_enum_printer(print_fcntl_protection, arg);
            abii_args->push_arg(printer1);

            abii_ret = real_openat(fd, file, oflag, arg);
        }
        else
            abii_ret = real_openat(fd, file, oflag);
        va_end(vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(openat, abii_ret)
    return real_openat(fd, file, oflag);
}

static int (*real_openat64)(int, const char*, int, ...) = nullptr;

extern "C" __nonnull((2))
int abii_openat64(int fd, const char* file, int oflag, ...)
{
    OVERRIDE_PREFIX(openat64)
        pre_fmtd_str str = "openat64(__fd, __file, __oflag, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(file, "__file"));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        va_list vargs;
        va_start(vargs, oflag);
        int abii_ret = 0;
        if (oflag & O_CREAT || oflag & O_TMPFILE)
        {
            auto arg = va_arg(vargs, mode_t);

            auto printer1 = new ArgPrinter(arg, "...");
            printer1->set_enum_printer(print_fcntl_protection, arg);
            abii_args->push_arg(printer1);

            abii_ret = real_openat64(fd, file, oflag, arg);
        }
        else
            abii_ret = real_openat64(fd, file, oflag);
        va_end(vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(openat64, abii_ret)
    return real_openat64(fd, file, oflag);
}

static int (*real_creat)(const char*, mode_t) = nullptr;

extern "C" __nonnull((1))
int abii_creat(const char* file, mode_t mode)
{
    OVERRIDE_PREFIX(creat)
        pre_fmtd_str str = "creat(__file, __mode)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));

        auto printer = new ArgPrinter(mode, "__mode");
        printer->set_enum_printer(print_fcntl_protection, mode);
        abii_args->push_arg(printer);

        auto abii_ret = real_creat(file, mode);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(creat, abii_ret)
    return real_creat(file, mode);
}

static int (*real_creat64)(const char*, mode_t) = nullptr;

extern "C" __nonnull((1))
int abii_creat64(const char* file, mode_t mode)
{
    OVERRIDE_PREFIX(creat64)
        pre_fmtd_str str = "creat64(__file, __mode)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));

        auto printer = new ArgPrinter(mode, "__mode");
        printer->set_enum_printer(print_fcntl_protection, mode);
        abii_args->push_arg(printer);

        auto abii_ret = real_creat64(file, mode);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(creat64, abii_ret)
    return real_creat64(file, mode);
}

static int (*real_lockf)(int, int, off_t) = nullptr;

extern "C" int abii_lockf(int fd, int cmd, off_t len)
{
    OVERRIDE_PREFIX(lockf)
        pre_fmtd_str str = "lockf(__fd, __cmd, __len)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(cmd, "__cmd");
        printer->set_enum_printer(print_fcntl_lockf_cmd, cmd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_lockf(fd, cmd, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lockf, abii_ret)
    return real_lockf(fd, cmd, len);
}

static int (*real_lockf64)(int, int, off64_t) = nullptr;

extern "C" int abii_lockf64(int fd, int cmd, off_t len)
{
    OVERRIDE_PREFIX(lockf64)
        pre_fmtd_str str = "lockf64(__fd, __cmd, __len)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(cmd, "__cmd");
        printer->set_enum_printer(print_fcntl_lockf_cmd, cmd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_lockf64(fd, cmd, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lockf64, abii_ret)
    return real_lockf64(fd, cmd, len);
}

static int (*real_posix_fadvise)(int, off_t, off_t, int) __THROW = nullptr;

extern "C" int abii_posix_fadvise(int fd, off_t offset, off_t len, int advise) __THROW
{
    OVERRIDE_PREFIX(posix_fadvise)
        pre_fmtd_str str = "posix_fadvise(__fd, __offset, __len, __advise)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto printer = new ArgPrinter(advise, "__advise");
        printer->set_enum_printer(print_fcntl_linux_fadvise, advise);
        abii_args->push_arg(printer);

        auto abii_ret = real_posix_fadvise(fd, offset, len, advise);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_fadvise, abii_ret)
    return real_posix_fadvise(fd, offset, len, advise);
}

static int (*real_posix_fadvise64)(int, off64_t, off64_t, int) __THROW = nullptr;

extern "C" int abii_posix_fadvise64(int fd, off_t offset, off_t len, int advise) __THROW
{
    OVERRIDE_PREFIX(posix_fadvise64)
        pre_fmtd_str str = "posix_fadvise64(__fd, __offset, __len, __advise)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto printer = new ArgPrinter(advise, "__advise");
        printer->set_enum_printer(print_fcntl_linux_fadvise, advise);
        abii_args->push_arg(printer);

        auto abii_ret = real_posix_fadvise64(fd, offset, len, advise);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_fadvise64, abii_ret)
    return real_posix_fadvise64(fd, offset, len, advise);
}

static int (*real_posix_fallocate)(int, off_t, off_t) = nullptr;

extern "C" int abii_posix_fallocate(int fd, off_t offset, off_t len)
{
    OVERRIDE_PREFIX(posix_fallocate)
        pre_fmtd_str str = "posix_fallocate(__fd, __offset, __len)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_posix_fallocate(fd, offset, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_fallocate, abii_ret)
    return real_posix_fallocate(fd, offset, len);
}

static int (*real_posix_fallocate64)(int, off64_t, off64_t) = nullptr;

extern "C" int abii_posix_fallocate64(int fd, off_t offset, off_t len)
{
    OVERRIDE_PREFIX(posix_fallocate64)
        pre_fmtd_str str = "posix_fallocate64(__fd, __offset, __len)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_posix_fallocate64(fd, offset, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_fallocate64, abii_ret)
    return real_posix_fallocate64(fd, offset, len);
}
}
