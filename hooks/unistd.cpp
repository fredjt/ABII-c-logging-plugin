//
// Created by Trent Tanchin on 7/5/26.
//

#include "unistd.h"

#include "custom_enum_printers.h"
#include "custom_printers.h"
#include "fcntl.h"
#include "bits/confname.h"
#include "linux/close_range.h"

namespace abii
{
static __nonnull((1)) int (*real_access)(const char*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_access(const char* name, int type) __THROW

{
    OVERRIDE_PREFIX(access)
        pre_fmtd_str pi_str = "access(__name, __type)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto printer = new ArgPrinter(type, "__type");
        printer->set_enum_printer(print_unistd_access_type, type);
        abii_args->push_arg(printer);

        auto abii_ret = real_access(name, type);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(access, abii_ret)
    return real_access(name, type);
}

static __nonnull((1)) int (*real_euidaccess)(const char*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_euidaccess(const char* name, int type) __THROW

{
    OVERRIDE_PREFIX(euidaccess)
        pre_fmtd_str pi_str = "euidaccess(__name, __type)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto printer = new ArgPrinter(type, "__type");
        printer->set_enum_printer(print_unistd_access_type, type);
        abii_args->push_arg(printer);

        auto abii_ret = real_euidaccess(name, type);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(euidaccess, abii_ret)
    return real_euidaccess(name, type);
}

static __nonnull((1)) int (*real_eaccess)(const char*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_eaccess(const char* name, int type) __THROW
{
    OVERRIDE_PREFIX(eaccess)
        pre_fmtd_str pi_str = "eaccess(__name, __type)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto printer = new ArgPrinter(type, "__type");
        printer->set_enum_printer(print_unistd_access_type, type);
        abii_args->push_arg(printer);

        auto abii_ret = real_eaccess(name, type);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(eaccess, abii_ret)
    return real_eaccess(name, type);
}

static __nonnull((2, 3)) int (*real_execveat)(int, const char*, char* const[], char* const[], int) __THROW = nullptr;

extern "C" __nonnull((2, 3))
int abii_execveat(int fd, const char* path, char* const argv[], char* const envp[], int flags) __THROW
{
    OVERRIDE_PREFIX(execveat)
        pre_fmtd_str pi_str = "execveat(__fd, __path, __argv, __envp, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(path, "__path"));
        abii_args->push_arg(new ArgPrinter(argv, "__argv"));
        abii_args->push_arg(new ArgPrinter(envp, "__envp"));

        auto printer1 = new ArgPrinter(flags, "__flags");
        printer1->set_enum_printer(print_fcntl_execveat, flags);
        abii_args->push_arg(printer1);

        auto abii_ret = real_execveat(fd, path, argv, envp, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(execveat, abii_ret)
    return real_execveat(fd, path, argv, envp, flags);
}

static __nonnull((2)) __wur int (*real_faccessat)(int, const char*, int, int) __THROW = nullptr;

extern "C" __nonnull((2)) __wur
int abii_faccessat(int fd, const char* file, int type, int flag) __THROW
{
    OVERRIDE_PREFIX(faccessat)
        pre_fmtd_str pi_str = "faccessat(__fd, __file, __type, __flag)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(file, "__file"));

        auto printer1 = new ArgPrinter(type, "__type");
        printer1->set_enum_printer(print_unistd_access_type, type);
        abii_args->push_arg(printer1);

        auto printer2 = new ArgPrinter(flag, "__flag");
        printer2->set_enum_printer(print_fcntl_faccessat, flag);
        abii_args->push_arg(printer2);

        auto abii_ret = real_faccessat(fd, file, type, flag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(faccessat, abii_ret)
    return real_faccessat(fd, file, type, flag);
}

static __off_t (*real_lseek)(int, __off_t, int) __THROW = nullptr;

extern "C" __off_t abii_lseek(int fd, __off_t offset, int whence) __THROW
{
    OVERRIDE_PREFIX(lseek)
        pre_fmtd_str pi_str = "lseek(__fd, __offset, __whence)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(offset, "__offset"));

        auto printer1 = new ArgPrinter(whence, "__whence");
        printer1->set_enum_printer(print_unistd_seek_whence, whence);
        abii_args->push_arg(printer1);

        auto abii_ret = real_lseek(fd, offset, whence);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lseek, abii_ret)
    return real_lseek(fd, offset, whence);
}

static __off64_t (*real_lseek64)(int, __off64_t, int) __THROW = nullptr;

extern "C" __off64_t abii_lseek64(int fd, __off64_t offset, int whence) __THROW
{
    OVERRIDE_PREFIX(lseek64)
        pre_fmtd_str pi_str = "lseek64(__fd, __offset, __whence)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(offset, "__offset"));

        auto printer1 = new ArgPrinter(whence, "__whence");
        printer1->set_enum_printer(print_unistd_seek_whence, whence);
        abii_args->push_arg(printer1);

        auto abii_ret = real_lseek64(fd, offset, whence);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lseek64, abii_ret)
    return real_lseek64(fd, offset, whence);
}

static int (*real_close)(int) = nullptr;

extern "C" int abii_close(int fd)
{
    OVERRIDE_PREFIX(close)
        pre_fmtd_str pi_str = "close(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto abii_ret = real_close(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(close, abii_ret)
    return real_close(fd);
}

static void (*real_closefrom)(int) __THROW = nullptr;

extern "C" void abii_closefrom(int lowfd) __THROW
{
    OVERRIDE_PREFIX(closefrom)
        pre_fmtd_str pi_str = "closefrom(__lowfd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(lowfd, "__lowfd");
        printer->set_enum_printer(print_fd_enum_entry, lowfd);
        abii_args->push_arg(printer);

        real_closefrom(lowfd);
    OVERRIDE_SUFFIX(closefrom,)
    return real_closefrom(lowfd);
}

static __wur __fortified_attr_access(__write_only__, 2, 3) ssize_t (*real_read)(int, void*, size_t) = nullptr;

extern "C" __wur __fortified_attr_access(__write_only__, 2, 3)
ssize_t abii_read(int fd, void* buf, size_t nbytes)
{
    OVERRIDE_PREFIX(read)
        pre_fmtd_str pi_str = "read(__fd, __buf, __nbytes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(nbytes);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(nbytes, "__nbytes"));

        auto abii_ret = real_read(fd, buf, nbytes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(read, abii_ret)
    return real_read(fd, buf, nbytes);
}

// The scope-based logger uses write in its destructor, causing recursion
#pragma push_macro("TRACE_LOGGER")
#undef TRACE_LOGGER
#define TRACE_LOGGER

static __wur __attr_access((__read_only__, 2, 3)) ssize_t (*real_write)(int, const void*, size_t) = nullptr;

extern "C" __wur __attr_access((__read_only__, 2, 3))
ssize_t abii_write(int fd, const void* buf, size_t n)
{
    OVERRIDE_PREFIX(write)
        pre_fmtd_str pi_str = "write(__fd, __buf, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_write(fd, buf, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(write, abii_ret)
    return real_write(fd, buf, n);
}
#pragma pop_macro("TRACE_LOGGER")

static __wur __fortified_attr_access(__write_only__, 2, 3)
ssize_t (*real_pread)(int, void*, size_t, __off_t) = nullptr;

extern "C" __wur __fortified_attr_access(__write_only__, 2, 3)
ssize_t abii_pread(int fd, void* buf, size_t nbytes, __off_t offset)
{
    OVERRIDE_PREFIX(pread)
        pre_fmtd_str pi_str = "pread(__fd, __buf, __nbytes, __offset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(nbytes);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(nbytes, "__nbytes"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));

        auto abii_ret = real_pread(fd, buf, nbytes, offset);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pread, abii_ret)
    return real_pread(fd, buf, nbytes, offset);
}

static __wur __attr_access((__read_only__, 2, 3)) ssize_t (*real_pwrite)(int, const void*, size_t, __off_t) = nullptr;

extern "C" __wur __attr_access((__read_only__, 2, 3))
ssize_t abii_pwrite(int fd, const void* buf, size_t n, __off_t offset)
{
    OVERRIDE_PREFIX(pwrite)
        pre_fmtd_str pi_str = "pwrite(__fd, __buf, __n, __offset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));

        auto abii_ret = real_pwrite(fd, buf, n, offset);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pwrite, abii_ret)
    return real_pwrite(fd, buf, n, offset);
}

static __wur __fortified_attr_access(__write_only__, 2, 3)
ssize_t (*real_pread64)(int, void*, size_t, __off64_t) = nullptr;

extern "C" __wur __fortified_attr_access(__write_only__, 2, 3)
ssize_t abii_pread64(int fd, void* buf, size_t nbytes, __off64_t offset)
{
    OVERRIDE_PREFIX(pread64)
        pre_fmtd_str pi_str = "pread64(__fd, __buf, __nbytes, __offset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(nbytes);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(nbytes, "__nbytes"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));

        auto abii_ret = real_pread64(fd, buf, nbytes, offset);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pread64, abii_ret)
    return real_pread64(fd, buf, nbytes, offset);
}

static __wur __attr_access((__read_only__, 2, 3))
ssize_t (*real_pwrite64)(int, const void*, size_t, __off64_t) = nullptr;

extern "C" __wur __attr_access((__read_only__, 2, 3))
ssize_t abii_pwrite64(int fd, const void* buf, size_t n, __off64_t offset)
{
    OVERRIDE_PREFIX(pwrite64)
        pre_fmtd_str pi_str = "pwrite64(__fd, __buf, __n, __offset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(n);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));

        auto abii_ret = real_pwrite64(fd, buf, n, offset);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pwrite, abii_ret)
    return real_pwrite64(fd, buf, n, offset);
}

static __wur int (*real_pipe)(int [2]) __THROW = nullptr;

extern "C" __wur
int abii_pipe(int pipedes[2]) __THROW
{
    OVERRIDE_PREFIX(pipe)
        pre_fmtd_str pi_str = "pipe(__pipedes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(pipedes, "__pipedes");
        printer->set_enum_printer_with_depth(print_fd_enum_entry, *pipedes, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pipe(pipedes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pipe, abii_ret)
    return real_pipe(pipedes);
}

static __wur int (*real_pipe2)(int [2], int) __THROW = nullptr;

extern "C" __wur
int abii_pipe2(int pipedes[2], int flags) __THROW
{
    OVERRIDE_PREFIX(pipe2)
        pre_fmtd_str pi_str = "pipe2(__pipedes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(pipedes, "__pipedes");
        printer->set_enum_printer_with_depth(print_fd_enum_entry, *pipedes, 1);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(pipedes, "__flags");
        printer1->set_enum_printer(print_fcntl_linux_oflag, flags);
        abii_args->push_arg(printer1);

        auto abii_ret = real_pipe2(pipedes, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pipe2, abii_ret)
    return real_pipe2(pipedes, flags);
}

static unsigned int (*real_alarm)(unsigned int) __THROW = nullptr;

extern "C" unsigned int abii_alarm(unsigned int seconds) __THROW
{
    OVERRIDE_PREFIX(alarm)
        pre_fmtd_str pi_str = "alarm(__seconds)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seconds, "__seconds"));

        auto abii_ret = real_alarm(seconds);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(alarm, abii_ret)
    return real_alarm(seconds);
}

static unsigned int (*real_sleep)(unsigned int) = nullptr;

extern "C" unsigned int abii_sleep(unsigned int seconds)
{
    OVERRIDE_PREFIX(sleep)
        pre_fmtd_str pi_str = "sleep(__seconds)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seconds, "__seconds"));

        auto abii_ret = real_sleep(seconds);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sleep, abii_ret)
    return real_sleep(seconds);
}

static __useconds_t (*real_ualarm)(__useconds_t, __useconds_t) __THROW = nullptr;

extern "C" __useconds_t abii_ualarm(__useconds_t value, __useconds_t interval) __THROW
{
    OVERRIDE_PREFIX(ualarm)
        pre_fmtd_str pi_str = "ualarm(__value, __interval)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(interval, "__interval"));

        auto abii_ret = real_ualarm(value, interval);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ualarm, abii_ret)
    return real_ualarm(value, interval);
}

