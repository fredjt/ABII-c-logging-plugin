//
// Created by Trent Tanchin on 4/17/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_RES_STATE_H
#define ABII_C_LOGGING_PLUGIN_RES_STATE_H

#include <abii/libabii.h>
#include <bits/types/res_state.h>

#include "hooks/resolv.h"
#include "netinet/in.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, struct __res_state>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = ArgPrinter(obj.retrans, "retrans", &os);
    printer.set_enum_printer(print_resolv_timeout, obj.retrans);
    abii_args->push_arg(&printer);

    auto printer1 = ArgPrinter(obj.retry, "retry", &os);
    printer1.set_enum_printer(print_resolv_dflretry, obj.retry);
    abii_args->push_arg(&printer1);

    auto printer2 = ArgPrinter(obj.options, "options", &os);
    printer2.set_enum_printer(print_resolv_option, obj.options);
    abii_args->push_arg(&printer2);

    abii_args->push_arg(new ArgPrinter(obj.nscount, "nscount", &os));
    abii_args->push_arg(new ArgPrinter(obj.nsaddr_list, "nsaddr_list", &os));
    abii_args->push_arg(new ArgPrinter(obj.id, "id", &os));
    abii_args->push_arg(new ArgPrinter(obj.dnsrch, "dnsrch", &os));
    abii_args->push_arg(new ArgPrinter(obj.defdname, "defdname", &os));

    auto printer3 = ArgPrinter(obj.pfcode, "pfcode", &os);
    printer3.set_enum_printer(print_resolv_pfcode, obj.pfcode);
    abii_args->push_arg(&printer3);

    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.ndots), "ndots", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.nsort), "nsort", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.ipv6_unavail), "ipv6_unavail", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.unused), "unused", &os));
    abii_args->push_arg(new ArgPrinter(obj.sort_list, "sort_list", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_unused_qhook, "__glibc_unused_qhook", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_unused_rhook, "__glibc_unused_rhook", &os));
    abii_args->push_arg(new ArgPrinter(obj.res_h_errno, "res_h_errno", &os));
    abii_args->push_arg(new ArgPrinter(obj._vcsock, "_vcsock", &os));
    abii_args->push_arg(new ArgPrinter(obj._flags, "_flags", &os));
    abii_args->push_arg(new ArgPrinter(obj._u, "_u", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(*__res_state::sort_list)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.addr, "addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.mask, "mask", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(__res_state::_u)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.pad, "pad", &os));
    abii_args->push_arg(new ArgPrinter(obj._ext, "_ext", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

using __res_state__u = typeof(__res_state::_u);

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(__res_state__u::_ext)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.nscount, "nscount", &os));
    abii_args->push_arg(new ArgPrinter(obj.nsmap, "nsmap", &os));
    abii_args->push_arg(new ArgPrinter(obj.nssocks, "nssocks", &os));
    abii_args->push_arg(new ArgPrinter(obj.nscount6, "nscount6", &os));
    abii_args->push_arg(new ArgPrinter(obj.nsinit, "nsinit", &os));
    abii_args->push_arg(new ArgPrinter(obj.nsaddrs, "nsaddrs", &os));
#ifdef _LIBC
    abii_args->push_arg(new ArgPrinter(obj.__glibc_extension_index, "__glibc_extension_index", &os, RECURSE));
#else
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved, "__glibc_reserved", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_RES_STATE_H
