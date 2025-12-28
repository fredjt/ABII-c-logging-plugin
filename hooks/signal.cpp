//
// Created by Trent Tanchin on 5/23/25.
//

#include <abii/libabii.h>

#include "custom_enum_printers.h"
#include "bits/sigaction.h"
#include "bits/sigcontext.h"
#include "bits/types/siginfo_t.h"
#include "bits/types/stack_t.h"
#include "bits/types/struct_sigstack.h"
#include "bits/types/struct_timespec.h"
#include "bits/types/__sigset_t.h"

namespace abii
{
static __sighandler_t (*real___sysv_signal)(int, __sighandler_t) __THROW = nullptr;

extern "C" __sighandler_t abii___sysv_signal(int sig, __sighandler_t handler) __THROW
{
    OVERRIDE_PREFIX(__sysv_signal)
        pre_fmtd_str pi_str = "__sysv_signal(__sig, __handler)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(handler, "__handler"));

        auto abii_ret = real___sysv_signal(sig, handler);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__sysv_signal, abii_ret)
    return real___sysv_signal(sig, handler);
}

static __sighandler_t (*real_sysv_signal)(int, __sighandler_t) __THROW = nullptr;

extern "C" __sighandler_t abii_sysv_signal(int sig, __sighandler_t handler) __THROW
{
    OVERRIDE_PREFIX(sysv_signal)
        pre_fmtd_str pi_str = "sysv_signal(__sig, __handler)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(handler, "__handler"));

        auto abii_ret = real_sysv_signal(sig, handler);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sysv_signal, abii_ret)
    return real_sysv_signal(sig, handler);
}

static __sighandler_t (*real_signal)(int, __sighandler_t) __THROW = nullptr;

extern "C" __sighandler_t abii_signal(int sig, __sighandler_t handler) __THROW
{
    OVERRIDE_PREFIX(signal)
        pre_fmtd_str pi_str = "signal(__sig, __handler)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(handler, "__handler"));

        auto abii_ret = real_signal(sig, handler);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(signal, abii_ret)
    return real_signal(sig, handler);
}

static __sighandler_t (*real_bsd_signal)(int, __sighandler_t) __THROW = nullptr;

__sighandler_t bsd_signal(int sig, __sighandler_t handler) __THROW
{
    OVERRIDE_PREFIX(bsd_signal)
        pre_fmtd_str pi_str = "bsd_signal(__sig, __handler)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(handler, "__handler"));

        auto abii_ret = real_bsd_signal(sig, handler);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(bsd_signal, abii_ret)
    return real_bsd_signal(sig, handler);
}

static int (*real_kill)(__pid_t, int) __THROW = nullptr;

extern "C" int abii_kill(__pid_t pid, int sig) __THROW
{
    OVERRIDE_PREFIX(kill)
        pre_fmtd_str pi_str = "kill(__pid, __sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_kill(pid, sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(kill, abii_ret)
    return real_kill(pid, sig);
}

static int (*real_killpg)(__pid_t, int) __THROW = nullptr;

extern "C" int abii_killpg(__pid_t pgrp, int sig) __THROW
{
    OVERRIDE_PREFIX(killpg)
        pre_fmtd_str pi_str = "killpg(__pgrp, __sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pgrp, "__pgrp"));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_killpg(pgrp, sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(killpg, abii_ret)
    return real_killpg(pgrp, sig);
}

static int (*real_raise)(int) __THROW = nullptr;

extern "C" int abii_raise(int sig) __THROW
{
    OVERRIDE_PREFIX(raise)
        pre_fmtd_str pi_str = "raise(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_raise(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(raise, abii_ret)
    return real_raise(sig);
}

static __sighandler_t (*real_ssignal)(int, __sighandler_t) __THROW = nullptr;

extern "C" __sighandler_t abii_ssignal(int sig, __sighandler_t handler) __THROW
{
    OVERRIDE_PREFIX(ssignal)
        pre_fmtd_str pi_str = "ssignal(__sig, __handler)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(handler, "__handler"));

        auto abii_ret = real_ssignal(sig, handler);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ssignal, abii_ret)
    return real_ssignal(sig, handler);
}

static int (*real_gsignal)(int) __THROW = nullptr;