static int (*real_usleep)(__useconds_t) = nullptr;

extern "C" int abii_usleep(__useconds_t useconds)
{
    OVERRIDE_PREFIX(usleep)
        pre_fmtd_str pi_str = "usleep(__useconds)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(useconds, "__useconds"));

        auto abii_ret = real_usleep(useconds);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(usleep, abii_ret)
    return real_usleep(useconds);
}

static int (*real_pause)() = nullptr;

extern "C" int abii_pause()
{
    OVERRIDE_PREFIX(pause)
        pre_fmtd_str pi_str = "pause()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_pause();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pause, abii_ret)
    return real_pause();
}

static __nonnull((1)) __wur int (*real_chown)(const char*, __uid_t, __gid_t) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii_chown(const char* file, __uid_t owner, __gid_t group) __THROW
{
    OVERRIDE_PREFIX(chown)
        pre_fmtd_str pi_str = "chown(__file, __owner, __group)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(owner, "__owner"));
        abii_args->push_arg(new ArgPrinter(group, "__group"));

        auto abii_ret = real_chown(file, owner, group);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(chown, abii_ret)
    return real_chown(file, owner, group);
}

static __wur int (*real_fchown)(int, __uid_t, __gid_t) __THROW = nullptr;

extern "C" __wur
int abii_fchown(int fd, __uid_t owner, __gid_t group) __THROW
{
    OVERRIDE_PREFIX(fchown)
        pre_fmtd_str pi_str = "fchown(__fd, __owner, __group)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(owner, "__owner"));
        abii_args->push_arg(new ArgPrinter(group, "__group"));

        auto abii_ret = real_fchown(fd, owner, group);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fchown, abii_ret)
    return real_fchown(fd, owner, group);
}

static __nonnull((1)) __wur int (*real_lchown)(const char*, __uid_t, __gid_t) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii_lchown(const char* file, __uid_t owner, __gid_t group) __THROW
{
    OVERRIDE_PREFIX(lchown)
        pre_fmtd_str pi_str = "lchown(__file, __owner, __group)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(owner, "__owner"));
        abii_args->push_arg(new ArgPrinter(group, "__group"));

        auto abii_ret = real_lchown(file, owner, group);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lchown, abii_ret)
    return real_lchown(file, owner, group);
}

static __nonnull((2)) __wur int (*real_fchownat)(int, const char*, __uid_t, __gid_t, int) __THROW = nullptr;

extern "C" __nonnull((2)) __wur
int abii_fchownat(int fd, const char* file, __uid_t owner, __gid_t group, int flag) __THROW
{
    OVERRIDE_PREFIX(fchownat)
        pre_fmtd_str pi_str = "fchownat(__fd, __file, __owner, __group, __flag)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(owner, "__owner"));
        abii_args->push_arg(new ArgPrinter(group, "__group"));

        auto printer1 = new ArgPrinter(flag, "__flag");
        printer1->set_enum_printer(print_fcntl_execveat, flag);
        abii_args->push_arg(printer1);

        auto abii_ret = real_fchownat(fd, file, owner, group, flag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fchownat, abii_ret)
    return real_fchownat(fd, file, owner, group, flag);
}

static __nonnull((1)) __wur int (*real_chdir)(const char*) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii_chdir(const char* path) __THROW
{
    OVERRIDE_PREFIX(chdir)
        pre_fmtd_str pi_str = "chdir(__path)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto abii_ret = real_chdir(path);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(chdir, abii_ret)
    return real_chdir(path);
}

static __wur int (*real_fchdir)(int) __THROW = nullptr;

extern "C" __wur
int abii_fchdir(int fd) __THROW
{
    OVERRIDE_PREFIX(fchdir)
        pre_fmtd_str pi_str = "fchdir(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto abii_ret = real_fchdir(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fchdir, abii_ret)
    return real_fchdir(fd);
}

static __wur char* (*real_getcwd)(char*, size_t) __THROW = nullptr;

extern "C" __wur
char* abii_getcwd(char* buf, size_t size) __THROW
{
    OVERRIDE_PREFIX(getcwd)
        pre_fmtd_str pi_str = "getcwd(__buf, __size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(size);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_getcwd(buf, size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getcwd, abii_ret)
    return real_getcwd(buf, size);
}

static char* (*real_get_current_dir_name)() __THROW = nullptr;

extern "C" char* abii_get_current_dir_name() __THROW
{
    OVERRIDE_PREFIX(get_current_dir_name)
        pre_fmtd_str pi_str = "get_current_dir_name()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_get_current_dir_name();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(get_current_dir_name, abii_ret)
    return real_get_current_dir_name();
}

static __nonnull((1)) __wur __attr_access((__write_only__, 1)) char* (*real_getwd)(char*) __THROW = nullptr;

