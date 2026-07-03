//
// Created by Trent Tanchin on 7/3/26.
//

#include "thread_db.h"

#include <abii/libabii.h>

#include "bits/types/__sigset_t.h"
#include "sys/user.h"

namespace abii
{
static td_err_e (*real_td_init)() = nullptr;

extern "C" td_err_e abii_td_init()
{
    OVERRIDE_PREFIX(td_init)
        pre_fmtd_str pi_str = "td_init()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_td_init();

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_init, abii_ret)
    return real_td_init();
}

static td_err_e (*real_td_log)() = nullptr;

extern "C" td_err_e abii_td_log()
{
    OVERRIDE_PREFIX(td_log)
        pre_fmtd_str pi_str = "td_log()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_td_log();

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_log, abii_ret)
    return real_td_log();
}

static const char** (*real_td_symbol_list)() = nullptr;

extern "C" const char** abii_td_symbol_list()
{
    OVERRIDE_PREFIX(td_symbol_list)
        pre_fmtd_str pi_str = "td_symbol_list()";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto abii_ret = real_td_symbol_list();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(td_symbol_list, abii_ret)
    return real_td_symbol_list();
}

static td_err_e (*real_td_ta_new)(ps_prochandle*, td_thragent_t**) = nullptr;

extern "C" td_err_e abii_td_ta_new(ps_prochandle* ps, td_thragent_t** ta)
{
    OVERRIDE_PREFIX(td_ta_new)
        pre_fmtd_str pi_str = "td_ta_new(__ps, __ta)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ps, "__ps"));
        abii_args->push_arg(new ArgPrinter(ta, "__ta"));

        auto abii_ret = real_td_ta_new(ps, ta);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_new, abii_ret)
    return real_td_ta_new(ps, ta);
}

static td_err_e (*real_td_ta_delete)(td_thragent_t*) = nullptr;

extern "C" td_err_e abii_td_ta_delete(td_thragent_t* ta)
{
    OVERRIDE_PREFIX(td_ta_delete)
        pre_fmtd_str pi_str = "td_ta_delete(__ta)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));

        auto abii_ret = real_td_ta_delete(ta);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_delete, abii_ret)
    return real_td_ta_delete(ta);
}

static td_err_e (*real_td_ta_get_nthreads)(const td_thragent_t*, int*) = nullptr;

extern "C" td_err_e abii_td_ta_get_nthreads(const td_thragent_t* ta, int* np)
{
    OVERRIDE_PREFIX(td_ta_get_nthreads)
        pre_fmtd_str pi_str = "td_ta_get_nthreads(__ta, __np)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(np, "__np"));

        auto abii_ret = real_td_ta_get_nthreads(ta, np);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_get_nthreads, abii_ret)
    return real_td_ta_get_nthreads(ta, np);
}

static td_err_e (*real_td_ta_get_ph)(const td_thragent_t*, ps_prochandle**) = nullptr;

extern "C" td_err_e abii_td_ta_get_ph(const td_thragent_t* ta, ps_prochandle** ph)
{
    OVERRIDE_PREFIX(td_ta_get_ph)
        pre_fmtd_str pi_str = "td_ta_get_ph(__ta, __ph)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(ph, "__ph"));

        auto abii_ret = real_td_ta_get_ph(ta, ph);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_get_ph, abii_ret)
    return real_td_ta_get_ph(ta, ph);
}

static td_err_e (*real_td_ta_map_id2thr)(const td_thragent_t*, pthread_t, td_thrhandle_t*) = nullptr;

extern "C" td_err_e abii_td_ta_map_id2thr(const td_thragent_t* ta, pthread_t pt, td_thrhandle_t* th)
{
    OVERRIDE_PREFIX(td_ta_map_id2thr)
        pre_fmtd_str pi_str = "td_ta_map_id2thr(__ta, __pt, __th)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(pt, "__pt"));
        abii_args->push_arg(new ArgPrinter(th, "__th"));

        auto abii_ret = real_td_ta_map_id2thr(ta, pt, th);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_map_id2thr, abii_ret)
    return real_td_ta_map_id2thr(ta, pt, th);
}

static td_err_e (*real_td_ta_map_lwp2thr)(const td_thragent_t*, lwpid_t, td_thrhandle_t*) = nullptr;

