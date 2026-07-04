//
// Created by Trent Tanchin on 7/4/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_UCONTEXT_H
#define ABII_C_LOGGING_PLUGIN_UCONTEXT_H

#include <ucontext.h>
#include <abii/libabii.h>

#include "hooks/asm/ucontext.h"
#include "hooks/bits/types/stack_t.h"
#include "hooks/bits/types/__sigset_t.h"

namespace abii
{
const defines_map ucontext_ngreg = {
#ifdef __x86_64__
    {23, "__NGREG"},
    {23, "NGREG"}
#else
    {19, "__NGREG"},
    {19, "NGREG"}
#endif
};

const defines_map ucontext_reg = {
#ifdef __x86_64__
    {0, "REG_R8"},
    {1, "REG_R9"},
    {2, "REG_R10"},
    {3, "REG_R11"},
    {4, "REG_R12"},
    {5, "REG_R13"},
    {6, "REG_R14"},
    {7, "REG_R15"},
    {8, "REG_RDI"},
    {9, "REG_RSI"},
    {10, "REG_RBP"},
    {11, "REG_RBX"},
    {12, "REG_RDX"},
    {13, "REG_RAX"},
    {14, "REG_RCX"},
    {15, "REG_RSP"},
    {16, "REG_RIP"},
    {17, "REG_EFL"},
    {18, "REG_CSGSFS"},
    {19, "REG_ERR"},
    {20, "REG_TRAPNO"},
    {21, "REG_OLDMASK"},
    {22, "REG_CR2"}
#else
    {0, "REG_GS"},
    {1, "REG_FS"},
    {2, "REG_ES"},
    {3, "REG_DS"},
    {4, "REG_EDI"},
    {5, "REG_ESI"},
    {6, "REG_EBP"},
    {7, "REG_ESP"},
    {8, "REG_EBX"},
    {9, "REG_EDX"},
    {10, "REG_ECX"},
    {11, "REG_EAX"},
    {12, "REG_TRAPNO"},
    {13, "REG_ERR"},
    {14, "REG_EIP"},
    {15, "REG_CS"},
    {16, "REG_EFL"},
    {17, "REG_UESP"},
    {18, "REG_SS"}
#endif
};

template <typename T>
std::string print_ucontext_ngreg(const T v)
{
    return print_enum_entry(v, ucontext_ngreg);
}

template <typename T>
std::string print_ucontext_reg(const T v)
{
    return print_enum_entry(v, ucontext_reg);
}
}

using namespace abii;

#ifdef __x86_64__
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _libc_fpxreg>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.significand, "significand", &os));
    abii_args->push_arg(new ArgPrinter(obj.exponent, "exponent", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved1, "__glibc_reserved1", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _libc_xmmreg>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.element, "element", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#else
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _libc_fpreg>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.significand, "significand", &os));
    abii_args->push_arg(new ArgPrinter(obj.exponent, "exponent", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _libc_fpstate>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#ifdef __x86_64__
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
#else
    abii_args->push_arg(new ArgPrinter(obj.cw, "cw", &os));
    abii_args->push_arg(new ArgPrinter(obj.sw, "sw", &os));
    abii_args->push_arg(new ArgPrinter(obj.tag, "tag", &os));
    abii_args->push_arg(new ArgPrinter(obj.ipoff, "ipoff", &os));
    abii_args->push_arg(new ArgPrinter(obj.cssel, "cssel", &os));
    abii_args->push_arg(new ArgPrinter(obj.dataoff, "dataoff", &os));
    abii_args->push_arg(new ArgPrinter(obj.datasel, "datasel", &os));
    abii_args->push_arg(new ArgPrinter(obj._st, "_st", &os));
    abii_args->push_arg(new ArgPrinter(obj.status, "status", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, mcontext_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.gregs, "gregs", &os));
    abii_args->push_arg(new ArgPrinter(obj.fpregs, "fpregs", &os));
#ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__reserved1, "__reserved1", &os, RECURSE));
#else
    abii_args->push_arg(new ArgPrinter(obj.oldmask, "oldmask", &os));
    abii_args->push_arg(new ArgPrinter(obj.cr2, "cr2", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ucontext_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.uc_flags, "uc_flags", &os);
    printer->set_enum_printer(print_ucontext_flags, obj.uc_flags);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.uc_link, "uc_link", &os));
    abii_args->push_arg(new ArgPrinter(obj.uc_stack, "uc_stack", &os));
    abii_args->push_arg(new ArgPrinter(obj.uc_mcontext, "uc_mcontext", &os));
    abii_args->push_arg(new ArgPrinter(obj.uc_sigmask, "uc_sigmask", &os));
    abii_args->push_arg(new ArgPrinter(obj.__fpregs_mem, "__fpregs_mem", &os));
    abii_args->push_arg(new ArgPrinter(obj.__ssp, "__ssp", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_UCONTEXT_H
