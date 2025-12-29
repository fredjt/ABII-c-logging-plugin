//
// Created by Trent Tanchin on 6/1/25.
//

#include "stdio_ext.h"

#include "stdint.h"

namespace abii
{
static size_t (*real___fbufsize)(FILE*) __THROW = nullptr;

extern "C" size_t abii___fbufsize(FILE* fp) __THROW
{
    OVERRIDE_PREFIX(__fbufsize)
        pre_fmtd_str pi_str = "__fbufsize(__fp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        auto abii_ret = real___fbufsize(fp);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdint_size, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(__fbufsize, abii_ret)
    return real___fbufsize(fp);
}

static int (*real___freading)(FILE*) __THROW = nullptr;

extern "C" int abii___freading(FILE* fp) __THROW
{
    OVERRIDE_PREFIX(__freading)
        pre_fmtd_str pi_str = "__freading(__fp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        auto abii_ret = real___freading(fp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__freading, abii_ret)
    return real___freading(fp);
}

static int (*real___fwriting)(FILE*) __THROW = nullptr;

extern "C" int abii___fwriting(FILE* fp) __THROW
{
    OVERRIDE_PREFIX(__fwriting)
        pre_fmtd_str pi_str = "__fwriting(__fp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        auto abii_ret = real___fwriting(fp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__fwriting, abii_ret)
    return real___fwriting(fp);
}

static int (*real___freadable)(FILE*) __THROW = nullptr;

extern "C" int abii___freadable(FILE* fp) __THROW
{
    OVERRIDE_PREFIX(__freadable)
        pre_fmtd_str pi_str = "__freadable(__fp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        auto abii_ret = real___freadable(fp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__freadable, abii_ret)
    return real___freadable(fp);
}

static int (*real___fwritable)(FILE*) __THROW = nullptr;

extern "C" int abii___fwritable(FILE* fp) __THROW
{
    OVERRIDE_PREFIX(__fwritable)
        pre_fmtd_str pi_str = "__fwritable(__fp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        auto abii_ret = real___fwritable(fp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__fwritable, abii_ret)
    return real___fwritable(fp);
}

static int (*real___flbf)(FILE*) __THROW = nullptr;

extern "C" int abii___flbf(FILE* fp) __THROW
{
    OVERRIDE_PREFIX(__flbf)
        pre_fmtd_str pi_str = "__flbf(__fp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        auto abii_ret = real___flbf(fp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__flbf, abii_ret)
    return real___flbf(fp);
}

static void (*real___fpurge)(FILE*) __THROW = nullptr;

extern "C" void abii___fpurge(FILE* fp) __THROW
{
    OVERRIDE_PREFIX(__fpurge)
        pre_fmtd_str pi_str = "__fpurge(__fp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        real___fpurge(fp);
    OVERRIDE_SUFFIX(__fpurge,)
    return real___fpurge(fp);
}

static size_t (*real___fpending)(FILE*) __THROW = nullptr;

extern "C" size_t abii___fpending(FILE* fp) __THROW
{
    OVERRIDE_PREFIX(__fpending)
        pre_fmtd_str pi_str = "__fpending(__fp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        auto abii_ret = real___fpending(fp);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdint_size, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(__fpending, abii_ret)
    return real___fpending(fp);
}

static void (*real__flushlbf)() = nullptr;

extern "C" void abii__flushlbf()
{
    OVERRIDE_PREFIX(_flushlbf)
        pre_fmtd_str pi_str = "_flushlbf()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real__flushlbf();
    OVERRIDE_SUFFIX(_flushlbf,)
    return real__flushlbf();
}

static int (*real___fsetlocking)(FILE*, int) __THROW = nullptr;

extern "C" int abii___fsetlocking(FILE* fp, int type) __THROW
{
    OVERRIDE_PREFIX(__fsetlocking)
        pre_fmtd_str pi_str = "__fsetlocking(__fp, __type)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        auto printer = new ArgPrinter(type, "__type");
        printer->set_enum_printer(print_stdio_ext_fsetlocking_type, type);
        abii_args->push_arg(printer);

        auto abii_ret = real___fsetlocking(fp, type);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__fsetlocking, abii_ret)
    return real___fsetlocking(fp, type);
}
}