extern "C" td_err_e abii_td_ta_map_lwp2thr(const td_thragent_t* ta, lwpid_t lwpid, td_thrhandle_t* th)
{
    OVERRIDE_PREFIX(td_ta_map_lwp2thr)
        pre_fmtd_str pi_str = "td_ta_map_lwp2thr(__ta, __lwpid, __th)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(lwpid, "__lwpid"));
        abii_args->push_arg(new ArgPrinter(th, "__th"));

        auto abii_ret = real_td_ta_map_lwp2thr(ta, lwpid, th);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_map_lwp2thr, abii_ret)
    return real_td_ta_map_lwp2thr(ta, lwpid, th);
}

static td_err_e (*real_td_ta_thr_iter)(const td_thragent_t*, td_thr_iter_f*, void*, td_thr_state_e, int, sigset_t*,
                                       unsigned int) = nullptr;

extern "C" td_err_e abii_td_ta_thr_iter(const td_thragent_t* ta, td_thr_iter_f* callback, void* cbdata_p,
                                        td_thr_state_e state, int ti_pri, sigset_t* ti_sigmask_p,
                                        unsigned int ti_user_flags)
{
    OVERRIDE_PREFIX(td_ta_thr_iter)
        pre_fmtd_str pi_str =
            "td_ta_thr_iter(__ta, __callback, __cbdata_p, __state, __ti_pri, __ti_sigmask_p, __ti_user_flags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(callback, "__callback"));
        abii_args->push_arg(new ArgPrinter(cbdata_p, "__cbdata_p"));

        auto printer = new ArgPrinter(state, "__state");
        printer->set_enum_printer(print_thread_db_td_thr_state_e, state);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(ti_pri, "__ti_pri"));
        abii_args->push_arg(new ArgPrinter(ti_sigmask_p, "__ti_sigmask_p"));
        abii_args->push_arg(new ArgPrinter(ti_user_flags, "__ti_user_flags"));

        auto abii_ret = real_td_ta_thr_iter(ta, callback, cbdata_p, state, ti_pri, ti_sigmask_p, ti_user_flags);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(td_ta_thr_iter, abii_ret)
    return real_td_ta_thr_iter(ta, callback, cbdata_p, state, ti_pri, ti_sigmask_p, ti_user_flags);
}

static td_err_e (*real_td_ta_tsd_iter)(const td_thragent_t*, td_key_iter_f*, void*) = nullptr;

extern "C" td_err_e abii_td_ta_tsd_iter(const td_thragent_t* ta, td_key_iter_f* ki, void* p)
{
    OVERRIDE_PREFIX(td_ta_tsd_iter)
        pre_fmtd_str pi_str = "td_ta_tsd_iter(__ta, __ki, __p)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(ki, "__ki"));
        abii_args->push_arg(new ArgPrinter(p, "__p"));

        auto abii_ret = real_td_ta_tsd_iter(ta, ki, p);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_tsd_iter, abii_ret)
    return real_td_ta_tsd_iter(ta, ki, p);
}

static td_err_e (*real_td_ta_event_addr)(const td_thragent_t*, td_event_e, td_notify_t*) = nullptr;

extern "C" td_err_e abii_td_ta_event_addr(const td_thragent_t* ta, td_event_e event, td_notify_t* ptr)
{
    OVERRIDE_PREFIX(td_ta_event_addr)
        pre_fmtd_str pi_str = "td_ta_event_addr(__ta, __event, __ptr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));

        auto printer = new ArgPrinter(event, "__event");
        printer->set_enum_printer(print_thread_db_td_event_e, event);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));

        auto abii_ret = real_td_ta_event_addr(ta, event, ptr);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(td_ta_event_addr, abii_ret)
    return real_td_ta_event_addr(ta, event, ptr);
}

static td_err_e (*real_td_ta_set_event)(const td_thragent_t*, td_thr_events_t*) = nullptr;

extern "C" td_err_e abii_td_ta_set_event(const td_thragent_t* ta, td_thr_events_t* event)
{
    OVERRIDE_PREFIX(td_ta_set_event)
        pre_fmtd_str pi_str = "td_ta_set_event(__ta, __event)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(event, "__event"));

        auto abii_ret = real_td_ta_set_event(ta, event);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_set_event, abii_ret)
    return real_td_ta_set_event(ta, event);
}

