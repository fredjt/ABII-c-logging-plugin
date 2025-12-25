//
// Created by Trent Tanchin on 5/25/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGACTION_H
#define ABII_C_LOGGING_PLUGIN_SIGACTION_H

#include <bits/sigaction.h>

#include "types/__sigset_t.h"

namespace abii
{
const defines_map sigaction_flags = {
    {1, "SA_NOCLDSTOP"},
    {2, "SA_NOCLDWAIT"},
    {4, "SA_SIGINFO"},
    {0x08000000, "SA_ONSTACK"},
    {0x10000000, "SA_RESTART"},
    {0x40000000, "SA_NODEFER"},
    {0x80000000, "SA_RESETHAND"},
    {0x20000000, "SA_INTERRUPT"},
    {0x40000000, "SA_NOMASK"},
    {0x80000000, "SA_ONESHOT"},
    {0x08000000, "SA_STACK"}
};

const defines_map sigaction_how = {
    {0, "SIG_BLOCK"},
    {1, "SIG_UNBLOCK"},
    {2, "SIG_SETMASK"}
};

template <typename T>
std::string print_sigaction_flags(const T v)
{
    return print_or_enum_entries(v, sigaction_flags);
}

template <typename T>
std::string print_sigaction_how(const T v)
{
    return print_enum_entry(v, sigaction_how);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sigaction>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#if defined __USE_POSIX199309 || defined __USE_XOPEN_EXTENDED
    abii_args->push_arg(new ArgPrinter(obj.__sigaction_handler, "__sigaction_handler", &os));
#else
    abii_args->push_arg(new ArgPrinter(obj.sa_handler, "sa_handler", &os));
#endif
    abii_args->push_arg(new ArgPrinter(obj.sa_mask, "sa_mask", &os));

    auto printer = new ArgPrinter(obj.sa_flags, "sa_flags", &os);
    printer->set_enum_printer(print_sigaction_flags, obj.sa_flags);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.sa_restorer, "sa_restorer", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#if defined __USE_POSIX199309 || defined __USE_XOPEN_EXTENDED
#undef sa_handler
#undef sa_sigaction
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(sigaction::__sigaction_handler)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.sa_handler, "sa_handler", &os));
    abii_args->push_arg(new ArgPrinter(obj.sa_sigaction, "sa_sigaction", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_SIGACTION_H
