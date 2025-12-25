//
// Created by Trent Tanchin on 3/11/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_REGEX_H
#define ABII_C_LOGGING_PLUGIN_REGEX_H

#include <regex.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<unsigned long int> regex_syntax = {
    {static_cast<unsigned long int>(1), "RE_BACKSLASH_ESCAPE_IN_LISTS"},
    {(static_cast<unsigned long int>(1) << 1), "RE_BK_PLUS_QM"},
    {(static_cast<unsigned long int>(1) << 2), "RE_CHAR_CLASSES"},
    {(static_cast<unsigned long int>(1) << 3), "RE_CONTEXT_INDEP_ANCHORS"},
    {(static_cast<unsigned long int>(1) << 4), "RE_CONTEXT_INDEP_OPS"},
    {(static_cast<unsigned long int>(1) << 5), "RE_CONTEXT_INVALID_OPS"},
    {(static_cast<unsigned long int>(1) << 6), "RE_DOT_NEWLINE"},
    {(static_cast<unsigned long int>(1) << 8), "RE_DOT_NOT_NULL"},
    {(static_cast<unsigned long int>(1) << 9), "RE_HAT_LISTS_NOT_NEWLINE"},
    {(static_cast<unsigned long int>(1) << 10), "RE_INTERVALS"},
    {(static_cast<unsigned long int>(1) << 11), "RE_LIMITED_OPS"},
    {(static_cast<unsigned long int>(1) << 12), "RE_NEWLINE_ALT"},
    {(static_cast<unsigned long int>(1) << 13), "RE_NO_BK_BRACES"},
    {(static_cast<unsigned long int>(1) << 14), "RE_NO_BK_PARENS"},
    {(static_cast<unsigned long int>(1) << 15), "RE_NO_BK_REFS"},
    {(static_cast<unsigned long int>(1) << 16), "RE_NO_BK_VBAR"},
    {(static_cast<unsigned long int>(1) << 17), "RE_NO_EMPTY_RANGES"},
    {(static_cast<unsigned long int>(1) << 18), "RE_UNMATCHED_RIGHT_PAREN_ORD"},
    {(static_cast<unsigned long int>(1) << 19), "RE_NO_POSIX_BACKTRACKING"},
    {(static_cast<unsigned long int>(1) << 20), "RE_NO_GNU_OPS"},
    {(static_cast<unsigned long int>(1) << 21), "RE_DEBUG"},
    {(static_cast<unsigned long int>(1) << 22), "RE_INVALID_INTERVAL_ORD"},
    {(static_cast<unsigned long int>(1) << 23), "RE_ICASE"},
    {(static_cast<unsigned long int>(1) << 24), "RE_CARET_ANCHORS_HERE"},
    {(static_cast<unsigned long int>(1) << 25), "RE_CONTEXT_INVALID_DUP"},
    {(static_cast<unsigned long int>(1) << 26), "RE_NO_SUB"},
    {0, "RE_SYNTAX_EMACS"},
    {
        (static_cast<unsigned long int>(1) | static_cast<unsigned long int>(1) << 8
            | static_cast<unsigned long int>(1) << 14 | static_cast<unsigned long int>(1) << 15
            | static_cast<unsigned long int>(1) << 16 | static_cast<unsigned long int>(1) << 17
            | static_cast<unsigned long int>(1) << 6 | static_cast<unsigned long int>(1) << 3
            | static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 18
            | static_cast<unsigned long int>(1) << 20),
        "RE_SYNTAX_AWK"
    },
    {
        ((static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
                | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
                | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 3
                | static_cast<unsigned long int>(1) << 4 | static_cast<unsigned long int>(1) << 13
                | static_cast<unsigned long int>(1) << 14 | static_cast<unsigned long int>(1) << 16
                | static_cast<unsigned long int>(1) << 5 | static_cast<unsigned long int>(1) << 18
                | static_cast<unsigned long int>(1) | static_cast<unsigned long int>(1) << 22)
            & ~(static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 4
                | static_cast<unsigned long int>(1) << 5)),
        "RE_SYNTAX_GNU_AWK"
    },
    {
        (static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
            | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
            | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 3
            | static_cast<unsigned long int>(1) << 4 | static_cast<unsigned long int>(1) << 13
            | static_cast<unsigned long int>(1) << 14 | static_cast<unsigned long int>(1) << 16
            | static_cast<unsigned long int>(1) << 5 | static_cast<unsigned long int>(1) << 18
            | static_cast<unsigned long int>(1) | static_cast<unsigned long int>(1) << 10
            | static_cast<unsigned long int>(1) << 20 | static_cast<unsigned long int>(1) << 22),
        "RE_SYNTAX_POSIX_AWK"
    },
    {
        ((static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
                | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
                | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 1
                | static_cast<unsigned long int>(1) << 25 | static_cast<unsigned long int>(1) << 12)
            & ~(static_cast<unsigned long int>(1) << 25 | static_cast<unsigned long int>(1) << 8)),
        "RE_SYNTAX_GREP"
    },
    {
        ((static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
                | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
                | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 3
                | static_cast<unsigned long int>(1) << 4 | static_cast<unsigned long int>(1) << 13
                | static_cast<unsigned long int>(1) << 14 | static_cast<unsigned long int>(1) << 16
                | static_cast<unsigned long int>(1) << 5 | static_cast<unsigned long int>(1) << 18
                | static_cast<unsigned long int>(1) << 22 | static_cast<unsigned long int>(1) << 12)
            & ~(static_cast<unsigned long int>(1) << 5 | static_cast<unsigned long int>(1) << 8)),
        "RE_SYNTAX_EGREP"
    },
    {
        ((static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
                | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
                | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 3
                | static_cast<unsigned long int>(1) << 4 | static_cast<unsigned long int>(1) << 13
                | static_cast<unsigned long int>(1) << 14 | static_cast<unsigned long int>(1) << 16
                | static_cast<unsigned long int>(1) << 5 | static_cast<unsigned long int>(1) << 18
                | static_cast<unsigned long int>(1) << 22 | static_cast<unsigned long int>(1) << 12)
            & ~(static_cast<unsigned long int>(1) << 5 | static_cast<unsigned long int>(1) << 8)),
        "RE_SYNTAX_POSIX_EGREP"
    },
    {
        (static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
            | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
            | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 1
            | static_cast<unsigned long int>(1) << 25),
        "RE_SYNTAX_ED"
    },
    {
        (static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
            | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
            | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 1
            | static_cast<unsigned long int>(1) << 25),
        "RE_SYNTAX_SED"
    },
    {
        (static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
            | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
            | static_cast<unsigned long int>(1) << 17),
        "_RE_SYNTAX_POSIX_COMMON"
    },
    {
        (static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
            | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
            | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 1
            | static_cast<unsigned long int>(1) << 25),
        "RE_SYNTAX_POSIX_BASIC"
    },
    {
        (static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
            | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
            | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 11),
        "RE_SYNTAX_POSIX_MINIMAL_BASIC"
    },
    {
        (static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
            | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
            | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 3
            | static_cast<unsigned long int>(1) << 4 | static_cast<unsigned long int>(1) << 13
            | static_cast<unsigned long int>(1) << 14 | static_cast<unsigned long int>(1) << 16
            | static_cast<unsigned long int>(1) << 5 | static_cast<unsigned long int>(1) << 18),
        "RE_SYNTAX_POSIX_EXTENDED"
    },
    {
        (static_cast<unsigned long int>(1) << 2 | static_cast<unsigned long int>(1) << 6
            | static_cast<unsigned long int>(1) << 8 | static_cast<unsigned long int>(1) << 10
            | static_cast<unsigned long int>(1) << 17 | static_cast<unsigned long int>(1) << 3
            | static_cast<unsigned long int>(1) << 5 | static_cast<unsigned long int>(1) << 13
            | static_cast<unsigned long int>(1) << 14 | static_cast<unsigned long int>(1) << 15
            | static_cast<unsigned long int>(1) << 16 | static_cast<unsigned long int>(1) << 18),
        "RE_SYNTAX_POSIX_MINIMAL_EXTENDED"
    }
};