static td_err_e (*real_td_ta_clear_event)(const td_thragent_t*, td_thr_events_t*) = nullptr;

extern "C" td_err_e abii_td_ta_clear_event(const td_thragent_t* ta, td_thr_events_t* event)
{
    OVERRIDE_PREFIX(td_ta_clear_event)
        pre_fmtd_str pi_str = "td_ta_clear_event(__ta, __event)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(event, "__event"));

        auto abii_ret = real_td_ta_clear_event(ta, event);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_clear_event, abii_ret)
    return real_td_ta_clear_event(ta, event);
}

static td_err_e (*real_td_ta_event_getmsg)(const td_thragent_t*, td_event_msg_t*) = nullptr;

extern "C" td_err_e abii_td_ta_event_getmsg(const td_thragent_t* ta, td_event_msg_t* msg)
{
    OVERRIDE_PREFIX(td_ta_event_getmsg)
        pre_fmtd_str pi_str = "td_ta_event_getmsg(__ta, __msg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(msg, "__msg"));

        auto abii_ret = real_td_ta_event_getmsg(ta, msg);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_event_getmsg, abii_ret)
    return real_td_ta_event_getmsg(ta, msg);
}

static td_err_e (*real_td_ta_setconcurrency)(const td_thragent_t*, int) = nullptr;

extern "C" td_err_e abii_td_ta_setconcurrency(const td_thragent_t* ta, int level)
{
    OVERRIDE_PREFIX(td_ta_setconcurrency)
        pre_fmtd_str pi_str = "td_ta_setconcurrency(__ta, __level)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(level, "__level"));

        auto abii_ret = real_td_ta_setconcurrency(ta, level);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_setconcurrency, abii_ret)
    return real_td_ta_setconcurrency(ta, level);
}

static td_err_e (*real_td_ta_enable_stats)(const td_thragent_t*, int) = nullptr;

extern "C" td_err_e abii_td_ta_enable_stats(const td_thragent_t* ta, int enable)
{
    OVERRIDE_PREFIX(td_ta_enable_stats)
        pre_fmtd_str pi_str = "td_ta_enable_stats(__ta, __enable)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(enable, "__enable"));

        auto abii_ret = real_td_ta_enable_stats(ta, enable);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_enable_stats, abii_ret)
    return real_td_ta_enable_stats(ta, enable);
}

static td_err_e (*real_td_ta_reset_stats)(const td_thragent_t*) = nullptr;

extern "C" td_err_e abii_td_ta_reset_stats(const td_thragent_t* ta)
{
    OVERRIDE_PREFIX(td_ta_reset_stats)
        pre_fmtd_str pi_str = "td_ta_reset_stats(__ta)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));

        auto abii_ret = real_td_ta_reset_stats(ta);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_reset_stats, abii_ret)
    return real_td_ta_reset_stats(ta);
}

static td_err_e (*real_td_ta_get_stats)(const td_thragent_t*, td_ta_stats_t*) = nullptr;

extern "C" td_err_e abii_td_ta_get_stats(const td_thragent_t* ta, td_ta_stats_t* statsp)
{
    OVERRIDE_PREFIX(td_ta_get_stats)
        pre_fmtd_str pi_str = "td_ta_get_stats(__ta, __statsp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ta, "__ta"));
        abii_args->push_arg(new ArgPrinter(statsp, "__statsp"));

        auto abii_ret = real_td_ta_get_stats(ta, statsp);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_ta_get_stats, abii_ret)
    return real_td_ta_get_stats(ta, statsp);
}

static td_err_e (*real_td_thr_validate)(const td_thrhandle_t*) = nullptr;

extern "C" td_err_e abii_td_thr_validate(const td_thrhandle_t* th)
{
    OVERRIDE_PREFIX(td_thr_validate)
        pre_fmtd_str pi_str = "td_thr_validate(__th)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));

        auto abii_ret = real_td_thr_validate(th);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_validate, abii_ret)
    return real_td_thr_validate(th);
}

static td_err_e (*real_td_thr_get_info)(const td_thrhandle_t*, td_thrinfo_t*) = nullptr;

