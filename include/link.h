//
// Created by Trent Tanchin on 7/26/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_LINK_H
#define ABII_C_LOGGING_PLUGIN_LINK_H

#include <link.h>
#include <abii/libabii.h>

#include "elf.h"

namespace abii
{
const defines_map link_rt = {
    {0, "RT_CONSISTENT"},
    {1, "RT_ADD"},
    {2, "RT_DELETE"}
};

const defines_map link_la_act = {
    {0, "LA_ACT_CONSISTENT"},
    {1, "LA_ACT_ADD"},
    {2, "LA_ACT_DELETE"}
};

const defines_map link_la_ser = {
    {1, "LA_SER_ORIG"},
    {2, "LA_SER_LIBPATH"},
    {4, "LA_SER_RUNPATH"},
    {8, "LA_SER_CONFIG"},
    {64, "LA_SER_DEFAULT"},
    {128, "LA_SER_SECURE"}
};

const defines_map link_la_flg = {
    {1, "LA_FLG_BINDTO"},
    {2, "LA_FLG_BINDFROM"}
};

const defines_map link_la_symb = {
    {1, "LA_SYMB_NOPLTENTER"},
    {2, "LA_SYMB_NOPLTEXIT"},
    {4, "LA_SYMB_STRUCTCALL"},
    {8, "LA_SYMB_DLSYM"},
    {16, "LA_SYMB_ALTVALUE"}
};

template <typename T>
std::string print_link_rt(const T v)
{
    return print_enum_entry(v, link_rt);
}

template <typename T>
std::string print_link_la_act(const T v)
{
    return print_enum_entry(v, link_la_act);
}

template <typename T>
std::string print_link_la_ser(const T v)
{
    return print_or_enum_entries(v, link_la_ser);
}

template <typename T>
std::string print_link_la_flg(const T v)
{
    return print_or_enum_entries(v, link_la_flg);
}

template <typename T>
std::string print_link_la_symb(const T v)
{
    return print_or_enum_entries(v, link_la_symb);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, r_debug>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.r_version, "r_version", &os));
    abii_args->push_arg(new ArgPrinter(obj.r_map, "r_map", &os));
    abii_args->push_arg(new ArgPrinter(obj.r_brk, "r_brk", &os));

    auto printer = ArgPrinter(obj.r_state, "r_state", &os);
    printer.set_enum_printer(print_link_rt, obj.r_state);
    abii_args->push_arg(&printer);

    abii_args->push_arg(new ArgPrinter(obj.r_ldbase, "r_ldbase", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, r_debug_extended>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.base, "base", &os));
    abii_args->push_arg(new ArgPrinter(obj.r_next, "r_next", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, link_map>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.l_addr, "l_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.l_name, "l_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.l_ld, "l_ld", &os));
    abii_args->push_arg(new ArgPrinter(obj.l_next, "l_next", &os, PRINT_ENDL));
    abii_args->push_arg(new ArgPrinter(obj.l_prev, "l_prev", &os, 0));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, dl_phdr_info>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.dlpi_addr, "dlpi_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlpi_name, "dlpi_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlpi_phdr, "dlpi_phdr", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlpi_phnum, "dlpi_phnum", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlpi_adds, "dlpi_adds", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlpi_subs, "dlpi_subs", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlpi_tls_modid, "dlpi_tls_modid", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlpi_tls_data, "dlpi_tls_data", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_LINK_H
