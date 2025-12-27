//
// Created by Trent Tanchin on 12/27/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_LOCALE_H
#define ABII_C_LOGGING_PLUGIN_LOCALE_H

#include <abii/libabii.h>

namespace abii
{
const defines_map locale_category = {
    {0, "LC_CTYPE"},
    {1, "LC_NUMERIC"},
    {2, "LC_TIME"},
    {3, "LC_COLLATE"},
    {4, "LC_MONETARY"},
    {5, "LC_MESSAGES"},
    {6, "LC_ALL"},
    {7, "LC_PAPER"},
    {8, "LC_NAME"},
    {9, "LC_ADDRESS"},
    {10, "LC_TELEPHONE"},
    {11, "LC_MEASUREMENT"},
    {12, "LC_IDENTIFICATION"}
};

const defines_map locale_category_mask = {
    {(1 << 0), "LC_CTYPE_MASK"},
    {(1 << 1), "LC_NUMERIC_MASK"},
    {(1 << 2), "LC_TIME_MASK"},
    {(1 << 3), "LC_COLLATE_MASK"},
    {(1 << 4), "LC_MONETARY_MASK"},
    {(1 << 5), "LC_MESSAGES_MASK"},
    {(1 << 7), "LC_PAPER_MASK"},
    {(1 << 8), "LC_NAME_MASK"},
    {(1 << 9), "LC_ADDRESS_MASK"},
    {(1 << 10), "LC_TELEPHONE_MASK"},
    {(1 << 11), "LC_MEASUREMENT_MASK"},
    {(1 << 12), "LC_IDENTIFICATION_MASK"},
    {
        (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 7 | 1 << 8 | 1 << 9 | 1 << 10 | 1 << 11 | 1 << 12),
        "LC_ALL_MASK"
    }
};

const defines_map<locale_t> locale_global_locale = {
    {reinterpret_cast<locale_t>(-1L), "LC_GLOBAL_LOCALE"}
};

template <typename T>
std::string print_locale_category(const T v)
{
    return print_enum_entry(v, locale_category);
}

template <typename T>
std::string print_locale_category_mask(const T v)
{
    return print_or_enum_entries(v, locale_category_mask);
}

template <typename T>
std::string print_locale_global_locale(const T v)
{
    return print_enum_entry(v, locale_global_locale);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, lconv>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.decimal_point, "decimal_point", &os));
    abii_args->push_arg(new ArgPrinter(obj.thousands_sep, "thousands_sep", &os));
    abii_args->push_arg(new ArgPrinter(obj.grouping, "grouping", &os));
    abii_args->push_arg(new ArgPrinter(obj.int_curr_symbol, "int_curr_symbol", &os));
    abii_args->push_arg(new ArgPrinter(obj.currency_symbol, "currency_symbol", &os));
    abii_args->push_arg(new ArgPrinter(obj.mon_decimal_point, "mon_decimal_point", &os));
    abii_args->push_arg(new ArgPrinter(obj.mon_thousands_sep, "mon_thousands_sep", &os));
    abii_args->push_arg(new ArgPrinter(obj.mon_grouping, "mon_grouping", &os));
    abii_args->push_arg(new ArgPrinter(obj.positive_sign, "positive_sign", &os));
    abii_args->push_arg(new ArgPrinter(obj.negative_sign, "negative_sign", &os));
    abii_args->push_arg(new ArgPrinter(obj.int_frac_digits, "int_frac_digits", &os));
    abii_args->push_arg(new ArgPrinter(obj.frac_digits, "frac_digits", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_cs_precedes, "p_cs_precedes", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_sep_by_space, "p_sep_by_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.n_cs_precedes, "n_cs_precedes", &os));
    abii_args->push_arg(new ArgPrinter(obj.n_sep_by_space, "n_sep_by_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_sign_posn, "p_sign_posn", &os));
    abii_args->push_arg(new ArgPrinter(obj.n_sign_posn, "n_sign_posn", &os));
#ifdef __USE_ISOC99
    abii_args->push_arg(new ArgPrinter(obj.int_p_cs_precedes, "int_p_cs_precedes", &os));
    abii_args->push_arg(new ArgPrinter(obj.int_p_sep_by_space, "int_p_sep_by_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.int_n_cs_precedes, "int_n_cs_precedes", &os));
    abii_args->push_arg(new ArgPrinter(obj.int_n_sep_by_space, "int_n_sep_by_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.int_p_sign_posn, "int_p_sign_posn", &os));
    abii_args->push_arg(new ArgPrinter(obj.int_n_sign_posn, "int_n_sign_posn", &os, RECURSE));
#else
    abii_args->push_arg(new ArgPrinter(obj.__int_p_cs_precedes, "int_p_cs_precedes", &os));
    abii_args->push_arg(new ArgPrinter(obj.__int_p_sep_by_space, "int_p_sep_by_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.__int_n_cs_precedes, "int_n_cs_precedes", &os));
    abii_args->push_arg(new ArgPrinter(obj.__int_n_sep_by_space, "int_n_sep_by_space", &os));
    abii_args->push_arg(new ArgPrinter(obj.__int_p_sign_posn, "int_p_sign_posn", &os));
    abii_args->push_arg(new ArgPrinter(obj.__int_n_sign_posn, "int_n_sign_posn", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_LOCALE_H
