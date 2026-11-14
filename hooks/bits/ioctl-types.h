//
// Created by Trent Tanchin on 3/10/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_IOCTL_TYPES_H
#define ABII_C_LOGGING_PLUGIN_BITS_IOCTL_TYPES_H

#include <abii/libabii.h>
#include <sys/ioctl.h>

namespace abii
{
const defines_map bits_ioctl_types_modem_lines = {
    {TIOCM_LE, "TIOCM_LE"},
    {TIOCM_DTR, "TIOCM_DTR"},
    {TIOCM_RTS, "TIOCM_RTS"},
    {TIOCM_ST, "TIOCM_ST"},
    {TIOCM_SR, "TIOCM_SR"},
    {TIOCM_CTS, "TIOCM_CTS"},
    {TIOCM_CAR, "TIOCM_CAR"},
    {TIOCM_RNG, "TIOCM_RNG"},
    {TIOCM_DSR, "TIOCM_DSR"},
    {TIOCM_CD, "TIOCM_CD"},
    {TIOCM_RI, "TIOCM_RI"}
};

const defines_map bits_ioctl_types_line_disciplines = {
    {N_TTY, "N_TTY"},
    {N_SLIP, "N_SLIP"},
    {N_MOUSE, "N_MOUSE"},
    {N_PPP, "N_PPP"},
    {N_STRIP, "N_STRIP"},
    {N_AX25, "N_AX25"},
    {N_X25, "N_X25"},
    {N_6PACK, "N_6PACK"},
    {N_MASC, "N_MASC"},
    {N_R3964, "N_R3964"},
    {N_PROFIBUS_FDL, "N_PROFIBUS_FDL"},
    {N_IRDA, "N_IRDA"},
    {N_SMSBLOCK, "N_SMSBLOCK"},
    {N_HDLC, "N_HDLC"},
    {N_SYNC_PPP, "N_SYNC_PPP"},
    {N_HCI, "N_HCI"}
};

template <typename T>
std::string print_bits_ioctl_types_modem_lines(const T v)
{
    return print_or_enum_entries(v, bits_ioctl_types_modem_lines);
}

template <typename T>
std::string print_bits_ioctl_types_line_disciplines(const T v)
{
    return print_enum_entry(v, bits_ioctl_types_line_disciplines);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, winsize>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ws_row, "ws_row", &os));
    abii_args->push_arg(new ArgPrinter(obj.ws_col, "ws_col", &os));
    abii_args->push_arg(new ArgPrinter(obj.ws_xpixel, "ws_xpixel", &os));
    abii_args->push_arg(new ArgPrinter(obj.ws_ypixel, "ws_ypixel", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_IOCTL_TYPES_H
