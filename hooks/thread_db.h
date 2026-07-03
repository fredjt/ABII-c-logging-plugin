//
// Created by Trent Tanchin on 7/3/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_THREAD_DB_H
#define ABII_C_LOGGING_PLUGIN_THREAD_DB_H

#include <thread_db.h>
#include <abii/libabii.h>

#include "asm/unistd_64.h"

namespace abii
{
const defines_map thread_db_td_err_e = {
    {0, "TD_OK"},
    {1, "TD_ERR"},
    {2, "TD_NOTHR"},
    {3, "TD_NOSV"},
    {4, "TD_NOLWP"},
    {5, "TD_BADPH"},
    {6, "TD_BADTH"},
    {7, "TD_BADSH"},
    {8, "TD_BADTA"},
    {9, "TD_BADKEY"},
    {10, "TD_NOMSG"},
    {11, "TD_NOFPREGS"},
    {12, "TD_NOLIBTHREAD"},
    {13, "TD_NOEVENT"},
    {14, "TD_NOCAPAB"},
    {15, "TD_DBERR"},
    {16, "TD_NOAPLIC"},
    {17, "TD_NOTSD"},
    {18, "TD_MALLOC"},
    {19, "TD_PARTIALREG"},
    {20, "TD_NOXREGS"},
    {21, "TD_TLSDEFER"},
    {21, "TD_NOTALLOC"},
    {22, "TD_VERSION"},
    {23, "TD_NOTLS"}
};

const defines_map thread_db_td_thr_state_e = {
    {0, "TD_THR_ANY_STATE"},
    {1, "TD_THR_UNKNOWN"},
    {2, "TD_THR_STOPPED"},
    {3, "TD_THR_RUN"},
    {4, "TD_THR_ACTIVE"},
    {5, "TD_THR_ZOMBIE"},
    {6, "TD_THR_SLEEP"},
    {7, "TD_THR_STOPPED_ASLEEP"}
};

const defines_map thread_db_td_thr_type_e = {
    {0, "TD_THR_ANY_TYPE"},
    {1, "TD_THR_USER"},
    {2, "TD_THR_SYSTEM"}
};

const defines_map thread_db_td_ta_thr_iter_flags = {
    {0xffffffff, "TD_THR_ANY_USER_FLAGS"},
    {-20, "TD_THR_LOWEST_PRIORITY"},
    {__null, "TD_SIGNO_MASK"}
};

const defines_map thread_db_td_eventsize = {
    {2, "TD_EVENTSIZE"}
};

const defines_map thread_db_bt_uishift = {
    {5, "BT_UISHIFT"}
};

const defines_map thread_db_bt_nbipui = {
    {(1 << 5), "BT_NBIPUI"}
};

const defines_map thread_db_bt_uimask = {
    {((1 << 5) - 1), "BT_UIMASK"}
};

const defines_map thread_db_td_event_e = {
    {0, "TD_ALL_EVENTS"},
    {0, "TD_EVENT_NONE"},
    {1, "TD_READY"},
    {2, "TD_SLEEP"},
    {3, "TD_SWITCHTO"},
    {4, "TD_SWITCHFROM"},
    {5, "TD_LOCK_TRY"},
    {6, "TD_CATCHSIG"},
    {7, "TD_IDLE"},
    {8, "TD_CREATE"},
    {9, "TD_DEATH"},
    {10, "TD_PREEMPT"},
    {11, "TD_PRI_INHERIT"},
    {12, "TD_REAP"},
    {13, "TD_CONCURRENCY"},
    {14, "TD_TIMEOUT"},
    {1, "TD_MIN_EVENT_NUM"},
    {14, "TD_MAX_EVENT_NUM"},
    {31, "TD_EVENTS_ENABLE"}
};

const defines_map thread_td_notify_e = {
    {0, "NOTIFY_BPT"},
    {1, "NOTIFY_AUTOBPT"},
    {2, "NOTIFY_SYSCALL"}
};

template <typename T>
std::string print_thread_db_td_err_e(const T v)
{
    return print_enum_entry(v, thread_db_td_err_e);
}

template <typename T>
std::string print_thread_db_td_thr_state_e(const T v)
{
    return print_enum_entry(v, thread_db_td_thr_state_e);
}

template <typename T>
std::string print_thread_db_td_thr_type_e(const T v)
{
    return print_enum_entry(v, thread_db_td_thr_type_e);
}

template <typename T>
std::string print_thread_db_td_ta_thr_iter_flags(const T v)
{
    return print_or_enum_entries(v, thread_db_td_ta_thr_iter_flags);
}

template <typename T>
std::string print_thread_db_td_eventsize(const T v)
{
    return print_enum_entry(v, thread_db_td_eventsize);
}

template <typename T>
std::string print_thread_db_bt_uishift(const T v)
{
    return print_enum_entry(v, thread_db_bt_uishift);
}

template <typename T>
std::string print_thread_db_bt_nbipui(const T v)
{
    return print_enum_entry(v, thread_db_bt_nbipui);
}

template <typename T>
std::string print_thread_db_bt_uimask(const T v)
{
    return print_enum_entry(v, thread_db_bt_uimask);
}

template <typename T>
std::string print_thread_db_td_event_e(const T v)
{
    return print_enum_entry(v, thread_db_td_event_e);
}

template <typename T>
std::string print_thread_db_td_notify_e(const T v)
{
    return print_enum_entry(v, thread_td_notify_e);
}
}

