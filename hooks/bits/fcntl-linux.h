//
// Created by Trent Tanchin on 8/17/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_FCNTL_LINUX_H
#define ABII_C_LOGGING_PLUGIN_BITS_FCNTL_LINUX_H

#include <abii/libabii.h>

namespace abii
{
const defines_map bits_fcntl_linux_oflag = {
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

const defines_map bits_fcntl_linux_cmd = {
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
    {__F_GETOWN, "__F_GETOWN"},
    {F_SETOWN, "F_SETOWN"},
    {F_GETOWN, "F_GETOWN"},
    {__F_SETSIG, "__F_SETSIG"},
    {__F_GETSIG, "__F_GETSIG"},
    {__F_SETOWN_EX, "__F_SETOWN_EX"},
    {__F_GETOWN_EX, "__F_GETOWN_EX"},
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
    {F_SET_FILE_RW_HINT, "F_SET_FILE_RW_HINT"},
    {F_DUPFD_CLOEXEC, "F_DUPFD_CLOEXEC"}
};

const defines_map bits_fcntl_linux_ofd_lock = {
    {F_OFD_GETLK, "F_OFD_GETLK"},
    {F_OFD_SETLK, "F_OFD_SETLK"},
    {F_OFD_SETLKW, "F_OFD_SETLKW"}
};

const defines_map bits_fcntl_linux_otype = {
    {O_LARGEFILE, "O_LARGEFILE"},
    {O_DIRECTORY, "O_DIRECTORY"},
    {O_NOFOLLOW, "O_NOFOLLOW"},
    {O_CLOEXEC, "O_CLOEXEC"},
    {O_DIRECT, "O_DIRECT"},
    {O_NOATIME, "O_NOATIME"},
    {O_PATH, "O_PATH"},
    {O_TMPFILE, "O_TMPFILE"},
    {O_DSYNC, "O_DSYNC"},
    {O_RSYNC, "O_RSYNC"}
};

const defines_map bits_fcntl_linux_fd_cloexec = {
    {FD_CLOEXEC, "FD_CLOEXEC"}
};

const defines_map bits_fcntl_linux_fd_pidfs_root = {
    {FD_PIDFS_ROOT, "FD_PIDFS_ROOT"}
};

const defines_map bits_fcntl_linux_l_type = {
    {F_RDLCK, "F_RDLCK"},
    {F_WRLCK, "F_WRLCK"},
    {F_UNLCK, "F_UNLCK"},
    {F_EXLCK, "F_EXLCK"},
    {F_SHLCK, "F_SHLCK"}
};

const defines_map bits_fcntl_linux_bsd_l_type = {
    {LOCK_SH, "LOCK_SH"},
    {LOCK_EX, "LOCK_EX"},
    {LOCK_NB, "LOCK_NB"},
    {LOCK_UN, "LOCK_UN"},
    {LOCK_MAND, "LOCK_MAND"},
    {LOCK_READ, "LOCK_READ"},
    {LOCK_WRITE, "LOCK_WRITE"},
    {LOCK_RW, "LOCK_RW"}
};

const defines_map bits_fcntl_linux_dir_notification = {
    {DN_ACCESS, "DN_ACCESS"},
    {DN_MODIFY, "DN_MODIFY"},
    {DN_CREATE, "DN_CREATE"},
    {DN_DELETE, "DN_DELETE"},
    {DN_RENAME, "DN_RENAME"},
    {DN_ATTRIB, "DN_ATTRIB"},
    {DN_MULTISHOT, "DN_MULTISHOT"}
};

const defines_map bits_fcntl_linux___pid_type = {
    {F_OWNER_TID, "F_OWNER_TID"},
    {F_OWNER_PID, "F_OWNER_PID"},
    {F_OWNER_PGRP, "F_OWNER_PGRP"},
    {F_OWNER_GID, "F_OWNER_GID"}
};

const defines_map bits_fcntl_linux_seal = {
    {F_SEAL_SEAL, "F_SEAL_SEAL"},
    {F_SEAL_SHRINK, "F_SEAL_SHRINK"},
    {F_SEAL_GROW, "F_SEAL_GROW"},
    {F_SEAL_WRITE, "F_SEAL_WRITE"},
    {F_SEAL_FUTURE_WRITE, "F_SEAL_FUTURE_WRITE"}
};

const defines_map bits_fcntl_linux_rw_hint = {
    {RWH_WRITE_LIFE_NOT_SET, "RWH_WRITE_LIFE_NOT_SET"},
    {RWF_WRITE_LIFE_NOT_SET, "RWF_WRITE_LIFE_NOT_SET"},
    {RWH_WRITE_LIFE_NONE, "RWH_WRITE_LIFE_NONE"},
    {RWH_WRITE_LIFE_SHORT, "RWH_WRITE_LIFE_SHORT"},
    {RWH_WRITE_LIFE_MEDIUM, "RWH_WRITE_LIFE_MEDIUM"},
    {RWH_WRITE_LIFE_LONG, "RWH_WRITE_LIFE_LONG"},
    {RWH_WRITE_LIFE_EXTREME, "RWH_WRITE_LIFE_EXTREME"}
};

const defines_map bits_fcntl_linux_fadvise = {
    {__POSIX_FADV_DONTNEED, "__POSIX_FADV_DONTNEED"},
    {__POSIX_FADV_NOREUSE, "__POSIX_FADV_NOREUSE"},
    {POSIX_FADV_NORMAL, "POSIX_FADV_NORMAL"},
    {POSIX_FADV_RANDOM, "POSIX_FADV_RANDOM"},
    {POSIX_FADV_SEQUENTIAL, "POSIX_FADV_SEQUENTIAL"},
    {POSIX_FADV_WILLNEED, "POSIX_FADV_WILLNEED"},
    {POSIX_FADV_DONTNEED, "POSIX_FADV_DONTNEED"},
    {POSIX_FADV_NOREUSE, "POSIX_FADV_NOREUSE"}
};

const defines_map bits_fcntl_linux_sync_file_range = {
    {SYNC_FILE_RANGE_WAIT_BEFORE, "SYNC_FILE_RANGE_WAIT_BEFORE"},
    {SYNC_FILE_RANGE_WRITE, "SYNC_FILE_RANGE_WRITE"},
    {SYNC_FILE_RANGE_WAIT_AFTER, "SYNC_FILE_RANGE_WAIT_AFTER"},
    {SYNC_FILE_RANGE_WRITE_AND_WAIT, "SYNC_FILE_RANGE_WRITE_AND_WAIT"}
};

const defines_map bits_fcntl_linux_splice = {
    {SPLICE_F_MOVE, "SPLICE_F_MOVE"},
    {SPLICE_F_NONBLOCK, "SPLICE_F_NONBLOCK"},
    {SPLICE_F_MORE, "SPLICE_F_MORE"},
    {SPLICE_F_GIFT, "SPLICE_F_GIFT"}
};

const defines_map bits_fcntl_linux_max_handle_sz = {
    {MAX_HANDLE_SZ, "MAX_HANDLE_SZ"}
};

const defines_map bits_fcntl_linux_at_handle = {
    {AT_HANDLE_FID, "AT_HANDLE_FID"},
    {AT_HANDLE_MNT_ID_UNIQUE, "AT_HANDLE_MNT_ID_UNIQUE"},
    {AT_HANDLE_CONNECTABLE, "AT_HANDLE_CONNECTABLE"}
};

const defines_map bits_fcntl_linux_at_execve_check = {
    {AT_EXECVE_CHECK, "AT_EXECVE_CHECK"}
};

template <typename T>
std::string print_bits_fcntl_linux_oflag(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_oflag);
}

template <typename T>
std::string print_bits_fcntl_linux_cmd(const T v)
{
    return print_enum_entry(v, bits_fcntl_linux_cmd);
}

template <typename T>
std::string print_bits_fcntl_linux_ofd_lock(const T v)
{
    return print_enum_entry(v, bits_fcntl_linux_ofd_lock);
}

template <typename T>
std::string print_bits_fcntl_linux_otype(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_otype);
}

