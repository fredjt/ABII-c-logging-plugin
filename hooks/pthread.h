//
// Created by Trent Tanchin on 2/4/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_PTHREAD_H
#define ABII_C_LOGGING_PLUGIN_PTHREAD_H

#include <pthread.h>
#include <abii/libabii.h>

#include "asm-generic/errno-base.h"
#include "asm-generic/errno.h"

namespace abii
{
const defines_map pthread_detach_state = {
    {0, "PTHREAD_CREATE_JOINABLE"},
    {1, "PTHREAD_CREATE_DETACHED"}
};

const defines_map pthread_mutex_type = {
    {0, "PTHREAD_MUTEX_TIMED_NP"},
    {1, "PTHREAD_MUTEX_RECURSIVE_NP"},
    {2, "PTHREAD_MUTEX_ERRORCHECK_NP"},
    {3, "PTHREAD_MUTEX_ADAPTIVE_NP"},
    {0, "PTHREAD_MUTEX_NORMAL"},
    {1, "PTHREAD_MUTEX_RECURSIVE"},
    {2, "PTHREAD_MUTEX_ERRORCHECK"},
    {0, "PTHREAD_MUTEX_DEFAULT"},
    {0, "PTHREAD_MUTEX_FAST_NP"}
};

const defines_map pthread_mutex_flag = {
    {0, "PTHREAD_MUTEX_STALLED"},
    {0, "PTHREAD_MUTEX_STALLED_NP"},
    {1, "PTHREAD_MUTEX_ROBUST"},
    {1, "PTHREAD_MUTEX_ROBUST_NP"}
};

const defines_map pthread_mutex_protocol = {
    {0, "PTHREAD_PRIO_NONE"},
    {1, "PTHREAD_PRIO_INHERIT"},
    {2, "PTHREAD_PRIO_PROTECT"}
};

const defines_map pthread_rwlock_type = {
    {0, "PTHREAD_RWLOCK_PREFER_READER_NP"},
    {1, "PTHREAD_RWLOCK_PREFER_WRITER_NP"},
    {2, "PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP"},
    {0, "PTHREAD_RWLOCK_DEFAULT_NP"}
};

const defines_map<pthread_rwlock_t> pthread_rwlock_initializer = {
#ifdef __x86_64__
    {pthread_rwlock_t({{0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0}, 0, 0}}), "PTHREAD_RWLOCK_INITIALIZER"},
    {
        pthread_rwlock_t({{0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0}, 0, 2}}),
        "PTHREAD_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP"
    }
#else
    {pthread_rwlock_t({{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}), "PTHREAD_RWLOCK_INITIALIZER"},
    {pthread_rwlock_t({{0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0}}), "PTHREAD_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP"}
#endif
};

const defines_map pthread_scheduler_inheritance = {
    {0, "PTHREAD_INHERIT_SCHED"},
    {1, "PTHREAD_EXPLICIT_SCHED"}
};

const defines_map pthread_scope_handling = {
    {0, "PTHREAD_SCOPE_SYSTEM"},
    {1, "PTHREAD_SCOPE_PROCESS"}
};

const defines_map pthread_visibility_flag = {
    {0, "PTHREAD_PROCESS_PRIVATE"},
    {1, "PTHREAD_PROCESS_SHARED"}
};

// TODO: This changes between glibc versions. Embed the value either based on the current version we are building
// against or from a copy of the latest version of pthread_cond_t embedded the pthreadtypes header.
const defines_map<pthread_cond_t> pthread_cond_initializer = {
    {PTHREAD_COND_INITIALIZER, "PTHREAD_COND_INITIALIZER"}
};

const defines_map pthread_cancellation = {
    {0, "PTHREAD_CANCEL_ENABLE"},
    {1, "PTHREAD_CANCEL_DISABLE"}
};

const defines_map pthread_cancellation_type = {
    {0, "PTHREAD_CANCEL_DEFERRED"},
    {1, "PTHREAD_CANCEL_ASYNCHRONOUS"}
};

const defines_map<void*> pthread_cancelled = {
    {reinterpret_cast<void*>(-1), "PTHREAD_CANCELED"}
};

const defines_map pthread_once_init = {
    {0, "PTHREAD_ONCE_INIT"}
};

const defines_map pthread_barrier_serial_thread = {
    {-1, "PTHREAD_BARRIER_SERIAL_THREAD"}
};

const defines_map pthread_attr_no_sigmask_np = {
    {-1, "PTHREAD_ATTR_NO_SIGMASK_NP"}
};

