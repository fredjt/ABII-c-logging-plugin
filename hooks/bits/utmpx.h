//
// Created by Trent Tanchin on 9/26/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_UTMPX_H
#define ABII_C_LOGGING_PLUGIN_BITS_UTMPX_H

#include <utmpx.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<const char*> bits_utmpx_path = {
    {"/var/run/utmp", "_PATH_UTMPX"},
    {"/var/log/wtmp", "_PATH_WTMPX"}
};

const defines_map bits_utmpx_ut_linesize = {
    {32, "UT_LINESIZE"}
};

const defines_map bits_utmpx_ut_namesize = {
    {32, "UT_NAMESIZE"}
};

const defines_map bits_utmpx_ut_hostsize = {
    {256, "UT_HOSTSIZE"}
};

const defines_map bits_utmpx_ut_type = {
    {0, "EMPTY"},
    {1, "RUN_LVL"},
    {2, "BOOT_TIME"},
    {3, "NEW_TIME"},
    {4, "OLD_TIME"},
    {5, "INIT_PROCESS"},
    {6, "LOGIN_PROCESS"},
    {7, "USER_PROCESS"},
    {8, "DEAD_PROCESS"},
    {9, "ACCOUNTING"}
};

template <typename T>
std::string print_bits_utmpx_path(const T v)
{
    return print_enum_entry(v, bits_utmpx_path);
}

template <typename T>
std::string print_bits_utmpx_ut_linesize(const T v)
{
    return print_enum_entry(v, bits_utmpx_ut_linesize);
}

template <typename T>
std::string print_bits_utmpx_ut_namesize(const T v)
{
    return print_enum_entry(v, bits_utmpx_ut_namesize);
}

template <typename T>
std::string print_bits_utmpx_ut_hostsize(const T v)
{
    return print_enum_entry(v, bits_utmpx_ut_hostsize);
}

template <typename T>
std::string print_bits_utmpx_ut_type(const T v)
{
    return print_enum_entry(v, bits_utmpx_ut_type);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __exit_status>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#ifdef __USE_GNU
    abii_args->push_arg(new ArgPrinter(obj.e_termination, "e_termination", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_exit, "e_exit", &os, RECURSE));
#else
    abii_args->push_arg(new ArgPrinter(obj.__e_termination, "__e_termination", &os));
    abii_args->push_arg(new ArgPrinter(obj.__e_exit, "__e_exit", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, utmpx>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.ut_type, "ut_type", &os);
    printer->set_enum_printer(print_bits_utmpx_ut_type, obj.ut_type);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.ut_pid, "ut_pid", &os));
    abii_args->push_arg(new ArgPrinter(obj.ut_line, "ut_line", &os));
    abii_args->push_arg(new ArgPrinter(obj.ut_id, "ut_id", &os));
    abii_args->push_arg(new ArgPrinter(obj.ut_user, "ut_user", &os));
    abii_args->push_arg(new ArgPrinter(obj.ut_host, "ut_host", &os));
    abii_args->push_arg(new ArgPrinter(obj.ut_exit, "ut_exit", &os));
    abii_args->push_arg(new ArgPrinter(obj.ut_session, "ut_session", &os));
    abii_args->push_arg(new ArgPrinter(obj.ut_tv, "ut_tv", &os));
    abii_args->push_arg(new ArgPrinter(obj.ut_addr_v6, "ut_addr_v6", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved, "__glibc_reserved", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#if __WORDSIZE_TIME64_COMPAT32
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(utmpx::ut_tv)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.tv_sec, "tv_sec", &os));
    abii_args->push_arg(new ArgPrinter(obj.tv_usec, "tv_usec", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_BITS_UTMPX_H
