//
// Created by Trent Tanchin on 2/4/25.
//

#include "pthread.h"

#include "custom_enum_printers.h"
#include "bits/cpu-set.h"
#include "bits/pthreadtypes.h"
#include "bits/sched.h"
#include "bits/time.h"
#include "bits/types/struct_sched_param.h"
#include "bits/types/struct_timespec.h"
#include "bits/types/struct___jmp_buf_tag.h"
#include "bits/types/__sigset_t.h"

namespace abii
{
static int (*real_pthread_create)(pthread_t*, const pthread_attr_t*, void*(*)(void*), void*) __THROWNL = nullptr;

extern "C" __nonnull((1, 3))
int abii_pthread_create(pthread_t* newthread, const pthread_attr_t* attr, void*(*start_routine)(void*),
                        void* arg) __THROWNL
{
    OVERRIDE_PREFIX(pthread_create)
        pre_fmtd_str pi_str = "pthread_create(__newthread, __attr, __start_routine, __arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(newthread, "__newthread"));
        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(start_routine, "__start_routine"));
        abii_args->push_arg(new ArgPrinter(arg, "__arg"));

        auto abii_ret = real_pthread_create(newthread, attr, start_routine, arg);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_create, abii_ret)
    return real_pthread_create(newthread, attr, start_routine, arg);
}

static void (*real_pthread_exit)(void*) = nullptr;

extern "C" __attribute__ ((__noreturn__))
void abii_pthread_exit(void* retval)
{
    OVERRIDE_PREFIX(pthread_exit)
        pre_fmtd_str pi_str = "pthread_exit(__retval)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(retval, "__retval"));

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        real_pthread_exit(retval);

        ENABLE_OVERRIDES
    }
    if (real_pthread_exit == nullptr)
    {
        real_pthread_exit = reinterpret_cast<decltype(real_pthread_exit)>(dlsym(RTLD_NEXT, "pthread_exit"));
        if (real_pthread_exit == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real_pthread_exit(retval);
}

static int (*real_pthread_join)(pthread_t, void**) = nullptr;

extern "C" int abii_pthread_join(pthread_t th, void** thread_return)
{
    OVERRIDE_PREFIX(pthread_join)
        pre_fmtd_str pi_str = "pthread_join(__th, __thread_return)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));

        auto printer = new ArgPrinter(thread_return, "__thread_return");
        printer->set_enum_printer(print_pthread_cancelled, *thread_return);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_join(th, thread_return);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_join, abii_ret)
    return real_pthread_join(th, thread_return);
}

static int (*real_pthread_tryjoin_np)(pthread_t, void**) __THROW = nullptr;

extern "C" int abii_pthread_tryjoin_np(pthread_t th, void** thread_return) __THROW
{
    OVERRIDE_PREFIX(pthread_tryjoin_np)
        pre_fmtd_str pi_str = "pthread_tryjoin_np(__th, __thread_return)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(thread_return, "__thread_return"));

        auto abii_ret = real_pthread_tryjoin_np(th, thread_return);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_tryjoin_np, abii_ret)
    return real_pthread_tryjoin_np(th, thread_return);
}

static int (*real_pthread_timedjoin_np)(pthread_t, void**, const timespec*) = nullptr;

extern "C" int abii_pthread_timedjoin_np(pthread_t th, void** thread_return, const timespec* abstime)
{
    OVERRIDE_PREFIX(pthread_timedjoin_np)
        pre_fmtd_str pi_str = "pthread_timedjoin_np(__th, __thread_return, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(thread_return, "__thread_return"));
        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_timedjoin_np(th, thread_return, abstime);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_timedjoin_np, abii_ret)
    return real_pthread_timedjoin_np(th, thread_return, abstime);
}

static int (*real_pthread_clockjoin_np)(pthread_t, void**, clockid_t, const timespec*) = nullptr;

extern "C" int abii_pthread_clockjoin_np(pthread_t th, void** thread_return, clockid_t clockid, const timespec* abstime)
{
    OVERRIDE_PREFIX(pthread_clockjoin_np)
        pre_fmtd_str pi_str = "pthread_clockjoin_np(__th, __thread_return, __clockid, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(thread_return, "__thread_return"));

        auto printer = new ArgPrinter(clockid, "__clockid");
        printer->set_enum_printer(print_time_clock, clockid);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_clockjoin_np(th, thread_return, clockid, abstime);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_clockjoin_np, abii_ret)
    return real_pthread_clockjoin_np(th, thread_return, clockid, abstime);
}

static int (*real_pthread_detach)(pthread_t) __THROW = nullptr;

extern "C" int abii_pthread_detach(pthread_t th) __THROW
{
    OVERRIDE_PREFIX(pthread_detach)
        pre_fmtd_str pi_str = "pthread_detach(__th)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));

        auto abii_ret = real_pthread_detach(th);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_detach, abii_ret)
    return real_pthread_detach(th);
}

static pthread_t (*real_pthread_self)() __THROW = nullptr;

extern "C" __attribute__ ((__const__))
pthread_t abii_pthread_self() __THROW
{
    OVERRIDE_PREFIX(pthread_self)
        pre_fmtd_str pi_str = "pthread_self()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_pthread_self();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pthread_self, abii_ret)
    return real_pthread_self();
}

static int (*real_pthread_equal)(pthread_t, pthread_t) __THROW = nullptr;

extern "C" __attribute__ ((__const__))
int abii_pthread_equal(pthread_t thread1, pthread_t thread2) __THROW
{
    OVERRIDE_PREFIX(pthread_equal)
        pre_fmtd_str pi_str = "pthread_equal(__thread1, __thread2)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(thread1, "__thread1"));
        abii_args->push_arg(new ArgPrinter(thread2, "__thread2"));

        auto abii_ret = real_pthread_equal(thread1, thread2);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pthread_equal, abii_ret)
    return real_pthread_equal(thread1, thread2);
}

static int (*real_pthread_attr_init)(pthread_attr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_attr_init(pthread_attr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_init)
        pre_fmtd_str pi_str = "pthread_attr_init(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_attr_init(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_init, abii_ret)
    return real_pthread_attr_init(attr);
}

static int (*real_pthread_attr_destroy)(pthread_attr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_attr_destroy(pthread_attr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_destroy)
        pre_fmtd_str pi_str = "pthread_attr_destroy(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_attr_destroy(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_destroy, abii_ret)
    return real_pthread_attr_destroy(attr);
}

static int (*real_pthread_attr_getdetachstate)(const pthread_attr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_attr_getdetachstate(const pthread_attr_t* attr, int* detachstate) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getdetachstate)
        pre_fmtd_str pi_str = "pthread_attr_getdetachstate(__attr, __detachstate)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(detachstate, "__detachstate");
        printer->set_enum_printer_with_depth(print_pthread_detach_state, *detachstate, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_attr_getdetachstate(attr, detachstate);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_attr_getdetachstate, abii_ret)
    return real_pthread_attr_getdetachstate(attr, detachstate);
}

static int (*real_pthread_attr_setdetachstate)(pthread_attr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_attr_setdetachstate(pthread_attr_t* attr, int detachstate) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setdetachstate)
        pre_fmtd_str pi_str = "pthread_attr_setdetachstate(__attr, __detachstate)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(detachstate, "__detachstate");
        printer->set_enum_printer(print_pthread_detach_state, detachstate);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_attr_setdetachstate(attr, detachstate);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_attr_setdetachstate, abii_ret)
    return real_pthread_attr_setdetachstate(attr, detachstate);
}

static int (*real_pthread_attr_getguardsize)(const pthread_attr_t*, size_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_attr_getguardsize(const pthread_attr_t* attr, size_t* guardsize) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getguardsize)
        pre_fmtd_str pi_str = "pthread_attr_getguardsize(__attr, __guardsize)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(guardsize, "__guardsize"));

        auto abii_ret = real_pthread_attr_getguardsize(attr, guardsize);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_getguardsize, abii_ret)
    return real_pthread_attr_getguardsize(attr, guardsize);
}

static int (*real_pthread_attr_setguardsize)(pthread_attr_t*, size_t) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_attr_setguardsize(pthread_attr_t* attr, size_t guardsize) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setguardsize)
        pre_fmtd_str pi_str = "pthread_attr_setguardsize(__attr, __guardsize)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(guardsize, "__guardsize"));

        auto abii_ret = real_pthread_attr_setguardsize(attr, guardsize);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_setguardsize, abii_ret)
    return real_pthread_attr_setguardsize(attr, guardsize);
}

