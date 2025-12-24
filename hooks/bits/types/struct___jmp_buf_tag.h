//
// Created by Trent Tanchin on 5/23/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_STRUCT___JMP_BUF_TAG_H
#define ABII_C_LOGGING_PLUGIN_STRUCT___JMP_BUF_TAG_H

#include <bits/types/struct___jmp_buf_tag.h>

#include "__sigset_t.h"

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, __jmp_buf_tag>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.__jmpbuf, "__jmpbuf", &os));
    abii_args->push_arg(new ArgPrinter(obj.__mask_was_saved, "__mask_was_saved", &os));
    abii_args->push_arg(new ArgPrinter(obj.__saved_mask, "__saved_mask", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_STRUCT___JMP_BUF_TAG_H
