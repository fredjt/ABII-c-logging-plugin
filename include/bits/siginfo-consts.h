//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGINFO_CONSTS_H
#define ABII_C_LOGGING_PLUGIN_SIGINFO_CONSTS_H

#include <bits/siginfo-consts.h>

namespace abii
{
const defines_map siginfo_consts_enum1 = {
    {SI_ASYNCNL, "SI_ASYNCNL"},
    {SI_DETHREAD, "SI_DETHREAD"},
    {SI_TKILL, "SI_TKILL"},
    {SI_SIGIO, "SI_SIGIO"},
    {SI_ASYNCIO, "SI_ASYNCIO"},
    {SI_MESGQ, "SI_MESGQ"},
    {SI_TIMER, "SI_TIMER"},
    {SI_QUEUE, "SI_QUEUE"},
    {SI_USER, "SI_USER"},
    {SI_KERNEL, "SI_KERNEL"}
};

#if defined __USE_XOPEN_EXTENDED || defined __USE_XOPEN2K8
const defines_map siginfo_consts_enum2 = {
    {ILL_ILLOPC, "ILL_ILLOPC"},
    {ILL_ILLOPN, "ILL_ILLOPN"},
    {ILL_ILLADR, "ILL_ILLADR"},
    {ILL_ILLTRP, "ILL_ILLTRP"},
    {ILL_PRVOPC, "ILL_PRVOPC"},
    {ILL_PRVREG, "ILL_PRVREG"},
    {ILL_COPROC, "ILL_COPROC"},
    {ILL_BADSTK, "ILL_BADSTK"},
    {ILL_BADIADDR, "ILL_BADIADDR"}
};

const defines_map siginfo_consts_enum3 = {
    {FPE_INTDIV, "FPE_INTDIV"},
    {FPE_INTOVF, "FPE_INTOVF"},
    {FPE_FLTDIV, "FPE_FLTDIV"},
    {FPE_FLTOVF, "FPE_FLTOVF"},
    {FPE_FLTUND, "FPE_FLTUND"},
    {FPE_FLTRES, "FPE_FLTRES"},
    {FPE_FLTINV, "FPE_FLTINV"},
    {FPE_FLTSUB, "FPE_FLTSUB"},
    {FPE_FLTUNK, "FPE_FLTUNK"},
    {FPE_CONDTRAP, "FPE_CONDTRAP"}
};

const defines_map siginfo_consts_enum4 = {
    {SEGV_MAPERR, "SEGV_MAPERR"},
    {SEGV_ACCERR, "SEGV_ACCERR"},
    {SEGV_BNDERR, "SEGV_BNDERR"},
    {SEGV_PKUERR, "SEGV_PKUERR"},
    {SEGV_ACCADI, "SEGV_ACCADI"},
    {SEGV_ADIDERR, "SEGV_ADIDERR"},
    {SEGV_ADIPERR, "SEGV_ADIPERR"},
    {SEGV_MTEAERR, "SEGV_MTEAERR"},
    {SEGV_MTESERR, "SEGV_MTESERR"},
    {SEGV_CPERR, "SEGV_CPERR"}
};

const defines_map siginfo_consts_enum5 = {
    {BUS_ADRALN, "BUS_ADRALN"},
    {BUS_ADRERR, "BUS_ADRERR"},
    {BUS_OBJERR, "BUS_OBJERR"},
    {BUS_MCEERR_AR, "BUS_MCEERR_AR"},
    {BUS_MCEERR_AO, "BUS_MCEERR_AO"}
};
#endif

#ifdef __USE_XOPEN_EXTENDED
const defines_map siginfo_consts_enum6 = {
    {TRAP_BRKPT, "TRAP_BRKPT"},
    {TRAP_TRACE, "TRAP_TRACE"},
    {TRAP_BRANCH, "TRAP_BRANCH"},
    {TRAP_HWBKPT, "TRAP_HWBKPT"},
    {TRAP_UNK, "TRAP_UNK"}
};
#endif

# if defined __USE_XOPEN_EXTENDED || defined __USE_XOPEN2K8
const defines_map siginfo_consts_enum7 = {
    {CLD_EXITED, "CLD_EXITED"},
    {CLD_KILLED, "CLD_KILLED"},
    {CLD_DUMPED, "CLD_DUMPED"},
    {CLD_TRAPPED, "CLD_TRAPPED"},
    {CLD_STOPPED, "CLD_STOPPED"},
    {CLD_CONTINUED, "CLD_CONTINUED"}
};

const defines_map siginfo_consts_enum8 = {
    {POLL_IN, "POLL_IN"},
    {POLL_OUT, "POLL_OUT"},
    {POLL_MSG, "POLL_MSG"},
    {POLL_ERR, "POLL_ERR"},
    {POLL_PRI, "POLL_PRI"},
    {POLL_HUP, "POLL_HUP"}
};
#endif

template<typename T>
std::string print_siginfo_consts_enum1(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum1);
}

# if defined __USE_XOPEN_EXTENDED || defined __USE_XOPEN2K8
template<typename T>
std::string print_siginfo_consts_enum2(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum2);
}

template<typename T>
std::string print_siginfo_consts_enum_si_ill(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum1, siginfo_consts_enum2);
}

template<typename T>
std::string print_siginfo_consts_enum3(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum3);
}

template<typename T>
std::string print_siginfo_consts_enum_si_fpe(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum1, siginfo_consts_enum3);
}

template<typename T>
std::string print_siginfo_consts_enum4(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum4);
}

template<typename T>
std::string print_siginfo_consts_enum_si_segv(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum1, siginfo_consts_enum4);
}

template<typename T>
std::string print_siginfo_consts_enum5(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum5);
}

template<typename T>
std::string print_siginfo_consts_enum_si_bus(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum1, siginfo_consts_enum5);
}
#endif

#ifdef __USE_XOPEN_EXTENDED
template<typename T>
std::string print_siginfo_consts_enum6(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum6);
}

template<typename T>
std::string print_siginfo_consts_enum_si_trap(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum1, siginfo_consts_enum6);
}
#endif

# if defined __USE_XOPEN_EXTENDED || defined __USE_XOPEN2K8
template<typename T>
std::string print_siginfo_consts_enum7(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum7);
}

template<typename T>
std::string print_siginfo_consts_enum_si_cld(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum1, siginfo_consts_enum7);
}

template<typename T>
std::string print_siginfo_consts_enum8(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum8);
}

template<typename T>
std::string print_siginfo_consts_enum_si_poll(const T v)
{
    return print_enum_entry(v, siginfo_consts_enum1, siginfo_consts_enum8);
}
#endif
}

#endif //ABII_C_LOGGING_PLUGIN_SIGINFO_CONSTS_H
