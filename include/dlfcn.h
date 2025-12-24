//
// Created by Trent Tanchin on 7/26/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_DLFCN_H
#define ABII_C_LOGGING_PLUGIN_DLFCN_H

#include <abii/libabii.h>

namespace abii
{
const defines_map dlfcn_lm_id = {
    {0, "LM_ID_BASE"},
    {-1, "LM_ID_NEWLM"}
};

const defines_map<void*> dlfcn_rtld = {
    {reinterpret_cast<void*>(-1l), "RTLD_NEXT"},
    {static_cast<void*>(nullptr), "RTLD_DEFAULT"}
};

const defines_map dlfcn_rtld_dl = {
    {1, "RTLD_DL_SYMENT"},
    {2, "RTLD_DL_LINKMAP"}
};

const defines_map dlfcn_rtld_di = {
    {1, "RTLD_DI_LMID"},
    {2, "RTLD_DI_LINKMAP"},
    {3, "RTLD_DI_CONFIGADDR"},
    {4, "RTLD_DI_SERINFO"},
    {5, "RTLD_DI_SERINFOSIZE"},
    {6, "RTLD_DI_ORIGIN"},
    {7, "RTLD_DI_PROFILENAME"},
    {8, "RTLD_DI_PROFILEOUT"},
    {9, "RTLD_DI_TLS_MODID"},
    {10, "RTLD_DI_TLS_DATA"},
    {11, "RTLD_DI_PHDR"},
    {11, "RTLD_DI_MAX"}
};

template <typename T>
std::string print_dlfcn_enum1(const T v)
{
    return print_enum_entry(v, dlfcn_lm_id);
}

template <typename T>
std::string print_dlfcn_enum2(const T v)
{
    return print_enum_entry(v, dlfcn_rtld);
}

template <typename T>
std::string print_dlfcn_enum3(const T v)
{
    return print_enum_entry(v, dlfcn_rtld_dl);
}

template <typename T>
std::string print_dlfcn_enum4(const T v)
{
    return print_enum_entry(v, dlfcn_rtld_di);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Dl_info>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.dli_fname, "dli_fname", &os));
    abii_args->push_arg(new ArgPrinter(obj.dli_fbase, "dli_fbase", &os));
    abii_args->push_arg(new ArgPrinter(obj.dli_sname, "dli_sname", &os));
    abii_args->push_arg(new ArgPrinter(obj.dli_saddr, "dli_saddr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Dl_serpath>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.dls_name, "dls_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.dls_flags, "dls_flags", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Dl_serinfo>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.dls_size, "dls_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.dls_cnt, "dls_cnt", &os));

    auto printer = ArgPrinter(obj.dls_serpath, "dls_serpath", &os);
    printer.set_len(obj.dls_cnt);
    abii_args->push_arg(&printer);

# if __GNUC_PREREQ(3, 0)
    abii_args->push_arg(new ArgPrinter(obj.__dls_serpath_pad, "__dls_serpath_pad", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, dl_find_object>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.dlfo_flags, "dlfo_flags", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlfo_map_start, "dlfo_map_start", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlfo_map_end, "dlfo_map_end", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlfo_link_map, "dlfo_link_map", &os));
    abii_args->push_arg(new ArgPrinter(obj.dlfo_eh_frame, "dlfo_eh_frame", &os));
#if DLFO_STRUCT_HAS_EH_DBASE
    abii_args->push_arg(new ArgPrinter(obj.dlfo_eh_dbase, "dlfo_eh_dbase", &os));
#if __WORDSIZE == 32
    abii_args->push_arg(new ArgPrinter(obj.__dlfo_eh_dbase_pad, "__dlfo_eh_dbase_pad", &os));
#endif
#endif
#if DLFO_STRUCT_HAS_EH_COUNT
    abii_args->push_arg(new ArgPrinter(obj.dlfo_eh_count, "dlfo_eh_count", &os));
    abii_args->push_arg(new ArgPrinter(obj.__dlfo_eh_count_pad, "__dlfo_eh_count_pad", &os));
#endif
    abii_args->push_arg(new ArgPrinter(obj.__dlfo_reserved, "__dflo_reserved", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_DLFCN_H
