//
// Created by Trent Tanchin on 7/4/26.
//

#include "time.h"

#include <abii/libabii.h>

#include "bits/time.h"
#include "bits/types/sigevent_t.h"
#include "bits/types/struct_itimerspec.h"
#include "bits/types/struct_timespec.h"
#include "bits/types/struct_tm.h"
#include "bits/types/__locale_t.h"

namespace abii
{
static clock_t (*real_clock)() __THROW = nullptr;

extern "C" clock_t abii_clock() __THROW
{
    OVERRIDE_PREFIX(clock)
        pre_fmtd_str pi_str = "clock()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_clock();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(clock, abii_ret)
    return real_clock();
}

static time_t (*real_time)(time_t*) __THROW = nullptr;

extern "C" time_t abii_time(time_t* timer) __THROW
{
    OVERRIDE_PREFIX(time)
        pre_fmtd_str pi_str = "time(__timer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timer, "__timer"));

        auto abii_ret = real_time(timer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(time, abii_ret)
    return real_time(timer);
}

static double (*real_difftime)(time_t, time_t) = nullptr;

extern "C" double abii_difftime(time_t time1, time_t time0)
{
    OVERRIDE_PREFIX(difftime)
        pre_fmtd_str pi_str = "difftime(__time1, __time0)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(time1, "__time1"));
        abii_args->push_arg(new ArgPrinter(time0, "__time0"));

        auto abii_ret = real_difftime(time1, time0);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(difftime, abii_ret)
    return real_difftime(time1, time0);
}

static time_t (*real_mktime)(tm*) __THROW = nullptr;

extern "C" time_t abii_mktime(tm* tp) __THROW
{
    OVERRIDE_PREFIX(mktime)
        pre_fmtd_str pi_str = "mktime(__tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_mktime(tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mktime, abii_ret)
    return real_mktime(tp);
}

static __nonnull((1, 3, 4)) size_t (*real_strftime)(char*, size_t, const char*, const tm*) __THROW = nullptr;

extern "C" __nonnull((1, 3, 4))
size_t abii_strftime(char* s, size_t maxsize, const char* format, const tm* tp) __THROW
{
    OVERRIDE_PREFIX(strftime)
        pre_fmtd_str pi_str = "strftime(__s, __maxsize, __format, __tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(maxsize);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(maxsize, "__maxsize"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_strftime(s, maxsize, format, tp);

        printer->set_len(abii_ret);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strftime, abii_ret)
    return real_strftime(s, maxsize, format, tp);
}

static char* (*real_strptime)(const char*, const char*, tm*) __THROW = nullptr;

extern "C" char* abii_strptime(const char* s, const char* fmt, tm* tp) __THROW
{
    OVERRIDE_PREFIX(strptime)
        pre_fmtd_str pi_str = "strptime(__s, __fmt, __tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(fmt, "__fmt"));
        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_strptime(s, fmt, tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strptime, abii_ret)
    return real_strptime(s, fmt, tp);
}

static __nonnull((1, 3, 4))
size_t (*real_strftime_l)(char*, size_t, const char*, const tm*, locale_t) __THROW = nullptr;

extern "C" size_t abii_strftime_l(char* s, size_t maxsize, const char* format, const tm* tp, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strftime_l)
        pre_fmtd_str pi_str = "strftime_l(__s, __maxsize, __format, __tp, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(s, "__s");
        printer->set_len(maxsize);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(maxsize, "__maxsize"));
        abii_args->push_arg(new ArgPrinter(format, "__format"));
        abii_args->push_arg(new ArgPrinter(tp, "__tp"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strftime_l(s, maxsize, format, tp, loc);

        printer->set_len(abii_ret);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strftime_l, abii_ret)
    return real_strftime_l(s, maxsize, format, tp, loc);
}

static char* (*real_strptime_l)(const char*, const char*, tm*, locale_t) __THROW = nullptr;

extern "C" char* abii_strptime_l(const char* s, const char* fmt, tm* tp, locale_t loc) __THROW
{
    OVERRIDE_PREFIX(strptime_l)
        pre_fmtd_str pi_str = "strptime_l(__s, __fmt, __tp, __loc)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(s, "__s"));
        abii_args->push_arg(new ArgPrinter(fmt, "__fmt"));
        abii_args->push_arg(new ArgPrinter(tp, "__tp"));
        abii_args->push_arg(new ArgPrinter(loc, "__loc"));

        auto abii_ret = real_strptime_l(s, fmt, tp, loc);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(strptime_l, abii_ret)
    return real_strptime_l(s, fmt, tp, loc);
}