extern "C" __nonnull((1)) __wur __attr_access((__write_only__, 1))
char* abii_getwd(char* buf) __THROW
{
    OVERRIDE_PREFIX(getwd)
        pre_fmtd_str pi_str = "getwd(__buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        auto abii_ret = real_getwd(buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getwd, abii_ret)
    return real_getwd(buf);
}

static __wur int (*real_dup)(int) __THROW = nullptr;

extern "C" __wur
int abii_dup(int fd) __THROW
{
    OVERRIDE_PREFIX(dup)
        pre_fmtd_str pi_str = "dup(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto abii_ret = real_dup(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dup, abii_ret)
    return real_dup(fd);
}

static int (*real_dup2)(int, int) __THROW = nullptr;

extern "C" int abii_dup2(int fd, int fd2) __THROW
{
    OVERRIDE_PREFIX(dup2)
        pre_fmtd_str pi_str = "dup2(__fd, __fd2)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(fd2, "__fd2");
        printer1->set_enum_printer(print_fd_enum_entry, fd2);
        abii_args->push_arg(printer1);

        auto abii_ret = real_dup2(fd, fd2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dup2, abii_ret)
    return real_dup2(fd, fd2);
}

static int (*real_dup3)(int, int, int) __THROW = nullptr;

extern "C" int abii_dup3(int fd, int fd2, int flags) __THROW
{
    OVERRIDE_PREFIX(dup3)
        pre_fmtd_str pi_str = "dup3(__fd, __fd2, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(fd2, "__fd2");
        printer1->set_enum_printer(print_fd_enum_entry, fd2);
        abii_args->push_arg(printer1);

        auto printer2 = new ArgPrinter(flags, "__flags");
        printer2->set_enum_printer(print_fcntl_linux_oflag, flags);
        abii_args->push_arg(printer2);

        auto abii_ret = real_dup3(fd, fd2, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dup3, abii_ret)
    return real_dup3(fd, fd2, flags);
}

static __nonnull((1, 2)) int (*real_execve)(const char*, char* const[], char* const[]) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_execve(const char* path, char* const argv[], char* const envp[]) __THROW
{
    OVERRIDE_PREFIX(execve)
        pre_fmtd_str pi_str = "execve(__path, __argv, __envp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        // TODO: This is a hack to get around ABII's requirement of a non-zero length to honor end_test_
        auto max = SIZE_MAX;
        auto printer = new ArgPrinter(argv, "__argv");
        printer->set_end_test([argv](const size_t i) { return i == 0 || argv[i - 1] != nullptr; });
        printer->set_len(max);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(envp, "__envp");
        printer1->set_end_test([envp](const size_t i) { return i == 0 || envp[i - 1] != nullptr; });
        printer1->set_len(max);
        abii_args->push_arg(printer1);

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        auto abii_ret = real_execve(path, argv, envp);

        // TODO: Figure out how to handle printing the return value if execve fails
        abii_args->push_return(new ArgPrinter(abii_ret, "return"));

        ENABLE_OVERRIDES
        return abii_ret;
    }
    if (real_execve == nullptr)
    {
        real_execve = reinterpret_cast<decltype(real_execve)>(dlsym(RTLD_NEXT, "execve"));
        if (real_execve == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    return real_execve(path, argv, envp);
}

static __nonnull((2)) int (*real_fexecve)(int, char* const[], char* const[]) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_fexecve(int fd, char* const argv[], char* const envp[]) __THROW
{
    OVERRIDE_PREFIX(fexecve)
        pre_fmtd_str pi_str = "fexecve(__fd, __argv, __envp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        // TODO: This is a hack to get around ABII's requirement of a non-zero length to honor end_test_
        auto max = SIZE_MAX;
        auto printer1 = new ArgPrinter(argv, "__argv");
        printer1->set_end_test([argv](const size_t i) { return i == 0 || argv[i - 1] != nullptr; });
        printer1->set_len(max);
        abii_args->push_arg(printer1);

        auto printer2 = new ArgPrinter(envp, "__envp");
        printer2->set_end_test([envp](const size_t i) { return i == 0 || envp[i - 1] != nullptr; });
        printer2->set_len(max);
        abii_args->push_arg(printer2);

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        auto abii_ret = real_fexecve(fd, argv, envp);

        // TODO: Figure out how to handle printing the return value if fexecve fails
        abii_args->push_return(new ArgPrinter(abii_ret, "return"));

        ENABLE_OVERRIDES
        return abii_ret;
    }
    if (real_fexecve == nullptr)
    {
        real_fexecve = reinterpret_cast<decltype(real_fexecve)>(dlsym(RTLD_NEXT, "fexecve"));
        if (real_fexecve == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    return real_fexecve(fd, argv, envp);
}

static __nonnull((1, 2)) int (*real_execv)(const char*, char* const[]) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_execv(const char* path, char* const argv[]) __THROW
{
    OVERRIDE_PREFIX(execv)
        pre_fmtd_str pi_str = "execv(__path, __argv)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        // TODO: This is a hack to get around ABII's requirement of a non-zero length to honor end_test_
        auto max = SIZE_MAX;
        auto printer1 = new ArgPrinter(argv, "__argv");
        printer1->set_end_test([argv](const size_t i) { return i == 0 || argv[i - 1] != nullptr; });
        printer1->set_len(max);
        abii_args->push_arg(printer1);

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        auto abii_ret = real_execv(path, argv);

        // TODO: Figure out how to handle printing the return value if execv fails
        abii_args->push_return(new ArgPrinter(abii_ret, "return"));

        ENABLE_OVERRIDES
        return abii_ret;
    }
    if (real_execv == nullptr)
    {
        real_execv = reinterpret_cast<decltype(real_execv)>(dlsym(RTLD_NEXT, "execv"));
        if (real_execv == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    return real_execv(path, argv);
}

static __nonnull((1, 2)) int (*real_execle)(const char*, const char*, ...) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_execle(const char* path, const char* arg, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(execle,)
        pre_fmtd_str pi_str = "execle(__path, __arg, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));
        abii_args->push_arg(new ArgPrinter(arg, "__argv"));

        // TODO: We need to print all of the values in the environment arg somehow
        auto format = "%s"; // The contents of this string are unimportant; it just shows what is in vargs.
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_execle)

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_execle), abii_bi_vargs, 1000);

        // TODO: Figure out how to handle printing the return value if execle fails
        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));

        va_start(abii_vargs, format);
        abii_args->print_args();
        va_end(abii_vargs);
        delete abii_args;
        abii_stream << std::endl;
        ENABLE_OVERRIDES
        __builtin_return(abii_ret);
    }
    if (real_execle == nullptr)
    {
        real_execle = reinterpret_cast<decltype(real_execle)>(dlsym(RTLD_NEXT, "execle"));
        if (real_execle == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    const auto abii_bi_vargs = __builtin_apply_args();
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_execle), abii_bi_vargs, 1000));
}

static __nonnull((1, 2)) int (*real_execl)(const char*, const char*, ...) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_execl(const char* path, const char* arg, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(execl,)
        pre_fmtd_str pi_str = "execl(__path, __arg, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));
        abii_args->push_arg(new ArgPrinter(arg, "__argv"));

        // TODO: We need to print all of the values in the environment arg somehow
        auto format = "%s"; // The contents of this string are unimportant; it just shows what is in vargs.
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_execl)

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_execl), abii_bi_vargs, 1000);

        // TODO: Figure out how to handle printing the return value if execl fails
        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));

        va_start(abii_vargs, format);
        abii_args->print_args();
        va_end(abii_vargs);
        delete abii_args;
        abii_stream << std::endl;
        ENABLE_OVERRIDES
        __builtin_return(abii_ret);
    }
    if (real_execl == nullptr)
    {
        real_execl = reinterpret_cast<decltype(real_execl)>(dlsym(RTLD_NEXT, "execl"));
        if (real_execl == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    const auto abii_bi_vargs = __builtin_apply_args();
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_execl), abii_bi_vargs, 1000));
}

