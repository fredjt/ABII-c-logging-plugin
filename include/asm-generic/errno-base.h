//
// Created by Trent Tanchin on 7/4/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_ERRNO_BASE_H
#define ABII_C_LOGGING_PLUGIN_ERRNO_BASE_H

#include <abii/libabii.h>

namespace abii
{
const defines_map errno_base_defines = {
    {EPERM, "EPERM"},
    {ENOENT, "ENOENT"},
    {ESRCH, "ESRCH"},
    {EINTR, "EINTR"},
    {EIO, "EIO"},
    {ENXIO, "ENXIO"},
    {E2BIG, "E2BIG"},
    {ENOEXEC, "ENOEXEC"},
    {EBADF, "EBADF"},
    {ECHILD, "ECHILD"},
    {EAGAIN, "EAGAIN"},
    {ENOMEM, "ENOMEM"},
    {EACCES, "EACCES"},
    {EFAULT, "EFAULT"},
    {ENOTBLK, "ENOTBLK"},
    {EBUSY, "EBUSY"},
    {EEXIST, "EEXIST"},
    {EXDEV, "EXDEV"},
    {ENODEV, "ENODEV"},
    {ENOTDIR, "ENOTDIR"},
    {EISDIR, "EISDIR"},
    {EINVAL, "EINVAL"},
    {ENFILE, "ENFILE"},
    {EMFILE, "EMFILE"},
    {ENOTTY, "ENOTTY"},
    {ETXTBSY, "ETXTBSY"},
    {EFBIG, "EFBIG"},
    {ENOSPC, "ENOSPC"},
    {ESPIPE, "ESPIPE"},
    {EROFS, "EROFS"},
    {EMLINK, "EMLINK"},
    {EPIPE, "EPIPE"},
    {EDOM, "EDOM"},
    {ERANGE, "ERANGE"},
};

template <typename T>
std::string print_errno_base_defines(const T v)
{
    return print_enum_entry(v, errno_base_defines);
}
}

#endif //ABII_C_LOGGING_PLUGIN_ERRNO_BASE_H