template <typename T>
std::string print_bits_fcntl_linux_fd_cloexec(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_fd_cloexec);
}

template <typename T>
std::string print_bits_fcntl_linux_fd_pidfs_root(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_fd_pidfs_root);
}

template <typename T>
std::string print_bits_fcntl_linux_l_type(const T v)
{
    return print_enum_entry(v, bits_fcntl_linux_l_type);
}

template <typename T>
std::string print_bits_fcntl_linux_bsd_l_type(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_bsd_l_type);
}

template <typename T>
std::string print_bits_fcntl_linux_dir_notification(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_dir_notification);
}

template <typename T>
std::string print_bits_fcntl_linux___pid_type(const T v)
{
    return print_enum_entry(v, bits_fcntl_linux___pid_type);
}

template <typename T>
std::string print_bits_fcntl_linux_seal(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_seal);
}

template <typename T>
std::string print_bits_fcntl_linux_rw_hint(const T v)
{
    return print_enum_entry(v, bits_fcntl_linux_rw_hint);
}

template <typename T>
std::string print_bits_fcntl_linux_fadvise(const T v)
{
    return print_enum_entry(v, bits_fcntl_linux_fadvise);
}

template <typename T>
std::string print_bits_fcntl_linux_sync_file_range(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_sync_file_range);
}

template <typename T>
std::string print_bits_fcntl_linux_splice(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_splice);
}

template <typename T>
std::string print_bits_fcntl_linux_max_handle_sz(const T v)
{
    return print_enum_entry(v, bits_fcntl_linux_max_handle_sz);
}

template <typename T>
std::string print_bits_fcntl_linux_at_handle(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_at_handle);
}

template <typename T>
std::string print_bits_fcntl_linux_at_execve_check(const T v)
{
    return print_or_enum_entries(v, bits_fcntl_linux_at_execve_check);
}
}

using namespace abii;

#ifdef __USE_GNU
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, f_owner_ex>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.type, "type", &os);
    printer->set_enum_printer(print_bits_fcntl_linux___pid_type, obj.type);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.pid, "pid", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, file_handle>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.handle_bytes, "handle_bytes", &os);
    printer->set_enum_printer(print_bits_fcntl_linux_max_handle_sz, obj.handle_bytes);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.handle_type, "handle_type", &os));

    auto printer1 = new ArgPrinter(obj.f_handle, "f_handle", &os, RECURSE);
    printer1->set_len(obj.handle_bytes);
    abii_args->push_arg(printer1);
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_BITS_FCNTL_LINUX_H