extern "C" int abii_gsignal(int sig) __THROW
{
    OVERRIDE_PREFIX(gsignal)
        pre_fmtd_str pi_str = "gsignal(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_gsignal(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gsignal, abii_ret)
    return real_gsignal(sig);
}

static void (*real_psignal)(int, const char*) = nullptr;

extern "C" void abii_psignal(int sig, const char* s)
{
    OVERRIDE_PREFIX(psignal)
        pre_fmtd_str pi_str = "psignal(__sig, __s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        real_psignal(sig, s);
    OVERRIDE_SUFFIX(psignal,)
    return real_psignal(sig, s);
}

static void (*real_psiginfo)(const siginfo_t*, const char*) = nullptr;

extern "C" void abii_psiginfo(const siginfo_t* pinfo, const char* s)
{
    OVERRIDE_PREFIX(psiginfo)
        pre_fmtd_str pi_str = "psiginfo(__pinfo, __s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pinfo, "__pinfo"));
        abii_args->push_arg(new ArgPrinter(s, "__s"));

        real_psiginfo(pinfo, s);
    OVERRIDE_SUFFIX(psiginfo,)
    return real_psiginfo(pinfo, s);
}

static int (*real___xpg_sigpause)(int) = nullptr;

extern "C" __attribute_deprecated_msg__("Use the sigsuspend function instead")
int abii___xpg_sigpause(int sig)
{
    OVERRIDE_PREFIX(__xpg_sigpause)
        pre_fmtd_str pi_str = "__xpg_sigpause(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real___xpg_sigpause(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__xpg_sigpause, abii_ret)
    return real___xpg_sigpause(sig);
}

static int (*real_sigpause)(int) = nullptr;

extern "C" __attribute_deprecated_msg__("Use the sigsuspend function instead")
int abii_sigpause(int sig)
{
    OVERRIDE_PREFIX(sigpause)
        pre_fmtd_str pi_str = "sigpause(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_sigpause(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigpause, abii_ret)
    return real_sigpause(sig);
}

static int (*real___sigpause)(int __sig_or_mask, int __is_sig) = nullptr;

extern "C" __attribute_deprecated_msg__("Use the sigsuspend function instead")
int abii___sigpause(int sig_or_mask, int is_sig)
{
    OVERRIDE_PREFIX(__sigpause)
        pre_fmtd_str pi_str = "sigpause(__sig_or_mask, __is_sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig_or_mask, "__sig_or_mask");
        printer->set_enum_printer(print_signum_enum_entry, sig_or_mask);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(is_sig, "__is_sig"));

        auto abii_ret = real___sigpause(sig_or_mask, is_sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__sigpause, abii_ret)
    return real___sigpause(sig_or_mask, is_sig);
}

static int (*real_sigblock)(int) __THROW = nullptr;

extern "C" __attribute_deprecated__
int abii_sigblock(int mask) __THROW
{
    OVERRIDE_PREFIX(sigblock)
        pre_fmtd_str pi_str = "sigblock(__mask)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mask, "__mask"));

        auto abii_ret = real_sigblock(mask);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigblock, abii_ret)
    return real_sigblock(mask);
}

static int (*real_sigsetmask)(int) __THROW = nullptr;

extern "C" __attribute_deprecated__
int abii_sigsetmask(int mask) __THROW
{
    OVERRIDE_PREFIX(sigsetmask)
        pre_fmtd_str pi_str = "sigsetmask(__mask)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mask, "__mask"));

        auto abii_ret = real_sigsetmask(mask);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigsetmask, abii_ret)
    return real_sigsetmask(mask);
}

static int (*real_siggetmask)() __THROW = nullptr;

extern "C" __attribute_deprecated__
int abii_siggetmask() __THROW
{
    OVERRIDE_PREFIX(siggetmask)
        pre_fmtd_str pi_str = "siggetmask()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_siggetmask();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(siggetmask, abii_ret)
    return real_siggetmask();
}

