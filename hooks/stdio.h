//
// Created by Trent Tanchin on 8/31/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_STDIO_H
#define ABII_C_LOGGING_PLUGIN_STDIO_H

#include <abii/libabii.h>

namespace abii
{
const defines_map stdio_buffer_mode = {
    {0, "_IOFBF"},
    {1, "_IOLBF"},
    {2, "_IONBF"}
};

const defines_map stdio_bufsiz = {
    {8192, "BUFSIZ"}
};

const defines_map stdio_eof = {
    {(-1), "EOF"}
};

const defines_map stdio_seek_whence = {
    {0, "SEEK_SET"},
    {1, "SEEK_CUR"},
    {2, "SEEK_END"},
    {3, "SEEK_DATA"},
    {4, "SEEK_HOLE"}
};

const defines_map<const char*> stdio_p_tmpdir = {
    {"/tmp", "P_tmpdir"}
};

const defines_map stdio_l_tmpnam = {
    {20, "L_tmpnam"}
};

const defines_map stdio_tmp_max = {
    {238328, "TMP_MAX"}
};

const defines_map stdio_l_ctermid = {
    {9, "L_ctermid"}
};

const defines_map stdio_l_cuserid = {
    {9, "L_cuserid"}
};

const defines_map stdio_fopen_max = {
    {16, "FOPEN_MAX"}
};

const defines_map stdio_printf_nan_len_max = {
    {4, "_PRINTF_NAN_LEN_MAX"}
};

const defines_map stdio_rename_flags = {
    {(1 << 0), "RENAME_NOREPLACE"},
    {(1 << 1), "RENAME_EXCHANGE"},
    {(1 << 2), "RENAME_WHITEOUT"}
};

template <typename T>
std::string print_stdio_buffer_mode(const T v)
{
    return print_enum_entry(v, stdio_buffer_mode);
}

template <typename T>
std::string print_stdio_bufsiz(const T v)
{
    return print_enum_entry(v, stdio_bufsiz);
}

template <typename T>
std::string print_stdio_eof(const T v)
{
    return print_enum_entry(v, stdio_eof);
}

template <typename T>
std::string print_stdio_seek_whence(const T v)
{
    return print_enum_entry(v, stdio_seek_whence);
}

template <typename T>
std::string print_stdio_p_tmpdir(const T v)
{
    return print_enum_entry(v, stdio_p_tmpdir);
}

template <typename T>
std::string print_stdio_l_tmpnam(const T v)
{
    return print_enum_entry(v, stdio_l_tmpnam);
}

template <typename T>
std::string print_stdio_tmp_max(const T v)
{
    return print_enum_entry(v, stdio_tmp_max);
}

template <typename T>
std::string print_stdio_l_ctermid(const T v)
{
    return print_enum_entry(v, stdio_l_ctermid);
}

template <typename T>
std::string print_stdio_l_cuserid(const T v)
{
    return print_enum_entry(v, stdio_l_cuserid);
}

template <typename T>
std::string print_stdio_fopen_max(const T v)
{
    return print_enum_entry(v, stdio_fopen_max);
}

template <typename T>
std::string print_stdio_printf_nan_len_max(const T v)
{
    return print_enum_entry(v, stdio_printf_nan_len_max);
}

template <typename T>
std::string print_stdio_rename_flags(const T v)
{
    return print_or_enum_entries(v, stdio_rename_flags);
}
}

#endif //ABII_C_LOGGING_PLUGIN_STDIO_H
