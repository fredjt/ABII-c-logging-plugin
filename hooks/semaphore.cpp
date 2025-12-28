//
// Created by Trent Tanchin on 5/23/25.
//

#include "bits/semaphore.h"

#include <semaphore.h>
#include <abii/libabii.h>

#include "bits/fcntl-linux.h"
#include "bits/time.h"
#include "bits/types/struct_timespec.h"

namespace abii
{
static int (*real_sem_init)(sem_t*, int, unsigned int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sem_init(sem_t* sem, int pshared, unsigned int value) __THROW
{
    OVERRIDE_PREFIX(sem_init)
        pre_fmtd_str pi_str = "sem_init(__sem, __pshared, __value)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sem, "__sem"));
        abii_args->push_arg(new ArgPrinter(pshared, "__pshared"));
        abii_args->push_arg(new ArgPrinter(value, "__value"));

        auto abii_ret = real_sem_init(sem, pshared, value);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_init, abii_ret)
    return real_sem_init(sem, pshared, value);
}

static int (*real_sem_destroy)(sem_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sem_destroy(sem_t* sem) __THROW
{
    OVERRIDE_PREFIX(sem_destroy)
        pre_fmtd_str pi_str = "sem_destroy(__sem)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sem, "__sem"));

        auto abii_ret = real_sem_destroy(sem);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_destroy, abii_ret)
    return real_sem_destroy(sem);
}

static sem_t* (*real_sem_open)(const char*, int, ...) __THROW = nullptr;

extern "C" __nonnull((1))
sem_t* abii_sem_open(const char* name, int oflag, ...) __THROW
{
    OVERRIDE_PREFIX(sem_open)
        pre_fmtd_str str = "sem_open(__name, __oflag, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        sem_t* abii_ret = nullptr;
        if (oflag == O_CREAT)
        {
            va_list vargs;
            va_start(vargs, oflag);
            auto mode = va_arg(vargs, mode_t);
            auto value = va_arg(vargs, unsigned int);

            auto printer1 = new ArgPrinter(mode, "__mode");
            printer1->set_enum_printer(print_fcntl_linux_oflag, mode);
            abii_args->push_arg(printer1);

            abii_args->push_arg(new ArgPrinter(value, "__value"));
            va_end(vargs);
            abii_ret = real_sem_open(name, oflag, mode, value);
        }
        else
            abii_ret = real_sem_open(name, oflag);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));

    OVERRIDE_SUFFIX(sem_open, abii_ret)
    auto pi_bi_vargs = __builtin_apply_args();
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_sem_open), pi_bi_vargs, 1000));
}

static int (*real_sem_close)(sem_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sem_close(sem_t* sem) __THROW
{
    OVERRIDE_PREFIX(sem_close)
        pre_fmtd_str pi_str = "sem_close(__sem)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sem, "__sem"));

        auto abii_ret = real_sem_close(sem);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_close, abii_ret)
    return real_sem_close(sem);
}

static int (*real_sem_unlink)(const char*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sem_unlink(const char* name) __THROW
{
    OVERRIDE_PREFIX(sem_unlink)
        pre_fmtd_str pi_str = "sem_unlink(__name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_sem_unlink(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_unlink, abii_ret)
    return real_sem_unlink(name);
}

static int (*real_sem_wait)(sem_t*) = nullptr;

extern "C" __nonnull((1))
int abii_sem_wait(sem_t* sem)
{
    OVERRIDE_PREFIX(sem_wait)
        pre_fmtd_str pi_str = "sem_wait(__sem)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sem, "__sem"));

        auto abii_ret = real_sem_wait(sem);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_wait, abii_ret)
    return real_sem_wait(sem);
}

static int (*real_sem_timedwait)(sem_t*, const timespec*) = nullptr;

extern "C" __nonnull((1, 2))
int abii_sem_timedwait(sem_t* sem, const timespec* abstime)
{
    OVERRIDE_PREFIX(sem_timedwait)
        pre_fmtd_str pi_str = "sem_timedwait(__sem, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sem, "__sem"));
        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_sem_timedwait(sem, abstime);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_timedwait, abii_ret)
    return real_sem_timedwait(sem, abstime);
}

static int (*real_sem_clockwait)(sem_t*, clockid_t, const timespec*) = nullptr;

extern "C" __nonnull((1, 3))
int abii_sem_clockwait(sem_t* sem, clockid_t clock, const timespec* abstime)
{
    OVERRIDE_PREFIX(sem_clockwait)
        pre_fmtd_str pi_str = "sem_clockwait(__sem, clock, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sem, "__sem"));

        auto printer = new ArgPrinter(clock, "clock");
        printer->set_enum_printer(print_time_clock, clock);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_sem_clockwait(sem, clock, abstime);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_clockwait, abii_ret)
    return real_sem_clockwait(sem, clock, abstime);
}

static int (*real_sem_trywait)(sem_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sem_trywait(sem_t* sem) __THROWNL
{
    OVERRIDE_PREFIX(sem_trywait)
        pre_fmtd_str pi_str = "sem_trywait(__sem)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sem, "__sem"));

        auto abii_ret = real_sem_trywait(sem);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_trywait, abii_ret)
    return real_sem_trywait(sem);
}

static int (*real_sem_post)(sem_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_sem_post(sem_t* sem) __THROWNL
{
    OVERRIDE_PREFIX(sem_post)
        pre_fmtd_str pi_str = "sem_post(__sem)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sem, "__sem"));

        auto abii_ret = real_sem_post(sem);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_post, abii_ret)
    return real_sem_post(sem);
}

static int (*real_sem_getvalue)(sem_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_sem_getvalue(sem_t* sem, int* sval) __THROW
{
    OVERRIDE_PREFIX(sem_getvalue)
        pre_fmtd_str pi_str = "sem_getvalue(__sem, __sval)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(sem, "__sem"));
        abii_args->push_arg(new ArgPrinter(sval, "__sval"));

        auto abii_ret = real_sem_getvalue(sem, sval);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sem_getvalue, abii_ret)
    return real_sem_getvalue(sem, sval);
}
}
