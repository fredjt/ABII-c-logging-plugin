//
// Created by Trent Tanchin on 5/26/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_STRUCT_SIGSTACK_H
#define ABII_C_LOGGING_PLUGIN_STRUCT_SIGSTACK_H

#include <abii/libabii.h>
#include <bits/types/struct_sigstack.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, struct sigstack>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ss_sp, "ss_sp", &os));
    abii_args->push_arg(new ArgPrinter(obj.ss_onstack, "ss_onstack", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_STRUCT_SIGSTACK_H
