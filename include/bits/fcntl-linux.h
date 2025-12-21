//
// Created by Trent Tanchin on 8/17/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_FCNTL_LINUX_H
#define ABII_C_LOGGING_PLUGIN_FCNTL_LINUX_H

namespace abii
{
const defines_map fcntl_linux_enum1 = {
    {O_ACCMODE, "O_ACCMODE"},
    {O_RDONLY, "O_RDONLY"},
    {O_WRONLY, "O_WRONLY"},
    {O_RDWR, "O_RDWR"},
    {O_CREAT, "O_CREAT"},
    {O_EXCL, "O_EXCL"},
    {O_NOCTTY, "O_NOCTTY"},
    {O_TRUNC, "O_TRUNC"},
    {O_APPEND, "O_APPEND"},
    {O_NONBLOCK, "O_NONBLOCK"},
    {O_NDELAY, "O_NDELAY"},
    {O_SYNC, "O_SYNC"},
    {O_FSYNC, "O_FSYNC"},
    {O_ASYNC, "O_ASYNC"},
    {__O_LARGEFILE, "__O_LARGEFILE"},
    {__O_DIRECTORY, "__O_DIRECTORY"},
    {__O_NOFOLLOW, "__O_NOFOLLOW"},
    {__O_CLOEXEC, "__O_CLOEXEC"},
    {__O_DIRECT, "__O_DIRECT"},
    {__O_NOATIME, "__O_NOATIME"},
    {__O_PATH, "__O_PATH"},
    {__O_DSYNC, "__O_DSYNC"},
    {__O_TMPFILE, "__O_TMPFILE"},
    {FAPPEND, "FAPPEND"},
    {FFSYNC, "FFSYNC"},
    {FASYNC, "FASYNC"},
    {FNONBLOCK, "FNONBLOCK"},
    {FNDELAY, "FNDELAY"}
};

const defines_map fcntl_linux_enum2 = {
    {F_GETLK, "F_GETLK"},
    {F_SETLK, "F_SETLK"},
    {F_SETLKW, "F_SETLKW"},
    {F_GETLK64, "F_GETLK64"},
    {F_SETLK64, "F_SETLK64"},
    {F_SETLKW64, "F_SETLKW64"},
    {F_DUPFD, "F_DUPFD"},
    {F_GETFD, "F_GETFD"},
    {F_SETFD, "F_SETFD"},
    {F_GETFL, "F_GETFL"},
    {F_SETFL, "F_SETFL"},
    {__F_SETOWN, "__F_SETOWN"},
    {__F_GETOWN, "__F_GETOWN"}
#if defined __USE_UNIX98 || defined __USE_XOPEN2K8
    ,
    {F_SETOWN, "F_SETOWN"},
    {F_GETOWN, "F_GETOWN"}
#endif
    ,
    {__F_SETSIG, "__F_SETSIG"},
    {__F_GETSIG, "__F_GETSIG"},
    {__F_SETOWN_EX, "__F_SETOWN_EX"},
    {__F_GETOWN_EX, "__F_GETOWN_EX"}
#ifdef __USE_GNU
    ,
    {F_SETSIG, "F_SETSIG"},
    {F_GETSIG, "F_GETSIG"},
    {F_SETOWN_EX, "F_SETOWN_EX"},
    {F_GETOWN_EX, "F_GETOWN_EX"},
    {F_SETLEASE, "F_SETLEASE"},
    {F_GETLEASE, "F_GETLEASE"},
    {F_NOTIFY, "F_NOTIFY"},
    {F_SETPIPE_SZ, "F_SETPIPE_SZ"},
    {F_GETPIPE_SZ, "F_GETPIPE_SZ"},
    {F_ADD_SEALS, "F_ADD_SEALS"},
    {F_GET_SEALS, "F_GET_SEALS"},
    {F_GET_RW_HINT, "F_GET_RW_HINT"},
    {F_SET_RW_HINT, "F_SET_RW_HINT"},
    {F_GET_FILE_RW_HINT, "F_GET_FILE_RW_HINT"},
    {F_SET_FILE_RW_HINT, "F_SET_FILE_RW_HINT"}
#endif
#ifdef __USE_XOPEN2K8
    ,
    {F_DUPFD_CLOEXEC, "F_DUPFD_CLOEXEC"}
#endif
};

const defines_map fcntl_linux_enum3 = {
#ifdef __USE_GNU
    {F_OFD_GETLK, "F_OFD_GETLK"},
    {F_OFD_SETLK, "F_OFD_SETLK"},
    {F_OFD_SETLKW, "F_OFD_SETLKW"}
#endif
};

const defines_map fcntl_linux_enum4 = {
    {}
#ifdef __USE_LARGEFILE64
    ,
    {O_LARGEFILE, "O_LARGEFILE"}
#endif
#ifdef __USE_XOPEN2K8
    ,
    {O_DIRECTORY, "O_DIRECTORY"},
    {O_NOFOLLOW, "O_NOFOLLOW"},
    {O_CLOEXEC, "O_CLOEXEC"}
#endif
#ifdef __USE_GNU
    ,
    {O_DIRECT, "O_DIRECT"},
    {O_NOATIME, "O_NOATIME"},
    {O_PATH, "O_PATH"},
    {O_TMPFILE, "O_TMPFILE"}
#endif
#if defined __USE_POSIX199309 || defined __USE_UNIX98
    ,
    {O_DSYNC, "O_DSYNC"},
    {O_RSYNC, "O_RSYNC"}
#endif
};

const defines_map fcntl_linux_enum5 = {
    {FD_CLOEXEC, "FD_CLOEXEC"}
};

const defines_map fcntl_linux_enum6 = {
    {F_RDLCK, "F_RDLCK"},
    {F_WRLCK, "F_WRLCK"},
    {F_UNLCK, "F_UNLCK"},
    {F_EXLCK, "F_EXLCK"},
    {F_SHLCK, "F_SHLCK"}
};

const defines_map fcntl_linux_enum7 = {
    {}
#ifdef __USE_MISC
    ,
    {LOCK_SH, "LOCK_SH"},
    {LOCK_EX, "LOCK_EX"},
    {LOCK_NB, "LOCK_NB"},
    {LOCK_UN, "LOCK_UN"}
#endif
#ifdef __USE_GNU
    ,
    {LOCK_MAND, "LOCK_MAND"},
    {LOCK_READ, "LOCK_READ"},
    {LOCK_WRITE, "LOCK_WRITE"},
    {LOCK_RW, "LOCK_RW"}
#endif
};

const defines_map fcntl_linux_enum8 = {
#ifdef __USE_GNU
    {DN_ACCESS, "DN_ACCESS"},
    {DN_MODIFY, "DN_MODIFY"},
    {DN_CREATE, "DN_CREATE"},
    {DN_DELETE, "DN_DELETE"},
    {DN_RENAME, "DN_RENAME"},
    {DN_ATTRIB, "DN_ATTRIB"},
    {DN_MULTISHOT, "DN_MULTISHOT"}
#endif
};

const defines_map fcntl_linux_enum9 = {
#ifdef __USE_GNU
    {F_OWNER_TID, "F_OWNER_TID"},
    {F_OWNER_PID, "F_OWNER_PID"},
    {F_OWNER_PGRP, "F_OWNER_PGRP"},
    {F_OWNER_GID, "F_OWNER_GID"}
#endif
};

const defines_map fcntl_linux_enum10 = {
#ifdef __USE_GNU
    {F_SEAL_SEAL, "F_SEAL_SEAL"},
    {F_SEAL_SHRINK, "F_SEAL_SHRINK"},
    {F_SEAL_GROW, "F_SEAL_GROW"},
    {F_SEAL_WRITE, "F_SEAL_WRITE"},
    {F_SEAL_FUTURE_WRITE, "F_SEAL_FUTURE_WRITE"}
#endif
};

const defines_map fcntl_linux_enum11 = {
#ifdef __USE_GNU
    {RWH_WRITE_LIFE_NOT_SET, "RWH_WRITE_LIFE_NOT_SET"},
    {RWF_WRITE_LIFE_NOT_SET, "RWF_WRITE_LIFE_NOT_SET"},
    {RWH_WRITE_LIFE_NONE, "RWH_WRITE_LIFE_NONE"},
    {RWH_WRITE_LIFE_SHORT, "RWH_WRITE_LIFE_SHORT"},
    {RWH_WRITE_LIFE_MEDIUM, "RWH_WRITE_LIFE_MEDIUM"},
    {RWH_WRITE_LIFE_LONG, "RWH_WRITE_LIFE_LONG"},
    {RWH_WRITE_LIFE_EXTREME, "RWH_WRITE_LIFE_EXTREME"}
#endif
};

const defines_map fcntl_linux_enum12 = {
    {__POSIX_FADV_DONTNEED, "__POSIX_FADV_DONTNEED"},
    {__POSIX_FADV_NOREUSE, "__POSIX_FADV_NOREUSE"},
#ifdef __USE_XOPEN2K
    {POSIX_FADV_NORMAL, "POSIX_FADV_NORMAL"},
    {POSIX_FADV_RANDOM, "POSIX_FADV_RANDOM"},
    {POSIX_FADV_SEQUENTIAL, "POSIX_FADV_SEQUENTIAL"},
    {POSIX_FADV_WILLNEED, "POSIX_FADV_WILLNEED"},
    {POSIX_FADV_DONTNEED, "POSIX_FADV_DONTNEED"},
    {POSIX_FADV_NOREUSE, "POSIX_FADV_NOREUSE"}
#endif
};

template <typename T>
std::string print_fcntl_linux_enum1(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_enum1);
}

