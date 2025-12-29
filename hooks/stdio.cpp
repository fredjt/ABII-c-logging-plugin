//
// Created by Trent Tanchin on 6/1/25.
//

#include "stdio.h"

#include "custom_printers.h"
#include "obstack.h"
#include "stdint.h"
#include "bits/types/cookie_io_functions_t.h"
#include "bits/types/__fpos64_t.h"
#include "bits/types/__fpos_t.h"

namespace abii
{
static int (*real_remove)(const char*) __THROW = nullptr;

extern "C" int abii_remove(const char* filename) __THROW
{
    OVERRIDE_PREFIX(remove)
        pre_fmtd_str pi_str = "remove(__filename)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(filename, "__filename"));

        auto abii_ret = real_remove(filename);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(remove, abii_ret)
    return real_remove(filename);
}

static int (*real_rename)(const char*, const char*) __THROW = nullptr;

extern "C" int abii_rename(const char* old, const char* _new) __THROW
{
    OVERRIDE_PREFIX(rename)
        pre_fmtd_str pi_str = "rename(__old, __new)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(old, "__old"));
        abii_args->push_arg(new ArgPrinter(_new, "__new"));

        auto abii_ret = real_rename(old, _new);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(rename, abii_ret)
    return real_rename(old, _new);
}

static int (*real_renameat)(int, const char*, int, const char*) __THROW = nullptr;

extern "C" int abii_renameat(int oldfd, const char* old, int newfd, const char* _new) __THROW
{
    OVERRIDE_PREFIX(renameat)
        pre_fmtd_str pi_str = "renameat(__oldfd, __old, __newfd, __new)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(oldfd, "__oldfd"));
        abii_args->push_arg(new ArgPrinter(old, "__old"));
        abii_args->push_arg(new ArgPrinter(newfd, "__newfd"));
        abii_args->push_arg(new ArgPrinter(_new, "__new"));

        auto abii_ret = real_renameat(oldfd, old, newfd, _new);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(renameat, abii_ret)
    return real_renameat(oldfd, old, newfd, _new);
}

static int (*real_renameat2)(int, const char*, int, const char*, unsigned int) __THROW = nullptr;

extern "C" int abii_renameat2(int oldfd, const char* old, int newfd, const char* _new, unsigned int flags) __THROW
{
    OVERRIDE_PREFIX(renameat2)
        pre_fmtd_str pi_str = "renameat2(__oldfd, __old, __newfd, __new)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(oldfd, "__oldfd"));
        abii_args->push_arg(new ArgPrinter(old, "__old"));
        abii_args->push_arg(new ArgPrinter(newfd, "__newfd"));
        abii_args->push_arg(new ArgPrinter(_new, "__new"));

        auto printer = new ArgPrinter(_new, "__flags");
        printer->set_enum_printer(print_stdio_rename_flags, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_renameat2(oldfd, old, newfd, _new, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(renameat2, abii_ret)
    return real_renameat2(oldfd, old, newfd, _new, flags);
}

static int (*real_fclose)(FILE*) = nullptr;

extern "C" __nonnull((1))
int abii_fclose(FILE* stream)
{
    OVERRIDE_PREFIX(fclose)
        pre_fmtd_str pi_str = "fclose(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fclose(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fclose, abii_ret)
    return real_fclose(stream);
}

static FILE* (*real_tmpfile)() = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_fclose __wur
FILE* abii_tmpfile()
{
    OVERRIDE_PREFIX(tmpfile)
        pre_fmtd_str pi_str = "tmpfile()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_tmpfile();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tmpfile, abii_ret)
    return real_tmpfile();
}

static FILE* (*real_tmpfile64)() = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_fclose __wur
FILE* abii_tmpfile64()
{
    OVERRIDE_PREFIX(tmpfile64)
        pre_fmtd_str pi_str = "tmpfile64()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_tmpfile64();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tmpfile64, abii_ret)
    return real_tmpfile64();
}

static char* (*real_tmpnam)(char [L_tmpnam]) __THROW = nullptr;

extern "C" __wur char* abii_tmpnam(char s[L_tmpnam]) __THROW
{
    OVERRIDE_PREFIX(tmpnam)
        pre_fmtd_str pi_str = "tmpnam(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_tmpnam(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tmpnam, abii_ret)
    return real_tmpnam(s);
}

static char* (*real_tmpnam_r)(char [L_tmpnam]) __THROW = nullptr;

extern "C" __wur char* abii_tmpnam_r(char s[L_tmpnam]) __THROW
{
    OVERRIDE_PREFIX(tmpnam_r)
        pre_fmtd_str pi_str = "tmpnam_r(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_tmpnam_r(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tmpnam_r, abii_ret)
    return real_tmpnam_r(s);
}

static char* (*real_tempnam)(const char*, const char*) __THROW = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_free __wur
char* abii_tempnam(const char* dir, const char* pfx) __THROW
{
    OVERRIDE_PREFIX(tempnam)
        pre_fmtd_str pi_str = "tempnam(__dir, __pfx)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(dir, "__dir");
        printer->set_enum_printer(print_stdio_p_tmpdir, dir);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(pfx, "__pfx"));

        auto abii_ret = real_tempnam(dir, pfx);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tempnam, abii_ret)
    return real_tempnam(dir, pfx);
}

static int (*real_fflush)(FILE*) = nullptr;

extern "C" int abii_fflush(FILE* stream)
{
    OVERRIDE_PREFIX(fflush)
        pre_fmtd_str pi_str = "fflush(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fflush(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fflush, abii_ret)
    return real_fflush(stream);
}

static int (*real_fflush_unlocked)(FILE*) = nullptr;

extern "C" int abii_fflush_unlocked(FILE* stream)
{
    OVERRIDE_PREFIX(fflush_unlocked)
        pre_fmtd_str pi_str = "fflush_unlocked(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fflush_unlocked(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fflush_unlocked, abii_ret)
    return real_fflush_unlocked(stream);
}

static int (*real_fcloseall)() = nullptr;

extern "C" int abii_fcloseall()
{
    OVERRIDE_PREFIX(fcloseall)
        pre_fmtd_str pi_str = "fcloseall(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_fcloseall();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fcloseall, abii_ret)
    return real_fcloseall();
}

static FILE* (*real_fopen)(const char*, const char*) = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_fclose __wur
FILE* abii_fopen(const char* filename, const char* modes)
{
    OVERRIDE_PREFIX(fopen)
        pre_fmtd_str pi_str = "fopen(__filename, __modes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(filename, "__filename"));
        abii_args->push_arg(new ArgPrinter(modes, "__modes"));

        auto abii_ret = real_fopen(filename, modes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fopen, abii_ret)
    return real_fopen(filename, modes);
}

static FILE* (*real_freopen)(const char*, const char*, FILE*) = nullptr;

extern "C" __nonnull((3)) __wur
FILE* abii_freopen(const char* filename, const char* modes, FILE* stream)
{
    OVERRIDE_PREFIX(freopen)
        pre_fmtd_str pi_str = "freopen(__filename, __modes, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(filename, "__filename"));
        abii_args->push_arg(new ArgPrinter(modes, "__modes"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_freopen(filename, modes, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(freopen, abii_ret)
    return real_freopen(filename, modes, stream);
}

static FILE* (*real_fopen64)(const char*, const char*) = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_fclose __wur
FILE* abii_fopen64(const char* filename, const char* modes)
{
    OVERRIDE_PREFIX(fopen64)
        pre_fmtd_str pi_str = "fopen64(__filename, __modes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(filename, "__filename"));
        abii_args->push_arg(new ArgPrinter(modes, "__modes"));

        auto abii_ret = real_fopen64(filename, modes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fopen64, abii_ret)
    return real_fopen64(filename, modes);
}

static FILE* (*real_freopen64)(const char*, const char*, FILE*) = nullptr;

extern "C" __nonnull((3)) __wur
FILE* abii_freopen64(const char* filename, const char* modes, FILE* stream)
{
    OVERRIDE_PREFIX(freopen64)
        pre_fmtd_str pi_str = "freopen64(__filename, __modes, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(filename, "__filename"));
        abii_args->push_arg(new ArgPrinter(modes, "__modes"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_freopen64(filename, modes, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(freopen64, abii_ret)
    return real_freopen64(filename, modes, stream);
}

static FILE* (*real_fdopen)(int, const char*) __THROW = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_fclose __wur
FILE* abii_fdopen(int fd, const char* modes) __THROW
{
    OVERRIDE_PREFIX(fdopen)
        pre_fmtd_str pi_str = "fdopen(__fd, __modes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(modes, "__modes"));

        auto abii_ret = real_fdopen(fd, modes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fdopen, abii_ret)
    return real_fdopen(fd, modes);
}

static FILE* (*real_fopencookie)(void*, const char*, cookie_io_functions_t) __THROW = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_fclose __wur
FILE* abii_fopencookie(void* magic_cookie, const char* modes, cookie_io_functions_t io_funcs) __THROW
{
    OVERRIDE_PREFIX(fopencookie)
        pre_fmtd_str pi_str = "fopencookie(__magic_cookie, __modes, __io_funcs)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(magic_cookie, "__magic_cookie"));
        abii_args->push_arg(new ArgPrinter(modes, "__modes"));
        abii_args->push_arg(new ArgPrinter(io_funcs, "__io_funcs"));

        auto abii_ret = real_fopencookie(magic_cookie, modes, io_funcs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fopencookie, abii_ret)
    return real_fopencookie(magic_cookie, modes, io_funcs);
}

static FILE* (*real_fmemopen)(void*, size_t, const char*) __THROW = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_fclose __wur
FILE* abii_fmemopen(void* s, size_t len, const char* modes) __THROW
{
    OVERRIDE_PREFIX(fmemopen)
        pre_fmtd_str pi_str = "fmemopen(__s, __len, __modes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(len, "__len"));
        abii_args->push_arg(new ArgPrinter(modes, "__modes"));

        auto abii_ret = real_fmemopen(s, len, modes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fmemopen, abii_ret)
    return real_fmemopen(s, len, modes);
}

static FILE* (*real_open_memstream)(char**, size_t*) __THROW = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_fclose __wur
FILE* abii_open_memstream(char** bufloc, size_t* sizeloc) __THROW
{
    OVERRIDE_PREFIX(open_memstream)
        pre_fmtd_str pi_str = "open_memstream(__bufloc, __sizeloc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(bufloc, "__bufloc");
        // TODO: This is not implemented yet
        // printer->set_len(*sizeloc, 1);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(sizeloc, "__sizeloc"));

        auto abii_ret = real_open_memstream(bufloc, sizeloc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(open_memstream, abii_ret)
    return real_open_memstream(bufloc, sizeloc);
}

#ifdef _WCHAR_H
static __FILE* (*real_open_wmemstream)(wchar_t**, size_t*) __THROW = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc_fclose
__FILE* abii_open_wmemstream(wchar_t** bufloc, size_t* sizeloc) __THROW
{
    OVERRIDE_PREFIX(open_wmemstream)
        pre_fmtd_str pi_str = "open_wmemstream(__bufloc, __sizeloc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(bufloc, "__bufloc");
        // TODO: This is not implemented yet
        // printer->set_len_with_depth(*sizeloc, 1);
        printer->set_enum_printer_with_depth(print_stdint_wchar, **bufloc, 2);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(sizeloc, "__sizeloc"));

        auto abii_ret = real_open_wmemstream(bufloc, sizeloc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(open_wmemstream, abii_ret)
    return real_open_wmemstream(bufloc, sizeloc);
}
#endif

static void (*real_setbuf)(FILE*, char*) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_setbuf(FILE* stream, char* buf) __THROW
{
    OVERRIDE_PREFIX(setbuf)
        pre_fmtd_str pi_str = "setbuf(__stream, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        real_setbuf(stream, buf);
    OVERRIDE_SUFFIX(setbuf,)
    return real_setbuf(stream, buf);
}

static int (*real_setvbuf)(FILE*, char*, int, size_t) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_setvbuf(FILE* stream, char* buf, int modes, size_t n) __THROW
{
    OVERRIDE_PREFIX(setvbuf)
        pre_fmtd_str pi_str = "setvbuf(__stream, __buf, __modes, __n)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(n);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(modes, "__modes");
        printer1->set_enum_printer(print_stdio_buffer_mode, modes);
        abii_args->push_arg(printer1);

        auto printer2 = new ArgPrinter(n, "__n");
        printer2->set_enum_printer(print_stdio_bufsiz, n);
        abii_args->push_arg(printer2);

        auto abii_ret = real_setvbuf(stream, buf, modes, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setvbuf, abii_ret)
    return real_setvbuf(stream, buf, modes, n);
}

static void (*real_setbuffer)(FILE*, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_setbuffer(FILE* stream, char* buf, size_t size) __THROW
{
    OVERRIDE_PREFIX(setbuffer)
        pre_fmtd_str pi_str = "setbuffer(__stream, __buf, __size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(size);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(size, "__size");
        printer1->set_enum_printer(print_stdio_bufsiz, size);
        abii_args->push_arg(printer1);

        real_setbuffer(stream, buf, size);
    OVERRIDE_SUFFIX(setbuffer,)
    return real_setbuffer(stream, buf, size);
}

static void (*real_setlinebuf)(FILE*) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_setlinebuf(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(setlinebuf)
        pre_fmtd_str pi_str = "setlinebuf(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        real_setlinebuf(stream);
    OVERRIDE_SUFFIX(setlinebuf,)
    return real_setlinebuf(stream);
}

static int (*real_fprintf)(FILE*, const char*, ...) = nullptr;

extern "C" __nonnull((1))
int abii_fprintf(FILE* stream, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(fprintf, format)
        pre_fmtd_str str = "fprintf(__stream, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_fprintf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(fprintf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_fprintf), abii_bi_vargs, 1000));
}

static int (*real_printf)(const char*, ...) = nullptr;

extern "C" int abii_printf(const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(printf, format)
        pre_fmtd_str str = "printf(__format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_printf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(printf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_printf), abii_bi_vargs, 1000));
}

static int (*real_sprintf)(char*, const char*, ...) __THROWNL = nullptr;

extern "C" int abii_sprintf(char* s, const char* format, ...) __THROWNL
{
    OVERRIDE_VARIADIC_PREFIX(sprintf, format)
        pre_fmtd_str str = "sprintf(__s, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_sprintf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(sprintf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_sprintf), abii_bi_vargs, 1000));
}

static int (*real_vfprintf)(FILE*, const char*, __gnuc_va_list) = nullptr;

extern "C" __nonnull((1))
int abii_vfprintf(FILE* s, const char* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(vfprintf, format, arg)
        pre_fmtd_str str = "vfprintf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, arg, "__arg", print_variadic_args_printf)

        auto abii_ret = real_vfprintf(s, format, abii_vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vfprintf, abii_ret, arg)
    return real_vfprintf(s, format, arg);
}

static int (*real_vprintf)(const char*, __gnuc_va_list) = nullptr;

extern "C" int abii_vprintf(const char* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(vprintf, format, arg)
        pre_fmtd_str str = "vprintf(__format, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, arg, "__arg", print_variadic_args_printf)

        auto abii_ret = real_vprintf(format, abii_vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vprintf, abii_ret, arg)
    return real_vprintf(format, arg);
}

static int (*real_vsprintf)(char*, const char*, __gnuc_va_list) __THROWNL = nullptr;

extern "C" int abii_vsprintf(char* s, const char* format, __gnuc_va_list arg) __THROWNL
{
    OVERRIDE_VALIST_PREFIX(vsprintf, format, arg)
        pre_fmtd_str str = "vsprintf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, arg, "__arg", print_variadic_args_printf)

        auto abii_ret = real_vsprintf(s, format, abii_vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vsprintf, abii_ret, arg)
    return real_vsprintf(s, format, arg);
}

static int (*real_snprintf)(char*, size_t, const char*, ...) __THROWNL = nullptr;

extern "C" __attribute__ (( __format__ (__printf__, 3 , 4)))
int abii_snprintf(char* s, size_t maxlen, const char* format, ...) __THROWNL
{
    OVERRIDE_VARIADIC_PREFIX(snprintf, format)
        pre_fmtd_str str = "snprintf(__s, __maxlen, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(maxlen, "__maxlen"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_snprintf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(snprintf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_snprintf), abii_bi_vargs, 1000));
}

static int (*real_vsnprintf)(char*, size_t, const char*, __gnuc_va_list) __THROWNL = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 3, 0)))
int abii_vsnprintf(char* s, size_t maxlen, const char* format, __gnuc_va_list arg) __THROWNL
{
    OVERRIDE_VALIST_PREFIX(vsnprintf, format, arg)
        pre_fmtd_str str = "vsnprintf(__s, __maxlen, __format, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(maxlen, "__maxlen"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, arg, "__arg", print_variadic_args_printf)

        auto abii_ret = real_vsnprintf(s, maxlen, format, abii_vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vsnprintf, abii_ret, arg)
    return real_vsnprintf(s, maxlen, format, arg);
}

static int (*real_vasprintf)(char**, const char*, __gnuc_va_list) __THROWNL = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 2, 0))) __wur
int abii_vasprintf(char** ptr, const char* f, __gnuc_va_list arg) __THROWNL
{
    OVERRIDE_VALIST_PREFIX(vasprintf, f, arg)
        pre_fmtd_str str = "vasprintf(__ptr, __f, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));
        abii_args->push_arg(new ArgPrinter(f, "__f"));

        PUSH_VALIST_ARGS(printer, f, arg, "__arg", print_variadic_args_printf)

        auto abii_ret = real_vasprintf(ptr, f, abii_vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vasprintf, abii_ret, arg)
    return real_vasprintf(ptr, f, arg);
}

static int (*real___asprintf)(char**, const char*, ...) __THROWNL = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 2, 3))) __wur
int abii___asprintf(char** ptr, const char* fmt, ...) __THROWNL
{
    OVERRIDE_VARIADIC_PREFIX(__asprintf, format)
        pre_fmtd_str str = "__asprintf(__ptr, __fmt, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));
        abii_args->push_arg(new ArgPrinter(fmt, "__fmt"));
        PUSH_VARIADIC_ARGS(printer, fmt, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___asprintf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(__asprintf, abii_ret, fmt)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___asprintf), abii_bi_vargs, 1000));
}

