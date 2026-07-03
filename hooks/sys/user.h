//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_USER_H
#define ABII_C_LOGGING_PLUGIN_USER_H

#include <abii/libabii.h>
#include <sys/user.h>

namespace abii
{
const defines_map user_page_shift = {
    {12, "PAGE_SHIFT"}
};

const defines_map user_page_size = {
    {(1UL << 12), "PAGE_SIZE"}
};

const defines_map user_page_mask = {
    {(~((1UL << 12) - 1)), "PAGE_MASK"}
};

const defines_map user_nbpg = {
    {(1UL << 12), "NBPG"}
};

const defines_map user_upages = {
    {1, "UPAGES"}
};

template <typename T>
std::string print_user_page_shift(const T v)
{
    return print_enum_entry(v, user_page_shift);
}

template <typename T>
std::string print_user_page_size(const T v)
{
    return print_enum_entry(v, user_page_size);
}

template <typename T>
std::string print_user_page_mask(const T v)
{
    return print_enum_entry(v, user_page_mask);
}

template <typename T>
std::string print_user_nbpg(const T v)
{
    return print_enum_entry(v, user_nbpg);
}

template <typename T>
std::string print_user_upages(const T v)
{
    return print_enum_entry(v, user_upages);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, user_fpregs_struct>
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
    abii_args->push_arg(new ArgPrinter(obj.st_space, "st_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.xmm_space, "xmm_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.padding, "padding", &os, RECURSE));
#else
    abii_args->push_arg(new ArgPrinter(obj.cwd, "cwd", &os));
    abii_args->push_arg(new ArgPrinter(obj.swd, "swd", &os));
    abii_args->push_arg(new ArgPrinter(obj.twd, "ftw", &os));
    abii_args->push_arg(new ArgPrinter(obj.fip, "fop", &os));
    abii_args->push_arg(new ArgPrinter(obj.fcs, "rip", &os));
    abii_args->push_arg(new ArgPrinter(obj.foo, "rdp", &os));
    abii_args->push_arg(new ArgPrinter(obj.fos, "mxcsr", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_space, "mxcr_mask", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

#ifndef __x86_64__
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, user_fpxregs_struct>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.cwd, "cwd", &os));
    abii_args->push_arg(new ArgPrinter(obj.swd, "swd", &os));
    abii_args->push_arg(new ArgPrinter(obj.twd, "twd", &os));
    abii_args->push_arg(new ArgPrinter(obj.fop, "fop", &os));
    abii_args->push_arg(new ArgPrinter(obj.fip, "fip", &os));
    abii_args->push_arg(new ArgPrinter(obj.fcs, "fcs", &os));
    abii_args->push_arg(new ArgPrinter(obj.foo, "foo", &os));
    abii_args->push_arg(new ArgPrinter(obj.fos, "fos", &os));
    abii_args->push_arg(new ArgPrinter(obj.mxcsr, "mxcsr", &os));
    abii_args->push_arg(new ArgPrinter(obj.reserved, "reserved", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_space, "st_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.xmm_space, "xmm_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.padding, "padding", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, user_regs_struct>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
#ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.r15, "r15", &os));
    abii_args->push_arg(new ArgPrinter(obj.r14, "r14", &os));
    abii_args->push_arg(new ArgPrinter(obj.r13, "r13", &os));
    abii_args->push_arg(new ArgPrinter(obj.r12, "r12", &os));
    abii_args->push_arg(new ArgPrinter(obj.rbp, "rbp", &os));
    abii_args->push_arg(new ArgPrinter(obj.rbx, "rbx", &os));
    abii_args->push_arg(new ArgPrinter(obj.r11, "r11", &os));
    abii_args->push_arg(new ArgPrinter(obj.r10, "r10", &os));
    abii_args->push_arg(new ArgPrinter(obj.r9, "r9", &os));
    abii_args->push_arg(new ArgPrinter(obj.r8, "r8", &os));
    abii_args->push_arg(new ArgPrinter(obj.rax, "rax", &os));
    abii_args->push_arg(new ArgPrinter(obj.rcx, "rcx", &os));
    abii_args->push_arg(new ArgPrinter(obj.rdx, "rdx", &os));
    abii_args->push_arg(new ArgPrinter(obj.rsi, "rsi", &os));
    abii_args->push_arg(new ArgPrinter(obj.rdi, "rdi", &os));
    abii_args->push_arg(new ArgPrinter(obj.orig_rax, "orig_rax", &os));
    abii_args->push_arg(new ArgPrinter(obj.rip, "rip", &os));
    abii_args->push_arg(new ArgPrinter(obj.cs, "cs", &os));
    abii_args->push_arg(new ArgPrinter(obj.eflags, "eflags", &os));
    abii_args->push_arg(new ArgPrinter(obj.rsp, "rsp", &os));
    abii_args->push_arg(new ArgPrinter(obj.ss, "ss", &os));
    abii_args->push_arg(new ArgPrinter(obj.fs_base, "fs_base", &os));
    abii_args->push_arg(new ArgPrinter(obj.gs_base, "gs_base", &os));
    abii_args->push_arg(new ArgPrinter(obj.ds, "ds", &os));
    abii_args->push_arg(new ArgPrinter(obj.es, "es", &os));
    abii_args->push_arg(new ArgPrinter(obj.fs, "fs", &os));
    abii_args->push_arg(new ArgPrinter(obj.gs, "gs", &os, RECURSE));
#else
    abii_args->push_arg(new ArgPrinter(obj.ebx, "ebx", &os));
    abii_args->push_arg(new ArgPrinter(obj.ecx, "ecx", &os));
    abii_args->push_arg(new ArgPrinter(obj.edx, "edx", &os));
    abii_args->push_arg(new ArgPrinter(obj.esi, "esi", &os));
    abii_args->push_arg(new ArgPrinter(obj.edi, "edi", &os));
    abii_args->push_arg(new ArgPrinter(obj.ebp, "ebp", &os));
    abii_args->push_arg(new ArgPrinter(obj.eax, "eax", &os));
    abii_args->push_arg(new ArgPrinter(obj.xds, "xds", &os));
    abii_args->push_arg(new ArgPrinter(obj.xes, "xes", &os));
    abii_args->push_arg(new ArgPrinter(obj.xfs, "xfs", &os));
    abii_args->push_arg(new ArgPrinter(obj.xgs, "xgs", &os));
    abii_args->push_arg(new ArgPrinter(obj.orig_eax, "orig_eax", &os));
    abii_args->push_arg(new ArgPrinter(obj.eip, "eip", &os));
    abii_args->push_arg(new ArgPrinter(obj.xcs, "xcs", &os));
    abii_args->push_arg(new ArgPrinter(obj.eflags, "eflags", &os));
    abii_args->push_arg(new ArgPrinter(obj.esp, "esp", &os));
    abii_args->push_arg(new ArgPrinter(obj.xss, "xss", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, user>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.regs, "regs", &os));
    abii_args->push_arg(new ArgPrinter(obj.u_fpvalid, "u_fpvalid", &os));
    abii_args->push_arg(new ArgPrinter(obj.i387, "i387", &os));
    abii_args->push_arg(new ArgPrinter(obj.u_tsize, "u_tsize", &os));
    abii_args->push_arg(new ArgPrinter(obj.u_dsize, "u_dsize", &os));
    abii_args->push_arg(new ArgPrinter(obj.u_ssize, "u_ssize", &os));
    abii_args->push_arg(new ArgPrinter(obj.start_code, "start_code", &os));
    abii_args->push_arg(new ArgPrinter(obj.start_stack, "start_stack", &os));
    abii_args->push_arg(new ArgPrinter(obj.signal, "signal", &os));
    abii_args->push_arg(new ArgPrinter(obj.reserved, "reserved", &os));
    abii_args->push_arg(new ArgPrinter(obj.u_ar0, "u_ar0", &os));
#ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__u_ar0_word, "__u_ar0_word", &os));
#endif
    abii_args->push_arg(new ArgPrinter(obj.u_fpstate, "u_fpstate", &os));
#ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__u_fpstate_word, "__u_fpstate_word", &os));
#endif
    abii_args->push_arg(new ArgPrinter(obj.magic, "magic", &os));
    abii_args->push_arg(new ArgPrinter(obj.u_comm, "u_comm", &os));
    abii_args->push_arg(new ArgPrinter(obj.u_debugreg, "u_debugreg", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_USER_H