static __nonnull((1, 2)) int (*real_execvp)(const char*, char* const[]) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_execvp(const char* file, char* const argv[]) __THROW
{
    OVERRIDE_PREFIX(execvp)
        pre_fmtd_str pi_str = "execvp(__file, __argv)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));

        // TODO: This is a hack to get around ABII's requirement of a non-zero length to honor end_test_
        auto max = SIZE_MAX;
        auto printer1 = new ArgPrinter(argv, "__argv");
        printer1->set_end_test([argv](const size_t i) { return i == 0 || argv[i - 1] != nullptr; });
        printer1->set_len(max);
        abii_args->push_arg(printer1);

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        auto abii_ret = real_execvp(file, argv);

        // TODO: Figure out how to handle printing the return value if execvp fails
        abii_args->push_return(new ArgPrinter(abii_ret, "return"));

        ENABLE_OVERRIDES
        return abii_ret;
    }
    if (real_execvp == nullptr)
    {
        real_execvp = reinterpret_cast<decltype(real_execvp)>(dlsym(RTLD_NEXT, "execvp"));
        if (real_execvp == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    return real_execvp(file, argv);
}

static __nonnull((1, 2)) int (*real_execlp)(const char*, const char*, ...) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_execlp(const char* file, const char* arg, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(execlp,)
        pre_fmtd_str pi_str = "execlp(__file, __arg, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(arg, "__argv"));

        // TODO: We need to print all of the values in the environment arg somehow
        auto format = "%s"; // The contents of this string are unimportant; it just shows what is in vargs.
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_execl)

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_execlp), abii_bi_vargs, 1000);

        // TODO: Figure out how to handle printing the return value if execlp fails
        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));

        va_start(abii_vargs, format);
        abii_args->print_args();
        va_end(abii_vargs);
        delete abii_args;
        abii_stream << std::endl;
        ENABLE_OVERRIDES
        __builtin_return(abii_ret);
    }
    if (real_execlp == nullptr)
    {
        real_execlp = reinterpret_cast<decltype(real_execlp)>(dlsym(RTLD_NEXT, "execlp"));
        if (real_execlp == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    const auto abii_bi_vargs = __builtin_apply_args();
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_execlp), abii_bi_vargs, 1000));
}

