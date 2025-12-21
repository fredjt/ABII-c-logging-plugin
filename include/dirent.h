//
// Created by Trent Tanchin on 7/27/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_DIRENT_H
#define ABII_C_LOGGING_PLUGIN_DIRENT_H

#include <abii/libabii.h>

namespace abii
{
const defines_map dirent_type = {
    {0, "DT_UNKNOWN"},
    {1, "DT_FIFO"},
    {2, "DT_CHR"},
    {4, "DT_DIR"},
    {6, "DT_BLK"},
    {8, "DT_REG"},
    {10, "DT_LNK"},
    {12, "DT_SOCK"},
    {14, "DT_WHT"}
};

template <typename T>
std::string print_dirent_type(const T v)
{
    return print_enum_entry(v, dirent_type);
}
}

#endif //ABII_C_LOGGING_PLUGIN_DIRENT_H
