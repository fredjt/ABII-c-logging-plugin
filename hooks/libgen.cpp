//
// Created by Trent Tanchin on 10/1/24.
//

#include <abii/libabii.h>

namespace abii
{
static char* (*real_dirname)(char*) __THROW = nullptr;

extern "C" char* abii_dirname(char* path) __THROW
{
    OVERRIDE_PREFIX(dirname)
        pre_fmtd_str str = "dirname(__path)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto abii_ret = real_dirname(path);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dirname, abii_ret)
    return real_dirname(path);
}

static char* (*real___xpg_basename)(char*) __THROW = nullptr;

extern "C" char* abii___xpg_basename(char* path) __THROW
{
    OVERRIDE_PREFIX(__xpg_basename)
        pre_fmtd_str str = "__xpg_basename(__path)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(path, "__path"));

        auto abii_ret = real___xpg_basename(path);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__xpg_basename, abii_ret)
    return real___xpg_basename(path);
}
}