static int (*real_asprintf)(char**, const char*, ...) __THROWNL = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 2, 3))) __wur
int abii_asprintf(char** ptr, const char* fmt, ...) __THROWNL
{
    OVERRIDE_VARIADIC_PREFIX(asprintf, format)
        pre_fmtd_str str = "asprintf(__ptr, __fmt, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));
        abii_args->push_arg(new ArgPrinter(fmt, "__fmt"));
        PUSH_VARIADIC_ARGS(printer, fmt, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_asprintf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(asprintf, abii_ret, fmt)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_asprintf), abii_bi_vargs, 1000));
}

static int (*real_vdprintf)(int, const char*, __gnuc_va_list) = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 2, 0)))
int abii_vdprintf(int fd, const char* fmt, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(vdprintf, f, arg)
        pre_fmtd_str str = "vdprintf(__fd, __fmt, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(fmt, "__fmt"));

        PUSH_VALIST_ARGS(printer, fmt, arg, "__arg", print_variadic_args_printf)

        auto abii_ret = real_vdprintf(fd, fmt, abii_vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(vdprintf, abii_ret, arg)
    return real_vdprintf(fd, fmt, arg);
}

static int (*real_dprintf)(int, const char*, ...) = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 2, 3)))
int abii_dprintf(int fd, const char* fmt, ...)
{
    OVERRIDE_VARIADIC_PREFIX(dprintf, format)
        pre_fmtd_str str = "dprintf(__fd, __fmt, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(fd, "__fd"));
        abii_args->push_arg(new ArgPrinter(fmt, "__fmt"));
        PUSH_VARIADIC_ARGS(printer, fmt, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_dprintf), abii_bi_vargs, 1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(dprintf, abii_ret, fmt)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_dprintf), abii_bi_vargs, 1000));
}