extern "C" td_err_e abii_td_thr_get_info(const td_thrhandle_t* th, td_thrinfo_t* infop)
{
    OVERRIDE_PREFIX(td_thr_get_info)
        pre_fmtd_str pi_str = "td_thr_get_info(__th, __infop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(infop, "__infop"));

        auto abii_ret = real_td_thr_get_info(th, infop);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_get_info, abii_ret)
    return real_td_thr_get_info(th, infop);
}

static td_err_e (*real_td_thr_getfpregs)(const td_thrhandle_t*, prfpregset_t*) = nullptr;

extern "C" td_err_e abii_td_thr_getfpregs(const td_thrhandle_t* th, prfpregset_t* regset)
{
    OVERRIDE_PREFIX(td_thr_getfpregs)
        pre_fmtd_str pi_str = "td_thr_getfpregs(__th, __regset)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(regset, "__regset"));

        auto abii_ret = real_td_thr_getfpregs(th, regset);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_getfpregs, abii_ret)
    return real_td_thr_getfpregs(th, regset);
}

static td_err_e (*real_td_thr_getgregs)(const td_thrhandle_t*, prgregset_t) = nullptr;

extern "C" td_err_e abii_td_thr_getgregs(const td_thrhandle_t* th, prgregset_t gregs)
{
    OVERRIDE_PREFIX(td_thr_getgregs)
        pre_fmtd_str pi_str = "td_thr_getgregs(__th, __gregs)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(gregs, "__gregs"));

        auto abii_ret = real_td_thr_getgregs(th, gregs);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_getgregs, abii_ret)
    return real_td_thr_getgregs(th, gregs);
}

static td_err_e (*real_td_thr_getxregs)(const td_thrhandle_t*, void*) = nullptr;

extern "C" td_err_e abii_td_thr_getxregs(const td_thrhandle_t* th, void* xregs)
{
    OVERRIDE_PREFIX(td_thr_getxregs)
        pre_fmtd_str pi_str = "td_thr_getxregs(__th, __xregs)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(xregs, "__xregs"));

        auto abii_ret = real_td_thr_getxregs(th, xregs);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_getxregs, abii_ret)
    return real_td_thr_getxregs(th, xregs);
}

static td_err_e (*real_td_thr_getxregsize)(const td_thrhandle_t*, int*) = nullptr;

extern "C" td_err_e abii_td_thr_getxregsize(const td_thrhandle_t* th, int* sizep)
{
    OVERRIDE_PREFIX(td_thr_getxregsize)
        pre_fmtd_str pi_str = "td_thr_getxregsize(__th, __sizep)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(sizep, "__sizep"));

        auto abii_ret = real_td_thr_getxregsize(th, sizep);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_getxregsize, abii_ret)
    return real_td_thr_getxregsize(th, sizep);
}

static td_err_e (*real_td_thr_setfpregs)(const td_thrhandle_t*, const prfpregset_t*) = nullptr;

extern "C" td_err_e abii_td_thr_setfpregs(const td_thrhandle_t* th, const prfpregset_t* fpregs)
{
    OVERRIDE_PREFIX(td_thr_setfpregs)
        pre_fmtd_str pi_str = "td_thr_setfpregs(__th, __fpregs)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(fpregs, "__fpregs"));

        auto abii_ret = real_td_thr_setfpregs(th, fpregs);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_setfpregs, abii_ret)
    return real_td_thr_setfpregs(th, fpregs);
}

static td_err_e (*real_td_thr_setgregs)(const td_thrhandle_t*, prgregset_t) = nullptr;

extern "C" td_err_e abii_td_thr_setgregs(const td_thrhandle_t* th, prgregset_t gregs)
{
    OVERRIDE_PREFIX(td_thr_setgregs)
        pre_fmtd_str pi_str = "td_thr_setgregs(__th, __gregs)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(gregs, "__gregs"));

        auto abii_ret = real_td_thr_setgregs(th, gregs);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_setgregs, abii_ret)
    return real_td_thr_setgregs(th, gregs);
}

static td_err_e (*real_td_thr_setxregs)(const td_thrhandle_t*, const void*) = nullptr;