static int (*real_pthread_attr_getschedparam)(const pthread_attr_t*, sched_param*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_attr_getschedparam(const pthread_attr_t* attr, sched_param* param) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getschedparam)
        pre_fmtd_str pi_str = "pthread_attr_getschedparam(__attr, __param)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(param, "__param"));

        auto abii_ret = real_pthread_attr_getschedparam(attr, param);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_getschedparam, abii_ret)
    return real_pthread_attr_getschedparam(attr, param);
}

static int (*real_pthread_attr_setschedparam)(pthread_attr_t*, const sched_param*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_attr_setschedparam(pthread_attr_t* attr, const sched_param* param) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setschedparam)
        pre_fmtd_str pi_str = "pthread_attr_setschedparam(__attr, __param)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(param, "__param"));

        auto abii_ret = real_pthread_attr_setschedparam(attr, param);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_setschedparam, abii_ret)
    return real_pthread_attr_setschedparam(attr, param);
}

static int (*real_pthread_attr_getschedpolicy)(const pthread_attr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_attr_getschedpolicy(const pthread_attr_t* attr, int* policy) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getschedpolicy)
        pre_fmtd_str pi_str = "pthread_attr_getschedpolicy(__attr, __policy)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(policy, "__policy");
        printer->set_enum_printer_with_depth(print_sched_algorithm, *policy, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_attr_getschedpolicy(attr, policy);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_attr_getschedpolicy, abii_ret)
    return real_pthread_attr_getschedpolicy(attr, policy);
}

static int (*real_pthread_attr_setschedpolicy)(pthread_attr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_attr_setschedpolicy(pthread_attr_t* attr, int policy) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setschedpolicy)
        pre_fmtd_str pi_str = "pthread_attr_setschedpolicy(__attr, __policy)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(policy, "__policy");
        printer->set_enum_printer(print_sched_algorithm, policy);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_attr_setschedpolicy(attr, policy);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_attr_setschedpolicy, abii_ret)
    return real_pthread_attr_setschedpolicy(attr, policy);
}

static int (*real_pthread_attr_getinheritsched)(const pthread_attr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_attr_getinheritsched(const pthread_attr_t* attr, int* inherit) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getinheritsched)
        pre_fmtd_str pi_str = "pthread_attr_getinheritsched(__attr, __inherit)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(inherit, "__inherit");
        printer->set_enum_printer_with_depth(print_pthread_scheduler_inheritance, *inherit, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_attr_getinheritsched(attr, inherit);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_attr_getinheritsched, abii_ret)
    return real_pthread_attr_getinheritsched(attr, inherit);
}

static int (*real_pthread_attr_setinheritsched)(pthread_attr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_attr_setinheritsched(pthread_attr_t* attr, int inherit) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setinheritsched)
        pre_fmtd_str pi_str = "pthread_attr_setinheritsched(__attr, __inherit)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(inherit, "__inherit");
        printer->set_enum_printer(print_pthread_scheduler_inheritance, inherit);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_attr_setinheritsched(attr, inherit);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_attr_setinheritsched, abii_ret)
    return real_pthread_attr_setinheritsched(attr, inherit);
}

static int (*real_pthread_attr_getscope)(const pthread_attr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_attr_getscope(const pthread_attr_t* attr, int* scope) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getscope)
        pre_fmtd_str pi_str = "pthread_attr_getscope(__attr, __scope)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(scope, "__scope");
        printer->set_enum_printer_with_depth(print_pthread_scope_handling, *scope, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_attr_getscope(attr, scope);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_attr_getscope, abii_ret)
    return real_pthread_attr_getscope(attr, scope);
}

static int (*real_pthread_attr_setscope)(pthread_attr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_attr_setscope(pthread_attr_t* attr, int scope) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setscope)
        pre_fmtd_str pi_str = "pthread_attr_setscope(__attr, __scope)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(scope, "__scope");
        printer->set_enum_printer(print_pthread_scope_handling, scope);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_attr_setscope(attr, scope);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_attr_setscope, abii_ret)
    return real_pthread_attr_setscope(attr, scope);
}

static int (*real_pthread_attr_getstackaddr)(const pthread_attr_t*, void**) __THROW = nullptr;

extern "C" __nonnull((1, 2)) __attribute_deprecated__
int abii_pthread_attr_getstackaddr(const pthread_attr_t* attr, void** stackaddr) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getstackaddr)
        pre_fmtd_str pi_str = "pthread_attr_getstackaddr(__attr, __stackaddr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(stackaddr, "__stackaddr"));

        auto abii_ret = real_pthread_attr_getstackaddr(attr, stackaddr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_getstackaddr, abii_ret)
    return real_pthread_attr_getstackaddr(attr, stackaddr);
}

static int (*real_pthread_attr_setstackaddr)(pthread_attr_t*, void*) __THROW = nullptr;

extern "C" __nonnull((1)) __attribute_deprecated__
int abii_pthread_attr_setstackaddr(pthread_attr_t* attr, void* stackaddr) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setstackaddr)
        pre_fmtd_str pi_str = "pthread_attr_setstackaddr(__attr, __stackaddr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(stackaddr, "__stackaddr"));

        auto abii_ret = real_pthread_attr_setstackaddr(attr, stackaddr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_setstackaddr, abii_ret)
    return real_pthread_attr_setstackaddr(attr, stackaddr);
}

static int (*real_pthread_attr_getstacksize)(const pthread_attr_t*, size_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_attr_getstacksize(const pthread_attr_t* attr, size_t* stacksize) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getstacksize)
        pre_fmtd_str pi_str = "pthread_attr_getstacksize(__attr, __stacksize)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(stacksize, "__stacksize"));

        auto abii_ret = real_pthread_attr_getstacksize(attr, stacksize);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_getstacksize, abii_ret)
    return real_pthread_attr_getstacksize(attr, stacksize);
}

static int (*real_pthread_attr_setstacksize)(pthread_attr_t*, size_t) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_attr_setstacksize(pthread_attr_t* attr, size_t stacksize) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setstacksize)
        pre_fmtd_str pi_str = "pthread_attr_setstacksize(__attr, __stacksize)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(stacksize, "__stacksize"));

        auto abii_ret = real_pthread_attr_setstacksize(attr, stacksize);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_setstacksize, abii_ret)
    return real_pthread_attr_setstacksize(attr, stacksize);
}

static int (*real_pthread_attr_getstack)(const pthread_attr_t*, void**, size_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2, 3))
int abii_pthread_attr_getstack(const pthread_attr_t* attr, void** stackaddr, size_t* stacksize) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getstack)
        pre_fmtd_str pi_str = "pthread_attr_getstack(__attr, __stackaddr, __stacksize)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(stackaddr, "__stackaddr"));
        abii_args->push_arg(new ArgPrinter(stacksize, "__stacksize"));

        auto abii_ret = real_pthread_attr_getstack(attr, stackaddr, stacksize);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_getstack, abii_ret)
    return real_pthread_attr_getstack(attr, stackaddr, stacksize);
}

static int (*real_pthread_attr_setstack)(pthread_attr_t*, void*, size_t) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_attr_setstack(pthread_attr_t* attr, void* stackaddr, size_t stacksize) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setstack)
        pre_fmtd_str pi_str = "pthread_attr_setstack(__attr, __stackaddr, __stacksize)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(stackaddr, "__stackaddr"));
        abii_args->push_arg(new ArgPrinter(stacksize, "__stacksize"));

        auto abii_ret = real_pthread_attr_setstack(attr, stackaddr, stacksize);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_setstack, abii_ret)
    return real_pthread_attr_setstack(attr, stackaddr, stacksize);
}

static int (*real_pthread_attr_setaffinity_np)(pthread_attr_t*, size_t, const cpu_set_t*) __THROW = nullptr;

extern "C" __nonnull((1, 3))
int abii_pthread_attr_setaffinity_np(pthread_attr_t* attr, size_t cpusetsize, const cpu_set_t* cpuset) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_setaffinity_np)
        pre_fmtd_str pi_str = "pthread_attr_setaffinity_np(__attr, __cpusetsize, __cpuset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(cpusetsize, "__cpusetsize"));
        abii_args->push_arg(new ArgPrinter(cpuset, "__cpuset"));

        auto abii_ret = real_pthread_attr_setaffinity_np(attr, cpusetsize, cpuset);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_setaffinity_np, abii_ret)
    return real_pthread_attr_setaffinity_np(attr, cpusetsize, cpuset);
}

static int (*real_pthread_attr_getaffinity_np)(const pthread_attr_t*, size_t, cpu_set_t*) __THROW = nullptr;

