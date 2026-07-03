//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TTY_H
#define ABII_C_LOGGING_PLUGIN_TTY_H

#include <abii/libabii.h>

namespace abii
{
const defines_map<unsigned> tty_line_discipline = {
    {0, "N_TTY"},
    {1, "N_SLIP"},
    {2, "N_MOUSE"},
    {3, "N_PPP"},
    {4, "N_STRIP"},
    {5, "N_AX25"},
    {6, "N_X25"},
    {7, "N_6PACK"},
    {8, "N_MASC"},
    {9, "N_R3964"},
    {10, "N_PROFIBUS_FDL"},
    {11, "N_IRDA"},
    {12, "N_SMSBLOCK"},
    {13, "N_HDLC"},
    {14, "N_SYNC_PPP"},
    {15, "N_HCI"},
    {16, "N_GIGASET_M101"},
    {17, "N_SLCAN"},
    {18, "N_PPS"},
    {19, "N_V253"},
    {20, "N_CAIF"},
    {21, "N_GSM0710"},
    {22, "N_TI_WL"},
    {23, "N_TRACESINK"},
    {24, "N_TRACEROUTER"},
    {25, "N_NCI"},
    {26, "N_SPEAKUP"},
    {27, "N_NULL"},
    {28, "N_MCTP"},
    {29, "N_DEVELOPMENT"},
    {30, "N_CAN327"},
    {31, "NR_LDISCS"}
};

template <typename T>
std::string print_tty_line_discipline(const T v)
{
    return print_enum_entry(v, tty_line_discipline);
}
}

#endif //ABII_C_LOGGING_PLUGIN_TTY_H
