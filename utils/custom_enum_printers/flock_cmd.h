//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_FLOCK_CMD_H
#define ABII_C_LOGGING_PLUGIN_FLOCK_CMD_H

#include <abii/libabii.h>

#include "hooks/bits/fcntl-linux.h"
#include "hooks/bits/fcntl.h"

namespace abii
{
template <typename T>
std::string print_flock_cmd(const T v)
{
    return print_enum_entry(v, bits_fcntl_flock, bits_fcntl_linux_cmd);
}
}

#endif //ABII_C_LOGGING_PLUGIN_FLOCK_CMD_H
