//
// Created by Trent Tanchin on 12/18/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_CUSTOM_ENUM_PRINTERS_H
#define ABII_C_LOGGING_PLUGIN_CUSTOM_ENUM_PRINTERS_H

#include <string>

#include "include/asm-generic/errno-base.h"
#include "include/asm-generic/errno.h"
#include "include/bits/signum-arch.h"
#include "include/bits/signum-generic.h"

namespace abii
{
template <typename T>
std::string print_error_enum_entry(const T v)
{
    return print_enum_entry(v, errno_defines, errno_base_defines);
}

template <typename T>
std::string print_signum_enum_entry(const T v)
{
    return print_enum_entry(v, signum_arch_enum1, signum_generic_enum1);
}
}

#endif //ABII_C_LOGGING_PLUGIN_CUSTOM_ENUM_PRINTERS_H
