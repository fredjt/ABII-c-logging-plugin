//
// Created by Trent Tanchin on 9/23/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_GLOB_H
#define ABII_C_LOGGING_PLUGIN_GLOB_H

#include <glob.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map glob_flag = {
    {(1 << 0), "GLOB_ERR"},
    {(1 << 1), "GLOB_MARK"},
    {(1 << 2), "GLOB_NOSORT"},
    {(1 << 3), "GLOB_DOOFFS"},
    {(1 << 4), "GLOB_NOCHECK"},
    {(1 << 5), "GLOB_APPEND"},
    {(1 << 6), "GLOB_NOESCAPE"},
    {(1 << 7), "GLOB_PERIOD"},
    {(1 << 8), "GLOB_MAGCHAR"},
    {(1 << 9), "GLOB_ALTDIRFUNC"},
    {(1 << 10), "GLOB_BRACE"},
    {(1 << 11), "GLOB_NOMAGIC"},
    {(1 << 12), "GLOB_TILDE"},
    {(1 << 13), "GLOB_ONLYDIR"},
    {(1 << 14), "GLOB_TILDE_CHECK"},
    {
        (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 6 | 1 << 4 | 1 << 5 | 1 << 7 | 1 << 9 | 1 << 10 | 1 << 11 | 1 << 12
            | 1 << 13 | 1 << 14),
        "__GLOB_FLAGS"
    }
};

const defines_map glob_error = {
    {1, "GLOB_NOSPACE"},
    {2, "GLOB_ABORTED"},
    {3, "GLOB_NOMATCH"},
    {4, "GLOB_NOSYS"},
    {2, "GLOB_ABEND"}
};

template <typename T>
std::string print_glob_flag(const T v)
{
    return print_or_enum_entries(v, glob_flag);
}

template <typename T>
std::string print_glob_error(const T v)
{
    return print_or_enum_entries(v, glob_error);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, glob_t>
    || std::is_same_v<std::remove_cvref_t<T>, glob64_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.gl_pathc, "gl_pathc", &os));
    abii_args->push_arg(new ArgPrinter(obj.gl_pathv, "gl_pathv", &os));
    abii_args->push_arg(new ArgPrinter(obj.gl_offs, "gl_offs", &os));

    auto printer = new ArgPrinter(obj.gl_flags, "gl_flags", &os);
    printer->set_enum_printer(print_glob_flag, obj.gl_flags);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.gl_closedir, "gl_closedir", &os));
    abii_args->push_arg(new ArgPrinter(obj.gl_readdir, "gl_readdir", &os));
    abii_args->push_arg(new ArgPrinter(obj.gl_opendir, "gl_opendir", &os));
    abii_args->push_arg(new ArgPrinter(obj.gl_lstat, "gl_lstat", &os));
    abii_args->push_arg(new ArgPrinter(obj.gl_stat, "gl_stat", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_GLOB_H