extern "C" __nonnull((1, 3))
int abii_pthread_attr_getaffinity_np(const pthread_attr_t* attr, size_t cpusetsize, cpu_set_t* cpuset) __THROW
{
    OVERRIDE_PREFIX(pthread_attr_getaffinity_np)
        pre_fmtd_str pi_str = "pthread_attr_getaffinity_np(__attr, __cpusetsize, __cpuset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(cpusetsize, "__cpusetsize"));
        abii_args->push_arg(new ArgPrinter(cpuset, "__cpuset"));

        auto abii_ret = real_pthread_attr_getaffinity_np(attr, cpusetsize, cpuset);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_getaffinity_np, abii_ret)
    return real_pthread_attr_getaffinity_np(attr, cpusetsize, cpuset);
}

static int (*real_pthread_getattr_default_np)(pthread_attr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_getattr_default_np(pthread_attr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_getattr_default_np)
        pre_fmtd_str pi_str = "pthread_getattr_default_np(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_getattr_default_np(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_getattr_default_np, abii_ret)
    return real_pthread_getattr_default_np(attr);
}

static int (*real_pthread_attr_setsigmask_np)(pthread_attr_t*, const __sigset_t*) = nullptr;

extern "C" int abii_pthread_attr_setsigmask_np(pthread_attr_t* attr, const __sigset_t* sigmask)
{
    OVERRIDE_PREFIX(pthread_attr_setsigmask_np)
        pre_fmtd_str pi_str = "pthread_attr_setsigmask_np(__attr, sigmask)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(sigmask, "sigmask"));

        auto abii_ret = real_pthread_attr_setsigmask_np(attr, sigmask);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_setsigmask_np, abii_ret)
    return real_pthread_attr_setsigmask_np(attr, sigmask);
}

static int (*real_pthread_attr_getsigmask_np)(const pthread_attr_t*, __sigset_t*) = nullptr;

extern "C" int abii_pthread_attr_getsigmask_np(const pthread_attr_t* attr, __sigset_t* sigmask)
{
    OVERRIDE_PREFIX(pthread_attr_getsigmask_np)
        pre_fmtd_str pi_str = "pthread_attr_getsigmask_np(__attr, sigmask)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(sigmask, "sigmask"));

        auto abii_ret = real_pthread_attr_getsigmask_np(attr, sigmask);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_pthread_attr_no_sigmask_np, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_attr_getsigmask_np, abii_ret)
    return real_pthread_attr_getsigmask_np(attr, sigmask);
}

static int (*real_pthread_setattr_default_np)(const pthread_attr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_setattr_default_np(const pthread_attr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_setattr_default_np)
        pre_fmtd_str pi_str = "pthread_setattr_default_np(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_setattr_default_np(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_setattr_default_np, abii_ret)
    return real_pthread_setattr_default_np(attr);
}

static int (*real_pthread_getattr_np)(pthread_t, pthread_attr_t*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_pthread_getattr_np(pthread_t th, pthread_attr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_getattr_np)
        pre_fmtd_str pi_str = "pthread_getattr_np(__th, __attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_getattr_np(th, attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_getattr_np, abii_ret)
    return real_pthread_getattr_np(th, attr);
}

static int (*real_pthread_setschedparam)(pthread_t, int, const sched_param*) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_pthread_setschedparam(pthread_t target_thread, int policy, const sched_param* param) __THROW
{
    OVERRIDE_PREFIX(pthread_setschedparam)
        pre_fmtd_str pi_str = "pthread_setschedparam(__target_thread, __policy, __param)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(target_thread, "__target_thread"));

        auto printer = new ArgPrinter(policy, "__policy");
        printer->set_enum_printer(print_sched_algorithm, policy);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(param, "__param"));

        auto abii_ret = real_pthread_setschedparam(target_thread, policy, param);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_setschedparam, abii_ret)
    return real_pthread_setschedparam(target_thread, policy, param);
}

static int (*real_pthread_getschedparam)(pthread_t, int*, sched_param*) __THROW = nullptr;

extern "C" __nonnull((2, 3))
int abii_pthread_getschedparam(pthread_t target_thread, int* policy, sched_param* param) __THROW
{
    OVERRIDE_PREFIX(pthread_getschedparam)
        pre_fmtd_str pi_str = "pthread_getschedparam(__target_thread, __policy, __param)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(target_thread, "__target_thread"));

        auto printer = new ArgPrinter(policy, "__policy");
        printer->set_enum_printer_with_depth(print_sched_algorithm, *policy, 1);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(param, "__param"));

        auto abii_ret = real_pthread_getschedparam(target_thread, policy, param);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_getschedparam, abii_ret)
    return real_pthread_getschedparam(target_thread, policy, param);
}

static int (*real_pthread_setschedprio)(pthread_t, int) __THROW = nullptr;

extern "C" int abii_pthread_setschedprio(pthread_t target_thread, int prio) __THROW
{
    OVERRIDE_PREFIX(pthread_setschedprio)
        pre_fmtd_str pi_str = "pthread_setschedprio(__target_thread, __prio)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(target_thread, "__target_thread"));
        abii_args->push_arg(new ArgPrinter(prio, "__prio"));

        auto abii_ret = real_pthread_setschedprio(target_thread, prio);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_setschedprio, abii_ret)
    return real_pthread_setschedprio(target_thread, prio);
}

static int (*real_pthread_getname_np)(pthread_t, char*, size_t) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_pthread_getname_np(pthread_t target_thread, char* buf, size_t buflen) __THROW
{
    OVERRIDE_PREFIX(pthread_getname_np)
        pre_fmtd_str pi_str = "pthread_getname_np(__target_thread, __buf, __buflen)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(target_thread, "__target_thread"));

        auto printer = new ArgPrinter(buf, "__buf");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));

        auto abii_ret = real_pthread_getname_np(target_thread, buf, buflen);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_getname_np, abii_ret)
    return real_pthread_getname_np(target_thread, buf, buflen);
}

static int (*real_pthread_setname_np)(pthread_t, const char*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_pthread_setname_np(pthread_t target_thread, const char* name) __THROW
{
    OVERRIDE_PREFIX(pthread_setname_np)
        pre_fmtd_str pi_str = "pthread_setname_np(__target_thread, __name)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(target_thread, "__target_thread"));
        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_pthread_setname_np(target_thread, name);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_setname_np, abii_ret)
    return real_pthread_setname_np(target_thread, name);
}

static int (*real_pthread_getconcurrency)() __THROW = nullptr;

extern "C" int abii_pthread_getconcurrency() __THROW
{
    OVERRIDE_PREFIX(pthread_getconcurrency)
        pre_fmtd_str pi_str = "pthread_getconcurrency()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_pthread_getconcurrency();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pthread_getconcurrency, abii_ret)
    return real_pthread_getconcurrency();
}

static int (*real_pthread_setconcurrency)(int) __THROW = nullptr;

extern "C" int abii_pthread_setconcurrency(int level) __THROW
{
    OVERRIDE_PREFIX(pthread_setconcurrency)
        pre_fmtd_str pi_str = "pthread_setconcurrency(__level)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(level, "__level"));

        auto abii_ret = real_pthread_setconcurrency(level);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_setconcurrency, abii_ret)
    return real_pthread_setconcurrency(level);
}

static int (*real_pthread_setaffinity_np)(pthread_t, size_t, const cpu_set_t*) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_pthread_setaffinity_np(pthread_t th, size_t cpusetsize, const cpu_set_t* cpuset) __THROW
{
    OVERRIDE_PREFIX(pthread_setaffinity_np)
        pre_fmtd_str pi_str = "pthread_setaffinity_np(__th, __cpusetsize, __cpuset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(cpusetsize, "__cpusetsize"));
        abii_args->push_arg(new ArgPrinter(cpuset, "__cpuset"));

        auto abii_ret = real_pthread_setaffinity_np(th, cpusetsize, cpuset);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_setaffinity_np, abii_ret)
    return real_pthread_setaffinity_np(th, cpusetsize, cpuset);
}

static int (*real_pthread_getaffinity_np)(pthread_t, size_t, cpu_set_t*) __THROW = nullptr;

extern "C" __nonnull((3))
int abii_pthread_getaffinity_np(pthread_t th, size_t cpusetsize, cpu_set_t* cpuset) __THROW
{
    OVERRIDE_PREFIX(pthread_getaffinity_np)
        pre_fmtd_str pi_str = "pthread_getaffinity_np(__th, __cpusetsize, __cpuset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(cpusetsize, "__cpusetsize"));
        abii_args->push_arg(new ArgPrinter(cpuset, "__cpuset"));

        auto abii_ret = real_pthread_getaffinity_np(th, cpusetsize, cpuset);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_getaffinity_np, abii_ret)
    return real_pthread_getaffinity_np(th, cpusetsize, cpuset);
}

