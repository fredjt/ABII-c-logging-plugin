//
// Created by Trent Tanchin on 8/30/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGNUM_ARCH_H
#define ABII_C_LOGGING_PLUGIN_SIGNUM_ARCH_H

#include <csignal>

namespace abii
{
const defines_map signum_arch_enum1 = {
    {SIGSTKFLT, "SIGSTKFLT"},
    {SIGPWR, "SIGPWR"},
    {SIGBUS, "SIGBUS"},
    {SIGSYS, "SIGSYS"},
    {SIGURG, "SIGURG"},
    {SIGSTOP, "SIGSTOP"},
    {SIGTSTP, "SIGTSTP"},
    {SIGCONT, "SIGCONT"},
    {SIGCHLD, "SIGCHLD"},
    {SIGTTIN, "SIGTTIN"},
    {SIGTTOU, "SIGTTOU"},
    {SIGPOLL, "SIGPOLL"},
    {SIGXFSZ, "SIGXFSZ"},
    {SIGXCPU, "SIGXCPU"},
    {SIGVTALRM, "SIGVTALRM"},
    {SIGPROF, "SIGPROF"},
    {SIGUSR1, "SIGUSR1"},
    {SIGUSR2, "SIGUSR2"},
    {SIGWINCH, "SIGWINCH"},
    {SIGIO, "SIGIO"},
    {SIGIOT, "SIGIOT"},
    {SIGCLD, "SIGCLD"},
    {__SIGRTMIN, "__SIGRTMIN"},
    {__SIGRTMAX, "__SIGRTMAX"}
};

template<typename T>
std::string print_signum_arch_enum1(const T v)
{
    return print_enum_entry(v, signum_arch_enum1);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SIGNUM_ARCH_H
