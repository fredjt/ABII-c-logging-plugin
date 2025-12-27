//
// Created by Trent Tanchin on 9/28/24.
//

#include "ifaddrs.h"

namespace abii
{
static int (*real_getifaddrs)(ifaddrs**) __THROW = nullptr;

extern "C" int abii_getifaddrs(ifaddrs** ifap) __THROW
{
    OVERRIDE_PREFIX(getifaddrs)
        pre_fmtd_str str = "getifaddrs(__ifap)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ifap, "__ifap"));

        auto abii_ret = real_getifaddrs(ifap);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getifaddrs, abii_ret)
    return real_getifaddrs(ifap);
}

static void (*real_freeifaddrs)(ifaddrs*) __THROW = nullptr;

extern "C" void abii_freeifaddrs(ifaddrs* ifa) __THROW
{
    OVERRIDE_PREFIX(freeifaddrs)
        pre_fmtd_str str = "freeifaddrs(__ifa)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(ifa, "__ifa"));

        real_freeifaddrs(ifa);
    OVERRIDE_SUFFIX(freeifaddrs,)
    return real_freeifaddrs(ifa);
}
}
