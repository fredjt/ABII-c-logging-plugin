//
// Created by Trent Tanchin on 10/6/24.
//

#include "bits/mqueue.h"

#include <mqueue.h>
#include <abii/libabii.h>

#include "custom_printers.h"
#include "bits/fcntl-linux.h"
#include "bits/types/sigevent_t.h"
#include "bits/types/struct_timespec.h"

namespace abii
{
static mqd_t (*real_mq_open)(const char*, int, ...) __THROW = nullptr;

extern "C" __nonnull((1))
mqd_t abii_mq_open(const char* name, int oflag, ...) __THROW
{
    OVERRIDE_VARIADIC_PREFIX(mq_open, format)
        pre_fmtd_str str = "mq_open(__name, __oflag, ...)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto printer = new ArgPrinter(oflag, "__oflag");
        printer->set_enum_printer(print_fcntl_linux_oflag, oflag);
        abii_args->push_arg(printer);

        const char* format = nullptr;
        if (oflag & O_CREAT)
            format = "%u%lu"; // The contents of this string are unimportant; it just shows what is in vargs.
        PUSH_VARIADIC_ARGS(printer1, format, print_variadic_args_mq_open)

        const auto abii_ret = __builtin_apply(reinterpret_cast<void (*)(...)>(real_mq_open), abii_bi_vargs, 1000);

        abii_args->push_return(new ArgPrinter(*reinterpret_cast<mqd_t*>(abii_ret), "return"));
    OVERRIDE_VARIADIC_SUFFIX(mq_open, abii_ret, format)
    __builtin_return(__builtin_apply(reinterpret_cast<void (*)(...)>(real_mq_open), abii_bi_vargs, 1000));
}

static int (*real_mq_close)(mqd_t) __THROW = nullptr;

extern "C" int abii_mq_close(mqd_t mqdes) __THROW
{
    OVERRIDE_PREFIX(mq_close)
        pre_fmtd_str str = "mq_close(__mqdes)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mqdes, "__mqdes"));

        const auto abii_ret = real_mq_close(mqdes);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mq_close, abii_ret)
    return real_mq_close(mqdes);
}

static int (*real_mq_getattr)(mqd_t, mq_attr*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_mq_getattr(mqd_t mqdes, mq_attr* mqstat) __THROW
{
    OVERRIDE_PREFIX(mq_getattr)
        pre_fmtd_str str = "mq_getattr(__mqdes, __mqstat)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mqdes, "__mqdes"));
        abii_args->push_arg(new ArgPrinter(mqstat, "__mqstat"));

        const auto abii_ret = real_mq_getattr(mqdes, mqstat);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mq_getattr, abii_ret)
    return real_mq_getattr(mqdes, mqstat);
}

static int (*real_mq_setattr)(mqd_t, const mq_attr*, mq_attr*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_mq_setattr(mqd_t mqdes, const mq_attr* mqstat, mq_attr* omqstat) __THROW
{
    OVERRIDE_PREFIX(mq_setattr)
        pre_fmtd_str str = "mq_setattr(__mqdes, __mqstat, __omqstat)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mqdes, "__mqdes"));
        abii_args->push_arg(new ArgPrinter(mqstat, "__mqstat"));
        abii_args->push_arg(new ArgPrinter(omqstat, "__omqstat"));

        const auto abii_ret = real_mq_setattr(mqdes, mqstat, omqstat);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mq_setattr, abii_ret)
    return real_mq_setattr(mqdes, mqstat, omqstat);
}

static int (*real_mq_unlink)(const char*) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_mq_unlink(const char* name) __THROW
{
    OVERRIDE_PREFIX(mq_unlink)
        pre_fmtd_str str = "mq_unlink(__name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        const auto abii_ret = real_mq_unlink(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mq_unlink, abii_ret)
    return real_mq_unlink(name);
}

static int (*real_mq_notify)(mqd_t, const sigevent*) __THROW = nullptr;

extern "C" int abii_mq_notify(mqd_t mqdes, const sigevent* notification) __THROW
{
    OVERRIDE_PREFIX(mq_notify)
        pre_fmtd_str str = "mq_notify(__mqdes, __notification)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mqdes, "__mqdes"));
        abii_args->push_arg(new ArgPrinter(notification, "__notification"));

        const auto abii_ret = real_mq_notify(mqdes, notification);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mq_notify, abii_ret)
    return real_mq_notify(mqdes, notification);
}

