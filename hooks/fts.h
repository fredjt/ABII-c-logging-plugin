//
// Created by Trent Tanchin on 9/18/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_FTS_H
#define ABII_C_LOGGING_PLUGIN_FTS_H

#include <fts.h>
#include <abii/libabii.h>

#include "bits/struct_stat.h"

namespace abii
{
const defines_map fts_opts = {
    {0x0001, "FTS_COMFOLLOW"},
    {0x0002, "FTS_LOGICAL"},
    {0x0004, "FTS_NOCHDIR"},
    {0x0008, "FTS_NOSTAT"},
    {0x0010, "FTS_PHYSICAL"},
    {0x0020, "FTS_SEEDOT"},
    {0x0040, "FTS_XDEV"},
    {0x0080, "FTS_WHITEOUT"},
    {0x00ff, "FTS_OPTIONMASK"},
    {0x0100, "FTS_NAMEONLY"},
    {0x0200, "FTS_STOP"}
};

const defines_map fts_level = {
    {-1, "FTS_ROOTPARENTLEVEL"},
    {0, "FTS_ROOTLEVEL"}
};

const defines_map fts_info = {
    {1, "FTS_D"},
    {2, "FTS_DC"},
    {3, "FTS_DEFAULT"},
    {4, "FTS_DNR"},
    {5, "FTS_DOT"},
    {6, "FTS_DP"},
    {7, "FTS_ERR"},
    {8, "FTS_F"},
    {9, "FTS_INIT"},
    {10, "FTS_NS"},
    {11, "FTS_NSOK"},
    {12, "FTS_SL"},
    {13, "FTS_SLNONE"},
    {14, "FTS_W"}
};

const defines_map fts_flags = {
    {0x01, "FTS_DONTCHDIR"},
    {0x02, "FTS_SYMFOLLOW"}
};

const defines_map fts_instr = {
    {1, "FTS_AGAIN"},
    {2, "FTS_FOLLOW"},
    {3, "FTS_NOINSTR"},
    {4, "FTS_SKIP"}
};

template <typename T>
std::string print_fts_opts(const T v)
{
    return print_or_enum_entries(v, fts_opts);
}

template <typename T>
std::string print_fts_level(const T v)
{
    return print_enum_entry(v, fts_level);
}

template <typename T>
std::string print_fts_info(const T v)
{
    return print_enum_entry(v, fts_info);
}

template <typename T>
std::string print_fts_flags(const T v)
{
    return print_or_enum_entries(v, fts_flags);
}

template <typename T>
std::string print_fts_instr(const T v)
{
    return print_enum_entry(v, fts_instr);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, FTS>
    || std::is_same_v<std::remove_cvref_t<T>, FTS64>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.fts_cur, "fts_cur", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_child, "fts_child", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_array, "fts_array", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_dev, "fts_dev", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_path, "fts_path", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_rfd, "fts_rfd", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_pathlen, "fts_pathlen", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_nitems, "fts_nitems", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_compar, "fts_compar", &os));

    auto printer = new ArgPrinter(obj.fts_options, "fts_options", &os, RECURSE);
    printer->set_enum_printer(print_fts_opts, obj.fts_options);
    abii_args->push_arg(printer);

    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, FTSENT>
    || std::is_same_v<std::remove_cvref_t<T>, FTSENT64>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.fts_cycle, "fts_cycle", &os, PRINT_ENDL));
    abii_args->push_arg(new ArgPrinter(obj.fts_parent, "fts_parent", &os, PRINT_ENDL));
    abii_args->push_arg(new ArgPrinter(obj.fts_link, "fts_link", &os, PRINT_ENDL));
    abii_args->push_arg(new ArgPrinter(obj.fts_number, "fts_number", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_pointer, "fts_pointer", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_accpath, "fts_accpath", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_path, "fts_path", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_errno, "fts_errno", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_symfd, "fts_symfd", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_pathlen, "fts_pathlen", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_namelen, "fts_namelen", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_ino, "fts_ino", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_dev, "fts_dev", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_nlink, "fts_nlink", &os));

    auto printer = new ArgPrinter(obj.fts_level, "fts_level", &os);
    printer->set_enum_printer(print_fts_level, obj.fts_level);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.fts_info, "fts_info", &os);
    printer1->set_enum_printer(print_fts_info, obj.fts_info);
    abii_args->push_arg(printer1);

    auto printer2 = new ArgPrinter(obj.fts_flags, "fts_flags", &os);
    printer2->set_enum_printer(print_fts_flags, obj.fts_flags);
    abii_args->push_arg(printer2);

    auto printer3 = new ArgPrinter(obj.fts_instr, "fts_instr", &os);
    printer3->set_enum_printer(print_fts_instr, obj.fts_instr);
    abii_args->push_arg(printer3);

    abii_args->push_arg(new ArgPrinter(obj.fts_statp, "fts_statp", &os));
    abii_args->push_arg(new ArgPrinter(obj.fts_name, "fts_name", &os, RECURSE));

    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_FTS_H