static int (*real_pthread_once)(pthread_once_t*, void (*)()) = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_once(pthread_once_t* once_control, void (*init_routine)())
{
    OVERRIDE_PREFIX(pthread_once)
        pre_fmtd_str pi_str = "pthread_once(__once_control, __init_routine)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(once_control, "__once_control");
        printer->set_enum_printer_with_depth(print_pthread_once_init, *once_control, 1);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(init_routine, "__init_routine"));

        auto abii_ret = real_pthread_once(once_control, init_routine);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_once, abii_ret)
    return real_pthread_once(once_control, init_routine);
}

static int (*real_pthread_setcancelstate)(int, int*) = nullptr;

extern "C" int abii_pthread_setcancelstate(int state, int* oldstate)
{
    OVERRIDE_PREFIX(pthread_setcancelstate)
        pre_fmtd_str pi_str = "pthread_setcancelstate(__state, __oldstate)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(state, "__state");
        printer->set_enum_printer(print_pthread_cancellation, state);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(oldstate, "__oldstate");
        printer->set_enum_printer_with_depth(print_pthread_cancellation, *oldstate, 1);
        abii_args->push_arg(printer1);

        auto abii_ret = real_pthread_setcancelstate(state, oldstate);

        auto printer2 = new ArgPrinter(abii_ret, "return");
        printer2->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer2);
    OVERRIDE_SUFFIX(pthread_setcancelstate, abii_ret)
    return real_pthread_setcancelstate(state, oldstate);
}

static int (*real_pthread_setcanceltype)(int, int*) = nullptr;

extern "C" int abii_pthread_setcanceltype(int type, int* oldtype)
{
    OVERRIDE_PREFIX(pthread_setcanceltype)
        pre_fmtd_str pi_str = "pthread_setcanceltype(__type, __oldtype)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(type, "__type");
        printer->set_enum_printer(print_pthread_cancellation_type, type);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(oldtype, "__oldtype");
        printer1->set_enum_printer_with_depth(print_pthread_cancellation_type, *oldtype, 1);
        abii_args->push_arg(printer1);

        auto abii_ret = real_pthread_setcanceltype(type, oldtype);

        auto printer2 = new ArgPrinter(abii_ret, "return");
        printer2->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer2);
    OVERRIDE_SUFFIX(pthread_setcanceltype, abii_ret)
    return real_pthread_setcanceltype(type, oldtype);
}

static int (*real_pthread_cancel)(pthread_t) = nullptr;

extern "C" int abii_pthread_cancel(pthread_t th)
{
    OVERRIDE_PREFIX(pthread_cancel)
        pre_fmtd_str pi_str = "pthread_cancel(__th)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));

        auto abii_ret = real_pthread_cancel(th);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_cancel, abii_ret)
    return real_pthread_cancel(th);
}

static void (*real_pthread_testcancel)() = nullptr;

extern "C" void abii_pthread_testcancel()
{
    OVERRIDE_PREFIX(pthread_testcancel)
        pre_fmtd_str pi_str = "pthread_testcancel()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_pthread_testcancel();
    OVERRIDE_SUFFIX(pthread_testcancel,)
    return real_pthread_testcancel();
}

static void (*real___pthread_unwind_next)(__pthread_unwind_buf_t* __buf) = nullptr;

extern "C"
#ifndef SHARED
__attribute__ ((__weak__))
#endif
__attribute__ ((__noreturn__)) __cleanup_fct_attribute
void abii___pthread_unwind_next(__pthread_unwind_buf_t* buf)
{
    OVERRIDE_PREFIX(__pthread_unwind_next)
        pre_fmtd_str pi_str = "__pthread_unwind_next(__buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        abii_args->print_args();
        abii_stream << std::endl;
        delete abii_args;

        real___pthread_unwind_next(buf);

        ENABLE_OVERRIDES
    }
    if (real___pthread_unwind_next == nullptr)
    {
        real___pthread_unwind_next = reinterpret_cast<decltype(real___pthread_unwind_next)>(dlsym(
            RTLD_NEXT, "__pthread_unwind_next"));
        if (real___pthread_unwind_next == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real___pthread_unwind_next(buf);
}

static int (*real___sigsetjmp)(__jmp_buf_tag __env[1], int __savemask) __THROWNL = nullptr;

extern "C" int abii___sigsetjmp(__jmp_buf_tag env[1], int savemask) __THROWNL
{
    OVERRIDE_PREFIX(__sigsetjmp)
        pre_fmtd_str pi_str = "__sigsetjmp(__env, __savemask)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(env, "__env"));
        abii_args->push_arg(new ArgPrinter(savemask, "__savemask"));

        auto abii_ret = real___sigsetjmp(env, savemask);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(__sigsetjmp, abii_ret)
    return real___sigsetjmp(env, savemask);
}

static int (*real_pthread_mutex_init)(pthread_mutex_t*, const pthread_mutexattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* mutexattr) __THROW
{
    OVERRIDE_PREFIX(pthread_mutex_init)
        pre_fmtd_str pi_str = "pthread_mutex_init(__mutex, __mutexattr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));
        abii_args->push_arg(new ArgPrinter(mutexattr, "__mutexattr"));

        auto abii_ret = real_pthread_mutex_init(mutex, mutexattr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutex_init, abii_ret)
    return real_pthread_mutex_init(mutex, mutexattr);
}

static int (*real_pthread_mutex_destroy)(pthread_mutex_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutex_destroy(pthread_mutex_t* mutex) __THROW
{
    OVERRIDE_PREFIX(pthread_mutex_destroy)
        pre_fmtd_str pi_str = "pthread_mutex_destroy(__mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_pthread_mutex_destroy(mutex);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutex_destroy, abii_ret)
    return real_pthread_mutex_destroy(mutex);
}

static int (*real_pthread_mutex_trylock)(pthread_mutex_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutex_trylock(pthread_mutex_t* mutex) __THROWNL
{
    OVERRIDE_PREFIX(pthread_mutex_trylock)
        pre_fmtd_str pi_str = "pthread_mutex_trylock(__mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_pthread_mutex_trylock(mutex);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutex_trylock, abii_ret)
    return real_pthread_mutex_trylock(mutex);
}

static int (*real_pthread_mutex_lock)(pthread_mutex_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutex_lock(pthread_mutex_t* mutex) __THROWNL
{
    OVERRIDE_PREFIX(pthread_mutex_lock)
        pre_fmtd_str pi_str = "pthread_mutex_lock(__mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_pthread_mutex_lock(mutex);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutex_lock, abii_ret)
    return real_pthread_mutex_lock(mutex);
}

static int (*real_pthread_mutex_timedlock)(pthread_mutex_t*, const timespec*) __THROWNL = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_mutex_timedlock(pthread_mutex_t* mutex, const timespec* abstime) __THROWNL
{
    OVERRIDE_PREFIX(pthread_mutex_timedlock)
        pre_fmtd_str pi_str = "pthread_mutex_timedlock(__mutex, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));
        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_mutex_timedlock(mutex, abstime);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutex_timedlock, abii_ret)
    return real_pthread_mutex_timedlock(mutex, abstime);
}

static int (*real_pthread_mutex_clocklock)(pthread_mutex_t*, clockid_t, const timespec*) __THROWNL = nullptr;

extern "C" __nonnull((1, 3))
int abii_pthread_mutex_clocklock(pthread_mutex_t* mutex, clockid_t clockid, const timespec* abstime) __THROWNL
{
    OVERRIDE_PREFIX(pthread_mutex_clocklock)
        pre_fmtd_str pi_str = "pthread_mutex_clocklock(__mutex, __clockid, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto printer = new ArgPrinter(clockid, "__clockid");
        printer->set_enum_printer(print_time_clock, clockid);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_mutex_clocklock(mutex, clockid, abstime);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_mutex_clocklock, abii_ret)
    return real_pthread_mutex_clocklock(mutex, clockid, abstime);
}

static int (*real_pthread_mutex_unlock)(pthread_mutex_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutex_unlock(pthread_mutex_t* mutex) __THROWNL
{
    OVERRIDE_PREFIX(pthread_mutex_unlock)
        pre_fmtd_str pi_str = "pthread_mutex_unlock(__mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_pthread_mutex_unlock(mutex);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutex_unlock, abii_ret)
    return real_pthread_mutex_unlock(mutex);
}

static int (*real_pthread_mutex_getprioceiling)(const pthread_mutex_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_mutex_getprioceiling(const pthread_mutex_t* mutex, int* prioceiling) __THROW
{
    OVERRIDE_PREFIX(pthread_mutex_getprioceiling)
        pre_fmtd_str pi_str = "pthread_mutex_getprioceiling(__mutex, __prioceiling)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));
        abii_args->push_arg(new ArgPrinter(prioceiling, "__prioceiling"));

        auto abii_ret = real_pthread_mutex_getprioceiling(mutex, prioceiling);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutex_getprioceiling, abii_ret)
    return real_pthread_mutex_getprioceiling(mutex, prioceiling);
}

static int (*real_pthread_mutex_setprioceiling)(pthread_mutex_t*, int, int*) __THROW = nullptr;

extern "C" __nonnull((1, 3))
int abii_pthread_mutex_setprioceiling(pthread_mutex_t* mutex, int prioceiling, int* old_ceiling) __THROW
{
    OVERRIDE_PREFIX(pthread_mutex_setprioceiling)
        pre_fmtd_str pi_str = "pthread_mutex_setprioceiling(__mutex, __prioceiling, __old_ceiling)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));
        abii_args->push_arg(new ArgPrinter(prioceiling, "__prioceiling"));
        abii_args->push_arg(new ArgPrinter(old_ceiling, "__old_ceiling"));

        auto abii_ret = real_pthread_mutex_setprioceiling(mutex, prioceiling, old_ceiling);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutex_setprioceiling, abii_ret)
    return real_pthread_mutex_setprioceiling(mutex, prioceiling, old_ceiling);
}

static int (*real_pthread_mutex_consistent)(pthread_mutex_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutex_consistent(pthread_mutex_t* mutex) __THROW
{
    OVERRIDE_PREFIX(pthread_mutex_consistent)
        pre_fmtd_str pi_str = "pthread_mutex_consistent(__mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_pthread_mutex_consistent(mutex);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutex_consistent, abii_ret)
    return real_pthread_mutex_consistent(mutex);
}

static int (*real_pthread_mutexattr_init)(pthread_mutexattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutexattr_init(pthread_mutexattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_init)
        pre_fmtd_str pi_str = "pthread_mutexattr_init(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_mutexattr_init(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutexattr_init, abii_ret)
    return real_pthread_mutexattr_init(attr);
}

static int (*real_pthread_mutexattr_destroy)(pthread_mutexattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutexattr_destroy(pthread_mutexattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_destroy)
        pre_fmtd_str pi_str = "pthread_mutexattr_destroy(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_mutexattr_destroy(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutexattr_destroy, abii_ret)
    return real_pthread_mutexattr_destroy(attr);
}

static int (*real_pthread_mutexattr_getpshared)(const pthread_mutexattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_mutexattr_getpshared(const pthread_mutexattr_t* attr, int* pshared) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_getpshared)
        pre_fmtd_str pi_str = "pthread_mutexattr_getpshared(__attr, __pshared)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pshared, "__pshared");
        printer->set_enum_printer_with_depth(print_pthread_visibility_flag, *pshared, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_mutexattr_getpshared(attr, pshared);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_mutexattr_getpshared, abii_ret)
    return real_pthread_mutexattr_getpshared(attr, pshared);
}

static int (*real_pthread_mutexattr_setpshared)(pthread_mutexattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutexattr_setpshared(pthread_mutexattr_t* attr, int pshared) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_setpshared)
        pre_fmtd_str pi_str = "pthread_mutexattr_setpshared(__attr, __pshared)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pshared, "__pshared");
        printer->set_enum_printer(print_pthread_visibility_flag, pshared);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_mutexattr_setpshared(attr, pshared);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_mutexattr_setpshared, abii_ret)
    return real_pthread_mutexattr_setpshared(attr, pshared);
}

