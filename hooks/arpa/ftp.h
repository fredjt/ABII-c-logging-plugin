//
// Created by Trent Tanchin on 11/8/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_ARPA_FTP_H
#define ABII_C_LOGGING_PLUGIN_ARPA_FTP_H

#include <abii/libabii.h>
#include <arpa/ftp.h>

namespace abii
{
const defines_map arpa_ftp_reply = {
    {1, "PRELIM"},
    {2, "COMPLETE"},
    {3, "CONTINUE"},
    {4, "TRANSIENT"},
    {5, "ERROR"}
};

const defines_map arpa_ftp_type = {
    {1, "TYPE_A"},
    {2, "TYPE_E"},
    {3, "TYPE_I"},
    {4, "TYPE_L"}
};

const defines_map arpa_ftp_form = {
    {1, "FORM_N"},
    {2, "FORM_T"},
    {3, "FORM_C"}
};

const defines_map arpa_ftp_stru = {
    {1, "STRU_F"},
    {2, "STRU_R"},
    {3, "STRU_P"}
};

const defines_map arpa_ftp_mode = {
    {1, "MODE_S"},
    {2, "MODE_B"},
    {3, "MODE_C"}
};

const defines_map arpa_ftp_rec = {
    {'\377', "REC_ESC"},
    {'\001', "REC_EOR"},
    {'\002', "REC_EOF"}
};

const defines_map arpa_ftp_blk = {
    {0x80, "BLK_EOR"},
    {0x40, "BLK_EOF"},
    {0x20, "BLK_ERRORS"},
    {0x10, "BLK_RESTART"}
};

const defines_map arpa_ftp_blk_bytecount = {
    {2, "BLK_BYTECOUNT"}
};

template <typename T>
std::string print_arpa_ftp_reply(const T v)
{
    return print_enum_entry(v, arpa_ftp_reply);
}

template <typename T>
std::string print_arpa_ftp_type(const T v)
{
    return print_enum_entry(v, arpa_ftp_type);
}

template <typename T>
std::string print_arpa_ftp_form(const T v)
{
    return print_enum_entry(v, arpa_ftp_form);
}

template <typename T>
std::string print_arpa_ftp_stru(const T v)
{
    return print_enum_entry(v, arpa_ftp_stru);
}

template <typename T>
std::string print_arpa_ftp_mode(const T v)
{
    return print_enum_entry(v, arpa_ftp_mode);
}

template <typename T>
std::string print_arpa_ftp_rec(const T v)
{
    return print_enum_entry(v, arpa_ftp_rec);
}

template <typename T>
std::string print_arpa_ftp_blk(const T v)
{
    return print_or_enum_entries(v, arpa_ftp_blk);
}

template <typename T>
std::string print_arpa_ftp_blk_bytecount(const T v)
{
    return print_enum_entry(v, arpa_ftp_blk_bytecount);
}
}

#endif //ABII_C_LOGGING_PLUGIN_ARPA_FTP_H