static tm* (*real_gmtime)(const time_t*) __THROW = nullptr;

extern "C" tm* abii_gmtime(const time_t* timer) __THROW
{
    OVERRIDE_PREFIX(gmtime)
        pre_fmtd_str pi_str = "gmtime(__timer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timer, "__timer"));

        auto abii_ret = real_gmtime(timer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gmtime, abii_ret)
    return real_gmtime(timer);
}

static tm* (*real_localtime)(const time_t*) __THROW = nullptr;

extern "C" tm* abii_localtime(const time_t* timer) __THROW
{
    OVERRIDE_PREFIX(localtime)
        pre_fmtd_str pi_str = "localtime(__timer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timer, "__timer"));

        auto abii_ret = real_localtime(timer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(localtime, abii_ret)
    return real_localtime(timer);
}

static tm* (*real_gmtime_r)(const time_t*, tm*) __THROW = nullptr;

extern "C" tm* abii_gmtime_r(const time_t* timer, tm* tp) __THROW
{
    OVERRIDE_PREFIX(gmtime_r)
        pre_fmtd_str pi_str = "gmtime_r(__timer, __tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timer, "__timer"));
        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_gmtime_r(timer, tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gmtime_r, abii_ret)
    return real_gmtime_r(timer, tp);
}

static tm* (*real_localtime_r)(const time_t*, tm*) __THROW = nullptr;

extern "C" tm* abii_localtime_r(const time_t* timer, tm* tp) __THROW
{
    OVERRIDE_PREFIX(localtime_r)
        pre_fmtd_str pi_str = "localtime_r(__timer, __tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timer, "__timer"));
        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_localtime_r(timer, tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(localtime_r, abii_ret)
    return real_localtime_r(timer, tp);
}

static char* (*real_asctime)(const tm*) __THROW = nullptr;

extern "C" char* abii_asctime(const tm* tp) __THROW
{
    OVERRIDE_PREFIX(asctime)
        pre_fmtd_str pi_str = "asctime(__tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_asctime(tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(asctime, abii_ret)
    return real_asctime(tp);
}

static char* (*real_ctime)(const time_t*) __THROW = nullptr;

extern "C" char* abii_ctime(const time_t* timer) __THROW
{
    OVERRIDE_PREFIX(ctime)
        pre_fmtd_str pi_str = "ctime(__timer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timer, "__timer"));

        auto abii_ret = real_ctime(timer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ctime, abii_ret)
    return real_ctime(timer);
}

static char* (*real_asctime_r)(const tm*, char*) __THROW = nullptr;

extern "C" char* abii_asctime_r(const tm* tp, char* buf) __THROW
{
    OVERRIDE_PREFIX(asctime_r)
        pre_fmtd_str pi_str = "asctime_r(__tp, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tp, "__tp"));
        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        auto abii_ret = real_asctime_r(tp, buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(asctime_r, abii_ret)
    return real_asctime_r(tp, buf);
}

static char* (*real_ctime_r)(const time_t*, char*) __THROW = nullptr;

extern "C" char* abii_ctime_r(const time_t* timer, char* buf) __THROW
{
    OVERRIDE_PREFIX(ctime_r)
        pre_fmtd_str pi_str = "ctime_r(__timer, __buf)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timer, "__timer"));
        abii_args->push_arg(new ArgPrinter(buf, "__buf"));

        auto abii_ret = real_ctime_r(timer, buf);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ctime_r, abii_ret)
    return real_ctime_r(timer, buf);
}

static void (*real_tzset)() __THROW = nullptr;

extern "C" void abii_tzset() __THROW
{
    OVERRIDE_PREFIX(tzset)
        pre_fmtd_str pi_str = "tzset()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_tzset();
    OVERRIDE_SUFFIX(tzset,)
    return real_tzset();
}

static time_t (*real_timegm)(tm*) __THROW = nullptr;

extern "C" time_t abii_timegm(tm* tp) __THROW
{
    OVERRIDE_PREFIX(timegm)
        pre_fmtd_str pi_str = "timegm(__tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_timegm(tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(timegm, abii_ret)
    return real_timegm(tp);
}

static time_t (*real_timelocal)(tm*) __THROW = nullptr;

extern "C" time_t abii_timelocal(tm* tp) __THROW
{
    OVERRIDE_PREFIX(timelocal)
        pre_fmtd_str pi_str = "timelocal(__tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_timelocal(tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(timelocal, abii_ret)
    return real_timelocal(tp);
}

static int (*real_dysize)(int) __THROW = nullptr;

extern "C" __attribute__ ((__const__))
int abii_dysize(int year) __THROW
{
    OVERRIDE_PREFIX(dysize)
        pre_fmtd_str pi_str = "dysize(__year)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(year, "__year"));

        auto abii_ret = real_dysize(year);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dysize, abii_ret)
    return real_dysize(year);
}

static int (*real_nanosleep)(const timespec*, timespec*) = nullptr;

extern "C" int abii_nanosleep(const timespec* requested_time, timespec* remaining)
{
    OVERRIDE_PREFIX(nanosleep)
        pre_fmtd_str pi_str = "nanosleep(__requested_time, __remaining)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(requested_time, "__requested_time"));
        abii_args->push_arg(new ArgPrinter(remaining, "__remaining"));

        auto abii_ret = real_nanosleep(requested_time, remaining);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(nanosleep, abii_ret)
    return real_nanosleep(requested_time, remaining);
}

static int (*real_clock_getres)(clockid_t, timespec*) __THROW = nullptr;

extern "C" int abii_clock_getres(clockid_t clock_id, timespec* res) __THROW
{
    OVERRIDE_PREFIX(clock_getres)
        pre_fmtd_str pi_str = "clock_getres(__clock_id, __res)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer(print_time_clock, clock_id);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(res, "__res"));

        auto abii_ret = real_clock_getres(clock_id, res);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(clock_getres, abii_ret)
    return real_clock_getres(clock_id, res);
}

static __nonnull((2)) int (*real_clock_gettime)(clockid_t, timespec*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_clock_gettime(clockid_t clock_id, timespec* tp) __THROW
{
    OVERRIDE_PREFIX(clock_gettime)
        pre_fmtd_str pi_str = "clock_gettime(__clock_id, __tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer(print_time_clock, clock_id);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_clock_gettime(clock_id, tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(clock_gettime, abii_ret)
    return real_clock_gettime(clock_id, tp);
}

static __nonnull((2)) int (*real_clock_settime)(clockid_t, const timespec*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_clock_settime(clockid_t clock_id, const timespec* tp) __THROW
{
    OVERRIDE_PREFIX(clock_settime)
        pre_fmtd_str pi_str = "clock_settime(__clock_id, __tp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer(print_time_clock, clock_id);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(tp, "__tp"));

        auto abii_ret = real_clock_settime(clock_id, tp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(clock_settime, abii_ret)
    return real_clock_settime(clock_id, tp);
}

static int (*real_clock_nanosleep)(clockid_t, int, const timespec*, timespec*) = nullptr;

extern "C" int abii_clock_nanosleep(clockid_t clock_id, int flags, const timespec* req, timespec* rem)
{
    OVERRIDE_PREFIX(clock_nanosleep)
        pre_fmtd_str pi_str = "clock_nanosleep(__clock_id, __flags, __req, __rem)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer(print_time_clock, clock_id);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(flags, "__flags");
        printer1->set_enum_printer(print_time_timer_abstime, flags);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(req, "__req"));
        abii_args->push_arg(new ArgPrinter(rem, "__rem"));

        auto abii_ret = real_clock_nanosleep(clock_id, flags, req, rem);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(clock_nanosleep, abii_ret)
    return real_clock_nanosleep(clock_id, flags, req, rem);
}

static int (*real_clock_getcpuclockid)(pid_t, clockid_t*) __THROW = nullptr;

extern "C" int abii_clock_getcpuclockid(pid_t pid, clockid_t* clock_id) __THROW
{
    OVERRIDE_PREFIX(clock_getcpuclockid)
        pre_fmtd_str pi_str = "clock_getcpuclockid(__pid, __clock_id)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(pid, "__pid"));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer_with_depth(print_time_clock, *clock_id, 1);
        abii_args->push_arg(printer);

        auto abii_ret = real_clock_getcpuclockid(pid, clock_id);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(clock_getcpuclockid, abii_ret)
    return real_clock_getcpuclockid(pid, clock_id);
}

static int (*real_timer_create)(clockid_t, sigevent*, timer_t*) __THROW = nullptr;

extern "C" int abii_timer_create(clockid_t clock_id, sigevent* evp, timer_t* timerid) __THROW
{
    OVERRIDE_PREFIX(timer_create)
        pre_fmtd_str pi_str = "timer_create(__clock_id, __evp, __timerid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(clock_id, "__clock_id");
        printer->set_enum_printer(print_time_clock, clock_id);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(evp, "__evp"));
        abii_args->push_arg(new ArgPrinter(timerid, "__timerid"));

        auto abii_ret = real_timer_create(clock_id, evp, timerid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(timer_create, abii_ret)
    return real_timer_create(clock_id, evp, timerid);
}

static int (*real_timer_delete)(timer_t) __THROW = nullptr;

extern "C" int abii_timer_delete(timer_t timerid) __THROW
{
    OVERRIDE_PREFIX(timer_delete)
        pre_fmtd_str pi_str = "timer_delete(__timerid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timerid, "__timerid"));

        auto abii_ret = real_timer_delete(timerid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(timer_delete, abii_ret)
    return real_timer_delete(timerid);
}

static int (*real_timer_settime)(timer_t, int, const itimerspec*, itimerspec*) __THROW = nullptr;

extern "C" int abii_timer_settime(timer_t timerid, int flags, const itimerspec* value, itimerspec* ovalue) __THROW
{
    OVERRIDE_PREFIX(timer_settime)
        pre_fmtd_str pi_str = "timer_settime(__timerid, __flags, __value, __ovalue)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timerid, "__timerid"));

        auto printer1 = new ArgPrinter(flags, "__flags");
        printer1->set_enum_printer(print_time_timer_abstime, flags);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(value, "__value"));
        abii_args->push_arg(new ArgPrinter(ovalue, "__ovalue"));

        auto abii_ret = real_timer_settime(timerid, flags, value, ovalue);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(timer_settime, abii_ret)
    return real_timer_settime(timerid, flags, value, ovalue);
}

static int (*real_timer_gettime)(timer_t, itimerspec*) __THROW = nullptr;

extern "C" int abii_timer_gettime(timer_t timerid, itimerspec* value) __THROW
{
    OVERRIDE_PREFIX(timer_gettime)
        pre_fmtd_str pi_str = "timer_gettime(__timerid, __value)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timerid, "__timerid"));
        abii_args->push_arg(new ArgPrinter(value, "__value"));

        auto abii_ret = real_timer_gettime(timerid, value);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(timer_gettime, abii_ret)
    return real_timer_gettime(timerid, value);
}

static int (*real_timer_getoverrun)(timer_t) __THROW = nullptr;

extern "C" int abii_timer_getoverrun(timer_t timerid) __THROW
{
    OVERRIDE_PREFIX(timer_getoverrun)
        pre_fmtd_str pi_str = "timer_getoverrun(__timerid)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(timerid, "__timerid"));

        auto abii_ret = real_timer_getoverrun(timerid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(timer_getoverrun, abii_ret)
    return real_timer_getoverrun(timerid);
}

static __nonnull((1)) int (*real_timespec_get)(timespec*, int) __THROW = nullptr;

extern "C" __nonnull((1))
int abii_timespec_get(timespec* ts, int base) __THROW
{
    OVERRIDE_PREFIX(timespec_get)
        pre_fmtd_str pi_str = "timespec_get(__ts, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ts, "__ts"));

        auto printer = new ArgPrinter(base, "__base");
        printer->set_enum_printer(print_time_base, base);
        abii_args->push_arg(printer);

        auto abii_ret = real_timespec_get(ts, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(timespec_get, abii_ret)
    return real_timespec_get(ts, base);
}

static int (*real_timespec_getres)(timespec*, int) __THROW = nullptr;

extern "C" int abii_timespec_getres(timespec* ts, int base) __THROW
{
    OVERRIDE_PREFIX(timespec_getres)
        pre_fmtd_str pi_str = "timespec_getres(__ts, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ts, "__ts"));

        auto printer = new ArgPrinter(base, "__base");
        printer->set_enum_printer(print_time_base, base);
        abii_args->push_arg(printer);

        auto abii_ret = real_timespec_getres(ts, base);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(timespec_getres, abii_ret)
    return real_timespec_getres(ts, base);
}

static tm* (*real_getdate)(const char*) = nullptr;

extern "C" tm* abii_getdate(const char* string)
{
    OVERRIDE_PREFIX(getdate)
        pre_fmtd_str pi_str = "getdate(__string)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));

        auto abii_ret = real_getdate(string);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getdate, abii_ret)
    return real_getdate(string);
}

static int (*real_getdate_r)(const char*, tm*) = nullptr;

extern "C" int abii_getdate_r(const char* string, tm* resbufp)
{
    OVERRIDE_PREFIX(getdate_r)
        pre_fmtd_str pi_str = "getdate_r(__string, __resbufp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));
        abii_args->push_arg(new ArgPrinter(resbufp, "__resbufp"));

        auto abii_ret = real_getdate_r(string, resbufp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getdate_r, abii_ret)
    return real_getdate_r(string, resbufp);
}
}
