//
// Created by Trent Tanchin on 7/4/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_ASM_UCONTEXT_H
#define ABII_C_LOGGING_PLUGIN_ASM_UCONTEXT_H

#include <abii/libabii.h>

namespace abii
{
const defines_map ucontext_flags = {
    {0x1, "UC_FP_XSTATE"},
    {0x2, "UC_SIGCONTEXT_SS"},
    {0x4, "UC_STRICT_RESTORE_SS"}
};

template <typename T>
std::string print_ucontext_flags(const T v)
{
    return print_or_enum_entries(v, ucontext_flags);
}
}

#endif //ABII_C_LOGGING_PLUGIN_ASM_UCONTEXT_H
