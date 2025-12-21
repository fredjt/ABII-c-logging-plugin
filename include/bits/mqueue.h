//
// Created by Trent Tanchin on 10/6/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_MQUEUE_H
#define ABII_C_LOGGING_PLUGIN_MQUEUE_H

#include <abii/libabii.h>
#include <bits/mqueue.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, mq_attr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.mq_flags, "mq_flags", &os));
    abii_args->push_arg(new ArgPrinter(obj.mq_maxmsg, "mq_maxmsg", &os));
    abii_args->push_arg(new ArgPrinter(obj.mq_msgsize, "mq_msgsize", &os));
    abii_args->push_arg(new ArgPrinter(obj.mq_curmsgs, "mq_curmsgs", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad, "__pad", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_MQUEUE_H
