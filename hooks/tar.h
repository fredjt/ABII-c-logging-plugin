//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TAR_H
#define ABII_C_LOGGING_PLUGIN_TAR_H

#include <abii/libabii.h>

namespace abii
{
const defines_map<uint64_t> tar_mode = {
    {04000, "TSUID"},
    {02000, "TSGID"},
    {01000, "TSVTX"},
    {00400, "TUREAD"},
    {00200, "TUWRITE"},
    {00100, "TUEXEC"},
    {00040, "TGREAD"},
    {00020, "TGWRITE"},
    {00010, "TGEXEC"},
    {00004, "TOREAD"},
    {00002, "TOWRITE"},
    {00001, "TOEXEC"}
};

const defines_map<uint8_t> tar_typeflag = {
    {'0', "REGTYPE"},
    {'\0', "AREGTYPE"},
    {'1', "LNKTYPE"},
    {'2', "SYMTYPE"},
    {'3', "CHRTYPE"},
    {'4', "BLKTYPE"},
    {'5', "DIRTYPE"},
    {'6', "FIFOTYPE"},
    {'7', "CONTTYPE"}
};

const defines_map<const char*> tar_tmagic = {
    {"ustar", "TMAGIC"}
};

const defines_map tar_tmaglen = {
    {6, "TMAGLEN"}
};

const defines_map<const char*> tar_tversion = {
    {"00", "TVERSION"}
};

const defines_map tar_tverslen = {
    {2, "TVERSLEN"}
};

template <typename T>
std::string print_tar_mode(const T v)
{
    return print_or_enum_entries(v, tar_mode);
}

template <typename T>
std::string print_tar_typeflag(const T v)
{
    return print_enum_entry(v, tar_typeflag);
}

template <typename T>
std::string print_tar_tmagic(const T v)
{
    return print_enum_entry(v, tar_tmagic);
}

template <typename T>
std::string print_tar_tmaglen(const T v)
{
    return print_enum_entry(v, tar_tmaglen);
}

template <typename T>
std::string print_tar_tversion(const T v)
{
    return print_enum_entry(v, tar_tversion);
}

template <typename T>
std::string print_tar_tverslen(const T v)
{
    return print_enum_entry(v, tar_tverslen);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TAR_H
