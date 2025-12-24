//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SIGINFO_CONSTS_H
#define ABII_C_LOGGING_PLUGIN_SIGINFO_CONSTS_H

#include <bits/siginfo-consts.h>

namespace abii
{
const defines_map siginfo_consts_code = {
    {-60, "SI_ASYNCNL"},
    {-7, "SI_DETHREAD"},
    {-6, "SI_TKILL"},
    {-5, "SI_SIGIO"},
    {-4, "SI_ASYNCIO"},
    {-3, "SI_MESGQ"},
    {-2, "SI_TIMER"},
    {-1, "SI_QUEUE"},
    {0, "SI_USER"},
    {128, "SI_KERNEL"}
};

const defines_map siginfo_consts_ill_code = {
    {1, "ILL_ILLOPC"},
    {2, "ILL_ILLOPN"},
    {3, "ILL_ILLADR"},
    {4, "ILL_ILLTRP"},
    {5, "ILL_PRVOPC"},
    {6, "ILL_PRVREG"},
    {7, "ILL_COPROC"},
    {8, "ILL_BADSTK"},
    {9, "ILL_BADIADDR"}
};

const defines_map siginfo_consts_fpe_code = {
    {1, "FPE_INTDIV"},
    {2, "FPE_INTOVF"},
    {3, "FPE_FLTDIV"},
    {4, "FPE_FLTOVF"},
    {5, "FPE_FLTUND"},
    {6, "FPE_FLTRES"},
    {7, "FPE_FLTINV"},
    {8, "FPE_FLTSUB"},
    {9, "FPE_FLTUNK"},
    {10, "FPE_CONDTRAP"}
};

const defines_map siginfo_consts_segv_code = {
    {1, "SEGV_MAPERR"},
    {2, "SEGV_ACCERR"},
    {3, "SEGV_BNDERR"},
    {4, "SEGV_PKUERR"},
    {5, "SEGV_ACCADI"},
    {6, "SEGV_ADIDERR"},
    {7, "SEGV_ADIPERR"},
    {8, "SEGV_MTEAERR"},
    {9, "SEGV_MTESERR"},
    {10, "SEGV_CPERR"}
};

const defines_map siginfo_consts_bus_code = {
    {1, "BUS_ADRALN"},
    {2, "BUS_ADRERR"},
    {3, "BUS_OBJERR"},
    {4, "BUS_MCEERR_AR"},
    {5, "BUS_MCEERR_AO"}
};

const defines_map siginfo_consts_trap_code = {
    {1, "TRAP_BRKPT"},
    {2, "TRAP_TRACE"},
    {3, "TRAP_BRANCH"},
    {4, "TRAP_HWBKPT"},
    {5, "TRAP_UNK"}
};

const defines_map siginfo_consts_cld_code = {
    {1, "CLD_EXITED"},
    {2, "CLD_KILLED"},
    {3, "CLD_DUMPED"},
    {4, "CLD_TRAPPED"},
    {5, "CLD_STOPPED"},
    {6, "CLD_CONTINUED"}
};

const defines_map siginfo_consts_poll_code = {
    {1, "POLL_IN"},
    {2, "POLL_OUT"},
    {3, "POLL_MSG"},
    {4, "POLL_ERR"},
    {5, "POLL_PRI"},
    {6, "POLL_HUP"}
};

template <typename T>
std::string print_siginfo_consts_code(const T v)
{
    return print_enum_entry(v, siginfo_consts_code);
}

template <typename T>
std::string print_siginfo_consts_ill_code(const T v)
{
    return print_enum_entry(v, siginfo_consts_ill_code);
}

template <typename T>
std::string print_siginfo_consts_enum_si_ill(const T v)
{
    return print_enum_entry(v, siginfo_consts_code, siginfo_consts_ill_code);
}

template <typename T>
std::string print_siginfo_consts_fpe_code(const T v)
{
    return print_enum_entry(v, siginfo_consts_fpe_code);
}

template <typename T>
std::string print_siginfo_consts_enum_si_fpe(const T v)
{
    return print_enum_entry(v, siginfo_consts_code, siginfo_consts_fpe_code);
}

template <typename T>
std::string print_siginfo_consts_segv_code(const T v)
{
    return print_enum_entry(v, siginfo_consts_segv_code);
}

template <typename T>
std::string print_siginfo_consts_enum_si_segv(const T v)
{
    return print_enum_entry(v, siginfo_consts_code, siginfo_consts_segv_code);
}

template <typename T>
std::string print_siginfo_consts_bus_code(const T v)
{
    return print_enum_entry(v, siginfo_consts_bus_code);
}

template <typename T>
std::string print_siginfo_consts_enum_si_bus(const T v)
{
    return print_enum_entry(v, siginfo_consts_code, siginfo_consts_bus_code);
}

template <typename T>
std::string print_siginfo_consts_trap_code(const T v)
{
    return print_enum_entry(v, siginfo_consts_trap_code);
}

template <typename T>
std::string print_siginfo_consts_enum_si_trap(const T v)
{
    return print_enum_entry(v, siginfo_consts_code, siginfo_consts_trap_code);
}

template <typename T>
std::string print_siginfo_consts_cld_code(const T v)
{
    return print_enum_entry(v, siginfo_consts_cld_code);
}

template <typename T>
std::string print_siginfo_consts_enum_si_cld(const T v)
{
    return print_enum_entry(v, siginfo_consts_code, siginfo_consts_cld_code);
}

template <typename T>
std::string print_siginfo_consts_poll_code(const T v)
{
    return print_enum_entry(v, siginfo_consts_poll_code);
}

template <typename T>
std::string print_siginfo_consts_enum_si_poll(const T v)
{
    return print_enum_entry(v, siginfo_consts_code, siginfo_consts_poll_code);
}
}

#endif //ABII_C_LOGGING_PLUGIN_SIGINFO_CONSTS_H
