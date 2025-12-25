//
// Created by Trent Tanchin on 7/4/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_ARGP_H
#define ABII_C_LOGGING_PLUGIN_ARGP_H

#include <argp.h>
#include <abii/libabii.h>

#include "asm-generic/errno-base.h"

namespace abii
{
const defines_map argp_option = {
    {0x1, "OPTION_ARG_OPTIONAL"},
    {0x2, "OPTION_HIDDEN"},
    {0x4, "OPTION_ALIAS"},
    {0x8, "OPTION_DOC"},
    {0x10, "OPTION_NO_USAGE"}
};

const defines_map argp_err_unknown = {
    {7, "ARGP_ERR_UNKNOWN"}
};

const defines_map argp_key = {
    {0, "ARGP_KEY_ARG"},
    {0x1000006, "ARGP_KEY_ARGS"},
    {0x1000001, "ARGP_KEY_END"},
    {0x1000002, "ARGP_KEY_NO_ARGS"},
    {0x1000003, "ARGP_KEY_INIT"},
    {0x1000007, "ARGP_KEY_FINI"},
    {0x1000004, "ARGP_KEY_SUCCESS"},
    {0x1000005, "ARGP_KEY_ERROR"}
};

const defines_map argp_key_help = {
    {0x2000001, "ARGP_KEY_HELP_PRE_DOC"},
    {0x2000002, "ARGP_KEY_HELP_POST_DOC"},
    {0x2000003, "ARGP_KEY_HELP_HEADER"},
    {0x2000004, "ARGP_KEY_HELP_EXTRA"},
    {0x2000005, "ARGP_KEY_HELP_DUP_ARGS_NOTE"},
    {0x2000006, "ARGP_KEY_HELP_ARGS_DOC"}
};

const defines_map argp_parse_flag = {
    {0x01, "ARGP_PARSE_ARGV0"},
    {0x02, "ARGP_NO_ERRS"},
    {0x04, "ARGP_NO_ARGS"},
    {0x08, "ARGP_IN_ORDER"},
    {0x10, "ARGP_NO_HELP"},
    {0x20, "ARGP_NO_EXIT"},
    {0x40, "ARGP_LONG_ONLY"},
    {(0x20 | 0x02 | 0x10), "ARGP_SILENT"}
};

const defines_map argp_help_flag = {
    {0x01, "ARGP_HELP_USAGE"},
    {0x02, "ARGP_HELP_SHORT_USAGE"},
    {0x04, "ARGP_HELP_SEE"},
    {0x08, "ARGP_HELP_LONG"},
    {0x10, "ARGP_HELP_PRE_DOC"},
    {0x20, "ARGP_HELP_POST_DOC"},
    {(0x10 | 0x20), "ARGP_HELP_DOC"},
    {0x40, "ARGP_HELP_BUG_ADDR"},
    {0x80, "ARGP_HELP_LONG_ONLY"},
    {0x100, "ARGP_HELP_EXIT_ERR"},
    {0x200, "ARGP_HELP_EXIT_OK"},
    {(0x04 | 0x100), "ARGP_HELP_STD_ERR"},
    {(0x02 | 0x04 | 0x100), "ARGP_HELP_STD_USAGE"},
    {(0x02 | 0x08 | 0x200 | (0x10 | 0x20) | 0x40), "ARGP_HELP_STD_HELP"}
};

template <typename T>
std::string print_argp_option(const T v)
{
    return print_or_enum_entries(v, argp_option);
}

template <typename T>
std::string print_argp_err_unknown(const T v)
{
    auto ret = print_or_enum_entries(v, argp_err_unknown);
    if (ret == std::to_string(v))
        ret = print_errno_base_error<T>(v);
    return ret;
}

template <typename T>
std::string print_argp_key(const T v)
{
    return print_or_enum_entries(v, argp_key);
}

template <typename T>
std::string print_argp_key_help(const T v)
{
    return print_or_enum_entries(v, argp_key_help);
}

template <typename T>
std::string print_argp_option_key(const T v)
{
    return print_or_enum_entries(v, argp_key, argp_key_help);
}

template <typename T>
std::string print_argp_parse_flag(const T v)
{
    return print_or_enum_entries(v, argp_parse_flag);
}

template <typename T>
std::string print_argp_help_flag(const T v)
{
    return print_or_enum_entries(v, argp_help_flag);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, struct argp_option>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.name, "name", &os));

    auto printer = new ArgPrinter(obj.key, "key", &os);
    printer->set_enum_printer(print_argp_option_key, obj.key);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.arg, "arg", &os));

    auto printer1 = new ArgPrinter(obj.flags, "flags", &os);
    printer1->set_enum_printer(print_argp_option, obj.flags);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.doc, "doc", &os));
    abii_args->push_arg(new ArgPrinter(obj.group, "group", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, argp_child>
std::ostream& operator<<(std::ostream& os, T&& obj);

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, argp>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.options, "options", &os);
    printer->set_end_test([obj](const size_t i) { return obj.options[i].name != nullptr || obj.options[i].key != 0; });
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.parser, "parser", &os));
    abii_args->push_arg(new ArgPrinter(obj.args_doc, "args_doc", &os));
    abii_args->push_arg(new ArgPrinter(obj.doc, "doc", &os));

    auto printer1 = new ArgPrinter(obj.children, "children", &os);
    printer1->set_end_test([obj](const size_t i) { return obj.children[i].argp != nullptr; });
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.help_filter, "help_filter", &os));
    abii_args->push_arg(new ArgPrinter(obj.argp_domain, "argp_domain", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, argp_child>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.argp, "argp", &os));

    auto printer = new ArgPrinter(obj.flags, "flags", &os);
    printer->set_enum_printer(print_argp_option, obj.flags);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.header, "header", &os));
    abii_args->push_arg(new ArgPrinter(obj.group, "group", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, argp_state>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.root_argp, "root_argp", &os));
    abii_args->push_arg(new ArgPrinter(obj.argc, "argc", &os));

    auto printer = new ArgPrinter(obj.argv, "argv", &os);
    printer->set_len(obj.argc);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.next, "next", &os));

    auto printer1 = new ArgPrinter(obj.flags, "flags", &os);
    printer1->set_enum_printer(print_argp_parse_flag, obj.flags);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.arg_num, "arg_num", &os));
    abii_args->push_arg(new ArgPrinter(obj.quoted, "quoted", &os));
    abii_args->push_arg(new ArgPrinter(obj.input, "input", &os));

    auto nchildren = 0;
    if (bomb_detector(obj.root_argp) && bomb_detector(obj.root_argp->children))
        for (auto child = obj.root_argp->children; bomb_detector(child->argp); ++child)
            nchildren++;
    auto printer2 = new ArgPrinter(obj.child_inputs, "child_inputs", &os);
    printer2->set_len(nchildren);
    abii_args->push_arg(printer2);

    abii_args->push_arg(new ArgPrinter(obj.hook, "hook", &os));
    abii_args->push_arg(new ArgPrinter(obj.name, "name", &os));
    abii_args->push_arg(new ArgPrinter(obj.err_stream, "err_stream", &os));
    abii_args->push_arg(new ArgPrinter(obj.out_stream, "out_stream", &os));
    abii_args->push_arg(new ArgPrinter(obj.pstate, "pstate", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_ARGP_H
