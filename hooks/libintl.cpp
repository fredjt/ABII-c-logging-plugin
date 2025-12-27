//
// Created by Trent Tanchin on 10/1/24.
//

#include <libintl.h>
#include <abii/libabii.h>

#include "locale.h"

namespace abii
{
static char* (*real_gettext)(const char*) noexcept(true) = nullptr;

extern "C" __attribute_format_arg__(1)
char* abii_gettext(const char* msgid) __THROW
{
    OVERRIDE_PREFIX(gettext)
        pre_fmtd_str str = "gettext(__msgid)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(msgid, "__msgid"));

        auto abii_ret = real_gettext(msgid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(gettext, abii_ret)
    return real_gettext(msgid);
}

static char* (*real_dgettext)(const char*, const char*) noexcept(true) = nullptr;

extern "C" __attribute_format_arg__(2)
char* abii_dgettext(const char* domainname, const char* msgid) __THROW
{
    OVERRIDE_PREFIX(dgettext)
        pre_fmtd_str str = "dgettext(__domainname, __msgid)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(domainname, "__domainname"));
        abii_args->push_arg(new ArgPrinter(msgid, "__msgid"));

        auto abii_ret = real_dgettext(domainname, msgid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dgettext, abii_ret)
    return real_dgettext(domainname, msgid);
}

static char* (*real___dgettext)(const char*, const char*) noexcept(true) = nullptr;

extern "C" __attribute_format_arg__(2)
char* abii___dgettext(const char* domainname, const char* msgid) __THROW
{
    OVERRIDE_PREFIX(__dgettext)
        pre_fmtd_str str = "__dgettext(__domainname, __msgid)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(domainname, "__domainname"));
        abii_args->push_arg(new ArgPrinter(msgid, "__msgid"));

        auto abii_ret = real___dgettext(domainname, msgid);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__dgettext, abii_ret)
    return real___dgettext(domainname, msgid);
}

static char* (*real_dcgettext)(const char*, const char*, int) noexcept(true) = nullptr;

extern "C" __attribute_format_arg__(2)
char* abii_dcgettext(const char* domainname, const char* msgid, int category) __THROW
{
    OVERRIDE_PREFIX(dcgettext)
        pre_fmtd_str str = "dcgettext(__domainname, __msgid, __category)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(domainname, "__domainname"));
        abii_args->push_arg(new ArgPrinter(msgid, "__msgid"));

        auto printer = new ArgPrinter(category, "__category");
        printer->set_enum_printer(print_locale_category, category);
        abii_args->push_arg(printer);

        auto abii_ret = real_dcgettext(domainname, msgid, category);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dcgettext, abii_ret)
    return real_dcgettext(domainname, msgid, category);
}

static char* (*real___dcgettext)(const char*, const char*, int) noexcept(true) = nullptr;

extern "C" __attribute_format_arg__(2)
char* abii___dcgettext(const char* domainname, const char* msgid, int category) __THROW
{
    OVERRIDE_PREFIX(__dcgettext)
        pre_fmtd_str str = "__dcgettext(__domainname, __msgid, __category)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(domainname, "__domainname"));
        abii_args->push_arg(new ArgPrinter(msgid, "__msgid"));

        auto printer = new ArgPrinter(category, "__category");
        printer->set_enum_printer(print_locale_category, category);
        abii_args->push_arg(printer);

        auto abii_ret = real___dcgettext(domainname, msgid, category);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(__dcgettext, abii_ret)
    return real___dcgettext(domainname, msgid, category);
}

static char* (*real_ngettext)(const char*, const char*, unsigned long int) noexcept(true) = nullptr;

