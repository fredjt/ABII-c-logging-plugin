//
// Created by Trent Tanchin on 7/4/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_ERRNO_BASE_H
#define ABII_C_LOGGING_PLUGIN_ERRNO_BASE_H

#include <abii/libabii.h>

namespace abii
{
const defines_map errno_base_error = {
    {1, "EPERM"},
    {2, "ENOENT"},
    {3, "ESRCH"},
    {4, "EINTR"},
    {5, "EIO"},
    {6, "ENXIO"},
    {7, "E2BIG"},
    {8, "ENOEXEC"},
    {9, "EBADF"},
    {10, "ECHILD"},
    {11, "EAGAIN"},
    {12, "ENOMEM"},
    {13, "EACCES"},
    {14, "EFAULT"},
    {15, "ENOTBLK"},
    {16, "EBUSY"},
    {17, "EEXIST"},
    {18, "EXDEV"},
    {19, "ENODEV"},
    {20, "ENOTDIR"},
    {21, "EISDIR"},
    {22, "EINVAL"},
    {23, "ENFILE"},
    {24, "EMFILE"},
    {25, "ENOTTY"},
    {26, "ETXTBSY"},
    {27, "EFBIG"},
    {28, "ENOSPC"},
    {29, "ESPIPE"},
    {30, "EROFS"},
    {31, "EMLINK"},
    {32, "EPIPE"},
    {33, "EDOM"},
    {34, "ERANGE"},
};

template <typename T>
std::string print_errno_base_error(const T v)
{
    return print_enum_entry(v, errno_base_error);
}
}

#endif //ABII_C_LOGGING_PLUGIN_ERRNO_BASE_H
