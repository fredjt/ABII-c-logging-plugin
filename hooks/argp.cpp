//
// Created by Trent Tanchin on 7/4/24.
//

#include "argp.h"

#include "custom_printers.h"

namespace abii
{
static error_t (*real_argp_parse)(const argp*, int, char**, unsigned, int*, void*) = nullptr;

extern "C" error_t abii_argp_parse(const argp* argp, int argc, char** argv, unsigned flags, int* arg_index, void* input)
{
    OVERRIDE_PREFIX(argp_parse)
        pre_fmtd_str str = "argp_parse(__argp, __argc, __argv, __flags, __arg_index, __input)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argp, "__argp"));
        abii_args->push_arg(new ArgPrinter(argc, "__argc"));

        auto printer = ArgPrinter(argv, "__argv");
        printer.set_len(argc);
        abii_args->push_arg(&printer);

        auto printer1 = ArgPrinter(flags, "__flags");
        printer1.set_enum_printer(print_argp_parse_flag, flags);
        abii_args->push_arg(&printer1);

        abii_args->push_arg(new ArgPrinter(arg_index, "__arg_index"));
        abii_args->push_arg(new ArgPrinter(input, "__input"));

        auto abii_ret = real_argp_parse(argp, argc, argv, flags, arg_index, input);

        auto printer2 = ArgPrinter(abii_ret, "return");;
        printer2.set_enum_printer(print_argp_err_unknown, abii_ret);
        abii_args->push_return(&printer2);
    OVERRIDE_SUFFIX(argp_parse, abii_ret)
    return real_argp_parse(argp, argc, argv, flags, arg_index, input);
}

static void (*real_argp_help)(const argp*, FILE*, unsigned, char*) = nullptr;

extern "C" void abii_argp_help(const argp* argp, FILE* stream, unsigned flags, char* name)
{
    OVERRIDE_PREFIX(argp_help)
        pre_fmtd_str str = "argp_help(__argp, __stream, __flags, __name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(argp, "__argp"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto printer = ArgPrinter(flags, "__flags");
        printer.set_enum_printer(print_argp_help_flag, flags);
        abii_args->push_arg(&printer);

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        real_argp_help(argp, stream, flags, name);
    OVERRIDE_SUFFIX(argp_help,)
    return real_argp_help(argp, stream, flags, name);
}

static void (*real_argp_state_help)(const argp_state*, FILE*, unsigned int) = nullptr;

extern "C" void abii_argp_state_help(const argp_state* state, FILE* stream, unsigned int flags)
{
    OVERRIDE_PREFIX(argp_state_help)
        pre_fmtd_str str = "argp_state_help(__state, __stream, __flags)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(state, "__state"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto printer = ArgPrinter(flags, "__flags");
        printer.set_enum_printer(print_argp_help_flag, flags);
        abii_args->push_arg(&printer);

        real_argp_state_help(state, stream, flags);
    OVERRIDE_SUFFIX(argp_state_help,)
    return real_argp_state_help(state, stream, flags);
}

static void (*real_argp_usage)(const argp_state*) = nullptr;

extern "C" void abii_argp_usage(const argp_state* state)
{
    OVERRIDE_PREFIX(argp_usage)
        pre_fmtd_str str = "argp_usage(__state)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(state, "__state"));

        abii_args->print_args();

        real_argp_usage(state);
    OVERRIDE_SUFFIX(argp_usage,)
    return real_argp_usage(state);
}

static void (*real_argp_error)(const argp_state*, const char*, ...) = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 2, 3)))
void abii_argp_error(const argp_state* state, const char* fmt, ...)
{
    OVERRIDE_VARIADIC_PREFIX(argp_error, fmt)
        pre_fmtd_str str = "argp_error(__state, __fmt, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(state, "__state"));
        abii_args->push_arg(new ArgPrinter(fmt, "__fmt"));
        PUSH_VARIADIC_ARGS(printer, fmt, print_variadic_args_printf)

        va_start(abii_vargs, fmt);
        abii_args->print_args();
        va_end(abii_vargs);

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_argp_error), abii_bi_vargs, 1000);
    OVERRIDE_VARIADIC_SUFFIX(argp_error, abii_ret, fmt)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_argp_error), abii_bi_vargs, 1000));
}

static void (*real_argp_failure)(const argp_state*, int, int, const char*, ...) = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 4, 5)))
void abii_argp_failure(const argp_state* state, int status, int errnum, const char* fmt, ...)
{
    OVERRIDE_VARIADIC_PREFIX(argp_failure, fmt)
        pre_fmtd_str str = "argp_failure(__state, __status, __errnum, __fmt, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(state, "__state"));
        abii_args->push_arg(new ArgPrinter(status, "__status"));
        abii_args->push_arg(new ArgPrinter(errnum, "__errnum"));
        abii_args->push_arg(new ArgPrinter(fmt, "__fmt"));
        PUSH_VARIADIC_ARGS(printer, fmt, print_variadic_args_printf)

        va_start(abii_vargs, fmt);
        abii_args->print_args();
        va_end(abii_vargs);

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_argp_failure), abii_bi_vargs, 1000);
    OVERRIDE_VARIADIC_SUFFIX(argp_failure, abii_ret, fmt)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_argp_failure), abii_bi_vargs, 1000));
}
}
