//
// Created by Trent Tanchin on 7/4/26.
//

#include "sys/ucontext.h"

#include <cinttypes>
#include <ucontext.h>
#include <abii/libabii.h>

#include "custom_printers.h"

namespace abii
{
static int (*real_getcontext)(ucontext_t*) __THROWNL = nullptr;

extern "C" int abii_getcontext(ucontext_t* ucp) __THROWNL
{
    OVERRIDE_PREFIX(getcontext)
        pre_fmtd_str pi_str = "getcontext(__ucp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ucp, "__ucp"));

        auto abii_ret = real_getcontext(ucp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getcontext, abii_ret)
    return real_getcontext(ucp);
}

static int (*real_setcontext)(const ucontext_t*) __THROWNL = nullptr;

extern "C" int abii_setcontext(const ucontext_t* ucp) __THROWNL
{
    OVERRIDE_PREFIX(setcontext)
        pre_fmtd_str pi_str = "setcontext(__ucp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ucp, "__ucp"));

        auto abii_ret = real_setcontext(ucp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(setcontext, abii_ret)
    return real_setcontext(ucp);
}

static __INDIRECT_RETURN int (*real_swapcontext)(ucontext_t*, const ucontext_t*) __THROWNL = nullptr;

extern "C" __INDIRECT_RETURN
int abii_swapcontext(ucontext_t* oucp, const ucontext_t* ucp) __THROWNL

{
    OVERRIDE_PREFIX(swapcontext)
        pre_fmtd_str pi_str = "swapcontext(__oucp, __ucp)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(oucp, "__oucp"));
        abii_args->push_arg(new ArgPrinter(ucp, "__ucp"));

        auto abii_ret = real_swapcontext(oucp, ucp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(swapcontext, abii_ret)
    return real_swapcontext(oucp, ucp);
}

static void (*real_makecontext)(ucontext_t*, void (*)(), int, ...) __THROWNL = nullptr;

extern "C" void abii_makecontext(ucontext_t* ucp, void (*func)(), int argc, ...) __THROW

{
    OVERRIDE_VARIADIC_PREFIX(makecontext,)
        pre_fmtd_str pi_str = "makecontext(__ucp, __func, __argc, ...)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(ucp, "__ucp"));
        abii_args->push_arg(new ArgPrinter(func, "__func"));
        abii_args->push_arg(new ArgPrinter(argc, "__argc"));

        std::stringstream ss;
        for (auto i = 1; i < argc; i++)
            ss << "%" << PRIuPTR;
        PUSH_VARIADIC_ARGS(printer, ss.str(), print_variadic_args_printf)

        __builtin_apply(reinterpret_cast<void (*)(...)>(real_makecontext), abii_bi_vargs, 1000);

        va_start(abii_vargs, ss.str());
        abii_args->print_args();
        va_end(abii_vargs);
        delete abii_args;
        abii_stream << std::endl;
        ENABLE_OVERRIDES
    }
    if (real_makecontext == nullptr)
    {
        real_makecontext = reinterpret_cast<decltype(real_makecontext)>(dlsym(RTLD_NEXT, "makecontext"));
        if (real_makecontext == nullptr) std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    const auto abii_bi_vargs = __builtin_apply_args();
    __builtin_apply(reinterpret_cast<void (*)(...)>(real_makecontext), abii_bi_vargs, 1000);
}
}