extern "C" __attribute_format_arg__(1) __attribute_format_arg__(2)
char* abii_ngettext(const char* msgid1, const char* msgid2, unsigned long int n) __THROW
{
    OVERRIDE_PREFIX(ngettext)
        pre_fmtd_str str = "ngettext(__msgid1, __msgid2, __n)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(msgid1, "__msgid1"));
        abii_args->push_arg(new ArgPrinter(msgid2, "__msgid2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_ngettext(msgid1, msgid2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(ngettext, abii_ret)
    return real_ngettext(msgid1, msgid2, n);
}

static char* (*real_dngettext)(const char*, const char*, const char*, unsigned long int) noexcept(true) = nullptr;

extern "C" __attribute_format_arg__(2) __attribute_format_arg__(3)
char* abii_dngettext(const char* domainname, const char* msgid1, const char* msgid2, unsigned long int n) __THROW
{
    OVERRIDE_PREFIX(dngettext)
        pre_fmtd_str str = "dngettext(__domainname, __msgid1, __msgid2, __n)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(domainname, "__domainname"));
        abii_args->push_arg(new ArgPrinter(msgid1, "__msgid1"));
        abii_args->push_arg(new ArgPrinter(msgid2, "__msgid2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto abii_ret = real_dngettext(domainname, msgid1, msgid2, n);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dngettext, abii_ret)
    return real_dngettext(domainname, msgid1, msgid2, n);
}

static char* (*real_dcngettext)(const char*, const char*, const char*, unsigned long int, int) noexcept(true) = nullptr;

extern "C" __attribute_format_arg__(2) __attribute_format_arg__(3)
char* abii_dcngettext(const char* domainname, const char* msgid1, const char* msgid2, unsigned long int n,
                      int category) __THROW
{
    OVERRIDE_PREFIX(dcngettext)
        pre_fmtd_str str = "dcngettext(__domainname, __msgid1, __msgid2, __n, __category)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(domainname, "__domainname"));
        abii_args->push_arg(new ArgPrinter(msgid1, "__msgid1"));
        abii_args->push_arg(new ArgPrinter(msgid2, "__msgid2"));
        abii_args->push_arg(new ArgPrinter(n, "__n"));

        auto printer = new ArgPrinter(category, "__category");
        printer->set_enum_printer(print_locale_category, category);
        abii_args->push_arg(printer);

        auto abii_ret = real_dcngettext(domainname, msgid1, msgid2, n, category);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(dcngettext, abii_ret)
    return real_dcngettext(domainname, msgid1, msgid2, n, category);
}

static char* (*real_textdomain)(const char*) noexcept(true) = nullptr;

extern "C" char* abii_textdomain(const char* domainname) __THROW
{
    OVERRIDE_PREFIX(textdomain)
        pre_fmtd_str str = "textdomain(__domainname)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(domainname, "__domainname"));

        auto abii_ret = real_textdomain(domainname);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(textdomain, abii_ret)
    return real_textdomain(domainname);
}

static char* (*real_bindtextdomain)(const char*, const char*) noexcept(true) = nullptr;

extern "C" char* abii_bindtextdomain(const char* domainname, const char* dirname) __THROW
{
    OVERRIDE_PREFIX(bindtextdomain)
        pre_fmtd_str str = "bindtextdomain(__domainname, __dirname)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(domainname, "__domainname"));
        abii_args->push_arg(new ArgPrinter(dirname, "__dirname"));

        auto abii_ret = real_bindtextdomain(domainname, dirname);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(bindtextdomain, abii_ret)
    return real_bindtextdomain(domainname, dirname);
}

static char* (*real_bind_textdomain_codeset)(const char*, const char*) noexcept(true) = nullptr;

extern "C" char* abii_bind_textdomain_codeset(const char* domainname, const char* codeset) __THROW
{
    OVERRIDE_PREFIX(bind_textdomain_codeset)
        pre_fmtd_str str = "bind_textdomain_codeset(__domainname, __codeset)";
        abii_args->push_func(new ArgPrinter(str));

        abii_args->push_arg(new ArgPrinter(domainname, "__domainname"));
        abii_args->push_arg(new ArgPrinter(codeset, "__codeset"));

        auto abii_ret = real_bind_textdomain_codeset(domainname, codeset);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(bind_textdomain_codeset, abii_ret)
    return real_bind_textdomain_codeset(domainname, codeset);
}
}
