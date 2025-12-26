//
// Created by Trent Tanchin on 9/28/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_GSHADOW_H
#define ABII_C_LOGGING_PLUGIN_GSHADOW_H

#include <gshadow.h>
#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sgrp>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.sg_namp, "sg_namp", &os));
    abii_args->push_arg(new ArgPrinter(obj.sg_passwd, "sg_passwd", &os));
    abii_args->push_arg(new ArgPrinter(obj.sg_adm, "sg_adm", &os));
    abii_args->push_arg(new ArgPrinter(obj.sg_mem, "sg_mem", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_GSHADOW_H
