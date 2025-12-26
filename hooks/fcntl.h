//
// Created by Trent Tanchin on 8/17/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_FCNTL_H
#define ABII_C_LOGGING_PLUGIN_FCNTL_H

#include <abii/libabii.h>

namespace abii
{
const defines_map fcntl_file_type = {
    {0170000, "S_IFMT"},
    {0040000, "S_IFDIR"},
    {0020000, "S_IFCHR"},
    {0060000, "S_IFBLK"},
    {0100000, "S_IFREG"},
    {0010000, "S_IFIFO"},
    {0120000, "S_IFLNK"},
    {0140000, "S_IFSOCK"}
};

const defines_map fcntl_protection = {
    {04000, "S_ISUID"},
    {02000, "S_ISGID"},
    {01000, "S_ISVTX"},
    {0400, "S_IRUSR"},
    {0200, "S_IWUSR"},
    {0100, "S_IXUSR"},
    {(0400 | 0200 | 0100), "S_IRWXU"},
    {(0400 >> 3), "S_IRGRP"},
    {(0200 >> 3), "S_IWGRP"},
    {(0100 >> 3), "S_IXGRP"},
    {((0400 | 0200 | 0100) >> 3), "S_IRWXG"},
    {((0400 >> 3) >> 3), "S_IROTH"},
    {((0200 >> 3) >> 3), "S_IWOTH"},
    {((0100 >> 3) >> 3), "S_IXOTH"},
    {(((0400 | 0200 | 0100) >> 3) >> 3), "S_IRWXO"}
};

const defines_map fcntl_access_prot = {
    {4, "R_OK"},
    {2, "W_OK"},
    {1, "X_OK"},
    {0, "F_OK"}
};

const defines_map fcntl_seek = {
    {0, "SEEK_SET"},
    {1, "SEEK_CUR"},
    {2, "SEEK_END"}
};

const defines_map fcntl_unlinkat = {
    {-100, "AT_FDCWD"},
    {0x100, "AT_SYMLINK_NOFOLLOW"},
    {0x200, "AT_REMOVEDIR"},
    {0x400, "AT_SYMLINK_FOLLOW"},
    {0x800, "AT_NO_AUTOMOUNT"},
    {0x1000, "AT_EMPTY_PATH"},
    {0x6000, "AT_STATX_SYNC_TYPE"},
    {0x0000, "AT_STATX_SYNC_AS_STAT"},
    {0x2000, "AT_STATX_FORCE_SYNC"},
    {0x4000, "AT_STATX_DONT_SYNC"},
    {0x8000, "AT_RECURSIVE"}
};

const defines_map fcntl_faccessat = {
    {-100, "AT_FDCWD"},
    {0x100, "AT_SYMLINK_NOFOLLOW"},
    {0x200, "AT_EACCESS"},
    {0x400, "AT_SYMLINK_FOLLOW"},
    {0x800, "AT_NO_AUTOMOUNT"},
    {0x1000, "AT_EMPTY_PATH"},
    {0x6000, "AT_STATX_SYNC_TYPE"},
    {0x0000, "AT_STATX_SYNC_AS_STAT"},
    {0x2000, "AT_STATX_FORCE_SYNC"},
    {0x4000, "AT_STATX_DONT_SYNC"},
    {0x8000, "AT_RECURSIVE"}
};

const defines_map fcntl_lockf_cmd = {
    {0, "F_ULOCK"},
    {1, "F_LOCK"},
    {2, "F_TLOCK"},
    {3, "F_TEST"}
};

template <typename T>
std::string print_fcntl_file_type(const T v)
{
    return print_or_enum_entries(v, fcntl_file_type);
}

template <typename T>
std::string print_fcntl_protection(const T v)
{
    return print_or_enum_entries(v, fcntl_protection);
}

template <typename T>
std::string print_fcntl_access_prot(const T v)
{
    return print_or_enum_entries(v, fcntl_access_prot);
}

template <typename T>
std::string print_fcntl_seek(const T v)
{
    return print_enum_entry(v, fcntl_seek);
}

template <typename T>
std::string print_fcntl_unlinkat(const T v)
{
    return print_or_enum_entries(v, fcntl_unlinkat);
}

template <typename T>
std::string print_fcntl_faccessat(const T v)
{
    return print_or_enum_entries(v, fcntl_faccessat);
}

template <typename T>
std::string print_fcntl_lockf_cmd(const T v)
{
    return print_enum_entry(v, fcntl_lockf_cmd);
}
}

#endif //ABII_C_LOGGING_PLUGIN_FCNTL_H
