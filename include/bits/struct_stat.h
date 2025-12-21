//
// Created by Trent Tanchin on 9/18/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_STRUCT_STAT_H
#define ABII_C_LOGGING_PLUGIN_STRUCT_STAT_H

#include <bits/struct_stat.h>

#include "types/struct_timespec.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, stat>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#ifndef __USE_TIME64_REDIRECTS
    abii_args->push_arg(new ArgPrinter(obj.st_dev, "st_dev", &os));
# ifndef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__pad1, "__pad1", &os));
#endif
# if defined __x86_64__ || !defined __USE_FILE_OFFSET64
    abii_args->push_arg(new ArgPrinter(obj.st_ino, "st_ino", &os));
# else
    abii_args->push_arg(new ArgPrinter(obj.__st_ino, "__st_ino", &os));
# endif
# ifndef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.st_mode, "st_mode", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_nlink, "st_nlink", &os));
# else
    abii_args->push_arg(new ArgPrinter(obj.st_nlink, "st_nlink", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_mode, "st_mode", &os));
# endif
    abii_args->push_arg(new ArgPrinter(obj.st_uid, "st_uid", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_gid, "st_gid", &os));
# ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__pad0, "__pad0", &os));
# endif
    abii_args->push_arg(new ArgPrinter(obj.st_rdev, "st_rdev", &os));
# ifndef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__pad2, "__pad2", &os));
# endif
    abii_args->push_arg(new ArgPrinter(obj.st_size, "st_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_blksize, "st_blksize", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_blocks, "st_blocks", &os));
# ifdef __USE_XOPEN2K8
    abii_args->push_arg(new ArgPrinter(obj.st_atim, "st_atim", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_mtim, "st_mtim", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_ctim, "st_ctim", &os));
# else
    abii_args->push_arg(new ArgPrinter(obj.st_atime, "st_atime", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_atimensec, "st_atimensec", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_mtime, "st_mtime", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_mtimensec, "st_mtimensec", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_ctime, "st_ctime", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_ctimensec, "st_ctimensec", &os));
# endif
# ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved, "__glibc_reserved", &os, RECURSE));
# else
#  ifndef __USE_FILE_OFFSET64
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved4, "__glibc_reserved4", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved5, "__glibc_reserved5", &os));
#  else
    abii_args->push_arg(new ArgPrinter(obj.st_ino, "st_ino", &os, RECURSE));
#  endif
# endif
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, struct stat64>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#ifndef __USE_TIME64_REDIRECTS
    abii_args->push_arg(new ArgPrinter(obj.st_dev, "st_dev", &os));
# ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.st_ino, "st_ino", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_nlink, "st_nlink", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_mode, "st_mode", &os));
# else
    abii_args->push_arg(new ArgPrinter(obj.__pad1, "__pad1", &os));
    abii_args->push_arg(new ArgPrinter(obj.__st_ino, "__st_ino", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_mode, "st_mode", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_nlink, "st_nlink", &os));
# endif
    abii_args->push_arg(new ArgPrinter(obj.st_uid, "st_uid", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_gid, "st_gid", &os));
#  ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__pad0, "__pad0", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_rdev, "st_rdev", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_size, "st_size", &os));
# else
    abii_args->push_arg(new ArgPrinter(obj.st_rdev, "st_rdev", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad2, "__pad2", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_size, "st_size", &os));
# endif
    abii_args->push_arg(new ArgPrinter(obj.st_blksize, "st_blksize", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_blocks, "st_blocks", &os));
#  ifdef __USE_XOPEN2K8
    abii_args->push_arg(new ArgPrinter(obj.st_atim, "st_atim", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_mtim, "st_mtim", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_ctim, "st_ctim", &os));
# else
    abii_args->push_arg(new ArgPrinter(obj.st_atime, "st_atime", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_atimensec, "st_atimensec", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_mtime, "st_mtime", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_mtimensec, "st_mtimensec", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_ctime, "st_ctime", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_ctimensec, "st_ctimensec", &os));
# endif
#  ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved, "__glibc_reserved", &os, RECURSE));
# else
    abii_args->push_arg(new ArgPrinter(obj.st_ino, "st_ino", &os, RECURSE));
# endif
#endif
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_STRUCT_STAT_H