static int (*real_fscanf)(FILE*, const char*, ...) = nullptr;

extern "C" __nonnull((1)) __wur
int abii_fscanf(FILE* stream, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(fscanf, format)
        pre_fmtd_str str = "fscanf(__stream, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_fscanf), abii_bi_vargs, 1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(fscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_fscanf), abii_bi_vargs, 1000));
}

static int (*real_scanf)(const char*, ...) = nullptr;

extern "C" int abii_scanf(const char* format, ...) __wur
{
    OVERRIDE_VARIADIC_PREFIX(scanf, format)
        pre_fmtd_str str = "scanf(__format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_scanf), abii_bi_vargs, 1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(scanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_scanf), abii_bi_vargs, 1000));
}

static int (*real_sscanf)(const char*, const char*, ...) __THROW = nullptr;

extern "C" int abii_sscanf(const char* s, const char* format, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(sscanf, format)
        pre_fmtd_str str = "sscanf(__s, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_sscanf), abii_bi_vargs, 1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(sscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_sscanf), abii_bi_vargs, 1000));
}

static int (*real___isoc23_fscanf)(FILE*, const char*, ...) = nullptr;

extern "C" __nonnull((1)) __wur
int abii___isoc23_fscanf(FILE* stream, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc23_fscanf, format)
        pre_fmtd_str str = "__isoc23_fscanf(__stream, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_fscanf), abii_bi_vargs,
                                        1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(__isoc23_fscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_fscanf), abii_bi_vargs, 1000));
}

