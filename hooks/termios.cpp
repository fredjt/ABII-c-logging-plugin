//
// Created by Trent Tanchin on 7/3/26.
//

#include "termios.h"

#include <abii/libabii.h>

#include "custom_enum_printers.h"
#include "bits/termios-struct.h"
#include "bits/termios-tcflow.h"

namespace abii
{
static speed_t (*real_cfgetospeed)(const termios*) __THROW = nullptr;

extern "C" speed_t abii_cfgetospeed(const termios* termios_p) __THROW
{
    OVERRIDE_PREFIX(cfgetospeed)
        pre_fmtd_str pi_str = "cfgetospeed(__termios_p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto abii_ret = real_cfgetospeed(termios_p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cfgetospeed, abii_ret)
    return real_cfgetospeed(termios_p);
}

static speed_t (*real_cfgetispeed)(const termios*) __THROW = nullptr;

extern "C" speed_t abii_cfgetispeed(const termios* termios_p) __THROW
{
    OVERRIDE_PREFIX(cfgetispeed)
        pre_fmtd_str pi_str = "cfgetispeed(__termios_p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto abii_ret = real_cfgetispeed(termios_p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cfgetispeed, abii_ret)
    return real_cfgetispeed(termios_p);
}

static int (*real_cfsetospeed)(termios*, speed_t) __THROW = nullptr;

extern "C" int abii_cfsetospeed(termios* termios_p, speed_t speed) __THROW
{
    OVERRIDE_PREFIX(cfsetospeed)
        pre_fmtd_str pi_str = "cfsetospeed(__termios_p, __speed)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto printer = new ArgPrinter(speed, "__speed");
        printer->set_enum_printer(print_baud_rate_enum_entry, speed);
        abii_args->push_arg(printer);

        auto abii_ret = real_cfsetospeed(termios_p, speed);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cfsetospeed, abii_ret)
    return real_cfsetospeed(termios_p, speed);
}

static int (*real_cfsetispeed)(termios*, speed_t) __THROW = nullptr;

extern "C" int abii_cfsetispeed(termios* termios_p, speed_t speed) __THROW
{
    OVERRIDE_PREFIX(cfsetispeed)
        pre_fmtd_str pi_str = "cfsetispeed(__termios_p, __speed)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto printer = new ArgPrinter(speed, "__speed");
        printer->set_enum_printer(print_baud_rate_enum_entry, speed);
        abii_args->push_arg(printer);

        auto abii_ret = real_cfsetispeed(termios_p, speed);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cfsetispeed, abii_ret)
    return real_cfsetispeed(termios_p, speed);
}

static int (*real_cfsetspeed)(termios*, speed_t) __THROW = nullptr;

extern "C" int abii_cfsetspeed(termios* termios_p, speed_t speed) __THROW
{
    OVERRIDE_PREFIX(cfsetspeed)
        pre_fmtd_str pi_str = "cfsetspeed(__termios_p, __speed)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto printer = new ArgPrinter(speed, "__speed");
        printer->set_enum_printer(print_baud_rate_enum_entry, speed);
        abii_args->push_arg(printer);

        auto abii_ret = real_cfsetspeed(termios_p, speed);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cfsetspeed, abii_ret)
    return real_cfsetspeed(termios_p, speed);
}

static baud_t (*real_cfgetobaud)(const termios*) __THROW = nullptr;

extern "C" baud_t abii_cfgetobaud(const termios* termios_p) __THROW
{
    OVERRIDE_PREFIX(cfgetobaud)
        pre_fmtd_str pi_str = "cfgetobaud(__termios_p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto abii_ret = real_cfgetobaud(termios_p);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_baud_rate_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(cfgetobaud, abii_ret)
    return real_cfgetobaud(termios_p);
}

static baud_t (*real_cfgetibaud)(const termios*) __THROW = nullptr;

extern "C" baud_t abii_cfgetibaud(const termios* termios_p) __THROW
{
    OVERRIDE_PREFIX(cfgetibaud)
        pre_fmtd_str pi_str = "cfgetibaud(__termios_p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto abii_ret = real_cfgetibaud(termios_p);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_baud_rate_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(cfgetibaud, abii_ret)
    return real_cfgetibaud(termios_p);
}

static int (*real_cfsetobaud)(termios*, baud_t) __THROW = nullptr;

extern "C" int abii_cfsetobaud(termios* termios_p, baud_t baud) __THROW
{
    OVERRIDE_PREFIX(cfsetobaud)
        pre_fmtd_str pi_str = "cfsetobaud(__termios_p, __baud)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto printer = new ArgPrinter(baud, "__baud");
        printer->set_enum_printer(print_baud_rate_enum_entry, baud);
        abii_args->push_arg(printer);

        auto abii_ret = real_cfsetobaud(termios_p, baud);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cfsetobaud, abii_ret)
    return real_cfsetobaud(termios_p, baud);
}

static int (*real_cfsetibaud)(termios*, baud_t) __THROW = nullptr;

