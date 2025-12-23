//
// Created by Trent Tanchin on 10/15/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_NETDB_H
#define ABII_C_LOGGING_PLUGIN_NETDB_H

#include <abii/libabii.h>
#include <bits/netdb.h>

#include "socket.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, netent>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.n_name, "n_name", &os));

    auto printer = ArgPrinter(obj.n_aliases, "n_aliases", &os);
    printer.set_end_test([&](const size_t i) { return obj.n_aliases[i] != nullptr; });
    abii_args->push_arg(&printer);

    auto printer1 = ArgPrinter(obj.n_addrtype, "n_addrtype", &os);
    printer1.set_enum_printer(print_socket_addr_family, obj.n_addrtype);
    abii_args->push_arg(&printer1);

    abii_args->push_arg(new ArgPrinter(obj.n_net, "n_net", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_NETDB_H