template <typename T>
std::string print_pthread_detach_state(const T v)
{
    return print_enum_entry(v, pthread_detach_state);
}

template <typename T>
std::string print_pthread_mutex_type(const T v)
{
    return print_enum_entry(v, pthread_mutex_type);
}

template <typename T>
std::string print_pthread_mutex_flag(const T v)
{
    return print_enum_entry(v, pthread_mutex_flag);
}

template <typename T>
std::string print_pthread_mutex_protocol(const T v)
{
    return print_enum_entry(v, pthread_mutex_protocol);
}

template <typename T>
std::string print_pthread_rwlock_type(const T v)
{
    return print_enum_entry(v, pthread_rwlock_type);
}

template <typename T>
std::string print_pthread_rwlock_initializer(const T v)
{
    return print_enum_entry(v, pthread_rwlock_initializer);
}

template <typename T>
std::string print_pthread_scheduler_inheritance(const T v)
{
    return print_enum_entry(v, pthread_scheduler_inheritance);
}

template <typename T>
std::string print_pthread_scope_handling(const T v)
{
    return print_enum_entry(v, pthread_scope_handling);
}

template <typename T>
std::string print_pthread_visibility_flag(const T v)
{
    return print_enum_entry(v, pthread_visibility_flag);
}

template <typename T>
std::string print_pthread_cond_initializer(const T v)
{
    return print_enum_entry(v, pthread_cond_initializer);
}

template <typename T>
std::string print_pthread_cancellation(const T v)
{
    return print_enum_entry(v, pthread_cancellation);
}

template <typename T>
std::string print_pthread_cancellation_type(const T v)
{
    return print_enum_entry(v, pthread_cancellation_type);
}

template <typename T>
std::string print_pthread_cancelled(const T v)
{
    return print_enum_entry(v, pthread_cancelled);
}

template <typename T>
std::string print_pthread_once_init(const T v)
{
    return print_enum_entry(v, pthread_once_init);
}

template <typename T>
std::string print_pthread_barrier_serial_thread(const T v)
{
    return print_enum_entry(v, pthread_barrier_serial_thread, errno_error, errno_base_error);
}

template <typename T>
std::string print_pthread_attr_no_sigmask_np(const T v)
{
    return print_enum_entry(v, pthread_attr_no_sigmask_np, errno_error, errno_base_error);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _pthread_cleanup_buffer>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__routine, "__routine", &os));
    abii_args->push_arg(new ArgPrinter(obj.__arg, "__arg", &os));
    abii_args->push_arg(new ArgPrinter(obj.__canceltype, "__canceltype", &os));
    abii_args->push_arg(new ArgPrinter(obj.__prev, "__prev", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __cancel_jmp_buf_tag>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__cancel_jmp_buf, "__cancel_jmp_buf", &os));
    abii_args->push_arg(new ArgPrinter(obj.__mask_was_saved, "__mask_was_saved", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __pthread_unwind_buf_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__cancel_jmp_buf, "__cancel_jmp_buf", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad, "__pad", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __pthread_cleanup_frame>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__cancel_routine, "__cancel_routine", &os));
    abii_args->push_arg(new ArgPrinter(obj.__cancel_arg, "__cancel_arg", &os));
    abii_args->push_arg(new ArgPrinter(obj.__do_it, "__do_it", &os));
    abii_args->push_arg(new ArgPrinter(obj.__cancel_type, "__cancel_type", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

// TODO: Maybe add a converting constructor and explicitly match the member fields instead of relying on perfect ABI match
class pi___pthread_cleanup_class
{
    void (*__cancel_routine)(void*);
    void* __cancel_arg;
    int __do_it;
    int __cancel_type;

public:
    template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __pthread_cleanup_class>
    friend std::ostream& operator<<(std::ostream& os, T&& obj);
};

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __pthread_cleanup_class>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(reinterpret_cast<pi___pthread_cleanup_class*>(&obj)->__cancel_routine,
                                       "__cancel_routine", &os));
    abii_args->push_arg(new ArgPrinter(reinterpret_cast<pi___pthread_cleanup_class*>(&obj)->__cancel_arg,
                                       "__cancel_arg", &os));
    abii_args->push_arg(new ArgPrinter(reinterpret_cast<pi___pthread_cleanup_class*>(&obj)->__do_it, "__do_it", &os));
    abii_args->push_arg(new ArgPrinter(reinterpret_cast<pi___pthread_cleanup_class*>(&obj)->__cancel_type,
                                       "__cancel_type", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_PTHREAD_H
