//
// Created by Trent Tanchin on 11/11/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_FD_H
#define ABII_C_LOGGING_PLUGIN_FD_H

#include <abii/libabii.h>

#include "hooks/fcntl.h"
#include "hooks/unistd.h"
#include "hooks/bits/fcntl-linux.h"

namespace abii
{
template <typename T>
std::string print_fd(const T v)
{
    return print_enum_entry(v, bits_fcntl_linux_fd_pidfs_root, fcntl_at_fdcwd, unistd_fileno);
}
}

#endif //ABII_C_LOGGING_PLUGIN_FD_H