extern "C" td_err_e abii_td_thr_setxregs(const td_thrhandle_t* th, const void* addr)
{
    OVERRIDE_PREFIX(td_thr_setxregs)
        pre_fmtd_str pi_str = "td_thr_setxregs(__th, __addr)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(addr, "__addr"));

        auto abii_ret = real_td_thr_setxregs(th, addr);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_setxregs, abii_ret)
    return real_td_thr_setxregs(th, addr);
}

static td_err_e (*real_td_thr_tlsbase)(const td_thrhandle_t*, unsigned long int, psaddr_t*) = nullptr;

extern "C" td_err_e abii_td_thr_tlsbase(const td_thrhandle_t* th, unsigned long int modid, psaddr_t* base)
{
    OVERRIDE_PREFIX(td_thr_tlsbase)
        pre_fmtd_str pi_str = "td_thr_tlsbase(__th, __modid, __base)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(modid, "__modid"));
        abii_args->push_arg(new ArgPrinter(base, "__base"));

        auto abii_ret = real_td_thr_tlsbase(th, modid, base);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_tlsbase, abii_ret)
    return real_td_thr_tlsbase(th, modid, base);
}

static td_err_e (*real_td_thr_tls_get_addr)(const td_thrhandle_t*, psaddr_t, size_t, psaddr_t*) = nullptr;

extern "C" td_err_e abii_td_thr_tls_get_addr(const td_thrhandle_t* th, psaddr_t map_address, size_t offset,
                                             psaddr_t* address)
{
    OVERRIDE_PREFIX(td_thr_tls_get_addr)
        pre_fmtd_str pi_str = "td_thr_tls_get_addr(__th, __map_address, __offset, __address)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(map_address, "__map_address"));
        abii_args->push_arg(new ArgPrinter(offset, "__offset"));
        abii_args->push_arg(new ArgPrinter(address, "__address"));

        auto abii_ret = real_td_thr_tls_get_addr(th, map_address, offset, address);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_tls_get_addr, abii_ret)
    return real_td_thr_tls_get_addr(th, map_address, offset, address);
}

static td_err_e (*real_td_thr_event_enable)(const td_thrhandle_t*, int) = nullptr;

extern "C" td_err_e abii_td_thr_event_enable(const td_thrhandle_t* th, int event)
{
    OVERRIDE_PREFIX(td_thr_event_enable)
        pre_fmtd_str pi_str = "td_thr_event_enable(__th, __event)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));

        auto printer = new ArgPrinter(event, "__event");
        printer->set_enum_printer(print_thread_db_td_event_e, event);
        abii_args->push_arg(printer);

        auto abii_ret = real_td_thr_event_enable(th, event);

        auto printer1 = new ArgPrinter(abii_ret, "return");
        printer1->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer1);
    OVERRIDE_SUFFIX(td_thr_event_enable, abii_ret)
    return real_td_thr_event_enable(th, event);
}

static td_err_e (*real_td_thr_set_event)(const td_thrhandle_t*, td_thr_events_t*) = nullptr;

extern "C" td_err_e abii_td_thr_set_event(const td_thrhandle_t* th, td_thr_events_t* event)
{
    OVERRIDE_PREFIX(td_thr_set_event)
        pre_fmtd_str pi_str = "td_thr_set_event(__th, __event)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(event, "__event"));

        auto abii_ret = real_td_thr_set_event(th, event);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_set_event, abii_ret)
    return real_td_thr_set_event(th, event);
}

static td_err_e (*real_td_thr_clear_event)(const td_thrhandle_t*, td_thr_events_t*) = nullptr;

extern "C" td_err_e abii_td_thr_clear_event(const td_thrhandle_t* th, td_thr_events_t* event)
{
    OVERRIDE_PREFIX(td_thr_clear_event)
        pre_fmtd_str pi_str = "td_thr_clear_event(__th, __event)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(event, "__event"));

        auto abii_ret = real_td_thr_clear_event(th, event);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_clear_event, abii_ret)
    return real_td_thr_clear_event(th, event);
}

static td_err_e (*real_td_thr_event_getmsg)(const td_thrhandle_t*, td_event_msg_t*) = nullptr;

