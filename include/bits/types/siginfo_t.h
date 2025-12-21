//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGINFO_T_H
#define ABII_C_LOGGING_PLUGIN_SIGINFO_T_H

#include <csignal>
#include <abii/libabii.h>
#include <bits/types/siginfo_t.h>

#include "custom_enum_printers.h"
#include "__sigval_t.h"
#include "include/bits/siginfo-consts.h"
#include "include/linux/audit.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, siginfo_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.si_signo, "si_signo", &os);
    printer->set_enum_printer(print_signum_enum_entry, obj.si_signo);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.si_errno, "si_errno", &os);
    printer1->set_enum_printer(print_error_enum_entry, obj.si_errno);

    auto printer2 = new ArgPrinter(obj.si_code, "si_code", &os);
    switch (obj.si_signo)
    {
    case SIGILL:
        printer2->set_enum_printer(print_siginfo_consts_enum_si_ill, obj.si_code);
        break;
    case SIGFPE:
        printer2->set_enum_printer(print_siginfo_consts_enum_si_fpe, obj.si_code);
        break;
    case SIGSEGV:
        printer2->set_enum_printer(print_siginfo_consts_enum_si_segv, obj.si_code);
        break;
    case SIGBUS:
        printer2->set_enum_printer(print_siginfo_consts_enum_si_bus, obj.si_code);
        break;
    case SIGTRAP:
        printer2->set_enum_printer(print_siginfo_consts_enum_si_trap, obj.si_code);
        break;
    case SIGCHLD:
        printer2->set_enum_printer(print_siginfo_consts_enum_si_cld, obj.si_code);
        break;
    case SIGPOLL:
        printer2->set_enum_printer(print_siginfo_consts_enum_si_poll, obj.si_code);
        break;
    default:
        printer2->set_enum_printer(print_siginfo_consts_code, obj.si_code);
    }
#if __SI_ERRNO_THEN_CODE
    abii_args->push_arg(printer1);
    abii_args->push_arg(printer2);
#else
    abii_args->push_arg(printer2);
    abii_args->push_arg(printer1);
#endif
#if __WORDSIZE == 64
    abii_args->push_arg(new ArgPrinter(obj.__pad0, "__pad0", &os));
#endif
    abii_args->push_arg(new ArgPrinter(obj._sifields, "_sifields", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj._pad, "_pad", &os));
    abii_args->push_arg(new ArgPrinter(obj._kill, "_kill", &os));
    abii_args->push_arg(new ArgPrinter(obj._timer, "_timer", &os));
    abii_args->push_arg(new ArgPrinter(obj._rt, "_rt", &os));
    abii_args->push_arg(new ArgPrinter(obj._sigchld, "_sigchld", &os));
    abii_args->push_arg(new ArgPrinter(obj._sigfault, "_sigfault", &os));
    abii_args->push_arg(new ArgPrinter(obj._sigpoll, "_sigpoll", &os));
#if __SI_HAVE_SIGSYS
    abii_args->push_arg(new ArgPrinter(obj._sigsys, "_sigsys", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

#undef si_pid
#undef si_uid
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields._kill)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.si_pid, "si_pid", &os));
    abii_args->push_arg(new ArgPrinter(obj.si_uid, "si_uid", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#undef si_overrun
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields._timer)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.si_tid, "si_tid", &os));
    abii_args->push_arg(new ArgPrinter(obj.si_overrun, "si_overrun", &os));
    abii_args->push_arg(new ArgPrinter(obj.si_sigval, "si_sigval", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields._rt)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.si_pid, "si_pid", &os));
    abii_args->push_arg(new ArgPrinter(obj.si_uid, "si_uid", &os));
    abii_args->push_arg(new ArgPrinter(obj.si_sigval, "si_sigval", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#undef si_status
#undef si_utime
#undef si_stime
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields._sigchld)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.si_pid, "si_pid", &os));
    abii_args->push_arg(new ArgPrinter(obj.si_uid, "si_uid", &os));

    auto printer = new ArgPrinter(obj.si_status, "si_status", &os);
    printer->set_enum_printer(print_signum_enum_entry, obj.si_status);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.si_utime, "si_utime", &os));
    abii_args->push_arg(new ArgPrinter(obj.si_stime, "si_stime", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#undef si_addr
#undef si_addr_lsb
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields._sigfault)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.si_addr, "si_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.si_addr_lsb, "si_addr_lsb", &os));
    abii_args->push_arg(new ArgPrinter(obj._bounds, "_bounds", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields._sigfault._bounds)>
inline std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj._addr_bnd, "_addr_bnd", &os));
    abii_args->push_arg(new ArgPrinter(obj._pkey, "_pkey", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields._sigfault._bounds.
                                                  _addr_bnd)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj._lower, "_lower", &os));
    abii_args->push_arg(new ArgPrinter(obj._upper, "_upper", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#undef si_band
#undef si_fd
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields._sigpoll)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.si_band, "si_band", &os));
    abii_args->push_arg(new ArgPrinter(obj.si_fd, "si_fd", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#if __SI_HAVE_SIGSYS
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(siginfo_t::_sifields._sigsys)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj._call_addr, "_call_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj._syscall, "_syscall", &os));

    auto printer = new ArgPrinter(obj._arch, "_arch", &os, RECURSE);
    printer->set_enum_printer(print_audit_arch, obj._arch);
    abii_args->push_arg(printer);
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_SIGINFO_T_H
