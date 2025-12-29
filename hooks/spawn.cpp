//
// Created by Trent Tanchin on 5/26/25.
//

#include "spawn.h"

#include "fcntl.h"
#include "bits/fcntl-linux.h"

namespace abii
{
static int (*real_posix_spawn)(pid_t*, const char*, const posix_spawn_file_actions_t*, const posix_spawnattr_t*,
                               char* const[__restrict_arr], char* const[__restrict_arr]) = nullptr;

extern "C" __nonnull((2, 5))
int abii_posix_spawn(pid_t* pid, const char* path, const posix_spawn_file_actions_t* file_actions,
                     const posix_spawnattr_t* attrp, char* const argv[__restrict_arr], char* const envp[__restrict_arr])
{
    OVERRIDE_PREFIX(posix_spawn)
        pre_fmtd_str pi_str = "posix_spawn(__pid, __path, __file_actions, __attrp, __argv, __envp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));
        abii_args->push_arg(new ArgPrinter(path, "__path"));
        abii_args->push_arg(new ArgPrinter(file_actions, "__file_actions"));
        abii_args->push_arg(new ArgPrinter(attrp, "__attrp"));
        abii_args->push_arg(new ArgPrinter(argv, "__argv"));
        abii_args->push_arg(new ArgPrinter(envp, "__envp"));

        auto abii_ret = real_posix_spawn(pid, path, file_actions, attrp, argv, envp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn, abii_ret)
    return real_posix_spawn(pid, path, file_actions, attrp, argv, envp);
}

static int (*real_posix_spawnp)(pid_t*, const char*, const posix_spawn_file_actions_t*, const posix_spawnattr_t*,
                                char* const[], char* const[]) = nullptr;

extern "C" __nonnull((2, 5))
int abii_posix_spawnp(pid_t* pid, const char* file, const posix_spawn_file_actions_t* file_actions,
                      const posix_spawnattr_t* attrp, char* const argv[], char* const envp[])
{
    OVERRIDE_PREFIX(posix_spawnp)
        pre_fmtd_str pi_str = "posix_spawnp(__pid, __file, __file_actions, __attrp, __argv, __envp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));
        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(file_actions, "__file_actions"));
        abii_args->push_arg(new ArgPrinter(attrp, "__attrp"));
        abii_args->push_arg(new ArgPrinter(argv, "__argv"));
        abii_args->push_arg(new ArgPrinter(envp, "__envp"));

        auto abii_ret = real_posix_spawnp(pid, file, file_actions, attrp, argv, envp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnp, abii_ret)
    return real_posix_spawnp(pid, file, file_actions, attrp, argv, envp);
}

static int (*real_posix_spawnattr_init)(posix_spawnattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawnattr_init(posix_spawnattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_init)
        pre_fmtd_str pi_str = "posix_spawnattr_init(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_posix_spawnattr_init(attr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_init, abii_ret)
    return real_posix_spawnattr_init(attr);
}

static int (*real_posix_spawnattr_destroy)(posix_spawnattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawnattr_destroy(posix_spawnattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_destroy)
        pre_fmtd_str pi_str = "posix_spawnattr_destroy(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_posix_spawnattr_destroy(attr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_destroy, abii_ret)
    return real_posix_spawnattr_destroy(attr);
}

static int (*real_posix_spawnattr_getsigdefault)(const posix_spawnattr_t*, sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawnattr_getsigdefault(const posix_spawnattr_t* attr, sigset_t* sigdefault) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_getsigdefault)
        pre_fmtd_str pi_str = "posix_spawnattr_getsigdefault(__attr, __sigdefault)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(sigdefault, "__sigdefault"));

        auto abii_ret = real_posix_spawnattr_getsigdefault(attr, sigdefault);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_getsigdefault, abii_ret)
    return real_posix_spawnattr_getsigdefault(attr, sigdefault);
}