extern "C" int abii_cfsetibaud(termios* termios_p, baud_t baud) __THROW
{
    OVERRIDE_PREFIX(cfsetibaud)
        pre_fmtd_str pi_str = "cfsetibaud(__termios_p, __baud)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto printer = new ArgPrinter(baud, "__baud");
        printer->set_enum_printer(print_baud_rate_enum_entry, baud);
        abii_args->push_arg(printer);

        auto abii_ret = real_cfsetibaud(termios_p, baud);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cfsetibaud, abii_ret)
    return real_cfsetibaud(termios_p, baud);
}

static int (*real_cfsetbaud)(termios*, baud_t) __THROW = nullptr;

extern "C" int abii_cfsetbaud(termios* termios_p, baud_t baud) __THROW
{
    OVERRIDE_PREFIX(cfsetbaud)
        pre_fmtd_str pi_str = "cfsetbaud(__termios_p, __baud)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto printer = new ArgPrinter(baud, "__baud");
        printer->set_enum_printer(print_baud_rate_enum_entry, baud);
        abii_args->push_arg(printer);

        auto abii_ret = real_cfsetbaud(termios_p, baud);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cfsetbaud, abii_ret)
    return real_cfsetbaud(termios_p, baud);
}

static int (*real_tcgetattr)(int, termios*) __THROW = nullptr;

extern "C" int abii_tcgetattr(int fd, termios* termios_p) __THROW
{
    OVERRIDE_PREFIX(tcgetattr)
        pre_fmtd_str pi_str = "tcgetattr(__fd, __termios_p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto abii_ret = real_tcgetattr(fd, termios_p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tcgetattr, abii_ret)
    return real_tcgetattr(fd, termios_p);
}

static int (*real_tcsetattr)(int, int, const termios*) __THROW = nullptr;

extern "C" int abii_tcsetattr(int fd, int optional_actions, const termios* termios_p) __THROW
{
    OVERRIDE_PREFIX(tcsetattr)
        pre_fmtd_str pi_str = "tcsetattr(__fd, __optional_actions, __termios_p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(optional_actions, "__optional_actions");
        printer->set_enum_printer(print_termios_tcflow_tcsa, optional_actions);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        auto abii_ret = real_tcsetattr(fd, optional_actions, termios_p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tcsetattr, abii_ret)
    return real_tcsetattr(fd, optional_actions, termios_p);
}

static void (*real_cfmakeraw)(termios*) __THROW = nullptr;

extern "C" void abii_cfmakeraw(termios* termios_p) __THROW
{
    OVERRIDE_PREFIX(cfmakeraw)
        pre_fmtd_str pi_str = "cfmakeraw(__termios_p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(termios_p, "__termios_p"));

        real_cfmakeraw(termios_p);
    OVERRIDE_SUFFIX(cfmakeraw,)
    return real_cfmakeraw(termios_p);
}

static int (*real_tcsendbreak)(int, int) __THROW = nullptr;

extern "C" int auto_tcsendbreak(int fd, int duration) __THROW
{
    OVERRIDE_PREFIX(tcsendbreak)
        pre_fmtd_str pi_str = "tcsendbreak(__fd, __duration)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(duration, "__duration"));

        auto abii_ret = real_tcsendbreak(fd, duration);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tcsendbreak, abii_ret)
    return real_tcsendbreak(fd, duration);
}

static int (*real_tcdrain)(int) = nullptr;

extern "C" int abii_tcdrain(int fd)
{
    OVERRIDE_PREFIX(tcdrain)
        pre_fmtd_str pi_str = "tcdrain(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto abii_ret = real_tcdrain(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tcdrain, abii_ret)
    return real_tcdrain(fd);
}

static int (*real_tcflush)(int, int) __THROW = nullptr;

extern "C" int abii_tcflush(int fd, int queue_selector) __THROW
{
    OVERRIDE_PREFIX(tcflush)
        pre_fmtd_str pi_str = "tcflush(__fd, __queue_selector)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(queue_selector, "__queue_selector");
        printer->set_enum_printer(print_termios_tcioflush, queue_selector);
        abii_args->push_arg(printer);

        auto abii_ret = real_tcflush(fd, queue_selector);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tcflush, abii_ret)
    return real_tcflush(fd, queue_selector);
}

static int (*real_tcflow)(int, int) __THROW = nullptr;

extern "C" int abii_tcflow(int fd, int action) __THROW
{
    OVERRIDE_PREFIX(tcflow)
        pre_fmtd_str pi_str = "tcflow(__fd, __action)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(action, "__action");
        printer->set_enum_printer(print_termios_tcio, action);
        abii_args->push_arg(printer);

        auto abii_ret = real_tcflow(fd, action);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tcflow, abii_ret)
    return real_tcflow(fd, action);
}

static __pid_t (*real_tcgetsid)(int) __THROW = nullptr;

extern "C" __pid_t abii_tcgetsid(int fd) __THROW
{
    OVERRIDE_PREFIX(tcgetsid)
        pre_fmtd_str pi_str = "tcgetsid(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto abii_ret = real_tcgetsid(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tcgetsid, abii_ret)
    return real_tcgetsid(fd);
}
}