static ssize_t (*real_mq_receive)(mqd_t, char*, size_t, unsigned int*) = nullptr;

extern "C" __nonnull((2))
ssize_t abii_mq_receive(mqd_t mqdes, char* msg_ptr, size_t msg_len, unsigned int* msg_prio)
{
    OVERRIDE_PREFIX(mq_receive)
        pre_fmtd_str str = "mq_receive(__mqdes, __msg_ptr, __msg_len, __msg_prio)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mqdes, "__mqdes"));

        auto printer = new ArgPrinter(msg_ptr, "__msg_ptr");
        printer->set_len(msg_len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(msg_len, "__msg_len"));
        abii_args->push_arg(new ArgPrinter(msg_prio, "__msg_prio"));

        const auto abii_ret = real_mq_receive(mqdes, msg_ptr, msg_len, msg_prio);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mq_receive, abii_ret)
    return real_mq_receive(mqdes, msg_ptr, msg_len, msg_prio);
}

static int (*real_mq_send)(mqd_t, const char*, size_t, unsigned int) = nullptr;

extern "C" __nonnull((2))
int abii_mq_send(mqd_t mqdes, const char* msg_ptr, size_t msg_len, unsigned int msg_prio)
{
    OVERRIDE_PREFIX(mq_send)
        pre_fmtd_str str = "mq_send(__mqdes, __msg_ptr, __msg_len, __msg_prio)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mqdes, "__mqdes"));

        auto printer = new ArgPrinter(msg_ptr, "__msg_ptr");
        printer->set_len(msg_len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(msg_len, "__msg_len"));
        abii_args->push_arg(new ArgPrinter(msg_prio, "__msg_prio"));

        const auto abii_ret = real_mq_send(mqdes, msg_ptr, msg_len, msg_prio);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mq_send, abii_ret)
    return real_mq_send(mqdes, msg_ptr, msg_len, msg_prio);
}

static ssize_t (*real_mq_timedreceive)(mqd_t, char*, size_t, unsigned int*, const timespec*) = nullptr;

extern "C" __nonnull((2, 5))
ssize_t abii_mq_timedreceive(mqd_t mqdes, char* msg_ptr, size_t msg_len, unsigned int* msg_prio,
                             const timespec* abs_timeout)
{
    OVERRIDE_PREFIX(mq_timedreceive)
        pre_fmtd_str str = "mq_timedreceive(__mqdes, __msg_ptr, __msg_len, __msg_prio, __abs_timeout)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mqdes, "__mqdes"));

        auto printer = new ArgPrinter(msg_ptr, "__msg_ptr");
        printer->set_len(msg_len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(msg_len, "__msg_len"));
        abii_args->push_arg(new ArgPrinter(msg_prio, "__msg_prio"));
        abii_args->push_arg(new ArgPrinter(abs_timeout, "__abs_timeout"));

        const auto abii_ret = real_mq_timedreceive(mqdes, msg_ptr, msg_len, msg_prio, abs_timeout);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mq_timedreceive, abii_ret)
    return real_mq_timedreceive(mqdes, msg_ptr, msg_len, msg_prio, abs_timeout);
}

static int (*real_mq_timedsend)(mqd_t, const char*, size_t, unsigned int, const timespec*) = nullptr;

extern "C" __nonnull((2, 5))
int abii_mq_timedsend(mqd_t mqdes, const char* msg_ptr, size_t msg_len, unsigned int msg_prio,
                      const timespec* abs_timeout)
{
    OVERRIDE_PREFIX(mq_timedsend)
        pre_fmtd_str str = "mq_timedsend(__mqdes, __msg_ptr, __msg_len, __msg_prio, __abs_timeout)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(mqdes, "__mqdes"));

        auto printer = new ArgPrinter(msg_ptr, "__msg_ptr");
        printer->set_len(msg_len);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(msg_len, "__msg_len"));
        abii_args->push_arg(new ArgPrinter(msg_prio, "__msg_prio"));
        abii_args->push_arg(new ArgPrinter(abs_timeout, "__abs_timeout"));

        const auto abii_ret = real_mq_timedsend(mqdes, msg_ptr, msg_len, msg_prio, abs_timeout);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mq_timedsend, abii_ret)
    return real_mq_timedsend(mqdes, msg_ptr, msg_len, msg_prio, abs_timeout);
}
}
