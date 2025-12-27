//
// Created by Trent Tanchin on 10/3/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_MALLOC_H
#define ABII_C_LOGGING_PLUGIN_MALLOC_H

#include <malloc.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map malloc_mallopt = {
    {1, "M_MXFAST"},
    {2, "M_NLBLKS"},
    {3, "M_GRAIN"},
    {4, "M_KEEP"},
    {-1, "M_TRIM_THRESHOLD"},
    {-2, "M_TOP_PAD"},
    {-3, "M_MMAP_THRESHOLD"},
    {-4, "M_MMAP_MAX"},
    {-5, "M_CHECK_ACTION"},
    {-6, "M_PERTURB"},
    {-7, "M_ARENA_TEST"},
    {-8, "M_ARENA_MAX"}
};

template <typename T>
std::string print_malloc_mallopt(const T v)
{
    return print_enum_entry(v, malloc_mallopt);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, struct mallinfo>
    || std::is_same_v<std::remove_cvref_t<T>, struct mallinfo2>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.arena, "arena", &os));
    abii_args->push_arg(new ArgPrinter(obj.ordblks, "ordblks", &os));
    abii_args->push_arg(new ArgPrinter(obj.smblks, "smblks", &os));
    abii_args->push_arg(new ArgPrinter(obj.hblks, "hblks", &os));
    abii_args->push_arg(new ArgPrinter(obj.hblkhd, "hblkhd", &os));
    abii_args->push_arg(new ArgPrinter(obj.usmblks, "usmblks", &os));
    abii_args->push_arg(new ArgPrinter(obj.fsmblks, "fsmblks", &os));
    abii_args->push_arg(new ArgPrinter(obj.uordblks, "uordblks", &os));
    abii_args->push_arg(new ArgPrinter(obj.fordblks, "fordblks", &os));
    abii_args->push_arg(new ArgPrinter(obj.keepcost, "keepcost", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_MALLOC_H
