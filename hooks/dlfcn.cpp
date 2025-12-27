//
// Created by Trent Tanchin on 7/26/24.
//

#include "dlfcn.h"

#include "link.h"

namespace abii
{
static void* (*real_dlopen)(const char*, int) __THROWNL = nullptr;

extern "C" void* abii_dlopen(const char* file, int mode) __THROWNL
{
    OVERRIDE_PREFIX(dlopen)
        pre_fmtd_str str = "dlopen(__file, __mode)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(mode, "__mode"));

        auto abii_ret = real_dlopen(file, mode);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dlopen, abii_ret)
    return real_dlopen(file, mode);
}

static int (*real_dlclose)(void*) __THROWNL = nullptr;

extern "C" __nonnull((1))
int abii_dlclose(void* handle) __THROWNL
{
    OVERRIDE_PREFIX(dlclose)
        pre_fmtd_str str = "dlclose(__handle)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(handle, "__handle"));

        auto abii_ret = real_dlclose(handle);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dlclose, abii_ret)
    return real_dlclose(handle);
}

static void* (*real_dlsym)(void*, const char*) __THROW = nullptr;

extern "C" __nonnull((2))
void* abii_dlsym(void* handle, const char* name) __THROW
{
    if (redirect)
    {
        DISABLE_OVERRIDES
        TRACE_LOGGER
        if (real_dlsym == nullptr)
        {
            real_dlsym = reinterpret_cast<decltype(real_dlsym)>(dlvsym(RTLD_NEXT, "dlsym", "GLIBC_2.34"));
            if (real_dlsym == nullptr)
                std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
        }
        prefix = "";
        const auto abii_args = new ArgsPrinter();

        pre_fmtd_str str = "dlsym(__handle, __name)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(handle, "__handle");
        printer->set_enum_printer(print_dlfcn_rtld, handle);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_dlsym(handle, name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));

        abii_args->print_args();
        delete abii_args;
        abii_stream << std::endl;
        ENABLE_OVERRIDES
        return abii_ret;
    }
    if (real_dlsym == nullptr)
    {
        real_dlsym = reinterpret_cast<decltype(real_dlsym)>(dlvsym(RTLD_NEXT, "dlsym", "GLIBC_2.34"));
        if (real_dlsym == nullptr)
            std::cerr << "Error in `dlsym`: " << dlerror() << std::endl;
    }
    return real_dlsym(handle, name);
}

static void* (*real_dlmopen)(Lmid_t, const char*, int) __THROWNL = nullptr;

extern "C" void* abii_dlmopen(Lmid_t nsid, const char* file, int mode) __THROWNL
{
    OVERRIDE_PREFIX(dlmopen)
        pre_fmtd_str str = "dlmopen(__nsid, __file, __mode)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(nsid, "__nsid");
        printer->set_enum_printer(print_dlfcn_lm_id, nsid);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(file, "__file"));
        abii_args->push_arg(new ArgPrinter(mode, "__mode"));

        auto abii_ret = real_dlmopen(nsid, file, mode);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dlmopen, abii_ret)
    return real_dlmopen(nsid, file, mode);
}

static void* (*real_dlvsym)(void*, const char*, const char*) __THROW = nullptr;

// TODO: This doesn't seem to always work
extern "C" __nonnull((2, 3))
void* abii_dlvsym(void* handle, const char* name, const char* version) __THROW
{
    OVERRIDE_PREFIX(dlvsym)
        pre_fmtd_str str = "dlvsym(__handle, __name, __version)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(handle, "__handle");
        printer->set_enum_printer(print_dlfcn_rtld, handle);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(version, "__version"));

        auto abii_ret = real_dlvsym(handle, name, version);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dlvsym, abii_ret)
    return real_dlvsym(handle, name, version);
}

static char* (*real_dlerror)() __THROW = nullptr;

extern "C" char* abii_dlerror() __THROW
{
    if (redirect)
    {
        DISABLE_OVERRIDES
        TRACE_LOGGER
        prefix = "";
        if (real_dlerror == nullptr)
        {
            real_dlerror = reinterpret_cast<decltype(real_dlerror)>(dlsym(RTLD_NEXT, "dlerror"));
            if (real_dlerror == nullptr)
                // dlerror cannot be used here due to recursion
                std::cerr << "Error in `dlsym`" << std::endl;
        }
        const auto abii_args = new ArgsPrinter();

        pre_fmtd_str str = "dlerror()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real_dlerror();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
        abii_args->print_args();
        abii_stream << std::endl;
        ENABLE_OVERRIDES
        return abii_ret;
    }
    if (real_dlerror == nullptr)
    {
        real_dlerror = reinterpret_cast<decltype(real_dlerror)>(dlsym(RTLD_NEXT, "dlerror"));
        if (real_dlerror == nullptr)
            // dlerror cannot be used here due to recursion
            std::cerr << "Error in `dlsym`" << std::endl;
    }
    return real_dlerror();
}

