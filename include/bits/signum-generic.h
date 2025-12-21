//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGNUM_GENERIC_H
#define ABII_C_LOGGING_PLUGIN_SIGNUM_GENERIC_H

#include <bits/signum-generic.h>

namespace abii
{
const defines_map signum_generic_enum1 = {
    {SIGINT, "SIGINT"},
    {SIGILL, "SIGILL"},
    {SIGABRT, "SIGABRT"},
    {SIGFPE, "SIGFPE"},
    {SIGSEGV, "SIGSEGV"},
    {SIGTERM, "SIGTERM"},
    {SIGHUP, "SIGHUP"},
    {SIGQUIT, "SIGQUIT"},
    {SIGTRAP, "SIGTRAP"},
    {SIGKILL, "SIGKILL"},
    {SIGPIPE, "SIGPIPE"},
    {SIGALRM, "SIGALRM"},
    {SIGIO, "SIGIO"},
    {SIGIOT, "SIGIOT"},
    {SIGCLD, "SIGCLD"}
};

template<typename T>
std::string print_signum_generic_enum1(const T v)
{
    return print_enum_entry(v, signum_generic_enum1);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SIGNUM_GENERIC_H