static __nonnull((1, 2)) int (*real_execvpe)(const char*, char* const[], char* const[]) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_execvpe(const char* file, char* const argv[], char* const envp[]) __THROW
{
    OVERRIDE_PREFIX(execvpe)
        pre_fmtd_str pi_str = "execvpe(__file, __argv, __envp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));

        // TODO: This is a hack to get around ABII's requirement of a non-zero length to honor end_test_
        auto max = SIZE_MAX;
        auto printer = new ArgPrinter(argv, "__argv");
        printer->set_end_test([argv](const size_t i) { return i == 0 || argv[i - 1] != nullptr; });
        printer->set_len(max);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(envp, "__envp");
        printer1->set_end_test([envp](const size_t i) { return i == 0 || envp[i - 1] != nullptr; });
        printer1->set_len(max);
        abii_args->push_arg(printer1);

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        auto abii_ret = real_execvpe(file, argv, envp);

        // TODO: Figure out how to handle printing the return value if execvpe fails
        abii_args->push_return(new ArgPrinter(abii_ret, "return"));

        ENABLE_OVERRIDES
        return abii_ret;
    }
    if (real_execvpe == nullptr)
    {
        real_execvpe = reinterpret_cast<decltype(real_execvpe)>(dlsym(RTLD_NEXT, "execvpe"));
        if (real_execvpe == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    return real_execvpe(file, argv, envp);
}

static __wur int (*real_nice)(int) __THROW = nullptr;

extern "C" __wur
int abii_nice(int inc) __THROW
{
    OVERRIDE_PREFIX(nice)
        pre_fmtd_str pi_str = "nice(__inc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(inc, "__inc"));

        auto abii_ret = real_nice(inc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(nice, abii_ret)
    return real_nice(inc);
}

static __attribute__ ((__noreturn__)) void (*real__exit)(int) __THROW = nullptr;

extern "C" __attribute__ ((__noreturn__))
void abii__exit(int status)
{
    OVERRIDE_PREFIX(_exit)
        pre_fmtd_str pi_str = "_exit(__status)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;
        real__exit(status);
    }
    if (real__exit == nullptr)
    {
        real__exit = reinterpret_cast<decltype(real__exit)>(dlsym(RTLD_NEXT, "_exit"));
        if (real__exit == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real__exit(status);
}

static __nonnull((1)) long int (*real_pathconf)(const char*, int) __THROW = nullptr;

extern "C" __nonnull((1))
long int abii_pathconf(const char* path, int name) __THROW
{
    OVERRIDE_PREFIX(pathconf)
        pre_fmtd_str pi_str = "pathconf(__path, __name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto printer = new ArgPrinter(name, "__name");
        printer->set_enum_printer(print_bits_confname__pc_, name);
        abii_args->push_arg(printer);

        auto abii_ret = real_pathconf(path, name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pathconf, abii_ret)
    return real_pathconf(path, name);
}

static long int (*real_fpathconf)(int, int) __THROW = nullptr;

extern "C" long int abii_fpathconf(int fd, int name) __THROW
{
    OVERRIDE_PREFIX(fpathconf)
        pre_fmtd_str pi_str = "fpathconf(__fd, __name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(name, "__name");
        printer1->set_enum_printer(print_bits_confname__pc_, name);
        abii_args->push_arg(printer1);

        auto abii_ret = real_fpathconf(fd, name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fpathconf, abii_ret)
    return real_fpathconf(fd, name);
}

static long int (*real_sysconf)(int) __THROW = nullptr;

extern "C" long int abii_sysconf(int name) __THROW
{
    OVERRIDE_PREFIX(sysconf)
        pre_fmtd_str pi_str = "sysconf(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(name, "__name");
        printer->set_enum_printer(print_bits_confname__sc_, name);
        abii_args->push_arg(printer);

        auto abii_ret = real_sysconf(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sysconf, abii_ret)
    return real_sysconf(name);
}

static __fortified_attr_access(__write_only__, 2, 3) long int (*real_confstr)(int, char*, size_t) __THROW = nullptr;

extern "C" __fortified_attr_access(__write_only__, 2, 3)
size_t abii_confstr(int name, char* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(confstr)
        pre_fmtd_str pi_str = "confstr(__name, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(name, "__name");
        printer->set_enum_printer(print_bits_confname__cs_, name);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(len);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_confstr(name, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(confstr, abii_ret)
    return real_confstr(name, buf, len);
}

static __pid_t (*real_getpid)() __THROW = nullptr;

extern "C" __pid_t abii_getpid() __THROW
{
    OVERRIDE_PREFIX(getpid)
        pre_fmtd_str pi_str = "getpid()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getpid();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpid, abii_ret)
    return real_getpid();
}

static __pid_t (*real_getppid)() __THROW = nullptr;

extern "C" __pid_t abii_getppid() __THROW
{
    OVERRIDE_PREFIX(getppid)
        pre_fmtd_str pi_str = "getppid()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getppid();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getppid, abii_ret)
    return real_getppid();
}

static __pid_t (*real_getpgrp)() __THROW = nullptr;

extern "C" __pid_t abii_getpgrp() __THROW
{
    OVERRIDE_PREFIX(getpgrp)
        pre_fmtd_str pi_str = "getpgrp()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getpgrp();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpgrp, abii_ret)
    return real_getpgrp();
}

static __pid_t (*real___getpgid)(__pid_t) __THROW = nullptr;

extern "C" __pid_t abii___getpgid(__pid_t pid) __THROW
{
    OVERRIDE_PREFIX(__getpgid)
        pre_fmtd_str pi_str = "__getpgid(__pid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));

        auto abii_ret = real___getpgid(pid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__getpgid, abii_ret)
    return real___getpgid(pid);
}

static __pid_t (*real_getpgid)(__pid_t) __THROW = nullptr;

extern "C" __pid_t abii_getpgid(__pid_t pid) __THROW
{
    OVERRIDE_PREFIX(getpgid)
        pre_fmtd_str pi_str = "getpgid(__pid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));

        auto abii_ret = real_getpgid(pid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpgid, abii_ret)
    return real_getpgid(pid);
}

static int (*real_setpgid)(__pid_t, __pid_t) __THROW = nullptr;

extern "C" int abii_setpgid(__pid_t pid, __pid_t pgid) __THROW
{
    OVERRIDE_PREFIX(setpgid)
        pre_fmtd_str pi_str = "setpgid(__pid, __pgid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));
        abii_args->push_arg(new ArgPrinter(pgid, "__pgid"));

        auto abii_ret = real_setpgid(pid, pgid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setpgid, abii_ret)
    return real_setpgid(pid, pgid);
}

static int (*real_setpgrp)() __THROW = nullptr;

extern "C" int abii_setpgrp() __THROW
{
    OVERRIDE_PREFIX(setpgrp)
        pre_fmtd_str pi_str = "setpgrp()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_setpgrp();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setpgrp, abii_ret)
    return real_setpgrp();
}

static __pid_t (*real_setsid)() __THROW = nullptr;

extern "C" __pid_t abii_setsid() __THROW
{
    OVERRIDE_PREFIX(setsid)
        pre_fmtd_str pi_str = "setsid()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_setsid();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setsid, abii_ret)
    return real_setsid();
}

static __pid_t (*real_getsid)(__pid_t) __THROW = nullptr;

extern "C" __pid_t abii_getsid(__pid_t pid) __THROW
{
    OVERRIDE_PREFIX(getsid)
        pre_fmtd_str pi_str = "getsid(__pid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));

        auto abii_ret = real_getsid(pid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getsid, abii_ret)
    return real_getsid(pid);
}

static __uid_t (*real_getuid)() __THROW = nullptr;

extern "C" __uid_t abii_getuid() __THROW
{
    OVERRIDE_PREFIX(getuid)
        pre_fmtd_str pi_str = "getuid()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getuid();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getuid, abii_ret)
    return real_getuid();
}

static __uid_t (*real_geteuid)() __THROW = nullptr;

extern "C" __uid_t abii_geteuid() __THROW
{
    OVERRIDE_PREFIX(geteuid)
        pre_fmtd_str pi_str = "geteuid()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_geteuid();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(geteuid, abii_ret)
    return real_geteuid();
}

static __gid_t (*real_getgid)() __THROW = nullptr;

extern "C" __gid_t abii_getgid() __THROW
{
    OVERRIDE_PREFIX(getgid)
        pre_fmtd_str pi_str = "getgid()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getgid();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getgid, abii_ret)
    return real_getgid();
}

static __gid_t (*real_getegid)() __THROW = nullptr;

extern "C" __gid_t abii_getegid() __THROW
{
    OVERRIDE_PREFIX(getegid)
        pre_fmtd_str pi_str = "getegid()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getegid();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getegid, abii_ret)
    return real_getegid();
}

static __wur __fortified_attr_access(__write_only__, 2, 1) int (*real_getgroups)(int, __gid_t []) __THROW = nullptr;

extern "C" __wur __fortified_attr_access(__write_only__, 2, 1)
int abii_getgroups(int size, __gid_t list[]) __THROW
{
    OVERRIDE_PREFIX(getgroups)
        pre_fmtd_str pi_str = "getgroups(__size, __list)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto printer = new ArgPrinter(list, "__list");
        printer->set_len(size);
        abii_args->push_arg(printer);

        auto abii_ret = real_getgroups(size, list);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getgroups, abii_ret)
    return real_getgroups(size, list);
}

static int (*real_group_member)(__gid_t) __THROW = nullptr;

extern "C" int abii_group_member(__gid_t gid) __THROW
{
    OVERRIDE_PREFIX(group_member)
        pre_fmtd_str pi_str = "group_member(__gid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(gid, "__gid"));

        auto abii_ret = real_group_member(gid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(group_member, abii_ret)
    return real_group_member(gid);
}

static int (*real_setuid)(__uid_t) __THROW = nullptr;

extern "C" __wur
int abii_setuid(__uid_t uid) __THROW
{
    OVERRIDE_PREFIX(setuid)
        pre_fmtd_str pi_str = "setuid(__uid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(uid, "__uid"));

        auto abii_ret = real_setuid(uid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setuid, abii_ret)
    return real_setuid(uid);
}

static int (*real_setreuid)(__uid_t, __uid_t) __THROW = nullptr;

extern "C" __wur
int abii_setreuid(__uid_t ruid, __uid_t euid) __THROW
{
    OVERRIDE_PREFIX(setreuid)
        pre_fmtd_str pi_str = "setreuid(__ruid, __euid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ruid, "__ruid"));
        abii_args->push_arg(new ArgPrinter(euid, "__euid"));

        auto abii_ret = real_setreuid(ruid, euid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setreuid, abii_ret)
    return real_setreuid(ruid, euid);
}

static int (*real_seteuid)(__uid_t) __THROW = nullptr;

extern "C" __wur
int abii_seteuid(__uid_t uid) __THROW
{
    OVERRIDE_PREFIX(seteuid)
        pre_fmtd_str pi_str = "seteuid(__uid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(uid, "__uid"));

        auto abii_ret = real_seteuid(uid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(seteuid, abii_ret)
    return real_seteuid(uid);
}

static int (*real_setgid)(__gid_t) __THROW = nullptr;

extern "C" __wur
int abii_setgid(__gid_t gid) __THROW
{
    OVERRIDE_PREFIX(setgid)
        pre_fmtd_str pi_str = "setgid(__gid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(gid, "__gid"));

        auto abii_ret = real_setgid(gid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setgid, abii_ret)
    return real_setgid(gid);
}

static int (*real_setregid)(__gid_t, __gid_t) __THROW = nullptr;

extern "C" __wur
int abii_setregid(__gid_t rgid, __gid_t egid) __THROW
{
    OVERRIDE_PREFIX(setregid)
        pre_fmtd_str pi_str = "setregid(__rgid, __egid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rgid, "__rgid"));
        abii_args->push_arg(new ArgPrinter(egid, "__egid"));

        auto abii_ret = real_setregid(rgid, egid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setregid, abii_ret)
    return real_setregid(rgid, egid);
}

static __wur int (*real_setegid)(__gid_t) __THROW = nullptr;

extern "C" __wur int abii_setegid(__gid_t gid) __THROW
{
    OVERRIDE_PREFIX(setegid)
        pre_fmtd_str pi_str = "setegid(__gid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(gid, "__gid"));

        auto abii_ret = real_setegid(gid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setegid, abii_ret)
    return real_setegid(gid);
}

static int (*real_getresuid)(__uid_t*, __uid_t*, __uid_t*) __THROW = nullptr;

extern "C" int abii_getresuid(__uid_t* ruid, __uid_t* euid, __uid_t* suid) __THROW
{
    OVERRIDE_PREFIX(getresuid)
        pre_fmtd_str pi_str = "getresuid(__ruid, __euid, __suid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ruid, "__ruid"));
        abii_args->push_arg(new ArgPrinter(euid, "__euid"));
        abii_args->push_arg(new ArgPrinter(suid, "__suid"));

        auto abii_ret = real_getresuid(ruid, euid, suid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getresuid, abii_ret)
    return real_getresuid(ruid, euid, suid);
}

static int (*real_getresgid)(__gid_t*, __gid_t*, __gid_t*) __THROW = nullptr;

extern "C" int abii_getresgid(__gid_t* rgid, __gid_t* egid, __gid_t* sgid) __THROW
{
    OVERRIDE_PREFIX(getresgid)
        pre_fmtd_str pi_str = "getresgid(__rgid, __egid, __sgid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rgid, "__rgid"));
        abii_args->push_arg(new ArgPrinter(egid, "__egid"));
        abii_args->push_arg(new ArgPrinter(sgid, "__sgid"));

        auto abii_ret = real_getresgid(rgid, egid, sgid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getresgid, abii_ret)
    return real_getresgid(rgid, egid, sgid);
}

static int (*real_setresuid)(__uid_t, __uid_t, __uid_t) __THROW = nullptr;

extern "C" __wur
int abii_setresuid(__uid_t ruid, __uid_t euid, __uid_t suid) __THROW
{
    OVERRIDE_PREFIX(setresuid)
        pre_fmtd_str pi_str = "setresuid(__ruid, __euid, __suid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ruid, "__ruid"));
        abii_args->push_arg(new ArgPrinter(euid, "__euid"));
        abii_args->push_arg(new ArgPrinter(suid, "__suid"));

        auto abii_ret = real_setresuid(ruid, euid, suid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setresuid, abii_ret)
    return real_setresuid(ruid, euid, suid);
}

static int (*real_setresgid)(__gid_t, __gid_t, __gid_t) __THROW = nullptr;

extern "C" __wur
int abii_setresgid(__gid_t rgid, __gid_t egid, __gid_t sgid) __THROW
{
    OVERRIDE_PREFIX(setresgid)
        pre_fmtd_str pi_str = "setresgid(__rgid, __egid, __sgid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rgid, "__rgid"));
        abii_args->push_arg(new ArgPrinter(egid, "__egid"));
        abii_args->push_arg(new ArgPrinter(sgid, "__sgid"));

        auto abii_ret = real_setresgid(rgid, egid, sgid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setresgid, abii_ret)
    return real_setresgid(rgid, egid, sgid);
}

static __pid_t (*real_fork)() __THROWNL = nullptr;

extern "C" __pid_t abii_fork() __THROWNL
{
    OVERRIDE_PREFIX(fork)
        pre_fmtd_str pi_str = "fork()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_fork();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fork, abii_ret)
    return real_fork();
}

static __pid_t (*real_vfork)() __THROW = nullptr;

extern "C" __pid_t abii_vfork() __THROW
{
    OVERRIDE_PREFIX(vfork)
        pre_fmtd_str pi_str = "vfork()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_vfork();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(vfork, abii_ret)
    return real_vfork();
}

static __pid_t (*real__Fork)() __THROW = nullptr;

extern "C" __pid_t abii__Fork() __THROW
{
    OVERRIDE_PREFIX(_Fork)
        pre_fmtd_str pi_str = "_Fork()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real__Fork();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(_Fork, abii_ret)
    return real__Fork();
}

static char* (*real_ttyname)(int) __THROW = nullptr;

extern "C" char* abii_ttyname(int fd) __THROW
{
    OVERRIDE_PREFIX(ttyname)
        pre_fmtd_str pi_str = "ttyname(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto abii_ret = real_ttyname(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ttyname, abii_ret)
    return real_ttyname(fd);
}

static __nonnull((2)) __wur __fortified_attr_access(__write_only__, 2, 3)
int (*real_ttyname_r)(int, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((2)) __wur __fortified_attr_access(__write_only__, 2, 3)
int abii_ttyname_r(int fd, char* buf, size_t buflen) __THROW
{
    OVERRIDE_PREFIX(ttyname_r)
        pre_fmtd_str pi_str = "ttyname_r(__fd, __buf, __buflen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));

        auto abii_ret = real_ttyname_r(fd, buf, buflen);

        auto printer2 = new ArgPrinter(abii_ret, "return");
        printer2->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer2);
    OVERRIDE_SUFFIX(ttyname_r, abii_ret)
    return real_ttyname_r(fd, buf, buflen);
}

static int (*real_isatty)(int) __THROW = nullptr;

extern "C" int abii_isatty(int fd) __THROW
{
    OVERRIDE_PREFIX(isatty)
        pre_fmtd_str pi_str = "isatty(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto abii_ret = real_isatty(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(isatty, abii_ret)
    return real_isatty(fd);
}

extern "C" int abii_ttyslot() __THROW;

static __nonnull((1, 2)) __wur int (*real_link)(const char*, const char*) __THROW = nullptr;

extern "C" __nonnull((1, 2)) __wur
int abii_link(const char* from, const char* to) __THROW
{
    OVERRIDE_PREFIX(link)
        pre_fmtd_str pi_str = "link(__from, __to)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(from, "__from"));
        abii_args->push_arg(new ArgPrinter(to, "__to"));

        auto abii_ret = real_link(from, to);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(link, abii_ret)
    return real_link(from, to);
}

static __nonnull((2, 4)) __wur int (*real_linkat)(int, const char*, int, const char*, int) __THROW = nullptr;

extern "C" __nonnull((2, 4)) __wur
int abii_linkat(int fromfd, const char* from, int tofd, const char* to, int flags) __THROW
{
    OVERRIDE_PREFIX(linkat)
        pre_fmtd_str pi_str = "linkat(__fromfd, __from, __tofd, __to, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fromfd, "__fromfd");
        printer->set_enum_printer(print_fd_enum_entry, fromfd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(from, "__from"));

        auto printer1 = new ArgPrinter(tofd, "__tofd");
        printer1->set_enum_printer(print_fd_enum_entry, tofd);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(to, "__to"));

        auto printer2 = new ArgPrinter(flags, "__flags");
        printer2->set_enum_printer(print_fcntl_linkat, flags);
        abii_args->push_arg(printer2);

        auto abii_ret = real_linkat(fromfd, from, tofd, to, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(linkat, abii_ret)
    return real_linkat(fromfd, from, tofd, to, flags);
}

static __nonnull((1, 2)) __wur int (*real_symlink)(const char*, const char*) __THROW = nullptr;

extern "C" __nonnull((1, 2)) __wur
int abii_symlink(const char* from, const char* to) __THROW
{
    OVERRIDE_PREFIX(symlink)
        pre_fmtd_str pi_str = "symlink(__from, __to)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(from, "__from"));
        abii_args->push_arg(new ArgPrinter(to, "__to"));

        auto abii_ret = real_symlink(from, to);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(symlink, abii_ret)
    return real_symlink(from, to);
}

static __nonnull((1, 2)) __wur __fortified_attr_access(__write_only__, 2, 3)
ssize_t (*real_readlink)(const char*, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1, 2)) __wur __fortified_attr_access(__write_only__, 2, 3)
ssize_t abii_readlink(const char* path, char* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(readlink)
        pre_fmtd_str pi_str = "readlink(__path, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_readlink(path, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(readlink, abii_ret)
    return real_readlink(path, buf, len);
}

static __nonnull((1, 3)) __wur int (*real_symlinkat)(const char*, int, const char*) __THROW = nullptr;

extern "C" __nonnull((1, 3)) __wur
int abii_symlinkat(const char* from, int tofd, const char* to) __THROW
{
    OVERRIDE_PREFIX(symlinkat)
        pre_fmtd_str pi_str = "symlinkat(__from, __tofd, __to)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(from, "__from"));

        auto printer = new ArgPrinter(tofd, "__tofd");
        printer->set_enum_printer(print_fd_enum_entry, tofd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(to, "__to"));

        auto abii_ret = real_symlinkat(from, tofd, to);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(symlinkat, abii_ret)
    return real_symlinkat(from, tofd, to);
}

static __nonnull((2, 3)) __wur __fortified_attr_access(__write_only__, 3, 4)
ssize_t (*real_readlinkat)(int, const char*, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((2, 3)) __wur __fortified_attr_access(__write_only__, 3, 4)
ssize_t abii_readlinkat(int fd, const char* path, char* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(readlinkat)
        pre_fmtd_str pi_str = "readlinkat(__fd, __path, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto printer1 = new ArgPrinter(buf, "__buf");
        printer1->set_len(len);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_readlinkat(fd, path, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(readlinkat, abii_ret)
    return real_readlinkat(fd, path, buf, len);
}

static __nonnull((1)) int (*real_unlink)(const char*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_unlink(const char* name) __THROW
{
    OVERRIDE_PREFIX(unlink)
        pre_fmtd_str pi_str = "unlink(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_unlink(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(unlink, abii_ret)
    return real_unlink(name);
}

static __nonnull((2)) int (*real_unlinkat)(int, const char*, int) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_unlinkat(int fd, const char* name, int flag) __THROW
{
    OVERRIDE_PREFIX(unlinkat)
        pre_fmtd_str pi_str = "unlinkat(__fd, __name, __flag)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto printer1 = new ArgPrinter(flag, "__flag");
        printer1->set_enum_printer(print_fcntl_unlinkat, flag);
        abii_args->push_arg(printer1);

        auto abii_ret = real_unlinkat(fd, name, flag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(unlinkat, abii_ret)
    return real_unlinkat(fd, name, flag);
}

static __nonnull((1)) int (*real_rmdir)(const char*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_rmdir(const char* path) __THROW
{
    OVERRIDE_PREFIX(rmdir)
        pre_fmtd_str pi_str = "rmdir(__path)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto abii_ret = real_rmdir(path);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rmdir, abii_ret)
    return real_rmdir(path);
}

static __pid_t (*real_tcgetpgrp)(int) __THROW = nullptr;

extern "C" __pid_t abii_tcgetpgrp(int fd) __THROW
{
    OVERRIDE_PREFIX(tcgetpgrp)
        pre_fmtd_str pi_str = "tcgetpgrp(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto abii_ret = real_tcgetpgrp(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tcgetpgrp, abii_ret)
    return real_tcgetpgrp(fd);
}

static int (*real_tcsetpgrp)(int, __pid_t) __THROW = nullptr;

extern "C" int abii_tcsetpgrp(int fd, __pid_t pgrp_id) __THROW
{
    OVERRIDE_PREFIX(tcsetpgrp)
        pre_fmtd_str pi_str = "tcsetpgrp(__fd, __pgrp_id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(pgrp_id, "__pgrp_id"));

        auto abii_ret = real_tcsetpgrp(fd, pgrp_id);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tcsetpgrp, abii_ret)
    return real_tcsetpgrp(fd, pgrp_id);
}

static char* (*real_getlogin)() = nullptr;

extern "C" char* abii_getlogin()
{
    OVERRIDE_PREFIX(getlogin)
        pre_fmtd_str pi_str = "getlogin()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getlogin();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getlogin, abii_ret)
    return real_getlogin();
}

static __nonnull((1)) __fortified_attr_access(__write_only__, 1, 2) int (*real_getlogin_r)(char*, size_t) = nullptr;

extern "C" __nonnull((1)) __fortified_attr_access(__write_only__, 1, 2)
int abii_getlogin_r(char* name, size_t name_len)
{
    OVERRIDE_PREFIX(getlogin_r)
        pre_fmtd_str pi_str = "getlogin_r(__name, __name_len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(name_len, "__name_len"));

        auto abii_ret = real_getlogin_r(name, name_len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getlogin_r, abii_ret)
    return real_getlogin_r(name, name_len);
}

static __nonnull((1)) int (*real_setlogin)(const char*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_setlogin(const char* name) __THROW
{
    OVERRIDE_PREFIX(setlogin)
        pre_fmtd_str pi_str = "setlogin(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_setlogin(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setlogin, abii_ret)
    return real_setlogin(name);
}

static __nonnull((1)) __fortified_attr_access(__write_only__, 1, 2)
int (*real_gethostname)(char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1)) __fortified_attr_access(__write_only__, 1, 2)
int abii_gethostname(char* name, size_t len) __THROW
{
    OVERRIDE_PREFIX(gethostname)
        pre_fmtd_str pi_str = "gethostname(__name, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_gethostname(name, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostname, abii_ret)
    return real_gethostname(name, len);
}

static __nonnull((1)) __wur __attr_access((__read_only__, 1, 2))
int (*real_sethostname)(const char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1)) __wur __attr_access((__read_only__, 1, 2))
int abii_sethostname(const char* name, size_t len) __THROW
{
    OVERRIDE_PREFIX(sethostname)
        pre_fmtd_str pi_str = "sethostname(__name, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_sethostname(name, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sethostname, abii_ret)
    return real_sethostname(name, len);
}

static __wur
int (*real_sethostid)(long int) __THROW = nullptr;

extern "C" __wur
int abii_sethostid(long int id) __THROW
{
    OVERRIDE_PREFIX(sethostid)
        pre_fmtd_str pi_str = "sethostid(__id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(id, "__id"));

        auto abii_ret = real_sethostid(id);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sethostid, abii_ret)
    return real_sethostid(id);
}

static __nonnull((1)) __wur __fortified_attr_access(__write_only__, 1, 2)
int (*real_getdomainname)(char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1)) __wur __fortified_attr_access(__write_only__, 1, 2)
int abii_getdomainname(char* name, size_t len) __THROW
{
    OVERRIDE_PREFIX(getdomainname)
        pre_fmtd_str pi_str = "getdomainname(__name, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_getdomainname(name, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getdomainname, abii_ret)
    return real_getdomainname(name, len);
}

static __nonnull((1)) __wur __attr_access((__read_only__, 1, 2))
int (*real_setdomainname)(const char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1)) __wur __attr_access((__read_only__, 1, 2))
int abii_setdomainname(const char* name, size_t len) __THROW
{
    OVERRIDE_PREFIX(setdomainname)
        pre_fmtd_str pi_str = "setdomainname(__name, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_setdomainname(name, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setdomainname, abii_ret)
    return real_setdomainname(name, len);
}

static int (*real_vhangup)() __THROW = nullptr;

extern "C" int abii_vhangup() __THROW
{
    OVERRIDE_PREFIX(vhangup)
        pre_fmtd_str pi_str = "vhangup()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_vhangup();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(vhangup, abii_ret)
    return real_vhangup();
}

static __nonnull((1)) __wur int (*real_revoke)(const char*) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii_revoke(const char* file) __THROW
{
    OVERRIDE_PREFIX(revoke)
        pre_fmtd_str pi_str = "revoke(__file)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));

        auto abii_ret = real_revoke(file);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(revoke, abii_ret)
    return real_revoke(file);
}

static __nonnull((1)) int (*real_profil)(unsigned short int*, size_t, size_t, unsigned int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_profil(unsigned short int* sample_buffer, size_t size, size_t offset, unsigned int scale) __THROW
{
    OVERRIDE_PREFIX(profil)
        pre_fmtd_str pi_str = "profil(__sample_buffer, __size, __offset, __scale)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sample_buffer, "__sample_buffer"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(scale, "__scale"));

        auto abii_ret = real_profil(sample_buffer, size, offset, scale);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(profil, abii_ret)
    return real_profil(sample_buffer, size, offset, scale);
}

static int (*real_acct)(const char*) __THROW = nullptr;

extern "C" int abii_acct(const char* name) __THROW
{
    OVERRIDE_PREFIX(acct)
        pre_fmtd_str pi_str = "acct(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_acct(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(acct, abii_ret)
    return real_acct(name);
}

static char* (*real_getusershell)() __THROW = nullptr;

extern "C" char* abii_getusershell() __THROW
{
    OVERRIDE_PREFIX(getusershell)
        pre_fmtd_str pi_str = "getusershell()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getusershell();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getusershell, abii_ret)
    return real_getusershell();
}

static void (*real_endusershell)() __THROW = nullptr;

extern "C" void abii_endusershell() __THROW
{
    OVERRIDE_PREFIX(endusershell)
        pre_fmtd_str pi_str = "endusershell()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_endusershell();
    OVERRIDE_SUFFIX(endusershell,)
    real_endusershell();
}

static void (*real_setusershell)() __THROW = nullptr;

extern "C" void abii_setusershell() __THROW
{
    OVERRIDE_PREFIX(setusershell)
        pre_fmtd_str pi_str = "setusershell()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_setusershell();
    OVERRIDE_SUFFIX(setusershell,)
    real_setusershell();
}

static __wur int (*real_daemon)(int, int) __THROW = nullptr;

extern "C" __wur
int abii_daemon(int nochdir, int noclose) __THROW
{
    OVERRIDE_PREFIX(daemon)
        pre_fmtd_str pi_str = "daemon(__nochdir, __noclose)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nochdir, "__nochdir"));
        abii_args->push_arg(new ArgPrinter(noclose, "__noclose"));

        auto abii_ret = real_daemon(nochdir, noclose);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(daemon, abii_ret)
    return real_daemon(nochdir, noclose);
}

static __nonnull((1)) __wur int (*real_chroot)(const char*) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii_chroot(const char* path) __THROW
{
    OVERRIDE_PREFIX(chroot)
        pre_fmtd_str pi_str = "chroot(__path)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto abii_ret = real_chroot(path);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(chroot, abii_ret)
    return real_chroot(path);
}

static __nonnull((1)) char* (*real_getpass)(const char*) = nullptr;

extern "C" __nonnull((1))
char* abii_getpass(const char* prompt)
{
    OVERRIDE_PREFIX(getpass)
        pre_fmtd_str pi_str = "getpass(__prompt)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(prompt, "__prompt"));

        auto abii_ret = real_getpass(prompt);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpass, abii_ret)
    return real_getpass(prompt);
}

static int (*real_fsync)(int) = nullptr;

extern "C" int abii_fsync(int fd)
{
    OVERRIDE_PREFIX(fsync)
        pre_fmtd_str pi_str = "fsync(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto abii_ret = real_fsync(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fsync, abii_ret)
    return real_fsync(fd);
}

static int (*real_syncfs)(int) __THROW = nullptr;

extern "C" int abii_syncfs(int fd) __THROW
{
    OVERRIDE_PREFIX(syncfs)
        pre_fmtd_str pi_str = "syncfs(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto abii_ret = real_syncfs(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(syncfs, abii_ret)
    return real_syncfs(fd);
}

static long int (*real_gethostid)() = nullptr;

extern "C" long int abii_gethostid()
{
    OVERRIDE_PREFIX(gethostid)
        pre_fmtd_str pi_str = "gethostid()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_gethostid();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gethostid, abii_ret)
    return real_gethostid();
}

static void (*real_sync)() __THROW = nullptr;

extern "C" void abii_sync() __THROW
{
    OVERRIDE_PREFIX(sync)
        pre_fmtd_str pi_str = "sync()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_sync();
    OVERRIDE_SUFFIX(sync,)
    return real_sync();
}

static __attribute__ ((__const__)) int (*real_getpagesize)() __THROW = nullptr;

extern "C" __attribute__ ((__const__))
int abii_getpagesize() __THROW
{
    OVERRIDE_PREFIX(getpagesize)
        pre_fmtd_str pi_str = "getpagesize()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getpagesize();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpagesize, abii_ret)
    return real_getpagesize();
}

static int (*real_getdtablesize)() __THROW = nullptr;

extern "C" int abii_getdtablesize() __THROW
{
    OVERRIDE_PREFIX(getdtablesize)
        pre_fmtd_str pi_str = "getdtablesize()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getdtablesize();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getdtablesize, abii_ret)
    return real_getdtablesize();
}

static __nonnull((1)) __wur int (*real_truncate)(const char*, __off_t) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii_truncate(const char* file, __off_t length) __THROW
{
    OVERRIDE_PREFIX(truncate)
        pre_fmtd_str pi_str = "truncate(__file, __length)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(length, "__length"));

        auto abii_ret = real_truncate(file, length);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(truncate, abii_ret)
    return real_truncate(file, length);
}

static __nonnull((1)) __wur int (*real_truncate64)(const char*, __off64_t) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii_truncate64(const char* file, __off64_t length) __THROW
{
    OVERRIDE_PREFIX(truncate64)
        pre_fmtd_str pi_str = "truncate64(__file, __length)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(length, "__length"));

        auto abii_ret = real_truncate64(file, length);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(truncate64, abii_ret)
    return real_truncate64(file, length);
}

static __wur int (*real_ftruncate)(int, __off_t) __THROW = nullptr;

extern "C" __wur
int abii_ftruncate(int fd, __off_t length) __THROW
{
    OVERRIDE_PREFIX(ftruncate)
        pre_fmtd_str pi_str = "ftruncate(__fd, __length)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(length, "__length"));

        auto abii_ret = real_ftruncate(fd, length);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ftruncate, abii_ret)
    return real_ftruncate(fd, length);
}

static __wur int (*real_ftruncate64)(int, __off64_t) __THROW = nullptr;

extern "C" __wur
int abii_ftruncate64(int fd, __off64_t length) __THROW
{
    OVERRIDE_PREFIX(ftruncate64)
        pre_fmtd_str pi_str = "ftruncate64(__fd, __length)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(length, "__length"));

        auto abii_ret = real_ftruncate64(fd, length);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ftruncate64, abii_ret)
    return real_ftruncate64(fd, length);
}

static __wur int (*real_brk)(void*) __THROW = nullptr;

extern "C" __wur
int abii_brk(void* addr) __THROW
{
    OVERRIDE_PREFIX(brk)
        pre_fmtd_str pi_str = "brk(__addr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(addr, "__addr"));

        auto abii_ret = real_brk(addr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(brk, abii_ret)
    return real_brk(addr);
}

static __wur void* (*real_sbrk)(intptr_t) __THROW = nullptr;

extern "C" void* abii_sbrk(intptr_t delta) __THROW
{
    OVERRIDE_PREFIX(sbrk)
        pre_fmtd_str pi_str = "sbrk(__delta)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(delta, "__delta"));

        auto abii_ret = real_sbrk(delta);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sbrk, abii_ret)
    return real_sbrk(delta);
}

static long int (*real_syscall)(long int, ...) __THROW = nullptr;

extern "C" long int abii_syscall(long int sysno, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(syscall,)
        pre_fmtd_str pi_str = "syscall(__sysno, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sysno, "__sysno"));

        // The contents of this string are unimportant; it just shows what is in vargs.
        auto format = "%ld%ld%ld%ld%ld%ld";
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_syscall)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_syscall), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter<long int>(*reinterpret_cast<long int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(syscall, abii_ret, format)
    return real_syscall(sysno);
}

extern "C" __wur
int abii_lockf(int fd, int cmd, __off_t len);

extern "C" __wur
int abii_lockf64(int fd, int cmd, __off64_t len);

static ssize_t (*real_copy_file_range)(int, __off64_t*, int, __off64_t*, size_t, unsigned int) = nullptr;

extern "C" ssize_t abii_copy_file_range(int infd, __off64_t* pinoff, int outfd, __off64_t* poutoff, size_t length,
                                        unsigned int flags)
{
    OVERRIDE_PREFIX(copy_file_range)
        pre_fmtd_str pi_str = "copy_file_range(__infd, __pinoff, __outfd, __poutoff, __length, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(infd, "__infd");
        printer->set_enum_printer(print_fd_enum_entry, infd);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(pinoff, "__pinoff"));

        auto printer1 = new ArgPrinter(outfd, "__outfd");
        printer1->set_enum_printer(print_fd_enum_entry, outfd);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(poutoff, "__poutoff"));
        abii_args->push_arg(new ArgPrinter(length, "__length"));
        abii_args->push_arg(new ArgPrinter(flags, "__flags"));

        auto abii_ret = real_copy_file_range(infd, pinoff, outfd, poutoff, length, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(copy_file_range, abii_ret)
    return real_copy_file_range(infd, pinoff, outfd, poutoff, length, flags);
}

