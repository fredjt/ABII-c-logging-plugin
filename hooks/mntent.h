//
// Created by Trent Tanchin on 10/4/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_MNTENT_H
#define ABII_C_LOGGING_PLUGIN_MNTENT_H

#include <mntent.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<const char*> mntent_mnttype = {
    {"ignore", "MNTTYPE_IGNORE"},
    {"nfs", "MNTTYPE_NFS"},
    {"swap", "MNTTYPE_SWAP"}
};

const defines_map<const char*> mntent_mntopt = {
    {"defaults", "MNTOPT_DEFAULTS"},
    {"ro", "MNTOPT_RO"},
    {"rw", "MNTOPT_RW"},
    {"suid", "MNTOPT_SUID"},
    {"nosuid", "MNTOPT_NOSUID"},
    {"noauto", "MNTOPT_NOAUTO"}
};

template <typename T>
std::string print_mntent_mnttype(const T v)
{
    return print_enum_entry(v, mntent_mnttype);
}

template <typename T>
std::string print_mntent_mntopt(const T v)
{
    return print_enum_entry(v, mntent_mntopt);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, mntent>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.mnt_fsname, "mnt_fsname", &os));
    abii_args->push_arg(new ArgPrinter(obj.mnt_dir, "mnt_dir", &os));

    auto printer = new ArgPrinter(obj.mnt_type, "mnt_type", &os);
    printer->set_enum_printer(print_mntent_mnttype, const_cast<const char*>(obj.mnt_type));
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.mnt_opts, "mnt_opts", &os));
    abii_args->push_arg(new ArgPrinter(obj.mnt_freq, "mnt_freq", &os));
    abii_args->push_arg(new ArgPrinter(obj.mnt_passno, "mnt_passno", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_MNTENT_H
