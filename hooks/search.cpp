//
// Created by Trent Tanchin on 5/23/25.
//

#include "search.h"

namespace abii
{
static void (*real_insque)(void*, void*) __THROW = nullptr;

extern "C" void abii_insque(void* elem, void* prev) __THROW
{
    OVERRIDE_PREFIX(insque)
        pre_fmtd_str pi_str = "insque(__elem, __prev)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(elem, "__elem"));
        abii_args->push_arg(new ArgPrinter(prev, "__prev"));

        real_insque(elem, prev);
    OVERRIDE_SUFFIX(insque,)
    return real_insque(elem, prev);
}

static void (*real_remque)(void*) __THROW = nullptr;

extern "C" void abii_remque(void* elem) __THROW
{
    OVERRIDE_PREFIX(remque)
        pre_fmtd_str pi_str = "remque(__elem)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(elem, "__elem"));

        real_remque(elem);
    OVERRIDE_SUFFIX(remque,)
    return real_remque(elem);
}

static ENTRY* (*real_hsearch)(ENTRY, ACTION) __THROW = nullptr;

extern "C" ENTRY* abii_hsearch(ENTRY item, ACTION action) __THROW
{
    OVERRIDE_PREFIX(hsearch)
        pre_fmtd_str pi_str = "hsearch(__item, __action)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(item, "__item"));

        auto printer = new ArgPrinter(action, "__action");
        printer->set_enum_printer(print_search_enum1, action);
        abii_args->push_arg(printer);

        auto abii_ret = real_hsearch(item, action);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(hsearch, abii_ret)
    return real_hsearch(item, action);
}

static int (*real_hcreate)(size_t) __THROW = nullptr;

extern "C" int abii_hcreate(size_t nel) __THROW
{
    OVERRIDE_PREFIX(hcreate)
        pre_fmtd_str pi_str = "hcreate(__nel)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nel, "__nel"));

        auto abii_ret = real_hcreate(nel);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(hcreate, abii_ret)
    return real_hcreate(nel);
}

static void (*real_hdestroy)() __THROW = nullptr;

extern "C" void abii_hdestroy() __THROW
{
    OVERRIDE_PREFIX(hdestroy)
        pre_fmtd_str pi_str = "hdestroy()";
        abii_args->push_func(new ArgPrinter(pi_str));

        real_hdestroy();
    OVERRIDE_SUFFIX(hdestroy,)
    return real_hdestroy();
}

static int (*real_hsearch_r)(ENTRY, ACTION, ENTRY**, hsearch_data*) __THROW = nullptr;

extern "C" int abii_hsearch_r(ENTRY item, ACTION action, ENTRY** retval, hsearch_data* htab) __THROW
{
    OVERRIDE_PREFIX(hsearch_r)
        pre_fmtd_str pi_str = "hsearch_r(__item, __action, __retval, __htab)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(item, "__item"));

        auto printer = new ArgPrinter(action, "__action");
        printer->set_enum_printer(print_search_enum1, action);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(retval, "__retval"));
        abii_args->push_arg(new ArgPrinter(htab, "__htab"));

        auto abii_ret = real_hsearch_r(item, action, retval, htab);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(hsearch_r, abii_ret)
    return real_hsearch_r(item, action, retval, htab);
}

static int (*real_hcreate_r)(size_t, hsearch_data*) __THROW = nullptr;

extern "C" int abii_hcreate_r(size_t nel, hsearch_data* htab) __THROW
{
    OVERRIDE_PREFIX(hcreate_r)
        pre_fmtd_str pi_str = "hcreate_r(__nel, __htab)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(nel, "__nel"));
        abii_args->push_arg(new ArgPrinter(htab, "__htab"));

        auto abii_ret = real_hcreate_r(nel, htab);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(hcreate_r, abii_ret)
    return real_hcreate_r(nel, htab);
}

static void (*real_hdestroy_r)(hsearch_data*) __THROW = nullptr;

extern "C" void abii_hdestroy_r(hsearch_data* htab) __THROW
{
    OVERRIDE_PREFIX(hdestroy_r)
        pre_fmtd_str pi_str = "hdestroy_r(__htab)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(htab, "__htab"));

        real_hdestroy_r(htab);
    OVERRIDE_SUFFIX(hdestroy_r,)
    return real_hdestroy_r(htab);
}

static void* (*real_tsearch)(const void*, void**, __compar_fn_t) = nullptr;

extern "C" void* abii_tsearch(const void* key, void** rootp, __compar_fn_t compar)
{
    OVERRIDE_PREFIX(tsearch)
        pre_fmtd_str pi_str = "tsearch(__key, __rootp, __compar)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key"));
        abii_args->push_arg(new ArgPrinter(rootp, "__rootp"));
        abii_args->push_arg(new ArgPrinter(compar, "__compar"));

        auto abii_ret = real_tsearch(key, rootp, compar);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tsearch, abii_ret)
    return real_tsearch(key, rootp, compar);
}