const defines_map regex_dup_max = {
    {0x7fff, "RE_DUP_MAX"}
};

const defines_map regex_cflags = {
    {1, "REG_EXTENDED"},
    {(1 << 1), "REG_ICASE"},
    {(1 << 2), "REG_NEWLINE"},
    {(1 << 3), "REG_NOSUB"}
};

const defines_map regex_eflags = {
    {1, "REG_NOTBOL"},
    {(1 << 1), "REG_NOTEOL"},
    {(1 << 2), "REG_STARTEND"}
};

const defines_map regex_reg_errcode_t = {
    {-1, "_REG_ENOSYS"},
    {0, "_REG_NOERROR"},
    {1, "_REG_NOMATCH"},
    {2, "_REG_BADPAT"},
    {3, "_REG_ECOLLATE"},
    {4, "_REG_ECTYPE"},
    {5, "_REG_EESCAPE"},
    {6, "_REG_ESUBREG"},
    {7, "_REG_EBRACK"},
    {8, "_REG_EPAREN"},
    {9, "_REG_EBRACE"},
    {10, "_REG_BADBR"},
    {11, "_REG_ERANGE"},
    {12, "_REG_ESPACE"},
    {13, "_REG_BADRPT"},
    {14, "_REG_EEND"},
    {15, "_REG_ESIZE"},
    {16, "_REG_ERPAREN"},
    {-1, "REG_ENOSYS"},
    {0, "REG_NOERROR"},
    {1, "REG_NOMATCH"},
    {2, "REG_BADPAT"},
    {3, "REG_ECOLLATE"},
    {4, "REG_ECTYPE"},
    {5, "REG_EESCAPE"},
    {6, "REG_ESUBREG"},
    {7, "REG_EBRACK"},
    {8, "REG_EPAREN"},
    {9, "REG_EBRACE"},
    {10, "REG_BADBR"},
    {11, "REG_ERANGE"},
    {12, "REG_ESPACE"},
    {13, "REG_BADRPT"},
    {14, "REG_EEND"},
    {15, "REG_ESIZE"},
    {16, "REG_ERPAREN"}
};

