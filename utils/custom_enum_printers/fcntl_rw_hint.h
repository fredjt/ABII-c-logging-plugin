//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_RWHINT_H
#define ABII_C_LOGGING_PLUGIN_RWHINT_H

#include <abii/libabii.h>

#include "hooks/stdint.h"
#include "hooks/bits/fcntl-linux.h"

template <typename T>
static std::string print_fcntl_rw_hint(const T v)
{
    return print_enum_entry(v, bits_fcntl_linux_rw_hint, stdint_uint64);
}

#endif //ABII_C_LOGGING_PLUGIN_RWHINT_H
