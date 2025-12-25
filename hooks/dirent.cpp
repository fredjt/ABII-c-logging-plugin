//
// Created by Trent Tanchin on 7/25/24.
//

#include "dirent.h"
#include "bits/dirent.h"

namespace abii
{
static int (*real_closedir)(DIR*) = nullptr;

extern "C" __nonnull((1))
int abii_closedir(DIR* dirp)
{
    OVERRIDE_PREFIX(closedir)
        pre_fmtd_str str = "closedir(__dirp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirp, "__dirp"));

        auto abii_ret = real_closedir(dirp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(closedir, abii_ret)
    return real_closedir(dirp);
}

static DIR*(*real_opendir)(const char*) = nullptr;

extern "C" __nonnull((1)) __attribute_malloc__ __attr_dealloc(closedir, 1)
DIR* abii_opendir(const char* name)
{
    OVERRIDE_PREFIX(opendir)
        pre_fmtd_str str = "opendir(__name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_opendir(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(opendir, abii_ret)
    return real_opendir(name);
}

static DIR*(*real_fdopendir)(int) = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc(closedir, 1)
DIR* abii_fdopendir(int fd)
{
    OVERRIDE_PREFIX(fdopendir)
        pre_fmtd_str str = "fdopendir(__fd)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto abii_ret = real_fdopendir(fd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fdopendir, abii_ret)
    return real_fdopendir(fd);
}

static dirent*(*real_readdir)(DIR*) = nullptr;

extern "C" __nonnull((1))
dirent* abii_readdir(DIR* dirp)
{
    OVERRIDE_PREFIX(readdir)
        pre_fmtd_str str = "readdir(__dirp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirp, "__dirp"));

        auto abii_ret = real_readdir(dirp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(readdir, abii_ret)
    return real_readdir(dirp);
}

static dirent64*(*real_readdir64)(DIR*) = nullptr;

extern "C" __nonnull((1))
dirent64* abii_readdir64(DIR* dirp)
{
    OVERRIDE_PREFIX(readdir64)
        pre_fmtd_str str = "readdir64(__dirp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirp, "__dirp"));

        auto abii_ret = real_readdir64(dirp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(readdir64, abii_ret)
    return real_readdir64(dirp);
}

static int (*real_readdir_r)(DIR*, dirent*, dirent**) = nullptr;

extern "C" __nonnull((1, 2, 3)) __attribute_deprecated__
int abii_readdir_r(DIR* dirp, dirent* entry, dirent** result)
{
    OVERRIDE_PREFIX(readdir_r)
        pre_fmtd_str str = "readdir_r(__dirp, __entry, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirp, "__dirp"));
        abii_args->push_arg(new ArgPrinter(entry, "__entry"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_readdir_r(dirp, entry, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(readdir_r, abii_ret)
    return real_readdir_r(dirp, entry, result);
}

static int (*real_readdir64_r)(DIR*, dirent64*, dirent64**) = nullptr;

extern "C" __nonnull((1, 2, 3)) __attribute_deprecated__
int abii_readdir64_r(DIR* dirp, dirent64* entry, dirent64** result)
{
    OVERRIDE_PREFIX(readdir64_r)
        pre_fmtd_str str = "readdir64_r(__dirp, __entry, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirp, "__dirp"));
        abii_args->push_arg(new ArgPrinter(entry, "__entry"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_readdir64_r(dirp, entry, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(readdir64_r, abii_ret)
    return real_readdir64_r(dirp, entry, result);
}

static void (*real_rewinddir)(DIR*) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_rewinddir(DIR* dirp) __THROW
{
    OVERRIDE_PREFIX(rewinddir)
        pre_fmtd_str str = "rewinddir(__dirp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirp, "__dirp"));

        real_rewinddir(dirp);
    OVERRIDE_SUFFIX(rewinddir,)
    return real_rewinddir(dirp);
}

static void (*real_seekdir)(DIR*, long int) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_seekdir(DIR* dirp, long int pos) __THROW
{
    OVERRIDE_PREFIX(seekdir)
        pre_fmtd_str str = "seekdir(__dirp, __pos)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirp, "__dirp"));
        abii_args->push_arg(new ArgPrinter(pos, "__pos"));

        real_seekdir(dirp, pos);
    OVERRIDE_SUFFIX(seekdir,)
    return real_seekdir(dirp, pos);
}

static long int (*real_telldir)(DIR*) __THROW = nullptr;

extern "C" __nonnull((1))
long int abii_telldir(DIR* dirp) __THROW
{
    OVERRIDE_PREFIX(telldir)
        pre_fmtd_str str = "telldir(__dirp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirp, "__dirp"));

        auto abii_ret = real_telldir(dirp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(telldir, abii_ret)
    return real_telldir(dirp);
}

static int (*real_dirfd)(DIR*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_dirfd(DIR* dirp) __THROW
{
    OVERRIDE_PREFIX(dirfd)
        pre_fmtd_str str = "dirfd(__dirp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dirp, "__dirp"));

        auto abii_ret = real_dirfd(dirp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dirfd, abii_ret)
    return real_dirfd(dirp);
}

static int (*real_scandir)(const char*, dirent***, int (*)(const dirent*), int (*)(const dirent**, const dirent**)) =
    nullptr;

extern "C" __nonnull((1, 2))
int abii_scandir(const char* dir, dirent*** namelist, int (*selector)(const dirent*),
                 int (*cmp)(const dirent**, const dirent**))
{
    OVERRIDE_PREFIX(scandir)
        pre_fmtd_str str = "scandir(__dir, __namelist, __selector, __cmp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dir, "__dir"));

        auto printer = new ArgPrinter(namelist, "__namelist");
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(selector, "__selector"));
        abii_args->push_arg(new ArgPrinter(cmp, "__cmp"));

        auto abii_ret = real_scandir(dir, namelist, selector, cmp);

        // TODO: This is not implemented yet
        // printer->set_len(abii_ret, 2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(scandir, abii_ret)
    return real_scandir(dir, namelist, selector, cmp);
}

static int (*real_scandir64)(const char*, dirent64***, int (*)(const dirent64*),
                             int (*)(const dirent64**, const dirent64**)) = nullptr;

extern "C" __nonnull((1, 2))
int abii_scandir64(const char* dir, dirent64*** namelist, int (*selector)(const dirent64*),
                   int (*cmp)(const dirent64**, const dirent64**))
{
    OVERRIDE_PREFIX(scandir64)
        pre_fmtd_str str = "scandir64(__dir, __namelist, __selector, __cmp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dir, "__dir"));

        auto printer = new ArgPrinter(namelist, "__namelist");
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(selector, "__selector"));
        abii_args->push_arg(new ArgPrinter(cmp, "__cmp"));

        auto abii_ret = real_scandir64(dir, namelist, selector, cmp);

        // TODO: This is not implemented yet
        // printer->set_len(abii_ret, 2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(scandir64, abii_ret)
    return real_scandir64(dir, namelist, selector, cmp);
}

static int (*real_scandirat)(int, const char*, dirent***, int (*)(const dirent*),
                             int (*)(const dirent**, const dirent**)) = nullptr;

extern "C" __nonnull((2, 3))
int abii_scandirat(int dfd, const char* dir, dirent*** namelist, int (*selector)(const dirent*),
                   int (*cmp)(const dirent**, const dirent**))
{
    OVERRIDE_PREFIX(scandirat)
        pre_fmtd_str str = "scandirat(__dfd, __dir, __namelist, __selector, __cmp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dfd, "__dfd"));
        abii_args->push_arg(new ArgPrinter(dir, "__dir"));

        auto printer = new ArgPrinter(namelist, "__namelist");
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(selector, "__selector"));
        abii_args->push_arg(new ArgPrinter(cmp, "__cmp"));

        auto abii_ret = real_scandirat(dfd, dir, namelist, selector, cmp);

        // TODO: This is not implemented yet
        // printer->set_len(abii_ret, 2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(scandirat, abii_ret)
    return real_scandirat(dfd, dir, namelist, selector, cmp);
}

static int (*real_scandirat64)(int, const char*, dirent64***, int (*)(const dirent64*),
                               int (*)(const dirent64**, const dirent64**)) = nullptr;

extern "C" __nonnull((2, 3))
int abii_scandirat64(int dfd, const char* dir, dirent64*** namelist, int (*selector)(const dirent64*),
                     int (*cmp)(const dirent64**, const dirent64**))
{
    OVERRIDE_PREFIX(scandirat64)
        pre_fmtd_str str = "scandirat64(__dfd, __dir, __namelist, __selector, __cmp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(dfd, "__dfd"));
        abii_args->push_arg(new ArgPrinter(dir, "__dir"));

        auto printer = new ArgPrinter(namelist, "__namelist");
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(selector, "__selector"));
        abii_args->push_arg(new ArgPrinter(cmp, "__cmp"));

        auto abii_ret = real_scandirat64(dfd, dir, namelist, selector, cmp);

        // TODO: This is not implemented yet
        // printer->set_len(abii_ret, 2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(scandirat64, abii_ret)
    return real_scandirat64(dfd, dir, namelist, selector, cmp);
}

static int (*real_alphasort)(const dirent**, const dirent**) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_alphasort(const dirent** e1, const dirent** e2) __THROW
{
    OVERRIDE_PREFIX(alphasort)
        pre_fmtd_str str = "alphasort(__e1, __e2)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(e1, "__e1"));
        abii_args->push_arg(new ArgPrinter(e2, "__e2"));

        auto abii_ret = real_alphasort(e1, e2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(alphasort, abii_ret)
    return real_alphasort(e1, e2);
}

static int (*real_alphasort64)(const dirent64**, const dirent64**) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_alphasort64(const dirent64** e1, const dirent64** e2) __THROW
{
    OVERRIDE_PREFIX(alphasort64)
        pre_fmtd_str str = "alphasort64(__e1, __e2)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(e1, "__e1"));
        abii_args->push_arg(new ArgPrinter(e2, "__e2"));

        auto abii_ret = real_alphasort64(e1, e2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(alphasort64, abii_ret)
    return real_alphasort64(e1, e2);
}

static __ssize_t (*real_getdirentries)(int, char*, size_t, __off_t*) __THROW = nullptr;

extern "C" __nonnull((2, 4))
__ssize_t abii_getdirentries(int fd, char* buf, size_t nbytes, __off_t* basep) __THROW
{
    OVERRIDE_PREFIX(getdirentries)
        pre_fmtd_str str = "getdirentries(__fd, __buf, __nbytes, __basep)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(buf, "__buf");
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nbytes, "__nbytes"));
        abii_args->push_arg(new ArgPrinter(basep, "__basep"));

        auto abii_ret = real_getdirentries(fd, buf, nbytes, basep);

        printer->set_len(abii_ret);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getdirentries, abii_ret)
    return real_getdirentries(fd, buf, nbytes, basep);
}

static __ssize_t (*real_getdirentries64)(int, char*, size_t, __off64_t*) __THROW = nullptr;

extern "C" __nonnull((2, 4))
__ssize_t abii_getdirentries64(int fd, char* buf, size_t nbytes, __off64_t* basep) __THROW
{
    OVERRIDE_PREFIX(getdirentries64)
        pre_fmtd_str str = "getdirentries64(__fd, __buf, __nbytes, __basep)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));

        auto printer = new ArgPrinter(buf, "__buf");
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(nbytes, "__nbytes"));
        abii_args->push_arg(new ArgPrinter(basep, "__basep"));

        auto abii_ret = real_getdirentries64(fd, buf, nbytes, basep);

        printer->set_len(abii_ret);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getdirentries64, abii_ret)
    return real_getdirentries64(fd, buf, nbytes, basep);
}

static int (*real_versionsort)(const dirent**, const dirent**) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_versionsort(const dirent** e1, const dirent** e2) __THROW
{
    OVERRIDE_PREFIX(versionsort)
        pre_fmtd_str str = "versionsort(__e1, __e2)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(e1, "__e1"));
        abii_args->push_arg(new ArgPrinter(e2, "__e2"));

        auto abii_ret = real_versionsort(e1, e2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(versionsort, abii_ret)
    return real_versionsort(e1, e2);
}

static int (*real_versionsort64)(const dirent64**, const dirent64**) __THROW = nullptr;

extern "C" __attribute_pure__ __nonnull((1, 2))
int abii_versionsort64(const dirent64** e1, const dirent64** e2) __THROW
{
    OVERRIDE_PREFIX(versionsort64)
        pre_fmtd_str str = "versionsort64(__e1, __e2)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(e1, "__e1"));
        abii_args->push_arg(new ArgPrinter(e2, "__e2"));

        auto abii_ret = real_versionsort64(e1, e2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(versionsort64, abii_ret)
    return real_versionsort64(e1, e2);
}
}
