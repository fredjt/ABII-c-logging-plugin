//
// Created by Trent Tanchin on 11/11/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_ERROR_H
#define ABII_C_LOGGING_PLUGIN_ERROR_H

#include <abii/libabii.h>

#include "hooks/asm-generic/errno-base.h"
#include "hooks/asm-generic/errno.h"
#include "hooks/bits/errno.h"

namespace abii
{
template <typename T>
std::string print_error(const T v)
{
    return print_enum_entry(v, errno_error, errno_base_error, bits_errno_error);
}
}

#endif //ABII_C_LOGGING_PLUGIN_ERROR_H
