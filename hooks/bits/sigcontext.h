//
// Created by Trent Tanchin on 5/25/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGCONTEXT_H
#define ABII_C_LOGGING_PLUGIN_SIGCONTEXT_H

#include <abii/libabii.h>
#include <bits/sigcontext.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _fpx_sw_bytes>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.magic1, "magic1", &os));
    abii_args->push_arg(new ArgPrinter(obj.extended_size, "extended_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.xstate_bv, "xstate_bv", &os));
    abii_args->push_arg(new ArgPrinter(obj.xstate_size, "xstate_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved1, "__glibc_reserved1", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _fpreg>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.significand, "significand", &os));
    abii_args->push_arg(new ArgPrinter(obj.exponent, "exponent", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _fpxreg>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.significand, "significand", &os));
    abii_args->push_arg(new ArgPrinter(obj.exponent, "exponent", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved1, "__glibc_reserved1", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _xmmreg>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.element, "element", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#ifndef __x86_64__
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _fpstate>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.cw, "cw", &os));
    abii_args->push_arg(new ArgPrinter(obj.sw, "sw", &os));
    abii_args->push_arg(new ArgPrinter(obj.tag, "tag", &os));
    abii_args->push_arg(new ArgPrinter(obj.ipoff, "ipoff", &os));
    abii_args->push_arg(new ArgPrinter(obj.cssel, "cssel", &os));
    abii_args->push_arg(new ArgPrinter(obj.dataoff, "dataoff", &os));
    abii_args->push_arg(new ArgPrinter(obj.datasel, "datasel", &os));
    abii_args->push_arg(new ArgPrinter(obj._st, "_st", &os));
    abii_args->push_arg(new ArgPrinter(obj.status, "status", &os));
    abii_args->push_arg(new ArgPrinter(obj.magic, "magic", &os));
    abii_args->push_arg(new ArgPrinter(obj._fxsr_env, "_fxsr_env", &os));
    abii_args->push_arg(new ArgPrinter(obj.mxcsr, "mxcsr", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved1, "__glibc_reserved1", &os));
    abii_args->push_arg(new ArgPrinter(obj._fxsr_st, "_fxsr_st", &os));
    abii_args->push_arg(new ArgPrinter(obj._xmm, "_xmm", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved2, "__glibc_reserved2", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sigcontext>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.gs, "gs", &os));
    abii_args->push_arg(new ArgPrinter(obj.__gsh, "__gsh", &os));
    abii_args->push_arg(new ArgPrinter(obj.fs, "__fsh", &os));
    abii_args->push_arg(new ArgPrinter(obj.__fsh, "__fsh", &os));
    abii_args->push_arg(new ArgPrinter(obj.es, "es", &os));
    abii_args->push_arg(new ArgPrinter(obj.__esh, "__esh", &os));
    abii_args->push_arg(new ArgPrinter(obj.ds, "ds", &os));
    abii_args->push_arg(new ArgPrinter(obj.__dsh, "__dsh", &os));
    abii_args->push_arg(new ArgPrinter(obj.edi, "edi", &os));
    abii_args->push_arg(new ArgPrinter(obj.esi, "esi", &os));
    abii_args->push_arg(new ArgPrinter(obj.ebp, "ebp", &os));
    abii_args->push_arg(new ArgPrinter(obj.esp, "esp", &os));
    abii_args->push_arg(new ArgPrinter(obj.ebx, "ebx", &os));
    abii_args->push_arg(new ArgPrinter(obj.edx, "edx", &os));
    abii_args->push_arg(new ArgPrinter(obj.ecx, "ecx", &os));
    abii_args->push_arg(new ArgPrinter(obj.eax, "eax", &os));
    abii_args->push_arg(new ArgPrinter(obj.trapno, "trapno", &os));
    abii_args->push_arg(new ArgPrinter(obj.err, "err", &os));
    abii_args->push_arg(new ArgPrinter(obj.eip, "eip", &os));
    abii_args->push_arg(new ArgPrinter(obj.cs, "cs", &os));
    abii_args->push_arg(new ArgPrinter(obj.__csh, "__csh", &os));
    abii_args->push_arg(new ArgPrinter(obj.eflags, "eflags", &os));
    abii_args->push_arg(new ArgPrinter(obj.esp_at_signal, "esp_at_signal", &os));
    abii_args->push_arg(new ArgPrinter(obj.ss, "ss", &os));
    abii_args->push_arg(new ArgPrinter(obj.__ssh, "__ssh", &os));
    abii_args->push_arg(new ArgPrinter(obj.fpstate, "fpstate", &os));
    abii_args->push_arg(new ArgPrinter(obj.oldmask, "oldmask", &os));
    abii_args->push_arg(new ArgPrinter(obj.cr2, "cr2", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#else
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _fpstate>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.cwd, "cwd", &os));
    abii_args->push_arg(new ArgPrinter(obj.swd, "swd", &os));
    abii_args->push_arg(new ArgPrinter(obj.ftw, "ftw", &os));
    abii_args->push_arg(new ArgPrinter(obj.fop, "fop", &os));
    abii_args->push_arg(new ArgPrinter(obj.rip, "rip", &os));
    abii_args->push_arg(new ArgPrinter(obj.rdp, "rdp", &os));
    abii_args->push_arg(new ArgPrinter(obj.mxcsr, "mxcsr", &os));
    abii_args->push_arg(new ArgPrinter(obj.mxcr_mask, "mxcr_mask", &os));
    abii_args->push_arg(new ArgPrinter(obj._st, "_st", &os));
    abii_args->push_arg(new ArgPrinter(obj._xmm, "_xmm", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved1, "__glibc_reserved1", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sigcontext>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.r8, "r8", &os));
    abii_args->push_arg(new ArgPrinter(obj.r9, "r9", &os));
    abii_args->push_arg(new ArgPrinter(obj.r10, "r10", &os));
    abii_args->push_arg(new ArgPrinter(obj.r11, "r11", &os));
    abii_args->push_arg(new ArgPrinter(obj.r12, "r12", &os));
    abii_args->push_arg(new ArgPrinter(obj.r13, "r13", &os));
    abii_args->push_arg(new ArgPrinter(obj.r14, "r14", &os));
    abii_args->push_arg(new ArgPrinter(obj.r15, "r15", &os));
    abii_args->push_arg(new ArgPrinter(obj.rdi, "rdi", &os));
    abii_args->push_arg(new ArgPrinter(obj.rsi, "rsi", &os));
    abii_args->push_arg(new ArgPrinter(obj.rbp, "rbp", &os));
    abii_args->push_arg(new ArgPrinter(obj.rbx, "rbx", &os));
    abii_args->push_arg(new ArgPrinter(obj.rdx, "rdx", &os));
    abii_args->push_arg(new ArgPrinter(obj.rax, "rax", &os));
    abii_args->push_arg(new ArgPrinter(obj.rcx, "rcx", &os));
    abii_args->push_arg(new ArgPrinter(obj.rsp, "rsp", &os));
    abii_args->push_arg(new ArgPrinter(obj.rip, "rip", &os));
    abii_args->push_arg(new ArgPrinter(obj.eflags, "eflags", &os));
    abii_args->push_arg(new ArgPrinter(obj.cs, "cs", &os));
    abii_args->push_arg(new ArgPrinter(obj.gs, "gs", &os));
    abii_args->push_arg(new ArgPrinter(obj.fs, "fs", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad0, "__pad0", &os));
    abii_args->push_arg(new ArgPrinter(obj.err, "err", &os));
    abii_args->push_arg(new ArgPrinter(obj.trapno, "trapno", &os));
    abii_args->push_arg(new ArgPrinter(obj.oldmask, "oldmask", &os));
    abii_args->push_arg(new ArgPrinter(obj.cr2, "cr2", &os));
    abii_args->push_arg(new ArgPrinter(obj.fpstate, "fpstate", &os));
    abii_args->push_arg(new ArgPrinter(obj.__fpstate_word, "__fpstate_word", &os));
    abii_args->push_arg(new ArgPrinter(obj.__reserved1, "__reserved1", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_SIGCONTEXT_H
