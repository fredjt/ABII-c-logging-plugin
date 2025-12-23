//
// Created by Trent Tanchin on 8/17/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_FCNTL_LINUX_H
#define ABII_C_LOGGING_PLUGIN_FCNTL_LINUX_H

namespace abii
{
const defines_map fcntl_linux_oflag = {
    {0003, "O_ACCMODE"},
    {00, "O_RDONLY"},
    {01, "O_WRONLY"},
    {02, "O_RDWR"},
    {0100, "O_CREAT"},
    {0200, "O_EXCL"},
    {0400, "O_NOCTTY"},
    {01000, "O_TRUNC"},
    {02000, "O_APPEND"},
    {04000, "O_NONBLOCK"},
    {04000, "O_NDELAY"},
    {04010000, "O_SYNC"},
    {04010000, "O_FSYNC"},
    {020000, "O_ASYNC"},
    {0, "__O_LARGEFILE"},
    {0200000, "__O_DIRECTORY"},
    {0400000, "__O_NOFOLLOW"},
    {02000000, "__O_CLOEXEC"},
    {040000, "__O_DIRECT"},
    {01000000, "__O_NOATIME"},
    {010000000, "__O_PATH"},
    {010000, "__O_DSYNC"},
    {(020000000 | 0200000), "__O_TMPFILE"},
    {02000, "FAPPEND"},
    {04010000, "FFSYNC"},
    {020000, "FASYNC"},
    {04000, "FNONBLOCK"},
    {04000, "FNDELAY"}
};

const defines_map fcntl_linux_cmd = {
    {5, "F_GETLK"},
    {6, "F_SETLK"},
    {7, "F_SETLKW"},
    {5, "F_GETLK64"},
    {6, "F_SETLK64"},
    {7, "F_SETLKW64"},
    {0, "F_DUPFD"},
    {1, "F_GETFD"},
    {2, "F_SETFD"},
    {3, "F_GETFL"},
    {4, "F_SETFL"},
    {8, "__F_SETOWN"},
    {9, "__F_GETOWN"},
    {8, "F_SETOWN"},
    {9, "F_GETOWN"},
    {10, "__F_SETSIG"},
    {11, "__F_GETSIG"},
    {15, "__F_SETOWN_EX"},
    {16, "__F_GETOWN_EX"},
    {10, "F_SETSIG"},
    {11, "F_GETSIG"},
    {15, "F_SETOWN_EX"},
    {16, "F_GETOWN_EX"},
    {1024, "F_SETLEASE"},
    {1025, "F_GETLEASE"},
    {1026, "F_NOTIFY"},
    {1031, "F_SETPIPE_SZ"},
    {1032, "F_GETPIPE_SZ"},
    {1033, "F_ADD_SEALS"},
    {1034, "F_GET_SEALS"},
    {1035, "F_GET_RW_HINT"},
    {1036, "F_SET_RW_HINT"},
    {1037, "F_GET_FILE_RW_HINT"},
    {1038, "F_SET_FILE_RW_HINT"},
    {1030, "F_DUPFD_CLOEXEC"}
};

const defines_map fcntl_linux_ofd_lock = {
    {36, "F_OFD_GETLK"},
    {37, "F_OFD_SETLK"},
    {38, "F_OFD_SETLKW"}
};

const defines_map fcntl_linux_otype = {
    {0, "O_LARGEFILE"},
    {0200000, "O_DIRECTORY"},
    {0400000, "O_NOFOLLOW"},
    {02000000, "O_CLOEXEC"},
    {040000, "O_DIRECT"},
    {01000000, "O_NOATIME"},
    {010000000, "O_PATH"},
    {(020000000 | 0200000), "O_TMPFILE"},
    {010000, "O_DSYNC"},
    {04010000, "O_RSYNC"}
};

const defines_map fcntl_linux_fd_cloexec = {
    {1, "FD_CLOEXEC"}
};

const defines_map fcntl_linux_l_type = {
    {0, "F_RDLCK"},
    {1, "F_WRLCK"},
    {2, "F_UNLCK"},
    {4, "F_EXLCK"},
    {8, "F_SHLCK"}
};

const defines_map fcntl_linux_bsd_l_type = {
    {1, "LOCK_SH"},
    {2, "LOCK_EX"},
    {4, "LOCK_NB"},
    {8, "LOCK_UN"},
    {32, "LOCK_MAND"},
    {64, "LOCK_READ"},
    {128, "LOCK_WRITE"},
    {192, "LOCK_RW"}
};

const defines_map fcntl_linux_dir_notification = {
    {0x00000001, "DN_ACCESS"},
    {0x00000002, "DN_MODIFY"},
    {0x00000004, "DN_CREATE"},
    {0x00000008, "DN_DELETE"},
    {0x00000010, "DN_RENAME"},
    {0x00000020, "DN_ATTRIB"},
    {0x80000000, "DN_MULTISHOT"}
};

const defines_map fcntl_linux___pid_type = {
    {0, "F_OWNER_TID"},
    {1, "F_OWNER_PID"},
    {2, "F_OWNER_PGRP"},
    {2, "F_OWNER_GID"}
};

const defines_map fcntl_linux_seal = {
    {0x0001, "F_SEAL_SEAL"},
    {0x0002, "F_SEAL_SHRINK"},
    {0x0004, "F_SEAL_GROW"},
    {0x0008, "F_SEAL_WRITE"},
    {0x0010, "F_SEAL_FUTURE_WRITE"}
};

const defines_map fcntl_linux_rw_hint = {
    {0, "RWH_WRITE_LIFE_NOT_SET"},
    {0, "RWF_WRITE_LIFE_NOT_SET"},
    {1, "RWH_WRITE_LIFE_NONE"},
    {2, "RWH_WRITE_LIFE_SHORT"},
    {3, "RWH_WRITE_LIFE_MEDIUM"},
    {4, "RWH_WRITE_LIFE_LONG"},
    {5, "RWH_WRITE_LIFE_EXTREME"}
};

const defines_map fcntl_linux_fadvise = {
    {4, "__POSIX_FADV_DONTNEED"},
    {5, "__POSIX_FADV_NOREUSE"},
    {0, "POSIX_FADV_NORMAL"},
    {1, "POSIX_FADV_RANDOM"},
    {2, "POSIX_FADV_SEQUENTIAL"},
    {3, "POSIX_FADV_WILLNEED"},
    {4, "POSIX_FADV_DONTNEED"},
    {5, "POSIX_FADV_NOREUSE"}
};

template <typename T>
std::string print_fcntl_linux_oflag(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_oflag);
}