static int (*real_pthread_mutexattr_gettype)(const pthread_mutexattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_mutexattr_gettype(const pthread_mutexattr_t* attr, int* kind) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_gettype)
        pre_fmtd_str pi_str = "pthread_mutexattr_gettype(__attr, __kind)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(kind, "__kind");
        printer->set_enum_printer_with_depth(print_pthread_mutex_type, *kind, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_mutexattr_gettype(attr, kind);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_mutexattr_gettype, abii_ret)
    return real_pthread_mutexattr_gettype(attr, kind);
}

static int (*real_pthread_mutexattr_settype)(pthread_mutexattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutexattr_settype(pthread_mutexattr_t* attr, int kind) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_settype)
        pre_fmtd_str pi_str = "pthread_mutexattr_settype(__attr, __kind)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(kind, "__kind");
        printer->set_enum_printer(print_pthread_mutex_type, kind);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_mutexattr_settype(attr, kind);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_mutexattr_settype, abii_ret)
    return real_pthread_mutexattr_settype(attr, kind);
}

static int (*real_pthread_mutexattr_getprotocol)(const pthread_mutexattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_mutexattr_getprotocol(const pthread_mutexattr_t* attr, int* protocol) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_getprotocol)
        pre_fmtd_str pi_str = "pthread_mutexattr_getprotocol(__attr, __protocol)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(protocol, "__protocol");
        printer->set_enum_printer_with_depth(print_pthread_mutex_protocol, *protocol, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_mutexattr_getprotocol(attr, protocol);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_mutexattr_getprotocol, abii_ret)
    return real_pthread_mutexattr_getprotocol(attr, protocol);
}

static int (*real_pthread_mutexattr_setprotocol)(pthread_mutexattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutexattr_setprotocol(pthread_mutexattr_t* attr, int protocol) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_setprotocol)
        pre_fmtd_str pi_str = "pthread_mutexattr_setprotocol(__attr, __protocol)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(protocol, "__protocol");
        printer->set_enum_printer(print_pthread_mutex_protocol, protocol);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_mutexattr_setprotocol(attr, protocol);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_mutexattr_setprotocol, abii_ret)
    return real_pthread_mutexattr_setprotocol(attr, protocol);
}

static int (*real_pthread_mutexattr_getprioceiling)(const pthread_mutexattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_mutexattr_getprioceiling(const pthread_mutexattr_t* attr, int* prioceiling) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_getprioceiling)
        pre_fmtd_str pi_str = "pthread_mutexattr_getprioceiling(__attr, __prioceiling)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(prioceiling, "__prioceiling"));

        auto abii_ret = real_pthread_mutexattr_getprioceiling(attr, prioceiling);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutexattr_getprioceiling, abii_ret)
    return real_pthread_mutexattr_getprioceiling(attr, prioceiling);
}

static int (*real_pthread_mutexattr_setprioceiling)(pthread_mutexattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutexattr_setprioceiling(pthread_mutexattr_t* attr, int prioceiling) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_setprioceiling)
        pre_fmtd_str pi_str = "pthread_mutexattr_setprioceiling(__attr, __prioceiling)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(prioceiling, "__prioceiling"));

        auto abii_ret = real_pthread_mutexattr_setprioceiling(attr, prioceiling);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_mutexattr_setprioceiling, abii_ret)
    return real_pthread_mutexattr_setprioceiling(attr, prioceiling);
}

static int (*real_pthread_mutexattr_getrobust)(const pthread_mutexattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_mutexattr_getrobust(const pthread_mutexattr_t* attr, int* robustness) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_getrobust)
        pre_fmtd_str pi_str = "pthread_mutexattr_getrobust(__attr, __robustness)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(robustness, "__robustness");
        printer->set_enum_printer_with_depth(print_pthread_mutex_flag, *robustness, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_mutexattr_getrobust(attr, robustness);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_mutexattr_getrobust, abii_ret)
    return real_pthread_mutexattr_getrobust(attr, robustness);
}

static int (*real_pthread_mutexattr_setrobust)(pthread_mutexattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_mutexattr_setrobust(pthread_mutexattr_t* attr, int robustness) __THROW
{
    OVERRIDE_PREFIX(pthread_mutexattr_setrobust)
        pre_fmtd_str pi_str = "pthread_mutexattr_setrobust(__attr, __robustness)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(robustness, "__robustness");
        printer->set_enum_printer(print_pthread_mutex_flag, robustness);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_mutexattr_setrobust(attr, robustness);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_mutexattr_setrobust, abii_ret)
    return real_pthread_mutexattr_setrobust(attr, robustness);
}

static int (*real_pthread_rwlock_init)(pthread_rwlock_t*, const pthread_rwlockattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlock_init(pthread_rwlock_t* rwlock, const pthread_rwlockattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_rwlock_init)
        pre_fmtd_str pi_str = "pthread_rwlock_init(__rwlock, __attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));
        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_rwlock_init(rwlock, attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlock_init, abii_ret)
    return real_pthread_rwlock_init(rwlock, attr);
}

