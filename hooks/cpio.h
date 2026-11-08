//
// Created by Trent Tanchin on 11/8/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_CPIO_H
#define ABII_C_LOGGING_PLUGIN_CPIO_H

#include <cpio.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<const char*> cpio_magic = {
    {"070707", "MAGIC"}
};

const defines_map cpio_mode = {
    {000400, "C_IRUSRS"},
    {000200, "C_IWUSRD"},
    {000100, "C_IXUSR"},
    {000040, "C_IRGRP"},
    {000020, "C_IWGRP"},
    {000010, "C_IXGRP"},
    {000004, "C_IROTH"},
    {000002, "C_IWOTH"},
    {000001, "C_IXOTH"},
    {004000, "C_ISUID"},
    {002000, "C_ISGID"},
    {001000, "C_ISVTX"},
    {060000, "C_ISBLK"},
    {020000, "C_ISCHR"},
    {040000, "C_ISDIR"},
    {010000, "C_ISFIFO"},
    {0140000, "C_ISSOCK"},
    {0120000, "C_ISLNK"},
    {0110000, "C_ISCTG"},
    {0100000, "C_ISREG"}
};

template <typename T>
std::string print_cpio_magic(const T v)
{
    return print_enum_entry(v, cpio_magic);
}

template <typename T>
std::string print_cpio_mode(const T v)
{
    return print_or_enum_entries(v, cpio_mode);
}
}

#endif //ABII_C_LOGGING_PLUGIN_CPIO_H