extern "C" td_err_e abii_td_thr_event_getmsg(const td_thrhandle_t* th, td_event_msg_t* msg)
{
    OVERRIDE_PREFIX(td_thr_event_getmsg)
        pre_fmtd_str pi_str = "td_thr_event_getmsg(__th, __msg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(msg, "__msg"));

        auto abii_ret = real_td_thr_event_getmsg(th, msg);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_event_getmsg, abii_ret)
    return real_td_thr_event_getmsg(th, msg);
}

static td_err_e (*real_td_thr_setprio)(const td_thrhandle_t*, int) = nullptr;

extern "C" td_err_e abii_td_thr_setprio(const td_thrhandle_t* th, int prio)
{
    OVERRIDE_PREFIX(td_thr_setprio)
        pre_fmtd_str pi_str = "td_thr_setprio(__th, __prio)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(prio, "__prio"));

        auto abii_ret = real_td_thr_setprio(th, prio);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_setprio, abii_ret)
    return real_td_thr_setprio(th, prio);
}

static td_err_e (*real_td_thr_setsigpending)(const td_thrhandle_t*, unsigned char, const sigset_t*) = nullptr;

extern "C" td_err_e abii_td_thr_setsigpending(const td_thrhandle_t* th, unsigned char n, const sigset_t* ss)
{
    OVERRIDE_PREFIX(td_thr_setsigpending)
        pre_fmtd_str pi_str = "td_thr_setsigpending(__th, __n, __ss)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));
        abii_args->push_arg(new ArgPrinter(ss, "__ss"));

        auto abii_ret = real_td_thr_setsigpending(th, n, ss);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_setsigpending, abii_ret)
    return real_td_thr_setsigpending(th, n, ss);
}

static td_err_e (*real_td_thr_sigsetmask)(const td_thrhandle_t*, const sigset_t*) = nullptr;

extern "C" td_err_e abii_td_thr_sigsetmask(const td_thrhandle_t* th, const sigset_t* ss)
{
    OVERRIDE_PREFIX(td_thr_sigsetmask)
        pre_fmtd_str pi_str = "td_thr_sigsetmask(__th, __ss)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(ss, "__ss"));

        auto abii_ret = real_td_thr_sigsetmask(th, ss);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_sigsetmask, abii_ret)
    return real_td_thr_sigsetmask(th, ss);
}

static td_err_e (*real_td_thr_tsd)(const td_thrhandle_t*, thread_key_t, void**) = nullptr;

extern "C" td_err_e abii_td_thr_tsd(const td_thrhandle_t* th, const thread_key_t tk, void** data)
{
    OVERRIDE_PREFIX(td_thr_tsd)
        pre_fmtd_str pi_str = "td_thr_tsd(__th, __tk, __data)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));
        abii_args->push_arg(new ArgPrinter(tk, "__tk"));
        abii_args->push_arg(new ArgPrinter(data, "__data"));

        auto abii_ret = real_td_thr_tsd(th, tk, data);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_tsd, abii_ret)
    return real_td_thr_tsd(th, tk, data);
}

static td_err_e (*real_td_thr_dbsuspend)(const td_thrhandle_t*) = nullptr;

extern "C" td_err_e abii_td_thr_dbsuspend(const td_thrhandle_t* th)
{
    OVERRIDE_PREFIX(td_thr_dbsuspend)
        pre_fmtd_str pi_str = "td_thr_dbsuspend(__th)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));

        auto abii_ret = real_td_thr_dbsuspend(th);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_dbsuspend, abii_ret)
    return real_td_thr_dbsuspend(th);
}

static td_err_e (*real_td_thr_dbresume)(const td_thrhandle_t*) = nullptr;

extern "C" td_err_e abii_td_thr_dbresume(const td_thrhandle_t* th)
{
    OVERRIDE_PREFIX(td_thr_dbresume)
        pre_fmtd_str pi_str = "td_thr_dbresume(__th)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(th, "__th"));

        auto abii_ret = real_td_thr_dbresume(th);

        auto printer = new ArgPrinter(abii_ret, "return");
        printer->set_enum_printer(print_thread_db_td_err_e, abii_ret);
        abii_args->push_return(printer);
    OVERRIDE_SUFFIX(td_thr_dbresume, abii_ret)
    return real_td_thr_dbresume(th);
}
}
