//
// Created by Trent Tanchin on 9/17/24.
//

#include "fstab.h"

namespace abii
{
static fstab* (*real_getfsent)() __THROW = nullptr;

extern "C" fstab* abii_getfsent() __THROW
{
    OVERRIDE_PREFIX(getfsent)
        pre_fmtd_str str = "getfsent()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real_getfsent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getfsent, abii_ret)
    return real_getfsent();
}

static fstab* (*real_getfsspec)(const char*) __THROW = nullptr;

extern "C" fstab* abii_getfsspec(const char* name) __THROW
{
    OVERRIDE_PREFIX(getfsspec)
        pre_fmtd_str str = "getfsspec(__name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getfsspec(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getfsspec, abii_ret)
    return real_getfsspec(name);
}

static fstab* (*real_getfsfile)(const char*) __THROW = nullptr;

extern "C" fstab* abii_getfsfile(const char* name) __THROW
{
    OVERRIDE_PREFIX(getfsfile)
        pre_fmtd_str str = "getfsfile(__name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getfsfile(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getfsfile, abii_ret)
    return real_getfsfile(name);
}

static int (*real_setfsent)() __THROW = nullptr;

extern "C" int abii_setfsent() __THROW
{
    OVERRIDE_PREFIX(setfsent)
        pre_fmtd_str str = "setfsent()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real_setfsent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setfsent, abii_ret)
    return real_setfsent();
}

static void (*real_endfsent)() __THROW = nullptr;

extern "C" void abii_endfsent() __THROW
{
    OVERRIDE_PREFIX(endfsent)
        pre_fmtd_str str = "endfsent()";
        abii_args->push_func(new ArgPrinter(str));

        real_endfsent();
    OVERRIDE_SUFFIX(endfsent,)
    return real_endfsent();
}
}
