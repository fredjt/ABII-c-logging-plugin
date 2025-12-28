//
// Created by Trent Tanchin on 5/23/25.
//

#include <setjmp.h>
#include <abii/libabii.h>

#include "bits/types/struct___jmp_buf_tag.h"

namespace abii
{
static int (*real_setjmp)(jmp_buf) __THROWNL = nullptr;

extern "C" int abii_setjmp(jmp_buf env) __THROWNL
{
    OVERRIDE_PREFIX(setjmp)
        pre_fmtd_str pi_str = "setjmp(__env)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(env, "__env"));

        auto abii_ret = real_setjmp(env);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setjmp, abii_ret)
    return real_setjmp(env);
}

static int (*real___sigsetjmp)(__jmp_buf_tag [1], int) __THROWNL = nullptr;

extern "C" int abii___sigsetjmp(__jmp_buf_tag env[1], int savemask) __THROWNL
{
    OVERRIDE_PREFIX(__sigsetjmp)
        pre_fmtd_str pi_str = "__sigsetjmp(__env, __savemask)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(env, "__env"));
        abii_args->push_arg(new ArgPrinter(savemask, "__savemask"));

        auto abii_ret = real___sigsetjmp(env, savemask);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__sigsetjmp, abii_ret)
    return real___sigsetjmp(env, savemask);
}

static int (*real__setjmp)(__jmp_buf_tag [1]) __THROWNL = nullptr;

extern "C" int abii__setjmp(__jmp_buf_tag env[1]) __THROWNL
{
    OVERRIDE_PREFIX(_setjmp)
        pre_fmtd_str pi_str = "_setjmp(__env)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(env, "__env"));

        auto abii_ret = real__setjmp(env);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(_setjmp, abii_ret)
    return real__setjmp(env);
}

static void (*real_longjmp)(__jmp_buf_tag [1], int) __THROWNL = nullptr;

extern "C" __attribute__ ((__noreturn__))
void abii_longjmp(__jmp_buf_tag env[1], int val) __THROWNL
{
    OVERRIDE_PREFIX(longjmp)
        pre_fmtd_str pi_str = "longjmp(__env, __val)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(env, "__env"));
        abii_args->push_arg(new ArgPrinter(val, "__val"));

        abii_args->print_args();
        abii_stream << std::endl;

        real_longjmp(env, val);
    }
    if (real_longjmp == nullptr)
    {
        real_longjmp = reinterpret_cast<decltype(real_longjmp)>(dlsym(RTLD_NEXT, "longjmp"));
        if (real_longjmp == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real_longjmp(env, val);
}

static void (*real__longjmp)(__jmp_buf_tag [1], int) __THROWNL = nullptr;

extern "C" __attribute__ ((__noreturn__))
void abii__longjmp(__jmp_buf_tag env[1], int val) __THROWNL
{
    OVERRIDE_PREFIX(_longjmp)
        pre_fmtd_str pi_str = "_longjmp(__env, __val)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(env, "__env"));
        abii_args->push_arg(new ArgPrinter(val, "__val"));

        abii_args->print_args();
        abii_stream << std::endl;

        real__longjmp(env, val);
    }
    if (real__longjmp == nullptr)
    {
        real__longjmp = reinterpret_cast<decltype(real__longjmp)>(dlsym(RTLD_NEXT, __func__));
        if (real__longjmp == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real__longjmp(env, val);
}

static decltype(siglongjmp)* real_siglongjmp = nullptr;

extern "C" __attribute__ ((__noreturn__))
void abii_siglongjmp(sigjmp_buf env, int val) __THROWNL
{
    OVERRIDE_PREFIX(siglongjmp)
        pre_fmtd_str pi_str = "siglongjmp(__env, __val)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(env, "__env"));
        abii_args->push_arg(new ArgPrinter(val, "__val"));

        abii_args->print_args();
        abii_stream << std::endl;

        real_siglongjmp(env, val);
    }
    if (real_siglongjmp == nullptr)
    {
        real_siglongjmp = reinterpret_cast<decltype(real_siglongjmp)>(dlsym(RTLD_NEXT, __func__));
        if (real_siglongjmp == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    real_siglongjmp(env, val);
}
}
