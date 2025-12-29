//
// Created by Trent Tanchin on 5/26/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SPAWN_H
#define ABII_C_LOGGING_PLUGIN_SPAWN_H

#include <spawn.h>
#include <abii/libabii.h>

#include "bits/types/struct_sched_param.h"
#include "bits/types/__sigset_t.h"

namespace abii
{
const defines_map spawn_flag = {
    {0x01, "POSIX_SPAWN_RESETIDS"},
    {0x02, "POSIX_SPAWN_SETPGROUP"},
    {0x04, "POSIX_SPAWN_SETSIGDEF"},
    {0x08, "POSIX_SPAWN_SETSIGMASK"},
    {0x10, "POSIX_SPAWN_SETSCHEDPARAM"},
    {0x20, "POSIX_SPAWN_SETSCHEDULER"},
    {0x40, "POSIX_SPAWN_USEVFORK"},
    {0x80, "POSIX_SPAWN_SETSID"},
    {0x100, "POSIX_SPAWN_SETCGROUP"}
};

template <typename T>
std::string print_spawn_flag(const T v)
{
    return print_or_enum_entries(v, spawn_flag);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, posix_spawnattr_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.__flags, "__flags", &os);
    printer->set_enum_printer(print_spawn_flag, obj.__flags);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.__pgrp, "__pgrp", &os));
    abii_args->push_arg(new ArgPrinter(obj.__sd, "__sd", &os));
    abii_args->push_arg(new ArgPrinter(obj.__ss, "__ss", &os));
    abii_args->push_arg(new ArgPrinter(obj.__sp, "__sp", &os));
    abii_args->push_arg(new ArgPrinter(obj.__policy, "__policy", &os));
    abii_args->push_arg(new ArgPrinter(obj.__cgroup, "__cgroup", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad, "__pad", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

struct __spawn_action {};

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, posix_spawn_file_actions_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__allocated, "__allocated", &os));
    abii_args->push_arg(new ArgPrinter(obj.__used, "__used", &os));
    abii_args->push_arg(new ArgPrinter(obj.__actions, "__actions", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad, "__pad", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __spawn_action>
std::ostream& operator<<(std::ostream& os, T&& /*obj*/)
{
    OVERRIDE_STREAM_PREFIX
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_SPAWN_H
