//
// Created by Trent Tanchin on 11/8/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_WORDEXP_H
#define ABII_C_LOGGING_PLUGIN_WORDEXP_H

#include <wordexp.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<wint_t> wordexp_wrde_flags = {
    {1 << 0, "WRDE_DOOFFS"},
    {1 << 1, "WRDE_APPEND"},
    {1 << 2, "WRDE_NOCMD"},
    {1 << 3, "WRDE_REUSE"},
    {1 << 4, "WRDE_SHOWERR"},
    {1 << 5, "WRDE_UNDEF"},
    {1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5, "__WRDE_FLAGS"}
};

const defines_map<wint_t> wordexp_wrde_ret = {
    {-1, "WRDE_NOSYS"},
    {1, "WRDE_NOSPACE"},
    {2, "WRDE_BADCHAR"},
    {3, "WRDE_BADVAL"},
    {4, "WRDE_CMDSUB"},
    {5, "WRDE_SYNTAX"}
};

template <typename T>
std::string print_wordexp_wrde_flags(const T v)
{
    return print_or_enum_entries(v, wordexp_wrde_flags);
}

template <typename T>
std::string print_wordexp_wrde_ret(const T v)
{
    return print_enum_entry(v, wordexp_wrde_ret);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, wordexp_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.we_wordc, "we_wordc", &os));

    const auto we_wordv_size = obj.we_offs + obj.we_wordc;
    auto printer = new ArgPrinter(obj.we_wordv, "we_wordv", &os);
    printer->set_len(we_wordv_size);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.we_offs, "we_offs", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_WORDEXP_H