static int (*real_sigemptyset)(sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sigemptyset(sigset_t* set) __THROW
{
    OVERRIDE_PREFIX(sigemptyset)
        pre_fmtd_str pi_str = "sigemptyset(__set)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        auto abii_ret = real_sigemptyset(set);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigemptyset, abii_ret)
    return real_sigemptyset(set);
}

static int (*real_sigfillset)(sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sigfillset(sigset_t* set) __THROW
{
    OVERRIDE_PREFIX(sigfillset)
        pre_fmtd_str pi_str = "sigfillset(__set)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        auto abii_ret = real_sigfillset(set);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigfillset, abii_ret)
    return real_sigfillset(set);
}

static int (*real_sigaddset)(sigset_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sigaddset(sigset_t* set, int signo) __THROW
{
    OVERRIDE_PREFIX(sigaddset)
        pre_fmtd_str pi_str = "sigaddset(__set, __signo)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        auto printer = new ArgPrinter(signo, "__signo");
        printer->set_enum_printer(print_signum_enum_entry, signo);
        abii_args->push_arg(printer);

        auto abii_ret = real_sigaddset(set, signo);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigaddset, abii_ret)
    return real_sigaddset(set, signo);
}

static int (*real_sigdelset)(sigset_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sigdelset(sigset_t* set, int signo) __THROW
{
    OVERRIDE_PREFIX(sigdelset)
        pre_fmtd_str pi_str = "sigdelset(__set, __signo)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        auto printer = new ArgPrinter(signo, "__signo");
        printer->set_enum_printer(print_signum_enum_entry, signo);
        abii_args->push_arg(printer);

        auto abii_ret = real_sigdelset(set, signo);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigdelset, abii_ret)
    return real_sigdelset(set, signo);
}

static int (*real_sigismember)(const sigset_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sigismember(const sigset_t* set, int signo) __THROW
{
    OVERRIDE_PREFIX(sigismember)
        pre_fmtd_str pi_str = "sigismember(__set, __signo)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        auto printer = new ArgPrinter(signo, "__signo");
        printer->set_enum_printer(print_signum_enum_entry, signo);
        abii_args->push_arg(printer);

        auto abii_ret = real_sigismember(set, signo);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigismember, abii_ret)
    return real_sigismember(set, signo);
}

static int (*real_sigisemptyset)(const sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sigisemptyset(const sigset_t* set) __THROW
{
    OVERRIDE_PREFIX(sigisemptyset)
        pre_fmtd_str pi_str = "sigisemptyset(__set)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        auto abii_ret = real_sigisemptyset(set);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigisemptyset, abii_ret)
    return real_sigisemptyset(set);
}

static int (*real_sigandset)(sigset_t*, const sigset_t*, const sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2, 3))
int abii_sigandset(sigset_t* set, const sigset_t* left, const sigset_t* right) __THROW
{
    OVERRIDE_PREFIX(sigandset)
        pre_fmtd_str pi_str = "sigandset(__set, __left, __right)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));
        abii_args->push_arg(new ArgPrinter(left, "__left"));
        abii_args->push_arg(new ArgPrinter(right, "__right"));

        auto abii_ret = real_sigandset(set, left, right);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigandset, abii_ret)
    return real_sigandset(set, left, right);
}

static int (*real_sigorset)(sigset_t*, const sigset_t*, const sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2, 3))
int abii_sigorset(sigset_t* set, const sigset_t* left, const sigset_t* right) __THROW
{
    OVERRIDE_PREFIX(sigorset)
        pre_fmtd_str pi_str = "sigorset(__set, __left, __right)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));
        abii_args->push_arg(new ArgPrinter(left, "__left"));
        abii_args->push_arg(new ArgPrinter(right, "__right"));

        auto abii_ret = real_sigorset(set, left, right);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigorset, abii_ret)
    return real_sigorset(set, left, right);
}

static int (*real_sigprocmask)(int, const sigset_t*, sigset_t*) __THROW = nullptr;

extern "C" int abii_sigprocmask(int how, const sigset_t* set, sigset_t* oset) __THROW
{
    OVERRIDE_PREFIX(sigprocmask)
        pre_fmtd_str pi_str = "sigprocmask(__how, __set, __oset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(how, "__how");
        printer->set_enum_printer(print_sigaction_how, how);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(set, "__set"));
        abii_args->push_arg(new ArgPrinter(oset, "__oset"));

        auto abii_ret = real_sigprocmask(how, set, oset);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigprocmask, abii_ret)
    return real_sigprocmask(how, set, oset);
}

static int (*real_sigsuspend)(const sigset_t*) = nullptr;

