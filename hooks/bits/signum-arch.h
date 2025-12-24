//
// Created by Trent Tanchin on 8/30/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGNUM_ARCH_H
#define ABII_C_LOGGING_PLUGIN_SIGNUM_ARCH_H

#include <csignal>

namespace abii
{
const defines_map signum_arch_signal = {
    {16, "SIGSTKFLT"},
    {30, "SIGPWR"},
    {7, "SIGBUS"},
    {31, "SIGSYS"},
    {23, "SIGURG"},
    {19, "SIGSTOP"},
    {20, "SIGTSTP"},
    {18, "SIGCONT"},
    {17, "SIGCHLD"},
    {21, "SIGTTIN"},
    {22, "SIGTTOU"},
    {29, "SIGPOLL"},
    {25, "SIGXFSZ"},
    {24, "SIGXCPU"},
    {26, "SIGVTALRM"},
    {27, "SIGPROF"},
    {10, "SIGUSR1"},
    {12, "SIGUSR2"},
    {28, "SIGWINCH"},
    {29, "SIGIO"},
    {6, "SIGIOT"},
    {17, "SIGCLD"},
    {32, "__SIGRTMIN"},
    {64, "__SIGRTMAX"}
};

template <typename T>
std::string print_signum_arch_signal(const T v)
{
    return print_enum_entry(v, signum_arch_signal);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SIGNUM_ARCH_H
