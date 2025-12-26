//
// Created by Trent Tanchin on 9/23/24.
//

#include "grp.h"

namespace abii
{
static void (*real_setgrent)() = nullptr;

extern "C" void abii_setgrent()
{
    OVERRIDE_PREFIX(setgrent)
        pre_fmtd_str str = "setgrent()";
        abii_args->push_func(new ArgPrinter(str));

        real_setgrent();
    OVERRIDE_SUFFIX(setgrent,)
    return real_setgrent();
}

static void (*real_endgrent)() = nullptr;

extern "C" void abii_endgrent()
{
    OVERRIDE_PREFIX(endgrent)
        pre_fmtd_str str = "endgrent()";
        abii_args->push_func(new ArgPrinter(str));

        real_endgrent();
    OVERRIDE_SUFFIX(endgrent,)
    return real_endgrent();
}

static group* (*real_getgrent)() = nullptr;

extern "C" group* abii_getgrent()
{
    OVERRIDE_PREFIX(getgrent)
        pre_fmtd_str str = "getgrent()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real_getgrent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getgrent, abii_ret)
    return real_getgrent();
}

static group* (*real_fgetgrent)(FILE*) = nullptr;

extern "C" group* abii_fgetgrent(FILE* stream)
{
    OVERRIDE_PREFIX(fgetgrent)
        pre_fmtd_str str = "fgetgrent(__stream)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetgrent(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetgrent, abii_ret)
    return real_fgetgrent(stream);
}

static int (*real_putgrent)(const group*, FILE*) = nullptr;

extern "C" int abii_putgrent(const group* p, FILE* f)
{
    OVERRIDE_PREFIX(putgrent)
        pre_fmtd_str str = "putgrent(__p, __f)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(p, "__p"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        auto abii_ret = real_putgrent(p, f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(putgrent, abii_ret)
    return real_putgrent(p, f);
}

static group* (*real_getgrgid)(__gid_t) = nullptr;

extern "C" group* abii_getgrgid(__gid_t gid)
{
    OVERRIDE_PREFIX(getgrgid)
        pre_fmtd_str str = "getgrgid(gid)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(gid, "__gid"));

        auto abii_ret = real_getgrgid(gid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getgrgid, abii_ret)
    return real_getgrgid(gid);
}

static group* (*real_getgrnam)(const char*) = nullptr;

extern "C" group* abii_getgrnam(const char* name)
{
    OVERRIDE_PREFIX(getgrnam)
        pre_fmtd_str str = "getgrnam(__name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getgrnam(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getgrnam, abii_ret)
    return real_getgrnam(name);
}

static int (*real_getgrent_r)(group*, char*, size_t, group**) = nullptr;

extern "C" __attr_access((__write_only__, 2, 3))
int abii_getgrent_r(group* resultbuf, char* buffer, size_t buflen, group** result)
{
    OVERRIDE_PREFIX(getgrent_r)
        pre_fmtd_str str = "getgrent_r(__resultbuf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(resultbuf, "__resultbuf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buflen, "__buflen");
        printer1->set_enum_printer(print_grp_nss_buflen_group, buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getgrent_r(resultbuf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getgrent_r, abii_ret)
    return real_getgrent_r(resultbuf, buffer, buflen, result);
}

static int (*real_getgrgid_r)(__gid_t, group*, char*, size_t, group**) = nullptr;

extern "C" __attr_access((__write_only__, 3, 4))
int abii_getgrgid_r(__gid_t gid, group* resultbuf, char* buffer, size_t buflen, group** result)
{
    OVERRIDE_PREFIX(getgrgid_r)
        pre_fmtd_str str = "getgrgid_r(__gid, __resultbuf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(gid, "__gid"));
        abii_args->push_arg(new ArgPrinter(resultbuf, "__resultbuf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buflen, "__buflen");
        printer1->set_enum_printer(print_grp_nss_buflen_group, buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getgrgid_r(gid, resultbuf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getgrgid_r, abii_ret)
    return real_getgrgid_r(gid, resultbuf, buffer, buflen, result);
}

static int (*real_getgrnam_r)(const char*, group*, char*, size_t, group**) = nullptr;

extern "C" __attr_access((__write_only__, 3, 4))
int abii_getgrnam_r(const char* name, group* resultbuf, char* buffer, size_t buflen, group** result)
{
    OVERRIDE_PREFIX(getgrnam_r)
        pre_fmtd_str str = "getgrnam_r(__name, __resultbuf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(resultbuf, "__resultbuf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buflen, "__buflen");
        printer1->set_enum_printer(print_grp_nss_buflen_group, buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getgrnam_r(name, resultbuf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getgrnam_r, abii_ret)
    return real_getgrnam_r(name, resultbuf, buffer, buflen, result);
}

static int (*real_fgetgrent_r)(FILE*, group*, char*, size_t, group**) = nullptr;

extern "C" __attr_access((__write_only__, 3, 4))
int abii_fgetgrent_r(FILE* stream, group* resultbuf, char* buffer, size_t buflen, group** result)
{
    OVERRIDE_PREFIX(fgetgrent_r)
        pre_fmtd_str str = "fgetgrent_r(__stream, __resultbuf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(resultbuf, "__resultbuf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(buflen, "__buflen");
        printer1->set_enum_printer(print_grp_nss_buflen_group, buflen);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_fgetgrent_r(stream, resultbuf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetgrent_r, abii_ret)
    return real_fgetgrent_r(stream, resultbuf, buffer, buflen, result);
}

static int (*real_setgroups)(size_t, const __gid_t*) __THROW = nullptr;

extern "C" int abii_setgroups(size_t n, const __gid_t* groups) __THROW
{
    OVERRIDE_PREFIX(setgroups)
        pre_fmtd_str str = "setgroups(__n, __groups)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto printer = new ArgPrinter(groups, "__groups");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto abii_ret = real_setgroups(n, groups);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setgroups, abii_ret)
    return real_setgroups(n, groups);
}

static int (*real_getgrouplist)(const char*, __gid_t, __gid_t*, int*) = nullptr;

extern "C" int abii_getgrouplist(const char* user, __gid_t group, __gid_t* groups, int* ngroups)
{
    OVERRIDE_PREFIX(getgrouplist)
        pre_fmtd_str str = "getgrouplist(__user, __group, __groups, __ngroups)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(user, "__user"));
        abii_args->push_arg(new ArgPrinter(group, "__group"));

        auto printer = new ArgPrinter(groups, "__groups");
        printer->set_len(*ngroups);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(ngroups, "__ngroups"));

        auto abii_ret = real_getgrouplist(user, group, groups, ngroups);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getgrouplist, abii_ret)
    return real_getgrouplist(user, group, groups, ngroups);
}

static int (*real_initgroups)(const char*, __gid_t) = nullptr;

extern "C" int abii_initgroups(const char* user, __gid_t group)
{
    OVERRIDE_PREFIX(initgroups)
        pre_fmtd_str str = "initgroups(__user, __group)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(user, "__user"));
        abii_args->push_arg(new ArgPrinter(group, "__group"));

        auto abii_ret = real_initgroups(user, group);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(initgroups, abii_ret)
    return real_initgroups(user, group);
}
}
