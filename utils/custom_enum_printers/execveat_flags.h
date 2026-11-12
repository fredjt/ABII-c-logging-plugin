//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_EXECVEAT_FLAGS_H
#define ABII_C_LOGGING_PLUGIN_EXECVEAT_FLAGS_H

#include <abii/libabii.h>

#include "hooks/fcntl.h"
#include "hooks/bits/fcntl-linux.h"

template <typename T>
static std::string print_execveat_flags(const T v)
{
    return print_or_enum_entries(v, fcntl_execveat, bits_fcntl_linux_at_execve_check);
}

#endif //ABII_C_LOGGING_PLUGIN_EXECVEAT_FLAGS_H
