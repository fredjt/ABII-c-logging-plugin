//
// Created by Trent Tanchin on 11/11/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGNUM_H
#define ABII_C_LOGGING_PLUGIN_SIGNUM_H

#include <abii/libabii.h>

#include "hooks/bits/signum-arch.h"
#include "hooks/bits/signum-generic.h"

namespace abii
{
template <typename T>
std::string print_signum_enum_entry(const T v)
{
    return print_enum_entry(v, signum_arch_signal, signum_generic_signal);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SIGNUM_H
