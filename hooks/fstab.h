//
// Created by Trent Tanchin on 9/17/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_FSTAB_H
#define ABII_C_LOGGING_PLUGIN_FSTAB_H

#include <fstab.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<const char*> fstab_path = {
    {"/etc/fstab", "_PATH_FSTAB"},
    {"/etc/fstab", "FSTAB"}
};

const defines_map<const char*> fstab_mntops = {
    {"rw", "FSTAB_RW"},
    {"rq", "FSTAB_RQ"},
    {"ro", "FSTAB_RO"},
    {"sw", "FSTAB_SW"},
    {"xx", "FSTAB_XX"}
};

template <typename T>
std::string print_fstab_path(const T v)
{
    return print_enum_entry(v, fstab_path);
}

template <typename T>
std::string print_fstab_mntops(const T v)
{
    return print_enum_entry(v, fstab_mntops);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, fstab>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.fs_spec, "fs_spec", &os));
    abii_args->push_arg(new ArgPrinter(obj.fs_file, "fs_file", &os));
    abii_args->push_arg(new ArgPrinter(obj.fs_vfstype, "fs_vfstype", &os));
    abii_args->push_arg(new ArgPrinter(obj.fs_mntops, "fs_mntops", &os));

    auto printer = new ArgPrinter(obj.fs_type, "fs_type", &os);
    printer->set_enum_printer(print_fstab_mntops, obj.fs_type);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.fs_freq, "fs_freq", &os));
    abii_args->push_arg(new ArgPrinter(obj.fs_passno, "fs_passno", &os, PRINT_ENDL));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_FSTAB_H
