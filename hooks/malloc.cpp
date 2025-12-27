//
// Created by Trent Tanchin on 10/3/24.
//

#include "malloc.h"

namespace abii
{
static void* (*real_malloc)(size_t) __THROW = nullptr;

extern "C" __attribute_malloc__ __attribute_alloc_size__((1)) __wur
void* abii_malloc(size_t size) __THROW
{
    OVERRIDE_PREFIX(malloc)
        pre_fmtd_str str = "malloc(__size)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_malloc(size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(malloc, abii_ret)
    return real_malloc(size);
}

static void* (*real_calloc)(size_t, size_t) __THROW = nullptr;

extern "C" __attribute_malloc__ __attribute_alloc_size__((1, 2)) __wur
void* abii_calloc(size_t nmemb, size_t size) __THROW
{
    OVERRIDE_PREFIX(calloc)
        pre_fmtd_str str = "calloc(__nmemb, __size)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(nmemb, "__nmemb"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_calloc(nmemb, size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(calloc, abii_ret)
    return real_calloc(nmemb, size);
}

static void* (*real_realloc)(void*, size_t) __THROW = nullptr;

extern "C" __attribute_warn_unused_result__ __attribute_alloc_size__((2))
void* abii_realloc(void* ptr, size_t size) __THROW
{
    OVERRIDE_PREFIX(realloc)
        pre_fmtd_str str = "realloc(__ptr, __size)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_realloc(ptr, size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(realloc, abii_ret)
    return real_realloc(ptr, size);
}

static void* (*real_reallocarray)(void*, size_t, size_t) __THROW = nullptr;

extern "C" __attribute_warn_unused_result__ __attribute_alloc_size__((2, 3)) __attr_dealloc_free
void* abii_reallocarray(void* ptr, size_t nmemb, size_t size) __THROW
{
    OVERRIDE_PREFIX(reallocarray)
        pre_fmtd_str str = "reallocarray(__ptr, __nmemb, __size)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));
        abii_args->push_arg(new ArgPrinter(nmemb, "__nmemb"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_reallocarray(ptr, nmemb, size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(reallocarray, abii_ret)
    return real_reallocarray(ptr, nmemb, size);
}

static void (*real_free)(void*) __THROW = nullptr;

extern "C" void abii_free(void* ptr) __THROW
{
    OVERRIDE_PREFIX(free)
        pre_fmtd_str str = "free(__ptr)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));

        abii_args->print_args();
        abii_stream << std::endl;

        real_free(ptr);

        delete abii_args;
        ENABLE_OVERRIDES
        return;
    }
    if (real_free == nullptr)
    {
        real_free = reinterpret_cast<decltype(real_free)>(dlsym(RTLD_NEXT, "free"));
        if (real_free == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    return real_free(ptr);
}

static void* (*real_memalign)(size_t, size_t) __THROW = nullptr;

extern "C" __attribute_malloc__ __attribute_alloc_align__((1)) __attribute_alloc_size__((2)) __wur __attr_dealloc_free
void* abii_memalign(size_t alignment, size_t size) __THROW
{
    OVERRIDE_PREFIX(memalign)
        pre_fmtd_str str = "memalign(__alignment, __size)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(alignment, "__alignment"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_memalign(alignment, size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(memalign, abii_ret)
    return real_memalign(alignment, size);
}

static void* (*real_valloc)(size_t) __THROW = nullptr;

extern "C" __attribute_malloc__ __attribute_alloc_size__((1)) __wur __attr_dealloc_free
void* abii_valloc(size_t size) __THROW
{
    OVERRIDE_PREFIX(valloc)
        pre_fmtd_str str = "valloc(__size)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_valloc(size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(valloc, abii_ret)
    return real_valloc(size);
}

static void* (*real_pvalloc)(size_t) __THROW = nullptr;

extern "C" __attribute_malloc__ __wur __attr_dealloc_free
void* abii_pvalloc(size_t size) __THROW
{
    OVERRIDE_PREFIX(pvalloc)
        pre_fmtd_str str = "pvalloc(__size)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(size, "__size"));

        auto abii_ret = real_pvalloc(size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(pvalloc, abii_ret)
    return real_pvalloc(size);
}

static struct mallinfo (*real_mallinfo)() __THROW = nullptr;

extern "C" __MALLOC_DEPRECATED
struct mallinfo abii_mallinfo() __THROW
{
    OVERRIDE_PREFIX(mallinfo)
        pre_fmtd_str str = "mallinfo()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real_mallinfo();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mallinfo, abii_ret)
    return real_mallinfo();
}

static struct mallinfo2 (*real_mallinfo2)() __THROW = nullptr;

extern "C" struct mallinfo2 abii_mallinfo2() __THROW
{
    OVERRIDE_PREFIX(mallinfo2)
        pre_fmtd_str str = "mallinfo2()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real_mallinfo2();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mallinfo2, abii_ret)
    return real_mallinfo2();
}

static int (*real_mallopt)(int, int) __THROW = nullptr;

extern "C" int abii_mallopt(int param, int val) __THROW
{
    OVERRIDE_PREFIX(mallopt)
        pre_fmtd_str str = "mallopt(__param, __val)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(param, "__param");
        printer->set_enum_printer(print_malloc_mallopt, param);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(val, "__val"));

        auto abii_ret = real_mallopt(param, val);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(mallopt, abii_ret)
    return real_mallopt(param, val);
}

static int (*real_malloc_trim)(size_t) __THROW = nullptr;

extern "C" int abii_malloc_trim(size_t pad) __THROW
{
    OVERRIDE_PREFIX(malloc_trim)
        pre_fmtd_str str = "malloc_trim(__pad)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(pad, "__pad"));

        auto abii_ret = real_malloc_trim(pad);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(malloc_trim, abii_ret)
    return real_malloc_trim(pad);
}

static size_t (*real_malloc_usable_size)(void*) __THROW = nullptr;

extern "C" size_t abii_malloc_usable_size(void* ptr) __THROW
{
    OVERRIDE_PREFIX(malloc_usable_size)
        pre_fmtd_str str = "malloc_usable_size(__ptr)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ptr, "__ptr"));

        auto abii_ret = real_malloc_usable_size(ptr);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(malloc_usable_size, abii_ret)
    return real_malloc_usable_size(ptr);
}

static void (*real_malloc_stats)() __THROW = nullptr;

extern "C" void abii_malloc_stats() __THROW
{
    OVERRIDE_PREFIX(malloc_stats)
        pre_fmtd_str str = "malloc_stats()";
        abii_args->push_func(new ArgPrinter(str));

        real_malloc_stats();
    OVERRIDE_SUFFIX(malloc_stats,)
    return real_malloc_stats();
}

static int (*real_malloc_info)(int, FILE*) __THROW = nullptr;

extern "C" int abii_malloc_info(int options, FILE* fp) __THROW
{
    OVERRIDE_PREFIX(malloc_info)
        pre_fmtd_str str = "malloc_info(__options, __fp)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(options, "__options"));
        abii_args->push_arg(new ArgPrinter(fp, "__fp"));

        auto abii_ret = real_malloc_info(options, fp);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(malloc_info, abii_ret)
    return real_malloc_info(options, fp);
}
}
