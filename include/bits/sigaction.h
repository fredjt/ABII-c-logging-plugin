//
// Created by Trent Tanchin on 5/25/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGACTION_H
#define ABII_C_LOGGING_PLUGIN_SIGACTION_H

#include <bits/sigaction.h>

#include "types/__sigset_t.h"

namespace abii
{
const defines_map sigaction_enum1 = {
    {SA_NOCLDSTOP, "SA_NOCLDSTOP"},
    {SA_NOCLDWAIT, "SA_NOCLDWAIT"},
    {SA_SIGINFO, "SA_SIGINFO"}
#if defined __USE_XOPEN_EXTENDED || defined __USE_MISC
    ,
    {SA_ONSTACK, "SA_ONSTACK"}
#endif
#if defined __USE_XOPEN_EXTENDED || defined __USE_XOPEN2K8
    ,
    {SA_RESTART, "SA_RESTART"},
    {SA_NODEFER, "SA_NODEFER"},
    {SA_RESETHAND, "SA_RESETHAND"}
#endif
#ifdef __USE_MISC
    ,
    {SA_INTERRUPT, "SA_INTERRUPT"},
    {SA_NOMASK, "SA_NOMASK"},
    {SA_ONESHOT, "SA_ONESHOT"},
    {SA_STACK, "SA_STACK"}
#endif
};

const defines_map sigaction_enum2 = {
    {SIG_BLOCK, "SIG_BLOCK"},
    {SIG_UNBLOCK, "SIG_UNBLOCK"},
    {SIG_SETMASK, "SIG_SETMASK"}
};

template <typename T>
std::string print_sigaction_enum1(const T v)
{
    return print_or_enum_entries(v, sigaction_enum1);
}

template <typename T>
std::string print_sigaction_enum2(const T v)
{
    return print_enum_entry(v, sigaction_enum2);
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
    printer->set_enum_printer(print_sigaction_enum1, obj.sa_flags);
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