static int (*real_pthread_rwlock_destroy)(pthread_rwlock_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlock_destroy(pthread_rwlock_t* rwlock) __THROW
{
    OVERRIDE_PREFIX(pthread_rwlock_destroy)
        pre_fmtd_str pi_str = "pthread_rwlock_destroy(__rwlock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));

        auto abii_ret = real_pthread_rwlock_destroy(rwlock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlock_destroy, abii_ret)
    return real_pthread_rwlock_destroy(rwlock);
}

static int (*real_pthread_rwlock_rdlock)(pthread_rwlock_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlock_rdlock(pthread_rwlock_t* rwlock) __THROWNL
{
    OVERRIDE_PREFIX(pthread_rwlock_rdlock)
        pre_fmtd_str pi_str = "pthread_rwlock_rdlock(__rwlock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));

        auto abii_ret = real_pthread_rwlock_rdlock(rwlock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlock_rdlock, abii_ret)
    return real_pthread_rwlock_rdlock(rwlock);
}

static int (*real_pthread_rwlock_tryrdlock)(pthread_rwlock_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlock_tryrdlock(pthread_rwlock_t* rwlock) __THROWNL
{
    OVERRIDE_PREFIX(pthread_rwlock_tryrdlock)
        pre_fmtd_str pi_str = "pthread_rwlock_tryrdlock(__rwlock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));

        auto abii_ret = real_pthread_rwlock_tryrdlock(rwlock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlock_tryrdlock, abii_ret)
    return real_pthread_rwlock_tryrdlock(rwlock);
}

static int (*real_pthread_rwlock_timedrdlock)(pthread_rwlock_t*, const timespec*) __THROWNL = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_rwlock_timedrdlock(pthread_rwlock_t* rwlock, const timespec* abstime) __THROWNL
{
    OVERRIDE_PREFIX(pthread_rwlock_timedrdlock)
        pre_fmtd_str pi_str = "pthread_rwlock_timedrdlock(__rwlock, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));
        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_rwlock_timedrdlock(rwlock, abstime);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlock_timedrdlock, abii_ret)
    return real_pthread_rwlock_timedrdlock(rwlock, abstime);
}

static int (*real_pthread_rwlock_clockrdlock)(pthread_rwlock_t*, clockid_t, const timespec*) __THROWNL = nullptr;

extern "C" __nonnull((1, 3))
int abii_pthread_rwlock_clockrdlock(pthread_rwlock_t* rwlock, clockid_t clockid, const timespec* abstime) __THROWNL
{
    OVERRIDE_PREFIX(pthread_rwlock_clockrdlock)
        pre_fmtd_str pi_str = "pthread_rwlock_clockrdlock(__rwlock, __clockid, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));

        auto printer = new ArgPrinter(clockid, "__clockid");
        printer->set_enum_printer(print_time_clock, clockid);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_rwlock_clockrdlock(rwlock, clockid, abstime);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_rwlock_clockrdlock, abii_ret)
    return real_pthread_rwlock_clockrdlock(rwlock, clockid, abstime);
}

static int (*real_pthread_rwlock_wrlock)(pthread_rwlock_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlock_wrlock(pthread_rwlock_t* rwlock) __THROWNL
{
    OVERRIDE_PREFIX(pthread_rwlock_wrlock)
        pre_fmtd_str pi_str = "pthread_rwlock_wrlock(__rwlock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));

        auto abii_ret = real_pthread_rwlock_wrlock(rwlock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlock_wrlock, abii_ret)
    return real_pthread_rwlock_wrlock(rwlock);
}

static int (*real_pthread_rwlock_trywrlock)(pthread_rwlock_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlock_trywrlock(pthread_rwlock_t* rwlock) __THROWNL
{
    OVERRIDE_PREFIX(pthread_rwlock_trywrlock)
        pre_fmtd_str pi_str = "pthread_rwlock_trywrlock(__rwlock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));

        auto abii_ret = real_pthread_rwlock_trywrlock(rwlock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlock_trywrlock, abii_ret)
    return real_pthread_rwlock_trywrlock(rwlock);
}

static int (*real_pthread_rwlock_timedwrlock)(pthread_rwlock_t*, const timespec*) __THROWNL = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_rwlock_timedwrlock(pthread_rwlock_t* rwlock, const timespec* abstime) __THROWNL
{
    OVERRIDE_PREFIX(pthread_rwlock_timedwrlock)
        pre_fmtd_str pi_str = "pthread_rwlock_timedwrlock(__rwlock, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));
        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_rwlock_timedwrlock(rwlock, abstime);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlock_timedwrlock, abii_ret)
    return real_pthread_rwlock_timedwrlock(rwlock, abstime);
}

static int (*real_pthread_rwlock_clockwrlock)(pthread_rwlock_t*, clockid_t, const timespec*) __THROWNL = nullptr;

extern "C" __nonnull((1, 3))
int abii_pthread_rwlock_clockwrlock(pthread_rwlock_t* rwlock, clockid_t clockid, const timespec* abstime) __THROWNL
{
    OVERRIDE_PREFIX(pthread_rwlock_clockwrlock)
        pre_fmtd_str pi_str = "pthread_rwlock_clockwrlock(__rwlock, __clockid, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));

        auto printer = new ArgPrinter(clockid, "__clockid");
        printer->set_enum_printer(print_time_clock, clockid);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_rwlock_clockwrlock(rwlock, clockid, abstime);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_rwlock_clockwrlock, abii_ret)
    return real_pthread_rwlock_clockwrlock(rwlock, clockid, abstime);
}

static int (*real_pthread_rwlock_unlock)(pthread_rwlock_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlock_unlock(pthread_rwlock_t* rwlock) __THROWNL
{
    OVERRIDE_PREFIX(pthread_rwlock_unlock)
        pre_fmtd_str pi_str = "pthread_rwlock_unlock(__rwlock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(rwlock, "__rwlock"));

        auto abii_ret = real_pthread_rwlock_unlock(rwlock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlock_unlock, abii_ret)
    return real_pthread_rwlock_unlock(rwlock);
}

static int (*real_pthread_rwlockattr_init)(pthread_rwlockattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlockattr_init(pthread_rwlockattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_rwlockattr_init)
        pre_fmtd_str pi_str = "pthread_rwlock_unlock(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_rwlockattr_init(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlockattr_init, abii_ret)
    return real_pthread_rwlockattr_init(attr);
}

static int (*real_pthread_rwlockattr_destroy)(pthread_rwlockattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlockattr_destroy(pthread_rwlockattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_rwlockattr_destroy)
        pre_fmtd_str pi_str = "pthread_rwlockattr_destroy(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_rwlockattr_destroy(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_rwlockattr_destroy, abii_ret)
    return real_pthread_rwlockattr_destroy(attr);
}

static int (*real_pthread_rwlockattr_getpshared)(const pthread_rwlockattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_rwlockattr_getpshared(const pthread_rwlockattr_t* attr, int* pshared) __THROW
{
    OVERRIDE_PREFIX(pthread_rwlockattr_getpshared)
        pre_fmtd_str pi_str = "pthread_rwlockattr_getpshared(__attr, __pshared)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pshared, "__pshared");
        printer->set_enum_printer_with_depth(print_pthread_visibility_flag, *pshared, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_rwlockattr_getpshared(attr, pshared);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_rwlockattr_getpshared, abii_ret)
    return real_pthread_rwlockattr_getpshared(attr, pshared);
}

static int (*real_pthread_rwlockattr_setpshared)(pthread_rwlockattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlockattr_setpshared(pthread_rwlockattr_t* attr, int pshared) __THROW
{
    OVERRIDE_PREFIX(pthread_rwlockattr_setpshared)
        pre_fmtd_str pi_str = "pthread_rwlockattr_setpshared(__attr, __pshared)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pshared, "__pshared");
        printer->set_enum_printer(print_pthread_visibility_flag, pshared);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_rwlockattr_setpshared(attr, pshared);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_rwlockattr_setpshared, abii_ret)
    return real_pthread_rwlockattr_setpshared(attr, pshared);
}

static int (*real_pthread_rwlockattr_getkind_np)(const pthread_rwlockattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t* attr, int* pref) __THROW
{
    OVERRIDE_PREFIX(pthread_rwlockattr_getkind_np)
        pre_fmtd_str pi_str = "pthread_rwlockattr_getkind_np(__attr, __pref)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pref, "__pref");
        printer->set_enum_printer_with_depth(print_pthread_rwlock_type, *pref, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_rwlockattr_getkind_np(attr, pref);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_rwlockattr_getkind_np, abii_ret)
    return real_pthread_rwlockattr_getkind_np(attr, pref);
}

static int (*real_pthread_rwlockattr_setkind_np)(pthread_rwlockattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_rwlockattr_setkind_np(pthread_rwlockattr_t* attr, int pref) __THROW
{
    OVERRIDE_PREFIX(pthread_rwlockattr_setkind_np)
        pre_fmtd_str pi_str = "pthread_rwlockattr_setkind_np(__attr, __pref)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pref, "__pref");
        printer->set_enum_printer(print_pthread_rwlock_type, pref);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_rwlockattr_setkind_np(attr, pref);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_rwlockattr_setkind_np, abii_ret)
    return real_pthread_rwlockattr_setkind_np(attr, pref);
}

static int (*real_pthread_cond_init)(pthread_cond_t*, const pthread_condattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_cond_init(pthread_cond_t* cond, const pthread_condattr_t* cond_attr) __THROW
{
    OVERRIDE_PREFIX(pthread_cond_init)
        pre_fmtd_str pi_str = "pthread_cond_init(__cond, __cond_attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(cond, "__cond");
        printer->set_enum_printer_with_depth(print_pthread_cond_initializer, *cond, 1);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(cond_attr, "__cond_attr"));

        auto abii_ret = real_pthread_cond_init(cond, cond_attr);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_cond_init, abii_ret)
    return real_pthread_cond_init(cond, cond_attr);
}

static int (*real_pthread_cond_destroy)(pthread_cond_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_cond_destroy(pthread_cond_t* cond) __THROW
{
    OVERRIDE_PREFIX(pthread_cond_destroy)
        pre_fmtd_str pi_str = "pthread_cond_destroy(__cond)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));

        auto abii_ret = real_pthread_cond_destroy(cond);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_cond_destroy, abii_ret)
    return real_pthread_cond_destroy(cond);
}

static int (*real_pthread_cond_signal)(pthread_cond_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_cond_signal(pthread_cond_t* cond) __THROWNL
{
    OVERRIDE_PREFIX(pthread_cond_signal)
        pre_fmtd_str pi_str = "pthread_cond_signal(__cond)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));

        auto abii_ret = real_pthread_cond_signal(cond);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_cond_signal, abii_ret)
    return real_pthread_cond_signal(cond);
}

static int (*real_pthread_cond_broadcast)(pthread_cond_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_cond_broadcast(pthread_cond_t* cond) __THROWNL
{
    OVERRIDE_PREFIX(pthread_cond_broadcast)
        pre_fmtd_str pi_str = "pthread_cond_broadcast(__cond)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));

        auto abii_ret = real_pthread_cond_broadcast(cond);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_cond_broadcast, abii_ret)
    return real_pthread_cond_broadcast(cond);
}

static int (*real_pthread_cond_wait)(pthread_cond_t*, pthread_mutex_t*) = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex)
{
    OVERRIDE_PREFIX(pthread_cond_wait)
        pre_fmtd_str pi_str = "pthread_cond_wait(__cond, __mutex)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));
        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto abii_ret = real_pthread_cond_wait(cond, mutex);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_cond_wait, abii_ret)
    return real_pthread_cond_wait(cond, mutex);
}

