//
// Created by Trent Tanchin on 9/28/24.
//

#include "gshadow.h"

namespace abii
{
static void (*real_setsgent)() = nullptr;

extern "C" void abii_setsgent()
{
    OVERRIDE_PREFIX(setsgent)
        pre_fmtd_str str = "setsgent()";
        abii_args->push_func(new ArgPrinter(str));

        real_setsgent();
    OVERRIDE_SUFFIX(setsgent,)
    return real_setsgent();
}

static void (*real_endsgent)() = nullptr;

extern "C" void abii_endsgent()
{
    OVERRIDE_PREFIX(endsgent)
        pre_fmtd_str str = "endsgent()";
        abii_args->push_func(new ArgPrinter(str));

        real_endsgent();
    OVERRIDE_SUFFIX(endsgent,)
    return real_endsgent();
}

static sgrp* (*real_getsgent)() = nullptr;

extern "C" sgrp* abii_getsgent()
{
    OVERRIDE_PREFIX(getsgent)
        pre_fmtd_str str = "getsgent()";
        abii_args->push_func(new ArgPrinter(str));

        auto abii_ret = real_getsgent();

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getsgent, abii_ret)
    return real_getsgent();
}

static sgrp* (*real_getsgnam)(const char*) = nullptr;

extern "C" sgrp* abii_getsgnam(const char* name)
{
    OVERRIDE_PREFIX(getsgnam)
        pre_fmtd_str str = "getsgnam(__name)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));

        auto abii_ret = real_getsgnam(name);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getsgnam, abii_ret)
    return real_getsgnam(name);
}

static sgrp* (*real_sgetsgent)(const char*) = nullptr;

extern "C" sgrp* abii_sgetsgent(const char* string)
{
    OVERRIDE_PREFIX(sgetsgent)
        pre_fmtd_str str = "sgetsgent(__string)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));

        auto abii_ret = real_sgetsgent(string);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sgetsgent, abii_ret)
    return real_sgetsgent(string);
}

static sgrp* (*real_fgetsgent)(FILE*) = nullptr;

extern "C" sgrp* abii_fgetsgent(FILE* stream)
{
    OVERRIDE_PREFIX(fgetsgent)
        pre_fmtd_str str = "fgetsgent(__stream)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_fgetsgent(stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetsgent, abii_ret)
    return real_fgetsgent(stream);
}

static int (*real_putsgent)(const sgrp*, FILE*) = nullptr;

extern "C" int abii_putsgent(const sgrp* g, FILE* stream)
{
    OVERRIDE_PREFIX(putsgent)
        pre_fmtd_str str = "putsgent(__g, __stream)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(g, "__g"));
        abii_args->push_arg(new ArgPrinter(stream, "__stream"));

        auto abii_ret = real_putsgent(g, stream);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(putsgent, abii_ret)
    return real_putsgent(g, stream);
}

static int (*real_getsgent_r)(sgrp*, char*, size_t, sgrp**) = nullptr;

extern "C" __attr_access((__write_only__, 2, 3))
int abii_getsgent_r(sgrp* result_buf, char* buffer, size_t buflen, sgrp** result)
{
    OVERRIDE_PREFIX(getsgent_r)
        pre_fmtd_str str = "getsgent_r(__result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getsgent_r(result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getsgent_r, abii_ret)
    return real_getsgent_r(result_buf, buffer, buflen, result);
}

static int (*real_getsgnam_r)(const char*, sgrp*, char*, size_t, sgrp**) = nullptr;

extern "C" __attr_access((__write_only__, 3, 4))
int abii_getsgnam_r(const char* name, sgrp* result_buf, char* buffer, size_t buflen, sgrp** result)
{
    OVERRIDE_PREFIX(getsgnam_r)
        pre_fmtd_str str = "getsgnam_r(__name, __result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(name, "__name"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_getsgnam_r(name, result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(getsgnam_r, abii_ret)
    return real_getsgnam_r(name, result_buf, buffer, buflen, result);
}

static int (*real_sgetsgent_r)(const char*, sgrp*, char*, size_t, sgrp**) = nullptr;

extern "C" __attr_access((__write_only__, 3, 4))
int abii_sgetsgent_r(const char* string, sgrp* result_buf, char* buffer, size_t buflen, sgrp** result)
{
    OVERRIDE_PREFIX(sgetsgent_r)
        pre_fmtd_str str = "sgetsgent_r(__string, __result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(string, "__string"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_sgetsgent_r(string, result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(sgetsgent_r, abii_ret)
    return real_sgetsgent_r(string, result_buf, buffer, buflen, result);
}

static int (*real_fgetsgent_r)(FILE*, sgrp*, char*, size_t, sgrp**) = nullptr;

extern "C" __attr_access((__write_only__, 3, 4))
int abii_fgetsgent_r(FILE* stream, sgrp* result_buf, char* buffer, size_t buflen, sgrp** result)
{
    OVERRIDE_PREFIX(fgetsgent_r)
        pre_fmtd_str str = "fgetsgent_r(__stream, __result_buf, __buffer, __buflen, __result)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(stream, "__stream"));
        abii_args->push_arg(new ArgPrinter(result_buf, "__result_buf"));

        auto printer = new ArgPrinter(buffer, "__buffer");
        printer->set_len(buflen);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(buflen, "__buflen"));
        abii_args->push_arg(new ArgPrinter(result, "__result"));

        auto abii_ret = real_fgetsgent_r(stream, result_buf, buffer, buflen, result);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(fgetsgent_r, abii_ret)
    return real_fgetsgent_r(stream, result_buf, buffer, buflen, result);
}
}
