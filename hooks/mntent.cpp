//
// Created by Trent Tanchin on 10/4/24.
//

#include "mntent.h"

namespace abii
{
static FILE* (*real_setmntent)(const char*, const char*) __THROW = nullptr;

extern "C" FILE* abii_setmntent(const char* file, const char* mode) __THROW
{
    OVERRIDE_PREFIX(setmntent)
        pre_fmtd_str str = "setmntent(__file, __mode)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(mode, "__mode"));

        auto abii_ret = real_setmntent(file, mode);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setmntent, abii_ret)
    return real_setmntent(file, mode);
}

static mntent* (*real_getmntent)(FILE*) __THROW = nullptr;

extern "C" mntent* abii_getmntent(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(getmntent)
        pre_fmtd_str str = "getmntent(__stream)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_getmntent(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getmntent, abii_ret)
    return real_getmntent(stream);
}

static mntent* (*real_getmntent_r)(FILE*, mntent*, char*, int) __THROW = nullptr;

extern "C" mntent* abii_getmntent_r(FILE* stream, mntent* result, char* buffer, int bufsize) __THROW
{
    OVERRIDE_PREFIX(getmntent_r)
        pre_fmtd_str str = "getmntent_r(__stream, __result, __buffer, __bufsize)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(bufsize);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(bufsize, "__bufsize"));

        auto abii_ret = real_getmntent_r(stream, result, buffer, bufsize);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getmntent_r, abii_ret)
    return real_getmntent_r(stream, result, buffer, bufsize);
}

static int (*real_addmntent)(FILE*, const mntent*) __THROW = nullptr;

extern "C" int abii_addmntent(FILE* stream, const mntent* mnt) __THROW
{
    OVERRIDE_PREFIX(addmntent)
        pre_fmtd_str str = "addmntent(__stream, __mnt)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(mnt, "__mnt"));

        auto abii_ret = real_addmntent(stream, mnt);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(addmntent, abii_ret)
    return real_addmntent(stream, mnt);
}

static int (*real_endmntent)(FILE*) __THROW = nullptr;

extern "C" int abii_endmntent(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(endmntent)
        pre_fmtd_str str = "endmntent(__stream)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_endmntent(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(endmntent, abii_ret)
    return real_endmntent(stream);
}

static char* (*real_hasmntopt)(const mntent*, const char*) __THROW = nullptr;

extern "C" char* abii_hasmntopt(const mntent* mnt, const char* opt) __THROW
{
    OVERRIDE_PREFIX(hasmntopt)
        pre_fmtd_str str = "hasmntopt(__mnt, __opt)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mnt, "__mnt"));

        auto printer = new ArgPrinter(opt, "__opt");
        printer->set_enum_printer(print_mntent_mntopt, opt);
        abii_args->push_arg(printer);

        auto abii_ret = real_hasmntopt(mnt, opt);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(hasmntopt, abii_ret)
    return real_hasmntopt(mnt, opt);
}
}
