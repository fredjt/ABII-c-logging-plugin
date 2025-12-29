//
// Created by Trent Tanchin on 12/27/25.
//

#include "inttypes.h"

#include "stdint.h"

namespace abii
{
static intmax_t (*real_imaxabs)(intmax_t) __THROW = nullptr;

extern "C" __attribute__ ((__const__))
intmax_t abii_imaxabs(intmax_t n) __THROW
{
    OVERRIDE_PREFIX(imaxabs)
        pre_fmtd_str str = "imaxabs(__n)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(n, "__n");
        printer->set_enum_printer(print_stdint_intmax, n);
        abii_args->push_arg(printer);

        auto abii_ret = real_imaxabs(n);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_stdint_intmax, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(imaxabs, abii_ret)
    return real_imaxabs(n);
}

static imaxdiv_t (*real_imaxdiv)(intmax_t, intmax_t) __THROW = nullptr;

extern "C" __attribute__ ((__const__))
imaxdiv_t abii_imaxdiv(intmax_t numer, intmax_t denom) __THROW
{
    OVERRIDE_PREFIX(imaxdiv)
        pre_fmtd_str str = "imaxdiv(__numer, __denom)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(numer, "__numer"));
        abii_args->push_arg(new ArgPrinter(denom, "__denom"));

        auto abii_ret = real_imaxdiv(numer, denom);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(imaxdiv, abii_ret)
    return real_imaxdiv(numer, denom);
}

static intmax_t (*real_strtoimax)(const char*, char**, int) __THROW = nullptr;

extern "C" intmax_t abii_strtoimax(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(strtoimax)
        pre_fmtd_str str = "strtoimax(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_strtoimax(nptr, endptr, base);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdint_intmax, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(strtoimax, abii_ret)
    return real_strtoimax(nptr, endptr, base);
}

static uintmax_t (*real_strtoumax)(const char*, char**, int) __THROW = nullptr;

extern "C" uintmax_t abii_strtoumax(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(strtoumax)
        pre_fmtd_str str = "strtoumax(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_strtoumax(nptr, endptr, base);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdint_uintmax, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(strtoumax, abii_ret)
    return real_strtoumax(nptr, endptr, base);
}

static intmax_t (*real_wcstoimax)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" intmax_t abii_wcstoimax(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(wcstoimax)
        pre_fmtd_str str = "wcstoimax(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(nptr, "__nptr");
        printer->set_enum_printer_with_depth(print_stdint_wchar, *nptr, 1);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(endptr, "__endptr");
        printer1->set_enum_printer_with_depth(print_stdint_wchar, **endptr, 1);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_wcstoimax(nptr, endptr, base);

        auto printer2 = new ArgPrinter(abii_ret, "return");
        printer2->set_enum_printer(print_stdint_intmax, abii_ret);
        abii_args->push_return(printer2);
    OVERRIDE_SUFFIX(wcstoimax, abii_ret)
    return real_wcstoimax(nptr, endptr, base);
}

static uintmax_t (*real_wcstoumax)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" uintmax_t abii_wcstoumax(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(wcstoumax)
        pre_fmtd_str str = "wcstoumax(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(nptr, "__nptr");
        printer->set_enum_printer_with_depth(print_stdint_wchar, *nptr, 1);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(endptr, "__endptr");
        printer1->set_enum_printer_with_depth(print_stdint_wchar, **endptr, 1);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_wcstoumax(nptr, endptr, base);

        auto printer2 = new ArgPrinter(abii_ret, "return");
        printer2->set_enum_printer(print_stdint_uintmax, abii_ret);
        abii_args->push_return(printer2);
    OVERRIDE_SUFFIX(wcstoumax, abii_ret)
    return real_wcstoumax(nptr, endptr, base);
}

static intmax_t (*real___isoc23_strtoimax)(const char*, char**, int) __THROW = nullptr;

extern "C" intmax_t abii___isoc23_strtoimax(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtoimax)
        pre_fmtd_str str = "__isoc23_strtoimax(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_strtoimax(nptr, endptr, base);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdint_intmax, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(__isoc23_strtoimax, abii_ret)
    return real___isoc23_strtoimax(nptr, endptr, base);
}

static uintmax_t (*real___isoc23_strtoumax)(const char*, char**, int) __THROW = nullptr;

extern "C" uintmax_t abii___isoc23_strtoumax(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtoumax)
        pre_fmtd_str str = "__isoc23_strtoumax(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_strtoumax(nptr, endptr, base);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdint_uintmax, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(__isoc23_strtoumax, abii_ret)
    return real___isoc23_strtoumax(nptr, endptr, base);
}

static intmax_t (*real___isoc23_wcstoimax)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" intmax_t abii___isoc23_wcstoimax(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstoimax)
        pre_fmtd_str str = "__isoc23_wcstoimax(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(nptr, "__nptr");
        printer->set_enum_printer_with_depth(print_stdint_wchar, *nptr, 1);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(endptr, "__endptr");
        printer1->set_enum_printer_with_depth(print_stdint_wchar, **endptr, 1);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_wcstoimax(nptr, endptr, base);

        auto printer2 = new ArgPrinter(abii_ret, "return");
        printer2->set_enum_printer(print_stdint_intmax, abii_ret);
        abii_args->push_return(printer2);
    OVERRIDE_SUFFIX(__isoc23_wcstoimax, abii_ret)
    return real___isoc23_wcstoimax(nptr, endptr, base);
}

static uintmax_t (*real___isoc23_wcstoumax)(const wchar_t*, wchar_t**, int) __THROW = nullptr;

extern "C" uintmax_t abii___isoc23_wcstoumax(const wchar_t* nptr, wchar_t** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_wcstoumax)
        pre_fmtd_str str = "__isoc23_wcstoumax(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(nptr, "__nptr");
        printer->set_enum_printer_with_depth(print_stdint_wchar, *nptr, 1);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(endptr, "__endptr");
        printer1->set_enum_printer_with_depth(print_stdint_wchar, **endptr, 1);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_wcstoumax(nptr, endptr, base);

        auto printer2 = new ArgPrinter(abii_ret, "return");
        printer2->set_enum_printer(print_stdint_uintmax, abii_ret);
        abii_args->push_return(printer2);
    OVERRIDE_SUFFIX(__isoc23_wcstoumax, abii_ret)
    return real___isoc23_wcstoumax(nptr, endptr, base);
}
}
