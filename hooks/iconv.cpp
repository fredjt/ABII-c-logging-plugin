//
// Created by Trent Tanchin on 9/28/24.
//

#include <iconv.h>
#include <abii/libabii.h>

namespace abii
{
static int (*real_iconv_close)(iconv_t) = nullptr;

extern "C" int abii_iconv_close(iconv_t cd)
{
    OVERRIDE_PREFIX(iconv_close)
        pre_fmtd_str str = "iconv_close(__cd)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(cd, "__cd"));

        auto abii_ret = real_iconv_close(cd);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iconv_close, abii_ret)
    return real_iconv_close(cd);
}

static iconv_t (*real_iconv_open)(const char*, const char*) = nullptr;

extern "C" __attribute_malloc__ __attr_dealloc(iconv_close, 1)
iconv_t abii_iconv_open(const char* tocode, const char* fromcode)
{
    OVERRIDE_PREFIX(iconv_open)
        pre_fmtd_str str = "iconv_open(__tocode, __fromcode)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(tocode, "__tocode"));
        abii_args->push_arg(new ArgPrinter(fromcode, "__fromcode"));

        auto abii_ret = real_iconv_open(tocode, fromcode);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iconv_open, abii_ret)
    return real_iconv_open(tocode, fromcode);
}

static size_t (*real_iconv)(iconv_t, char**, size_t*, char**, size_t*) = nullptr;

extern "C" size_t abii_iconv(iconv_t cd, char** inbuf, size_t* inbytesleft, char** outbuf, size_t* outbytesleft)
{
    OVERRIDE_PREFIX(iconv)
        pre_fmtd_str str = "iconv(__cd, __inbuf, __inbytesleft, __outbuf, __outbytesleft)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(cd, "__cd"));

        auto printer = new ArgPrinter(inbuf, "__inbuf");
        // TODO: This is not implemented yet
        // printer->set_len_with_depth(*inbytesleft, 1);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(inbytesleft, "__inbytesleft"));

        auto printer1 = new ArgPrinter(outbuf, "__outbuf");
        // TODO: This is not implemented yet
        // printer1->set_len_with_depth(*outbytesleft, 1);
        abii_args->push_arg(printer1);

        abii_args->push_arg(new ArgPrinter(outbytesleft, "__outbytesleft"));

        auto abii_ret = real_iconv(cd, inbuf, inbytesleft, outbuf, outbytesleft);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(iconv, abii_ret)
    return real_iconv(cd, inbuf, inbytesleft, outbuf, outbytesleft);
}
}
