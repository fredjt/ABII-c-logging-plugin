//
// Created by Trent Tanchin on 12/27/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_PATHS_H
#define ABII_C_LOGGING_PLUGIN_PATHS_H

#include <paths.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map<const char*> paths_default = {
    {"/usr/bin:/bin", "_PATH_DEFPATH"},
    {"/usr/bin:/bin:/usr/sbin:/sbin", "_PATH_STDPATH"},
    {"/bin/sh", "_PATH_BSHELL"},
    {"/dev/console", "_PATH_CONSOLE"},
    {"/bin/csh", "_PATH_CSHELL"},
    {"/var/run/dev.db", "_PATH_DEVDB"},
    {"/dev/null", "_PATH_DEVNULL"},
    {"/dev/drum", "_PATH_DRUM"},
    {"/etc/gshadow", "_PATH_GSHADOW"},
    {"/proc/kmsg", "_PATH_KLOG"},
    {"/dev/kmem", "_PATH_KMEM"},
    {"/var/log/lastlog", "_PATH_LASTLOG"},
    {"/var/mail", "_PATH_MAILDIR"},
    {"/usr/share/man", "_PATH_MAN"},
    {"/dev/mem", "_PATH_MEM"},
    {"/etc/fstab", "_PATH_MNTTAB"},
    {"/etc/mtab", "_PATH_MOUNTED"},
    {"/etc/nologin", "_PATH_NOLOGIN"},
    {"/var/lib", "_PATH_PRESERVE"},
    {"/var/spool/rwho", "_PATH_RWHODIR"},
    {"/usr/sbin/sendmail", "_PATH_SENDMAIL"},
    {"/etc/shadow", "_PATH_SHADOW"},
    {"/etc/shells", "_PATH_SHELLS"},
    {"/dev/tty", "_PATH_TTY"},
    {"/boot/vmlinux", "_PATH_UNIX"},
    {"/var/run/utmp", "_PATH_UTMP"},
    {"/usr/bin/vi", "_PATH_VI"},
    {"/var/log/wtmp", "_PATH_WTMP"},
    {"/dev/", "_PATH_DEV"},
    {"/tmp/", "_PATH_TMP"},
    {"/var/lib/nss_db/", "_PATH_VARDB"},
    {"/var/run/", "_PATH_VARRUN"},
    {"/var/tmp/", "_PATH_VARTMP"}
};

template <typename T>
std::string print_paths_default(const T v)
{
    return print_enum_entry(v, paths_default);
}
}

#endif //ABII_C_LOGGING_PLUGIN_PATHS_H
