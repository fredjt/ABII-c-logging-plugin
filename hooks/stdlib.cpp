//
// Created by Trent Tanchin on 11/18/25.
//

#include "stdlib.h"

#include <bits/types/once_flag.h>

#include "bits/fcntl-linux.h"
#include "bits/thread-shared-types.h"
#include "bits/types/__locale_t.h"

namespace abii
{
static __wur size_t (*real___ctype_get_mb_cur_max)() __THROW = nullptr;

extern "C" __wur
size_t abii___ctype_get_mb_cur_max() __THROW
{
    OVERRIDE_PREFIX(__ctype_get_mb_cur_max)
        pre_fmtd_str pi_str = "__ctype_get_mb_cur_max()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real___ctype_get_mb_cur_max();

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdlib_enum3, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(__ctype_get_mb_cur_max, abii_ret)
    return real___ctype_get_mb_cur_max();
}

static __attribute_pure__ __nonnull((1)) __wur double (*real_atof)(const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1)) __wur
double abii_atof(const char* nptr) __THROW
{
    OVERRIDE_PREFIX(atof)
        pre_fmtd_str pi_str = "atof(__nptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));

        auto abii_ret = real_atof(nptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(atof, abii_ret)
    return real_atof(nptr);
}

static __attribute_pure__ __nonnull((1)) __wur int (*real_atoi)(const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1)) __wur
int abii_atoi(const char* nptr) __THROW
{
    OVERRIDE_PREFIX(atoi)
        pre_fmtd_str pi_str = "atoi(__nptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));

        auto abii_ret = real_atoi(nptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(atoi, abii_ret)
    return real_atoi(nptr);
}

static __attribute_pure__ __nonnull((1)) __wur long int (*real_atol)(const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1)) __wur
long int abii_atol(const char* nptr) __THROW
{
    OVERRIDE_PREFIX(atol)
        pre_fmtd_str pi_str = "atol(__nptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));

        auto abii_ret = real_atol(nptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(atol, abii_ret)
    return real_atol(nptr);
}

static __attribute_pure__ __nonnull((1)) __wur long long int (*real_atoll)(const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1)) __wur
long long int abii_atoll(const char* nptr) __THROW
{
    OVERRIDE_PREFIX(atoll)
        pre_fmtd_str pi_str = "atoll(__nptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));

        auto abii_ret = real_atoll(nptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(atoll, abii_ret)
    return real_atoll(nptr);
}

static __nonnull((1)) double (*real_strtod)(const char*, char**) __THROW = nullptr;

extern "C" __nonnull((1))
double abii_strtod(const char* nptr, char** endptr) __THROW
{
    OVERRIDE_PREFIX(strtod)
        pre_fmtd_str pi_str = "strtod(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_strtod(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtod, abii_ret)
    return real_strtod(nptr, endptr);
}

static __nonnull((1)) float (*real_strtof)(const char*, char**) __THROW = nullptr;

extern "C" __nonnull((1))
float abii_strtof(const char* nptr, char** endptr) __THROW
{
    OVERRIDE_PREFIX(strtof)
        pre_fmtd_str pi_str = "strtof(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_strtof(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof, abii_ret)
    return real_strtof(nptr, endptr);
}

static __nonnull((1)) long double (*real_strtold)(const char*, char**) __THROW = nullptr;

extern "C" __nonnull((1))
long double abii_strtold(const char* nptr, char** endptr) __THROW
{
    OVERRIDE_PREFIX(strtold)
        pre_fmtd_str pi_str = "strtold(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_strtold(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtold, abii_ret)
    return real_strtold(nptr, endptr);
}

static __nonnull((1)) _Float16 (*real_strtof16)(const char*, char**) __THROW = nullptr;

extern "C" __nonnull((1))
_Float16 abii_strtof16(const char* nptr, char** endptr) __THROW
{
    OVERRIDE_PREFIX(strtof16)
        pre_fmtd_str pi_str = "strtof16(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_strtof16(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof16, abii_ret)
    return real_strtof16(nptr, endptr);
}

static __nonnull((1)) _Float32 (*real_strtof32)(const char*, char**) __THROW = nullptr;

extern "C" __nonnull((1))
_Float32 abii_strtof32(const char* nptr, char** endptr) __THROW
{
    OVERRIDE_PREFIX(strtof32)
        pre_fmtd_str pi_str = "strtof32(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_strtof32(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof32, abii_ret)
    return real_strtof32(nptr, endptr);
}

static __nonnull((1)) _Float64 (*real_strtof64)(const char*, char**) __THROW = nullptr;

extern "C" __nonnull((1))
_Float64 abii_strtof64(const char* nptr, char** endptr) __THROW
{
    OVERRIDE_PREFIX(strtof64)
        pre_fmtd_str pi_str = "strtof64(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_strtof64(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof64, abii_ret)
    return real_strtof64(nptr, endptr);
}

static __nonnull((1)) _Float128 (*real_strtof128)(const char*, char**) __THROW = nullptr;

extern "C" __nonnull((1))
_Float128 abii_strtof128(const char* nptr, char** endptr) __THROW
{
    OVERRIDE_PREFIX(strtof128)
        pre_fmtd_str pi_str = "strtof128(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_strtof128(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof128, abii_ret)
    return real_strtof128(nptr, endptr);
}

static __nonnull((1)) _Float32x (*real_strtof32x)(const char*, char**) __THROW = nullptr;

extern "C" __nonnull((1))
_Float32x abii_strtof32x(const char* nptr, char** endptr) __THROW
{
    OVERRIDE_PREFIX(strtof32x)
        pre_fmtd_str pi_str = "strtof32x(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_strtof32x(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof32x, abii_ret)
    return real_strtof32x(nptr, endptr);
}

static __nonnull((1)) _Float64x (*real_strtof64x)(const char*, char**) __THROW = nullptr;

extern "C" __nonnull((1))
_Float64x abii_strtof64x(const char* nptr, char** endptr) __THROW
{
    OVERRIDE_PREFIX(strtof64x)
        pre_fmtd_str pi_str = "strtof64x(__nptr, __endptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));

        auto abii_ret = real_strtof64x(nptr, endptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof64x, abii_ret)
    return real_strtof64x(nptr, endptr);
}

static __nonnull((1)) long int (*real_strtol)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
long int abii_strtol(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(strtol)
        pre_fmtd_str pi_str = "strtol(__nptr, __endptr, base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_strtol(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtol, abii_ret)
    return real_strtol(nptr, endptr, base);
}

static __nonnull((1)) unsigned long int (*real_strtoul)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
unsigned long int abii_strtoul(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(strtoul)
        pre_fmtd_str pi_str = "strtoul(__nptr, __endptr, base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_strtoul(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtoul, abii_ret)
    return real_strtoul(nptr, endptr, base);
}

static __nonnull((1)) long long int (*real_strtoq)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
long long int abii_strtoq(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(strtoq)
        pre_fmtd_str pi_str = "strtoq(__nptr, __endptr, base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_strtoq(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtoq, abii_ret)
    return real_strtoq(nptr, endptr, base);
}

static __nonnull((1)) unsigned long long int (*real_strtouq)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
unsigned long long int abii_strtouq(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(strtouq)
        pre_fmtd_str pi_str = "strtouq(__nptr, __endptr, base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_strtouq(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtouq, abii_ret)
    return real_strtouq(nptr, endptr, base);
}

static __nonnull((1)) long long int (*real_strtoll)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
long long int abii_strtoll(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(strtoll)
        pre_fmtd_str pi_str = "strtoll(__nptr, __endptr, base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_strtoll(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtoll, abii_ret)
    return real_strtoll(nptr, endptr, base);
}

static __nonnull((1)) unsigned long long int (*real_strtoull)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
unsigned long long int abii_strtoull(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(strtoull)
        pre_fmtd_str pi_str = "strtoull(__nptr, __endptr, base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_strtoull(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtoull, abii_ret)
    return real_strtoull(nptr, endptr, base);
}

static __nonnull((1)) long int (*real___isoc23_strtol)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
long int abii___isoc23_strtol(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtol)
        pre_fmtd_str pi_str = "__isoc23_strtol(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_strtol(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_strtol, abii_ret)
    return real___isoc23_strtol(nptr, endptr, base);
}

static __nonnull((1)) unsigned long int (*real___isoc23_strtoul)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
unsigned long int abii___isoc23_strtoul(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtoul)
        pre_fmtd_str pi_str = "__isoc23_strtoul(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_strtoul(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_strtoul, abii_ret)
    return real___isoc23_strtoul(nptr, endptr, base);
}

static __nonnull((1)) long long int (*real___isoc23_strtoll)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
long long int abii___isoc23_strtoll(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtoll)
        pre_fmtd_str pi_str = "__isoc23_strtoll(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_strtoll(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_strtoll, abii_ret)
    return real___isoc23_strtoll(nptr, endptr, base);
}

