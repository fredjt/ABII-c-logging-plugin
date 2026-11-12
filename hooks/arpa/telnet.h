//
// Created by Trent Tanchin on 11/11/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_ARPA_TELNET_H
#define ABII_C_LOGGING_PLUGIN_ARPA_TELNET_H

#include <abii/libabii.h>

namespace abii
{
const defines_map arpa_telnet_defs = {
    {255, "IAC"},
    {254, "DONT"},
    {253, "DO"},
    {252, "WONT"},
    {251, "WILL"},
    {250, "SB"},
    {249, "GA"},
    {248, "EL"},
    {247, "EC"},
    {246, "AYT"},
    {245, "AO"},
    {244, "IP"},
    {243, "BREAK"},
    {242, "DM"},
    {241, "NOP"},
    {240, "SE"},
    {239, "EOR"},
    {238, "ABORT"},
    {237, "SUSP"},
    {236, "xEOF"},
    {242, "SYNCH"},
    {236, "TELCMD_FIRST"},
    {255, "TELCMD_LAST"}
};

const defines_map arpa_telnet_opts = {
    {0, "TELOPT_BINARY"},
    {1, "TELOPT_ECHO"},
    {2, "TELOPT_RCP"},
    {3, "TELOPT_SGA"},
    {4, "TELOPT_NAMS"},
    {5, "TELOPT_STATUS"},
    {6, "TELOPT_TM"},
    {7, "TELOPT_RCTE"},
    {8, "TELOPT_NAOL"},
    {9, "TELOPT_NAOP"},
    {10, "TELOPT_NAOCRD"},
    {11, "TELOPT_NAOHTS"},
    {12, "TELOPT_NAOHTD"},
    {13, "TELOPT_NAOFFD"},
    {14, "TELOPT_NAOVTS"},
    {15, "TELOPT_NAOVTD"},
    {16, "TELOPT_NAOLFD"},
    {17, "TELOPT_XASCII"},
    {18, "TELOPT_LOGOUT"},
    {19, "TELOPT_BM"},
    {20, "TELOPT_DET"},
    {21, "TELOPT_SUPDUP"},
    {22, "TELOPT_SUPDUPOUTPUT"},
    {23, "TELOPT_SNDLOC"},
    {24, "TELOPT_TTYPE"},
    {25, "TELOPT_EOR"},
    {26, "TELOPT_TUID"},
    {27, "TELOPT_OUTMRK"},
    {28, "TELOPT_TTYLOC"},
    {29, "TELOPT_3270REGIME"},
    {30, "TELOPT_X3PAD"},
    {31, "TELOPT_NAWS"},
    {32, "TELOPT_TSPEED"},
    {33, "TELOPT_LFLOW"},
    {34, "TELOPT_LINEMODE"},
    {35, "TELOPT_XDISPLOC"},
    {36, "TELOPT_OLD_ENVIRON"},
    {37, "TELOPT_AUTHENTICATION"},
    {38, "TELOPT_ENCRYPT"},
    {39, "TELOPT_NEW_ENVIRON"},
    {255, "TELOPT_EXOPL"},
    {40, "NTELOPTS"},
    {0, "TELOPT_FIRST"},
    {39, "TELOPT_LAST"}
};

const defines_map arpa_telnet_telqual = {
    {0, "TELQUAL_IS"},
    {1, "TELQUAL_SEND"}
};

const defines_map arpa_telnet_telqual_env = {
    {2, "TELQUAL_INFO"}
};

const defines_map arpa_telnet_telqual_auth = {
    {2, "TELQUAL_REPLY"},
    {3, "TELQUAL_NAME"}
};

const defines_map arpa_telnet_lflow = {
    {0, "LFLOW_OFF"},
    {1, "LFLOW_ON"},
    {2, "LFLOW_RESTART_ANY"},
    {3, "LFLOW_RESTART_XON"}
};

const defines_map arpa_telnet_lm = {
    {1, "LM_MODE"},
    {2, "LM_FORWARDMASK"},
    {3, "LM_SLC"}
};

const defines_map arpa_telnet_line_mode = {
    {0x01, "MODE_EDIT"},
    {0x02, "MODE_TRAPSIG"},
    {0x04, "MODE_ACK"},
    {0x08, "MODE_SOFT_TAB"},
    {0x10, "MODE_LIT_ECHO"}
};

const defines_map arpa_telnet_mode_mask = {
    {0x1f, "MODE_MASK"}
};

const defines_map arpa_telnet_mode = {
    {0x0100, "MODE_FLOW"},
    {0x0200, "MODE_ECHO"},
    {0x0400, "MODE_INBIN"},
    {0x0800, "MODE_OUTBIN"},
    {0x1000, "MODE_FORCE"}
};

const defines_map arpa_telnet_slc = {
    {1, "SLC_SYNCH"},
    {2, "SLC_BRK"},
    {3, "SLC_IP"},
    {4, "SLC_AO"},
    {5, "SLC_AYT"},
    {6, "SLC_EOR"},
    {7, "SLC_ABORT"},
    {8, "SLC_EOF"},
    {9, "SLC_SUSP"},
    {10, "SLC_EC"},
    {11, "SLC_EL"},
    {12, "SLC_EW"},
    {13, "SLC_RP"},
    {14, "SLC_LNEXT"},
    {15, "SLC_XON"},
    {16, "SLC_XOFF"},
    {17, "SLC_FORW1"},
    {18, "SLC_FORW2"},
    {18, "NSLC"}
};

const defines_map arpa_telnet_slc_level = {
    {0, "SLC_NOSUPPORT"},
    {1, "SLC_CANTCHANGE"},
    {2, "SLC_VARIABLE"},
    {3, "SLC_DEFAULT"},
    {0x03, "SLC_LEVELBITS"}
};

const defines_map arpa_telnet_slc_entry = {
    {0, "SLC_FUNC"},
    {1, "SLC_FLAGS"},
    {2, "SLC_VALUE"}
};

const defines_map arpa_telnet_slc_flags = {
    {0x80, "SLC_ACK"},
    {0x40, "SLC_FLUSHIN"},
    {0x20, "SLC_FLUSHOUT"}
};

const defines_map arpa_telnet_old_env = {
    {1, "OLD_ENV_VAR"},
    {0, "OLD_ENV_VALUE"},
    {2, "ENV_ESC"},
    {3, "ENV_USERVAR"}
};

const defines_map arpa_telnet_new_env = {
    {0, "NEW_ENV_VAR"},
    {1, "NEW_ENV_VALUE"},
    {2, "ENV_ESC"},
    {3, "ENV_USERVAR"}
};

const defines_map arpa_telnet_auth_who = {
    {0, "AUTH_WHO_CLIENT"},
    {1, "AUTH_WHO_SERVER"}
};

const defines_map arpa_telnet_auth_who_mask = {
    {1, "AUTH_WHO_MASK"}
};

const defines_map arpa_telnet_auth_how = {
    {0, "AUTH_HOW_ONE_WAY"},
    {2, "AUTH_HOW_MUTUAL"}
};

const defines_map arpa_telnet_authtype = {
    {0, "AUTHTYPE_NULL"},
    {1, "AUTHTYPE_KERBEROS_V4"},
    {2, "AUTHTYPE_KERBEROS_V5"},
    {3, "AUTHTYPE_SPX"},
    {4, "AUTHTYPE_MINK"},
    {5, "AUTHTYPE_CNT"},
    {99, "AUTHTYPE_TEST"}
};

const defines_map arpa_telnet_encrypt = {
    {0, "ENCRYPT_IS"},
    {1, "ENCRYPT_SUPPORT"},
    {2, "ENCRYPT_REPLY"},
    {3, "ENCRYPT_START"},
    {4, "ENCRYPT_END"},
    {5, "ENCRYPT_REQSTART"},
    {6, "ENCRYPT_REQEND"},
    {7, "ENCRYPT_ENC_KEYID"},
    {8, "ENCRYPT_DEC_KEYID"},
    {9, "ENCRYPT_CNT"}
};

const defines_map arpa_telnet_enctype = {
    {0, "ENCTYPE_ANY"},
    {1, "ENCTYPE_DES_CFB64"},
    {2, "ENCTYPE_DES_OFB64"},
    {3, "ENCTYPE_CNT"}
};

template <typename T>
std::string print_arpa_telnet_defs(const T v)
{
    return print_enum_entry(v, arpa_telnet_defs);
}

template <typename T>
std::string print_arpa_telnet_opts(const T v)
{
    return print_enum_entry(v, arpa_telnet_opts);
}

template <typename T>
std::string print_arpa_telnet_telqual(const T v)
{
    return print_enum_entry(v, arpa_telnet_telqual);
}

template <typename T>
std::string print_arpa_telnet_telqual_env(const T v)
{
    return print_enum_entry(v, arpa_telnet_telqual_env);
}

template <typename T>
std::string print_arpa_telnet_telqual_auth(const T v)
{
    return print_enum_entry(v, arpa_telnet_telqual_auth);
}

template <typename T>
std::string print_arpa_telnet_lflow(const T v)
{
    return print_enum_entry(v, arpa_telnet_lflow);
}

template <typename T>
std::string print_arpa_telnet_lm(const T v)
{
    return print_enum_entry(v, arpa_telnet_lm);
}

template <typename T>
std::string print_arpa_telnet_line_mode(const T v)
{
    return print_or_enum_entries(v, arpa_telnet_line_mode);
}

template <typename T>
std::string print_arpa_telnet_mode_mask(const T v)
{
    return print_enum_entry(v, arpa_telnet_mode_mask);
}

template <typename T>
std::string print_arpa_telnet_mode(const T v)
{
    return print_or_enum_entries(v, arpa_telnet_mode);
}

template <typename T>
std::string print_arpa_telnet_slc(const T v)
{
    return print_enum_entry(v, arpa_telnet_slc);
}

template <typename T>
std::string print_arpa_telnet_slc_level(const T v)
{
    return print_enum_entry(v, arpa_telnet_slc_level);
}

template <typename T>
std::string print_arpa_telnet_slc_entry(const T v)
{
    return print_enum_entry(v, arpa_telnet_slc_entry);
}

template <typename T>
std::string print_arpa_telnet_slc_flags(const T v)
{
    return print_or_enum_entries(v, arpa_telnet_slc_flags);
}

template <typename T>
std::string print_arpa_telnet_old_env(const T v)
{
    return print_enum_entry(v, arpa_telnet_old_env);
}

template <typename T>
std::string print_arpa_telnet_new_env(const T v)
{
    return print_enum_entry(v, arpa_telnet_new_env);
}

template <typename T>
std::string print_arpa_telnet_auth_who(const T v)
{
    return print_enum_entry(v, arpa_telnet_auth_who);
}

template <typename T>
std::string print_arpa_telnet_auth_who_mask(const T v)
{
    return print_enum_entry(v, arpa_telnet_auth_who_mask);
}

template <typename T>
std::string print_arpa_telnet_auth_how(const T v)
{
    return print_enum_entry(v, arpa_telnet_auth_how);
}

template <typename T>
std::string print_arpa_telnet_authtype(const T v)
{
    return print_enum_entry(v, arpa_telnet_authtype);
}

template <typename T>
std::string print_arpa_telnet_encrypt(const T v)
{
    return print_enum_entry(v, arpa_telnet_encrypt);
}

template <typename T>
std::string print_arpa_telnet_enctype(const T v)
{
    return print_enum_entry(v, arpa_telnet_enctype);
}

template <typename T>
std::string print_arpa_telnet_telqual_environ(const T v)
{
    return print_enum_entry(v, arpa_telnet_telqual, arpa_telnet_telqual_env);
}

template <typename T>
std::string print_arpa_telnet_telqual_authentication(const T v)
{
    return print_enum_entry(v, arpa_telnet_telqual, arpa_telnet_telqual_auth);
}

template <typename T>
std::string print_arpa_telnet_slc_level_flags(const T v)
{
    const auto level = print_enum_entry(v, arpa_telnet_slc_level);
    const auto flags = print_or_enum_entries(v, arpa_telnet_slc_flags);
    return level + (level.empty() || flags.empty() ? "" : " | ") + flags;
}
}

#endif //ABII_C_LOGGING_PLUGIN_ARPA_TELNET_H