static int (*real___isoc23_scanf)(const char*, ...) = nullptr;

extern "C" __wur int abii___isoc23_scanf(const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc23_scanf, format)
        pre_fmtd_str str = "__isoc23_scanf(__format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_scanf), abii_bi_vargs, 1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(__isoc23_scanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_scanf), abii_bi_vargs, 1000));
}

static int (*real___isoc23_sscanf)(const char*, const char*, ...) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii___isoc23_sscanf(const char* s, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc23_sscanf, format)
        pre_fmtd_str str = "__isoc23_sscanf(__s, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_sscanf), abii_bi_vargs, 1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(__isoc23_sscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc23_sscanf), abii_bi_vargs, 1000));
}

static int (*real___isoc99_fscanf)(FILE*, const char*, ...) = nullptr;

extern "C" __nonnull((1)) __wur
int abii___isoc99_fscanf(FILE* stream, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc99_fscanf, format)
        pre_fmtd_str str = "__isoc99_fscanf(__stream, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_fscanf), abii_bi_vargs,
                                        1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(__isoc99_fscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_fscanf), abii_bi_vargs, 1000));
}

static int (*real___isoc99_scanf)(const char*, ...) = nullptr;

extern "C" __wur int abii___isoc99_scanf(const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc99_scanf, format)
        pre_fmtd_str str = "__isoc99_scanf(__format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_scanf), abii_bi_vargs, 1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(__isoc99_scanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_scanf), abii_bi_vargs, 1000));
}

static int (*real___isoc99_sscanf)(const char*, const char*, ...) __THROW = nullptr;

extern "C" __nonnull((1)) __wur
int abii___isoc99_sscanf(const char* s, const char* format, ...)
{
    OVERRIDE_VARIADIC_PREFIX(__isoc99_sscanf, format)
        pre_fmtd_str str = "__isoc99_sscanf(__s, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_sscanf), abii_bi_vargs, 1000);

        auto printer1 = new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return");
        printer1->set_enum_printer(print_stdio_eof, *reinterpret_cast<int*>(abii_ret));
        abii_args->push_return(printer1);
    OVERRIDE_VARIADIC_SUFFIX(__isoc99_sscanf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real___isoc99_sscanf), abii_bi_vargs, 1000));
}

static int (*real_vfscanf)(FILE*, const char*, __gnuc_va_list) = nullptr;

extern "C" __attribute__ ((__format__ (__scanf__, 2, 0))) __nonnull((1)) __wur
int abii_vfscanf(FILE* s, const char* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(vfscanf, format, arg)
        pre_fmtd_str str = "vfscanf(__s, __format, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, arg, "__arg", print_variadic_args_printf)

        auto abii_ret = real_vfscanf(s, format, abii_vargs);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_VALIST_SUFFIX(vfscanf, abii_ret, arg)
    return real_vfscanf(s, format, arg);
}

static int (*real_vscanf)(const char*, __gnuc_va_list) = nullptr;

extern "C" __attribute__ ((__format__ (__scanf__, 1, 0))) __wur
int abii_vscanf(const char* format, __gnuc_va_list arg)
{
    OVERRIDE_VALIST_PREFIX(vscanf, format, arg)
        pre_fmtd_str str = "vscanf(__format, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, arg, "__arg", print_variadic_args_printf)

        auto abii_ret = real_vscanf(format, abii_vargs);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_VALIST_SUFFIX(vscanf, abii_ret, arg)
    return real_vscanf(format, arg);
}

