//
// Created by Trent Tanchin on 7/4/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_TIMEX_H
#define ABII_C_LOGGING_PLUGIN_TIMEX_H

#include <abii/libabii.h>

#include "types/struct_timeval.h"

namespace abii
{
const defines_map timex_modes = {
    {0x0001, "ADJ_OFFSET"},
    {0x0002, "ADJ_FREQUENCY"},
    {0x0004, "ADJ_MAXERROR"},
    {0x0008, "ADJ_ESTERROR"},
    {0x0010, "ADJ_STATUS"},
    {0x0020, "ADJ_TIMECONST"},
    {0x0080, "ADJ_TAI"},
    {0x0100, "ADJ_SETOFFSET"},
    {0x1000, "ADJ_MICRO"},
    {0x2000, "ADJ_NANO"},
    {0x4000, "ADJ_TICK"},
    {0x8001, "ADJ_OFFSET_SINGLESHOT"},
    {0xa001, "ADJ_OFFSET_SS_READ"},
    {0x0001, "MOD_OFFSET"},
    {0x0002, "MOD_FREQUENCY"},
    {0x0004, "MOD_MAXERROR"},
    {0x0008, "MOD_ESTERROR"},
    {0x0010, "MOD_STATUS"},
    {0x0020, "MOD_TIMECONST"},
    {0x4000, "MOD_CLKB"},
    {0x8001, "MOD_CLKA"},
    {0x0080, "MOD_TAI"},
    {0x1000, "MOD_MICRO"},
    {0x2000, "MOD_NANO"}
};

const defines_map timex_statuses = {
    {0x0001, "STA_PLL"},
    {0x0002, "STA_PPSFREQ"},
    {0x0004, "STA_PPSTIME"},
    {0x0008, "STA_FLL"},
    {0x0010, "STA_INS"},
    {0x0020, "STA_DEL"},
    {0x0040, "STA_UNSYNC"},
    {0x0080, "STA_FREQHOLD"},
    {0x0100, "STA_PPSSIGNAL"},
    {0x0200, "STA_PPSJITTER"},
    {0x0400, "STA_PPSWANDER"},
    {0x0800, "STA_PPSERROR"},
    {0x1000, "STA_CLOCKERR"},
    {0x2000, "STA_NANO"},
    {0x4000, "STA_MODE"},
    {0x8000, "STA_CLK"},
    {0xff00, "STA_RONLY"}
};

template <typename T>
std::string print_timex_modes(const T v)
{
    return print_or_enum_entries(v, timex_modes);
}

template <typename T>
std::string print_timex_statuses(const T v)
{
    return print_or_enum_entries(v, timex_statuses);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, timex>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.modes, "modes", &os);
    printer->set_enum_printer(print_timex_modes, obj.modes);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.offset, "offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.freq, "freq", &os));
    abii_args->push_arg(new ArgPrinter(obj.maxerror, "maxerror", &os));
    abii_args->push_arg(new ArgPrinter(obj.esterror, "esterror", &os));

    auto printer1 = new ArgPrinter(obj.status, "status", &os);
    printer1->set_enum_printer(print_timex_statuses, obj.status);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.constant, "constant", &os));
    abii_args->push_arg(new ArgPrinter(obj.precision, "precision", &os));
    abii_args->push_arg(new ArgPrinter(obj.tolerance, "tolerance", &os));
    abii_args->push_arg(new ArgPrinter(obj.time, "time", &os));
    abii_args->push_arg(new ArgPrinter(obj.tick, "tick", &os));
    abii_args->push_arg(new ArgPrinter(obj.ppsfreq, "ppsfreq", &os));
    abii_args->push_arg(new ArgPrinter(obj.jitter, "jitter", &os));
    abii_args->push_arg(new ArgPrinter(obj.shift, "shift", &os));
    abii_args->push_arg(new ArgPrinter(obj.stabil, "stabil", &os));
    abii_args->push_arg(new ArgPrinter(obj.jitcnt, "jitcnt", &os));
    abii_args->push_arg(new ArgPrinter(obj.calcnt, "calcnt", &os));
    abii_args->push_arg(new ArgPrinter(obj.errcnt, "errcnt", &os));
    abii_args->push_arg(new ArgPrinter(obj.stbcnt, "stbcnt", &os));
    abii_args->push_arg(new ArgPrinter(obj.tai, "tai", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_TIMEX_H
