//
// Created by Trent Tanchin on 11/12/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_BITS_TYPES_STRUCT_IOVEC_H
#define ABII_C_LOGGING_PLUGIN_BITS_TYPES_STRUCT_IOVEC_H

#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, iovec>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.iov_base, "iov_base", &os);
    printer->set_len(obj.iov_len);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.iov_len, "iov_len", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_BITS_TYPES_STRUCT_IOVEC_H
