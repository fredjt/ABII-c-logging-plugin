//
// Created by Trent Tanchin on 3/10/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_TERMIOS_STRUCT_H
#define ABII_C_LOGGING_PLUGIN_TERMIOS_STRUCT_H

#include <termios.h>
#include <abii/libabii.h>

#include "custom_enum_printers.h"
#include "termios-c_cc.h"
#include "termios-c_cflag.h"
#include "termios-c_iflag.h"
#include "termios-c_lflag.h"
#include "termios-c_oflag.h"
#include "hooks/linux/tty.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, termios>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.c_iflag, "c_iflag", &os);
    printer->set_enum_printer(print_termios_c_iflag_flags, obj.c_iflag);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.c_oflag, "c_oflag", &os);
    printer1->set_enum_printer(print_termios_c_oflag_flags, obj.c_oflag);
    abii_args->push_arg(printer1);

    auto printer2 = new ArgPrinter(obj.c_cflag, "c_cflag", &os);
    printer2->set_enum_printer(print_termios_c_cflag_flags, obj.c_cflag);
    abii_args->push_arg(printer2);

    auto printer3 = new ArgPrinter(obj.c_lflag, "c_lflag", &os);
    printer3->set_enum_printer(print_termios_c_lflag_flags, obj.c_lflag);
    abii_args->push_arg(printer3);

    auto printer4 = new ArgPrinter(obj.c_line, "c_line", &os);
    printer4->set_enum_printer(print_tty_line_discipline, obj.c_line);
    abii_args->push_arg(printer4);

    auto printer5 = new ArgPrinter(obj.c_cc, "c_cc", &os);
    printer5->set_enum_printer_with_depth(print_termios_c_cc_v, *obj.c_cc, 1);
    abii_args->push_arg(printer5);

    auto printer6 = new ArgPrinter(obj.__ispeed, "__ispeed", &os);
    printer6->set_enum_printer(print_baud_rate_enum_entry, obj.__ispeed);
    abii_args->push_arg(printer6);

    auto printer7 = new ArgPrinter(obj.c_ispeed, "c_ispeed", &os);
    printer7->set_enum_printer(print_baud_rate_enum_entry, obj.c_ispeed);
    abii_args->push_arg(printer7);

    auto printer8 = new ArgPrinter(obj.__ospeed, "__ospeed", &os);
    printer8->set_enum_printer(print_baud_rate_enum_entry, obj.__ospeed);
    abii_args->push_arg(printer8);

    auto printer9 = new ArgPrinter(obj.c_ospeed, "c_ospeed", &os, RECURSE);
    printer9->set_enum_printer(print_baud_rate_enum_entry, obj.c_ospeed);
    abii_args->push_arg(printer9);
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_TERMIOS_STRUCT_H