static int (*real_vsscanf)(const char*, const char*, __gnuc_va_list) __THROW = nullptr;

extern "C" __attribute__ ((__format__ (__scanf__, 2, 0)))
int abii_vsscanf(const char* s, const char* format, __gnuc_va_list arg) __THROW
{
    OVERRIDE_VALIST_PREFIX(vsscanf, format, arg)
        pre_fmtd_str str = "vsscanf(__format, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, arg, "__arg", print_variadic_args_printf)

        auto abii_ret = real_vsscanf(s, format, abii_vargs);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_VALIST_SUFFIX(vsscanf, abii_ret, arg)
    return real_vsscanf(s, format, arg);
}

static int (*real_fgetc)(FILE*) = nullptr;

extern "C" __nonnull((1))
int abii_fgetc(FILE* stream)
{
    OVERRIDE_PREFIX(fgetc)
        pre_fmtd_str pi_str = "fgetc(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetc(stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(fgetc, abii_ret)
    return real_fgetc(stream);
}

static int (*real_getc)(FILE*) = nullptr;

extern "C" __nonnull((1))
int abii_getc(FILE* stream)
{
    OVERRIDE_PREFIX(getc)
        pre_fmtd_str pi_str = "getc(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_getc(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getc, abii_ret)
    return real_getc(stream);
}

static int (*real_getchar)() = nullptr;

extern "C" int abii_getchar()
{
    OVERRIDE_PREFIX(getchar)
        pre_fmtd_str pi_str = "getchar()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getchar();

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(getchar, abii_ret)
    return real_getchar();
}

static int (*real_getc_unlocked)(FILE*) = nullptr;

extern "C" __nonnull((1))
int abii_getc_unlocked(FILE* stream)
{
    OVERRIDE_PREFIX(getc_unlocked)
        pre_fmtd_str pi_str = "getc_unlocked(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_getc_unlocked(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getc_unlocked, abii_ret)
    return real_getc_unlocked(stream);
}

static int (*real_getchar_unlocked)() = nullptr;

extern "C" int abii_getchar_unlocked()
{
    OVERRIDE_PREFIX(getchar_unlocked)
        pre_fmtd_str pi_str = "getchar_unlocked()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_getchar_unlocked();

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(getchar_unlocked, abii_ret)
    return real_getchar_unlocked();
}

static int (*real_fgetc_unlocked)(FILE*) = nullptr;

extern "C" __nonnull((1))
int abii_fgetc_unlocked(FILE* stream)
{
    OVERRIDE_PREFIX(fgetc_unlocked)
        pre_fmtd_str pi_str = "fgetc_unlocked(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetc_unlocked(stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(fgetc_unlocked, abii_ret)
    return real_fgetc_unlocked(stream);
}

static int (*real_fputc)(int, FILE*) = nullptr;

extern "C" __nonnull((2))
int abii_fputc(int c, FILE* stream)
{
    OVERRIDE_PREFIX(fputc)
        pre_fmtd_str pi_str = "fputc(__c, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fputc(c, stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(fputc, abii_ret)
    return real_fputc(c, stream);
}

static int (*real_putc)(int, FILE*) = nullptr;

extern "C" __nonnull((2))
int abii_putc(int c, FILE* stream)
{
    OVERRIDE_PREFIX(putc)
        pre_fmtd_str pi_str = "putc(__c, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_putc(c, stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(putc, abii_ret)
    return real_putc(c, stream);
}

static int (*real_putchar)(int) = nullptr;

extern "C" int abii_putchar(int c)
{
    OVERRIDE_PREFIX(putchar)
        pre_fmtd_str pi_str = "putchar(__c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_putchar(c);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(putchar, abii_ret)
    return real_putchar(c);
}

static int (*real_fputc_unlocked)(int, FILE*) = nullptr;

extern "C" __nonnull((2))
int abii_fputc_unlocked(int c, FILE* stream)
{
    OVERRIDE_PREFIX(fputc_unlocked)
        pre_fmtd_str pi_str = "fputc_unlocked(__c, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fputc_unlocked(c, stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(fputc_unlocked, abii_ret)
    return real_fputc_unlocked(c, stream);
}

static int (*real_putc_unlocked)(int, FILE*) = nullptr;

extern "C" __nonnull((2))
int abii_putc_unlocked(int c, FILE* stream)
{
    OVERRIDE_PREFIX(putc_unlocked)
        pre_fmtd_str pi_str = "putc_unlocked(__c, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_putc_unlocked(c, stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(putc_unlocked, abii_ret)
    return real_putc_unlocked(c, stream);
}

static int (*real_putchar_unlocked)(int) = nullptr;

extern "C" int abii_putchar_unlocked(int c)
{
    OVERRIDE_PREFIX(putchar_unlocked)
        pre_fmtd_str pi_str = "putchar_unlocked(__c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));

        auto abii_ret = real_putchar_unlocked(c);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(putchar_unlocked, abii_ret)
    return real_putchar_unlocked(c);
}

static int (*real_getw)(FILE*) = nullptr;

extern "C" __nonnull((1))
int abii_getw(FILE* stream)
{
    OVERRIDE_PREFIX(getw)
        pre_fmtd_str pi_str = "getw(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_getw(stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(getw, abii_ret)
    return real_getw(stream);
}

static int (*real_putw)(int, FILE*) = nullptr;

extern "C" __nonnull((2))
int abii_putw(int w, FILE* stream)
{
    OVERRIDE_PREFIX(putw)
        pre_fmtd_str pi_str = "putw(__w, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(w, "__w"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_putw(w, stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(putw, abii_ret)
    return real_putw(w, stream);
}

static char* (*real_fgets)(char*, int, FILE*) = nullptr;

extern "C" __wur __fortified_attr_access(__write_only__, 1, 2) __nonnull((3))
char* abii_fgets(char* s, int n, FILE* stream)
{
    OVERRIDE_PREFIX(fgets)
        pre_fmtd_str pi_str = "fgets(__s, __n, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgets(s, n, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgets, abii_ret)
    return real_fgets(s, n, stream);
}

static char* (*real_gets)(char*) = nullptr;