static int (*real_posix_spawnattr_setsigdefault)(posix_spawnattr_t*, const sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawnattr_setsigdefault(posix_spawnattr_t* attr, const sigset_t* sigdefault) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_setsigdefault)
        pre_fmtd_str pi_str = "posix_spawnattr_setsigdefault(__attr, __sigdefault)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(sigdefault, "__sigdefault"));

        auto abii_ret = real_posix_spawnattr_setsigdefault(attr, sigdefault);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_setsigdefault, abii_ret)
    return real_posix_spawnattr_setsigdefault(attr, sigdefault);
}

static int (*real_posix_spawnattr_getsigmask)(const posix_spawnattr_t*, sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawnattr_getsigmask(const posix_spawnattr_t* attr, sigset_t* sigmask) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_getsigmask)
        pre_fmtd_str pi_str = "posix_spawnattr_getsigmask(__attr, __sigmask)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(sigmask, "__sigmask"));

        auto abii_ret = real_posix_spawnattr_getsigmask(attr, sigmask);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_getsigmask, abii_ret)
    return real_posix_spawnattr_getsigmask(attr, sigmask);
}

static int (*real_posix_spawnattr_setsigmask)(posix_spawnattr_t*, const sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawnattr_setsigmask(posix_spawnattr_t* attr, const sigset_t* sigmask) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_setsigmask)
        pre_fmtd_str pi_str = "posix_spawnattr_getsigmask(__attr, __sigmask)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(sigmask, "__sigmask"));

        auto abii_ret = real_posix_spawnattr_setsigmask(attr, sigmask);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_setsigmask, abii_ret)
    return real_posix_spawnattr_setsigmask(attr, sigmask);
}

static int (*real_posix_spawnattr_getflags)(const posix_spawnattr_t*, short int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawnattr_getflags(const posix_spawnattr_t* attr, short int* flags) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_getflags)
        pre_fmtd_str pi_str = "posix_spawnattr_getflags(__attr, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer_with_depth(print_spawn_flag, *flags, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_posix_spawnattr_getflags(attr, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_getflags, abii_ret)
    return real_posix_spawnattr_getflags(attr, flags);
}

static int (*real_posix_spawnattr_setflags)(posix_spawnattr_t*, short int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawnattr_setflags(posix_spawnattr_t* attr, short int flags) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_setflags)
        pre_fmtd_str pi_str = "posix_spawnattr_setflags(_attr, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_spawn_flag, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_posix_spawnattr_setflags(attr, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_setflags, abii_ret)
    return real_posix_spawnattr_setflags(attr, flags);
}

static int (*real_posix_spawnattr_getpgroup)(const posix_spawnattr_t*, pid_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawnattr_getpgroup(const posix_spawnattr_t* attr, pid_t* pgroup) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_getpgroup)
        pre_fmtd_str pi_str = "posix_spawnattr_getpgroup(__attr, __pgroup)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(pgroup, "__pgroup"));

        auto abii_ret = real_posix_spawnattr_getpgroup(attr, pgroup);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_getpgroup, abii_ret)
    return real_posix_spawnattr_getpgroup(attr, pgroup);
}

static int (*real_posix_spawnattr_setpgroup)(posix_spawnattr_t*, pid_t) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawnattr_setpgroup(posix_spawnattr_t* attr, pid_t pgroup) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_setpgroup)
        pre_fmtd_str pi_str = "posix_spawnattr_setpgroup(__attr, __pgroup)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(pgroup, "__pgroup"));

        auto abii_ret = real_posix_spawnattr_setpgroup(attr, pgroup);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_setpgroup, abii_ret)
    return real_posix_spawnattr_setpgroup(attr, pgroup);
}

static int (*real_posix_spawnattr_getschedpolicy)(const posix_spawnattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawnattr_getschedpolicy(const posix_spawnattr_t* attr, int* schedpolicy) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_getschedpolicy)
        pre_fmtd_str pi_str = "posix_spawnattr_getschedpolicy(__attr, __schedpolicy)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(schedpolicy, "__schedpolicy"));

        auto abii_ret = real_posix_spawnattr_getschedpolicy(attr, schedpolicy);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_getschedpolicy, abii_ret)
    return real_posix_spawnattr_getschedpolicy(attr, schedpolicy);
}

