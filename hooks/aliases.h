//
// Created by Trent Tanchin on 7/4/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_ALIASES_H
#define ABII_C_LOGGING_PLUGIN_ALIASES_H

#include <aliases.h>
#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, aliasent>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.alias_name, "alias_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.alias_members_len, "alias_members_len", &os));

    auto printer = new ArgPrinter(obj.alias_members, "alias_members", &os);
    printer->set_len(obj.alias_members_len);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.alias_local, "alias_local", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_ALIASES_H