extern "C" __wur __attribute_deprecated__
char* abii_gets(char* s)
{
    OVERRIDE_PREFIX(gets)
        pre_fmtd_str pi_str = "gets(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_gets(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gets, abii_ret)
    return real_gets(s);
}

static char* (*real_fgets_unlocked)(char*, int, FILE*) = nullptr;

extern "C" __wur __fortified_attr_access(__write_only__, 1, 2) __nonnull((3))
char* abii_fgets_unlocked(char* s, int n, FILE* stream)
{
    OVERRIDE_PREFIX(fgets_unlocked)
        pre_fmtd_str pi_str = "fgets_unlocked(__s, __n, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgets_unlocked(s, n, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgets_unlocked, abii_ret)
    return real_fgets_unlocked(s, n, stream);
}

static __ssize_t (*real___getdelim)(char**, size_t*, int, FILE*) = nullptr;

extern "C" __wur __nonnull((4))
__ssize_t abii___getdelim(char** lineptr, size_t* n, int delimiter, FILE* stream)
{
    OVERRIDE_PREFIX(__getdelim)
        pre_fmtd_str pi_str = "__getdelim(__lineptr, __n, __delimiter, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(lineptr, "__lineptr"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(delimiter, "__delimiter"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real___getdelim(lineptr, n, delimiter, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__getdelim, abii_ret)
    return real___getdelim(lineptr, n, delimiter, stream);
}

static __ssize_t (*real_getdelim)(char**, size_t*, int, FILE*) = nullptr;

extern "C" __wur __nonnull((4))
__ssize_t abii_getdelim(char** lineptr, size_t* n, int delimiter, FILE* stream)
{
    OVERRIDE_PREFIX(getdelim)
        pre_fmtd_str pi_str = "getdelim(__lineptr, __n, __delimiter, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(lineptr, "__lineptr"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(delimiter, "__delimiter"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_getdelim(lineptr, n, delimiter, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getdelim, abii_ret)
    return real_getdelim(lineptr, n, delimiter, stream);
}

static __ssize_t (*real_getline)(char**, size_t*, FILE*) = nullptr;

extern "C" __wur __nonnull((3))
__ssize_t abii_getline(char** lineptr, size_t* n, FILE* stream)
{
    OVERRIDE_PREFIX(getline)
        pre_fmtd_str pi_str = "getline(__lineptr, __n, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(lineptr, "__lineptr"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_getline(lineptr, n, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getline, abii_ret)
    return real_getline(lineptr, n, stream);
}

static int (*real_fputs)(const char*, FILE*) = nullptr;

extern "C" __nonnull((2))
int abii_fputs(const char* s, FILE* stream)
{
    OVERRIDE_PREFIX(fputs)
        pre_fmtd_str pi_str = "fputs(__s, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fputs(s, stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(fputs, abii_ret)
    return real_fputs(s, stream);
}

static int (*real_puts)(const char*) = nullptr;

extern "C" int abii_puts(const char* s)
{
    OVERRIDE_PREFIX(puts)
        pre_fmtd_str pi_str = "puts(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_puts(s);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(puts, abii_ret)
    return real_puts(s);
}

static int (*real_ungetc)(int, FILE*) = nullptr;

extern "C" __nonnull((2))
int abii_ungetc(int c, FILE* stream)
{
    OVERRIDE_PREFIX(ungetc)
        pre_fmtd_str pi_str = "ungetc(__c, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(c, "__c"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_ungetc(c, stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(ungetc, abii_ret)
    return real_ungetc(c, stream);
}

static size_t (*real_fread)(void*, size_t, size_t, FILE*) = nullptr;

extern "C" __wur __nonnull((4))
size_t abii_fread(void* ptr, size_t size, size_t n, FILE* stream)
{
    OVERRIDE_PREFIX(fread)
        pre_fmtd_str pi_str = "fread(__ptr, __size, __n, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fread(ptr, size, n, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fread, abii_ret)
    return real_fread(ptr, size, n, stream);
}

static size_t (*real_fwrite)(const void*, size_t, size_t, FILE*) = nullptr;

extern "C" __nonnull((4))
size_t abii_fwrite(const void* ptr, size_t size, size_t n, FILE* s)
{
    OVERRIDE_PREFIX(fwrite)
        pre_fmtd_str pi_str = "fwrite(__ptr, __size, __n, __s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_fwrite(ptr, size, n, s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fwrite, abii_ret)
    return real_fwrite(ptr, size, n, s);
}

static int (*real_fputs_unlocked)(const char*, FILE*) = nullptr;

extern "C" __nonnull((2))
int abii_fputs_unlocked(const char* s, FILE* stream)
{
    OVERRIDE_PREFIX(fputs_unlocked)
        pre_fmtd_str pi_str = "fputs_unlocked(__s, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fputs_unlocked(s, stream);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_stdio_eof, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(fputs_unlocked, abii_ret)
    return real_fputs_unlocked(s, stream);
}

static size_t (*real_fread_unlocked)(void*, size_t, size_t, FILE*) = nullptr;

extern "C" __wur __nonnull((4))
size_t abii_fread_unlocked(void* ptr, size_t size, size_t n, FILE* stream)
{
    OVERRIDE_PREFIX(fread_unlocked)
        pre_fmtd_str pi_str = "fread_unlocked(__ptr, __size, __n, __stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fread_unlocked(ptr, size, n, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fread_unlocked, abii_ret)
    return real_fread_unlocked(ptr, size, n, stream);
}

static size_t (*real_fwrite_unlocked)(const void*, size_t, size_t, FILE*) = nullptr;

extern "C" __nonnull((4))
size_t abii_fwrite_unlocked(const void* ptr, size_t size, size_t n, FILE* stream)
{
    OVERRIDE_PREFIX(fwrite_unlocked)
        pre_fmtd_str pi_str = "fwrite_unlocked(__ptr, __size, __n, __s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fwrite_unlocked(ptr, size, n, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fwrite_unlocked, abii_ret)
    return real_fwrite_unlocked(ptr, size, n, stream);
}

static int (*real_fseek)(FILE*, long int, int) = nullptr;

extern "C" __nonnull((1))
int abii_fseek(FILE* stream, long int off, int whence)
{
    OVERRIDE_PREFIX(fseek)
        pre_fmtd_str pi_str = "fseek(__stream, __off, __whence)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(off, "__off"));

        auto printer = new ArgPrinter(whence, "__whence");
        printer->set_enum_printer(print_stdio_seek_whence, whence);
        abii_args->push_arg(printer);

        auto abii_ret = real_fseek(stream, off, whence);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fseek, abii_ret)
    return real_fseek(stream, off, whence);
}