static int (*real_posix_spawnattr_setschedpolicy)(posix_spawnattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawnattr_setschedpolicy(posix_spawnattr_t* attr, int schedpolicy) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_setschedpolicy)
        pre_fmtd_str pi_str = "posix_spawnattr_getschedpolicy(__attr, __schedpolicy)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(schedpolicy, "__schedpolicy"));

        auto abii_ret = real_posix_spawnattr_setschedpolicy(attr, schedpolicy);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_setschedpolicy, abii_ret)
    return real_posix_spawnattr_setschedpolicy(attr, schedpolicy);
}

static int (*real_posix_spawnattr_getschedparam)(const posix_spawnattr_t*, sched_param*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawnattr_getschedparam(const posix_spawnattr_t* attr, sched_param* schedparam) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_getschedparam)
        pre_fmtd_str pi_str = "posix_spawnattr_getschedparam(__attr, __schedparam)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(schedparam, "__schedparam"));

        auto abii_ret = real_posix_spawnattr_getschedparam(attr, schedparam);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_getschedparam, abii_ret)
    return real_posix_spawnattr_getschedparam(attr, schedparam);
}

static int (*real_posix_spawnattr_setschedparam)(posix_spawnattr_t*, const sched_param*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawnattr_setschedparam(posix_spawnattr_t* attr, const sched_param* schedparam) __THROW
{
    OVERRIDE_PREFIX(posix_spawnattr_setschedparam)
        pre_fmtd_str pi_str = "posix_spawnattr_setschedparam(__attr, __schedparam)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(schedparam, "__schedparam"));

        auto abii_ret = real_posix_spawnattr_setschedparam(attr, schedparam);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawnattr_setschedparam, abii_ret)
    return real_posix_spawnattr_setschedparam(attr, schedparam);
}

static int (*real_posix_spawn_file_actions_init)(posix_spawn_file_actions_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawn_file_actions_init(posix_spawn_file_actions_t* file_actions) __THROW
{
    OVERRIDE_PREFIX(posix_spawn_file_actions_init)
        pre_fmtd_str pi_str = "posix_spawn_file_actions_init(__file_actions)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file_actions, "__file_actions"));

        auto abii_ret = real_posix_spawn_file_actions_init(file_actions);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn_file_actions_init, abii_ret)
    return real_posix_spawn_file_actions_init(file_actions);
}

static int (*real_posix_spawn_file_actions_destroy)(posix_spawn_file_actions_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawn_file_actions_destroy(posix_spawn_file_actions_t* file_actions) __THROW
{
    OVERRIDE_PREFIX(posix_spawn_file_actions_destroy)
        pre_fmtd_str pi_str = "posix_spawn_file_actions_destroy(__file_actions)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file_actions, "__file_actions"));

        auto abii_ret = real_posix_spawn_file_actions_destroy(file_actions);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn_file_actions_destroy, abii_ret)
    return real_posix_spawn_file_actions_destroy(file_actions);
}

static int (*real_posix_spawn_file_actions_addopen)(posix_spawn_file_actions_t*, int, const char*, int,
                                                    mode_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
int abii_posix_spawn_file_actions_addopen(posix_spawn_file_actions_t* file_actions, int fd, const char* path, int oflag,
                                          mode_t mode) __THROW
{
    OVERRIDE_PREFIX(posix_spawn_file_actions_addopen)
        pre_fmtd_str pi_str = "posix_spawn_file_actions_addopen(__file_actions, __fd, __path, __oflag, __mode)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file_actions, "__file_actions"));
        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(mode, "__mode");
        printer1->set_enum_printer(print_fcntl_protection, mode);
        abii_args->push_arg(printer1);

        auto abii_ret = real_posix_spawn_file_actions_addopen(file_actions, fd, path, oflag, mode);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn_file_actions_addopen, abii_ret)
    return real_posix_spawn_file_actions_addopen(file_actions, fd, path, oflag, mode);
}

