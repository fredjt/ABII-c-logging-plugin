//
// Created by Trent Tanchin on 7/22/24.
//

#include <abii/libabii.h>

#include "asm-generic/errno-base.h"

namespace abii
{
static void (*real___assert_fail)(const char*, const char*, unsigned int, const char*) __THROW = nullptr;

extern "C" __attribute__ ((__noreturn__))
void abii___assert_fail(const char* assertion, const char* file, unsigned int line, const char* function) __THROW
{
    OVERRIDE_PREFIX(__assert_fail)
        pre_fmtd_str str = "__assert_fail(__assertion, __file, __line, __function)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(assertion, "__assertion"));
        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(line, "__line"));
        abii_args->push_arg(new ArgPrinter(function, "__function"));

        abii_args->print_args();
        abii_stream << std::endl;

        real___assert_fail(assertion, file, line, function);
    }
    if (real___assert_fail == nullptr)
    {
        real___assert_fail = reinterpret_cast<decltype(real___assert_fail)>(dlsym(RTLD_NEXT, "__assert_fail"));
        if (real___assert_fail == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real___assert_fail(assertion, file, line, function);
}

static void (*real___assert_perror_fail)(int, const char*, unsigned int, const char*) __THROW = nullptr;

extern "C" __attribute__ ((__noreturn__))
void abii___assert_perror_fail(int errnum, const char* file, unsigned int line, const char* function) __THROW
{
    OVERRIDE_PREFIX(__assert_perror_fail)
        pre_fmtd_str str = "__assert_perror_fail(__errnum, __file, __line, __function)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = ArgPrinter(errnum, "__errnum");
        printer.set_enum_printer(print_errno_base_error, errnum);
        abii_args->push_arg(&printer);

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(line, "__line"));
        abii_args->push_arg(new ArgPrinter(function, "__function"));

        abii_args->print_args();
        abii_stream << std::endl;

        real___assert_perror_fail(errnum, file, line, function);
    }
    if (real___assert_perror_fail == nullptr)
    {
        real___assert_perror_fail = reinterpret_cast<decltype(real___assert_perror_fail)>(dlsym(
            RTLD_NEXT, "__assert_perror_fail"));
        if (real___assert_perror_fail == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real___assert_perror_fail(errnum, file, line, function);
}

static void (*real___assert)(const char*, const char*, int) __THROW = nullptr;

extern "C" __attribute__ ((__noreturn__))
void abii___assert(const char* assertion, const char* file, int line) __THROW
{
    OVERRIDE_PREFIX(__assert)
        pre_fmtd_str str = "__assert(__assertion, __file, __line)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(assertion, "__assertion"));
        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(line, "__line"));

        abii_args->print_args();
        abii_stream << std::endl;

        real___assert(assertion, file, line);
    }
    if (real___assert == nullptr)
    {
        real___assert = reinterpret_cast<decltype(real___assert)>(dlsym(RTLD_NEXT, "__assert"));
        if (real___assert == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real___assert(assertion, file, line);
}
}
