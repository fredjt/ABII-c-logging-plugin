//
// Created by Trent Tanchin on 9/17/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_FMTMSG_H
#define ABII_C_LOGGING_PLUGIN_FMTMSG_H

#include <fmtmsg.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<long int> fmtmsg_classification = {
    {0x001, "MM_HARD"},
    {0x002, "MM_SOFT"},
    {0x004, "MM_FIRM"},
    {0x008, "MM_APPL"},
    {0x010, "MM_UTIL"},
    {0x020, "MM_OPSYS"},
    {0x040, "MM_RECOVER"},
    {0x080, "MM_NRECOV"},
    {0x100, "MM_PRINT"},
    {0x200, "MM_CONSOLE"},
    {static_cast<long int>(0), "MM_NULLMC"}
};

const defines_map fmtmsg_severity = {
    {0, "MM_NOSEV"},
    {1, "MM_HALT"},
    {2, "MM_ERROR"},
    {3, "MM_WARNING"},
    {4, "MM_INFO"},
    {0, "MM_NULLSEV"}
};

const defines_map<char*> fmtmsg_mm_nulllbl = {
    {static_cast<char*>(nullptr), "MM_NULLLBL"}
};

const defines_map<char*> fmtmsg_mm_nulltxt = {
    {static_cast<char*>(nullptr), "MM_NULLTXT"}
};

const defines_map<char*> fmtmsg_mm_nullact = {
    {static_cast<char*>(nullptr), "MM_NULLACT"}
};

const defines_map<char*> fmtmsg_mm_nulltag = {
    {static_cast<char*>(nullptr), "MM_NULLTAG"}
};

const defines_map fmtmsg_fmtmsg_ret = {
    {-1, "MM_NOTOK"},
    {0, "MM_OK"},
    {1, "MM_NOMSG"},
    {4, "MM_NOCON"}
};

template <typename T>
std::string print_fmtmsg_classification(const T v)
{
    return print_or_enum_entries(v, fmtmsg_classification);
}

template <typename T>
std::string print_fmtmsg_severity(const T v)
{
    return print_enum_entry(v, fmtmsg_severity);
}

template <typename T>
std::string print_fmtmsg_mm_nulllbl(const T v)
{
    return print_enum_entry(v, fmtmsg_mm_nulllbl);
}

template <typename T>
std::string print_fmtmsg_mm_nulltxt(const T v)
{
    return print_enum_entry(v, fmtmsg_mm_nulltxt);
}

template <typename T>
std::string print_fmtmsg_mm_nullact(const T v)
{
    return print_enum_entry(v, fmtmsg_mm_nullact);
}

template <typename T>
std::string print_fmtmsg_mm_nulltag(const T v)
{
    return print_enum_entry(v, fmtmsg_mm_nulltag);
}

template <typename T>
std::string print_fmtmsg_fmtmsg_ret(const T v)
{
    return print_enum_entry(v, fmtmsg_fmtmsg_ret);
}
}

#endif //ABII_C_LOGGING_PLUGIN_FMTMSG_H