static __nonnull((1)) unsigned long long int (*real___isoc23_strtoull)(const char*, char**, int) __THROW = nullptr;

extern "C" __nonnull((1))
unsigned long long int abii___isoc23_strtoull(const char* nptr, char** endptr, int base) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtoull)
        pre_fmtd_str pi_str = "__isoc23_strtoull(__nptr, __endptr, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real___isoc23_strtoull(nptr, endptr, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_strtoull, abii_ret)
    return real___isoc23_strtoull(nptr, endptr, base);
}

static __nonnull((3)) int (*real_strfromd)(char*, size_t, const char*, double) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_strfromd(char* dest, size_t size, const char* format, double f) __THROW
{
    OVERRIDE_PREFIX(strfromd)
        pre_fmtd_str pi_str = "strfromd(__dest, __size, __format, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_strfromd(dest, size, format, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfromd, abii_ret)
    return real_strfromd(dest, size, format, f);
}

static __nonnull((3)) int (*real_strfromf)(char*, size_t, const char*, float) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_strfromf(char* dest, size_t size, const char* format, float f) __THROW
{
    OVERRIDE_PREFIX(strfromf)
        pre_fmtd_str pi_str = "strfromf(__dest, __size, __format, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_strfromf(dest, size, format, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfromf, abii_ret)
    return real_strfromf(dest, size, format, f);
}

static __nonnull((3)) int (*real_strfroml)(char*, size_t, const char*, long double) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_strfroml(char* dest, size_t size, const char* format, long double f) __THROW
{
    OVERRIDE_PREFIX(strfroml)
        pre_fmtd_str pi_str = "strfroml(__dest, __size, __format, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_strfroml(dest, size, format, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfroml, abii_ret)
    return real_strfroml(dest, size, format, f);
}

static __nonnull((3)) int (*real_strfromf16)(char*, size_t, const char*, _Float16) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_strfromf16(char* dest, size_t size, const char* format, _Float16 f) __THROW
{
    OVERRIDE_PREFIX(strfromf16)
        pre_fmtd_str pi_str = "strfromf16(__dest, __size, __format, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_strfromf16(dest, size, format, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfromf16, abii_ret)
    return real_strfromf16(dest, size, format, f);
}

static __nonnull((3)) int (*real_strfromf32)(char*, size_t, const char*, _Float32) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_strfromf32(char* dest, size_t size, const char* format, _Float32 f) __THROW
{
    OVERRIDE_PREFIX(strfromf32)
        pre_fmtd_str pi_str = "strfromf32(__dest, __size, __format, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_strfromf32(dest, size, format, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfromf32, abii_ret)
    return real_strfromf32(dest, size, format, f);
}

static __nonnull((3)) int (*real_strfromf64)(char*, size_t, const char*, _Float64) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_strfromf64(char* dest, size_t size, const char* format, _Float64 f) __THROW
{
    OVERRIDE_PREFIX(strfromf64)
        pre_fmtd_str pi_str = "strfromf64(__dest, __size, __format, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_strfromf64(dest, size, format, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfromf64, abii_ret)
    return real_strfromf64(dest, size, format, f);
}

static __nonnull((3)) int (*real_strfromf128)(char*, size_t, const char*, _Float128) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_strfromf128(char* dest, size_t size, const char* format, _Float128 f) __THROW
{
    OVERRIDE_PREFIX(strfromf128)
        pre_fmtd_str pi_str = "strfromf128(__dest, __size, __format, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_strfromf128(dest, size, format, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfromf128, abii_ret)
    return real_strfromf128(dest, size, format, f);
}

static __nonnull((3)) int (*real_strfromf32x)(char*, size_t, const char*, _Float32x __f) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_strfromf32x(char* dest, size_t size, const char* format, _Float32x f) __THROW
{
    OVERRIDE_PREFIX(strfromf32x)
        pre_fmtd_str pi_str = "strfromf32x(__dest, __size, __format, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_strfromf32x(dest, size, format, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfromf32x, abii_ret)
    return real_strfromf32x(dest, size, format, f);
}

static __nonnull((3)) int (*real_strfromf64x)(char*, size_t, const char*, _Float64x) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_strfromf64x(char* dest, size_t size, const char* format, _Float64x f) __THROW
{
    OVERRIDE_PREFIX(strfromf64x)
        pre_fmtd_str pi_str = "strfromf64x(__dest, __size, __format, __f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(dest, "__dest"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_strfromf64x(dest, size, format, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strfromf64x, abii_ret)
    return real_strfromf64x(dest, size, format, f);
}

static __nonnull((1, 4)) long int (*real_strtol_l)(const char*, char**, int, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 4))
long int abii_strtol_l(const char* nptr, char** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtol_l)
        pre_fmtd_str pi_str = "strtol_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtol_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtol_l, abii_ret)
    return real_strtol_l(nptr, endptr, base, loc);
}

static __nonnull((1, 4)) unsigned long int (*real_strtoul_l)(const char*, char**, int, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 4))
unsigned long int abii_strtoul_l(const char* nptr, char** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtoul_l)
        pre_fmtd_str pi_str = "strtoul_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtoul_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtoul_l, abii_ret)
    return real_strtoul_l(nptr, endptr, base, loc);
}

static __nonnull((1, 4)) long long int (*real_strtoll_l)(const char*, char**, int, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 4))
long long int abii_strtoll_l(const char* nptr, char** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtoll_l)
        pre_fmtd_str pi_str = "strtoll_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtoll_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtoll_l, abii_ret)
    return real_strtoll_l(nptr, endptr, base, loc);
}

static __nonnull((1, 4)) unsigned long long int (*real_strtoull_l)(const char*, char**, int, locale_t) __THROW =
    nullptr;

extern "C" __nonnull((1, 4))
unsigned long long int abii_strtoull_l(const char* nptr, char** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtoull_l)
        pre_fmtd_str pi_str = "strtoull_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtoull_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtoull_l, abii_ret)
    return real_strtoull_l(nptr, endptr, base, loc);
}

static __nonnull((1, 4)) long int (*real___isoc23_strtol_l)(const char*, char**, int, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 4))
long int abii___isoc23_strtol_l(const char* nptr, char** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtol_l)
        pre_fmtd_str pi_str = "__isoc23_strtol_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real___isoc23_strtol_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_strtol_l, abii_ret)
    return real___isoc23_strtol_l(nptr, endptr, base, loc);
}

static __nonnull((1, 4)) unsigned long int (*real___isoc23_strtoul_l)(const char*, char**, int, locale_t) __THROW =
    nullptr;

extern "C" __nonnull((1, 4))
unsigned long int abii___isoc23_strtoul_l(const char* nptr, char** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtoul_l)
        pre_fmtd_str pi_str = "__isoc23_strtoul_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real___isoc23_strtoul_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_strtoul_l, abii_ret)
    return real___isoc23_strtoul_l(nptr, endptr, base, loc);
}

static __nonnull((1, 4)) long long int (*real___isoc23_strtoll_l)(const char*, char**, int, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 4))
long long int abii___isoc23_strtoll_l(const char* nptr, char** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtoll_l)
        pre_fmtd_str pi_str = "__isoc23_strtoll_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real___isoc23_strtoll_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_strtoll_l, abii_ret)
    return real___isoc23_strtoll_l(nptr, endptr, base, loc);
}

static __nonnull((1, 4)) unsigned long long int (*real___isoc23_strtoull_l)(const char*, char**, int, locale_t) __THROW
    = nullptr;

extern "C" __nonnull((1, 4))
unsigned long long int abii___isoc23_strtoull_l(const char* nptr, char** endptr, int base, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(__isoc23_strtoull_l)
        pre_fmtd_str pi_str = "__isoc23_strtoull_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real___isoc23_strtoull_l(nptr, endptr, base, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__isoc23_strtoull_l, abii_ret)
    return real___isoc23_strtoull_l(nptr, endptr, base, loc);
}

static __nonnull((1, 3)) double (*real_strtod_l)(const char*, char**, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
double abii_strtod_l(const char* nptr, char** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtod_l)
        pre_fmtd_str pi_str = "strtod_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtod_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtod_l, abii_ret)
    return real_strtod_l(nptr, endptr, loc);
}

static __nonnull((1, 3)) float (*real_strtof_l)(const char*, char**, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
float abii_strtof_l(const char* nptr, char** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtof_l)
        pre_fmtd_str pi_str = "strtof_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtof_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof_l, abii_ret)
    return real_strtof_l(nptr, endptr, loc);
}

static __nonnull((1, 3)) long double (*real_strtold_l)(const char*, char**, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
long double abii_strtold_l(const char* nptr, char** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtold_l)
        pre_fmtd_str pi_str = "strtold_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtold_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtold_l, abii_ret)
    return real_strtold_l(nptr, endptr, loc);
}