static int (*real_dladdr)(const void*, Dl_info*) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_dladdr(const void* address, Dl_info* info) __THROW
{
    OVERRIDE_PREFIX(dladdr)
        pre_fmtd_str str = "dladdr(__address, __info)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(address, "__address"));
        abii_args->push_arg(new ArgPrinter(info, "__info"));

        auto abii_ret = real_dladdr(address, info);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dladdr, abii_ret)
    return real_dladdr(address, info);
}

static int (*real_dladdr1)(const void*, Dl_info*, void**, int) __THROW = nullptr;

extern "C" __nonnull((2))
int abii_dladdr1(const void* address, Dl_info* info, void** extra_info, int flags) __THROW
{
    OVERRIDE_PREFIX(dladdr1)
        pre_fmtd_str str = "dladdr1(__address, __info, __extra_info, __flags)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(address, "__address"));
        abii_args->push_arg(new ArgPrinter(info, "__info"));

        if (flags == RTLD_DL_SYMENT)
        {
            auto extra_info_sym = reinterpret_cast<const ElfW(Sym)**>(const_cast<const void**>(extra_info));
            abii_args->push_arg(new ArgPrinter(extra_info_sym, "__extra_info"));
        }
        else if (flags == RTLD_DL_LINKMAP)
        {
            auto extra_info_lm = reinterpret_cast<struct link_map**>(extra_info);
            abii_args->push_arg(new ArgPrinter(extra_info_lm, "__extra_info"));
        }
        else
            abii_args->push_arg(new ArgPrinter(extra_info, "__extra_info"));

        auto printer = new ArgPrinter(flags, "__flags");
        printer->set_enum_printer(print_dlfcn_rtld_dl, flags);
        abii_args->push_arg(printer);

        auto abii_ret = real_dladdr1(address, info, extra_info, flags);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dladdr1, abii_ret)
    return real_dladdr1(address, info, extra_info, flags);
}

static int (*real_dlinfo)(void*, int, void*) __THROW = nullptr;

extern "C" __nonnull((1, 3))
int abii_dlinfo(void* handle, int request, void* arg) __THROW
{
    OVERRIDE_PREFIX(dlinfo)
        pre_fmtd_str str = "dlinfo(__handle, __request, __arg)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(handle, "__handle"));

        auto printer = new ArgPrinter(request, "__request");
        printer->set_enum_printer(print_dlfcn_rtld_di, request);
        abii_args->push_arg(printer);

        if (request == RTLD_DI_LMID)
        {
            auto arg_f = static_cast<Lmid_t*>(arg);
            auto printer1 = new ArgPrinter(arg_f, "__arg");
            printer1->set_enum_printer_with_depth(print_dlfcn_lm_id, *arg_f, 1);
            abii_args->push_arg(printer1);
        }
        else if (request == RTLD_DI_LINKMAP)
        {
            auto arg_f = static_cast<struct link_map**>(arg);
            abii_args->push_arg(new ArgPrinter(arg_f, "__arg"));
        }
        else if (request == RTLD_DI_SERINFO || request == RTLD_DI_SERINFOSIZE)
        {
            auto arg_f = static_cast<Dl_serinfo*>(arg);
            abii_args->push_arg(new ArgPrinter(arg_f, "__arg"));
        }
        else if (request == RTLD_DI_ORIGIN)
        {
            auto arg_f = static_cast<char*>(arg);
            abii_args->push_arg(new ArgPrinter(arg_f, "__arg"));
        }
        else if (request == RTLD_DI_TLS_MODID)
        {
            auto arg_f = static_cast<size_t*>(arg);
            abii_args->push_arg(new ArgPrinter(arg_f, "__arg"));
        }
        else if (request == RTLD_DI_TLS_DATA)
        {
            auto arg_f = static_cast<void**>(arg);
            abii_args->push_arg(new ArgPrinter(arg_f, "__arg"));
        }
        else if (request == RTLD_DI_PHDR)
        {
            auto arg_f = static_cast<const ElfW(Phdr)**>(arg);
            abii_args->push_arg(new ArgPrinter(arg_f, "__arg"));
        }
        else
            abii_args->push_arg(new ArgPrinter(arg, "__arg"));

        auto abii_ret = real_dlinfo(handle, request, arg);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dlinfo, abii_ret)
    return real_dlinfo(handle, request, arg);
}

static int (*real__dl_find_object)(void*, dl_find_object*) __THROW = nullptr;

extern "C" int abii__dl_find_object(void* address, dl_find_object* result) __THROW
{
    OVERRIDE_PREFIX(_dl_find_object)
        pre_fmtd_str str = "_dl_find_object(__address, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(address, "__address"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real__dl_find_object(address, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(_dl_find_object, abii_ret)
    return real__dl_find_object(address, result);
}
}
