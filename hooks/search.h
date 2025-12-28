//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SEARCH_H
#define ABII_C_LOGGING_PLUGIN_SEARCH_H

#include <search.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map search_action = {
    {0, "FIND"},
    {1, "ENTER"}
};

const defines_map search_visit = {
    {0, "preorder"},
    {1, "postorder"},
    {2, "endorder"},
    {3, "leaf"}
};

template <typename T>
std::string print_search_enum1(const T v)
{
    return print_enum_entry(v, search_action);
}

template <typename T>
std::string print_search_enum2(const T v)
{
    return print_enum_entry(v, search_visit);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, qelem>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.q_forw, "q_forw", &os));
    abii_args->push_arg(new ArgPrinter(obj.q_back, "q_back", &os));
    abii_args->push_arg(new ArgPrinter(obj.q_data, "q_data", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, entry>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.key, "key", &os));
    abii_args->push_arg(new ArgPrinter(obj.data, "data", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

struct _ENTRY {};

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _ENTRY>
std::ostream& operator<<(std::ostream& os, T&& /*obj*/)
{
    OVERRIDE_STREAM_PREFIX
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, hsearch_data>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.table, "table", &os));
    abii_args->push_arg(new ArgPrinter(obj.size, "size", &os));
    abii_args->push_arg(new ArgPrinter(obj.filled, "filled", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_SEARCH_H
