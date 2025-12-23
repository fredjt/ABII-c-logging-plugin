//
// Created by Trent Tanchin on 7/3/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_AIO_H
#define ABII_C_LOGGING_PLUGIN_AIO_H

#include <aio.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map aio_status = {
    {0, "AIO_CANCELED"},
    {1, "AIO_NOTCANCELED"},
    {2, "AIO_ALLDONE"}
};

const defines_map aio_lio_opcode = {
    {0, "LIO_READ"},
    {1, "LIO_WRITE"},
    {2, "LIO_NOP"}
};

const defines_map aio_lio_wait = {
    {0, "LIO_WAIT"},
    {1, "LIO_NOWAIT"}
};

template <typename T>
std::string print_aio_status(const T v)
{
    return print_enum_entry(v, aio_status);
}

template <typename T>
std::string print_aio_lio_opcode(const T v)
{
    return print_enum_entry(v, aio_lio_opcode);
}

template <typename T>
std::string print_aio_lio_wait(const T v)
{
    return print_enum_entry(v, aio_lio_wait);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, aiocb>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.aio_fildes, "aio_fildes", &os));

    auto printer = ArgPrinter(obj.aio_lio_opcode, "aio_lio_opcode", &os);
    printer.set_enum_printer(print_aio_lio_opcode, obj.aio_lio_opcode);
    abii_args->push_arg(&printer);

    abii_args->push_arg(new ArgPrinter(obj.aio_reqprio, "aio_reqprio", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_buf, "aio_buf", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_nbytes, "aio_nbytes", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_sigevent, "aio_sigevent", &os));
    abii_args->push_arg(new ArgPrinter(obj.__next_prio, "__next_prio", &os));
    abii_args->push_arg(new ArgPrinter(obj.__abs_prio, "__abs_prio", &os));
    abii_args->push_arg(new ArgPrinter(obj.__policy, "__policy", &os));
    abii_args->push_arg(new ArgPrinter(obj.__error_code, "__error_code", &os));
    abii_args->push_arg(new ArgPrinter(obj.__return_value, "__return_value", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_offset, "aio_offset", &os));
#ifndef __USE_FILE_OFFSET64
    abii_args->push_arg(new ArgPrinter(obj.__pad, "__pad", &os));
#endif
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved, "__glibc_reserved", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#ifdef __USE_LARGEFILE64
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, aiocb64>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.aio_fildes, "aio_fildes", &os));

    auto printer = ArgPrinter(obj.aio_lio_opcode, "aio_lio_opcode", &os);
    printer.set_enum_printer(print_aio_lio_opcode, obj.aio_lio_opcode);
    abii_args->push_arg(&printer);

    abii_args->push_arg(new ArgPrinter(obj.aio_reqprio, "aio_reqprio", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_buf, "aio_buf", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_nbytes, "aio_nbytes", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_sigevent, "aio_sigevent", &os));
    abii_args->push_arg(new ArgPrinter(obj.__next_prio, "__next_prio", &os));
    abii_args->push_arg(new ArgPrinter(obj.__abs_prio, "__abs_prio", &os));
    abii_args->push_arg(new ArgPrinter(obj.__policy, "__policy", &os));
    abii_args->push_arg(new ArgPrinter(obj.__error_code, "__error_code", &os));
    abii_args->push_arg(new ArgPrinter(obj.__return_value, "__return_value", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_offset, "aio_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.__glibc_reserved, "__glibc_reserved", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, aioinit>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.aio_threads, "aio_threads", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_num, "aio_num", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_locks, "aio_locks", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_usedba, "aio_usedba", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_debug, "aio_debug", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_numusers, "aio_numusers", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_idle_time, "aio_idle_time", &os));
    abii_args->push_arg(new ArgPrinter(obj.aio_reserved, "aio_reserved", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}
#endif

#endif //ABII_C_LOGGING_PLUGIN_AIO_H