static __nonnull((1, 3)) _Float16 (*real_strtof16_l)(const char*, char**, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
_Float16 abii_strtof16_l(const char* nptr, char** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtof16_l)
        pre_fmtd_str pi_str = "strtof16_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtof16_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof16_l, abii_ret)
    return real_strtof16_l(nptr, endptr, loc);
}

static __nonnull((1, 3)) _Float32 (*real_strtof32_l)(const char*, char**, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
_Float32 abii_strtof32_l(const char* nptr, char** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtof32_l)
        pre_fmtd_str pi_str = "strtof32_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtof32_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof32_l, abii_ret)
    return real_strtof32_l(nptr, endptr, loc);
}

static __nonnull((1, 3)) _Float64 (*real_strtof64_l)(const char*, char**, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
_Float64 abii_strtof64_l(const char* nptr, char** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtof64_l)
        pre_fmtd_str pi_str = "strtof64_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtof64_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof64_l, abii_ret)
    return real_strtof64_l(nptr, endptr, loc);
}

static __nonnull((1, 3)) _Float128 (*real_strtof128_l)(const char*, char**, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
_Float128 abii_strtof128_l(const char* nptr, char** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtof128_l)
        pre_fmtd_str pi_str = "strtof128_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtof128_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof128_l, abii_ret)
    return real_strtof128_l(nptr, endptr, loc);
}

static __nonnull((1, 3)) _Float32x (*real_strtof32x_l)(const char*, char**, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
_Float32x abii_strtof32x_l(const char* nptr, char** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtof32x_l)
        pre_fmtd_str pi_str = "strtof32x_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtof32x_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof32x_l, abii_ret)
    return real_strtof32x_l(nptr, endptr, loc);
}

static __nonnull((1, 3)) _Float64x (*real_strtof64x_l)(const char*, char**, locale_t) __THROW = nullptr;

extern "C" __nonnull((1, 3))
_Float64x abii_strtof64x_l(const char* nptr, char** endptr, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strtof64x_l)
        pre_fmtd_str pi_str = "strtof64x_l(__nptr, __endptr, __base, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nptr, "__nptr"));
        abii_args->push_arg(new ArgPrinter(endptr, "__endptr"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strtof64x_l(nptr, endptr, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strtof64x_l, abii_ret)
    return real_strtof64x_l(nptr, endptr, loc);
}

static __wur char* (*real_l64a)(long int) __THROW = nullptr;

extern "C" __wur
char* abii_l64a(long int n) __THROW
{
    OVERRIDE_PREFIX(l64a)
        pre_fmtd_str pi_str = "l64a(__n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_l64a(n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(l64a, abii_ret)
    return real_l64a(n);
}

static __attribute_pure__ __nonnull((1)) __wur long int (*real_a64l)(const char*) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1)) __wur
long int abii_a64l(const char* s) __THROW
{
    OVERRIDE_PREFIX(a64l)
        pre_fmtd_str pi_str = "a64l(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_a64l(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(a64l, abii_ret)
    return real_a64l(s);
}

static long int (*real_random)() __THROW = nullptr;

extern "C" long int abii_random() __THROW
{
    OVERRIDE_PREFIX(random)
        pre_fmtd_str pi_str = "random()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_random();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(random, abii_ret)
    return real_random();
}

static void (*real_srandom)(unsigned int) __THROW = nullptr;

extern "C" void abii_srandom(unsigned int seed) __THROW
{
    OVERRIDE_PREFIX(srandom)
        pre_fmtd_str pi_str = "srandom(__seed)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seed, "__seed"));

        real_srandom(seed);
    OVERRIDE_SUFFIX(srandom,)
    return real_srandom(seed);
}

