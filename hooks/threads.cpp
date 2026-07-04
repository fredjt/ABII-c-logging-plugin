//
// Created by Trent Tanchin on 7/4/26.
//

#include "threads.h"

#include <abii/libabii.h>

#include "bits/thread-shared-types.h"
#include "bits/types/struct_timespec.h"

namespace abii
{
static int (*real_thrd_create)(thrd_t*, thrd_start_t, void*) = nullptr;

extern "C" int abii_thrd_create(thrd_t* thr, thrd_start_t func, void* arg)
{
    OVERRIDE_PREFIX(thrd_create)
        pre_fmtd_str pi_str = "thrd_create(__thr, __func, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(thr, "__thr"));
        abii_args->push_arg(new ArgPrinter(func, "__func"));
        abii_args->push_arg(new ArgPrinter(arg, "__arg"));

        auto abii_ret = real_thrd_create(thr, func, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(thrd_create, abii_ret)
    return real_thrd_create(thr, func, arg);
}

static int (*real_thrd_equal)(thrd_t, thrd_t) = nullptr;

extern "C" int abii_thrd_equal(thrd_t lhs, thrd_t rhs)
{
    OVERRIDE_PREFIX(thrd_equal)
        pre_fmtd_str pi_str = "thrd_equal(__lhs, __rhs)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(lhs, "__lhs"));
        abii_args->push_arg(new ArgPrinter(rhs, "__rhs"));

        auto abii_ret = real_thrd_equal(lhs, rhs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(thrd_equal, abii_ret)
    return real_thrd_equal(lhs, rhs);
}

static thrd_t (*real_thrd_current)() = nullptr;

extern "C" thrd_t abii_thrd_current()
{
    OVERRIDE_PREFIX(thrd_current)
        pre_fmtd_str pi_str = "thrd_current()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_thrd_current();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(thrd_current, abii_ret)
    return real_thrd_current();
}

static int (*real_thrd_sleep)(const timespec*, timespec*) = nullptr;

extern "C" int abii_thrd_sleep(const timespec* time_point, timespec* remaining)
{
    OVERRIDE_PREFIX(thrd_sleep)
        pre_fmtd_str pi_str = "thrd_sleep(__time_point, __remaining)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(time_point, "__time_point"));
        abii_args->push_arg(new ArgPrinter(remaining, "__remaining"));

        auto abii_ret = real_thrd_sleep(time_point, remaining);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(thrd_sleep, abii_ret)
    return real_thrd_sleep(time_point, remaining);
}

static __attribute__ ((__noreturn__)) void (*real_thrd_exit)(int) = nullptr;

extern "C" __attribute__ ((__noreturn__))
void abii_thrd_exit(int res)
{
    OVERRIDE_PREFIX(thrd_exit)
        pre_fmtd_str pi_str = "thrd_exit(__res)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(res, "__res"));

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        real_thrd_exit(res);
    }
    if (real_thrd_exit == nullptr)
    {
        real_thrd_exit = reinterpret_cast<decltype(real_thrd_exit)>(dlsym(RTLD_NEXT, "thrd_exit"));
        if (real_thrd_exit == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real_thrd_exit(res);
}

static int (*real_thrd_detach)(thrd_t) = nullptr;

extern "C" int abii_thrd_detach(thrd_t thr)
{
    OVERRIDE_PREFIX(thrd_detach)
        pre_fmtd_str pi_str = "thrd_detach(__thr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(thr, "__thr"));

        auto abii_ret = real_thrd_detach(thr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(thrd_detach, abii_ret)
    return real_thrd_detach(thr);
}

static int (*real_thrd_join)(thrd_t, int*) = nullptr;

extern "C" int abii_thrd_join(thrd_t thr, int* res)
{
    OVERRIDE_PREFIX(thrd_join)
        pre_fmtd_str pi_str = "thrd_join(__thr, __res)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(thr, "__thr"));
        abii_args->push_arg(new ArgPrinter(res, "__res"));

        auto abii_ret = real_thrd_join(thr, res);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(thrd_join, abii_ret)
    return real_thrd_join(thr, res);
}

static void (*real_thrd_yield)() = nullptr;

extern "C" void abii_thrd_yield()
{
    OVERRIDE_PREFIX(thrd_yield)
        pre_fmtd_str pi_str = "thrd_yield()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_thrd_yield();
    OVERRIDE_SUFFIX(thrd_yield,)
    return real_thrd_yield();
}

static int (*real_mtx_init)(mtx_t*, int) = nullptr;

extern "C" int abii_mtx_init(mtx_t* mutex, int type)
{
    OVERRIDE_PREFIX(mtx_init)
        pre_fmtd_str pi_str = "mtx_init(__mutex, __type)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto printer = new ArgPrinter(type, "__type");
        printer->set_enum_printer(print_threads_mtx, type);
        abii_args->push_arg(printer);

        auto abii_ret = real_mtx_init(mutex, type);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mtx_init, abii_ret)
    return real_mtx_init(mutex, type);
}

static int (*real_mtx_lock)(mtx_t*) = nullptr;

extern "C" int abii_mtx_lock(mtx_t* mutex)
{
    OVERRIDE_PREFIX(mtx_lock)
        pre_fmtd_str pi_str = "mtx_lock(__mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_mtx_lock(mutex);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mtx_lock, abii_ret)
    return real_mtx_lock(mutex);
}

static int (*real_mtx_timedlock)(mtx_t*, const timespec*) = nullptr;

extern "C" int abii_mtx_timedlock(mtx_t* mutex, const timespec* time_point)
{
    OVERRIDE_PREFIX(mtx_timedlock)
        pre_fmtd_str pi_str = "mtx_timedlock(__mutex, __time_point)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));
        abii_args->push_arg(new ArgPrinter(time_point, "__time_point"));

        auto abii_ret = real_mtx_timedlock(mutex, time_point);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mtx_timedlock, abii_ret)
    return real_mtx_timedlock(mutex, time_point);
}

static int (*real_mtx_trylock)(mtx_t*) = nullptr;

extern "C" int abii_mtx_trylock(mtx_t* mutex)
{
    OVERRIDE_PREFIX(mtx_trylock)
        pre_fmtd_str pi_str = "mtx_trylock(__mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_mtx_trylock(mutex);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mtx_trylock, abii_ret)
    return real_mtx_trylock(mutex);
}

static int (*real_mtx_unlock)(mtx_t*) = nullptr;

extern "C" int abii_mtx_unlock(mtx_t* mutex)
{
    OVERRIDE_PREFIX(mtx_unlock)
        pre_fmtd_str pi_str = "mtx_unlock(__mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_mtx_unlock(mutex);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mtx_unlock, abii_ret)
    return real_mtx_unlock(mutex);
}

static void (*real_mtx_destroy)(mtx_t*) = nullptr;

extern "C" void abii_mtx_destroy(mtx_t* mutex)
{
    OVERRIDE_PREFIX(mtx_destroy)
        pre_fmtd_str pi_str = "mtx_destroy(__mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        real_mtx_destroy(mutex);
    OVERRIDE_SUFFIX(mtx_destroy,)
    return real_mtx_destroy(mutex);
}

static void (*real_call_once)(once_flag*, void (*)()) = nullptr;

extern "C" void abii_call_once(once_flag* flag, void (*func)())
{
    OVERRIDE_PREFIX(call_once)
        pre_fmtd_str pi_str = "call_once(__flag, __func)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(flag, "__flag"));
        abii_args->push_arg(new ArgPrinter(func, "__func"));

        real_call_once(flag, func);
    OVERRIDE_SUFFIX(call_once,)
    return real_call_once(flag, func);
}

static int (*real_cnd_init)(cnd_t*) = nullptr;

extern "C" int abii_cnd_init(cnd_t* cond)
{
    OVERRIDE_PREFIX(cnd_init)
        pre_fmtd_str pi_str = "cnd_init(__cond)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));

        auto abii_ret = real_cnd_init(cond);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cnd_init, abii_ret)
    return real_cnd_init(cond);
}

static int (*real_cnd_signal)(cnd_t*) = nullptr;

extern "C" int abii_cnd_signal(cnd_t* cond)
{
    OVERRIDE_PREFIX(cnd_signal)
        pre_fmtd_str pi_str = "cnd_signal(__cond)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));

        auto abii_ret = real_cnd_signal(cond);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cnd_signal, abii_ret)
    return real_cnd_signal(cond);
}

static int (*real_cnd_broadcast)(cnd_t*) = nullptr;

extern "C" int abii_cnd_broadcast(cnd_t* cond)
{
    OVERRIDE_PREFIX(cnd_broadcast)
        pre_fmtd_str pi_str = "cnd_broadcast(__cond)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));

        auto abii_ret = real_cnd_broadcast(cond);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cnd_broadcast, abii_ret)
    return real_cnd_broadcast(cond);
}