extern "C" __nonnull((1))
int abii_sigsuspend(const sigset_t* set)
{
    OVERRIDE_PREFIX(sigsuspend)
        pre_fmtd_str pi_str = "sigsuspend(__set)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        auto abii_ret = real_sigsuspend(set);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigsuspend, abii_ret)
    return real_sigsuspend(set);
}

static int (*real_sigaction)(int, const struct sigaction*, struct sigaction*) __THROW = nullptr;

extern "C" int abii_sigaction(int sig, const struct sigaction* act, struct sigaction* oact) __THROW
{
    OVERRIDE_PREFIX(sigaction)
        pre_fmtd_str pi_str = "sigaction(__sig, __act, __oact)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(act, "__act"));
        abii_args->push_arg(new ArgPrinter(oact, "__oact"));

        auto abii_ret = real_sigaction(sig, act, oact);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigaction, abii_ret)
    return real_sigaction(sig, act, oact);
}

static int (*real_sigpending)(sigset_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sigpending(sigset_t* set) __THROW
{
    OVERRIDE_PREFIX(sigpending)
        pre_fmtd_str pi_str = "sigpending(__set)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        auto abii_ret = real_sigpending(set);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigpending, abii_ret)
    return real_sigpending(set);
}

static int (*real_sigwait)(const sigset_t*, int*) = nullptr;

extern "C" __nonnull((1, 2))
int abii_sigwait(const sigset_t* set, int* sig)
{
    OVERRIDE_PREFIX(sigwait)
        pre_fmtd_str pi_str = "sigwait(__set, __sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer_with_depth(print_signum_enum_entry, *sig, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_sigwait(set, sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigwait, abii_ret)
    return real_sigwait(set, sig);
}

static int (*real_sigwaitinfo)(const sigset_t*, siginfo_t*) = nullptr;

extern "C" __nonnull((1))
int abii_sigwaitinfo(const sigset_t* set, siginfo_t* info)
{
    OVERRIDE_PREFIX(sigwaitinfo)
        pre_fmtd_str pi_str = "sigwaitinfo(__set, __info)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));
        abii_args->push_arg(new ArgPrinter(info, "__info"));

        auto abii_ret = real_sigwaitinfo(set, info);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigwaitinfo, abii_ret)
    return real_sigwaitinfo(set, info);
}

static int (*real_sigtimedwait)(const sigset_t*, siginfo_t*, const timespec*) = nullptr;

extern "C" __nonnull((1))
int abii_sigtimedwait(const sigset_t* set, siginfo_t* info, const timespec* timeout)
{
    OVERRIDE_PREFIX(sigtimedwait)
        pre_fmtd_str pi_str = "sigtimedwait(__set, __info, __timeout)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(set, "__set"));
        abii_args->push_arg(new ArgPrinter(info, "__info"));
        abii_args->push_arg(new ArgPrinter(timeout, "__timeout"));

        auto abii_ret = real_sigtimedwait(set, info, timeout);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigtimedwait, abii_ret)
    return real_sigtimedwait(set, info, timeout);
}

static int (*real_sigqueue)(__pid_t, int, sigval) __THROW = nullptr;

extern "C" int abii_sigqueue(__pid_t pid, int sig, const sigval val) __THROW
{
    OVERRIDE_PREFIX(sigqueue)
        pre_fmtd_str pi_str = "sigqueue(__pid, __sig, __val)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));
        abii_args->push_arg(new ArgPrinter(sig, "__sig"));
        abii_args->push_arg(new ArgPrinter(val, "__val"));

        auto abii_ret = real_sigqueue(pid, sig, val);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigqueue, abii_ret)
    return real_sigqueue(pid, sig, val);
}

static int (*real_sigreturn)(sigcontext*) __THROW = nullptr;

extern "C" int abii_sigreturn(sigcontext* scp) __THROW
{
    OVERRIDE_PREFIX(sigreturn)
        pre_fmtd_str pi_str = "sigreturn(__scp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(scp, "__scp"));

        auto abii_ret = real_sigreturn(scp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigreturn, abii_ret)
    return real_sigreturn(scp);
}

static int (*real_siginterrupt)(int, int) __THROW = nullptr;