static __nonnull((2)) char* (*real_initstate)(unsigned int, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((2))
char* abii_initstate(unsigned int seed, char* statebuf, size_t statelen) __THROW
{
    OVERRIDE_PREFIX(initstate)
        pre_fmtd_str pi_str = "initstate(__seed, __statebuf, __statelen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seed, "__seed"));

        auto printer = new ArgPrinter(statebuf, "__statebuf");
        printer->set_len(statelen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(statelen, "__statelen"));

        auto abii_ret = real_initstate(seed, statebuf, statelen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(initstate, abii_ret)
    return real_initstate(seed, statebuf, statelen);
}

static __nonnull((1)) char* (*real_setstate)(char*) __THROW = nullptr;

extern "C" __nonnull((1))
char* abii_setstate(char* statebuf) __THROW
{
    OVERRIDE_PREFIX(setstate)
        pre_fmtd_str pi_str = "setstate(__statebuf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(statebuf, "__statebuf"));

        auto abii_ret = real_setstate(statebuf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setstate, abii_ret)
    return real_setstate(statebuf);
}

static __nonnull((1, 2)) int (*real_random_r)(random_data*, int32_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_random_r(random_data* buf, int32_t* result) __THROW
{
    OVERRIDE_PREFIX(random_r)
        pre_fmtd_str pi_str = "random_r(__buf, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buf, "__buf"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_random_r(buf, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(random_r, abii_ret)
    return real_random_r(buf, result);
}

static __nonnull((2)) int (*real_srandom_r)(unsigned int seed, random_data*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_srandom_r(unsigned int seed, random_data* buf) __THROW
{
    OVERRIDE_PREFIX(srandom_r)
        pre_fmtd_str pi_str = "srandom_r(__seed, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seed, "__seed"));
        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        auto abii_ret = real_srandom_r(seed, buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(srandom_r, abii_ret)
    return real_srandom_r(seed, buf);
}

static __nonnull((2, 4)) int (*real_initstate_r)(unsigned int, char*, size_t, random_data*) __THROW = nullptr;

extern "C" __nonnull((2, 4))
int abii_initstate_r(unsigned int seed, char* statebuf, size_t statelen,
                     random_data* buf) __THROW
{
    OVERRIDE_PREFIX(initstate_r)
        pre_fmtd_str pi_str = "initstate_r(__seed, __statebuf, __statelen, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seed, "__seed"));

        auto printer = new ArgPrinter(statebuf, "__statebuf");
        printer->set_len(statelen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(statelen, "__statelen"));

        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        auto abii_ret = real_initstate_r(seed, statebuf, statelen, buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(initstate_r, abii_ret)
    return real_initstate_r(seed, statebuf, statelen, buf);
}

static __nonnull((1, 2)) int (*real_setstate_r)(char*, random_data*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_setstate_r(char* statebuf, random_data* buf) __THROW
{
    OVERRIDE_PREFIX(setstate_r)
        pre_fmtd_str pi_str = "setstate_r(__statebuf, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(statebuf, "__statebuf"));
        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        auto abii_ret = real_setstate_r(statebuf, buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setstate_r, abii_ret)
    return real_setstate_r(statebuf, buf);
}

static int (*real_rand)() __THROW = nullptr;

extern "C" int abii_rand() __THROW
{
    OVERRIDE_PREFIX(rand)
        pre_fmtd_str pi_str = "rand()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_rand();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rand, abii_ret)
    return real_rand();
}

static void (*real_srand)(unsigned int) __THROW = nullptr;

extern "C" void abii_srand(unsigned int seed) __THROW
{
    OVERRIDE_PREFIX(srand)
        pre_fmtd_str pi_str = "srand(__seed)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seed, "__seed"));

        real_srand(seed);
    OVERRIDE_SUFFIX(srand,)
    return real_srand(seed);
}

static int (*real_rand_r)(unsigned int*) __THROW = nullptr;

extern "C" int abii_rand_r(unsigned int* seed) __THROW
{
    OVERRIDE_PREFIX(rand_r)
        pre_fmtd_str pi_str = "rand_r(__seed)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seed, "__seed"));

        auto abii_ret = real_rand_r(seed);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rand_r, abii_ret)
    return real_rand_r(seed);
}

static double (*real_drand48)() __THROW = nullptr;

extern "C" double abii_drand48() __THROW
{
    OVERRIDE_PREFIX(drand48)
        pre_fmtd_str pi_str = "drand48()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_drand48();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(drand48, abii_ret)
    return real_drand48();
}

static __nonnull((1)) double (*real_erand48)(unsigned short int [3]) __THROW = nullptr;

extern "C" __nonnull((1))
double abii_erand48(unsigned short int xsubi[3]) __THROW
{
    OVERRIDE_PREFIX(erand48)
        pre_fmtd_str pi_str = "erand48(__xsubi)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(xsubi, "__xsubi"));

        auto abii_ret = real_erand48(xsubi);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(erand48, abii_ret)
    return real_erand48(xsubi);
}

static long int (*real_lrand48)() __THROW = nullptr;

extern "C" long int abii_lrand48() __THROW
{
    OVERRIDE_PREFIX(lrand48)
        pre_fmtd_str pi_str = "lrand48()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_lrand48();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lrand48, abii_ret)
    return real_lrand48();
}

static __nonnull((1)) long int (*real_nrand48)(unsigned short int [3]) __THROW = nullptr;

extern "C" __nonnull((1))
long int abii_nrand48(unsigned short int xsubi[3]) __THROW
{
    OVERRIDE_PREFIX(nrand48)
        pre_fmtd_str pi_str = "nrand48(__xsubi)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(xsubi, "__xsubi"));

        auto abii_ret = real_nrand48(xsubi);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(nrand48, abii_ret)
    return real_nrand48(xsubi);
}

static long int (*real_mrand48)() __THROW = nullptr;

extern "C" long int abii_mrand48() __THROW
{
    OVERRIDE_PREFIX(mrand48)
        pre_fmtd_str pi_str = "mrand48()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_mrand48();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mrand48, abii_ret)
    return real_mrand48();
}

static __nonnull((1)) long int (*real_jrand48)(unsigned short int [3]) __THROW = nullptr;

extern "C" __nonnull((1))
long int abii_jrand48(unsigned short int xsubi[3]) __THROW
{
    OVERRIDE_PREFIX(jrand48)
        pre_fmtd_str pi_str = "jrand48(__xsubi)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(xsubi, "__xsubi"));

        auto abii_ret = real_jrand48(xsubi);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(jrand48, abii_ret)
    return real_jrand48(xsubi);
}

static void (*real_srand48)(long int) __THROW = nullptr;

extern "C" void abii_srand48(long int seedval) __THROW
{
    OVERRIDE_PREFIX(srand48)
        pre_fmtd_str pi_str = "srand48(__seedval)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seedval, "__seedval"));

        real_srand48(seedval);
    OVERRIDE_SUFFIX(srand48,)
    return real_srand48(seedval);
}

static __nonnull((1)) unsigned short int* (*real_seed48)(unsigned short int [3]) __THROW = nullptr;

extern "C" __nonnull((1))
unsigned short int* abii_seed48(unsigned short int seed16v[3]) __THROW
{
    OVERRIDE_PREFIX(seed48)
        pre_fmtd_str pi_str = "seed48(__seed16v)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seed16v, "__seed16v"));

        auto abii_ret = real_seed48(seed16v);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(seed48, abii_ret)
    return real_seed48(seed16v);
}

static __nonnull((1)) void (*real_lcong48)(unsigned short int [7]) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_lcong48(unsigned short int param[7]) __THROW
{
    OVERRIDE_PREFIX(lcong48)
        pre_fmtd_str pi_str = "lcong48(__param)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(param, "__param"));

        real_lcong48(param);
    OVERRIDE_SUFFIX(lcong48,)
    return real_lcong48(param);
}

static __nonnull((1, 2)) int (*real_drand48_r)(drand48_data*, double*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_drand48_r(drand48_data* buffer, double* result) __THROW
{
    OVERRIDE_PREFIX(drand48_r)
        pre_fmtd_str pi_str = "drand48_r(__buffer, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_drand48_r(buffer, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(drand48_r, abii_ret)
    return real_drand48_r(buffer, result);
}

static __nonnull((1, 2)) int (*real_erand48_r)(unsigned short int [3], drand48_data*, double*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_erand48_r(unsigned short int xsubi[3], drand48_data* buffer, double* result) __THROW
{
    OVERRIDE_PREFIX(erand48_r)
        pre_fmtd_str pi_str = "erand48_r(__xsubi, __buffer, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(xsubi, "__xsubi"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_erand48_r(xsubi, buffer, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(erand48_r, abii_ret)
    return real_erand48_r(xsubi, buffer, result);
}

static __nonnull((1, 2)) int (*real_lrand48_r)(drand48_data*, long int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_lrand48_r(drand48_data* buffer, long int* result) __THROW
{
    OVERRIDE_PREFIX(lrand48_r)
        pre_fmtd_str pi_str = "lrand48_r(__buffer, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_lrand48_r(buffer, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lrand48_r, abii_ret)
    return real_lrand48_r(buffer, result);
}

static __nonnull((1, 2)) int (*real_nrand48_r)(unsigned short int [3], drand48_data*, long int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_nrand48_r(unsigned short int xsubi[3], drand48_data* buffer, long int* result) __THROW
{
    OVERRIDE_PREFIX(nrand48_r)
        pre_fmtd_str pi_str = "nrand48_r(__xsubi, __buffer, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(xsubi, "__xsubi"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_nrand48_r(xsubi, buffer, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(nrand48_r, abii_ret)
    return real_nrand48_r(xsubi, buffer, result);
}

static __nonnull((1, 2)) int (*real_mrand48_r)(drand48_data*, long int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_mrand48_r(drand48_data* buffer, long int* result) __THROW
{
    OVERRIDE_PREFIX(mrand48_r)
        pre_fmtd_str pi_str = "mrand48_r(__buffer, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_mrand48_r(buffer, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mrand48_r, abii_ret)
    return real_mrand48_r(buffer, result);
}

static __nonnull((1, 2)) int (*real_jrand48_r)(unsigned short int [3], drand48_data*, long int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_jrand48_r(unsigned short int xsubi[3], drand48_data* buffer, long int* result) __THROW
{
    OVERRIDE_PREFIX(jrand48_r)
        pre_fmtd_str pi_str = "jrand48_r(__xsubi, __buffer, __result)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(xsubi, "__xsubi"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_jrand48_r(xsubi, buffer, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(jrand48_r, abii_ret)
    return real_jrand48_r(xsubi, buffer, result);
}

static __nonnull((2)) int (*real_srand48_r)(long int, drand48_data*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_srand48_r(long int seedval, drand48_data* buffer) __THROW
{
    OVERRIDE_PREFIX(srand48_r)
        pre_fmtd_str pi_str = "srand48_r(__seedval, __buffer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seedval, "__seedval"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        auto abii_ret = real_srand48_r(seedval, buffer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(srand48_r, abii_ret)
    return real_srand48_r(seedval, buffer);
}

static __nonnull((1, 2)) int (*real_seed48_r)(unsigned short int [3], drand48_data*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_seed48_r(unsigned short int seed16v[3], drand48_data* buffer) __THROW
{
    OVERRIDE_PREFIX(seed48_r)
        pre_fmtd_str pi_str = "seed48_r(__seed16v, __buffer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(seed16v, "__seed16v"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        auto abii_ret = real_seed48_r(seed16v, buffer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(seed48_r, abii_ret)
    return real_seed48_r(seed16v, buffer);
}

static __nonnull((1, 2)) int (*real_lcong48_r)(unsigned short int [7], drand48_data*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_lcong48_r(unsigned short int param[7], drand48_data* buffer) __THROW
{
    OVERRIDE_PREFIX(lcong48_r)
        pre_fmtd_str pi_str = "lcong48_r(__param, __buffer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(param, "__param"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        auto abii_ret = real_lcong48_r(param, buffer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lcong48_r, abii_ret)
    return real_lcong48_r(param, buffer);
}

static __wur __uint32_t (*real_arc4random)() __THROW = nullptr;

extern "C" __wur
__uint32_t abii_arc4random() __THROW
{
    OVERRIDE_PREFIX(arc4random)
        pre_fmtd_str pi_str = "arc4random()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_arc4random();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(arc4random, abii_ret)
    return real_arc4random();
}

static __nonnull((1)) void (*real_arc4random_buf)(void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_arc4random_buf(void* buf, size_t size) __THROW
{
    OVERRIDE_PREFIX(arc4random_buf)
        pre_fmtd_str pi_str = "arc4random_buf(__buf, __size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(size);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        real_arc4random_buf(buf, size);
    OVERRIDE_SUFFIX(arc4random_buf,)
    return real_arc4random_buf(buf, size);
}

static __wur __uint32_t (*real_arc4random_uniform)(__uint32_t) __THROW = nullptr;

extern "C" __wur
__uint32_t abii_arc4random_uniform(__uint32_t upper_bound) __THROW
{
    OVERRIDE_PREFIX(arc4random_uniform)
        pre_fmtd_str pi_str = "arc4random_uniform(__upper_bound)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(upper_bound, "__upper_bound"));

        auto abii_ret = real_arc4random_uniform(upper_bound);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(arc4random_uniform, abii_ret)
    return real_arc4random_uniform(upper_bound);
}

extern "C" __attribute_malloc__ __attribute_alloc_size__((1)) __wur
void* abii_malloc(size_t size) __THROW;

extern "C" __attribute_malloc__ __attribute_alloc_size__((1, 2)) __wur
void* abii_calloc(size_t nmemb, size_t size) __THROW;

extern "C" __attribute_warn_unused_result__ __attribute_alloc_size__((2))
void* abii_realloc(void* ptr, size_t size) __THROW;

extern "C" void abii_free(void* ptr) __THROW;

static void (*real_free_sized)(void*, size_t) __THROW = nullptr;

extern "C" void abii_free_sized(void* ptr, size_t size) __THROW
{
    OVERRIDE_PREFIX(free_sized)
        pre_fmtd_str pi_str = "free_sized(__ptr, __size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(ptr, "__ptr");
        printer->set_len(size);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        real_free_sized(ptr, size);
    OVERRIDE_SUFFIX(free_sized,)
    return real_free_sized(ptr, size);
}

static void (*real_free_aligned_sized)(void*, size_t, size_t) __THROW = nullptr;

extern "C" void abii_free_aligned_sized(void* ptr, size_t alignment, size_t size) __THROW
{
    OVERRIDE_PREFIX(free_aligned_sized)
        pre_fmtd_str pi_str = "free_aligned_sized(__ptr, __alignment, __size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(ptr, "__ptr");
        printer->set_len(size);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(alignment, "__alignment"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));

        real_free_aligned_sized(ptr, alignment, size);
    OVERRIDE_SUFFIX(free_aligned_sized,)
    return real_free_aligned_sized(ptr, alignment, size);
}

extern "C" __attribute_warn_unused_result__ __attribute_alloc_size__((2, 3)) __attr_dealloc_free
void* abii_reallocarray(void* ptr, size_t nmemb, size_t size) __THROW;

extern "C" __attr_dealloc(reallocarray, 1)
void* abii_reallocarray(void* ptr, size_t nmemb, size_t size) __THROW;

extern "C" __attribute_malloc__ __attribute_alloc_size__((1)) __wur
void* abii_valloc(size_t size) __THROW;

static __nonnull((1)) __wur int (*real_posix_memalign)(void**, size_t, size_t) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii_posix_memalign(void** memptr, size_t alignment, size_t size) __THROW
{
    OVERRIDE_PREFIX(posix_memalign)
        pre_fmtd_str pi_str = "posix_memalign(__memptr, __alignment, __size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(memptr, "__memptr");
        printer->set_len(size);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(alignment, "__alignment"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_posix_memalign(memptr, alignment, size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_memalign, abii_ret)
    return real_posix_memalign(memptr, alignment, size);
}

static __attribute_malloc__ __attribute_alloc_align__((1)) __attribute_alloc_size__((2)) __wur
void* (*real_aligned_alloc)(size_t, size_t) __THROW = nullptr;

extern "C" __attribute_malloc__ __attribute_alloc_align__((1)) __attribute_alloc_size__((2)) __wur
void* abii_aligned_alloc(size_t alignment, size_t size) __THROW
{
    OVERRIDE_PREFIX(aligned_alloc)
        pre_fmtd_str pi_str = "aligned_alloc(__alignment, __size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(alignment, "__alignment"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_aligned_alloc(alignment, size);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_len(size);
        abii_args->push_return(printer);

    OVERRIDE_SUFFIX(aligned_alloc, abii_ret)
    return real_aligned_alloc(alignment, size);
}

static __attribute__((__noreturn__)) __COLD void (*real_abort)() __THROW = nullptr;

extern "C" __attribute__((__noreturn__)) __COLD
void abii_abort() __THROW
{
    OVERRIDE_PREFIX(abort)
        pre_fmtd_str pi_str = "abort()";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        real_abort();
    }
    if (real_abort == nullptr)
    {
        real_abort = reinterpret_cast<decltype(real_abort)>(dlsym(RTLD_NEXT, "abort"));
        if (real_abort == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real_abort();
}

static __nonnull((1)) int (*real_atexit)(void (*)()) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_atexit(void (*func)()) __THROW
{
    OVERRIDE_PREFIX(atexit)
        pre_fmtd_str pi_str = "atexit(__func)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(func, "__func"));

        auto abii_ret = real_atexit(func);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(atexit, abii_ret)
    return real_atexit(func);
}

static __nonnull((1)) int (*real_at_quick_exit)(void (*)()) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_at_quick_exit(void (*func)()) __THROW
{
    OVERRIDE_PREFIX(at_quick_exit)
        pre_fmtd_str pi_str = "at_quick_exit(__func)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(func, "__func"));

        auto abii_ret = real_at_quick_exit(func);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(at_quick_exit, abii_ret)
    return real_at_quick_exit(func);
}

static __nonnull((1)) int (*real_on_exit)(void (*)(int, void*), void*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_on_exit(void (*func)(int, void*), void* arg) __THROW
{
    OVERRIDE_PREFIX(on_exit)
        pre_fmtd_str pi_str = "on_exit(__func, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(func, "__func"));
        abii_args->push_arg(new ArgPrinter(arg, "__arg"));

        auto abii_ret = real_on_exit(func, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(on_exit, abii_ret)
    return real_on_exit(func, arg);
}

static __attribute__((__noreturn__)) void (*real_exit)(int) __THROW = nullptr;

extern "C" __attribute__((__noreturn__))
void abii_exit(int status) __THROW
{
    OVERRIDE_PREFIX(exit)
        pre_fmtd_str pi_str = "exit(__status)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        real_exit(status);
    }
    if (real_exit == nullptr)
    {
        real_exit = reinterpret_cast<decltype(real_exit)>(dlsym(RTLD_NEXT, "exit"));
        if (real_exit == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real_exit(status);
}

static __attribute__((__noreturn__)) void (*real_quick_exit)(int) __THROW = nullptr;

extern "C" __attribute__((__noreturn__))
void abii_quick_exit(int status) __THROW
{
    OVERRIDE_PREFIX(quick_exit)
        pre_fmtd_str pi_str = "quick_exit(__status)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        real_quick_exit(status);
    }
    if (real_quick_exit == nullptr)
    {
        real_quick_exit = reinterpret_cast<decltype(real_quick_exit)>(dlsym(RTLD_NEXT, "quick_exit"));
        if (real_quick_exit == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real_quick_exit(status);
}

static __attribute__((__noreturn__)) void (*real__Exit)(int) __THROW = nullptr;

extern "C" __attribute__((__noreturn__))
void abii__Exit(int status) __THROW
{
    OVERRIDE_PREFIX(_Exit)
        pre_fmtd_str pi_str = "_Exit(__status)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(status, "__status"));

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        real__Exit(status);
    }
    if (real__Exit == nullptr)
    {
        real__Exit = reinterpret_cast<decltype(real__Exit)>(dlsym(RTLD_NEXT, "quick_exit"));
        if (real__Exit == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real__Exit(status);
}

static __nonnull((1)) __wur char* (*real_getenv)(const char*) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
char* abii_getenv(const char* name) __THROW
{
    OVERRIDE_PREFIX(getenv)
        pre_fmtd_str pi_str = "getenv(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getenv(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getenv, abii_ret)
    return real_getenv(name);
}

static __nonnull((1)) __wur char* (*real_secure_getenv)(const char*) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
char* abii_secure_getenv(const char* name) __THROW
{
    OVERRIDE_PREFIX(secure_getenv)
        pre_fmtd_str pi_str = "secure_getenv(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_secure_getenv(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(secure_getenv, abii_ret)
    return real_secure_getenv(name);
}

static __nonnull((1)) int (*real_putenv)(char*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_putenv(char* string) __THROW
{
    OVERRIDE_PREFIX(putenv)
        pre_fmtd_str pi_str = "putenv(__string)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));

        auto abii_ret = real_putenv(string);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(putenv, abii_ret)
    return real_putenv(string);
}

static __nonnull((2)) int (*real_setenv)(const char*, const char*, int) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_setenv(const char* name, const char* value, int replace) __THROW
{
    OVERRIDE_PREFIX(setenv)
        pre_fmtd_str pi_str = "setenv(__name, __value, __replace)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(replace, "__replace"));

        auto abii_ret = real_setenv(name, value, replace);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setenv, abii_ret)
    return real_setenv(name, value, replace);
}

static __nonnull((1)) int (*real_unsetenv)(const char*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_unsetenv(const char* name) __THROW
{
    OVERRIDE_PREFIX(unsetenv)
        pre_fmtd_str pi_str = "unsetenv(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_unsetenv(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(unsetenv, abii_ret)
    return real_unsetenv(name);
}

static int (*real_clearenv)() __THROW = nullptr;

extern "C" int abii_clearenv() __THROW
{
    OVERRIDE_PREFIX(clearenv)
        pre_fmtd_str pi_str = "clearenv()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_clearenv();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(clearenv, abii_ret)
    return real_clearenv();
}

static __nonnull((1)) char* (*real_mktemp)(char*) __THROW = nullptr;

extern "C" __nonnull((1))
char* abii_mktemp(char* _template) __THROW
{
    OVERRIDE_PREFIX(mktemp)
        pre_fmtd_str pi_str = "mktemp(__template)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));

        auto abii_ret = real_mktemp(_template);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mktemp, abii_ret)
    return real_mktemp(_template);
}

static __nonnull((1)) __wur int (*real_mkstemp)(char*) = nullptr;

extern "C" __nonnull((1)) __wur
int abii_mkstemp(char* _template)
{
    OVERRIDE_PREFIX(mkstemp)
        pre_fmtd_str pi_str = "mkstemp(__template)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));

        auto abii_ret = real_mkstemp(_template);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mkstemp, abii_ret)
    return real_mkstemp(_template);
}

static __nonnull((1)) __wur int (*real_mkstemp64)(char*) = nullptr;

extern "C" __nonnull((1)) __wur
int abii_mkstemp64(char* _template)
{
    OVERRIDE_PREFIX(mkstemp64)
        pre_fmtd_str pi_str = "mkstemp64(__template)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));

        auto abii_ret = real_mkstemp64(_template);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mkstemp64, abii_ret)
    return real_mkstemp64(_template);
}

static __nonnull((1)) __wur int (*real_mkstemps)(char*, int) = nullptr;

extern "C" __nonnull((1)) __wur
int abii_mkstemps(char* _template, int suffixlen)
{
    OVERRIDE_PREFIX(mkstemps)
        pre_fmtd_str pi_str = "mkstemps(__template)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));
        abii_args->push_arg(new ArgPrinter(suffixlen, "__suffixlen"));

        auto abii_ret = real_mkstemps(_template, suffixlen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mkstemps, abii_ret)
    return real_mkstemps(_template, suffixlen);
}

static __nonnull((1)) __wur int (*real_mkstemps64)(char*, int) = nullptr;

extern "C" __nonnull((1)) __wur
int abii_mkstemps64(char* _template, int suffixlen)
{
    OVERRIDE_PREFIX(mkstemps64)
        pre_fmtd_str pi_str = "mkstemps64(__template)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));
        abii_args->push_arg(new ArgPrinter(suffixlen, "__suffixlen"));

        auto abii_ret = real_mkstemps64(_template, suffixlen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mkstemps64, abii_ret)
    return real_mkstemps64(_template, suffixlen);
}

static __nonnull((1)) __wur char* (*real_mkdtemp)(char*) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
char* abii_mkdtemp(char* _template) __THROW
{
    OVERRIDE_PREFIX(mkdtemp)
        pre_fmtd_str pi_str = "mkdtemp(__template)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));

        auto abii_ret = real_mkdtemp(_template);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mkdtemp, abii_ret)
    return real_mkdtemp(_template);
}

static __nonnull((1)) __wur int (*real_mkostemp)(char*, int) = nullptr;

extern "C" __nonnull((1)) __wur
int abii_mkostemp(char* _template, int flags)
{
    OVERRIDE_PREFIX(mkostemp)
        pre_fmtd_str pi_str = "mkostemp(__template, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));

        auto printer = new ArgPrinter(flags);
        printer->set_enum_printer(print_fcntl_linux_oflag, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_mkostemp(_template, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mkostemp, abii_ret)
    return real_mkostemp(_template, flags);
}

static __nonnull((1)) __wur int (*real_mkostemp64)(char*, int) = nullptr;

extern "C" __nonnull((1)) __wur
int abii_mkostemp64(char* _template, int flags)
{
    OVERRIDE_PREFIX(mkostemp64)
        pre_fmtd_str pi_str = "mkostemp64(__template, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));

        auto printer = new ArgPrinter(flags);
        printer->set_enum_printer(print_fcntl_linux_oflag, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_mkostemp64(_template, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mkostemp64, abii_ret)
    return real_mkostemp64(_template, flags);
}

static __nonnull((1)) __wur int (*real_mkostemps)(char*, int, int) = nullptr;

extern "C" __nonnull((1)) __wur
int abii_mkostemps(char* _template, int suffixlen, int flags)
{
    OVERRIDE_PREFIX(mkostemps)
        pre_fmtd_str pi_str = "mkostemps(__template, __suffixlen, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));
        abii_args->push_arg(new ArgPrinter(_template, "__suffixlen"));

        auto printer = new ArgPrinter(flags);
        printer->set_enum_printer(print_fcntl_linux_oflag, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_mkostemps(_template, suffixlen, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mkostemps, abii_ret)
    return real_mkostemps(_template, suffixlen, flags);
}

static __nonnull((1)) __wur int (*real_mkostemps64)(char*, int, int) = nullptr;

extern "C" __nonnull((1)) __wur
int abii_mkostemps64(char* _template, int suffixlen, int flags)
{
    OVERRIDE_PREFIX(mkostemps64)
        pre_fmtd_str pi_str = "mkostemps64(__template, __suffixlen, __flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(_template, "__template"));
        abii_args->push_arg(new ArgPrinter(_template, "__suffixlen"));

        auto printer = new ArgPrinter(flags);
        printer->set_enum_printer(print_fcntl_linux_oflag, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_mkostemps64(_template, suffixlen, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mkostemps64, abii_ret)
    return real_mkostemps64(_template, suffixlen, flags);
}

static int (*real_system)(const char*) = nullptr;

extern "C" int abii_system(const char* command) __wur
{
    OVERRIDE_PREFIX(system)
        pre_fmtd_str pi_str = "system(__command)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(command, "__command"));

        auto abii_ret = real_system(command);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(system, abii_ret)
    return real_system(command);
}

static __nonnull((1)) __attribute_malloc__ __attr_dealloc_free __wur
char* (*real_canonicalize_file_name)(const char*) __THROW = nullptr;

extern "C" __nonnull((1)) __attribute_malloc__ __attr_dealloc_free __wur
char* abii_canonicalize_file_name(const char* name) __THROW
{
    OVERRIDE_PREFIX(canonicalize_file_name)
        pre_fmtd_str pi_str = "canonicalize_file_name(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_canonicalize_file_name(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(canonicalize_file_name, abii_ret)
    return real_canonicalize_file_name(name);
}

static __wur char* (*real_realpath)(const char*, char*) __THROW = nullptr;

extern "C" __wur
char* abii_realpath(const char* name, char* resolved) __THROW
{
    OVERRIDE_PREFIX(realpath)
        pre_fmtd_str pi_str = "realpath(__name, __resolved)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(resolved, "__resolved"));

        auto abii_ret = real_realpath(name, resolved);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(realpath, abii_ret)
    return real_realpath(name, resolved);
}

static __nonnull((1, 2, 5)) __wur
void* (*real_bsearch)(const void*, const void*, size_t, size_t, __compar_fn_t) = nullptr;

extern "C" __nonnull((1, 2, 5)) __wur
void* abii_bsearch(const void* key, const void* base, size_t nmemb, size_t size, __compar_fn_t compar)
{
    OVERRIDE_PREFIX(bsearch)
        pre_fmtd_str pi_str = "bsearch(__key, __base, __nmemb, __size, __compar)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key"));

        auto printer = new ArgPrinter(base, "__base");
        const auto base_sz = nmemb * size;
        printer->set_len(base_sz);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nmemb, "__nmemb"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(compar, "__compar"));

        auto abii_ret = real_bsearch(key, base, nmemb, size, compar);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_len(size);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(bsearch, abii_ret)
    return real_bsearch(key, base, nmemb, size, compar);
}

static __nonnull((1, 4)) void (*real_qsort)(void*, size_t, size_t, __compar_fn_t) = nullptr;

extern "C" __nonnull((1, 4))
void abii_qsort(void* base, size_t nmemb, size_t size, __compar_fn_t compar)
{
    OVERRIDE_PREFIX(qsort)
        pre_fmtd_str pi_str = "qsort(__base, __nmemb, __size, __compar)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(base, "__base");
        const auto base_sz = nmemb * size;
        printer->set_len(base_sz);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nmemb, "__nmemb"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(compar, "__compar"));

        real_qsort(base, nmemb, size, compar);
    OVERRIDE_SUFFIX(qsort,)
    return real_qsort(base, nmemb, size, compar);
}

static __nonnull((1, 4)) void (*real_qsort_r)(void*, size_t, size_t, __compar_d_fn_t, void*) = nullptr;

extern "C" __nonnull((1, 4))
void abii_qsort_r(void* base, size_t nmemb, size_t size, __compar_d_fn_t compar, void* arg)
{
    OVERRIDE_PREFIX(qsort_r)
        pre_fmtd_str pi_str = "qsort_r(__base, __nmemb, __size, __compar, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(base, "__base");
        const auto base_sz = nmemb * size;
        printer->set_len(base_sz);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nmemb, "__nmemb"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(compar, "__compar"));
        abii_args->push_arg(new ArgPrinter(arg, "__arg"));

        real_qsort_r(base, nmemb, size, compar, arg);
    OVERRIDE_SUFFIX(qsort_r,)
    return real_qsort_r(base, nmemb, size, compar, arg);
}

static __attribute__((__const__)) __wur int (*real_abs)(int) __THROW = nullptr;

extern "C" __attribute__((__const__)) __wur
int abii_abs(int x) __THROW
{
    OVERRIDE_PREFIX(abs)
        pre_fmtd_str pi_str = "abs(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_abs(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(abs, abii_ret)
    return real_abs(x);
}

static __attribute__((__const__)) __wur long int (*real_labs)(long int) __THROW = nullptr;

extern "C" __attribute__((__const__)) __wur
long int abii_labs(long int x) __THROW
{
    OVERRIDE_PREFIX(labs)
        pre_fmtd_str pi_str = "labs(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_labs(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(labs, abii_ret)
    return real_labs(x);
}

static __attribute__((__const__)) __wur long long int (*real_llabs)(long long int) __THROW = nullptr;

__extension__ extern "C" __attribute__((__const__)) __wur
long long int abii_llabs(long long int x) __THROW
{
    OVERRIDE_PREFIX(llabs)
        pre_fmtd_str pi_str = "llabs(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_llabs(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(llabs, abii_ret)
    return real_llabs(x);
}

static __attribute__((__const__)) __wur int (*real_uabs)(int) __THROW = nullptr;

extern "C" __attribute__((__const__)) __wur
unsigned int abii_uabs(int x) __THROW
{
    OVERRIDE_PREFIX(uabs)
        pre_fmtd_str pi_str = "uabs(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_uabs(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(uabs, abii_ret)
    return real_uabs(x);
}

static __attribute__((__const__)) __wur long int (*real_ulabs)(long int) __THROW = nullptr;

extern "C" __attribute__((__const__)) __wur
unsigned long int abii_ulabs(long int x) __THROW
{
    OVERRIDE_PREFIX(ulabs)
        pre_fmtd_str pi_str = "ulabs(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_ulabs(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ulabs, abii_ret)
    return real_ulabs(x);
}

static __attribute__((__const__)) __wur long long int (*real_ullabs)(long long int) __THROW = nullptr;

__extension__ extern "C" __attribute__((__const__)) __wur
unsigned long long int abii_ullabs(long long int x) __THROW
{
    OVERRIDE_PREFIX(ullabs)
        pre_fmtd_str pi_str = "ullabs(__x)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(x, "__x"));

        auto abii_ret = real_ullabs(x);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ullabs, abii_ret)
    return real_ullabs(x);
}

static __attribute__((__const__)) __wur div_t (*real_div)(int, int) __THROW = nullptr;

extern "C" __attribute__((__const__)) __wur
div_t abii_div(int numer, int denom) __THROW
{
    OVERRIDE_PREFIX(div)
        pre_fmtd_str pi_str = "div(__numer, __denom)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(numer, "__numer"));
        abii_args->push_arg(new ArgPrinter(denom, "__denom"));

        auto abii_ret = real_div(numer, denom);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(div, abii_ret)
    return real_div(numer, denom);
}

static __attribute__((__const__)) __wur ldiv_t (*real_ldiv)(long int, long int) __THROW = nullptr;

extern "C" __attribute__((__const__)) __wur
ldiv_t abii_ldiv(long int numer, long int denom) __THROW
{
    OVERRIDE_PREFIX(ldiv)
        pre_fmtd_str pi_str = "ldiv(__numer, __denom)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(numer, "__numer"));
        abii_args->push_arg(new ArgPrinter(denom, "__denom"));

        auto abii_ret = real_ldiv(numer, denom);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ldiv, abii_ret)
    return real_ldiv(numer, denom);
}

static __attribute__((__const__)) __wur lldiv_t (*real_lldiv)(long long int, long long int) __THROW = nullptr;

__extension__ extern "C" __attribute__((__const__)) __wur
lldiv_t abii_lldiv(long long int numer, long long int denom) __THROW
{
    OVERRIDE_PREFIX(lldiv)
        pre_fmtd_str pi_str = "lldiv(__numer, __denom)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(numer, "__numer"));
        abii_args->push_arg(new ArgPrinter(denom, "__denom"));

        auto abii_ret = real_lldiv(numer, denom);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lldiv, abii_ret)
    return real_lldiv(numer, denom);
}

static __nonnull((3, 4)) __wur char* (*real_ecvt)(double, int, int*, int*) __THROW = nullptr;

extern "C" __nonnull((3, 4)) __wur
char* abii_ecvt(double value, int ndigit, int* decpt, int* sign) __THROW
{
    OVERRIDE_PREFIX(ecvt)
        pre_fmtd_str pi_str = "ecvt(__value, __ndigit, __decpt, __sign)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(decpt, "__decpt"));
        abii_args->push_arg(new ArgPrinter(sign, "__sign"));

        auto abii_ret = real_ecvt(value, ndigit, decpt, sign);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ecvt, abii_ret)
    return real_ecvt(value, ndigit, decpt, sign);
}

static __nonnull((3, 4)) __wur char* (*real_fcvt)(double, int, int*, int*) __THROW = nullptr;

extern "C" __nonnull((3, 4)) __wur
char* abii_fcvt(double value, int ndigit, int* decpt, int* sign) __THROW
{
    OVERRIDE_PREFIX(fcvt)
        pre_fmtd_str pi_str = "fcvt(__value, __ndigit, __decpt, __sign)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(decpt, "__decpt"));
        abii_args->push_arg(new ArgPrinter(sign, "__sign"));

        auto abii_ret = real_fcvt(value, ndigit, decpt, sign);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fcvt, abii_ret)
    return real_fcvt(value, ndigit, decpt, sign);
}

static __nonnull((3)) __wur char* (*real_gcvt)(double, int, char*) __THROW = nullptr;

extern "C" __nonnull((3)) __wur
char* abii_gcvt(double value, int ndigit, char* buf) __THROW
{
    OVERRIDE_PREFIX(gcvt)
        pre_fmtd_str pi_str = "gcvt(__value, __ndigit, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        auto abii_ret = real_gcvt(value, ndigit, buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gcvt, abii_ret)
    return real_gcvt(value, ndigit, buf);
}

static __nonnull((3, 4)) __wur char* (*real_qecvt)(long double, int, int*, int*) __THROW = nullptr;

extern "C" __nonnull((3, 4)) __wur
char* abii_qecvt(long double value, int ndigit, int* decpt, int* sign) __THROW
{
    OVERRIDE_PREFIX(qecvt)
        pre_fmtd_str pi_str = "qecvt(__value, __ndigit, __decpt, __sign)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(decpt, "__decpt"));
        abii_args->push_arg(new ArgPrinter(sign, "__sign"));

        auto abii_ret = real_qecvt(value, ndigit, decpt, sign);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(qecvt, abii_ret)
    return real_qecvt(value, ndigit, decpt, sign);
}

static __nonnull((3, 4)) __wur char* (*real_qfcvt)(long double, int, int*, int*) __THROW = nullptr;

extern "C" __nonnull((3, 4)) __wur
char* abii_qfcvt(long double value, int ndigit, int* decpt, int* sign) __THROW
{
    OVERRIDE_PREFIX(qfcvt)
        pre_fmtd_str pi_str = "qfcvt(__value, __ndigit, __decpt, __sign)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(decpt, "__decpt"));
        abii_args->push_arg(new ArgPrinter(sign, "__sign"));

        auto abii_ret = real_qfcvt(value, ndigit, decpt, sign);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(qfcvt, abii_ret)
    return real_qfcvt(value, ndigit, decpt, sign);
}

static __nonnull((3)) __wur char* (*real_qgcvt)(long double, int, char*) __THROW = nullptr;

extern "C" __nonnull((3)) __wur
char* abii_qgcvt(long double value, int ndigit, char* buf) __THROW
{
    OVERRIDE_PREFIX(qgcvt)
        pre_fmtd_str pi_str = "qgcvt(__value, __ndigit, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        auto abii_ret = real_qgcvt(value, ndigit, buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(qgcvt, abii_ret)
    return real_qgcvt(value, ndigit, buf);
}

static __nonnull((3, 4, 5)) int (*real_ecvt_r)(double, int, int*, int*, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((3, 4, 5))
int abii_ecvt_r(double value, int ndigit, int* decpt, int* sign, char* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(ecvt_r)
        pre_fmtd_str pi_str = "ecvt_r(__value, __ndigit, __decpt, __sign, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(decpt, "__decpt"));
        abii_args->push_arg(new ArgPrinter(sign, "__sign"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_ecvt_r(value, ndigit, decpt, sign, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ecvt_r, abii_ret)
    return real_ecvt_r(value, ndigit, decpt, sign, buf, len);
}

static __nonnull((3, 4, 5)) int (*real_fcvt_r)(double, int, int*, int*, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((3, 4, 5))
int abii_fcvt_r(double value, int ndigit, int* decpt, int* sign, char* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(fcvt_r)
        pre_fmtd_str pi_str = "fcvt_r(__value, __ndigit, __decpt, __sign, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(decpt, "__decpt"));
        abii_args->push_arg(new ArgPrinter(sign, "__sign"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_fcvt_r(value, ndigit, decpt, sign, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fcvt_r, abii_ret)
    return real_fcvt_r(value, ndigit, decpt, sign, buf, len);
}

static __nonnull((3, 4, 5)) int (*real_qecvt_r)(long double, int, int*, int*, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((3, 4, 5))
int abii_qecvt_r(long double value, int ndigit, int* decpt, int* sign, char* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(qecvt_r)
        pre_fmtd_str pi_str = "qecvt_r(__value, __ndigit, __decpt, __sign, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(decpt, "__decpt"));
        abii_args->push_arg(new ArgPrinter(sign, "__sign"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_qecvt_r(value, ndigit, decpt, sign, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(qecvt_r, abii_ret)
    return real_qecvt_r(value, ndigit, decpt, sign, buf, len);
}

static __nonnull((3, 4, 5)) int (*real_qfcvt_r)(long double, int, int*, int*, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((3, 4, 5))
int abii_qfcvt_r(long double value, int ndigit, int* decpt, int* sign, char* buf, size_t len) __THROW
{
    OVERRIDE_PREFIX(qfcvt_r)
        pre_fmtd_str pi_str = "qfcvt_r(__value, __ndigit, __decpt, __sign, __buf, __len)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ndigit, "__ndigit"));
        abii_args->push_arg(new ArgPrinter(decpt, "__decpt"));
        abii_args->push_arg(new ArgPrinter(sign, "__sign"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(len, "__len"));

        auto abii_ret = real_qfcvt_r(value, ndigit, decpt, sign, buf, len);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(qfcvt_r, abii_ret)
    return real_qfcvt_r(value, ndigit, decpt, sign, buf, len);
}

static int (*real_mblen)(const char*, size_t) __THROW = nullptr;

extern "C" int abii_mblen(const char* s, size_t n) __THROW
{
    OVERRIDE_PREFIX(mblen)
        pre_fmtd_str pi_str = "mblen(__s, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_mblen(s, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mblen, abii_ret)
    return real_mblen(s, n);
}

static int (*real_mbtowc)(wchar_t*, const char*, size_t) __THROW = nullptr;

extern "C" int abii_mbtowc(wchar_t* pwc, const char* s, size_t n) __THROW
{
    OVERRIDE_PREFIX(mbtowc)
        pre_fmtd_str pi_str = "mbtowc(__pwc, __s, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pwc, "__pwc"));
        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_mbtowc(pwc, s, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbtowc, abii_ret)
    return real_mbtowc(pwc, s, n);
}

static int (*real_wctomb)(char*, wchar_t) __THROW = nullptr;

extern "C" int abii_wctomb(char* s, wchar_t wchar) __THROW
{
    OVERRIDE_PREFIX(wctomb)
        pre_fmtd_str pi_str = "wctomb(__s, __wchar)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(wchar, "__wchar"));

        auto abii_ret = real_wctomb(s, wchar);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wctomb, abii_ret)
    return real_wctomb(s, wchar);
}

static __attr_access((__read_only__, 2)) int (*real_mbstowcs)(wchar_t*, const char*, size_t) __THROW = nullptr;

extern "C" __attr_access((__read_only__, 2))
size_t abii_mbstowcs(wchar_t* pwcs, const char* s, size_t n) __THROW
{
    OVERRIDE_PREFIX(mbstowcs)
        pre_fmtd_str pi_str = "mbstowcs(__pwcs, __s, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pwcs, "__pwcs"));
        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_mbstowcs(pwcs, s, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mbstowcs, abii_ret)
    return real_mbstowcs(pwcs, s, n);
}

static __fortified_attr_access(__write_only__, 1, 3) __attr_access((__read_only__, 2))
size_t (*real_wcstombs)(char*, const wchar_t*, size_t) __THROW = nullptr;

extern "C" __fortified_attr_access(__write_only__, 1, 3) __attr_access((__read_only__, 2))
size_t abii_wcstombs(char* s, const wchar_t* pwcs, size_t n) __THROW
{
    OVERRIDE_PREFIX(wcstombs)
        pre_fmtd_str pi_str = "wcstombs(__s, __pwcs, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(pwcs, "__pwcs"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_wcstombs(s, pwcs, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(wcstombs, abii_ret)
    return real_wcstombs(s, pwcs, n);
}

static __nonnull((1)) __wur int (*real_rpmatch)(const char*) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii_rpmatch(const char* response) __THROW
{
    OVERRIDE_PREFIX(rpmatch)
        pre_fmtd_str pi_str = "rpmatch(__response)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(response, "__response"));

        auto abii_ret = real_rpmatch(response);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rpmatch, abii_ret)
    return real_rpmatch(response);
}

static __nonnull((1, 2, 3)) __wur int (*real_getsubopt)(char**, char* const*, char**) __THROW = nullptr;

extern "C" __nonnull((1, 2, 3)) __wur
int abii_getsubopt(char** optionp, char* const* tokens, char** valuep) __THROW
{
    OVERRIDE_PREFIX(getsubopt)
        pre_fmtd_str pi_str = "getsubopt(__optionp, __tokens, __valuep)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(optionp, "__optionp"));
        abii_args->push_arg(new ArgPrinter(tokens, "__tokens"));
        abii_args->push_arg(new ArgPrinter(valuep, "__valuep"));

        auto abii_ret = real_getsubopt(optionp, tokens, valuep);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getsubopt, abii_ret)
    return real_getsubopt(optionp, tokens, valuep);
}

static __wur int (*real_posix_openpt)(int) __THROW = nullptr;

extern "C" __wur
int abii_posix_openpt(int oflag)
{
    OVERRIDE_PREFIX(posix_openpt)
        pre_fmtd_str pi_str = "posix_openpt(__oflag)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        auto abii_ret = real_posix_openpt(oflag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(posix_openpt, abii_ret)
    return real_posix_openpt(oflag);
}

static int (*real_grantpt)(int) __THROW = nullptr;

extern "C" int abii_grantpt(int fd) __THROW
{
    OVERRIDE_PREFIX(grantpt)
        pre_fmtd_str pi_str = "grantpt(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto abii_ret = real_grantpt(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(grantpt, abii_ret)
    return real_grantpt(fd);
}

static int (*real_unlockpt)(int) __THROW = nullptr;

extern "C" int abii_unlockpt(int fd) __THROW
{
    OVERRIDE_PREFIX(unlockpt)
        pre_fmtd_str pi_str = "unlockpt(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto abii_ret = real_unlockpt(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(unlockpt, abii_ret)
    return real_unlockpt(fd);
}

static __wur char* (*real_ptsname)(int) __THROW = nullptr;

extern "C" __wur
char* abii_ptsname(int fd) __THROW
{
    OVERRIDE_PREFIX(ptsname)
        pre_fmtd_str pi_str = "ptsname(__fd)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto abii_ret = real_ptsname(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ptsname, abii_ret)
    return real_ptsname(fd);
}

static __nonnull((2)) __fortified_attr_access(__write_only__, 2, 3)
int (*real_ptsname_r)(int, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((2)) __fortified_attr_access(__write_only__, 2, 3)
int abii_ptsname_r(int fd, char* buf, size_t buflen) __THROW
{
    OVERRIDE_PREFIX(ptsname_r)
        pre_fmtd_str pi_str = "ptsname_r(__fd, __buf, __buflen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));

        auto abii_ret = real_ptsname_r(fd, buf, buflen);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ptsname_r, abii_ret)
    return real_ptsname_r(fd, buf, buflen);
}

static int (*real_getpt)() = nullptr;

extern "C" int abii_getpt()
{
    OVERRIDE_PREFIX(getpt)
        pre_fmtd_str pi_str = "getpt()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getpt();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getpt, abii_ret)
    return real_getpt();
}

static __nonnull((1)) int (*real_getloadavg)(double [], int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_getloadavg(double loadavg[], int nelem) __THROW
{
    OVERRIDE_PREFIX(getloadavg)
        pre_fmtd_str pi_str = "getloadavg(__loadavg, __nelem)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(loadavg, "__loadavg");
        printer->set_len(nelem);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nelem, "__nelem"));

        auto abii_ret = real_getloadavg(loadavg, nelem);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getloadavg, abii_ret)
    return real_getloadavg(loadavg, nelem);
}

static int (*real_ttyslot)() __THROW = nullptr;

extern "C" int abii_ttyslot() __THROW
{
    OVERRIDE_PREFIX(ttyslot)
        pre_fmtd_str pi_str = "ttyslot()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_ttyslot();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ttyslot, abii_ret)
    return real_ttyslot();
}

static size_t (*real_memalignment)(const void*) = nullptr;

extern "C" size_t abii_memalignment(const void* p)
{
    OVERRIDE_PREFIX(memalignment)
        pre_fmtd_str pi_str = "memalignment(__p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(p, "__p"));

        auto abii_ret = real_memalignment(p);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memalignment, abii_ret)
    return real_memalignment(p);
}
}
