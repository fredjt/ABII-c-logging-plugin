//
// Created by Trent Tanchin on 12/27/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_OBSTACK_H
#define ABII_C_LOGGING_PLUGIN_OBSTACK_H

#include <obstack.h>
#include <abii/libabii.h>

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, _obstack_chunk>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.limit, "limit", &os, PRINT_ENDL));
    abii_args->push_arg(new ArgPrinter(obj.prev, "prev", &os));
    abii_args->push_arg(new ArgPrinter(obj.contents, "contents", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

// TODO: Ensure these static_casts are not messing with any cv-qualifications.
template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, obstack>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.chunk_size, "chunk_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.chunk, "chunk", &os));
    abii_args->push_arg(new ArgPrinter(obj.object_base, "object_base", &os, PRINT_ENDL));
    abii_args->push_arg(new ArgPrinter(obj.next_free, "next_free", &os, PRINT_ENDL));
    abii_args->push_arg(new ArgPrinter(obj.chunk_limit, "chunk_limit", &os, PRINT_ENDL));
    abii_args->push_arg(new ArgPrinter(obj.temp, "temp", &os));
    abii_args->push_arg(new ArgPrinter(obj.alignment_mask, "alignment_mask", &os));
    abii_args->push_arg(new ArgPrinter(obj.chunkfun, "chunkfun", &os));
    abii_args->push_arg(new ArgPrinter(obj.freefun, "freefun", &os));
    abii_args->push_arg(new ArgPrinter(obj.extra_arg, "extra_arg", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.use_extra_arg), "use_extra_arg", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.maybe_empty_object), "maybe_empty_object", &os));
    abii_args->push_arg(new ArgPrinter(static_cast<unsigned>(obj.alloc_failed), "alloc_failed", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, typeof(obstack::temp)>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.tempint, "tempint", &os));
    abii_args->push_arg(new ArgPrinter(obj.tempptr, "tempptr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_OBSTACK_H