template <typename T>
std::string print_fcntl_linux_cmd(const T v)
{
    return print_enum_entry(v, fcntl_linux_cmd);
}

template <typename T>
std::string print_fcntl_linux_ofd_lock(const T v)
{
    return print_enum_entry(v, fcntl_linux_ofd_lock);
}

template <typename T>
std::string print_fcntl_linux_otype(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_otype);
}

template <typename T>
std::string print_fcntl_linux_fd_cloexec(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_fd_cloexec);
}

template <typename T>
std::string print_fcntl_linux_l_type(const T v)
{
    return print_enum_entry(v, fcntl_linux_l_type);
}

template <typename T>
std::string print_fcntl_linux_bsd_l_type(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_bsd_l_type);
}

template <typename T>
std::string print_fcntl_linux_dir_notification(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_dir_notification);
}

template <typename T>
std::string print_fcntl_linux___pid_type(const T v)
{
    return print_enum_entry(v, fcntl_linux___pid_type);
}

template <typename T>
std::string print_fcntl_linux_seal(const T v)
{
    return print_or_enum_entries(v, fcntl_linux_seal);
}

template <typename T>
std::string print_fcntl_linux_rw_hint(const T v)
{
    return print_enum_entry(v, fcntl_linux_rw_hint);
}

template <typename T>
std::string print_fcntl_linux_fadvise(const T v)
{
    return print_enum_entry(v, fcntl_linux_fadvise);
}
}

using namespace abii;

#ifdef __USE_GNU
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, f_owner_ex>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = ArgPrinter(obj.type, "type", &os);
    printer.set_enum_printer(print_fcntl_linux___pid_type, obj.type);
    abii_args->push_arg(&printer);

    abii_args->push_arg(new ArgPrinter(obj.pid, "pid", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_FCNTL_LINUX_H