static void* (*real_tfind)(const void*, void* const*, __compar_fn_t) = nullptr;

extern "C" void* abii_tfind(const void* key, void* const* rootp, __compar_fn_t compar)
{
    OVERRIDE_PREFIX(tfind)
        pre_fmtd_str pi_str = "tfind(__key, __rootp, __compar)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key"));
        abii_args->push_arg(new ArgPrinter(rootp, "__rootp"));
        abii_args->push_arg(new ArgPrinter(compar, "__compar"));

        auto abii_ret = real_tfind(key, rootp, compar);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tfind, abii_ret)
    return real_tfind(key, rootp, compar);
}

static void* (*real_tdelete)(const void*, void**, __compar_fn_t) = nullptr;

extern "C" void* abii_tdelete(const void* key, void** rootp, __compar_fn_t compar)
{
    OVERRIDE_PREFIX(tdelete)
        pre_fmtd_str pi_str = "tdelete(__key, __rootp, __compar)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key"));
        abii_args->push_arg(new ArgPrinter(rootp, "__rootp"));
        abii_args->push_arg(new ArgPrinter(compar, "__compar"));

        auto abii_ret = real_tdelete(key, rootp, compar);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(tdelete, abii_ret)
    return real_tdelete(key, rootp, compar);
}

static void (*real_twalk)(const void*, __action_fn_t) = nullptr;

extern "C" void abii_twalk(const void* root, __action_fn_t action)
{
    OVERRIDE_PREFIX(twalk)
        pre_fmtd_str pi_str = "twalk(__root, __action)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(root, "__root"));
        abii_args->push_arg(new ArgPrinter(action, "__action"));

        real_twalk(root, action);
    OVERRIDE_SUFFIX(twalk,)
    return real_twalk(root, action);
}

static void (*real_twalk_r)(const void*, void (*)(const void*, VISIT, void*), void*) = nullptr;

extern "C" void abii_twalk_r(const void* root, void (*action)(const void* nodep, VISIT value, void* closure),
                             void* closure)
{
    OVERRIDE_PREFIX(twalk_r)
        pre_fmtd_str pi_str = "twalk_r(__root, __action, __closure)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(root, "__root"));
        abii_args->push_arg(new ArgPrinter(action, "__action"));
        abii_args->push_arg(new ArgPrinter(closure, "__closure"));

        real_twalk_r(root, action, closure);
    OVERRIDE_SUFFIX(twalk_r,)
    return real_twalk_r(root, action, closure);
}

static void (*real_tdestroy)(void*, __free_fn_t) = nullptr;

extern "C" void abii_tdestroy(void* root, __free_fn_t freefct)
{
    OVERRIDE_PREFIX(tdestroy)
        pre_fmtd_str pi_str = "tdestroy(__root, __freefct)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(root, "__root"));
        abii_args->push_arg(new ArgPrinter(freefct, "__freefct"));

        real_tdestroy(root, freefct);
    OVERRIDE_SUFFIX(tdestroy,)
    return real_tdestroy(root, freefct);
}

static void* (*real_lfind)(const void*, const void*, size_t*, size_t, __compar_fn_t) = nullptr;

extern "C" void* abii_lfind(const void* key, const void* base, size_t* nmemb, size_t size, __compar_fn_t compar)
{
    OVERRIDE_PREFIX(lfind)
        pre_fmtd_str pi_str = "lfind(__key, __base, __nmemb, __size, __compar)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key")); // Size = size
        abii_args->push_arg(new ArgPrinter(base, "__base")); // Size = *nmemb * size
        abii_args->push_arg(new ArgPrinter(nmemb, "__nmemb"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(compar, "__compar"));

        auto abii_ret = real_lfind(key, base, nmemb, size, compar);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lfind, abii_ret)
    return real_lfind(key, base, nmemb, size, compar);
}

static void* (*real_lsearch)(const void*, void*, size_t*, size_t, __compar_fn_t) = nullptr;

extern "C" void* abii_lsearch(const void* key, void* base, size_t* nmemb, size_t size, __compar_fn_t compar)
{
    OVERRIDE_PREFIX(lsearch)
        pre_fmtd_str pi_str = "lsearch(__key, __base, __nmemb, __size, __compar)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(key, "__key")); // Size = size
        abii_args->push_arg(new ArgPrinter(base, "__base")); // Size = *nmemb * size
        abii_args->push_arg(new ArgPrinter(nmemb, "__nmemb"));
        abii_args->push_arg(new ArgPrinter(size, "__size"));
        abii_args->push_arg(new ArgPrinter(compar, "__compar"));

        auto abii_ret = real_lsearch(key, base, nmemb, size, compar);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(lsearch, abii_ret)
    return real_lsearch(key, base, nmemb, size, compar);
}
}
