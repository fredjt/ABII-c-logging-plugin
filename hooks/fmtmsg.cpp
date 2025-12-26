//
// Created by Trent Tanchin on 9/17/24.
//

#include "fmtmsg.h"

namespace abii
{
static int (*real_fmtmsg)(long int, const char*, int, const char*, const char*, const char*) = nullptr;

extern "C" int abii_fmtmsg(long int classification, const char* label, int severity, const char* text,
                           const char* action, const char* tag)
{
    OVERRIDE_PREFIX(fmtmsg)
        pre_fmtd_str str = "fmtmsg(__classification, __label, __severity, __text, __action, __tag)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(classification, "__classification");
        printer->set_enum_printer(print_fmtmsg_classification, classification);
        abii_args->push_arg(printer);

        auto printer1 = new ArgPrinter(label, "__label");
        printer1->set_enum_printer(print_fmtmsg_mm_nulllbl, label);
        abii_args->push_arg(printer1);

        auto printer2 = new ArgPrinter(severity, "__severity");
        printer2->set_enum_printer(print_fmtmsg_severity, severity);
        abii_args->push_arg(printer2);

        auto printer3 = new ArgPrinter(text, "__text");
        printer3->set_enum_printer(print_fmtmsg_mm_nulltxt, text);
        abii_args->push_arg(printer3);

        auto printer4 = new ArgPrinter(action, "__action");
        printer4->set_enum_printer(print_fmtmsg_mm_nullact, action);
        abii_args->push_arg(printer4);

        auto printer5 = new ArgPrinter(tag, "__tag");
        printer5->set_enum_printer(print_fmtmsg_mm_nulltag, tag);
        abii_args->push_arg(printer5);

        auto abii_ret = real_fmtmsg(classification, label, severity, text, action, tag);

        auto printer6 = new ArgPrinter(abii_ret, "return");
        printer6->set_enum_printer(print_fmtmsg_fmtmsg_ret, abii_ret);
        abii_args->push_return(printer6);
    OVERRIDE_SUFFIX(fmtmsg, abii_ret)
    return real_fmtmsg(classification, label, severity, text, action, tag);
}

static int (*real_addseverity)(int, const char*) __THROW = nullptr;

extern "C" int abii_addseverity(int severity, const char* string) __THROW
{
    OVERRIDE_PREFIX(addseverity)
        pre_fmtd_str str = "addseverity(__severity, __string)";
        abii_args->push_func(new ArgPrinter(str));

        auto printer = new ArgPrinter(severity, "__severity");
        printer->set_enum_printer(print_fmtmsg_severity, severity);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(string, "__string"));

        auto abii_ret = real_addseverity(severity, string);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(addseverity, abii_ret)
    return real_addseverity(severity, string);
}
}
