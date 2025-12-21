//
// Created by Trent Tanchin on 3/8/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_STRUCT_RWLOCK_H
#define ABII_C_LOGGING_PLUGIN_STRUCT_RWLOCK_H

#include <bits/struct_rwlock.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __pthread_rwlock_arch_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__readers, "__readers", &os));
    abii_args->push_arg(new ArgPrinter(obj.__writers, "__writers", &os));
    abii_args->push_arg(new ArgPrinter(obj.__wrphase_futex, "__wrphase_futex", &os));
    abii_args->push_arg(new ArgPrinter(obj.__writers_futex, "__writers_futex", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad3, "__pad3", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad4, "__pad4", &os));
#ifdef __x86_64__
    abii_args->push_arg(new ArgPrinter(obj.__cur_writer, "__cur_writer", &os));
    abii_args->push_arg(new ArgPrinter(obj.__shared, "__shared", &os));
    abii_args->push_arg(new ArgPrinter(obj.__rwelision, "__rwelision", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad1, "__pad1", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad2, "__pad2", &os));

    auto printer = new ArgPrinter(obj.__flags, "__flags", &os, RECURSE);
    printer->set_enum_printer(print_pthread_rwlock_type, obj.__flags);
    abii_args->push_arg(printer);
#else
    auto printer = new ArgPrinter(obj.__flags, "__flags", &os, RECURSE);
    printer->set_enum_printer(print_pthread_rwlock_type, obj.__flags);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.__shared, "__shared", &os));
    abii_args->push_arg(new ArgPrinter(obj.__rwelision, "__rwelision", &os));
    abii_args->push_arg(new ArgPrinter(obj.__pad2, "__pad2", &os));
    abii_args->push_arg(new ArgPrinter(obj.__cur_writer, "__cur_writer", &os, RECURSE));
#endif
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_STRUCT_RWLOCK_H