static int (*real_posix_spawn_file_actions_addclose)(posix_spawn_file_actions_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawn_file_actions_addclose(posix_spawn_file_actions_t* file_actions, int fd) __THROW
{
    OVERRIDE_PREFIX(posix_spawn_file_actions_addclose)
        pre_fmtd_str pi_str = "posix_spawn_file_actions_addclose(__file_actions, __fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file_actions, "__file_actions"));
        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto abii_ret = real_posix_spawn_file_actions_addclose(file_actions, fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn_file_actions_addclose, abii_ret)
    return real_posix_spawn_file_actions_addclose(file_actions, fd);
}

static int (*real_posix_spawn_file_actions_adddup2)(posix_spawn_file_actions_t*, int, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t* file_actions, int fd, int newfd) __THROW
{
    OVERRIDE_PREFIX(posix_spawn_file_actions_adddup2)
        pre_fmtd_str pi_str = "posix_spawn_file_actions_adddup2(__file_actions, __fd, __newfd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(file_actions, "__file_actions"));
        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(newfd, "__newfd"));

        auto abii_ret = real_posix_spawn_file_actions_adddup2(file_actions, fd, newfd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn_file_actions_adddup2, abii_ret)
    return real_posix_spawn_file_actions_adddup2(file_actions, fd, newfd);
}

static int (*real_posix_spawn_file_actions_addchdir_np)(posix_spawn_file_actions_t*, const char*) __THROW =
    nullptr;

extern "C" __nonnull((1, 2))
int abii_posix_spawn_file_actions_addchdir_np(posix_spawn_file_actions_t* actions, const char* path) __THROW
{
    OVERRIDE_PREFIX(posix_spawn_file_actions_addchdir_np)
        pre_fmtd_str pi_str = "posix_spawn_file_actions_addchdir_np(__actions, __path)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(actions, "__actions"));
        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto abii_ret = real_posix_spawn_file_actions_addchdir_np(actions, path);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn_file_actions_addchdir_np, abii_ret)
    return real_posix_spawn_file_actions_addchdir_np(actions, path);
}

static int (*real_posix_spawn_file_actions_addfchdir_np)(posix_spawn_file_actions_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawn_file_actions_addfchdir_np(posix_spawn_file_actions_t* actions, int fd) __THROW
{
    OVERRIDE_PREFIX(posix_spawn_file_actions_addfchdir_np)
        pre_fmtd_str pi_str = "posix_spawn_file_actions_addfchdir_np(__actions, __fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(actions, "__actions"));
        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto abii_ret = real_posix_spawn_file_actions_addfchdir_np(actions, fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn_file_actions_addfchdir_np, abii_ret)
    return real_posix_spawn_file_actions_addfchdir_np(actions, fd);
}

static int (*real_posix_spawn_file_actions_addclosefrom_np)(posix_spawn_file_actions_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawn_file_actions_addclosefrom_np(posix_spawn_file_actions_t* actions, int from) __THROW
{
    OVERRIDE_PREFIX(posix_spawn_file_actions_addclosefrom_np)
        pre_fmtd_str pi_str = "posix_spawn_file_actions_addclosefrom_np(__actions, __from)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(actions, "__actions"));
        abii_args->push_arg(new ArgPrinter(from, "__from"));

        auto abii_ret = real_posix_spawn_file_actions_addclosefrom_np(actions, from);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn_file_actions_addclosefrom_np, abii_ret)
    return real_posix_spawn_file_actions_addclosefrom_np(actions, from);
}

static int (*real_posix_spawn_file_actions_addtcsetpgrp_np)(posix_spawn_file_actions_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_posix_spawn_file_actions_addtcsetpgrp_np(posix_spawn_file_actions_t* actions, int tcfd) __THROW
{
    OVERRIDE_PREFIX(posix_spawn_file_actions_addtcsetpgrp_np)
        pre_fmtd_str pi_str = "posix_spawn_file_actions_addtcsetpgrp_np(__actions, __tcfd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(actions, "__actions"));
        abii_args->push_arg(new ArgPrinter(tcfd, "__tcfd"));

        auto abii_ret = real_posix_spawn_file_actions_addtcsetpgrp_np(actions, tcfd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_spawn_file_actions_addtcsetpgrp_np, abii_ret)
    return real_posix_spawn_file_actions_addtcsetpgrp_np(actions, tcfd);
}
}