static int (*real_pthread_cond_timedwait)(pthread_cond_t*, pthread_mutex_t*, const timespec*) = nullptr;

extern "C" __nonnull((1, 2, 3))
int abii_pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t* mutex, const timespec* abstime)
{
    OVERRIDE_PREFIX(pthread_cond_timedwait)
        pre_fmtd_str pi_str = "pthread_cond_timedwait(__cond, __mutex, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));
        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));
        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_cond_timedwait(cond, mutex, abstime);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_cond_timedwait, abii_ret)
    return real_pthread_cond_timedwait(cond, mutex, abstime);
}

static int (*real_pthread_cond_clockwait)(pthread_cond_t*, pthread_mutex_t*, __clockid_t, const timespec*) = nullptr;

extern "C" __nonnull((1, 2, 4))
int abii_pthread_cond_clockwait(pthread_cond_t* cond, pthread_mutex_t* mutex, __clockid_t clock_id,
                                const timespec* abstime)
{
    OVERRIDE_PREFIX(pthread_cond_clockwait)
        pre_fmtd_str pi_str = "pthread_cond_clockwait(__cond, __mutex, __clock_id, __abstime)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(cond, "__cond"));
        abii_args->push_arg(new ArgPrinter(mutex, "__mutex"));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer(print_time_clock, clock_id);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(abstime, "__abstime"));

        auto abii_ret = real_pthread_cond_clockwait(cond, mutex, clock_id, abstime);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_cond_clockwait, abii_ret)
    return real_pthread_cond_clockwait(cond, mutex, clock_id, abstime);
}

static int (*real_pthread_condattr_init)(pthread_condattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_condattr_init(pthread_condattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_condattr_init)
        pre_fmtd_str pi_str = "pthread_condattr_init(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_condattr_init(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_condattr_init, abii_ret)
    return real_pthread_condattr_init(attr);
}

static int (*real_pthread_condattr_destroy)(pthread_condattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_condattr_destroy(pthread_condattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_condattr_destroy)
        pre_fmtd_str pi_str = "pthread_condattr_destroy(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_condattr_destroy(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_condattr_destroy, abii_ret)
    return real_pthread_condattr_destroy(attr);
}