static long int (*real_ftell)(FILE*) = nullptr;

extern "C" __wur __nonnull((1))
long int abii_ftell(FILE* stream)
{
    OVERRIDE_PREFIX(ftell)
        pre_fmtd_str pi_str = "ftell(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_ftell(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ftell, abii_ret)
    return real_ftell(stream);
}

static void (*real_rewind)(FILE*) = nullptr;

extern "C" __nonnull((1))
void abii_rewind(FILE* stream)
{
    OVERRIDE_PREFIX(rewind)
        pre_fmtd_str pi_str = "rewind(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        real_rewind(stream);
    OVERRIDE_SUFFIX(rewind,)
    return real_rewind(stream);
}

static int (*real_fseeko)(FILE*, __off_t, int) = nullptr;

extern "C" __nonnull((1))
int abii_fseeko(FILE* stream, __off_t off, int whence)
{
    OVERRIDE_PREFIX(fseeko)
        pre_fmtd_str pi_str = "fseeko(__stream, __off, __whence)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(off, "__off"));

        auto printer = new ArgPrinter(whence, "__whence");
        printer->set_enum_printer(print_stdio_seek_whence, whence);
        abii_args->push_arg(printer);

        auto abii_ret = real_fseeko(stream, off, whence);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fseeko, abii_ret)
    return real_fseeko(stream, off, whence);
}

static __off_t (*real_ftello)(FILE*) = nullptr;

extern "C" __wur __nonnull((1))
long int abii_ftello(FILE* stream)
{
    OVERRIDE_PREFIX(ftello)
        pre_fmtd_str pi_str = "ftello(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_ftello(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ftello, abii_ret)
    return real_ftello(stream);
}

static int (*real_fgetpos)(FILE*, fpos_t*) = nullptr;

extern "C" __nonnull((1))
int abii_fgetpos(FILE* stream, fpos_t* pos)
{
    OVERRIDE_PREFIX(fgetpos)
        pre_fmtd_str pi_str = "fgetpos(__stream, __pos)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(pos, "__pos"));

        auto abii_ret = real_fgetpos(stream, pos);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetpos, abii_ret)
    return real_fgetpos(stream, pos);
}

static int (*real_fsetpos)(FILE*, const fpos_t*) = nullptr;

extern "C" __nonnull((1))
int abii_fsetpos(FILE* stream, const fpos_t* pos)
{
    OVERRIDE_PREFIX(fsetpos)
        pre_fmtd_str pi_str = "fsetpos(__stream, __pos)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(pos, "__pos"));

        auto abii_ret = real_fsetpos(stream, pos);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fsetpos, abii_ret)
    return real_fsetpos(stream, pos);
}

static int (*real_fseeko64)(FILE*, __off64_t, int) = nullptr;

extern "C" __nonnull((1))
int abii_fseeko64(FILE* stream, __off64_t off, int whence)
{
    OVERRIDE_PREFIX(fseeko64)
        pre_fmtd_str pi_str = "fseeko64(__stream, __off, __whence)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(off, "__off"));

        auto printer = new ArgPrinter(whence, "__whence");
        printer->set_enum_printer(print_stdio_seek_whence, whence);
        abii_args->push_arg(printer);

        auto abii_ret = real_fseeko64(stream, off, whence);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fseeko64, abii_ret)
    return real_fseeko64(stream, off, whence);
}

static __off64_t (*real_ftello64)(FILE*) = nullptr;

extern "C" __wur __nonnull((1))
__off64_t abii_ftello64(FILE* stream)
{
    OVERRIDE_PREFIX(ftello64)
        pre_fmtd_str pi_str = "ftello64(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_ftello64(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ftello64, abii_ret)
    return real_ftello64(stream);
}

static int (*real_fgetpos64)(FILE*, fpos64_t*) = nullptr;

extern "C" __nonnull((1))
int abii_fgetpos64(FILE* stream, fpos64_t* pos)
{
    OVERRIDE_PREFIX(fgetpos64)
        pre_fmtd_str pi_str = "fgetpos64(__stream, __pos)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(pos, "__pos"));

        auto abii_ret = real_fgetpos64(stream, pos);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetpos64, abii_ret)
    return real_fgetpos64(stream, pos);
}

static int (*real_fsetpos64)(FILE*, const fpos64_t*) = nullptr;

extern "C" __nonnull((1))
int abii_fsetpos64(FILE* stream, const fpos64_t* pos)
{
    OVERRIDE_PREFIX(fsetpos64)
        pre_fmtd_str pi_str = "fsetpos64(__stream, __pos)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(pos, "__pos"));

        auto abii_ret = real_fsetpos64(stream, pos);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fsetpos64, abii_ret)
    return real_fsetpos64(stream, pos);
}

static void (*real_clearerr)(FILE*) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_clearerr(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(clearerr)
        pre_fmtd_str pi_str = "clearerr(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        real_clearerr(stream);
    OVERRIDE_SUFFIX(clearerr,)
    return real_clearerr(stream);
}

static int (*real_feof)(FILE*) __THROW = nullptr;

extern "C" __wur __nonnull((1))
int abii_feof(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(feof)
        pre_fmtd_str pi_str = "feof(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_feof(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(feof, abii_ret)
    return real_feof(stream);
}

static int (*real_ferror)(FILE*) __THROW = nullptr;

extern "C" __wur __nonnull((1))
int abii_ferror(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(ferror)
        pre_fmtd_str pi_str = "ferror(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_ferror(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ferror, abii_ret)
    return real_ferror(stream);
}

static void (*real_clearerr_unlocked)(FILE*) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_clearerr_unlocked(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(clearerr_unlocked)
        pre_fmtd_str pi_str = "clearerr_unlocked(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        real_clearerr_unlocked(stream);
    OVERRIDE_SUFFIX(clearerr_unlocked,)
    return real_clearerr_unlocked(stream);
}

static int (*real_feof_unlocked)(FILE*) __THROW = nullptr;