static int (*real_cnd_wait)(cnd_t*, mtx_t*) = nullptr;

extern "C" int abii_cnd_wait(cnd_t* cond, mtx_t* mutex)
{
    OVERRIDE_PREFIX(cnd_wait)
        pre_fmtd_str pi_str = "cnd_wait(__cond, __mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));
        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_cnd_wait(cond, mutex);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cnd_wait, abii_ret)
    return real_cnd_wait(cond, mutex);
}

static int (*real_cnd_timedwait)(cnd_t*, mtx_t*, const timespec*) = nullptr;

extern "C" int abii_cnd_timedwait(cnd_t* cond, mtx_t* mutex, const timespec* time_point)
{
    OVERRIDE_PREFIX(cnd_timedwait)
        pre_fmtd_str pi_str = "cnd_timedwait(__cond, __mutex, __time_point)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));
        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));
        abii_args->push_arg(new ArgPrinter(time_point, "__time_point"));

        auto abii_ret = real_cnd_timedwait(cond, mutex, time_point);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(cnd_timedwait, abii_ret)
    return real_cnd_timedwait(cond, mutex, time_point);
}

static void (*real_cnd_destroy)(cnd_t*) = nullptr;

extern "C" void abii_cnd_destroy(cnd_t* COND)
{
    OVERRIDE_PREFIX(cnd_destroy)
        pre_fmtd_str pi_str = "cnd_destroy(__COND)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(COND, "__COND"));

        real_cnd_destroy(COND);
    OVERRIDE_SUFFIX(cnd_destroy,)
    return real_cnd_destroy(COND);
}