static int (*real_pthread_condattr_getpshared)(const pthread_condattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_condattr_getpshared(const pthread_condattr_t* attr, int* pshared) __THROW
{
    OVERRIDE_PREFIX(pthread_condattr_getpshared)
        pre_fmtd_str pi_str = "pthread_condattr_getpshared(__attr, __pshared)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pshared, "__pshared");
        printer->set_enum_printer_with_depth(print_pthread_visibility_flag, *pshared, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_condattr_getpshared(attr, pshared);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_condattr_getpshared, abii_ret)
    return real_pthread_condattr_getpshared(attr, pshared);
}

static int (*real_pthread_condattr_setpshared)(pthread_condattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_condattr_setpshared(pthread_condattr_t* attr, int pshared) __THROW
{
    OVERRIDE_PREFIX(pthread_condattr_setpshared)
        pre_fmtd_str pi_str = "pthread_condattr_setpshared(__attr, __pshared)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pshared, "__pshared");
        printer->set_enum_printer(print_pthread_visibility_flag, pshared);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_condattr_setpshared(attr, pshared);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_condattr_setpshared, abii_ret)
    return real_pthread_condattr_setpshared(attr, pshared);
}

static int (*real_pthread_condattr_getclock)(const pthread_condattr_t*, __clockid_t*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_condattr_getclock(const pthread_condattr_t* attr, __clockid_t* clock_id) __THROW
{
    OVERRIDE_PREFIX(pthread_condattr_getclock)
        pre_fmtd_str pi_str = "pthread_condattr_getclock(__attr, __clock_id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer_with_depth(print_time_clock, *clock_id, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_condattr_getclock(attr, clock_id);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_condattr_getclock, abii_ret)
    return real_pthread_condattr_getclock(attr, clock_id);
}

static int (*real_pthread_condattr_setclock)(pthread_condattr_t*, __clockid_t) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_condattr_setclock(pthread_condattr_t* attr, __clockid_t clock_id) __THROW
{
    OVERRIDE_PREFIX(pthread_condattr_setclock)
        pre_fmtd_str pi_str = "pthread_condattr_setclock(__attr, __clock_id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer(print_time_clock, clock_id);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_condattr_setclock(attr, clock_id);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_condattr_setclock, abii_ret)
    return real_pthread_condattr_setclock(attr, clock_id);
}

static int (*real_pthread_spin_init)(pthread_spinlock_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_spin_init(pthread_spinlock_t* lock, int pshared) __THROW
{
    OVERRIDE_PREFIX(pthread_spin_init)
        pre_fmtd_str pi_str = "pthread_spin_init(__lock, __pshared)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(lock, "__lock"));

        auto printer = new ArgPrinter(pshared, "__pshared");
        printer->set_enum_printer(print_pthread_visibility_flag, pshared);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_spin_init(lock, pshared);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_spin_init, abii_ret)
    return real_pthread_spin_init(lock, pshared);
}

static int (*real_pthread_spin_destroy)(pthread_spinlock_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_spin_destroy(pthread_spinlock_t* lock) __THROW
{
    OVERRIDE_PREFIX(pthread_spin_destroy)
        pre_fmtd_str pi_str = "pthread_spin_destroy(__lock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(lock, "__lock"));

        auto abii_ret = real_pthread_spin_destroy(lock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_spin_destroy, abii_ret)
    return real_pthread_spin_destroy(lock);
}

static int (*real_pthread_spin_lock)(pthread_spinlock_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_spin_lock(pthread_spinlock_t* lock) __THROWNL
{
    OVERRIDE_PREFIX(pthread_spin_lock)
        pre_fmtd_str pi_str = "pthread_spin_lock(__lock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(lock, "__lock"));

        auto abii_ret = real_pthread_spin_lock(lock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_spin_lock, abii_ret)
    return real_pthread_spin_lock(lock);
}

static int (*real_pthread_spin_trylock)(pthread_spinlock_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_spin_trylock(pthread_spinlock_t* lock) __THROWNL
{
    OVERRIDE_PREFIX(pthread_spin_trylock)
        pre_fmtd_str pi_str = "pthread_spin_trylock(__lock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(lock, "__lock"));

        auto abii_ret = real_pthread_spin_trylock(lock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_spin_trylock, abii_ret)
    return real_pthread_spin_trylock(lock);
}

static int (*real_pthread_spin_unlock)(pthread_spinlock_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_spin_unlock(pthread_spinlock_t* lock) __THROWNL
{
    OVERRIDE_PREFIX(pthread_spin_unlock)
        pre_fmtd_str pi_str = "pthread_spin_unlock(__lock)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(lock, "__lock"));

        auto abii_ret = real_pthread_spin_unlock(lock);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_spin_unlock, abii_ret)
    return real_pthread_spin_unlock(lock);
}

static int (*real_pthread_barrier_init)(pthread_barrier_t*, const pthread_barrierattr_t*, unsigned int) __THROW =
    nullptr;

extern "C" __nonnull((1))
int abii_pthread_barrier_init(pthread_barrier_t* barrier, const pthread_barrierattr_t* attr, unsigned int count) __THROW
{
    OVERRIDE_PREFIX(pthread_barrier_init)
        pre_fmtd_str pi_str = "pthread_barrier_init(__barrier, __attr, __count)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(barrier, "__barrier"));
        abii_args->push_arg(new ArgPrinter(attr, "__attr"));
        abii_args->push_arg(new ArgPrinter(count, "__count"));

        auto abii_ret = real_pthread_barrier_init(barrier, attr, count);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_barrier_init, abii_ret)
    return real_pthread_barrier_init(barrier, attr, count);
}

static int (*real_pthread_barrier_destroy)(pthread_barrier_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_barrier_destroy(pthread_barrier_t* barrier) __THROW
{
    OVERRIDE_PREFIX(pthread_barrier_destroy)
        pre_fmtd_str pi_str = "pthread_barrier_destroy(__barrier)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(barrier, "__barrier"));

        auto abii_ret = real_pthread_barrier_destroy(barrier);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_barrier_destroy, abii_ret)
    return real_pthread_barrier_destroy(barrier);
}

static int (*real_pthread_barrier_wait)(pthread_barrier_t*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_pthread_barrier_wait(pthread_barrier_t* barrier) __THROWNL
{
    OVERRIDE_PREFIX(pthread_barrier_wait)
        pre_fmtd_str pi_str = "pthread_barrier_wait(__barrier)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(barrier, "__barrier"));

        auto abii_ret = real_pthread_barrier_wait(barrier);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_pthread_barrier_serial_thread, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_barrier_wait, abii_ret)
    return real_pthread_barrier_wait(barrier);
}

static int (*real_pthread_barrierattr_init)(pthread_barrierattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_barrierattr_init(pthread_barrierattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_barrierattr_init)
        pre_fmtd_str pi_str = "pthread_barrierattr_init(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_barrierattr_init(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_barrierattr_init, abii_ret)
    return real_pthread_barrierattr_init(attr);
}

static int (*real_pthread_barrierattr_destroy)(pthread_barrierattr_t*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_barrierattr_destroy(pthread_barrierattr_t* attr) __THROW
{
    OVERRIDE_PREFIX(pthread_barrierattr_destroy)
        pre_fmtd_str pi_str = "pthread_barrierattr_destroy(__attr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto abii_ret = real_pthread_barrierattr_destroy(attr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_barrierattr_destroy, abii_ret)
    return real_pthread_barrierattr_destroy(attr);
}

static int (*real_pthread_barrierattr_getpshared)(const pthread_barrierattr_t*, int*) __THROW = nullptr;

extern "C" __nonnull((1, 2))
int abii_pthread_barrierattr_getpshared(const pthread_barrierattr_t* attr, int* pshared) __THROW
{
    OVERRIDE_PREFIX(pthread_barrierattr_getpshared)
        pre_fmtd_str pi_str = "pthread_barrierattr_getpshared(__attr, __pshared)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pshared, "__pshared");
        printer->set_enum_printer_with_depth(print_pthread_visibility_flag, *pshared, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_barrierattr_getpshared(attr, pshared);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_barrierattr_getpshared, abii_ret)
    return real_pthread_barrierattr_getpshared(attr, pshared);
}

static int (*real_pthread_barrierattr_setpshared)(pthread_barrierattr_t*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_barrierattr_setpshared(pthread_barrierattr_t* attr, int pshared) __THROW
{
    OVERRIDE_PREFIX(pthread_barrierattr_setpshared)
        pre_fmtd_str pi_str = "pthread_barrierattr_setpshared(__attr, __pshared)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(attr, "__attr"));

        auto printer = new ArgPrinter(pshared, "__pshared");
        printer->set_enum_printer(print_pthread_visibility_flag, pshared);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_barrierattr_setpshared(attr, pshared);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_barrierattr_setpshared, abii_ret)
    return real_pthread_barrierattr_setpshared(attr, pshared);
}

static int (*real_pthread_key_create)(pthread_key_t*, void (*)(void*)) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_pthread_key_create(pthread_key_t* key, void (*destr_function)(void*)) __THROW
{
    OVERRIDE_PREFIX(pthread_key_create)
        pre_fmtd_str pi_str = "pthread_key_create(__key, __destr_function)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key"));
        abii_args->push_arg(new ArgPrinter(destr_function, "__destr_function"));

        auto abii_ret = real_pthread_key_create(key, destr_function);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_key_create, abii_ret)
    return real_pthread_key_create(key, destr_function);
}

static int (*real_pthread_key_delete)(pthread_key_t) __THROW = nullptr;

extern "C" int abii_pthread_key_delete(pthread_key_t key) __THROW
{
    OVERRIDE_PREFIX(pthread_key_delete)
        pre_fmtd_str pi_str = "pthread_key_delete(__key)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key"));

        auto abii_ret = real_pthread_key_delete(key);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_key_delete, abii_ret)
    return real_pthread_key_delete(key);
}

static void*(*real_pthread_getspecific)(pthread_key_t) __THROW = nullptr;

extern "C" void* abii_pthread_getspecific(pthread_key_t key) __THROW
{
    OVERRIDE_PREFIX(pthread_getspecific)
        pre_fmtd_str pi_str = "pthread_getspecific(__key)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key"));

        auto abii_ret = real_pthread_getspecific(key);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pthread_getspecific, abii_ret)
    return real_pthread_getspecific(key);
}

static int (*real_pthread_setspecific)(pthread_key_t, const void*) __THROW = nullptr;

extern "C" __attr_access_none(2)
int abii_pthread_setspecific(pthread_key_t key, const void* pointer) __THROW
{
    OVERRIDE_PREFIX(pthread_setspecific)
        pre_fmtd_str pi_str = "pthread_setspecific(__key, __pointer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key"));
        abii_args->push_arg(new ArgPrinter(pointer, "__pointer"));

        auto abii_ret = real_pthread_setspecific(key, pointer);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_setspecific, abii_ret)
    return real_pthread_setspecific(key, pointer);
}

static int (*real_pthread_getcpuclockid)(pthread_t, __clockid_t*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_pthread_getcpuclockid(pthread_t thread_id, __clockid_t* clock_id) __THROW
{
    OVERRIDE_PREFIX(pthread_getcpuclockid)
        pre_fmtd_str pi_str = "pthread_getcpuclockid(__thread_id, __clock_id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(thread_id, "__thread_id"));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer_with_depth(print_time_clock, *clock_id, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_pthread_getcpuclockid(thread_id, clock_id);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(pthread_getcpuclockid, abii_ret)
    return real_pthread_getcpuclockid(thread_id, clock_id);
}

static int (*real_pthread_atfork)(void (*)(), void (*)(), void (*)()) __THROW = nullptr;

extern "C" int abii_pthread_atfork(void (*prepare)(), void (*parent)(), void (*child)()) __THROW
{
    OVERRIDE_PREFIX(pthread_atfork)
        pre_fmtd_str pi_str = "pthread_atfork(__prepare, __parent, __child)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(prepare, "__prepare"));
        abii_args->push_arg(new ArgPrinter(parent, "__parent"));
        abii_args->push_arg(new ArgPrinter(child, "__child"));

        auto abii_ret = real_pthread_atfork(prepare, parent, child);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_error_enum_entry, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(pthread_atfork, abii_ret)
    return real_pthread_atfork(prepare, parent, child);
}
}