extern "C" __wur __nonnull((1))
int abii_feof_unlocked(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(feof_unlocked)
        pre_fmtd_str pi_str = "feof_unlocked(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_feof_unlocked(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(feof_unlocked, abii_ret)
    return real_feof_unlocked(stream);
}

static int (*real_ferror_unlocked)(FILE*) __THROW = nullptr;

extern "C" __wur __nonnull((1))
int abii_ferror_unlocked(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(ferror_unlocked)
        pre_fmtd_str pi_str = "ferror_unlocked(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_ferror_unlocked(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ferror_unlocked, abii_ret)
    return real_ferror_unlocked(stream);
}

static void (*real_perror)(const char*) = nullptr;

extern "C" __COLD
void abii_perror(const char* s)
{
    OVERRIDE_PREFIX(perror)
        pre_fmtd_str pi_str = "perror(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        real_perror(s);
    OVERRIDE_SUFFIX(perror,)
    return real_perror(s);
}

static int (*real_fileno)(FILE*) __THROW = nullptr;

extern "C" __wur __nonnull((1))
int abii_fileno(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(fileno)
        pre_fmtd_str pi_str = "fileno(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fileno(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fileno, abii_ret)
    return real_fileno(stream);
}

static int (*real_fileno_unlocked)(FILE*) __THROW = nullptr;

extern "C" __wur __nonnull((1))
int abii_fileno_unlocked(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(fileno_unlocked)
        pre_fmtd_str pi_str = "fileno_unlocked(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fileno_unlocked(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fileno_unlocked, abii_ret)
    return real_fileno_unlocked(stream);
}

static int (*real_pclose)(FILE*) = nullptr;

extern "C" __nonnull((1))
int abii_pclose(FILE* stream)
{
    OVERRIDE_PREFIX(pclose)
        pre_fmtd_str pi_str = "pclose(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_pclose(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pclose, abii_ret)
    return real_pclose(stream);
}

static FILE* (*real_popen)(const char*, const char*) = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc(pclose, 1) __wur
FILE* abii_popen(const char* command, const char* modes)
{
    OVERRIDE_PREFIX(popen)
        pre_fmtd_str pi_str = "popen(__command, __modes)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(command, "__command"));
        abii_args->push_arg(new ArgPrinter(modes, "__modes"));

        auto abii_ret = real_popen(command, modes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(popen, abii_ret)
    return real_popen(command, modes);
}

static char* (*real_ctermid)(char*) __THROW = nullptr;

extern "C" __attr_access((__write_only__, 1))
char* abii_ctermid(char* s) __THROW
{
    OVERRIDE_PREFIX(ctermid)
        pre_fmtd_str pi_str = "ctermid(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_ctermid(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ctermid, abii_ret)
    return real_ctermid(s);
}

static char* (*real_cuserid)(char*) = nullptr;

extern "C" __attr_access((__write_only__, 1))
char* abii_cuserid(char* s)
{
    OVERRIDE_PREFIX(cuserid)
        pre_fmtd_str pi_str = "cuserid(__s)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));

        auto abii_ret = real_cuserid(s);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cuserid, abii_ret)
    return real_cuserid(s);
}

static int (*real_obstack_printf)(obstack*, const char*, ...) __THROWNL = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 2, 3)))
int abii_obstack_printf(obstack* obstack, const char* format, ...) __THROWNL
{
    OVERRIDE_VARIADIC_PREFIX(obstack_printf, format)
        pre_fmtd_str str = "obstack_printf(__obstack, __format, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(obstack, "__obstack"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        PUSH_VARIADIC_ARGS(printer, format, print_variadic_args_printf)

        auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_obstack_printf), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter<int>(*reinterpret_cast<int*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(obstack_printf, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_obstack_printf), abii_bi_vargs, 1000));
}

static int (*real_obstack_vprintf)(obstack*, const char*, __gnuc_va_list) __THROWNL = nullptr;

extern "C" __attribute__ ((__format__ (__printf__, 2, 0)))
int abii_obstack_vprintf(obstack* obstack, const char* format, __gnuc_va_list args) __THROWNL
{
    OVERRIDE_VALIST_PREFIX(obstack_vprintf, f, args)
        pre_fmtd_str str = "obstack_vprintf(__obstack, __format, __args)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(obstack, "__obstack"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));

        PUSH_VALIST_ARGS(printer, format, args, "__args", print_variadic_args_printf)

        auto abii_ret = real_obstack_vprintf(obstack, format, abii_vargs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_VALIST_SUFFIX(obstack_vprintf, abii_ret, args)
    return real_obstack_vprintf(obstack, format, args);
}

static void (*real_flockfile)(FILE*) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_flockfile(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(flockfile)
        pre_fmtd_str pi_str = "flockfile(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        real_flockfile(stream);
    OVERRIDE_SUFFIX(flockfile,)
    return real_flockfile(stream);
}

static int (*real_ftrylockfile)(FILE*) __THROW = nullptr;

extern "C" __wur __nonnull((1))
int abii_ftrylockfile(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(ftrylockfile)
        pre_fmtd_str pi_str = "ftrylockfile(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_ftrylockfile(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ftrylockfile, abii_ret)
    return real_ftrylockfile(stream);
}

static void (*real_funlockfile)(FILE*) __THROW = nullptr;

extern "C" __nonnull((1))
void abii_funlockfile(FILE* stream) __THROW
{
    OVERRIDE_PREFIX(funlockfile)
        pre_fmtd_str pi_str = "funlockfile(__stream)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        real_funlockfile(stream);
    OVERRIDE_SUFFIX(funlockfile,)
    return real_funlockfile(stream);
}

static int (*real___uflow)(FILE*) = nullptr;

extern "C" int abii___uflow(FILE* f)
{
    OVERRIDE_PREFIX(__uflow)
        pre_fmtd_str pi_str = "__uflow(f)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(f, "f"));

        auto abii_ret = real___uflow(f);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__uflow, abii_ret)
    return real___uflow(f);
}

static int (*real___overflow)(FILE*, int) = nullptr;

extern "C" int abii___overflow(FILE* f, int c)
{
    OVERRIDE_PREFIX(__overflow)
        pre_fmtd_str pi_str = "__overflow(f, _c)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(f, "f"));
        abii_args->push_arg(new ArgPrinter(c, "_c"));

        auto abii_ret = real___overflow(f, c);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__overflow, abii_ret)
    return real___overflow(f, c);
}
}
