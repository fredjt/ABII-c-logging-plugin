//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_LINUX_FALLOC_H
#define ABII_C_LOGGING_PLUGIN_LINUX_FALLOC_H

#include <abii/libabii.h>

namespace abii
{
const defines_map linux_falloc_fl = {
    {FALLOC_FL_ALLOCATE_RANGE, "FALLOC_FL_ALLOCATE_RANGE"},
    {FALLOC_FL_KEEP_SIZE, "FALLOC_FL_KEEP_SIZE"},
    {FALLOC_FL_PUNCH_HOLE, "FALLOC_FL_PUNCH_HOLE"},
    {FALLOC_FL_NO_HIDE_STALE, "FALLOC_FL_NO_HIDE_STALE"},
    {FALLOC_FL_COLLAPSE_RANGE, "FALLOC_FL_COLLAPSE_RANGE"},
    {FALLOC_FL_ZERO_RANGE, "FALLOC_FL_ZERO_RANGE"},
    {FALLOC_FL_INSERT_RANGE, "FALLOC_FL_INSERT_RANGE"},
    {FALLOC_FL_UNSHARE_RANGE, "FALLOC_FL_UNSHARE_RANGE"},
    {FALLOC_FL_WRITE_ZEROES, "FALLOC_FL_WRITE_ZEROES"}
};


template <typename T>
std::string print_linux_falloc_fl(const T v)
{
    return print_or_enum_entries(v, linux_falloc_fl);
}
}
#endif //ABII_C_LOGGING_PLUGIN_LINUX_FALLOC_H