static int (*real_tss_create)(tss_t*, tss_dtor_t) = nullptr;

extern "C" int abii_tss_create(tss_t* tss_id, tss_dtor_t destructor)
{
    OVERRIDE_PREFIX(tss_create)
        pre_fmtd_str pi_str = "tss_create(__tss_id, __destructor)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tss_id, "__tss_id"));
        abii_args->push_arg(new ArgPrinter(destructor, "__destructor"));

        auto abii_ret = real_tss_create(tss_id, destructor);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tss_create, abii_ret)
    return real_tss_create(tss_id, destructor);
}

static void* (*real_tss_get)(tss_t) = nullptr;

extern "C" void* abii_tss_get(tss_t tss_id)
{
    OVERRIDE_PREFIX(tss_get)
        pre_fmtd_str pi_str = "tss_get(__tss_id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tss_id, "__tss_id"));

        auto abii_ret = real_tss_get(tss_id);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tss_get, abii_ret)
    return real_tss_get(tss_id);
}

static int (*real_tss_set)(tss_t, void*) = nullptr;

extern "C" int abii_tss_set(tss_t tss_id, void* val)
{
    OVERRIDE_PREFIX(tss_set)
        pre_fmtd_str pi_str = "tss_set(__tss_id, __val)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tss_id, "__tss_id"));
        abii_args->push_arg(new ArgPrinter(val, "__val"));

        auto abii_ret = real_tss_set(tss_id, val);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tss_set, abii_ret)
    return real_tss_set(tss_id, val);
}

static void (*real_tss_delete)(tss_t) = nullptr;

extern "C" void abii_tss_delete(tss_t tss_id)
{
    OVERRIDE_PREFIX(tss_delete)
        pre_fmtd_str pi_str = "tss_delete(__tss_id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tss_id, "__tss_id"));

        real_tss_delete(tss_id);
    OVERRIDE_SUFFIX(tss_delete,)
    return real_tss_delete(tss_id);
}
}
