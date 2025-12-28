//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_SGTTY_H
#define ABII_C_LOGGING_PLUGIN_SGTTY_H

#include <abii/libabii.h>

using namespace abii;

struct sgttyb {};

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, sgttyb>
std::ostream& operator<<(std::ostream& os, T&& /*obj*/)
{
    OVERRIDE_STREAM_PREFIX
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_SGTTY_H