template <typename T>
std::string print_fcntl_linux_enum2(const T v)
{
    return print_enum_entry(v, fcntl_linux_enum2);
}

template <typename T>
std::string print_fcntl_linux_enum3(const T v)
{
    return print_enum_entry(v, fcntl_linux_enum3);
}

template <typename T>
std::string print_fcntl_linux_enum4(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_enum4);
}

template <typename T>
std::string print_fcntl_linux_enum5(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_enum5);
}

template <typename T>
std::string print_fcntl_linux_enum6(const T v)
{
    return print_enum_entry(v, fcntl_linux_enum6);
}

template <typename T>
std::string print_fcntl_linux_enum7(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_enum7);
}

template <typename T>
std::string print_fcntl_linux_enum8(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_enum8);
}

template <typename T>
std::string print_fcntl_linux_enum9(const T v)
{
    return print_enum_entry(v, fcntl_linux_enum9);
}

template <typename T>
std::string print_fcntl_linux_enum10(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_enum10);
}

template <typename T>
std::string print_fcntl_linux_enum11(const T v)
{
    return print_enum_entry(v, fcntl_linux_enum11);
}

template <typename T>
std::string print_fcntl_linux_enum12(const T v)
{
    return print_enum_entry(v, fcntl_linux_enum12);
}
}

using namespace abii;

#ifdef __USE_GNU
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, f_owner_ex>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.type, "type", &os);
    printer->set_enum_printer(print_fcntl_linux_enum9, obj.type);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.pid, "pid", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_FCNTL_LINUX_H