static int (*real_fdatasync)(int) = nullptr;

extern "C" int abii_fdatasync(int fildes)
{
    OVERRIDE_PREFIX(fdatasync)
        pre_fmtd_str pi_str = "fdatasync(__fildes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fildes, "__fildes");
        printer->set_enum_printer(print_fd_enum_entry, fildes);
        abii_args->push_arg(printer);

        auto abii_ret = real_fdatasync(fildes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fdatasync, abii_ret)
    return real_fdatasync(fildes);
}

static __nonnull((1, 2)) char* (*real_crypt)(const char*, const char*) = nullptr;

extern "C" __nonnull((1, 2))
char* abii_crypt(const char* key, const char* salt) __THROW
{
    OVERRIDE_PREFIX(crypt)
        pre_fmtd_str pi_str = "crypt(__key, __salt)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key"));
        abii_args->push_arg(new ArgPrinter(salt, "__salt"));

        auto abii_ret = real_crypt(key, salt);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(crypt, abii_ret)
    return real_crypt(key, salt);
}

static __nonnull((1, 2)) __attr_access((__read_only__, 1, 3)) __attr_access((__write_only__, 2, 3))
void (*real_swab)(const void*, void*, ssize_t) = nullptr;

extern "C" __nonnull((1, 2)) __attr_access((__read_only__, 1, 3)) __attr_access((__write_only__, 2, 3))
void abii_swab(const void* from, void* to, ssize_t n) __THROW
{
    OVERRIDE_PREFIX(swab)
        pre_fmtd_str pi_str = "swab(__from, __to, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(from, "__from"));
        abii_args->push_arg(new ArgPrinter(to, "__to"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        real_swab(from, to, n);
    OVERRIDE_SUFFIX(swab,)
    return real_swab(from, to, n);
}

extern "C" char* abii_ctermid(char* s) __THROW;

extern "C" char* abii_cuserid(char* s);

extern "C" int abii_pthread_atfork(void (*prepare)(), void (*parent)(), void (*child)()) __THROW;

static __wur __attr_access((__write_only__, 1, 2)) int (*real_getentropy)(void*, size_t) = nullptr;

extern "C" __wur __attr_access((__write_only__, 1, 2))
int abii_getentropy(void* buffer, size_t length)
{
    OVERRIDE_PREFIX(getentropy)
        pre_fmtd_str pi_str = "getentropy(__buffer, __length)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(length);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(length, "__length"));

        auto abii_ret = real_getentropy(buffer, length);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getentropy, abii_ret)
    return real_getentropy(buffer, length);
}

static int (*real_close_range)(unsigned int, unsigned int, int) __THROW = nullptr;

extern "C" int abii_close_range(unsigned int fd, unsigned int max_fd, int flags) __THROW
{
    OVERRIDE_PREFIX(close_range)
        pre_fmtd_str pi_str = "close_range(__fd, __max_fd, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(fd, "__fd");
        printer->set_enum_printer(print_fd_enum_entry, fd);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(max_fd, "__max_fd");
        printer1->set_enum_printer(print_fd_enum_entry, max_fd);
        abii_args->push_arg(printer1);

        auto printer2 = new ArgPrinter(flags, "__flags");
        printer2->set_enum_printer(print_close_range_close_range, flags);
        abii_args->push_arg(printer2);

        auto abii_ret = real_close_range(fd, max_fd, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(close_range, abii_ret)
    return real_close_range(fd, max_fd, flags);
}
}