const defines_map regex_regs_allocation = {
    {0, "REGS_UNALLOCATED"},
    {1, "REGS_REALLOCATE"},
    {2, "REGS_FIXED"}
};

const defines_map regex_re_nregs = {
    {30, "RE_NREGS"}
};

template <typename T>
std::string print_regex_syntax(const T v)
{
    return print_or_enum_entries(v, regex_syntax);
}

template <typename T>
std::string print_regex_dup_max(const T v)
{
    return print_enum_entry(v, regex_dup_max);
}

template <typename T>
std::string print_regex_cflags(const T v)
{
    return print_or_enum_entries(v, regex_cflags);
}

template <typename T>
std::string print_regex_eflags(const T v)
{
    return print_or_enum_entries(v, regex_eflags);
}

template <typename T>
std::string print_regex_reg_errcode_t(const T v)
{
    return print_enum_entry(v, regex_reg_errcode_t);
}

template <typename T>
std::string print_regex_regs_allocation(const T v)
{
    return print_enum_entry(v, regex_regs_allocation);
}

template <typename T>
std::string print_regex_re_nregs(const T v)
{
    return print_enum_entry(v, regex_re_nregs);
}
}

using namespace abii;

#ifdef __USE_GNU
struct re_dfa_t {};

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, re_pattern_buffer>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__REPB_PREFIX(buffer), TOSTRING(__REPB_PREFIX(buffer)), &os));
    abii_args->push_arg(new ArgPrinter(obj.__REPB_PREFIX(allocated), TOSTRING(__REPB_PREFIX(allocated)), &os));
    abii_args->push_arg(new ArgPrinter(obj.__REPB_PREFIX(used), TOSTRING(__REPB_PREFIX(used)), &os));

    auto printer = new ArgPrinter(obj.__REPB_PREFIX(syntax), TOSTRING(__REPB_PREFIX(syntax)), &os);
    printer->set_enum_printer(print_regex_syntax, obj.__REPB_PREFIX(syntax));
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.__REPB_PREFIX(fastmap), TOSTRING(__REPB_PREFIX(fastmap)), &os));
    abii_args->push_arg(new ArgPrinter(obj.__REPB_PREFIX(translate), TOSTRING(__REPB_PREFIX(translate)), &os));
    abii_args->push_arg(new ArgPrinter(obj.re_nsub, "re_nsub", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.__REPB_PREFIX(can_be_null)),
                                       TOSTRING(__REPB_PREFIX(can_be_null)), &os));

    auto printer1 = new ArgPrinter(static_cast<unsigned>(obj.__REPB_PREFIX(regs_allocated)),
                               TOSTRING(__REPB_PREFIX(regs_allocated)), &os);
    printer1->set_enum_printer(print_regex_regs_allocation, obj.__REPB_PREFIX(regs_allocated));
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.__REPB_PREFIX(fastmap_accurate)),
                                       TOSTRING(__REPB_PREFIX(fastmap_accurate)), &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.__REPB_PREFIX(no_sub)),
                                       TOSTRING(__REPB_PREFIX(no_sub)), &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.__REPB_PREFIX(not_bol)),
                                       TOSTRING(__REPB_PREFIX(not_bol)), &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.__REPB_PREFIX(not_eol)),
                                       TOSTRING(__REPB_PREFIX(not_eol)), &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.__REPB_PREFIX(newline_anchor)),
                                       TOSTRING(__REPB_PREFIX(newline_anchor)), &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, re_dfa_t>
std::ostream& operator<<(std::ostream& os, T&& /*obj*/)
{
    OVERRIDE_STREAM_PREFIX
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, re_registers>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.num_regs, "num_regs", &os);
    printer->set_enum_printer(print_regex_re_nregs, obj.num_regs);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.start, "start", &os));
    abii_args->push_arg(new ArgPrinter(obj.end, "end", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, regmatch_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.rm_so, "rm_so", &os));
    abii_args->push_arg(new ArgPrinter(obj.rm_eo, "rm_eo", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_REGEX_H
