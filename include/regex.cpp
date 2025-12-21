//
// Created by Trent Tanchin on 3/11/25.
//

#include "regex.h"

namespace abii
{
static reg_syntax_t (*real_re_set_syntax)(reg_syntax_t) = nullptr;

extern "C" reg_syntax_t abii_re_set_syntax(reg_syntax_t syntax)
{
    OVERRIDE_PREFIX(re_set_syntax)
        pre_fmtd_str pi_str = "re_set_syntax(__syntax)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = ArgPrinter(syntax, "__syntax");
        printer.set_enum_printer(print_regex_syntax, syntax);
        abii_args->push_arg(&printer);

        const auto abii_ret = real_re_set_syntax(syntax);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(re_set_syntax, abii_ret)
    return real_re_set_syntax(syntax);
}

static const char*(*real_re_compile_pattern)(const char*, size_t, re_pattern_buffer*) = nullptr;

extern "C" _Attr_access_((__read_only__, 1, 2))
const char* abii_re_compile_pattern(const char* pattern, size_t length, re_pattern_buffer* buffer)
{
    OVERRIDE_PREFIX(re_compile_pattern)
        pre_fmtd_str pi_str = "re_compile_pattern(__pattern, __length, __buffer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = new ArgPrinter(pattern, "__pattern");
        printer->set_len(length);
        abii_args->push_arg(printer);

        abii_args->push_arg(new ArgPrinter(length, "__length"));
        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        const auto abii_ret = real_re_compile_pattern(pattern, length, buffer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(re_compile_pattern, abii_ret)
    return real_re_compile_pattern(pattern, length, buffer);
}

static int (*real_re_compile_fastmap)(re_pattern_buffer*) = nullptr;

extern "C" int abii_re_compile_fastmap(re_pattern_buffer* buffer)
{
    OVERRIDE_PREFIX(re_compile_fastmap)
        pre_fmtd_str pi_str = "re_compile_fastmap(__buffer)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        const auto abii_ret = real_re_compile_fastmap(buffer);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(re_compile_fastmap, abii_ret)
    return real_re_compile_fastmap(buffer);
}

static regoff_t (*real_re_search)(re_pattern_buffer*, const char*, regoff_t, regoff_t, regoff_t, re_registers*) =
    nullptr;

extern "C" _Attr_access_((__read_only__, 2, 3))
regoff_t abii_re_search(re_pattern_buffer* buffer, const char* String, regoff_t length, regoff_t start, regoff_t range,
                        re_registers* regs)
{
    OVERRIDE_PREFIX(re_search)
        pre_fmtd_str pi_str = "re_search(__buffer, __String, __length, __start, __range, __regs)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        auto printer = ArgPrinter(String, "__String");
        printer.set_len(length);
        abii_args->push_arg(&printer);

        abii_args->push_arg(new ArgPrinter(length, "__length"));
        abii_args->push_arg(new ArgPrinter(start, "__start"));
        abii_args->push_arg(new ArgPrinter(range, "__range"));
        abii_args->push_arg(new ArgPrinter(regs, "__regs"));

        const auto abii_ret = real_re_search(buffer, String, length, start, range, regs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(re_search, abii_ret)
    return real_re_search(buffer, String, length, start, range, regs);
}

static regoff_t (*real_re_search_2)(re_pattern_buffer*, const char*, regoff_t, const char*, regoff_t, regoff_t,
                                    regoff_t, re_registers*, regoff_t) = nullptr;

extern "C" _Attr_access_((__read_only__, 2, 3)) _Attr_access_((__read_only__, 4, 5))
regoff_t abii_re_search_2(re_pattern_buffer* buffer, const char* string1, regoff_t length1, const char* string2,
                          regoff_t length2, regoff_t start, regoff_t range, re_registers* regs, regoff_t stop)
{
    OVERRIDE_PREFIX(re_search_2)
        pre_fmtd_str pi_str =
            "re_search_2(__buffer, __string1, __length1, __string2, __length2, __start, __range, __regs, __stop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        auto printer = ArgPrinter(string1, "__string1");
        printer.set_len(length1);
        abii_args->push_arg(&printer);

        abii_args->push_arg(new ArgPrinter(length1, "__length1"));

        auto printer1 = ArgPrinter(string2, "__string2");
        printer1.set_len(length2);
        abii_args->push_arg(&printer1);

        abii_args->push_arg(new ArgPrinter(length2, "__length2"));
        abii_args->push_arg(new ArgPrinter(start, "__start"));
        abii_args->push_arg(new ArgPrinter(range, "__range"));
        abii_args->push_arg(new ArgPrinter(regs, "__regs"));
        abii_args->push_arg(new ArgPrinter(stop, "__stop"));

        const auto abii_ret = real_re_search_2(buffer, string1, length1, string2, length2, start, range, regs, stop);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(re_search_2, abii_ret)
    return real_re_search_2(buffer, string1, length1, string2, length2, start, range, regs, stop);
}

static regoff_t (*real_re_match)(re_pattern_buffer*, const char*, regoff_t, regoff_t, re_registers*) = nullptr;

extern "C" _Attr_access_((__read_only__, 2, 3))
regoff_t abii_re_match(re_pattern_buffer* buffer, const char* String, regoff_t length, regoff_t start,
                       re_registers* regs)
{
    OVERRIDE_PREFIX(re_match)
        pre_fmtd_str pi_str =
            "re_match(__buffer, __String, __length, __start, __regs)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        auto printer = ArgPrinter(String, "__String");
        printer.set_len(length);
        abii_args->push_arg(&printer);

        abii_args->push_arg(new ArgPrinter(length, "__length"));
        abii_args->push_arg(new ArgPrinter(start, "__start"));
        abii_args->push_arg(new ArgPrinter(regs, "__regs"));

        const auto abii_ret = real_re_match(buffer, String, length, start, regs);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(re_match, abii_ret)
    return real_re_match(buffer, String, length, start, regs);
}

static regoff_t (*real_re_match_2)(re_pattern_buffer*, const char*, regoff_t, const char*, regoff_t, regoff_t,
                                   re_registers*, regoff_t) = nullptr;

extern "C" _Attr_access_((__read_only__, 2, 3)) _Attr_access_((__read_only__, 4, 5))
regoff_t abii_re_match_2(re_pattern_buffer* buffer, const char* string1, regoff_t length1, const char* string2,
                         regoff_t length2, regoff_t start, re_registers* regs, regoff_t stop)
{
    OVERRIDE_PREFIX(re_match_2)
        pre_fmtd_str pi_str =
            "re_match_2(__buffer, __string1, __length1, __string2, __length2, __start, __regs, __stop)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));

        auto printer = ArgPrinter(string1, "__string1");
        printer.set_len(length1);
        abii_args->push_arg(&printer);

        abii_args->push_arg(new ArgPrinter(length1, "__length1"));

        auto printer1 = ArgPrinter(string2, "__string2");
        printer1.set_len(length2);
        abii_args->push_arg(&printer1);

        abii_args->push_arg(new ArgPrinter(length2, "__length2"));
        abii_args->push_arg(new ArgPrinter(start, "__start"));
        abii_args->push_arg(new ArgPrinter(regs, "__regs"));
        abii_args->push_arg(new ArgPrinter(stop, "__stop"));

        const auto abii_ret = real_re_match_2(buffer, string1, length1, string2, length2, start, regs, stop);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(re_match_2, abii_ret)
    return real_re_match_2(buffer, string1, length1, string2, length2, start, regs, stop);
}

static void (*real_re_set_registers)(re_pattern_buffer*, re_registers*, __re_size_t, regoff_t*, regoff_t*) = nullptr;

extern "C" void abii_re_set_registers(re_pattern_buffer* buffer, re_registers* regs, __re_size_t num_regs,
                                      regoff_t* starts, regoff_t* ends)
{
    OVERRIDE_PREFIX(re_set_registers)
        pre_fmtd_str pi_str = "re_set_registers(__buffer, __regs, __num_regs, __starts, __ends)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(buffer, "__buffer"));
        abii_args->push_arg(new ArgPrinter(regs, "__regs"));
        abii_args->push_arg(new ArgPrinter(num_regs, "__num_regs"));

        auto printer = ArgPrinter(starts, "__starts");
        printer.set_len(num_regs);
        abii_args->push_arg(&printer);

        auto printer1 = ArgPrinter(ends, "__ends");
        printer1.set_len(num_regs);
        abii_args->push_arg(&printer1);

        real_re_set_registers(buffer, regs, num_regs, starts, ends);
    OVERRIDE_SUFFIX(re_set_registers,)
    return real_re_set_registers(buffer, regs, num_regs, starts, ends);
}

static char* (*real_re_comp)(const char*) = nullptr;

extern "C" char* abii_re_comp(const char* str)
{
    OVERRIDE_PREFIX(re_comp)
        pre_fmtd_str pi_str = "re_comp(str)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(str, "__str"));

        const auto abii_ret = real_re_comp(str);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(re_comp, abii_ret)
    return real_re_comp(str);
}

static int (*real_re_exec)(const char*) = nullptr;

extern "C" int abii_re_exec(const char* str)
{
    OVERRIDE_PREFIX(re_exec)
        pre_fmtd_str pi_str = "re_exec(str)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(str, "__str"));

        const auto abii_ret = real_re_exec(str);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(re_exec, abii_ret)
    return real_re_exec(str);
}

static int (*real_regcomp)(regex_t*, const char*, int) = nullptr;

extern "C" int abii_regcomp(regex_t* preg, const char* pattern, int cflags)
{
    OVERRIDE_PREFIX(regcomp)
        pre_fmtd_str pi_str = "regcomp(__preg, __pattern, __cflags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(preg, "__preg"));
        abii_args->push_arg(new ArgPrinter(pattern, "__pattern"));

        auto printer = ArgPrinter(cflags, "__cflags");
        printer.set_enum_printer(print_regex_cflags, cflags);
        abii_args->push_arg(&printer);

        const auto abii_ret = real_regcomp(preg, pattern, cflags);

        auto printer1 = ArgPrinter(abii_ret, "return");
        printer1.set_enum_printer(print_regex_reg_errcode_t, abii_ret);
        abii_args->push_return(&printer1);
    OVERRIDE_SUFFIX(regcomp, abii_ret)
    return real_regcomp(preg, pattern, cflags);
}

static int (*real_regexec)(const regex_t*, const char*, size_t, regmatch_t [], int __eflags) = nullptr;

extern "C" int abii_regexec(const regex_t* preg, const char* String, size_t nmatch,
                            regmatch_t pmatch[_REGEX_NELTS(nmatch)], int eflags)
{
    OVERRIDE_PREFIX(regexec)
        pre_fmtd_str pi_str = "regexec(__preg, __String, __nmatch, pmatch, eflags)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(preg, "__preg"));
        abii_args->push_arg(new ArgPrinter(String, "__String"));
        abii_args->push_arg(new ArgPrinter(nmatch, "__nmatch"));
        abii_args->push_arg(new ArgPrinter(pmatch, "__pmatch"));

        auto printer = ArgPrinter(eflags, "__eflags");
        printer.set_enum_printer(print_regex_eflags, eflags);
        abii_args->push_arg(&printer);

        const auto abii_ret = real_regexec(preg, String, nmatch, pmatch, eflags);

        auto printer1 = ArgPrinter(abii_ret, "return");
        printer1.set_enum_printer(print_regex_reg_errcode_t, abii_ret);
        abii_args->push_return(&printer1);
    OVERRIDE_SUFFIX(regexec, abii_ret)
    return real_regexec(preg, String, nmatch, pmatch, eflags);
}

static size_t (*real_regerror)(int, const regex_t*, char*, size_t) = nullptr;

extern "C" _Attr_access_((__write_only__, 3, 4))
size_t abii_regerror(int errcode, const regex_t* preg, char* errbuf, size_t errbuf_size)
{
    OVERRIDE_PREFIX(regerror)
        pre_fmtd_str pi_str = "regerror(__errcode, __preg, __errbuf, __errbuf_size)";
        abii_args->push_func(new ArgPrinter(pi_str));

        auto printer = ArgPrinter(errcode, "__errcode");
        printer.set_enum_printer(print_regex_reg_errcode_t, errcode);
        abii_args->push_arg(&printer);

        abii_args->push_arg(new ArgPrinter(preg, "__preg"));

        auto printer1 = ArgPrinter(errbuf, "__errbuf");
        printer1.set_len(errbuf_size);
        abii_args->push_arg(&printer1);

        abii_args->push_arg(new ArgPrinter(errbuf_size, "__errbuf_size"));

        const auto abii_ret = real_regerror(errcode, preg, errbuf, errbuf_size);

        abii_args->push_return(new ArgPrinter(abii_ret, "return"));
    OVERRIDE_SUFFIX(regerror, abii_ret)
    return real_regerror(errcode, preg, errbuf, errbuf_size);
}

static void (*real_regfree)(regex_t*) = nullptr;

extern "C" void abii_regfree(regex_t* preg)
{
    OVERRIDE_PREFIX(regfree)
        pre_fmtd_str pi_str = "regfree(__preg)";
        abii_args->push_func(new ArgPrinter(pi_str));

        abii_args->push_arg(new ArgPrinter(preg, "__preg"));

        real_regfree(preg);
    OVERRIDE_SUFFIX(regfree,)
    return real_regfree(preg);
}
}