extern "C" __attribute_deprecated_msg__("Use sigaction with SA_RESTART instead")
int abii_siginterrupt(int sig, int interrupt) __THROW
{
    OVERRIDE_PREFIX(siginterrupt)
        pre_fmtd_str pi_str = "siginterrupt(__sig, __interrupt)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(interrupt, "__interrupt"));

        auto abii_ret = real_siginterrupt(sig, interrupt);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(siginterrupt, abii_ret)
    return real_siginterrupt(sig, interrupt);
}

static int (*real_sigaltstack)(const stack_t*, stack_t*) __THROW = nullptr;

extern "C" int abii_sigaltstack(const stack_t* ss, stack_t* oss) __THROW
{
    OVERRIDE_PREFIX(sigaltstack)
        pre_fmtd_str pi_str = "sigaltstack(__ss, __oss)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ss, "__ss"));
        abii_args->push_arg(new ArgPrinter(oss, "__oss"));

        auto abii_ret = real_sigaltstack(ss, oss);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigaltstack, abii_ret)
    return real_sigaltstack(ss, oss);
}

static int (*real_sigstack)(struct sigstack*, struct sigstack*) __THROW = nullptr;

extern "C" __attribute_deprecated__
int abii_sigstack(struct sigstack* ss, struct sigstack* oss) __THROW
{
    OVERRIDE_PREFIX(sigstack)
        pre_fmtd_str pi_str = "sigstack(__ss, __oss)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ss, "__ss"));
        abii_args->push_arg(new ArgPrinter(oss, "__oss"));

        auto abii_ret = real_sigstack(ss, oss);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigstack, abii_ret)
    return real_sigstack(ss, oss);
}

static int (*real_sighold)(int) __THROW = nullptr;

extern "C" __attribute_deprecated_msg__("Use the sigprocmask function instead")
int abii_sighold(int sig) __THROW
{
    OVERRIDE_PREFIX(sighold)
        pre_fmtd_str pi_str = "sighold(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_sighold(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sighold, abii_ret)
    return real_sighold(sig);
}

static int (*real_sigrelse)(int) __THROW = nullptr;

extern "C" __attribute_deprecated_msg__("Use the sigprocmask function instead")
int abii_sigrelse(int sig) __THROW
{
    OVERRIDE_PREFIX(sigrelse)
        pre_fmtd_str pi_str = "sigrelse(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_sigrelse(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigrelse, abii_ret)
    return real_sigrelse(sig);
}

static int (*real_sigignore)(int) __THROW = nullptr;

extern "C" __attribute_deprecated_msg__("Use the signal function instead")
int abii_sigignore(int sig) __THROW
{
    OVERRIDE_PREFIX(sigignore)
        pre_fmtd_str pi_str = "sigignore(__sig)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        auto abii_ret = real_sigignore(sig);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigignore, abii_ret)
    return real_sigignore(sig);
}

static __sighandler_t (*real_sigset)(int, __sighandler_t) __THROW = nullptr;

extern "C" __attribute_deprecated_msg__("Use the signal and sigprocmask functions instead")
__sighandler_t abii_sigset(int sig, __sighandler_t disp) __THROW
{
    OVERRIDE_PREFIX(sigset)
        pre_fmtd_str pi_str = "sigset(__sig, __disp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(sig, "__sig");
        printer->set_enum_printer(print_signum_enum_entry, sig);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(disp, "__disp"));

        auto abii_ret = real_sigset(sig, disp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sigset, abii_ret)
    return real_sigset(sig, disp);
}

static int (*real___libc_current_sigrtmin)() __THROW = nullptr;

extern "C" int abii___libc_current_sigrtmin() __THROW
{
    OVERRIDE_PREFIX(__libc_current_sigrtmin)
        pre_fmtd_str pi_str = "__libc_current_sigrtmin()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real___libc_current_sigrtmin();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__libc_current_sigrtmin, abii_ret)
    return real___libc_current_sigrtmin();
}

static int (*real___libc_current_sigrtmax)() __THROW = nullptr;

extern "C" int abii___libc_current_sigrtmax() __THROW
{
    OVERRIDE_PREFIX(__libc_current_sigrtmax)
        pre_fmtd_str pi_str = "__libc_current_sigrtmax()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real___libc_current_sigrtmax();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__libc_current_sigrtmax, abii_ret)
    return real___libc_current_sigrtmax();
}
}
