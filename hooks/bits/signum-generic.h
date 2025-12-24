//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGNUM_GENERIC_H
#define ABII_C_LOGGING_PLUGIN_SIGNUM_GENERIC_H

#include <bits/signum-generic.h>

namespace abii
{
const defines_map signum_generic_signal = {
    {2, "SIGINT"},
    {4, "SIGILL"},
    {6, "SIGABRT"},
    {8, "SIGFPE"},
    {11, "SIGSEGV"},
    {15, "SIGTERM"},
    {1, "SIGHUP"},
    {3, "SIGQUIT"},
    {5, "SIGTRAP"},
    {9, "SIGKILL"},
    {13, "SIGPIPE"},
    {14, "SIGALRM"},
    {29, "SIGIO"},
    {6, "SIGIOT"},
    {17, "SIGCLD"}
};

template <typename T>
std::string print_signum_generic_signal(const T v)
{
    return print_enum_entry(v, signum_generic_signal);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SIGNUM_GENERIC_H
