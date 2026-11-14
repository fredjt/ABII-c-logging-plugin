//
// Created by Trent Tanchin on 11/13/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_IPC_H
#define ABII_C_LOGGING_PLUGIN_IPC_H

#include <abii/libabii.h>
#include <sys/ipc.h>

namespace abii
{
const defines_map bits_ipc_modes = {
    {IPC_CREAT, "IPC_CREAT"},
    {IPC_EXCL, "IPC_EXCL"},
    {IPC_NOWAIT, "IPC_NOWAIT"}
};

const defines_map bits_ipc_cntrl_cmd = {
    {IPC_RMID, "IPC_RMID"},
    {IPC_SET, "IPC_SET"},
    {IPC_STAT, "IPC_STAT"},
    {IPC_INFO, "IPC_INFO"}
};

const defines_map<__key_t> bits_ipc_private = {
    {IPC_PRIVATE, "IPC_PRIVATE"}
};

template <typename T>
std::string print_bits_ipc_modes(const T v)
{
    return print_or_enum_entries(v, bits_ipc_modes);
}

template <typename T>
std::string print_bits_ipc_cntrl_cmd(const T v)
{
    return print_enum_entry(v, bits_ipc_cntrl_cmd);
}

template <typename T>
std::string print_bits_ipc_private(const T v)
{
    return print_enum_entry(v, bits_ipc_private);
}
}

#endif //ABII_C_LOGGING_PLUGIN_IPC_H