using namespace abii;

struct td_thragent {};

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, td_thragent_t>
std::ostream& operator<<(std::ostream& os, T&& /*obj*/)
{
    OVERRIDE_STREAM_PREFIX
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, td_thrhandle_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.th_ta_p, "th_ta_p", &os));
    abii_args->push_arg(new ArgPrinter(obj.th_unique, "th_unique", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, td_thr_events_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.event_bits, "th_unique", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, td_notify_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.type, "type", &os);
    printer->set_enum_printer(print_thread_db_td_notify_e, obj.type);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.u, "u", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(td_notify_t::u)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.bptaddr, "bptaddr", &os));

    auto printer = new ArgPrinter(obj.syscallno, "syscallno", &os, RECURSE);
    printer->set_enum_printer(print_unistd_64_syscall_no, obj.syscallno);
    abii_args->push_arg(printer);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, td_event_msg_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.event, "event", &os);
    printer->set_enum_printer(print_thread_db_td_event_e, obj.event);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.th_p, "th_p", &os));
    abii_args->push_arg(new ArgPrinter(obj.msg, "msg", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, decltype(td_event_msg_t::msg)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.data, "data", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, td_eventbuf_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.eventmask, "eventmask", &os));

    auto printer = new ArgPrinter(obj.eventnum, "event", &os);
    printer->set_enum_printer(print_thread_db_td_event_e, obj.eventnum);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.eventdata, "eventdata", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, td_ta_stats_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.nthreads, "nthreads", &os));
    abii_args->push_arg(new ArgPrinter(obj.r_concurrency, "r_concurrency", &os));
    abii_args->push_arg(new ArgPrinter(obj.nrunnable_num, "nrunnable_num", &os));
    abii_args->push_arg(new ArgPrinter(obj.nrunnable_den, "nrunnable_den", &os));
    abii_args->push_arg(new ArgPrinter(obj.a_concurrency_num, "a_concurrency_num", &os));
    abii_args->push_arg(new ArgPrinter(obj.a_concurrency_den, "a_concurrency_den", &os));
    abii_args->push_arg(new ArgPrinter(obj.nlwps_num, "nlwps_num", &os));
    abii_args->push_arg(new ArgPrinter(obj.nlwps_den, "nlwps_den", &os));
    abii_args->push_arg(new ArgPrinter(obj.nidle_num, "nidle_num", &os));
    abii_args->push_arg(new ArgPrinter(obj.nidle_den, "nidle_den", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

struct ps_prochandle {};

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, ps_prochandle>
std::ostream& operator<<(std::ostream& os, T&& /*obj*/)
{
    OVERRIDE_STREAM_PREFIX
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, td_thrinfo_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ti_ta_p, "ti_ta_p", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_user_flags, "ti_user_flags", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_tid, "ti_tid", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_tls, "ti_tls", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_startfunc, "ti_startfunc", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_stkbase, "ti_stkbase", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_stksize, "ti_stksize", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_ro_area, "ti_ro_area", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_ro_size, "ti_ro_size", &os));

    auto printer = new ArgPrinter(obj.ti_state, "ti_state", &os);
    printer->set_enum_printer(print_thread_db_td_thr_state_e, obj.ti_state);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.ti_db_suspended, "ti_db_suspended", &os));

    auto printer1 = new ArgPrinter(obj.ti_type, "ti_type", &os);
    printer1->set_enum_printer(print_thread_db_td_thr_type_e, obj.ti_type);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.ti_pc, "ti_pc", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_sp, "ti_sp", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_flags, "ti_flags", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_pri, "ti_pri", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_lid, "ti_lid", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_sigmask, "ti_sigmask", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_traceme, "ti_traceme", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_preemptflag, "ti_preemptflag", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_pirecflag, "ti_pirecflag", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_pending, "ti_pending", &os));
    abii_args->push_arg(new ArgPrinter(obj.ti_events, "ti_events", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_THREAD_DB_H
