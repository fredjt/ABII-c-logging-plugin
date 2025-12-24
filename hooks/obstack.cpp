//
// Created by Trent Tanchin on 12/27/24.
//

#include "obstack.h"

namespace abii
{
static void (*real__obstack_newchunk)(obstack*, int) = nullptr;

extern "C" void abii__obstack_newchunk(obstack* h, int length)
{
    OVERRIDE_PREFIX(_obstack_newchunk)
        pre_fmtd_str pi_str = "_obstack_newchunk(h, length)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(h, "h"));
        abii_args->push_arg(new ArgPrinter(length, "length"));

        real__obstack_newchunk(h, length);
    OVERRIDE_SUFFIX(_obstack_newchunk,)
    return real__obstack_newchunk(h, length);
}

static int (*real__obstack_begin)(obstack*, int, int, void*(*)(long), void (*)(void*)) = nullptr;

extern "C" int abii__obstack_begin(obstack* h, int size, int alignment, void*(*chunkfun)(long), void (*freefun)(void*))
{
    OVERRIDE_PREFIX(_obstack_begin)
        pre_fmtd_str pi_str = "_obstack_begin(h, size, alignment, chunkfun, freefun)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(h, "h"));
        abii_args->push_arg(new ArgPrinter(size, "size"));
        abii_args->push_arg(new ArgPrinter(alignment, "alignment"));
        abii_args->push_arg(new ArgPrinter(chunkfun, "chunkfun"));
        abii_args->push_arg(new ArgPrinter(freefun, "freefun"));

        auto pi_ret = real__obstack_begin(h, size, alignment, chunkfun, freefun);

        abii_args->push_return(new ArgPrinter(pi_ret, "return"));
    OVERRIDE_SUFFIX(_obstack_begin, pi_ret)
    return real__obstack_begin(h, size, alignment, chunkfun, freefun);
}

static int (*real__obstack_begin_1)(obstack*, int, int, void*(*)(void*, long), void (*)(void*, void*), void*) = nullptr;

extern "C" int abii__obstack_begin_1(obstack* h, int size, int alignment, void*(*chunkfun)(void*, long),
                                     void (*freefun)(void*, void*), void* arg)
{
    OVERRIDE_PREFIX(_obstack_begin_1)
        pre_fmtd_str pi_str = "_obstack_begin_1(h, size, alignment, chunkfun, freefun, arg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(h, "h"));
        abii_args->push_arg(new ArgPrinter(size, "size"));
        abii_args->push_arg(new ArgPrinter(alignment, "alignment"));
        abii_args->push_arg(new ArgPrinter(chunkfun, "chunkfun"));
        abii_args->push_arg(new ArgPrinter(freefun, "freefun"));
        abii_args->push_arg(new ArgPrinter(arg, "arg"));

        auto pi_ret = real__obstack_begin_1(h, size, alignment, chunkfun, freefun, arg);

        abii_args->push_return(new ArgPrinter(pi_ret, "return"));
    OVERRIDE_SUFFIX(_obstack_begin_1, pi_ret)
    return real__obstack_begin_1(h, size, alignment, chunkfun, freefun, arg);
}

static int (*real__obstack_memory_used)(obstack*) = nullptr;

extern "C" __attribute_pure__
int abii__obstack_memory_used(obstack* h)
{
    OVERRIDE_PREFIX(_obstack_memory_used)
        pre_fmtd_str pi_str = "_obstack_memory_used(h)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(h, "h"));

        auto pi_ret = real__obstack_memory_used(h);

        abii_args->push_return(new ArgPrinter(pi_ret, "return"));
    OVERRIDE_SUFFIX(_obstack_memory_used, pi_ret)
    return real__obstack_memory_used(h);
}

static void (*real_obstack_free)(obstack*, void*) = nullptr;

extern "C" void abii_obstack_free(obstack* h, void* obj)
{
    OVERRIDE_PREFIX(obstack_free)
        pre_fmtd_str pi_str = "obstack_free(h, obj)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(h, "h"));
        abii_args->push_arg(new ArgPrinter(obj, "obj"));

        real_obstack_free(h, obj);
    OVERRIDE_SUFFIX(obstack_free,)
    return real_obstack_free(h, obj);
}
}
