//
// Created by Trent Tanchin on 12/18/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_CUSTOM_ENUM_PRINTERS_H
#define ABII_C_LOGGING_PLUGIN_CUSTOM_ENUM_PRINTERS_H

#include <string>

#include "hooks/asm-generic/errno-base.h"
#include "hooks/asm-generic/errno.h"
#include "hooks/bits/signum-arch.h"
#include "hooks/bits/signum-generic.h"

namespace abii
{
template <typename T>
std::string print_error_enum_entry(const T v)
{
    return print_enum_entry(v, errno_error, errno_base_error);
}

template <typename T>
std::string print_signum_enum_entry(const T v)
{
    return print_enum_entry(v, signum_arch_signal, signum_generic_signal);
}
}

#endif //ABII_C_LOGGING_PLUGIN_CUSTOM_ENUM_PRINTERS_H
