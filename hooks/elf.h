//
// Created by Trent Tanchin on 7/26/24.
//

#ifndef ABII_C_LOGGING_PLUGIN_ELF_H
#define ABII_C_LOGGING_PLUGIN_ELF_H

#include <elf.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map elf_ei = {
    {0, "EI_MAG0"},
    {1, "EI_MAG1"},
    {2, "EI_MAG2"},
    {3, "EI_MAG3"},
    {4, "EI_CLASS"},
    {5, "EI_DATA"},
    {6, "EI_VERSION"},
    {7, "EI_OSABI"},
    {8, "EI_ABIVERSION"},
    {9, "EI_PAD"}
};

const defines_map elf_elfmag0 = {
    {0x7f, "ELFMAG0"}
};

const defines_map elf_elfmag1 = {
    {'E', "ELFMAG1"}
};

const defines_map elf_elfmag2 = {
    {'L', "ELFMAG2"}
};

const defines_map elf_elfmag3 = {
    {'F', "ELFMAG3"}
};

const defines_map elf_elfclass = {
    {0, "ELFCLASSNONE"},
    {1, "ELFCLASS32"},
    {2, "ELFCLASS64"},
    {3, "ELFCLASSNUM"}
};

const defines_map elf_elfdata = {
    {0, "ELFDATANONE"},
    {1, "ELFDATA2LSB"},
    {2, "ELFDATA2MSB"},
    {3, "ELFDATANUM"}
};

const defines_map elf_ev_current = {
    {1, "EV_CURRENT"}
};

const defines_map elf_elfosabi = {
    {0, "ELFOSABI_NONE"},
    {0, "ELFOSABI_SYSV"},
    {1, "ELFOSABI_HPUX"},
    {2, "ELFOSABI_NETBSD"},
    {3, "ELFOSABI_GNU"},
    {3, "ELFOSABI_LINUX"},
    {6, "ELFOSABI_SOLARIS"},
    {7, "ELFOSABI_AIX"},
    {8, "ELFOSABI_IRIX"},
    {9, "ELFOSABI_FREEBSD"},
    {10, "ELFOSABI_TRU64"},
    {11, "ELFOSABI_MODESTO"},
    {12, "ELFOSABI_OPENBSD"},
    {64, "ELFOSABI_ARM_AEABI"},
    {97, "ELFOSABI_ARM"},
    {255, "ELFOSABI_STANDALONE"}
};

const defines_map elf_et = {
    {0, "ET_NONE"},
    {1, "ET_REL"},
    {2, "ET_EXEC"},
    {3, "ET_DYN"},
    {4, "ET_CORE"},
    {5, "ET_NUM"},
    {0xfe00, "ET_LOOS"},
    {0xfeff, "ET_HIOS"},
    {0xff00, "ET_LOPROC"},
    {0xffff, "ET_HIPROC"}
};

const defines_map elf_em = {
    {0, "EM_NONE"},
    {1, "EM_M32"},
    {2, "EM_SPARC"},
    {3, "EM_386"},
    {4, "EM_68K"},
    {5, "EM_88K"},
    {6, "EM_IAMCU"},
    {7, "EM_860"},
    {8, "EM_MIPS"},
    {9, "EM_S370"},
    {10, "EM_MIPS_RS3_LE"},
    {15, "EM_PARISC"},
    {17, "EM_VPP500"},
    {18, "EM_SPARC32PLUS"},
    {19, "EM_960"},
    {20, "EM_PPC"},
    {21, "EM_PPC64"},
    {22, "EM_S390"},
    {23, "EM_SPU"},
    {36, "EM_V800"},
    {37, "EM_FR20"},
    {38, "EM_RH32"},
    {39, "EM_RCE"},
    {40, "EM_ARM"},
    {41, "EM_FAKE_ALPHA"},
    {42, "EM_SH"},
    {43, "EM_SPARCV9"},
    {44, "EM_TRICORE"},
    {45, "EM_ARC"},
    {46, "EM_H8_300"},
    {47, "EM_H8_300H"},
    {48, "EM_H8S"},
    {50, "EM_IA_64"},
    {51, "EM_MIPS_X"},
    {52, "EM_COLDFIRE"},
    {53, "EM_68HC12"},
    {54, "EM_MMA"},
    {55, "EM_PCP"},
    {56, "EM_NCPU"},
    {57, "EM_NDR1"},
    {58, "EM_STARCORE"},
    {59, "EM_ME16"},
    {60, "EM_ST100"},
    {61, "EM_TINYJ"},
    {62, "EM_X86_64"},
    {63, "EM_PDSP"},
    {64, "EM_PDP10"},
    {65, "EM_PDP11"},
    {66, "EM_FX66"},
    {67, "EM_ST9PLUS"},
    {68, "EM_ST7"},
    {69, "EM_68HC16"},
    {70, "EM_68HC11"},
    {71, "EM_68HC08"},
    {72, "EM_68HC05"},
    {73, "EM_SVX"},
    {74, "EM_ST19"},
    {75, "EM_VAX"},
    {76, "EM_CRIS"},
    {77, "EM_JAVELIN"},
    {78, "EM_FIREPATH"},
    {79, "EM_ZSP"},
    {80, "EM_MMIX"},
    {81, "EM_HUANY"},
    {82, "EM_PRISM"},
    {83, "EM_AVR"},
    {84, "EM_FR30"},
    {85, "EM_D10V"},
    {86, "EM_D30V"},
    {87, "EM_V850"},
    {88, "EM_M32R"},
    {89, "EM_MN10300"},
    {90, "EM_MN10200"},
    {91, "EM_PJ"},
    {92, "EM_OPENRISC"},
    {93, "EM_ARC_COMPACT"},
    {94, "EM_XTENSA"},
    {95, "EM_VIDEOCORE"},
    {96, "EM_TMM_GPP"},
    {97, "EM_NS32K"},
    {98, "EM_TPC"},
    {99, "EM_SNP1K"},
    {100, "EM_ST200"},
    {101, "EM_IP2K"},
    {102, "EM_MAX"},
    {103, "EM_CR"},
    {104, "EM_F2MC16"},
    {105, "EM_MSP430"},
    {106, "EM_BLACKFIN"},
    {107, "EM_SE_C33"},
    {108, "EM_SEP"},
    {109, "EM_ARCA"},
    {110, "EM_UNICORE"},
    {111, "EM_EXCESS"},
    {112, "EM_DXP"},
    {113, "EM_ALTERA_NIOS2"},
    {114, "EM_CRX"},
    {115, "EM_XGATE"},
    {116, "EM_C166"},
    {117, "EM_M16C"},
    {118, "EM_DSPIC30F"},
    {119, "EM_CE"},
    {120, "EM_M32C"},
    {131, "EM_TSK3000"},
    {132, "EM_RS08"},
    {133, "EM_SHARC"},
    {134, "EM_ECOG2"},
    {135, "EM_SCORE7"},
    {136, "EM_DSP24"},
    {137, "EM_VIDEOCORE3"},
    {138, "EM_LATTICEMICO32"},
    {139, "EM_SE_C17"},
    {140, "EM_TI_C6000"},
    {141, "EM_TI_C2000"},
    {142, "EM_TI_C5500"},
    {143, "EM_TI_ARP32"},
    {144, "EM_TI_PRU"},
    {160, "EM_MMDSP_PLUS"},
    {161, "EM_CYPRESS_M8C"},
    {162, "EM_R32C"},
    {163, "EM_TRIMEDIA"},
    {164, "EM_QDSP6"},
    {165, "EM_8051"},
    {166, "EM_STXP7X"},
    {167, "EM_NDS32"},
    {168, "EM_ECOG1X"},
    {169, "EM_MAXQ30"},
    {170, "EM_XIMO16"},
    {171, "EM_MANIK"},
    {172, "EM_CRAYNV2"},
    {173, "EM_RX"},
    {174, "EM_METAG"},
    {175, "EM_MCST_ELBRUS"},
    {176, "EM_ECOG16"},
    {177, "EM_CR16"},
    {178, "EM_ETPU"},
    {179, "EM_SLE9X"},
    {180, "EM_L10M"},
    {181, "EM_K10M"},
    {183, "EM_AARCH64"},
    {185, "EM_AVR32"},
    {186, "EM_STM8"},
    {187, "EM_TILE64"},
    {188, "EM_TILEPRO"},
    {189, "EM_MICROBLAZE"},
    {190, "EM_CUDA"},
    {191, "EM_TILEGX"},
    {192, "EM_CLOUDSHIELD"},
    {193, "EM_COREA_1ST"},
    {194, "EM_COREA_2ND"},
    {195, "EM_ARCV2"},
    {196, "EM_OPEN8"},
    {197, "EM_RL78"},
    {198, "EM_VIDEOCORE5"},
    {199, "EM_78KOR"},
    {200, "EM_56800EX"},
    {201, "EM_BA1"},
    {202, "EM_BA2"},
    {203, "EM_XCORE"},
    {204, "EM_MCHP_PIC"},
    {205, "EM_INTELGT"},
    {210, "EM_KM32"},
    {211, "EM_KMX32"},
    {212, "EM_EMX16"},
    {213, "EM_EMX8"},
    {214, "EM_KVARC"},
    {215, "EM_CDP"},
    {216, "EM_COGE"},
    {217, "EM_COOL"},
    {218, "EM_NORC"},
    {219, "EM_CSR_KALIMBA"},
    {220, "EM_Z80"},
    {221, "EM_VISIUM"},
    {222, "EM_FT32"},
    {223, "EM_MOXIE"},
    {224, "EM_AMDGPU"},
    {243, "EM_RISCV"},
    {247, "EM_BPF"},
    {252, "EM_CSKY"},
    {258, "EM_LOONGARCH"},
    {259, "EM_NUM"},
    {93, "EM_ARC_A5"},
    {0x9026, "EM_ALPHA"}
};

const defines_map elf_ev = {
    {0, "EV_NONE"},
    {1, "EV_CURRENT"},
    {2, "EV_NUM"}
};

const defines_map elf_shn = {
    {0, "SHN_UNDEF"},
    {0xff00, "SHN_LORESERVE"},
    {0xff00, "SHN_LOPROC"},
    {0xff00, "SHN_BEFORE"},
    {0xff01, "SHN_AFTER"},
    {0xff1f, "SHN_HIPROC"},
    {0xff20, "SHN_LOOS"},
    {0xff3f, "SHN_HIOS"},
    {0xfff1, "SHN_ABS"},
    {0xfff2, "SHN_COMMON"},
    {0xffff, "SHN_XINDEX"},
    {0xffff, "SHN_HIRESERVE"}
};

const defines_map elf_sht = {
    {0, "SHT_NULL"},
    {1, "SHT_PROGBITS"},
    {2, "SHT_SYMTAB"},
    {3, "SHT_STRTAB"},
    {4, "SHT_RELA"},
    {5, "SHT_HASH"},
    {6, "SHT_DYNAMIC"},
    {7, "SHT_NOTE"},
    {8, "SHT_NOBITS"},
    {9, "SHT_REL"},
    {10, "SHT_SHLIB"},
    {11, "SHT_DYNSYM"},
    {14, "SHT_INIT_ARRAY"},
    {15, "SHT_FINI_ARRAY"},
    {16, "SHT_PREINIT_ARRAY"},
    {17, "SHT_GROUP"},
    {18, "SHT_SYMTAB_SHNDX"},
    {19, "SHT_RELR"},
    {20, "SHT_NUM"},
    {0x60000000, "SHT_LOOS"},
    {0x6ffffff5, "SHT_GNU_ATTRIBUTES"},
    {0x6ffffff6, "SHT_GNU_HASH"},
    {0x6ffffff7, "SHT_GNU_LIBLIST"},
    {0x6ffffff8, "SHT_CHECKSUM"},
    {0x6ffffffa, "SHT_LOSUNW"},
    {0x6ffffffa, "SHT_SUNW_move"},
    {0x6ffffffb, "SHT_SUNW_COMDAT"},
    {0x6ffffffc, "SHT_SUNW_syminfo"},
    {0x6ffffffd, "SHT_GNU_verdef"},
    {0x6ffffffe, "SHT_GNU_verneed"},
    {0x6fffffff, "SHT_GNU_versym"},
    {0x6fffffff, "SHT_HISUNW"},
    {0x6fffffff, "SHT_HIOS"},
    {0x70000000, "SHT_LOPROC"},
    {0x7fffffff, "SHT_HIPROC"},
    {0x80000000, "SHT_LOUSER"},
    {0x8fffffff, "SHT_HIUSER"}
};

const defines_map elf_shf = {
    {(1 << 0), "SHF_WRITE"},
    {(1 << 1), "SHF_ALLOC"},
    {(1 << 2), "SHF_EXECINSTR"},
    {(1 << 4), "SHF_MERGE"},
    {(1 << 5), "SHF_STRINGS"},
    {(1 << 6), "SHF_INFO_LINK"},
    {(1 << 7), "SHF_LINK_ORDER"},
    {(1 << 8), "SHF_OS_NONCONFORMING"},
    {(1 << 9), "SHF_GROUP"},
    {(1 << 10), "SHF_TLS"},
    {(1 << 11), "SHF_COMPRESSED"},
    {0x0ff00000, "SHF_MASKOS"},
    {0xf0000000, "SHF_MASKPROC"},
    {(1 << 21), "SHF_GNU_RETAIN"},
    {(1 << 30), "SHF_ORDERED"},
    {(1U << 31), "SHF_EXCLUDE"}
};

const defines_map elf_elfcompress = {
    {1, "ELFCOMPRESS_ZLIB"},
    {2, "ELFCOMPRESS_ZSTD"},
    {0x60000000, "ELFCOMPRESS_LOOS"},
    {0x6fffffff, "ELFCOMPRESS_HIOS"},
    {0x70000000, "ELFCOMPRESS_LOPROC"},
    {0x7fffffff, "ELFCOMPRESS_HIPROC"}
};

const defines_map elf_syminfo_bt = {
    {0xffff, "SYMINFO_BT_SELF"},
    {0xfffe, "SYMINFO_BT_PARENT"},
    {0xff00, "SYMINFO_BT_LOWRESERVE"}
};

const defines_map elf_syminfo_flg = {
    {0x0001, "SYMINFO_FLG_DIRECT"},
    {0x0002, "SYMINFO_FLG_PASSTHRU"},
    {0x0004, "SYMINFO_FLG_COPY"},
    {0x0008, "SYMINFO_FLG_LAZYLOAD"}
};

const defines_map elf_stb = {
    {0, "STB_LOCAL"},
    {1, "STB_GLOBAL"},
    {2, "STB_WEAK"},
    {3, "STB_NUM"},
    {10, "STB_LOOS"},
    {10, "STB_GNU_UNIQUE"},
    {12, "STB_HIOS"},
    {13, "STB_LOPROC"},
    {15, "STB_HIPROC"}
};

const defines_map elf_stt = {
    {0, "STT_NOTYPE"},
    {1, "STT_OBJECT"},
    {2, "STT_FUNC"},
    {3, "STT_SECTION"},
    {4, "STT_FILE"},
    {5, "STT_COMMON"},
    {6, "STT_TLS"},
    {7, "STT_NUM"},
    {10, "STT_LOOS"},
    {10, "STT_GNU_IFUNC"},
    {12, "STT_HIOS"},
    {13, "STT_LOPROC"},
    {15, "STT_HIPROC"}
};

const defines_map elf_stv = {
    {0, "STV_DEFAULT"},
    {1, "STV_INTERNAL"},
    {2, "STV_HIDDEN"},
    {3, "STV_PROTECTED"}
};

const defines_map elf_pn = {
    {0xffff, "PN_XNUM"}
};

const defines_map elf_pt = {
    {0, "PT_NULL"},
    {1, "PT_LOAD"},
    {2, "PT_DYNAMIC"},
    {3, "PT_INTERP"},
    {4, "PT_NOTE"},
    {5, "PT_SHLIB"},
    {6, "PT_PHDR"},
    {7, "PT_TLS"},
    {8, "PT_NUM"},
    {0x60000000, "PT_LOOS"},
    {0x6474e550, "PT_GNU_EH_FRAME"},
    {0x6474e551, "PT_GNU_STACK"},
    {0x6474e552, "PT_GNU_RELRO"},
    {0x6474e553, "PT_GNU_PROPERTY"},
    {0x6474e554, "PT_GNU_SFRAME"},
    {0x6ffffffa, "PT_LOSUNW"},
    {0x6ffffffa, "PT_SUNWBSS"},
    {0x6ffffffb, "PT_SUNWSTACK"},
    {0x6fffffff, "PT_HISUNW"},
    {0x6fffffff, "PT_HIOS"},
    {0x70000000, "PT_LOPROC"},
    {0x7fffffff, "PT_HIPROC"}
};

const defines_map elf_pf = {
    {(1 << 0), "PF_X"},
    {(1 << 1), "PF_W"},
    {(1 << 2), "PF_R"},
    {0x0ff00000, "PF_MASKOS"},
    {0xf0000000, "PF_MASKPROC"}
};

const defines_map elf_nt = {
    {1, "NT_PRSTATUS"},
    {2, "NT_PRFPREG"},
    {2, "NT_FPREGSET"},
    {3, "NT_PRPSINFO"},
    {4, "NT_PRXREG"},
    {4, "NT_TASKSTRUCT"},
    {5, "NT_PLATFORM"},
    {6, "NT_AUXV"},
    {7, "NT_GWINDOWS"},
    {8, "NT_ASRS"},
    {10, "NT_PSTATUS"},
    {13, "NT_PSINFO"},
    {14, "NT_PRCRED"},
    {15, "NT_UTSNAME"},
    {16, "NT_LWPSTATUS"},
    {17, "NT_LWPSINFO"},
    {20, "NT_PRFPXREG"},
    {0x53494749, "NT_SIGINFO"},
    {0x46494c45, "NT_FILE"},
    {0x46e62b7f, "NT_PRXFPREG"},
    {0x100, "NT_PPC_VMX"},
    {0x101, "NT_PPC_SPE"},
    {0x102, "NT_PPC_VSX"},
    {0x103, "NT_PPC_TAR"},
    {0x104, "NT_PPC_PPR"},
    {0x105, "NT_PPC_DSCR"},
    {0x106, "NT_PPC_EBB"},
    {0x107, "NT_PPC_PMU"},
    {0x108, "NT_PPC_TM_CGPR"},
    {0x109, "NT_PPC_TM_CFPR"},
    {0x10a, "NT_PPC_TM_CVMX"},
    {0x10b, "NT_PPC_TM_CVSX"},
    {0x10c, "NT_PPC_TM_SPR"},
    {0x10d, "NT_PPC_TM_CTAR"},
    {0x10e, "NT_PPC_TM_CPPR"},
    {0x10f, "NT_PPC_TM_CDSCR"},
    {0x110, "NT_PPC_PKEY"},
    {0x111, "NT_PPC_DEXCR"},
    {0x112, "NT_PPC_HASHKEYR"},
    {0x200, "NT_386_TLS"},
    {0x201, "NT_386_IOPERM"},
    {0x202, "NT_X86_XSTATE"},
    {0x204, "NT_X86_SHSTK"},
    {0x205, "NT_X86_XSAVE_LAYOUT"},
    {0x300, "NT_S390_HIGH_GPRS"},
    {0x302, "NT_S390_TODCMP"},
    {0x303, "NT_S390_TODPREG"},
    {0x304, "NT_S390_CTRS"},
    {0x305, "NT_S390_PREFIX"},
    {0x306, "NT_S390_LAST_BREAK"},
    {0x307, "NT_S390_SYSTEM_CALL"},
    {0x308, "NT_S390_TDB"},
    {0x309, "NT_S390_VXRS_LOW"},
    {0x30a, "NT_S390_VXRS_HIGH"},
    {0x30b, "NT_S390_GS_CB"},
    {0x30c, "NT_S390_GS_BC"},
    {0x30d, "NT_S390_RI_CB"},
    {0x30e, "NT_S390_PV_CPU_DATA"},
    {0x400, "NT_ARM_VFP"},
    {0x401, "NT_ARM_TLS"},
    {0x402, "NT_ARM_HW_BREAK"},
    {0x403, "NT_ARM_HW_WATCH"},
    {0x404, "NT_ARM_SYSTEM_CALL"},
    {0x405, "NT_ARM_SVE"},
    {0x406, "NT_ARM_PAC_MASK"},
    {0x407, "NT_ARM_PACA_KEYS"},
    {0x408, "NT_ARM_PACG_KEYS"},
    {0x409, "NT_ARM_TAGGED_ADDR_CTRL"},
    {0x40a, "NT_ARM_PAC_ENABLED_KEYS"},
    {0x40b, "NT_ARM_SSVE"},
    {0x40c, "NT_ARM_ZA"},
    {0x40d, "NT_ARM_ZT"},
    {0x40e, "NT_ARM_FPMR"},
    {0x40f, "NT_ARM_POE"},
    {0x700, "NT_VMCOREDD"},
    {0x800, "NT_MIPS_DSP"},
    {0x800, "NT_MIPS_DSP"},
    {0x801, "NT_MIPS_FP_MODE"},
    {0x802, "NT_MIPS_MSA"},
    {0x900, "NT_RISCV_CSR"},
    {0x901, "NT_RISCV_VECTOR"},
    {0xa00, "NT_LOONGARCH_CPUCFG"},
    {0xa01, "NT_LOONGARCH_CSR"},
    {0xa02, "NT_LOONGARCH_LSX"},
    {0xa03, "NT_LOONGARCH_LASX"},
    {0xa04, "NT_LOONGARCH_LBT"},
    {0xa05, "NT_LOONGARCH_HW_BREAK"},
    {0xa06, "NT_LOONGARCH_HW_WATCH"}
};

const defines_map elf_nt_version = {
    {1, "NT_VERSION"}
};

const defines_map elf_dt = {
    {0, "DT_NULL"},
    {1, "DT_NEEDED"},
    {2, "DT_PLTRELSZ"},
    {3, "DT_PLTGOT"},
    {4, "DT_HASH"},
    {5, "DT_STRTAB"},
    {6, "DT_SYMTAB"},
    {8, "DT_RELASZ"},
    {9, "DT_RELAENT"},
    {10, "DT_STRSZ"},
    {11, "DT_SYMENT"},
    {12, "DT_INIT"},
    {13, "DT_FINI"},
    {14, "DT_SONAME"},
    {15, "DT_RPATH"},
    {16, "DT_SYMBOLIC"},
    {17, "DT_REL"},
    {18, "DT_RELSZ"},
    {19, "DT_RELENT"},
    {20, "DT_PLTREL"},
    {21, "DT_DEBUG"},
    {22, "DT_TEXTREL"},
    {23, "DT_JMPREL"},
    {24, "DT_BIND_NOW"},
    {25, "DT_INIT_ARRAY"},
    {26, "DT_FINI_ARRAY"},
    {27, "DT_INIT_ARRAYSZ"},
    {28, "DT_FINI_ARRAYSZ"},
    {29, "DT_RUNPATH"},
    {30, "DT_FLAGS"},
    {32, "DT_ENCODING"},
    {32, "DT_PREINIT_ARRAY"},
    {33, "DT_PREINIT_ARRAYSZ"},
    {34, "DT_SYMTAB_SHNDX"},
    {35, "DT_RELRSZ"},
    {36, "DT_RELR"},
    {37, "DT_RELRENT"},
    {38, "DT_NUM"},
    {0x6000000d, "DT_LOOS"},
    {0x6ffff000, "DT_HIOS"},
    {0x70000000, "DT_LOPROC"},
    {0x7fffffff, "DT_HIPROC"},
    {0x37, "DT_PROCNUM"},
    {0x6ffffd00, "DT_VALRNGLO"},
    {0x6ffffdf5, "DT_GNU_PRELINKED"},
    {0x6ffffdf6, "DT_GNU_CONFLICTSZ"},
    {0x6ffffdf7, "DT_GNU_LIBLISTSZ"},
    {0x6ffffdf8, "DT_CHECKSUM"},
    {0x6ffffdf9, "DT_PLTPADSZ"},
    {0x6ffffdfa, "DT_MOVEENT"},
    {0x6ffffdfb, "DT_MOVESZ"},
    {0x6ffffdfc, "DT_FEATURE_1"},
    {0x6ffffdfd, "DT_POSFLAG_1"},
    {0x6ffffdfe, "DT_SYMINSZ"},
    {0x6ffffdff, "DT_SYMINENT"},
    {0x6ffffdff, "DT_VALRNGHI"},
    {12, "DT_VALNUM"},
    {0x6ffffe00, "DT_ADDRRNGLO"},
    {0x6ffffef5, "DT_GNU_HASH"},
    {0x6ffffef6, "DT_TLSDESC_PLT"},
    {0x6ffffef7, "DT_TLSDESC_GOT"},
    {0x6ffffef8, "DT_GNU_CONFLICT"},
    {0x6ffffef9, "DT_GNU_LIBLIST"},
    {0x6ffffefa, "DT_CONFIG"},
    {0x6ffffefb, "DT_DEPAUDIT"},
    {0x6ffffefc, "DT_AUDIT"},
    {0x6ffffefd, "DT_PLTPAD"},
    {0x6ffffefe, "DT_MOVETAB"},
    {0x6ffffeff, "DT_SYMINFO"},
    {0x6ffffeff, "DT_ADDRRNGHI"},
    {11, "DT_ADDRNUM"},
    {0x6ffffff0, "DT_VERSYM"},
    {0x6ffffff9, "DT_RELACOUNT"},
    {0x6ffffffa, "DT_RELCOUNT"},
    {0x6ffffffb, "DT_FLAGS_1"},
    {0x6ffffffc, "DT_VERDEF"},
    {0x6ffffffd, "DT_VERDEFNUM"},
    {0x6ffffffe, "DT_VERNEED"},
    {0x6fffffff, "DT_VERNEEDNUM"},
    {16, "DT_VERSIONTAGNUM"},
    {0x7ffffffd, "DT_AUXILIARY"},
    {0x7fffffff, "DT_FILTER"},
    {3, "DT_EXTRANUM"}
};

const defines_map elf_df = {
    {0x00000001, "DF_ORIGIN"},
    {0x00000002, "DF_SYMBOLIC"},
    {0x00000004, "DF_TEXTREL"},
    {0x00000008, "DF_BIND_NOW"},
    {0x00000010, "DF_STATIC_TLS"}
};

const defines_map elf_df_1 = {
    {0x00000001, "DF_1_NOW"},
    {0x00000002, "DF_1_GLOBAL"},
    {0x00000004, "DF_1_GROUP"},
    {0x00000008, "DF_1_NODELETE"},
    {0x00000010, "DF_1_LOADFLTR"},
    {0x00000020, "DF_1_INITFIRST"},
    {0x00000040, "DF_1_NOOPEN"},
    {0x00000080, "DF_1_ORIGIN"},
    {0x00000100, "DF_1_DIRECT"},
    {0x00000200, "DF_1_TRANS"},
    {0x00000400, "DF_1_INTERPOSE"},
    {0x00000800, "DF_1_NODEFLIB"},
    {0x00001000, "DF_1_NODUMP"},
    {0x00002000, "DF_1_CONFALT"},
    {0x00004000, "DF_1_ENDFILTEE"},
    {0x00008000, "DF_1_DISPRELDNE"},
    {0x00010000, "DF_1_DISPRELPND"},
    {0x00020000, "DF_1_NODIRECT"},
    {0x00040000, "DF_1_IGNMULDEF"},
    {0x00080000, "DF_1_NOKSYMS"},
    {0x00100000, "DF_1_NOHDR"},
    {0x00200000, "DF_1_EDITED"},
    {0x00400000, "DF_1_NORELOC"},
    {0x00800000, "DF_1_SYMINTPOSE"},
    {0x01000000, "DF_1_GLOBAUDIT"},
    {0x02000000, "DF_1_SINGLETON"},
    {0x04000000, "DF_1_STUB"},
    {0x08000000, "DF_1_PIE"},
    {0x10000000, "DF_1_KMOD"},
    {0x20000000, "DF_1_WEAKFILTER"},
    {0x40000000, "DF_1_NOCOMMON"}
};

const defines_map elf_dtf_1 = {
    {0x00000001, "DTF_1_PARINIT"},
    {0x00000002, "DTF_1_CONFEXP"}
};

const defines_map elf_df_p1 = {
    {0x00000001, "DF_P1_LAZYLOAD"},
    {0x00000002, "DF_P1_GROUPPERM"}
};

const defines_map elf_ver_def = {
    {0, "VER_DEF_NONE"},
    {1, "VER_DEF_CURRENT"},
    {2, "VER_DEF_NUM"}
};

const defines_map elf_ver_flg = {
    {0x1, "VER_FLG_BASE"},
    {0x2, "VER_FLG_WEAK"}
};

const defines_map elf_ver_ndx = {
    {0, "VER_NDX_LOCAL"},
    {1, "VER_NDX_GLOBAL"},
    {0xff00, "VER_NDX_LORESERVE"},
    {0xff01, "VER_NDX_ELIMINATE"}
};

const defines_map elf_ver_need = {
    {0, "VER_NEED_NONE"},
    {1, "VER_NEED_CURRENT"},
    {2, "VER_NEED_NUM"}
};

const defines_map elf_at = {
    {0, "AT_NULL"},
    {1, "AT_IGNORE"},
    {2, "AT_EXECFD"},
    {3, "AT_PHDR"},
    {4, "AT_PHENT"},
    {5, "AT_PHNUM"},
    {6, "AT_PAGESZ"},
    {7, "AT_BASE"},
    {8, "AT_FLAGS"},
    {9, "AT_ENTRY"},
    {10, "AT_NOTELF"},
    {11, "AT_UID"},
    {12, "AT_EUID"},
    {13, "AT_GID"},
    {14, "AT_EGID"},
    {17, "AT_CLKTCK"},
    {15, "AT_PLATFORM"},
    {16, "AT_HWCAP"},
    {18, "AT_FPUCW"},
    {19, "AT_DCACHEBSIZE"},
    {20, "AT_ICACHEBSIZE"},
    {21, "AT_UCACHEBSIZE"},
    {22, "AT_IGNOREPPC"},
    {23, "AT_SECURE"},
    {24, "AT_BASE_PLATFORM"},
    {25, "AT_RANDOM"},
    {26, "AT_HWCAP2"},
    {27, "AT_RSEQ_FEATURE_SIZE"},
    {28, "AT_RSEQ_ALIGN"},
    {29, "AT_HWCAP3"},
    {30, "AT_HWCAP4"},
    {31, "AT_EXECFN"},
    {32, "AT_SYSINFO"},
    {33, "AT_SYSINFO_EHDR"},
    {34, "AT_L1I_CACHESHAPE"},
    {35, "AT_L1D_CACHESHAPE"},
    {36, "AT_L2_CACHESHAPE"},
    {37, "AT_L3_CACHESHAPE"},
    {40, "AT_L1I_CACHESIZE"},
    {41, "AT_L1I_CACHEGEOMETRY"},
    {42, "AT_L1D_CACHESIZE"},
    {43, "AT_L1D_CACHEGEOMETRY"},
    {44, "AT_L2_CACHESIZE"},
    {45, "AT_L2_CACHEGEOMETRY"},
    {46, "AT_L3_CACHESIZE"},
    {47, "AT_L3_CACHEGEOMETRY"},
    {51, "AT_MINSIGSTKSZ"}
};

const defines_map elf_elf_note_pagesize_hint = {
    {1, "ELF_NOTE_PAGESIZE_HINT"}
};

const defines_map elf_nt_gnu = {
    {1, "NT_GNU_ABI_TAG"},
    {1, "ELF_NOTE_ABI"},
    {2, "NT_GNU_HWCAP"},
    {3, "NT_GNU_BUILD_ID"},
    {4, "NT_GNU_GOLD_VERSION"},
    {5, "NT_GNU_PROPERTY_TYPE_0"},
    {0xcafe1a7e, "NT_FDO_PACKAGING_METADATA"},
    {0x407c0c0a, "NT_FDO_DLOPEN_METADATA"}
};

const defines_map elf_elf_note_os = {
    {0, "ELF_NOTE_OS_LINUX"},
    {1, "ELF_NOTE_OS_GNU"},
    {2, "ELF_NOTE_OS_SOLARIS2"},
    {3, "ELF_NOTE_OS_FREEBSD"}
};

const defines_map elf_ef_cpu32 = {
    {0x00810000, "EF_CPU32"}
};

const defines_map elf_r_68k = {
    {0, "R_68K_NONE"},
    {1, "R_68K_32"},
    {2, "R_68K_16"},
    {3, "R_68K_8"},
    {4, "R_68K_PC32"},
    {5, "R_68K_PC16"},
    {6, "R_68K_PC8"},
    {7, "R_68K_GOT32"},
    {8, "R_68K_GOT16"},
    {9, "R_68K_GOT8"},
    {10, "R_68K_GOT32O"},
    {11, "R_68K_GOT16O"},
    {12, "R_68K_GOT8O"},
    {13, "R_68K_PLT32"},
    {14, "R_68K_PLT16"},
    {15, "R_68K_PLT8"},
    {16, "R_68K_PLT32O"},
    {17, "R_68K_PLT16O"},
    {18, "R_68K_PLT8O"},
    {19, "R_68K_COPY"},
    {20, "R_68K_GLOB_DAT"},
    {21, "R_68K_JMP_SLOT"},
    {22, "R_68K_RELATIVE"},
    {25, "R_68K_TLS_GD32"},
    {26, "R_68K_TLS_GD16"},
    {27, "R_68K_TLS_GD8"},
    {28, "R_68K_TLS_LDM32"},
    {29, "R_68K_TLS_LDM16"},
    {30, "R_68K_TLS_LDM8"},
    {31, "R_68K_TLS_LDO32"},
    {32, "R_68K_TLS_LDO16"},
    {33, "R_68K_TLS_LDO8"},
    {34, "R_68K_TLS_IE32"},
    {35, "R_68K_TLS_IE16"},
    {36, "R_68K_TLS_IE8"},
    {37, "R_68K_TLS_LE32"},
    {38, "R_68K_TLS_LE16"},
    {39, "R_68K_TLS_LE8"},
    {40, "R_68K_TLS_DTPMOD32"},
    {41, "R_68K_TLS_DTPREL32"},
    {42, "R_68K_TLS_TPREL32"},
    {43, "R_68K_NUM"}
};

const defines_map elf_r_386 = {
    {0, "R_386_NONE"},
    {1, "R_386_32"},
    {2, "R_386_PC32"},
    {3, "R_386_GOT32"},
    {4, "R_386_PLT32"},
    {5, "R_386_COPY"},
    {6, "R_386_GLOB_DAT"},
    {7, "R_386_JMP_SLOT"},
    {8, "R_386_RELATIVE"},
    {9, "R_386_GOTOFF"},
    {10, "R_386_GOTPC"},
    {11, "R_386_32PLT"},
    {14, "R_386_TLS_TPOFF"},
    {15, "R_386_TLS_IE"},
    {16, "R_386_TLS_GOTIE"},
    {17, "R_386_TLS_LE"},
    {18, "R_386_TLS_GD"},
    {19, "R_386_TLS_LDM"},
    {20, "R_386_16"},
    {21, "R_386_PC16"},
    {22, "R_386_8"},
    {23, "R_386_PC8"},
    {24, "R_386_TLS_GD_32"},
    {25, "R_386_TLS_GD_PUSH"},
    {26, "R_386_TLS_GD_CALL"},
    {27, "R_386_TLS_GD_POP"},
    {28, "R_386_TLS_LDM_32"},
    {29, "R_386_TLS_LDM_PUSH"},
    {30, "R_386_TLS_LDM_CALL"},
    {31, "R_386_TLS_LDM_POP"},
    {32, "R_386_TLS_LDO_32"},
    {33, "R_386_TLS_IE_32"},
    {34, "R_386_TLS_LE_32"},
    {35, "R_386_TLS_DTPMOD32"},
    {36, "R_386_TLS_DTPOFF32"},
    {37, "R_386_TLS_TPOFF32"},
    {38, "R_386_SIZE32"},
    {39, "R_386_TLS_GOTDESC"},
    {40, "R_386_TLS_DESC_CALL"},
    {41, "R_386_TLS_DESC"},
    {42, "R_386_IRELATIVE"},
    {43, "R_386_GOT32X"},
    {44, "R_386_NUM"}
};

const defines_map elf_stt_sparc_register = {
    {13, "STT_SPARC_REGISTER"}
};

const defines_map elf_ef_sparc = {
    {3, "EF_SPARCV9_MM"},
    {0, "EF_SPARCV9_TSO"},
    {1, "EF_SPARCV9_PSO"},
    {2, "EF_SPARCV9_RMO"},
    {0x800000, "EF_SPARC_LEDATA"},
    {0xFFFF00, "EF_SPARC_EXT_MASK"},
    {0x000100, "EF_SPARC_32PLUS"},
    {0x000200, "EF_SPARC_SUN_US1"},
    {0x000400, "EF_SPARC_HAL_R1"},
    {0x000800, "EF_SPARC_SUN_US3"}
};

const defines_map elf_r_sparc32 = {
    {0, "R_SPARC_NONE"},
    {1, "R_SPARC_8"},
    {2, "R_SPARC_16"},
    {3, "R_SPARC_32"},
    {4, "R_SPARC_DISP8"},
    {5, "R_SPARC_DISP16"},
    {6, "R_SPARC_DISP32"},
    {7, "R_SPARC_WDISP30"},
    {8, "R_SPARC_WDISP22"},
    {9, "R_SPARC_HI22"},
    {10, "R_SPARC_22"},
    {11, "R_SPARC_13"},
    {12, "R_SPARC_LO10"},
    {13, "R_SPARC_GOT10"},
    {14, "R_SPARC_GOT13"},
    {15, "R_SPARC_GOT22"},
    {16, "R_SPARC_PC10"},
    {17, "R_SPARC_PC22"},
    {18, "R_SPARC_WPLT30"},
    {19, "R_SPARC_COPY"},
    {20, "R_SPARC_GLOB_DAT"},
    {21, "R_SPARC_JMP_SLOT"},
    {22, "R_SPARC_RELATIVE"},
    {23, "R_SPARC_UA32"}
};

const defines_map elf_sparc64 = {
    {24, "R_SPARC_PLT32"},
    {25, "R_SPARC_HIPLT22"},
    {26, "R_SPARC_LOPLT10"},
    {27, "R_SPARC_PCPLT32"},
    {28, "R_SPARC_PCPLT22"},
    {29, "R_SPARC_PCPLT10"},
    {30, "R_SPARC_10"},
    {31, "R_SPARC_11"},
    {32, "R_SPARC_64"},
    {33, "R_SPARC_OLO10"},
    {34, "R_SPARC_HH22"},
    {35, "R_SPARC_HM10"},
    {36, "R_SPARC_LM22"},
    {37, "R_SPARC_PC_HH22"},
    {38, "R_SPARC_PC_HM10"},
    {39, "R_SPARC_PC_LM22"},
    {40, "R_SPARC_WDISP16"},
    {41, "R_SPARC_WDISP19"},
    {42, "R_SPARC_GLOB_JMP"},
    {43, "R_SPARC_7"},
    {44, "R_SPARC_5"},
    {45, "R_SPARC_6"},
    {46, "R_SPARC_DISP64"},
    {47, "R_SPARC_PLT64"},
    {48, "R_SPARC_HIX22"},
    {49, "R_SPARC_LOX10"},
    {50, "R_SPARC_H44"},
    {51, "R_SPARC_M44"},
    {52, "R_SPARC_L44"},
    {53, "R_SPARC_REGISTER"},
    {54, "R_SPARC_UA64"},
    {55, "R_SPARC_UA16"},
    {56, "R_SPARC_TLS_GD_HI22"},
    {57, "R_SPARC_TLS_GD_LO10"},
    {58, "R_SPARC_TLS_GD_ADD"},
    {59, "R_SPARC_TLS_GD_CALL"},
    {60, "R_SPARC_TLS_LDM_HI22"},
    {61, "R_SPARC_TLS_LDM_LO10"},
    {62, "R_SPARC_TLS_LDM_ADD"},
    {63, "R_SPARC_TLS_LDM_CALL"},
    {64, "R_SPARC_TLS_LDO_HIX22"},
    {65, "R_SPARC_TLS_LDO_LOX10"},
    {66, "R_SPARC_TLS_LDO_ADD"},
    {67, "R_SPARC_TLS_IE_HI22"},
    {68, "R_SPARC_TLS_IE_LO10"},
    {69, "R_SPARC_TLS_IE_LD"},
    {70, "R_SPARC_TLS_IE_LDX"},
    {71, "R_SPARC_TLS_IE_ADD"},
    {72, "R_SPARC_TLS_LE_HIX22"},
    {73, "R_SPARC_TLS_LE_LOX10"},
    {74, "R_SPARC_TLS_DTPMOD32"},
    {75, "R_SPARC_TLS_DTPMOD64"},
    {76, "R_SPARC_TLS_DTPOFF32"},
    {77, "R_SPARC_TLS_DTPOFF64"},
    {78, "R_SPARC_TLS_TPOFF32"},
    {79, "R_SPARC_TLS_TPOFF64"},
    {80, "R_SPARC_GOTDATA_HIX22"},
    {81, "R_SPARC_GOTDATA_LOX10"},
    {82, "R_SPARC_GOTDATA_OP_HIX22"},
    {83, "R_SPARC_GOTDATA_OP_LOX10"},
    {84, "R_SPARC_GOTDATA_OP"},
    {85, "R_SPARC_H34"},
    {86, "R_SPARC_SIZE32"},
    {87, "R_SPARC_SIZE64"},
    {88, "R_SPARC_WDISP10"},
    {248, "R_SPARC_JMP_IREL"},
    {249, "R_SPARC_IRELATIVE"},
    {250, "R_SPARC_GNU_VTINHERIT"},
    {251, "R_SPARC_GNU_VTENTRY"},
    {252, "R_SPARC_REV32"},
    {253, "R_SPARC_NUM"}
};

const defines_map elf_dt_sparc = {
    {0x70000001, "DT_SPARC_REGISTER"},
    {2, "DT_SPARC_NUM"}
};

const defines_map elf_ef_mips = {
    {1, "EF_MIPS_NOREORDER"},
    {2, "EF_MIPS_PIC"},
    {4, "EF_MIPS_CPIC"},
    {8, "EF_MIPS_XGOT"},
    {16, "EF_MIPS_UCODE"},
    {32, "EF_MIPS_ABI2"},
    {64, "EF_MIPS_ABI_ON32"},
    {0x00000080, "EF_MIPS_OPTIONS_FIRST"},
    {0x00000100, "EF_MIPS_32BITMODE"},
    {512, "EF_MIPS_FP64"},
    {1024, "EF_MIPS_NAN2008"},
    {0x0f000000, "EF_MIPS_ARCH_ASE"},
    {0x08000000, "EF_MIPS_ARCH_ASE_MDMX"},
    {0x04000000, "EF_MIPS_ARCH_ASE_M16"},
    {0x02000000, "EF_MIPS_ARCH_ASE_MICROMIPS"},
    {0xf0000000, "EF_MIPS_ARCH"},
    {0x00000000, "EF_MIPS_ARCH_1"},
    {0x10000000, "EF_MIPS_ARCH_2"},
    {0x20000000, "EF_MIPS_ARCH_3"},
    {0x30000000, "EF_MIPS_ARCH_4"},
    {0x40000000, "EF_MIPS_ARCH_5"},
    {0x50000000, "EF_MIPS_ARCH_32"},
    {0x60000000, "EF_MIPS_ARCH_64"},
    {0x70000000, "EF_MIPS_ARCH_32R2"},
    {0x80000000, "EF_MIPS_ARCH_64R2"},
    {0x90000000, "EF_MIPS_ARCH_32R6"},
    {0xa0000000, "EF_MIPS_ARCH_64R6"},
    {0x0000F000, "EF_MIPS_ABI"},
    {0x00001000, "EF_MIPS_ABI_O32"},
    {0x00002000, "EF_MIPS_ABI_O64"},
    {0x00003000, "EF_MIPS_ABI_EABI32"},
    {0x00004000, "EF_MIPS_ABI_EABI64"},
    {0x00FF0000, "EF_MIPS_MACH"},
    {0x00810000, "EF_MIPS_MACH_3900"},
    {0x00820000, "EF_MIPS_MACH_4010"},
    {0x00830000, "EF_MIPS_MACH_4100"},
    {0x00840000, "EF_MIPS_MACH_ALLEGREX"},
    {0x00850000, "EF_MIPS_MACH_4650"},
    {0x00870000, "EF_MIPS_MACH_4120"},
    {0x00880000, "EF_MIPS_MACH_4111"},
    {0x008a0000, "EF_MIPS_MACH_SB1"},
    {0x008b0000, "EF_MIPS_MACH_OCTEON"},
    {0x008c0000, "EF_MIPS_MACH_XLR"},
    {0x008d0000, "EF_MIPS_MACH_OCTEON2"},
    {0x008e0000, "EF_MIPS_MACH_OCTEON3"},
    {0x00910000, "EF_MIPS_MACH_5400"},
    {0x00920000, "EF_MIPS_MACH_5900"},
    {0x00930000, "EF_MIPS_MACH_IAMR2"},
    {0x00980000, "EF_MIPS_MACH_5500"},
    {0x00990000, "EF_MIPS_MACH_9000"},
    {0x00A00000, "EF_MIPS_MACH_LS2E"},
    {0x00A10000, "EF_MIPS_MACH_LS2F"},
    {0x00A20000, "EF_MIPS_MACH_GS464"},
    {0x00A30000, "EF_MIPS_MACH_GS464E"},
    {0x00A40000, "EF_MIPS_MACH_GS264E"},
    {0x00000000, "E_MIPS_ARCH_1"},
    {0x10000000, "E_MIPS_ARCH_2"},
    {0x20000000, "E_MIPS_ARCH_3"},
    {0x30000000, "E_MIPS_ARCH_4"},
    {0x40000000, "E_MIPS_ARCH_5"},
    {0x50000000, "E_MIPS_ARCH_32"},
    {0x60000000, "E_MIPS_ARCH_64"}
};

const defines_map elf_shn_mips = {
    {0xff00, "SHN_MIPS_ACOMMON"},
    {0xff01, "SHN_MIPS_TEXT"},
    {0xff02, "SHN_MIPS_DATA"},
    {0xff03, "SHN_MIPS_SCOMMON"},
    {0xff04, "SHN_MIPS_SUNDEFINED"}
};

const defines_map elf_sht_mips = {
    {0x70000000, "SHT_MIPS_LIBLIST"},
    {0x70000001, "SHT_MIPS_MSYM"},
    {0x70000002, "SHT_MIPS_CONFLICT"},
    {0x70000003, "SHT_MIPS_GPTAB"},
    {0x70000004, "SHT_MIPS_UCODE"},
    {0x70000005, "SHT_MIPS_DEBUG"},
    {0x70000006, "SHT_MIPS_REGINFO"},
    {0x70000007, "SHT_MIPS_PACKAGE"},
    {0x70000008, "SHT_MIPS_PACKSYM"},
    {0x70000009, "SHT_MIPS_RELD"},
    {0x7000000b, "SHT_MIPS_IFACE"},
    {0x7000000c, "SHT_MIPS_CONTENT"},
    {0x7000000d, "SHT_MIPS_OPTIONS"},
    {0x70000010, "SHT_MIPS_SHDR"},
    {0x70000011, "SHT_MIPS_FDESC"},
    {0x70000012, "SHT_MIPS_EXTSYM"},
    {0x70000013, "SHT_MIPS_DENSE"},
    {0x70000014, "SHT_MIPS_PDESC"},
    {0x70000015, "SHT_MIPS_LOCSYM"},
    {0x70000016, "SHT_MIPS_AUXSYM"},
    {0x70000017, "SHT_MIPS_OPTSYM"},
    {0x70000018, "SHT_MIPS_LOCSTR"},
    {0x70000019, "SHT_MIPS_LINE"},
    {0x7000001a, "SHT_MIPS_RFDESC"},
    {0x7000001b, "SHT_MIPS_DELTASYM"},
    {0x7000001c, "SHT_MIPS_DELTAINST"},
    {0x7000001d, "SHT_MIPS_DELTACLASS"},
    {0x7000001e, "SHT_MIPS_DWARF"},
    {0x7000001f, "SHT_MIPS_DELTADECL"},
    {0x70000020, "SHT_MIPS_SYMBOL_LIB"},
    {0x70000021, "SHT_MIPS_EVENTS"},
    {0x70000022, "SHT_MIPS_TRANSLATE"},
    {0x70000023, "SHT_MIPS_PIXIE"},
    {0x70000024, "SHT_MIPS_XLATE"},
    {0x70000025, "SHT_MIPS_XLATE_DEBUG"},
    {0x70000026, "SHT_MIPS_WHIRL"},
    {0x70000027, "SHT_MIPS_EH_REGION"},
    {0x70000028, "SHT_MIPS_XLATE_OLD"},
    {0x70000029, "SHT_MIPS_PDR_EXCEPTION"},
    {0x7000002a, "SHT_MIPS_ABIFLAGS"},
    {0x7000002b, "SHT_MIPS_XHASH"}
};

const defines_map elf_shf_mips = {
    {0x10000000, "SHF_MIPS_GPREL"},
    {0x20000000, "SHF_MIPS_MERGE"},
    {0x40000000, "SHF_MIPS_ADDR"},
    {0x80000000, "SHF_MIPS_STRINGS"},
    {0x08000000, "SHF_MIPS_NOSTRIP"},
    {0x04000000, "SHF_MIPS_LOCAL"},
    {0x02000000, "SHF_MIPS_NAMES"},
    {0x01000000, "SHF_MIPS_NODUPE"}
};

const defines_map elf_sto_mips = {
    {0x0, "STO_MIPS_DEFAULT"},
    {0x1, "STO_MIPS_INTERNAL"},
    {0x2, "STO_MIPS_HIDDEN"},
    {0x3, "STO_MIPS_PROTECTED"},
    {0x8, "STO_MIPS_PLT"},
    {0xff, "STO_MIPS_SC_ALIGN_UNUSED"}
};

const defines_map elf_stb_mips = {
    {13, "STB_MIPS_SPLIT_COMMON"}
};

const defines_map elf_odk = {
    {0, "ODK_NULL"},
    {1, "ODK_REGINFO"},
    {2, "ODK_EXCEPTIONS"},
    {3, "ODK_PAD"},
    {4, "ODK_HWPATCH"},
    {5, "ODK_FILL"},
    {6, "ODK_TAGS"},
    {7, "ODK_HWAND"},
    {8, "ODK_HWOR"}
};

const defines_map elf_oex = {
    {0x1f, "OEX_FPU_MIN"},
    {0x1f00, "OEX_FPU_MAX"},
    {0x10000, "OEX_PAGE0"},
    {0x20000, "OEX_SMM"},
    {0x40000, "OEX_FPDBUG"},
    {0x40000, "OEX_PRECISEFP"},
    {0x80000, "OEX_DISMISS"},
    {0x10, "OEX_FPU_INVAL"},
    {0x08, "OEX_FPU_DIV0"},
    {0x04, "OEX_FPU_OFLO"},
    {0x02, "OEX_FPU_UFLO"},
    {0x01, "OEX_FPU_INEX"}
};

const defines_map elf_ohw = {
    {0x1, "OHW_R4KEOP"},
    {0x2, "OHW_R8KPFETCH"},
    {0x4, "OHW_R5KEOP"},
    {0x8, "OHW_R5KCVTL"}
};

const defines_map elf_opad = {
    {0x1, "OPAD_PREFIX"},
    {0x2, "OPAD_POSTFIX"},
    {0x4, "OPAD_SYMBOL"}
};

const defines_map elf_ohwa = {
    {0x00000001, "OHWA0_R4KEOP_CHECKED"},
    {0x00000002, "OHWA1_R4KEOP_CLEAN"}
};

const defines_map elf_r_mips = {
    {0, "R_MIPS_NONE"},
    {1, "R_MIPS_16"},
    {2, "R_MIPS_32"},
    {3, "R_MIPS_REL32"},
    {4, "R_MIPS_26"},
    {5, "R_MIPS_HI16"},
    {6, "R_MIPS_LO16"},
    {7, "R_MIPS_GPREL16"},
    {8, "R_MIPS_LITERAL"},
    {9, "R_MIPS_GOT16"},
    {10, "R_MIPS_PC16"},
    {11, "R_MIPS_CALL16"},
    {12, "R_MIPS_GPREL32"},
    {16, "R_MIPS_SHIFT5"},
    {17, "R_MIPS_SHIFT6"},
    {18, "R_MIPS_64"},
    {19, "R_MIPS_GOT_DISP"},
    {20, "R_MIPS_GOT_PAGE"},
    {21, "R_MIPS_GOT_OFST"},
    {22, "R_MIPS_GOT_HI16"},
    {23, "R_MIPS_GOT_LO16"},
    {24, "R_MIPS_SUB"},
    {25, "R_MIPS_INSERT_A"},
    {26, "R_MIPS_INSERT_B"},
    {27, "R_MIPS_DELETE"},
    {28, "R_MIPS_HIGHER"},
    {29, "R_MIPS_HIGHEST"},
    {30, "R_MIPS_CALL_HI16"},
    {31, "R_MIPS_CALL_LO16"},
    {32, "R_MIPS_SCN_DISP"},
    {33, "R_MIPS_REL16"},
    {34, "R_MIPS_ADD_IMMEDIATE"},
    {35, "R_MIPS_PJUMP"},
    {36, "R_MIPS_RELGOT"},
    {37, "R_MIPS_JALR"},
    {38, "R_MIPS_TLS_DTPMOD32"},
    {39, "R_MIPS_TLS_DTPREL32"},
    {40, "R_MIPS_TLS_DTPMOD64"},
    {41, "R_MIPS_TLS_DTPREL64"},
    {42, "R_MIPS_TLS_GD"},
    {43, "R_MIPS_TLS_LDM"},
    {44, "R_MIPS_TLS_DTPREL_HI16"},
    {45, "R_MIPS_TLS_DTPREL_LO16"},
    {46, "R_MIPS_TLS_GOTTPREL"},
    {47, "R_MIPS_TLS_TPREL32"},
    {48, "R_MIPS_TLS_TPREL64"},
    {49, "R_MIPS_TLS_TPREL_HI16"},
    {50, "R_MIPS_TLS_TPREL_LO16"},
    {51, "R_MIPS_GLOB_DAT"},
    {60, "R_MIPS_PC21_S2"},
    {61, "R_MIPS_PC26_S2"},
    {62, "R_MIPS_PC18_S3"},
    {63, "R_MIPS_PC19_S2"},
    {64, "R_MIPS_PCHI16"},
    {65, "R_MIPS_PCLO16"},
    {100, "R_MIPS16_26"},
    {101, "R_MIPS16_GPREL"},
    {102, "R_MIPS16_GOT16"},
    {103, "R_MIPS16_CALL16"},
    {104, "R_MIPS16_HI16"},
    {105, "R_MIPS16_LO16"},
    {106, "R_MIPS16_TLS_GD"},
    {107, "R_MIPS16_TLS_LDM"},
    {108, "R_MIPS16_TLS_DTPREL_HI16"},
    {109, "R_MIPS16_TLS_DTPREL_LO16"},
    {110, "R_MIPS16_TLS_GOTTPREL"},
    {111, "R_MIPS16_TLS_TPREL_HI16"},
    {112, "R_MIPS16_TLS_TPREL_LO16"},
    {113, "R_MIPS16_PC16_S1"},
    {126, "R_MIPS_COPY"},
    {127, "R_MIPS_JUMP_SLOT"},
    {128, "R_MIPS_RELATIVE"},
    {133, "R_MICROMIPS_26_S1"},
    {134, "R_MICROMIPS_HI16"},
    {135, "R_MICROMIPS_LO16"},
    {136, "R_MICROMIPS_GPREL16"},
    {137, "R_MICROMIPS_LITERAL"},
    {138, "R_MICROMIPS_GOT16"},
    {139, "R_MICROMIPS_PC7_S1"},
    {140, "R_MICROMIPS_PC10_S1"},
    {141, "R_MICROMIPS_PC16_S1"},
    {142, "R_MICROMIPS_CALL16"},
    {145, "R_MICROMIPS_GOT_DISP"},
    {146, "R_MICROMIPS_GOT_PAGE"},
    {147, "R_MICROMIPS_GOT_OFST"},
    {148, "R_MICROMIPS_GOT_HI16"},
    {149, "R_MICROMIPS_GOT_LO16"},
    {150, "R_MICROMIPS_SUB"},
    {151, "R_MICROMIPS_HIGHER"},
    {152, "R_MICROMIPS_HIGHEST"},
    {153, "R_MICROMIPS_CALL_HI16"},
    {154, "R_MICROMIPS_CALL_LO16"},
    {155, "R_MICROMIPS_SCN_DISP"},
    {156, "R_MICROMIPS_JALR"},
    {157, "R_MICROMIPS_HI0_LO16"},
    {162, "R_MICROMIPS_TLS_GD"},
    {163, "R_MICROMIPS_TLS_LDM"},
    {164, "R_MICROMIPS_TLS_DTPREL_HI16"},
    {165, "R_MICROMIPS_TLS_DTPREL_LO16"},
    {166, "R_MICROMIPS_TLS_GOTTPREL"},
    {169, "R_MICROMIPS_TLS_TPREL_HI16"},
    {170, "R_MICROMIPS_TLS_TPREL_LO16"},
    {172, "R_MICROMIPS_GPREL7_S2"},
    {173, "R_MICROMIPS_PC23_S2"},
    {248, "R_MIPS_PC32"},
    {249, "R_MIPS_EH"},
    {250, "R_MIPS_GNU_REL16_S2"},
    {253, "R_MIPS_GNU_VTINHERIT"},
    {254, "R_MIPS_GNU_VTENTRY"},
    {255, "R_MIPS_NUM"}
};

const defines_map elf_pt_mips = {
    {0x70000000, "PT_MIPS_REGINFO"},
    {0x70000001, "PT_MIPS_RTPROC"},
    {0x70000002, "PT_MIPS_OPTIONS"},
    {0x70000003, "PT_MIPS_ABIFLAGS"}
};

const defines_map elf_pf_mips = {
    {0x10000000, "PF_MIPS_LOCAL"}
};

const defines_map elf_dt_mips = {
    {0x70000001, "DT_MIPS_RLD_VERSION"},
    {0x70000002, "DT_MIPS_TIME_STAMP"},
    {0x70000003, "DT_MIPS_ICHECKSUM"},
    {0x70000004, "DT_MIPS_IVERSION"},
    {0x70000005, "DT_MIPS_FLAGS"},
    {0x70000006, "DT_MIPS_BASE_ADDRESS"},
    {0x70000007, "DT_MIPS_MSYM"},
    {0x70000008, "DT_MIPS_CONFLICT"},
    {0x70000009, "DT_MIPS_LIBLIST"},
    {0x7000000a, "DT_MIPS_LOCAL_GOTNO"},
    {0x7000000b, "DT_MIPS_CONFLICTNO"},
    {0x70000010, "DT_MIPS_LIBLISTNO"},
    {0x70000011, "DT_MIPS_SYMTABNO"},
    {0x70000012, "DT_MIPS_UNREFEXTNO"},
    {0x70000013, "DT_MIPS_GOTSYM"},
    {0x70000014, "DT_MIPS_HIPAGENO"},
    {0x70000016, "DT_MIPS_RLD_MAP"},
    {0x70000017, "DT_MIPS_DELTA_CLASS"},
    {0x70000018, "DT_MIPS_DELTA_CLASS_NO"},
    {0x70000019, "DT_MIPS_DELTA_INSTANCE"},
    {0x7000001a, "DT_MIPS_DELTA_INSTANCE_NO"},
    {0x7000001b, "DT_MIPS_DELTA_RELOC"},
    {0x7000001c, "DT_MIPS_DELTA_RELOC_NO"},
    {0x7000001d, "DT_MIPS_DELTA_SYM"},
    {0x7000001e, "DT_MIPS_DELTA_SYM_NO"},
    {0x70000020, "DT_MIPS_DELTA_CLASSSYM"},
    {0x70000021, "DT_MIPS_DELTA_CLASSSYM_NO"},
    {0x70000022, "DT_MIPS_CXX_FLAGS"},
    {0x70000023, "DT_MIPS_PIXIE_INIT"},
    {0x70000024, "DT_MIPS_SYMBOL_LIB"},
    {0x70000025, "DT_MIPS_LOCALPAGE_GOTIDX"},
    {0x70000026, "DT_MIPS_LOCAL_GOTIDX"},
    {0x70000027, "DT_MIPS_HIDDEN_GOTIDX"},
    {0x70000028, "DT_MIPS_PROTECTED_GOTIDX"},
    {0x70000029, "DT_MIPS_OPTIONS"},
    {0x7000002a, "DT_MIPS_INTERFACE"},
    {0x7000002b, "DT_MIPS_DYNSTR_ALIGN"},
    {0x7000002c, "DT_MIPS_INTERFACE_SIZE"},
    {0x7000002d, "DT_MIPS_RLD_TEXT_RESOLVE_ADDR"},
    {0x7000002e, "DT_MIPS_PERF_SUFFIX"},
    {0x7000002f, "DT_MIPS_COMPACT_SIZE"},
    {0x70000030, "DT_MIPS_GP_VALUE"},
    {0x70000031, "DT_MIPS_AUX_DYNAMIC"},
    {0x70000032, "DT_MIPS_PLTGOT"},
    {0x70000034, "DT_MIPS_RWPLT"},
    {0x70000035, "DT_MIPS_RLD_MAP_REL"},
    {0x70000036, "DT_MIPS_XHASH"},
    {0x37, "DT_MIPS_NUM"}
};

const defines_map elf_rhf = {
    {0, "RHF_NONE"},
    {(1 << 0), "RHF_QUICKSTART"},
    {(1 << 1), "RHF_NOTPOT"},
    {(1 << 2), "RHF_NO_LIBRARY_REPLACEMENT"},
    {(1 << 3), "RHF_NO_MOVE"},
    {(1 << 4), "RHF_SGI_ONLY"},
    {(1 << 5), "RHF_GUARANTEE_INIT"},
    {(1 << 6), "RHF_DELTA_C_PLUS_PLUS"},
    {(1 << 7), "RHF_GUARANTEE_START_INIT"},
    {(1 << 8), "RHF_PIXIE"},
    {(1 << 9), "RHF_DEFAULT_DELAY_LOAD"},
    {(1 << 10), "RHF_REQUICKSTART"},
    {(1 << 11), "RHF_REQUICKSTARTED"},
    {(1 << 12), "RHF_CORD"},
    {(1 << 13), "RHF_NO_UNRES_UNDEF"},
    {(1 << 14), "RHF_RLD_ORDER_SAFE"}
};

const defines_map elf_ll = {
    {0, "LL_NONE"},
    {(1 << 0), "LL_EXACT_MATCH"},
    {(1 << 1), "LL_IGNORE_INT_VER"},
    {(1 << 2), "LL_REQUIRE_MINOR"},
    {(1 << 3), "LL_EXPORTS"},
    {(1 << 4), "LL_DELAY_LOAD"},
    {(1 << 5), "LL_DELTA"}
};

const defines_map elf_mips_afl_reg = {
    {0x00, "MIPS_AFL_REG_NONE"},
    {0x01, "MIPS_AFL_REG_32"},
    {0x02, "MIPS_AFL_REG_64"},
    {0x03, "MIPS_AFL_REG_128"}
};

const defines_map elf_mips_afl_ase = {
    {0x00000001, "MIPS_AFL_ASE_DSP"},
    {0x00000002, "MIPS_AFL_ASE_DSPR2"},
    {0x00000004, "MIPS_AFL_ASE_EVA"},
    {0x00000008, "MIPS_AFL_ASE_MCU"},
    {0x00000010, "MIPS_AFL_ASE_MDMX"},
    {0x00000020, "MIPS_AFL_ASE_MIPS3D"},
    {0x00000040, "MIPS_AFL_ASE_MT"},
    {0x00000080, "MIPS_AFL_ASE_SMARTMIPS"},
    {0x00000100, "MIPS_AFL_ASE_VIRT"},
    {0x00000200, "MIPS_AFL_ASE_MSA"},
    {0x00000400, "MIPS_AFL_ASE_MIPS16"},
    {0x00000800, "MIPS_AFL_ASE_MICROMIPS"},
    {0x00001000, "MIPS_AFL_ASE_XPA"},
    {0x00001fff, "MIPS_AFL_ASE_MASK"}
};

const defines_map elf_mips_afl_ext = {
    {1, "MIPS_AFL_EXT_XLR"},
    {2, "MIPS_AFL_EXT_OCTEON2"},
    {3, "MIPS_AFL_EXT_OCTEONP"},
    {4, "MIPS_AFL_EXT_LOONGSON_3A"},
    {5, "MIPS_AFL_EXT_OCTEON"},
    {6, "MIPS_AFL_EXT_5900"},
    {7, "MIPS_AFL_EXT_4650"},
    {8, "MIPS_AFL_EXT_4010"},
    {9, "MIPS_AFL_EXT_4100"},
    {10, "MIPS_AFL_EXT_3900"},
    {11, "MIPS_AFL_EXT_10000"},
    {12, "MIPS_AFL_EXT_SB1"},
    {13, "MIPS_AFL_EXT_4111"},
    {14, "MIPS_AFL_EXT_4120"},
    {15, "MIPS_AFL_EXT_5400"},
    {16, "MIPS_AFL_EXT_5500"},
    {17, "MIPS_AFL_EXT_LOONGSON_2E"},
    {18, "MIPS_AFL_EXT_LOONGSON_2F"}
};

const defines_map elf_mips_afl_flags1 = {
    {1, "MIPS_AFL_FLAGS1_ODDSPREG"}
};

const defines_map elf_val_gnu_mips_abi_fp = {
    {Val_GNU_MIPS_ABI_FP_ANY, "Val_GNU_MIPS_ABI_FP_ANY"},
    {Val_GNU_MIPS_ABI_FP_DOUBLE, "Val_GNU_MIPS_ABI_FP_DOUBLE"},
    {Val_GNU_MIPS_ABI_FP_SINGLE, "Val_GNU_MIPS_ABI_FP_SINGLE"},
    {Val_GNU_MIPS_ABI_FP_SOFT, "Val_GNU_MIPS_ABI_FP_SOFT"},
    {Val_GNU_MIPS_ABI_FP_OLD_64, "Val_GNU_MIPS_ABI_FP_OLD_64"},
    {Val_GNU_MIPS_ABI_FP_XX, "Val_GNU_MIPS_ABI_FP_XX"},
    {Val_GNU_MIPS_ABI_FP_64, "Val_GNU_MIPS_ABI_FP_64"},
    {Val_GNU_MIPS_ABI_FP_64A, "Val_GNU_MIPS_ABI_FP_64A"},
    {Val_GNU_MIPS_ABI_FP_MAX, "Val_GNU_MIPS_ABI_FP_MAX"}
};

const defines_map elf_ef_parisc = {
    {0x00010000, "EF_PARISC_TRAPNIL"},
    {0x00020000, "EF_PARISC_EXT"},
    {0x00040000, "EF_PARISC_LSB"},
    {0x00080000, "EF_PARISC_WIDE"},
    {0x00100000, "EF_PARISC_NO_KABP"},
    {0x00400000, "EF_PARISC_LAZYSWAP"},
    {0x0000ffff, "EF_PARISC_ARCH"}
};

const defines_map elf_efa_parisc = {
    {0x020b, "EFA_PARISC_1_0"},
    {0x0210, "EFA_PARISC_1_1"},
    {0x0214, "EFA_PARISC_2_0"}
};

const defines_map elf_shn_parisc = {
    {0xff00, "SHN_PARISC_ANSI_COMMON"},
    {0xff01, "SHN_PARISC_HUGE_COMMON"}
};

const defines_map elf_sht_parisc = {
    {0x70000000, "SHT_PARISC_EXT"},
    {0x70000001, "SHT_PARISC_UNWIND"},
    {0x70000002, "SHT_PARISC_DOC"}
};

const defines_map elf_shf_parisc = {
    {0x20000000, "SHF_PARISC_SHORT"},
    {0x40000000, "SHF_PARISC_HUGE"},
    {0x80000000, "SHF_PARISC_SBP"}
};

const defines_map elf_stt_parisc_hp = {
    {13, "STT_PARISC_MILLICODE"},
    {(10 + 0x1), "STT_HP_OPAQUE"},
    {(10 + 0x2), "STT_HP_STUB"}
};

const defines_map elf_r_parisc = {
    {0, "R_PARISC_NONE"},
    {1, "R_PARISC_DIR32"},
    {2, "R_PARISC_DIR21L"},
    {3, "R_PARISC_DIR17R"},
    {4, "R_PARISC_DIR17F"},
    {6, "R_PARISC_DIR14R"},
    {9, "R_PARISC_PCREL32"},
    {10, "R_PARISC_PCREL21L"},
    {11, "R_PARISC_PCREL17R"},
    {12, "R_PARISC_PCREL17F"},
    {14, "R_PARISC_PCREL14R"},
    {18, "R_PARISC_DPREL21L"},
    {22, "R_PARISC_DPREL14R"},
    {26, "R_PARISC_GPREL21L"},
    {30, "R_PARISC_GPREL14R"},
    {34, "R_PARISC_LTOFF21L"},
    {38, "R_PARISC_LTOFF14R"},
    {41, "R_PARISC_SECREL32"},
    {48, "R_PARISC_SEGBASE"},
    {49, "R_PARISC_SEGREL32"},
    {50, "R_PARISC_PLTOFF21L"},
    {54, "R_PARISC_PLTOFF14R"},
    {57, "R_PARISC_LTOFF_FPTR32"},
    {58, "R_PARISC_LTOFF_FPTR21L"},
    {62, "R_PARISC_LTOFF_FPTR14R"},
    {64, "R_PARISC_FPTR64"},
    {65, "R_PARISC_PLABEL32"},
    {66, "R_PARISC_PLABEL21L"},
    {70, "R_PARISC_PLABEL14R"},
    {72, "R_PARISC_PCREL64"},
    {74, "R_PARISC_PCREL22F"},
    {75, "R_PARISC_PCREL14WR"},
    {76, "R_PARISC_PCREL14DR"},
    {77, "R_PARISC_PCREL16F"},
    {78, "R_PARISC_PCREL16WF"},
    {79, "R_PARISC_PCREL16DF"},
    {80, "R_PARISC_DIR64"},
    {83, "R_PARISC_DIR14WR"},
    {84, "R_PARISC_DIR14DR"},
    {85, "R_PARISC_DIR16F"},
    {86, "R_PARISC_DIR16WF"},
    {87, "R_PARISC_DIR16DF"},
    {88, "R_PARISC_GPREL64"},
    {91, "R_PARISC_GPREL14WR"},
    {92, "R_PARISC_GPREL14DR"},
    {93, "R_PARISC_GPREL16F"},
    {94, "R_PARISC_GPREL16WF"},
    {95, "R_PARISC_GPREL16DF"},
    {96, "R_PARISC_LTOFF64"},
    {99, "R_PARISC_LTOFF14WR"},
    {100, "R_PARISC_LTOFF14DR"},
    {101, "R_PARISC_LTOFF16F"},
    {102, "R_PARISC_LTOFF16WF"},
    {103, "R_PARISC_LTOFF16DF"},
    {104, "R_PARISC_SECREL64"},
    {112, "R_PARISC_SEGREL64"},
    {115, "R_PARISC_PLTOFF14WR"},
    {116, "R_PARISC_PLTOFF14DR"},
    {117, "R_PARISC_PLTOFF16F"},
    {118, "R_PARISC_PLTOFF16WF"},
    {119, "R_PARISC_PLTOFF16DF"},
    {120, "R_PARISC_LTOFF_FPTR64"},
    {123, "R_PARISC_LTOFF_FPTR14WR"},
    {124, "R_PARISC_LTOFF_FPTR14DR"},
    {125, "R_PARISC_LTOFF_FPTR16F"},
    {126, "R_PARISC_LTOFF_FPTR16WF"},
    {127, "R_PARISC_LTOFF_FPTR16DF"},
    {128, "R_PARISC_LORESERVE"},
    {128, "R_PARISC_COPY"},
    {129, "R_PARISC_IPLT"},
    {130, "R_PARISC_EPLT"},
    {153, "R_PARISC_TPREL32"},
    {154, "R_PARISC_TPREL21L"},
    {158, "R_PARISC_TPREL14R"},
    {162, "R_PARISC_LTOFF_TP21L"},
    {166, "R_PARISC_LTOFF_TP14R"},
    {167, "R_PARISC_LTOFF_TP14F"},
    {216, "R_PARISC_TPREL64"},
    {219, "R_PARISC_TPREL14WR"},
    {220, "R_PARISC_TPREL14DR"},
    {221, "R_PARISC_TPREL16F"},
    {222, "R_PARISC_TPREL16WF"},
    {223, "R_PARISC_TPREL16DF"},
    {224, "R_PARISC_LTOFF_TP64"},
    {227, "R_PARISC_LTOFF_TP14WR"},
    {228, "R_PARISC_LTOFF_TP14DR"},
    {229, "R_PARISC_LTOFF_TP16F"},
    {230, "R_PARISC_LTOFF_TP16WF"},
    {231, "R_PARISC_LTOFF_TP16DF"},
    {232, "R_PARISC_GNU_VTENTRY"},
    {233, "R_PARISC_GNU_VTINHERIT"},
    {234, "R_PARISC_TLS_GD21L"},
    {235, "R_PARISC_TLS_GD14R"},
    {236, "R_PARISC_TLS_GDCALL"},
    {237, "R_PARISC_TLS_LDM21L"},
    {238, "R_PARISC_TLS_LDM14R"},
    {239, "R_PARISC_TLS_LDMCALL"},
    {240, "R_PARISC_TLS_LDO21L"},
    {241, "R_PARISC_TLS_LDO14R"},
    {242, "R_PARISC_TLS_DTPMOD32"},
    {243, "R_PARISC_TLS_DTPMOD64"},
    {244, "R_PARISC_TLS_DTPOFF32"},
    {245, "R_PARISC_TLS_DTPOFF64"},
    {154, "R_PARISC_TLS_LE21L"},
    {158, "R_PARISC_TLS_LE14R"},
    {162, "R_PARISC_TLS_IE21L"},
    {166, "R_PARISC_TLS_IE14R"},
    {153, "R_PARISC_TLS_TPREL32"},
    {216, "R_PARISC_TLS_TPREL64"},
    {255, "R_PARISC_HIRESERVE"}
};

const defines_map elf_pt_parisc_hp = {
    {(0x60000000 + 0x0), "PT_HP_TLS"},
    {(0x60000000 + 0x1), "PT_HP_CORE_NONE"},
    {(0x60000000 + 0x2), "PT_HP_CORE_VERSION"},
    {(0x60000000 + 0x3), "PT_HP_CORE_KERNEL"},
    {(0x60000000 + 0x4), "PT_HP_CORE_COMM"},
    {(0x60000000 + 0x5), "PT_HP_CORE_PROC"},
    {(0x60000000 + 0x6), "PT_HP_CORE_LOADABLE"},
    {(0x60000000 + 0x7), "PT_HP_CORE_STACK"},
    {(0x60000000 + 0x8), "PT_HP_CORE_SHM"},
    {(0x60000000 + 0x9), "PT_HP_CORE_MMF"},
    {(0x60000000 + 0x10), "PT_HP_PARALLEL"},
    {(0x60000000 + 0x11), "PT_HP_FASTBIND"},
    {(0x60000000 + 0x12), "PT_HP_OPT_ANNOT"},
    {(0x60000000 + 0x13), "PT_HP_HSL_ANNOT"},
    {(0x60000000 + 0x14), "PT_HP_STACK"},
    {0x70000000, "PT_PARISC_ARCHEXT"},
    {0x70000001, "PT_PARISC_UNWIND"}
};

const defines_map elf_pf_parisc_hp = {
    {0x08000000, "PF_PARISC_SBP"},
    {0x00100000, "PF_HP_PAGE_SIZE"},
    {0x00200000, "PF_HP_FAR_SHARED"},
    {0x00400000, "PF_HP_NEAR_SHARED"},
    {0x01000000, "PF_HP_CODE"},
    {0x02000000, "PF_HP_MODIFY"},
    {0x04000000, "PF_HP_LAZYSWAP"},
    {0x08000000, "PF_HP_SBP"}
};

const defines_map elf_ef_alpha = {
    {1, "EF_ALPHA_32BIT"},
    {2, "EF_ALPHA_CANRELAX"}
};

const defines_map elf_sht_alpha = {
    {0x70000001, "SHT_ALPHA_DEBUG"},
    {0x70000002, "EF_ALPHA_CANRELAX"}
};

const defines_map elf_shf_alpha = {
    {0x10000000, "SHF_ALPHA_GPREL"}
};

const defines_map elf_sto_alpha = {
    {0x80, "STO_ALPHA_NOPV"},
    {0x88, "STO_ALPHA_STD_GPLOAD"}
};

const defines_map elf_r_alpha = {
    {0, "R_ALPHA_NONE"},
    {1, "R_ALPHA_REFLONG"},
    {2, "R_ALPHA_REFQUAD"},
    {3, "R_ALPHA_GPREL32"},
    {4, "R_ALPHA_LITERAL"},
    {5, "R_ALPHA_LITUSE"},
    {6, "R_ALPHA_GPDISP"},
    {7, "R_ALPHA_BRADDR"},
    {8, "R_ALPHA_HINT"},
    {9, "R_ALPHA_SREL16"},
    {10, "R_ALPHA_SREL32"},
    {11, "R_ALPHA_SREL64"},
    {17, "R_ALPHA_GPRELHIGH"},
    {18, "R_ALPHA_GPRELLOW"},
    {19, "R_ALPHA_GPREL16"},
    {24, "R_ALPHA_COPY"},
    {25, "R_ALPHA_GLOB_DAT"},
    {26, "R_ALPHA_JMP_SLOT"},
    {27, "R_ALPHA_RELATIVE"},
    {28, "R_ALPHA_TLS_GD_HI"},
    {29, "R_ALPHA_TLSGD"},
    {30, "R_ALPHA_TLS_LDM"},
    {31, "R_ALPHA_DTPMOD64"},
    {32, "R_ALPHA_GOTDTPREL"},
    {33, "R_ALPHA_DTPREL64"},
    {34, "R_ALPHA_DTPRELHI"},
    {35, "R_ALPHA_DTPRELLO"},
    {36, "R_ALPHA_DTPREL16"},
    {37, "R_ALPHA_GOTTPREL"},
    {38, "R_ALPHA_TPREL64"},
    {39, "R_ALPHA_TPRELHI"},
    {40, "R_ALPHA_TPRELLO"},
    {41, "R_ALPHA_TPREL16"},
    {46, "R_ALPHA_NUM"}
};

const defines_map elf_lituse_alpha = {
    {0, "LITUSE_ALPHA_ADDR"},
    {1, "LITUSE_ALPHA_BASE"},
    {2, "LITUSE_ALPHA_BYTOFF"},
    {3, "LITUSE_ALPHA_JSR"},
    {4, "LITUSE_ALPHA_TLS_GD"},
    {5, "LITUSE_ALPHA_TLS_LDM"}
};

const defines_map elf_dt_alpha = {
    {(0x70000000 + 0), "DT_ALPHA_PLTRO"},
    {1, "DT_ALPHA_NUM"}
};

const defines_map elf_ef_ppc = {
    {0x80000000, "EF_PPC_EMB"}
};

const defines_map elf_ef_ppc_relocatable = {
    {0x00010000, "EF_PPC_RELOCATABLE"},
    {0x00008000, "EF_PPC_RELOCATABLE_LIB"}
};

const defines_map elf_r_ppc = {
    {0, "R_PPC_NONE"},
    {1, "R_PPC_ADDR32"},
    {2, "R_PPC_ADDR24"},
    {3, "R_PPC_ADDR16"},
    {4, "R_PPC_ADDR16_LO"},
    {5, "R_PPC_ADDR16_HI"},
    {6, "R_PPC_ADDR16_HA"},
    {7, "R_PPC_ADDR14"},
    {8, "R_PPC_ADDR14_BRTAKEN"},
    {9, "R_PPC_ADDR14_BRNTAKEN"},
    {10, "R_PPC_REL24"},
    {11, "R_PPC_REL14"},
    {12, "R_PPC_REL14_BRTAKEN"},
    {13, "R_PPC_REL14_BRNTAKEN"},
    {14, "R_PPC_GOT16"},
    {15, "R_PPC_GOT16_LO"},
    {16, "R_PPC_GOT16_HI"},
    {17, "R_PPC_GOT16_HA"},
    {18, "R_PPC_PLTREL24"},
    {19, "R_PPC_COPY"},
    {20, "R_PPC_GLOB_DAT"},
    {21, "R_PPC_JMP_SLOT"},
    {22, "R_PPC_RELATIVE"},
    {23, "R_PPC_LOCAL24PC"},
    {24, "R_PPC_UADDR32"},
    {25, "R_PPC_UADDR16"},
    {26, "R_PPC_REL32"},
    {27, "R_PPC_PLT32"},
    {28, "R_PPC_PLTREL32"},
    {29, "R_PPC_PLT16_LO"},
    {30, "R_PPC_PLT16_HI"},
    {31, "R_PPC_PLT16_HA"},
    {32, "R_PPC_SDAREL16"},
    {33, "R_PPC_SECTOFF"},
    {34, "R_PPC_SECTOFF_LO"},
    {35, "R_PPC_SECTOFF_HI"},
    {36, "R_PPC_SECTOFF_HA"},
    {67, "R_PPC_TLS"},
    {68, "R_PPC_DTPMOD32"},
    {69, "R_PPC_TPREL16"},
    {70, "R_PPC_TPREL16_LO"},
    {71, "R_PPC_TPREL16_HI"},
    {72, "R_PPC_TPREL16_HA"},
    {73, "R_PPC_TPREL32"},
    {74, "R_PPC_DTPREL16"},
    {75, "R_PPC_DTPREL16_LO"},
    {76, "R_PPC_DTPREL16_HI"},
    {77, "R_PPC_DTPREL16_HA"},
    {78, "R_PPC_DTPREL32"},
    {79, "R_PPC_GOT_TLSGD16"},
    {80, "R_PPC_GOT_TLSGD16_LO"},
    {81, "R_PPC_GOT_TLSGD16_HI"},
    {82, "R_PPC_GOT_TLSGD16_HA"},
    {83, "R_PPC_GOT_TLSLD16"},
    {84, "R_PPC_GOT_TLSLD16_LO"},
    {85, "R_PPC_GOT_TLSLD16_HI"},
    {86, "R_PPC_GOT_TLSLD16_HA"},
    {87, "R_PPC_GOT_TPREL16"},
    {88, "R_PPC_GOT_TPREL16_LO"},
    {89, "R_PPC_GOT_TPREL16_HI"},
    {90, "R_PPC_GOT_TPREL16_HA"},
    {91, "R_PPC_GOT_DTPREL16"},
    {92, "R_PPC_GOT_DTPREL16_LO"},
    {93, "R_PPC_GOT_DTPREL16_HI"},
    {94, "R_PPC_GOT_DTPREL16_HA"},
    {95, "R_PPC_TLSGD"},
    {96, "R_PPC_TLSLD"},
    {101, "R_PPC_EMB_NADDR32"},
    {102, "R_PPC_EMB_NADDR16"},
    {103, "R_PPC_EMB_NADDR16_LO"},
    {104, "R_PPC_EMB_NADDR16_HI"},
    {105, "R_PPC_EMB_NADDR16_HA"},
    {106, "R_PPC_EMB_SDAI16"},
    {107, "R_PPC_EMB_SDA2I16"},
    {108, "R_PPC_EMB_SDA2REL"},
    {109, "R_PPC_EMB_SDA21"},
    {110, "R_PPC_EMB_MRKREF"},
    {111, "R_PPC_EMB_RELSEC16"},
    {112, "R_PPC_EMB_RELST_LO"},
    {113, "R_PPC_EMB_RELST_HI"},
    {114, "R_PPC_EMB_RELST_HA"},
    {115, "R_PPC_EMB_BIT_FLD"},
    {116, "R_PPC_EMB_RELSDA"},
    {180, "R_PPC_DIAB_SDA21_LO"},
    {181, "R_PPC_DIAB_SDA21_HI"},
    {182, "R_PPC_DIAB_SDA21_HA"},
    {183, "R_PPC_DIAB_RELSDA_LO"},
    {184, "R_PPC_DIAB_RELSDA_HI"},
    {185, "R_PPC_DIAB_RELSDA_HA"},
    {248, "R_PPC_IRELATIVE"},
    {249, "R_PPC_REL16"},
    {250, "R_PPC_REL16_LO"},
    {251, "R_PPC_REL16_HI"},
    {252, "R_PPC_REL16_HA"},
    {255, "R_PPC_TOC16"}
};

const defines_map elf_dt_ppc = {
    {(0x70000000 + 0), "DT_PPC_GOT"},
    {(0x70000000 + 1), "DT_PPC_OPT"},
    {2, "DT_PPC_NUM"}
};

const defines_map elf_ppc_opt = {
    {1, "PPC_OPT_TLS"}
};

const defines_map elf_r_ppc64 = {
    {0, "R_PPC64_NONE"},
    {1, "R_PPC64_ADDR32"},
    {2, "R_PPC64_ADDR24"},
    {3, "R_PPC64_ADDR16"},
    {4, "R_PPC64_ADDR16_LO"},
    {5, "R_PPC64_ADDR16_HI"},
    {6, "R_PPC64_ADDR16_HA"},
    {7, "R_PPC64_ADDR14"},
    {8, "R_PPC64_ADDR14_BRTAKEN"},
    {9, "R_PPC64_ADDR14_BRNTAKEN"},
    {10, "R_PPC64_REL24"},
    {11, "R_PPC64_REL14"},
    {12, "R_PPC64_REL14_BRTAKEN"},
    {13, "R_PPC64_REL14_BRNTAKEN"},
    {14, "R_PPC64_GOT16"},
    {15, "R_PPC64_GOT16_LO"},
    {16, "R_PPC64_GOT16_HI"},
    {17, "R_PPC64_GOT16_HA"},
    {19, "R_PPC64_COPY"},
    {20, "R_PPC64_GLOB_DAT"},
    {21, "R_PPC64_JMP_SLOT"},
    {22, "R_PPC64_RELATIVE"},
    {24, "R_PPC64_UADDR32"},
    {25, "R_PPC64_UADDR16"},
    {26, "R_PPC64_REL32"},
    {27, "R_PPC64_PLT32"},
    {28, "R_PPC64_PLTREL32"},
    {29, "R_PPC64_PLT16_LO"},
    {30, "R_PPC64_PLT16_HI"},
    {31, "R_PPC64_PLT16_HA"},
    {33, "R_PPC64_SECTOFF"},
    {34, "R_PPC64_SECTOFF_LO"},
    {35, "R_PPC64_SECTOFF_HI"},
    {36, "R_PPC64_SECTOFF_HA"},
    {37, "R_PPC64_ADDR30"},
    {38, "R_PPC64_ADDR64"},
    {39, "R_PPC64_ADDR16_HIGHER"},
    {40, "R_PPC64_ADDR16_HIGHERA"},
    {41, "R_PPC64_ADDR16_HIGHEST"},
    {42, "R_PPC64_ADDR16_HIGHESTA"},
    {43, "R_PPC64_UADDR64"},
    {44, "R_PPC64_REL64"},
    {45, "R_PPC64_PLT64"},
    {46, "R_PPC64_PLTREL64"},
    {47, "R_PPC64_TOC16"},
    {48, "R_PPC64_TOC16_LO"},
    {49, "R_PPC64_TOC16_HI"},
    {50, "R_PPC64_TOC16_HA"},
    {51, "R_PPC64_TOC"},
    {52, "R_PPC64_PLTGOT16"},
    {53, "R_PPC64_PLTGOT16_LO"},
    {54, "R_PPC64_PLTGOT16_HI"},
    {55, "R_PPC64_PLTGOT16_HA"},
    {56, "R_PPC64_ADDR16_DS"},
    {57, "R_PPC64_ADDR16_LO_DS"},
    {58, "R_PPC64_GOT16_DS"},
    {59, "R_PPC64_GOT16_LO_DS"},
    {60, "R_PPC64_PLT16_LO_DS"},
    {61, "R_PPC64_SECTOFF_DS"},
    {62, "R_PPC64_SECTOFF_LO_DS"},
    {63, "R_PPC64_TOC16_DS"},
    {64, "R_PPC64_TOC16_LO_DS"},
    {65, "R_PPC64_PLTGOT16_DS"},
    {66, "R_PPC64_PLTGOT16_LO_DS"},
    {67, "R_PPC64_TLS"},
    {68, "R_PPC64_DTPMOD64"},
    {69, "R_PPC64_TPREL16"},
    {70, "R_PPC64_TPREL16_LO"},
    {71, "R_PPC64_TPREL16_HI"},
    {72, "R_PPC64_TPREL16_HA"},
    {73, "R_PPC64_TPREL64"},
    {74, "R_PPC64_DTPREL16"},
    {75, "R_PPC64_DTPREL16_LO"},
    {76, "R_PPC64_DTPREL16_HI"},
    {77, "R_PPC64_DTPREL16_HA"},
    {78, "R_PPC64_DTPREL64"},
    {79, "R_PPC64_GOT_TLSGD16"},
    {80, "R_PPC64_GOT_TLSGD16_LO"},
    {81, "R_PPC64_GOT_TLSGD16_HI"},
    {82, "R_PPC64_GOT_TLSGD16_HA"},
    {83, "R_PPC64_GOT_TLSLD16"},
    {84, "R_PPC64_GOT_TLSLD16_LO"},
    {85, "R_PPC64_GOT_TLSLD16_HI"},
    {86, "R_PPC64_GOT_TLSLD16_HA"},
    {87, "R_PPC64_GOT_TPREL16_DS"},
    {88, "R_PPC64_GOT_TPREL16_LO_DS"},
    {89, "R_PPC64_GOT_TPREL16_HI"},
    {90, "R_PPC64_GOT_TPREL16_HA"},
    {91, "R_PPC64_GOT_DTPREL16_DS"},
    {92, "R_PPC64_GOT_DTPREL16_LO_DS"},
    {93, "R_PPC64_GOT_DTPREL16_HI"},
    {94, "R_PPC64_GOT_DTPREL16_HA"},
    {95, "R_PPC64_TPREL16_DS"},
    {96, "R_PPC64_TPREL16_LO_DS"},
    {97, "R_PPC64_TPREL16_HIGHER"},
    {98, "R_PPC64_TPREL16_HIGHERA"},
    {99, "R_PPC64_TPREL16_HIGHEST"},
    {100, "R_PPC64_TPREL16_HIGHESTA"},
    {101, "R_PPC64_DTPREL16_DS"},
    {102, "R_PPC64_DTPREL16_LO_DS"},
    {103, "R_PPC64_DTPREL16_HIGHER"},
    {104, "R_PPC64_DTPREL16_HIGHERA"},
    {105, "R_PPC64_DTPREL16_HIGHEST"},
    {106, "R_PPC64_DTPREL16_HIGHESTA"},
    {107, "R_PPC64_TLSGD"},
    {108, "R_PPC64_TLSLD"},
    {109, "R_PPC64_TOCSAVE"},
    {110, "R_PPC64_ADDR16_HIGH"},
    {111, "R_PPC64_ADDR16_HIGHA"},
    {112, "R_PPC64_TPREL16_HIGH"},
    {113, "R_PPC64_TPREL16_HIGHA"},
    {114, "R_PPC64_DTPREL16_HIGH"},
    {115, "R_PPC64_DTPREL16_HIGHA"},
    {247, "R_PPC64_JMP_IREL"},
    {248, "R_PPC64_IRELATIVE"},
    {249, "R_PPC64_REL16"},
    {250, "R_PPC64_REL16_LO"},
    {251, "R_PPC64_REL16_HI"},
    {252, "R_PPC64_REL16_HA"}
};

const defines_map elf_ef_ppc64 = {
    {3, "EF_PPC64_ABI"}
};

const defines_map elf_dt_ppc64 = {
    {(0x70000000 + 0), "DT_PPC64_GLINK"},
    {(0x70000000 + 1), "DT_PPC64_OPD"},
    {(0x70000000 + 2), "DT_PPC64_OPDSZ"},
    {(0x70000000 + 3), "DT_PPC64_OPT"},
    {4, "DT_PPC64_NUM"}
};

const defines_map elf_ppc64_opt = {
    {1, "PPC64_OPT_TLS"},
    {2, "PPC64_OPT_MULTI_TOC"},
    {4, "PPC64_OPT_LOCALENTRY"}
};

const defines_map elf_sto_ppc64_local_bit = {
    {5, "STO_PPC64_LOCAL_BIT"}
};

const defines_map elf_sto_ppc64_local_mask = {
    {(7 << 5), "STO_PPC64_LOCAL_MASK"}
};

const defines_map elf_ef_arm = {
    {0x01, "EF_ARM_RELEXEC"},
    {0x02, "EF_ARM_HASENTRY"},
    {0x04, "EF_ARM_INTERWORK"},
    {0x08, "EF_ARM_APCS_26"},
    {0x10, "EF_ARM_APCS_FLOAT"},
    {0x20, "EF_ARM_PIC"},
    {0x40, "EF_ARM_ALIGN8"},
    {0x80, "EF_ARM_NEW_ABI"},
    {0x100, "EF_ARM_OLD_ABI"},
    {0x200, "EF_ARM_SOFT_FLOAT"},
    {0x400, "EF_ARM_VFP_FLOAT"},
    {0x800, "EF_ARM_MAVERICK_FLOAT"},
    {0x200, "EF_ARM_ABI_FLOAT_SOFT"},
    {0x400, "EF_ARM_ABI_FLOAT_HARD"}
};

const defines_map elf_ef_arm_b01 = {
    {0x04, "EF_ARM_SYMSARESORTED"},
    {0x08, "EF_ARM_DYNSYMSUSESEGIDX"},
    {0x10, "EF_ARM_MAPSYMSFIRST"},
    {0XFF000000, "EF_ARM_EABIMASK"}
};

const defines_map elf_ef_arm_aaelf = {
    {0x00800000, "EF_ARM_BE8"},
    {0x00400000, "EF_ARM_LE8"}
};

const defines_map elf_ef_arm_eabi = {
    {0x00000000, "EF_ARM_EABI_UNKNOWN"},
    {0x01000000, "EF_ARM_EABI_VER1"},
    {0x02000000, "EF_ARM_EABI_VER2"},
    {0x03000000, "EF_ARM_EABI_VER3"},
    {0x04000000, "EF_ARM_EABI_VER4"},
    {0x05000000, "EF_ARM_EABI_VER5"}
};

const defines_map elf_stt_arm = {
    {13, "STT_ARM_TFUNC"},
    {15, "STT_ARM_16BIT"}
};

const defines_map elf_shf_arm = {
    {0x10000000, "SHF_ARM_ENTRYSECT"},
    {0x80000000, "SHF_ARM_COMDEF"}
};

const defines_map elf_pf_arm = {
    {0x10000000, "PF_ARM_SB"},
    {0x20000000, "PF_ARM_PI"},
    {0x40000000, "PF_ARM_ABS"}
};

const defines_map elf_pt_arm = {
    {(0x70000000 + 1), "PT_ARM_EXIDX"}
};

const defines_map elf_sht_arm = {
    {(0x70000000 + 1), "SHT_ARM_EXIDX"},
    {(0x70000000 + 2), "SHT_ARM_PREEMPTMAP"},
    {(0x70000000 + 3), "SHT_ARM_ATTRIBUTES"}
};

const defines_map elf_r_aarch64 = {
    {0, "R_AARCH64_NONE"},
    {257, "R_AARCH64_ABS64"},
    {258, "R_AARCH64_ABS32"},
    {259, "R_AARCH64_ABS16"},
    {260, "R_AARCH64_PREL64"},
    {261, "R_AARCH64_PREL32"},
    {262, "R_AARCH64_PREL16"},
    {263, "R_AARCH64_MOVW_UABS_G0"},
    {264, "R_AARCH64_MOVW_UABS_G0_NC"},
    {265, "R_AARCH64_MOVW_UABS_G1"},
    {266, "R_AARCH64_MOVW_UABS_G1_NC"},
    {267, "R_AARCH64_MOVW_UABS_G2"},
    {268, "R_AARCH64_MOVW_UABS_G2_NC"},
    {269, "R_AARCH64_MOVW_UABS_G3"},
    {270, "R_AARCH64_MOVW_SABS_G0"},
    {271, "R_AARCH64_MOVW_SABS_G1"},
    {272, "R_AARCH64_MOVW_SABS_G2"},
    {273, "R_AARCH64_LD_PREL_LO19"},
    {274, "R_AARCH64_ADR_PREL_LO21"},
    {275, "R_AARCH64_ADR_PREL_PG_HI21"},
    {276, "R_AARCH64_ADR_PREL_PG_HI21_NC"},
    {277, "R_AARCH64_ADD_ABS_LO12_NC"},
    {278, "R_AARCH64_LDST8_ABS_LO12_NC"},
    {279, "R_AARCH64_TSTBR14"},
    {280, "R_AARCH64_CONDBR19"},
    {282, "R_AARCH64_JUMP26"},
    {283, "R_AARCH64_CALL26"},
    {284, "R_AARCH64_LDST16_ABS_LO12_NC"},
    {285, "R_AARCH64_LDST32_ABS_LO12_NC"},
    {286, "R_AARCH64_LDST64_ABS_LO12_NC"},
    {287, "R_AARCH64_MOVW_PREL_G0"},
    {288, "R_AARCH64_MOVW_PREL_G0_NC"},
    {289, "R_AARCH64_MOVW_PREL_G1"},
    {290, "R_AARCH64_MOVW_PREL_G1_NC"},
    {291, "R_AARCH64_MOVW_PREL_G2"},
    {292, "R_AARCH64_MOVW_PREL_G2_NC"},
    {293, "R_AARCH64_MOVW_PREL_G3"},
    {299, "R_AARCH64_LDST128_ABS_LO12_NC"},
    {300, "R_AARCH64_MOVW_GOTOFF_G0"},
    {301, "R_AARCH64_MOVW_GOTOFF_G0_NC"},
    {302, "R_AARCH64_MOVW_GOTOFF_G1"},
    {303, "R_AARCH64_MOVW_GOTOFF_G1_NC"},
    {304, "R_AARCH64_MOVW_GOTOFF_G2"},
    {305, "R_AARCH64_MOVW_GOTOFF_G2_NC"},
    {306, "R_AARCH64_MOVW_GOTOFF_G3"},
    {307, "R_AARCH64_GOTREL64"},
    {308, "R_AARCH64_GOTREL32"},
    {309, "R_AARCH64_GOT_LD_PREL19"},
    {310, "R_AARCH64_LD64_GOTOFF_LO15"},
    {311, "R_AARCH64_ADR_GOT_PAGE"},
    {312, "R_AARCH64_LD64_GOT_LO12_NC"},
    {313, "R_AARCH64_LD64_GOTPAGE_LO15"},
    {512, "R_AARCH64_TLSGD_ADR_PREL21"},
    {513, "R_AARCH64_TLSGD_ADR_PAGE21"},
    {514, "R_AARCH64_TLSGD_ADD_LO12_NC"},
    {515, "R_AARCH64_TLSGD_MOVW_G1"},
    {516, "R_AARCH64_TLSGD_MOVW_G0_NC"},
    {517, "R_AARCH64_TLSLD_ADR_PREL21"},
    {518, "R_AARCH64_TLSLD_ADR_PAGE21"},
    {519, "R_AARCH64_TLSLD_ADD_LO12_NC"},
    {520, "R_AARCH64_TLSLD_MOVW_G1"},
    {521, "R_AARCH64_TLSLD_MOVW_G0_NC"},
    {522, "R_AARCH64_TLSLD_LD_PREL19"},
    {523, "R_AARCH64_TLSLD_MOVW_DTPREL_G2"},
    {524, "R_AARCH64_TLSLD_MOVW_DTPREL_G1"},
    {525, "R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC"},
    {526, "R_AARCH64_TLSLD_MOVW_DTPREL_G0"},
    {527, "R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC"},
    {528, "R_AARCH64_TLSLD_ADD_DTPREL_HI12"},
    {529, "R_AARCH64_TLSLD_ADD_DTPREL_LO12"},
    {530, "R_AARCH64_TLSLD_ADD_DTPREL_LO12_NC"},
    {531, "R_AARCH64_TLSLD_LDST8_DTPREL_LO12"},
    {532, "R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC"},
    {533, "R_AARCH64_TLSLD_LDST16_DTPREL_LO12"},
    {534, "R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC"},
    {535, "R_AARCH64_TLSLD_LDST32_DTPREL_LO12"},
    {536, "R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC"},
    {537, "R_AARCH64_TLSLD_LDST64_DTPREL_LO12"},
    {538, "R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC"},
    {539, "R_AARCH64_TLSIE_MOVW_GOTTPREL_G1"},
    {540, "R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC"},
    {541, "R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21"},
    {542, "R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC"},
    {543, "R_AARCH64_TLSIE_LD_GOTTPREL_PREL19"},
    {544, "R_AARCH64_TLSLE_MOVW_TPREL_G2"},
    {545, "R_AARCH64_TLSLE_MOVW_TPREL_G1"},
    {546, "R_AARCH64_TLSLE_MOVW_TPREL_G1_NC"},
    {547, "R_AARCH64_TLSLE_MOVW_TPREL_G0"},
    {548, "R_AARCH64_TLSLE_MOVW_TPREL_G0_NC"},
    {549, "R_AARCH64_TLSLE_ADD_TPREL_HI12"},
    {550, "R_AARCH64_TLSLE_ADD_TPREL_LO12"},
    {551, "R_AARCH64_TLSLE_ADD_TPREL_LO12_NC"},
    {552, "R_AARCH64_TLSLE_LDST8_TPREL_LO12"},
    {553, "R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC"},
    {554, "R_AARCH64_TLSLE_LDST16_TPREL_LO12"},
    {555, "R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC"},
    {556, "R_AARCH64_TLSLE_LDST32_TPREL_LO12"},
    {557, "R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC"},
    {558, "R_AARCH64_TLSLE_LDST64_TPREL_LO12"},
    {559, "R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC"},
    {560, "R_AARCH64_TLSDESC_LD_PREL19"},
    {561, "R_AARCH64_TLSDESC_ADR_PREL21"},
    {562, "R_AARCH64_TLSDESC_ADR_PAGE21"},
    {563, "R_AARCH64_TLSDESC_LD64_LO12"},
    {564, "R_AARCH64_TLSDESC_ADD_LO12"},
    {565, "R_AARCH64_TLSDESC_OFF_G1"},
    {566, "R_AARCH64_TLSDESC_OFF_G0_NC"},
    {567, "R_AARCH64_TLSDESC_LDR"},
    {568, "R_AARCH64_TLSDESC_ADD"},
    {569, "R_AARCH64_TLSDESC_CALL"},
    {570, "R_AARCH64_TLSLE_LDST128_TPREL_LO12"},
    {571, "R_AARCH64_TLSLE_LDST128_TPREL_LO12_NC"},
    {572, "R_AARCH64_TLSLD_LDST128_DTPREL_LO12"},
    {573, "R_AARCH64_TLSLD_LDST128_DTPREL_LO12_NC"},
    {1024, "R_AARCH64_COPY"},
    {1025, "R_AARCH64_GLOB_DAT"},
    {1026, "R_AARCH64_JUMP_SLOT"},
    {1027, "R_AARCH64_RELATIVE"},
    {1028, "R_AARCH64_TLS_DTPMOD"},
    {1029, "R_AARCH64_TLS_DTPREL"},
    {1030, "R_AARCH64_TLS_TPREL"},
    {1031, "R_AARCH64_TLSDESC"},
    {1032, "R_AARCH64_IRELATIVE"}
};

const defines_map elf_pt_aarch64 = {
    {(0x70000000 + 2), "PT_AARCH64_MEMTAG_MTE"}
};

const defines_map elf_dt_aarch64 = {
    {(0x70000000 + 1), "DT_AARCH64_BTI_PLT"},
    {(0x70000000 + 3), "DT_AARCH64_PAC_PLT"},
    {(0x70000000 + 5), "DT_AARCH64_VARIANT_PCS"},
    {6, "DT_AARCH64_NUM"}
};

const defines_map elf_sto_aarch64 = {
    {0x80, "STO_AARCH64_VARIANT_PCS"}
};

const defines_map elf_r_arm = {
    {0, "R_ARM_NONE"},
    {1, "R_ARM_PC24"},
    {2, "R_ARM_ABS32"},
    {3, "R_ARM_REL32"},
    {4, "R_ARM_PC13"},
    {5, "R_ARM_ABS16"},
    {6, "R_ARM_ABS12"},
    {7, "R_ARM_THM_ABS5"},
    {8, "R_ARM_ABS8"},
    {9, "R_ARM_SBREL32"},
    {10, "R_ARM_THM_PC22"},
    {11, "R_ARM_THM_PC8"},
    {12, "R_ARM_AMP_VCALL9"},
    {13, "R_ARM_SWI24"},
    {13, "R_ARM_TLS_DESC"},
    {14, "R_ARM_THM_SWI8"},
    {15, "R_ARM_XPC25"},
    {16, "R_ARM_THM_XPC22"},
    {17, "R_ARM_TLS_DTPMOD32"},
    {18, "R_ARM_TLS_DTPOFF32"},
    {19, "R_ARM_TLS_TPOFF32"},
    {20, "R_ARM_COPY"},
    {21, "R_ARM_GLOB_DAT"},
    {22, "R_ARM_JUMP_SLOT"},
    {23, "R_ARM_RELATIVE"},
    {24, "R_ARM_GOTOFF"},
    {25, "R_ARM_GOTPC"},
    {26, "R_ARM_GOT32"},
    {27, "R_ARM_PLT32"},
    {28, "R_ARM_CALL"},
    {29, "R_ARM_JUMP24"},
    {30, "R_ARM_THM_JUMP24"},
    {31, "R_ARM_BASE_ABS"},
    {32, "R_ARM_ALU_PCREL_7_0"},
    {33, "R_ARM_ALU_PCREL_15_8"},
    {34, "R_ARM_ALU_PCREL_23_15"},
    {35, "R_ARM_LDR_SBREL_11_0"},
    {36, "R_ARM_ALU_SBREL_19_12"},
    {37, "R_ARM_ALU_SBREL_27_20"},
    {38, "R_ARM_TARGET1"},
    {39, "R_ARM_SBREL31"},
    {40, "R_ARM_V4BX"},
    {41, "R_ARM_TARGET2"},
    {42, "R_ARM_PREL31"},
    {43, "R_ARM_MOVW_ABS_NC"},
    {44, "R_ARM_MOVT_ABS"},
    {45, "R_ARM_MOVW_PREL_NC"},
    {46, "R_ARM_MOVT_PREL"},
    {47, "R_ARM_THM_MOVW_ABS_NC"},
    {48, "R_ARM_THM_MOVT_ABS"},
    {49, "R_ARM_THM_MOVW_PREL_NC"},
    {50, "R_ARM_THM_MOVT_PREL"},
    {51, "R_ARM_THM_JUMP19"},
    {52, "R_ARM_THM_JUMP6"},
    {53, "R_ARM_THM_ALU_PREL_11_0"},
    {54, "R_ARM_THM_PC12"},
    {55, "R_ARM_ABS32_NOI"},
    {56, "R_ARM_REL32_NOI"},
    {57, "R_ARM_ALU_PC_G0_NC"},
    {58, "R_ARM_ALU_PC_G0"},
    {59, "R_ARM_ALU_PC_G1_NC"},
    {60, "R_ARM_ALU_PC_G1"},
    {61, "R_ARM_ALU_PC_G2"},
    {62, "R_ARM_LDR_PC_G1"},
    {63, "R_ARM_LDR_PC_G2"},
    {64, "R_ARM_LDRS_PC_G0"},
    {65, "R_ARM_LDRS_PC_G1"},
    {66, "R_ARM_LDRS_PC_G2"},
    {67, "R_ARM_LDC_PC_G0"},
    {68, "R_ARM_LDC_PC_G1"},
    {69, "R_ARM_LDC_PC_G2"},
    {70, "R_ARM_ALU_SB_G0_NC"},
    {71, "R_ARM_ALU_SB_G0"},
    {72, "R_ARM_ALU_SB_G1_NC"},
    {73, "R_ARM_ALU_SB_G1"},
    {74, "R_ARM_ALU_SB_G2"},
    {75, "R_ARM_LDR_SB_G0"},
    {76, "R_ARM_LDR_SB_G1"},
    {77, "R_ARM_LDR_SB_G2"},
    {78, "R_ARM_LDRS_SB_G0"},
    {79, "R_ARM_LDRS_SB_G1"},
    {80, "R_ARM_LDRS_SB_G2"},
    {81, "R_ARM_LDC_SB_G0"},
    {82, "R_ARM_LDC_SB_G1"},
    {83, "R_ARM_LDC_SB_G2"},
    {84, "R_ARM_MOVW_BREL_NC"},
    {85, "R_ARM_MOVT_BREL"},
    {86, "R_ARM_MOVW_BREL"},
    {87, "R_ARM_THM_MOVW_BREL_NC"},
    {88, "R_ARM_THM_MOVT_BREL"},
    {89, "R_ARM_THM_MOVW_BREL"},
    {90, "R_ARM_TLS_GOTDESC"},
    {91, "R_ARM_TLS_CALL"},
    {92, "R_ARM_TLS_DESCSEQ"},
    {93, "R_ARM_THM_TLS_CALL"},
    {94, "R_ARM_PLT32_ABS"},
    {95, "R_ARM_GOT_ABS"},
    {96, "R_ARM_GOT_PREL"},
    {97, "R_ARM_GOT_BREL12"},
    {98, "R_ARM_GOTOFF12"},
    {99, "R_ARM_GOTRELAX"},
    {100, "R_ARM_GNU_VTENTRY"},
    {101, "R_ARM_GNU_VTINHERIT"},
    {102, "R_ARM_THM_PC11"},
    {103, "R_ARM_THM_PC9"},
    {104, "R_ARM_TLS_GD32"},
    {105, "R_ARM_TLS_LDM32"},
    {106, "R_ARM_TLS_LDO32"},
    {107, "R_ARM_TLS_IE32"},
    {108, "R_ARM_TLS_LE32"},
    {109, "R_ARM_TLS_LDO12"},
    {110, "R_ARM_TLS_LE12"},
    {111, "R_ARM_TLS_IE12GP"},
    {128, "R_ARM_ME_TOO"},
    {129, "R_ARM_THM_TLS_DESCSEQ"},
    {129, "R_ARM_THM_TLS_DESCSEQ16"},
    {130, "R_ARM_THM_TLS_DESCSEQ32"},
    {131, "R_ARM_THM_GOT_BREL12"},
    {160, "R_ARM_IRELATIVE"},
    {249, "R_ARM_RXPC25"},
    {250, "R_ARM_RSBREL32"},
    {251, "R_ARM_THM_RPC22"},
    {252, "R_ARM_RREL32"},
    {253, "R_ARM_RABS22"},
    {254, "R_ARM_RPC24"},
    {255, "R_ARM_RBASE"},
    {256, "R_ARM_NUM"}
};

const defines_map elf_r_ckcore = {
    {0, "R_CKCORE_NONE"},
    {1, "R_CKCORE_ADDR32"},
    {2, "R_CKCORE_PCRELIMM8BY4"},
    {3, "R_CKCORE_PCRELIMM11BY2"},
    {5, "R_CKCORE_PCREL32"},
    {6, "R_CKCORE_PCRELJSR_IMM11BY2"},
    {9, "R_CKCORE_RELATIVE"},
    {10, "R_CKCORE_COPY"},
    {11, "R_CKCORE_GLOB_DAT"},
    {12, "R_CKCORE_JUMP_SLOT"},
    {13, "R_CKCORE_GOTOFF"},
    {14, "R_CKCORE_GOTPC"},
    {15, "R_CKCORE_GOT32"},
    {16, "R_CKCORE_PLT32"},
    {17, "R_CKCORE_ADDRGOT"},
    {18, "R_CKCORE_ADDRPLT"},
    {19, "R_CKCORE_PCREL_IMM26BY2"},
    {20, "R_CKCORE_PCREL_IMM16BY2"},
    {21, "R_CKCORE_PCREL_IMM16BY4"},
    {22, "R_CKCORE_PCREL_IMM10BY2"},
    {23, "R_CKCORE_PCREL_IMM10BY4"},
    {24, "R_CKCORE_ADDR_HI16"},
    {25, "R_CKCORE_ADDR_LO16"},
    {26, "R_CKCORE_GOTPC_HI16"},
    {27, "R_CKCORE_GOTPC_LO16"},
    {28, "R_CKCORE_GOTOFF_HI16"},
    {29, "R_CKCORE_GOTOFF_LO16"},
    {30, "R_CKCORE_GOT12"},
    {31, "R_CKCORE_GOT_HI16"},
    {32, "R_CKCORE_GOT_LO16"},
    {33, "R_CKCORE_PLT12"},
    {34, "R_CKCORE_PLT_HI16"},
    {35, "R_CKCORE_PLT_LO16"},
    {36, "R_CKCORE_ADDRGOT_HI16"},
    {37, "R_CKCORE_ADDRGOT_LO16"},
    {38, "R_CKCORE_ADDRPLT_HI16"},
    {39, "R_CKCORE_ADDRPLT_LO16"},
    {40, "R_CKCORE_PCREL_JSR_IMM26BY2"},
    {41, "R_CKCORE_TOFFSET_LO16"},
    {42, "R_CKCORE_DOFFSET_LO16"},
    {43, "R_CKCORE_PCREL_IMM18BY2"},
    {44, "R_CKCORE_DOFFSET_IMM18"},
    {45, "R_CKCORE_DOFFSET_IMM18BY2"},
    {46, "R_CKCORE_DOFFSET_IMM18BY4"},
    {48, "R_CKCORE_GOT_IMM18BY4"},
    {49, "R_CKCORE_PLT_IMM18BY4"},
    {50, "R_CKCORE_PCREL_IMM7BY4"},
    {51, "R_CKCORE_TLS_LE32"},
    {52, "R_CKCORE_TLS_IE32"},
    {53, "R_CKCORE_TLS_GD32"},
    {54, "R_CKCORE_TLS_LDM32"},
    {55, "R_CKCORE_TLS_LDO32"},
    {56, "R_CKCORE_TLS_DTPMOD32"},
    {57, "R_CKCORE_TLS_DTPOFF32"},
    {58, "R_CKCORE_TLS_TPOFF32"}
};

const defines_map elf_ef_csky = {
    {0XF0000000, "EF_CSKY_ABIMASK"},
    {0X0FFF0000, "EF_CSKY_OTHER"},
    {0X0000FFFF, "EF_CSKY_PROCESSOR"}
};

const defines_map elf_ef_csky_abiv = {
    {0X10000000, "EF_CSKY_ABIV1"},
    {0X20000000, "EF_CSKY_ABIV2"}
};

const defines_map elf_sht_csky = {
    {(0x70000000 + 1), "SHT_CSKY_ATTRIBUTES"}
};

const defines_map elf_ef_ia_64 = {
    {0x0000000f, "EF_IA_64_MASKOS"},
    {0x00000010, "EF_IA_64_ABI64"},
    {0xff000000, "EF_IA_64_ARCH"}
};

const defines_map elf_pt_ia_64 = {
    {(0x70000000 + 0), "PT_IA_64_ARCHEXT"},
    {(0x70000000 + 1), "PT_IA_64_UNWIND"},
    {(0x60000000 + 0x12), "PT_IA_64_HP_OPT_ANOT"},
    {(0x60000000 + 0x13), "PT_IA_64_HP_HSL_ANOT"},
    {(0x60000000 + 0x14), "PT_IA_64_HP_STACK"}
};

const defines_map elf_pf_ia_64 = {
    {0x80000000, "PF_IA_64_NORECOV"}
};

const defines_map elf_sht_ia_64 = {
    {(0x70000000 + 0), "SHT_IA_64_EXT"},
    {(0x70000000 + 1), "SHT_IA_64_UNWIND"}
};

const defines_map elf_shf_ia_64 = {
    {0x10000000, "SHF_IA_64_SHORT"},
    {0x20000000, "SHF_IA_64_NORECOV"}
};

const defines_map elf_dt_ia_64 = {
    {(0x70000000 + 0), "DT_IA_64_PLT_RESERVE"},
    {1, "DT_IA_64_NUM"}
};

const defines_map elf_r_ia64 = {
    {0x00, "R_IA64_NONE"},
    {0x21, "R_IA64_IMM14"},
    {0x22, "R_IA64_IMM22"},
    {0x23, "R_IA64_IMM64"},
    {0x24, "R_IA64_DIR32MSB"},
    {0x25, "R_IA64_DIR32LSB"},
    {0x26, "R_IA64_DIR64MSB"},
    {0x27, "R_IA64_DIR64LSB"},
    {0x2a, "R_IA64_GPREL22"},
    {0x2b, "R_IA64_GPREL64I"},
    {0x2c, "R_IA64_GPREL32MSB"},
    {0x2d, "R_IA64_GPREL32LSB"},
    {0x2e, "R_IA64_GPREL64MSB"},
    {0x2f, "R_IA64_GPREL64LSB"},
    {0x32, "R_IA64_LTOFF22"},
    {0x33, "R_IA64_LTOFF64I"},
    {0x3a, "R_IA64_PLTOFF22"},
    {0x3b, "R_IA64_PLTOFF64I"},
    {0x3e, "R_IA64_PLTOFF64MSB"},
    {0x3f, "R_IA64_PLTOFF64LSB"},
    {0x43, "R_IA64_FPTR64I"},
    {0x44, "R_IA64_FPTR32MSB"},
    {0x45, "R_IA64_FPTR32LSB"},
    {0x46, "R_IA64_FPTR64MSB"},
    {0x47, "R_IA64_FPTR64LSB"},
    {0x48, "R_IA64_PCREL60B"},
    {0x49, "R_IA64_PCREL21B"},
    {0x4a, "R_IA64_PCREL21M"},
    {0x4b, "R_IA64_PCREL21F"},
    {0x4c, "R_IA64_PCREL32MSB"},
    {0x4d, "R_IA64_PCREL32LSB"},
    {0x4e, "R_IA64_PCREL64MSB"},
    {0x4f, "R_IA64_PCREL64LSB"},
    {0x52, "R_IA64_LTOFF_FPTR22"},
    {0x53, "R_IA64_LTOFF_FPTR64I"},
    {0x54, "R_IA64_LTOFF_FPTR32MSB"},
    {0x55, "R_IA64_LTOFF_FPTR32LSB"},
    {0x56, "R_IA64_LTOFF_FPTR64MSB"},
    {0x57, "R_IA64_LTOFF_FPTR64LSB"},
    {0x5c, "R_IA64_SEGREL32MSB"},
    {0x5d, "R_IA64_SEGREL32LSB"},
    {0x5e, "R_IA64_SEGREL64MSB"},
    {0x5f, "R_IA64_SEGREL64LSB"},
    {0x64, "R_IA64_SECREL32MSB"},
    {0x65, "R_IA64_SECREL32LSB"},
    {0x66, "R_IA64_SECREL64MSB"},
    {0x67, "R_IA64_SECREL64LSB"},
    {0x6c, "R_IA64_REL32MSB"},
    {0x6d, "R_IA64_REL32LSB"},
    {0x6e, "R_IA64_REL64MSB"},
    {0x6f, "R_IA64_REL64LSB"},
    {0x74, "R_IA64_LTV32MSB"},
    {0x75, "R_IA64_LTV32LSB"},
    {0x76, "R_IA64_LTV64MSB"},
    {0x77, "R_IA64_LTV64LSB"},
    {0x79, "R_IA64_PCREL21BI"},
    {0x7a, "R_IA64_PCREL22"},
    {0x7b, "R_IA64_PCREL64I"},
    {0x80, "R_IA64_IPLTMSB"},
    {0x81, "R_IA64_IPLTLSB"},
    {0x84, "R_IA64_COPY"},
    {0x85, "R_IA64_SUB"},
    {0x86, "R_IA64_LTOFF22X"},
    {0x87, "R_IA64_LDXMOV"},
    {0x91, "R_IA64_TPREL14"},
    {0x92, "R_IA64_TPREL22"},
    {0x93, "R_IA64_TPREL64I"},
    {0x96, "R_IA64_TPREL64MSB"},
    {0x97, "R_IA64_TPREL64LSB"},
    {0x9a, "R_IA64_LTOFF_TPREL22"},
    {0xa6, "R_IA64_DTPMOD64MSB"},
    {0xa7, "R_IA64_DTPMOD64LSB"},
    {0xaa, "R_IA64_LTOFF_DTPMOD22"},
    {0xb1, "R_IA64_DTPREL14"},
    {0xb2, "R_IA64_DTPREL22"},
    {0xb3, "R_IA64_DTPREL64I"},
    {0xb4, "R_IA64_DTPREL32MSB"},
    {0xb5, "R_IA64_DTPREL32LSB"},
    {0xb6, "R_IA64_DTPREL64MSB"},
    {0xb7, "R_IA64_DTPREL64LSB"},
    {0xba, "R_IA64_LTOFF_DTPREL22"}
};

const defines_map elf_ef_sh = {
    {0x1f, "EF_SH_MACH_MASK"},
    {0x0, "EF_SH_UNKNOWN"},
    {0x1, "EF_SH1"},
    {0x2, "EF_SH2"},
    {0x3, "EF_SH3"},
    {0x4, "EF_SH_DSP"},
    {0x5, "EF_SH3_DSP"},
    {0x6, "EF_SH4AL_DSP"},
    {0x8, "EF_SH3E"},
    {0x9, "EF_SH4"},
    {0xb, "EF_SH2E"},
    {0xc, "EF_SH4A"},
    {0xd, "EF_SH2A"},
    {0x10, "EF_SH4_NOFPU"},
    {0x11, "EF_SH4A_NOFPU"},
    {0x12, "EF_SH4_NOMMU_NOFPU"},
    {0x13, "EF_SH2A_NOFPU"},
    {0x14, "EF_SH3_NOMMU"},
    {0x15, "EF_SH2A_SH4_NOFPU"},
    {0x16, "EF_SH2A_SH3_NOFPU"},
    {0x17, "EF_SH2A_SH4"},
    {0x18, "EF_SH2A_SH3E"}
};

const defines_map elf_r_sh = {
    {0, "R_SH_NONE"},
    {1, "R_SH_DIR32"},
    {2, "R_SH_REL32"},
    {3, "R_SH_DIR8WPN"},
    {4, "R_SH_IND12W"},
    {5, "R_SH_DIR8WPL"},
    {6, "R_SH_DIR8WPZ"},
    {7, "R_SH_DIR8BP"},
    {8, "R_SH_DIR8W"},
    {9, "R_SH_DIR8L"},
    {25, "R_SH_SWITCH16"},
    {26, "R_SH_SWITCH32"},
    {27, "R_SH_USES"},
    {28, "R_SH_COUNT"},
    {29, "R_SH_ALIGN"},
    {30, "R_SH_CODE"},
    {31, "R_SH_DATA"},
    {32, "R_SH_LABEL"},
    {33, "R_SH_SWITCH8"},
    {34, "R_SH_GNU_VTINHERIT"},
    {35, "R_SH_GNU_VTENTRY"},
    {144, "R_SH_TLS_GD_32"},
    {145, "R_SH_TLS_LD_32"},
    {146, "R_SH_TLS_LDO_32"},
    {147, "R_SH_TLS_IE_32"},
    {148, "R_SH_TLS_LE_32"},
    {149, "R_SH_TLS_DTPMOD32"},
    {150, "R_SH_TLS_DTPOFF32"},
    {151, "R_SH_TLS_TPOFF32"},
    {160, "R_SH_GOT32"},
    {161, "R_SH_PLT32"},
    {162, "R_SH_COPY"},
    {163, "R_SH_GLOB_DAT"},
    {164, "R_SH_JMP_SLOT"},
    {165, "R_SH_RELATIVE"},
    {166, "R_SH_GOTOFF"},
    {167, "R_SH_GOTPC"},
    {256, "R_SH_NUM"}
};

const defines_map elf_ef_s390 = {
    {0x00000001, "EF_S390_HIGH_GPRS"}
};

const defines_map elf_r_390 = {
    {0, "R_390_NONE"},
    {1, "R_390_8"},
    {2, "R_390_12"},
    {3, "R_390_16"},
    {4, "R_390_32"},
    {5, "R_390_PC32"},
    {6, "R_390_GOT12"},
    {7, "R_390_GOT32"},
    {8, "R_390_PLT32"},
    {9, "R_390_COPY"},
    {10, "R_390_GLOB_DAT"},
    {11, "R_390_JMP_SLOT"},
    {12, "R_390_RELATIVE"},
    {13, "R_390_GOTOFF32"},
    {14, "R_390_GOTPC"},
    {15, "R_390_GOT16"},
    {16, "R_390_PC16"},
    {17, "R_390_PC16DBL"},
    {18, "R_390_PLT16DBL"},
    {19, "R_390_PC32DBL"},
    {20, "R_390_PLT32DBL"},
    {21, "R_390_GOTPCDBL"},
    {22, "R_390_64"},
    {23, "R_390_PC64"},
    {24, "R_390_GOT64"},
    {25, "R_390_PLT64"},
    {26, "R_390_GOTENT"},
    {27, "R_390_GOTOFF16"},
    {28, "R_390_GOTOFF64"},
    {29, "R_390_GOTPLT12"},
    {30, "R_390_GOTPLT16"},
    {31, "R_390_GOTPLT32"},
    {32, "R_390_GOTPLT64"},
    {33, "R_390_GOTPLTENT"},
    {34, "R_390_PLTOFF16"},
    {35, "R_390_PLTOFF32"},
    {36, "R_390_PLTOFF64"},
    {37, "R_390_TLS_LOAD"},
    {38, "R_390_TLS_GDCALL"},
    {39, "R_390_TLS_LDCALL"},
    {40, "R_390_TLS_GD32"},
    {41, "R_390_TLS_GD64"},
    {42, "R_390_TLS_GOTIE12"},
    {43, "R_390_TLS_GOTIE32"},
    {44, "R_390_TLS_GOTIE64"},
    {45, "R_390_TLS_LDM32"},
    {46, "R_390_TLS_LDM64"},
    {47, "R_390_TLS_IE32"},
    {48, "R_390_TLS_IE64"},
    {49, "R_390_TLS_IEENT"},
    {50, "R_390_TLS_LE32"},
    {51, "R_390_TLS_LE64"},
    {52, "R_390_TLS_LDO32"},
    {53, "R_390_TLS_LDO64"},
    {54, "R_390_TLS_DTPMOD"},
    {55, "R_390_TLS_DTPOFF"},
    {56, "R_390_TLS_TPOFF"},
    {57, "R_390_20"},
    {58, "R_390_GOT20"},
    {59, "R_390_GOTPLT20"},
    {60, "R_390_TLS_GOTIE20"},
    {61, "R_390_IRELATIVE"},
    {62, "R_390_NUM"}
};

const defines_map elf_r_cris = {
    {0, "R_CRIS_NONE"},
    {1, "R_CRIS_8"},
    {2, "R_CRIS_16"},
    {3, "R_CRIS_32"},
    {4, "R_CRIS_8_PCREL"},
    {5, "R_CRIS_16_PCREL"},
    {6, "R_CRIS_32_PCREL"},
    {7, "R_CRIS_GNU_VTINHERIT"},
    {8, "R_CRIS_GNU_VTENTRY"},
    {9, "R_CRIS_COPY"},
    {10, "R_CRIS_GLOB_DAT"},
    {11, "R_CRIS_JUMP_SLOT"},
    {12, "R_CRIS_RELATIVE"},
    {13, "R_CRIS_16_GOT"},
    {14, "R_CRIS_32_GOT"},
    {15, "R_CRIS_16_GOTPLT"},
    {16, "R_CRIS_32_GOTPLT"},
    {17, "R_CRIS_32_GOTREL"},
    {18, "R_CRIS_32_PLT_GOTREL"},
    {19, "R_CRIS_32_PLT_PCREL"},
    {20, "R_CRIS_NUM"}
};

const defines_map elf_r_x86_64 = {
    {0, "R_X86_64_NONE"},
    {1, "R_X86_64_64"},
    {2, "R_X86_64_PC32"},
    {3, "R_X86_64_GOT32"},
    {4, "R_X86_64_PLT32"},
    {5, "R_X86_64_COPY"},
    {6, "R_X86_64_GLOB_DAT"},
    {7, "R_X86_64_JUMP_SLOT"},
    {8, "R_X86_64_RELATIVE"},
    {9, "R_X86_64_GOTPCREL"},
    {10, "R_X86_64_32"},
    {11, "R_X86_64_32S"},
    {12, "R_X86_64_16"},
    {13, "R_X86_64_PC16"},
    {14, "R_X86_64_8"},
    {15, "R_X86_64_PC8"},
    {16, "R_X86_64_DTPMOD64"},
    {17, "R_X86_64_DTPOFF64"},
    {18, "R_X86_64_TPOFF64"},
    {19, "R_X86_64_TLSGD"},
    {20, "R_X86_64_TLSLD"},
    {21, "R_X86_64_DTPOFF32"},
    {22, "R_X86_64_GOTTPOFF"},
    {23, "R_X86_64_TPOFF32"},
    {24, "R_X86_64_PC64"},
    {25, "R_X86_64_GOTOFF64"},
    {26, "R_X86_64_GOTPC32"},
    {27, "R_X86_64_GOT64"},
    {28, "R_X86_64_GOTPCREL64"},
    {29, "R_X86_64_GOTPC64"},
    {30, "R_X86_64_GOTPLT64"},
    {31, "R_X86_64_PLTOFF64"},
    {32, "R_X86_64_SIZE32"},
    {33, "R_X86_64_SIZE64"},
    {34, "R_X86_64_GOTPC32_TLSDESC"},
    {35, "R_X86_64_TLSDESC_CALL"},
    {36, "R_X86_64_TLSDESC"},
    {37, "R_X86_64_IRELATIVE"},
    {38, "R_X86_64_RELATIVE64"},
    {41, "R_X86_64_GOTPCRELX"},
    {42, "R_X86_64_REX_GOTPCRELX"},
    {43, "R_X86_64_NUM"}
};

const defines_map elf_sht_x86_64 = {
    {0x70000001, "SHT_X86_64_UNWIND"}
};

const defines_map elf_dt_x86_64 = {
    {(0x70000000 + 0), "DT_X86_64_PLT"},
    {(0x70000000 + 1), "DT_X86_64_PLTSZ"},
    {(0x70000000 + 3), "DT_X86_64_PLTENT"},
    {4, "DT_X86_64_NUM"}
};

const defines_map elf_r_mn10300 = {
    {0, "R_MN10300_NONE"},
    {1, "R_MN10300_32"},
    {2, "R_MN10300_16"},
    {3, "R_MN10300_8"},
    {4, "R_MN10300_PCREL32"},
    {5, "R_MN10300_PCREL16"},
    {6, "R_MN10300_PCREL8"},
    {7, "R_MN10300_GNU_VTINHERIT"},
    {8, "R_MN10300_GNU_VTENTRY"},
    {9, "R_MN10300_24"},
    {10, "R_MN10300_GOTPC32"},
    {11, "R_MN10300_GOTPC16"},
    {12, "R_MN10300_GOTOFF32"},
    {13, "R_MN10300_GOTOFF24"},
    {14, "R_MN10300_GOTOFF16"},
    {15, "R_MN10300_PLT32"},
    {16, "R_MN10300_PLT16"},
    {17, "R_MN10300_GOT32"},
    {18, "R_MN10300_GOT24"},
    {19, "R_MN10300_GOT16"},
    {20, "R_MN10300_COPY"},
    {21, "R_MN10300_GLOB_DAT"},
    {22, "R_MN10300_JMP_SLOT"},
    {23, "R_MN10300_RELATIVE"},
    {24, "R_MN10300_TLS_GD"},
    {25, "R_MN10300_TLS_LD"},
    {26, "R_MN10300_TLS_LDO"},
    {27, "R_MN10300_TLS_GOTIE"},
    {28, "R_MN10300_TLS_IE"},
    {29, "R_MN10300_TLS_LE"},
    {30, "R_MN10300_TLS_DTPMOD"},
    {31, "R_MN10300_TLS_DTPOFF"},
    {32, "R_MN10300_TLS_TPOFF"},
    {33, "R_MN10300_SYM_DIFF"},
    {34, "R_MN10300_ALIGN"},
    {35, "R_MN10300_NUM"}
};

const defines_map elf_r_m32r = {
    {0, "R_M32R_NONE"},
    {1, "R_M32R_16"},
    {2, "R_M32R_32"},
    {3, "R_M32R_24"},
    {4, "R_M32R_10_PCREL"},
    {5, "R_M32R_18_PCREL"},
    {6, "R_M32R_26_PCREL"},
    {7, "R_M32R_HI16_ULO"},
    {8, "R_M32R_HI16_SLO"},
    {9, "R_M32R_LO16"},
    {10, "R_M32R_SDA16"},
    {11, "R_M32R_GNU_VTINHERIT"},
    {12, "R_M32R_GNU_VTENTRY"},
    {33, "R_M32R_16_RELA"},
    {34, "R_M32R_32_RELA"},
    {35, "R_M32R_24_RELA"},
    {36, "R_M32R_10_PCREL_RELA"},
    {37, "R_M32R_18_PCREL_RELA"},
    {38, "R_M32R_26_PCREL_RELA"},
    {39, "R_M32R_HI16_ULO_RELA"},
    {40, "R_M32R_HI16_SLO_RELA"},
    {41, "R_M32R_LO16_RELA"},
    {42, "R_M32R_SDA16_RELA"},
    {43, "R_M32R_RELA_GNU_VTINHERIT"},
    {44, "R_M32R_RELA_GNU_VTENTRY"},
    {45, "R_M32R_REL32"},
    {48, "R_M32R_GOT24"},
    {49, "R_M32R_26_PLTREL"},
    {50, "R_M32R_COPY"},
    {51, "R_M32R_GLOB_DAT"},
    {52, "R_M32R_JMP_SLOT"},
    {53, "R_M32R_RELATIVE"},
    {54, "R_M32R_GOTOFF"},
    {55, "R_M32R_GOTPC24"},
    {56, "R_M32R_GOT16_HI_ULO"},
    {57, "R_M32R_GOT16_HI_SLO"},
    {58, "R_M32R_GOT16_LO"},
    {59, "R_M32R_GOTPC_HI_ULO"},
    {60, "R_M32R_GOTPC_HI_SLO"},
    {61, "R_M32R_GOTPC_LO"},
    {62, "R_M32R_GOTOFF_HI_ULO"},
    {63, "R_M32R_GOTOFF_HI_SLO"},
    {64, "R_M32R_GOTOFF_LO"},
    {256, "R_M32R_NUM"}
};

const defines_map elf_r_microblaze = {
    {0, "R_MICROBLAZE_NONE"},
    {1, "R_MICROBLAZE_32"},
    {2, "R_MICROBLAZE_32_PCREL"},
    {3, "R_MICROBLAZE_64_PCREL"},
    {4, "R_MICROBLAZE_32_PCREL_LO"},
    {5, "R_MICROBLAZE_64"},
    {6, "R_MICROBLAZE_32_LO"},
    {7, "R_MICROBLAZE_SRO32"},
    {8, "R_MICROBLAZE_SRW32"},
    {9, "R_MICROBLAZE_64_NONE"},
    {10, "R_MICROBLAZE_32_SYM_OP_SYM"},
    {11, "R_MICROBLAZE_GNU_VTINHERIT"},
    {12, "R_MICROBLAZE_GNU_VTENTRY"},
    {13, "R_MICROBLAZE_GOTPC_64"},
    {14, "R_MICROBLAZE_GOT_64"},
    {15, "R_MICROBLAZE_PLT_64"},
    {16, "R_MICROBLAZE_REL"},
    {17, "R_MICROBLAZE_JUMP_SLOT"},
    {18, "R_MICROBLAZE_GLOB_DAT"},
    {19, "R_MICROBLAZE_GOTOFF_64"},
    {20, "R_MICROBLAZE_GOTOFF_32"},
    {21, "R_MICROBLAZE_COPY"},
    {22, "R_MICROBLAZE_TLS"},
    {23, "R_MICROBLAZE_TLSGD"},
    {24, "R_MICROBLAZE_TLSLD"},
    {25, "R_MICROBLAZE_TLSDTPMOD32"},
    {26, "R_MICROBLAZE_TLSDTPREL32"},
    {27, "R_MICROBLAZE_TLSDTPREL64"},
    {28, "R_MICROBLAZE_TLSGOTTPREL32"},
    {29, "R_MICROBLAZE_TLSTPREL32"}
};

const defines_map elf_dt_nios2 = {
    {0x70000002, "DT_NIOS2_GP"}
};

const defines_map elf_r_nios2 = {
    {0, "R_NIOS2_NONE"},
    {1, "R_NIOS2_S16"},
    {2, "R_NIOS2_U16"},
    {3, "R_NIOS2_PCREL16"},
    {4, "R_NIOS2_CALL26"},
    {5, "R_NIOS2_IMM5"},
    {6, "R_NIOS2_CACHE_OPX"},
    {7, "R_NIOS2_IMM6"},
    {8, "R_NIOS2_IMM8"},
    {9, "R_NIOS2_HI16"},
    {10, "R_NIOS2_LO16"},
    {11, "R_NIOS2_HIADJ16"},
    {12, "R_NIOS2_BFD_RELOC_32"},
    {13, "R_NIOS2_BFD_RELOC_16"},
    {14, "R_NIOS2_BFD_RELOC_8"},
    {15, "R_NIOS2_GPREL"},
    {16, "R_NIOS2_GNU_VTINHERIT"},
    {17, "R_NIOS2_GNU_VTENTRY"},
    {18, "R_NIOS2_UJMP"},
    {19, "R_NIOS2_CJMP"},
    {20, "R_NIOS2_CALLR"},
    {21, "R_NIOS2_ALIGN"},
    {22, "R_NIOS2_GOT16"},
    {23, "R_NIOS2_CALL16"},
    {24, "R_NIOS2_GOTOFF_LO"},
    {25, "R_NIOS2_GOTOFF_HA"},
    {26, "R_NIOS2_PCREL_LO"},
    {27, "R_NIOS2_PCREL_HA"},
    {28, "R_NIOS2_TLS_GD16"},
    {29, "R_NIOS2_TLS_LDM16"},
    {30, "R_NIOS2_TLS_LDO16"},
    {31, "R_NIOS2_TLS_IE16"},
    {32, "R_NIOS2_TLS_LE16"},
    {33, "R_NIOS2_TLS_DTPMOD"},
    {34, "R_NIOS2_TLS_DTPREL"},
    {35, "R_NIOS2_TLS_TPREL"},
    {36, "R_NIOS2_COPY"},
    {37, "R_NIOS2_GLOB_DAT"},
    {38, "R_NIOS2_JUMP_SLOT"},
    {39, "R_NIOS2_RELATIVE"},
    {40, "R_NIOS2_GOTOFF"},
    {41, "R_NIOS2_CALL26_NOAT"},
    {42, "R_NIOS2_GOT_LO"},
    {43, "R_NIOS2_GOT_HA"},
    {44, "R_NIOS2_CALL_LO"},
    {45, "R_NIOS2_CALL_HA"}
};

const defines_map elf_r_tilepro = {
    {0, "R_TILEPRO_NONE"},
    {1, "R_TILEPRO_32"},
    {2, "R_TILEPRO_16"},
    {3, "R_TILEPRO_8"},
    {4, "R_TILEPRO_32_PCREL"},
    {5, "R_TILEPRO_16_PCREL"},
    {6, "R_TILEPRO_8_PCREL"},
    {7, "R_TILEPRO_LO16"},
    {8, "R_TILEPRO_HI16"},
    {9, "R_TILEPRO_HA16"},
    {10, "R_TILEPRO_COPY"},
    {11, "R_TILEPRO_GLOB_DAT"},
    {12, "R_TILEPRO_JMP_SLOT"},
    {13, "R_TILEPRO_RELATIVE"},
    {14, "R_TILEPRO_BROFF_X1"},
    {15, "R_TILEPRO_JOFFLONG_X1"},
    {16, "R_TILEPRO_JOFFLONG_X1_PLT"},
    {17, "R_TILEPRO_IMM8_X0"},
    {18, "R_TILEPRO_IMM8_Y0"},
    {19, "R_TILEPRO_IMM8_X1"},
    {20, "R_TILEPRO_IMM8_Y1"},
    {21, "R_TILEPRO_MT_IMM15_X1"},
    {22, "R_TILEPRO_MF_IMM15_X1"},
    {23, "R_TILEPRO_IMM16_X0"},
    {24, "R_TILEPRO_IMM16_X1"},
    {25, "R_TILEPRO_IMM16_X0_LO"},
    {26, "R_TILEPRO_IMM16_X1_LO"},
    {27, "R_TILEPRO_IMM16_X0_HI"},
    {28, "R_TILEPRO_IMM16_X1_HI"},
    {29, "R_TILEPRO_IMM16_X0_HA"},
    {30, "R_TILEPRO_IMM16_X1_HA"},
    {31, "R_TILEPRO_IMM16_X0_PCREL"},
    {32, "R_TILEPRO_IMM16_X1_PCREL"},
    {33, "R_TILEPRO_IMM16_X0_LO_PCREL"},
    {34, "R_TILEPRO_IMM16_X1_LO_PCREL"},
    {35, "R_TILEPRO_IMM16_X0_HI_PCREL"},
    {36, "R_TILEPRO_IMM16_X1_HI_PCREL"},
    {37, "R_TILEPRO_IMM16_X0_HA_PCREL"},
    {38, "R_TILEPRO_IMM16_X1_HA_PCREL"},
    {39, "R_TILEPRO_IMM16_X0_GOT"},
    {40, "R_TILEPRO_IMM16_X1_GOT"},
    {41, "R_TILEPRO_IMM16_X0_GOT_LO"},
    {42, "R_TILEPRO_IMM16_X1_GOT_LO"},
    {43, "R_TILEPRO_IMM16_X0_GOT_HI"},
    {44, "R_TILEPRO_IMM16_X1_GOT_HI"},
    {45, "R_TILEPRO_IMM16_X0_GOT_HA"},
    {46, "R_TILEPRO_IMM16_X1_GOT_HA"},
    {47, "R_TILEPRO_MMSTART_X0"},
    {48, "R_TILEPRO_MMEND_X0"},
    {49, "R_TILEPRO_MMSTART_X1"},
    {50, "R_TILEPRO_MMEND_X1"},
    {51, "R_TILEPRO_SHAMT_X0"},
    {52, "R_TILEPRO_SHAMT_X1"},
    {53, "R_TILEPRO_SHAMT_Y0"},
    {54, "R_TILEPRO_SHAMT_Y1"},
    {55, "R_TILEPRO_DEST_IMM8_X1"},
    {60, "R_TILEPRO_TLS_GD_CALL"},
    {61, "R_TILEPRO_IMM8_X0_TLS_GD_ADD"},
    {62, "R_TILEPRO_IMM8_X1_TLS_GD_ADD"},
    {63, "R_TILEPRO_IMM8_Y0_TLS_GD_ADD"},
    {64, "R_TILEPRO_IMM8_Y1_TLS_GD_ADD"},
    {65, "R_TILEPRO_TLS_IE_LOAD"},
    {66, "R_TILEPRO_IMM16_X0_TLS_GD"},
    {67, "R_TILEPRO_IMM16_X1_TLS_GD"},
    {68, "R_TILEPRO_IMM16_X0_TLS_GD_LO"},
    {69, "R_TILEPRO_IMM16_X1_TLS_GD_LO"},
    {70, "R_TILEPRO_IMM16_X0_TLS_GD_HI"},
    {71, "R_TILEPRO_IMM16_X1_TLS_GD_HI"},
    {72, "R_TILEPRO_IMM16_X0_TLS_GD_HA"},
    {73, "R_TILEPRO_IMM16_X1_TLS_GD_HA"},
    {74, "R_TILEPRO_IMM16_X0_TLS_IE"},
    {75, "R_TILEPRO_IMM16_X1_TLS_IE"},
    {76, "R_TILEPRO_IMM16_X0_TLS_IE_LO"},
    {77, "R_TILEPRO_IMM16_X1_TLS_IE_LO"},
    {78, "R_TILEPRO_IMM16_X0_TLS_IE_HI"},
    {79, "R_TILEPRO_IMM16_X1_TLS_IE_HI"},
    {80, "R_TILEPRO_IMM16_X0_TLS_IE_HA"},
    {81, "R_TILEPRO_IMM16_X1_TLS_IE_HA"},
    {82, "R_TILEPRO_TLS_DTPMOD32"},
    {83, "R_TILEPRO_TLS_DTPOFF32"},
    {84, "R_TILEPRO_TLS_TPOFF32"},
    {85, "R_TILEPRO_IMM16_X0_TLS_LE"},
    {86, "R_TILEPRO_IMM16_X1_TLS_LE"},
    {87, "R_TILEPRO_IMM16_X0_TLS_LE_LO"},
    {88, "R_TILEPRO_IMM16_X1_TLS_LE_LO"},
    {89, "R_TILEPRO_IMM16_X0_TLS_LE_HI"},
    {90, "R_TILEPRO_IMM16_X1_TLS_LE_HI"},
    {91, "R_TILEPRO_IMM16_X0_TLS_LE_HA"},
    {92, "R_TILEPRO_IMM16_X1_TLS_LE_HA"},
    {128, "R_TILEPRO_GNU_VTINHERIT"},
    {129, "R_TILEPRO_GNU_VTENTRY"},
    {130, "R_TILEPRO_NUM"}
};

const defines_map elf_r_tilegx = {
    {0, "R_TILEGX_NONE"},
    {1, "R_TILEGX_64"},
    {2, "R_TILEGX_32"},
    {3, "R_TILEGX_16"},
    {4, "R_TILEGX_8"},
    {5, "R_TILEGX_64_PCREL"},
    {6, "R_TILEGX_32_PCREL"},
    {7, "R_TILEGX_16_PCREL"},
    {8, "R_TILEGX_8_PCREL"},
    {9, "R_TILEGX_HW0"},
    {10, "R_TILEGX_HW1"},
    {11, "R_TILEGX_HW2"},
    {12, "R_TILEGX_HW3"},
    {13, "R_TILEGX_HW0_LAST"},
    {14, "R_TILEGX_HW1_LAST"},
    {15, "R_TILEGX_HW2_LAST"},
    {16, "R_TILEGX_COPY"},
    {17, "R_TILEGX_GLOB_DAT"},
    {18, "R_TILEGX_JMP_SLOT"},
    {19, "R_TILEGX_RELATIVE"},
    {20, "R_TILEGX_BROFF_X1"},
    {21, "R_TILEGX_JUMPOFF_X1"},
    {22, "R_TILEGX_JUMPOFF_X1_PLT"},
    {23, "R_TILEGX_IMM8_X0"},
    {24, "R_TILEGX_IMM8_Y0"},
    {25, "R_TILEGX_IMM8_X1"},
    {26, "R_TILEGX_IMM8_Y1"},
    {27, "R_TILEGX_DEST_IMM8_X1"},
    {28, "R_TILEGX_MT_IMM14_X1"},
    {29, "R_TILEGX_MF_IMM14_X1"},
    {30, "R_TILEGX_MMSTART_X0"},
    {31, "R_TILEGX_MMEND_X0"},
    {32, "R_TILEGX_SHAMT_X0"},
    {33, "R_TILEGX_SHAMT_X1"},
    {34, "R_TILEGX_SHAMT_Y0"},
    {35, "R_TILEGX_SHAMT_Y1"},
    {36, "R_TILEGX_IMM16_X0_HW0"},
    {37, "R_TILEGX_IMM16_X1_HW0"},
    {38, "R_TILEGX_IMM16_X0_HW1"},
    {39, "R_TILEGX_IMM16_X1_HW1"},
    {40, "R_TILEGX_IMM16_X0_HW2"},
    {41, "R_TILEGX_IMM16_X1_HW2"},
    {42, "R_TILEGX_IMM16_X0_HW3"},
    {43, "R_TILEGX_IMM16_X1_HW3"},
    {44, "R_TILEGX_IMM16_X0_HW0_LAST"},
    {45, "R_TILEGX_IMM16_X1_HW0_LAST"},
    {46, "R_TILEGX_IMM16_X0_HW1_LAST"},
    {47, "R_TILEGX_IMM16_X1_HW1_LAST"},
    {48, "R_TILEGX_IMM16_X0_HW2_LAST"},
    {49, "R_TILEGX_IMM16_X1_HW2_LAST"},
    {50, "R_TILEGX_IMM16_X0_HW0_PCREL"},
    {51, "R_TILEGX_IMM16_X1_HW0_PCREL"},
    {52, "R_TILEGX_IMM16_X0_HW1_PCREL"},
    {53, "R_TILEGX_IMM16_X1_HW1_PCREL"},
    {54, "R_TILEGX_IMM16_X0_HW2_PCREL"},
    {55, "R_TILEGX_IMM16_X1_HW2_PCREL"},
    {56, "R_TILEGX_IMM16_X0_HW3_PCREL"},
    {57, "R_TILEGX_IMM16_X1_HW3_PCREL"},
    {58, "R_TILEGX_IMM16_X0_HW0_LAST_PCREL"},
    {59, "R_TILEGX_IMM16_X1_HW0_LAST_PCREL"},
    {60, "R_TILEGX_IMM16_X0_HW1_LAST_PCREL"},
    {61, "R_TILEGX_IMM16_X1_HW1_LAST_PCREL"},
    {62, "R_TILEGX_IMM16_X0_HW2_LAST_PCREL"},
    {63, "R_TILEGX_IMM16_X1_HW2_LAST_PCREL"},
    {64, "R_TILEGX_IMM16_X0_HW0_GOT"},
    {65, "R_TILEGX_IMM16_X1_HW0_GOT"},
    {66, "R_TILEGX_IMM16_X0_HW0_PLT_PCREL"},
    {67, "R_TILEGX_IMM16_X1_HW0_PLT_PCREL"},
    {68, "R_TILEGX_IMM16_X0_HW1_PLT_PCREL"},
    {69, "R_TILEGX_IMM16_X1_HW1_PLT_PCREL"},
    {70, "R_TILEGX_IMM16_X0_HW2_PLT_PCREL"},
    {71, "R_TILEGX_IMM16_X1_HW2_PLT_PCREL"},
    {72, "R_TILEGX_IMM16_X0_HW0_LAST_GOT"},
    {73, "R_TILEGX_IMM16_X1_HW0_LAST_GOT"},
    {74, "R_TILEGX_IMM16_X0_HW1_LAST_GOT"},
    {75, "R_TILEGX_IMM16_X1_HW1_LAST_GOT"},
    {76, "R_TILEGX_IMM16_X0_HW3_PLT_PCREL"},
    {77, "R_TILEGX_IMM16_X1_HW3_PLT_PCREL"},
    {78, "R_TILEGX_IMM16_X0_HW0_TLS_GD"},
    {79, "R_TILEGX_IMM16_X1_HW0_TLS_GD"},
    {80, "R_TILEGX_IMM16_X0_HW0_TLS_LE"},
    {81, "R_TILEGX_IMM16_X1_HW0_TLS_LE"},
    {82, "R_TILEGX_IMM16_X0_HW0_LAST_TLS_LE"},
    {83, "R_TILEGX_IMM16_X1_HW0_LAST_TLS_LE"},
    {84, "R_TILEGX_IMM16_X0_HW1_LAST_TLS_LE"},
    {85, "R_TILEGX_IMM16_X1_HW1_LAST_TLS_LE"},
    {86, "R_TILEGX_IMM16_X0_HW0_LAST_TLS_GD"},
    {87, "R_TILEGX_IMM16_X1_HW0_LAST_TLS_GD"},
    {88, "R_TILEGX_IMM16_X0_HW1_LAST_TLS_GD"},
    {89, "R_TILEGX_IMM16_X1_HW1_LAST_TLS_GD"},
    {92, "R_TILEGX_IMM16_X0_HW0_TLS_IE"},
    {93, "R_TILEGX_IMM16_X1_HW0_TLS_IE"},
    {94, "R_TILEGX_IMM16_X0_HW0_LAST_PLT_PCREL"},
    {95, "R_TILEGX_IMM16_X1_HW0_LAST_PLT_PCREL"},
    {96, "R_TILEGX_IMM16_X0_HW1_LAST_PLT_PCREL"},
    {97, "R_TILEGX_IMM16_X1_HW1_LAST_PLT_PCREL"},
    {98, "R_TILEGX_IMM16_X0_HW2_LAST_PLT_PCREL"},
    {99, "R_TILEGX_IMM16_X1_HW2_LAST_PLT_PCREL"},
    {100, "R_TILEGX_IMM16_X0_HW0_LAST_TLS_IE"},
    {101, "R_TILEGX_IMM16_X1_HW0_LAST_TLS_IE"},
    {102, "R_TILEGX_IMM16_X0_HW1_LAST_TLS_IE"},
    {103, "R_TILEGX_IMM16_X1_HW1_LAST_TLS_IE"},
    {106, "R_TILEGX_TLS_DTPMOD64"},
    {107, "R_TILEGX_TLS_DTPOFF64"},
    {108, "R_TILEGX_TLS_TPOFF64"},
    {109, "R_TILEGX_TLS_DTPMOD32"},
    {110, "R_TILEGX_TLS_DTPOFF32"},
    {111, "R_TILEGX_TLS_TPOFF32"},
    {112, "R_TILEGX_TLS_GD_CALL"},
    {113, "R_TILEGX_IMM8_X0_TLS_GD_ADD"},
    {114, "R_TILEGX_IMM8_X1_TLS_GD_ADD"},
    {115, "R_TILEGX_IMM8_Y0_TLS_GD_ADD"},
    {116, "R_TILEGX_IMM8_Y1_TLS_GD_ADD"},
    {117, "R_TILEGX_TLS_IE_LOAD"},
    {118, "R_TILEGX_IMM8_X0_TLS_ADD"},
    {119, "R_TILEGX_IMM8_X1_TLS_ADD"},
    {120, "R_TILEGX_IMM8_Y0_TLS_ADD"},
    {121, "R_TILEGX_IMM8_Y1_TLS_ADD"},
    {128, "R_TILEGX_GNU_VTINHERIT"},
    {129, "R_TILEGX_GNU_VTENTRY"},
    {130, "R_TILEGX_NUM"}
};

const defines_map elf_ef_riscv = {
    {0x0001, "EF_RISCV_RVC"},
    {0x0006, "EF_RISCV_FLOAT_ABI"},
    {0x0000, "EF_RISCV_FLOAT_ABI_SOFT"},
    {0x0002, "EF_RISCV_FLOAT_ABI_SINGLE"},
    {0x0004, "EF_RISCV_FLOAT_ABI_DOUBLE"},
    {0x0006, "EF_RISCV_FLOAT_ABI_QUAD"},
    {0x0008, "EF_RISCV_RVE"},
    {0x0010, "EF_RISCV_TSO"}
};

const defines_map elf_r_riscv = {
    {0, "R_RISCV_NONE"},
    {1, "R_RISCV_32"},
    {2, "R_RISCV_64"},
    {3, "R_RISCV_RELATIVE"},
    {4, "R_RISCV_COPY"},
    {5, "R_RISCV_JUMP_SLOT"},
    {6, "R_RISCV_TLS_DTPMOD32"},
    {7, "R_RISCV_TLS_DTPMOD64"},
    {8, "R_RISCV_TLS_DTPREL32"},
    {9, "R_RISCV_TLS_DTPREL64"},
    {10, "R_RISCV_TLS_TPREL32"},
    {11, "R_RISCV_TLS_TPREL64"},
    {16, "R_RISCV_BRANCH"},
    {17, "R_RISCV_JAL"},
    {18, "R_RISCV_CALL"},
    {19, "R_RISCV_CALL_PLT"},
    {20, "R_RISCV_GOT_HI20"},
    {21, "R_RISCV_TLS_GOT_HI20"},
    {22, "R_RISCV_TLS_GD_HI20"},
    {23, "R_RISCV_PCREL_HI20"},
    {24, "R_RISCV_PCREL_LO12_I"},
    {25, "R_RISCV_PCREL_LO12_S"},
    {26, "R_RISCV_HI20"},
    {27, "R_RISCV_LO12_I"},
    {28, "R_RISCV_LO12_S"},
    {29, "R_RISCV_TPREL_HI20"},
    {30, "R_RISCV_TPREL_LO12_I"},
    {31, "R_RISCV_TPREL_LO12_S"},
    {32, "R_RISCV_TPREL_ADD"},
    {33, "R_RISCV_ADD8"},
    {34, "R_RISCV_ADD16"},
    {35, "R_RISCV_ADD32"},
    {36, "R_RISCV_ADD64"},
    {37, "R_RISCV_SUB8"},
    {38, "R_RISCV_SUB16"},
    {39, "R_RISCV_SUB32"},
    {40, "R_RISCV_SUB64"},
    {51, "R_RISCV_RELAX"},
    {52, "R_RISCV_SUB6"},
    {53, "R_RISCV_SET6"},
    {54, "R_RISCV_SET8"},
    {55, "R_RISCV_SET16"},
    {56, "R_RISCV_SET32"},
    {57, "R_RISCV_32_PCREL"},
    {58, "R_RISCV_IRELATIVE"},
    {59, "R_RISCV_PLT32"},
    {60, "R_RISCV_SET_ULEB128"},
    {61, "R_RISCV_SUB_ULEB128"},
    {66, "R_RISCV_NUM"}
};

const defines_map elf_sto_riscv = {
    {0x80, "STO_RISCV_VARIANT_CC"}
};

const defines_map elf_sht_riscv = {
    {(0x70000000 + 3), "SHT_RISCV_ATTRIBUTES"}
};

const defines_map elf_pt_riscv = {
    {(0x70000000 + 3), "PT_RISCV_ATTRIBUTES"}
};

const defines_map elf_dt_riscv = {
    {(0x70000000 + 1), "DT_RISCV_VARIANT_CC"}
};

const defines_map elf_r_bpf = {
    {0, "R_BPF_NONE"},
    {1, "R_BPF_64_64"},
    {10, "R_BPF_64_32"}
};

const defines_map elf_r_metag = {
    {0, "R_METAG_HIADDR16"},
    {1, "R_METAG_LOADDR16"},
    {2, "R_METAG_ADDR32"},
    {3, "R_METAG_NONE"},
    {4, "R_METAG_RELBRANCH"},
    {5, "R_METAG_GETSETOFF"},
    {6, "R_METAG_REG32OP1"},
    {7, "R_METAG_REG32OP2"},
    {8, "R_METAG_REG32OP3"},
    {9, "R_METAG_REG16OP1"},
    {10, "R_METAG_REG16OP2"},
    {11, "R_METAG_REG16OP3"},
    {12, "R_METAG_REG32OP4"},
    {13, "R_METAG_HIOG"},
    {14, "R_METAG_LOOG"},
    {15, "R_METAG_REL8"},
    {16, "R_METAG_REL16"},
    {30, "R_METAG_GNU_VTINHERIT"},
    {31, "R_METAG_GNU_VTENTRY"},
    {32, "R_METAG_HI16_GOTOFF"},
    {33, "R_METAG_LO16_GOTOFF"},
    {34, "R_METAG_GETSET_GOTOFF"},
    {35, "R_METAG_GETSET_GOT"},
    {36, "R_METAG_HI16_GOTPC"},
    {37, "R_METAG_LO16_GOTPC"},
    {38, "R_METAG_HI16_PLT"},
    {39, "R_METAG_LO16_PLT"},
    {40, "R_METAG_RELBRANCH_PLT"},
    {41, "R_METAG_GOTOFF"},
    {42, "R_METAG_PLT"},
    {43, "R_METAG_COPY"},
    {44, "R_METAG_JMP_SLOT"},
    {45, "R_METAG_RELATIVE"},
    {46, "R_METAG_GLOB_DAT"},
    {47, "R_METAG_TLS_GD"},
    {48, "R_METAG_TLS_LDM"},
    {49, "R_METAG_TLS_LDO_HI16"},
    {50, "R_METAG_TLS_LDO_LO16"},
    {51, "R_METAG_TLS_LDO"},
    {52, "R_METAG_TLS_IE"},
    {53, "R_METAG_TLS_IENONPIC"},
    {54, "R_METAG_TLS_IENONPIC_HI16"},
    {55, "R_METAG_TLS_IENONPIC_LO16"},
    {56, "R_METAG_TLS_TPOFF"},
    {57, "R_METAG_TLS_DTPMOD"},
    {58, "R_METAG_TLS_DTPOFF"},
    {59, "R_METAG_TLS_LE"},
    {60, "R_METAG_TLS_LE_HI16"},
    {61, "R_METAG_TLS_LE_LO16"}
};

const defines_map elf_r_nds32 = {
    {0, "R_NDS32_NONE"},
    {20, "R_NDS32_32_RELA"},
    {39, "R_NDS32_COPY"},
    {40, "R_NDS32_GLOB_DAT"},
    {41, "R_NDS32_JMP_SLOT"},
    {42, "R_NDS32_RELATIVE"},
    {102, "R_NDS32_TLS_TPOFF"},
    {119, "R_NDS32_TLS_DESC"}
};

const defines_map elf_ef_larch = {
    {0x07, "EF_LARCH_ABI_MODIFIER_MASK"},
    {0x01, "EF_LARCH_ABI_SOFT_FLOAT"},
    {0x02, "EF_LARCH_ABI_SINGLE_FLOAT"},
    {0x03, "EF_LARCH_ABI_DOUBLE_FLOAT"},
    {0x40, "EF_LARCH_OBJABI_V1"}
};

const defines_map elf_r_larch = {
    {0, "R_LARCH_NONE"},
    {1, "R_LARCH_32"},
    {2, "R_LARCH_64"},
    {3, "R_LARCH_RELATIVE"},
    {4, "R_LARCH_COPY"},
    {5, "R_LARCH_JUMP_SLOT"},
    {6, "R_LARCH_TLS_DTPMOD32"},
    {7, "R_LARCH_TLS_DTPMOD64"},
    {8, "R_LARCH_TLS_DTPREL32"},
    {9, "R_LARCH_TLS_DTPREL64"},
    {10, "R_LARCH_TLS_TPREL32"},
    {11, "R_LARCH_TLS_TPREL64"},
    {12, "R_LARCH_IRELATIVE"},
    {13, "R_LARCH_TLS_DESC32"},
    {14, "R_LARCH_TLS_DESC64"},
    {20, "R_LARCH_MARK_LA"},
    {21, "R_LARCH_MARK_PCREL"},
    {22, "R_LARCH_SOP_PUSH_PCREL"},
    {23, "R_LARCH_SOP_PUSH_ABSOLUTE"},
    {24, "R_LARCH_SOP_PUSH_DUP"},
    {25, "R_LARCH_SOP_PUSH_GPREL"},
    {26, "R_LARCH_SOP_PUSH_TLS_TPREL"},
    {27, "R_LARCH_SOP_PUSH_TLS_GOT"},
    {28, "R_LARCH_SOP_PUSH_TLS_GD"},
    {29, "R_LARCH_SOP_PUSH_PLT_PCREL"},
    {30, "R_LARCH_SOP_ASSERT"},
    {31, "R_LARCH_SOP_NOT"},
    {32, "R_LARCH_SOP_SUB"},
    {33, "R_LARCH_SOP_SL"},
    {34, "R_LARCH_SOP_SR"},
    {35, "R_LARCH_SOP_ADD"},
    {36, "R_LARCH_SOP_AND"},
    {37, "R_LARCH_SOP_IF_ELSE"},
    {38, "R_LARCH_SOP_POP_32_S_10_5"},
    {39, "R_LARCH_SOP_POP_32_U_10_12"},
    {40, "R_LARCH_SOP_POP_32_S_10_12"},
    {41, "R_LARCH_SOP_POP_32_S_10_16"},
    {42, "R_LARCH_SOP_POP_32_S_10_16_S2"},
    {43, "R_LARCH_SOP_POP_32_S_5_20"},
    {44, "R_LARCH_SOP_POP_32_S_0_5_10_16_S2"},
    {45, "R_LARCH_SOP_POP_32_S_0_10_10_16_S2"},
    {46, "R_LARCH_SOP_POP_32_U"},
    {47, "R_LARCH_ADD8"},
    {48, "R_LARCH_ADD16"},
    {49, "R_LARCH_ADD24"},
    {50, "R_LARCH_ADD32"},
    {51, "R_LARCH_ADD64"},
    {52, "R_LARCH_SUB8"},
    {53, "R_LARCH_SUB16"},
    {54, "R_LARCH_SUB24"},
    {55, "R_LARCH_SUB32"},
    {56, "R_LARCH_SUB64"},
    {57, "R_LARCH_GNU_VTINHERIT"},
    {58, "R_LARCH_GNU_VTENTRY"},
    {64, "R_LARCH_B16"},
    {65, "R_LARCH_B21"},
    {66, "R_LARCH_B26"},
    {67, "R_LARCH_ABS_HI20"},
    {68, "R_LARCH_ABS_LO12"},
    {69, "R_LARCH_ABS64_LO20"},
    {70, "R_LARCH_ABS64_HI12"},
    {71, "R_LARCH_PCALA_HI20"},
    {72, "R_LARCH_PCALA_LO12"},
    {73, "R_LARCH_PCALA64_LO20"},
    {74, "R_LARCH_PCALA64_HI12"},
    {75, "R_LARCH_GOT_PC_HI20"},
    {76, "R_LARCH_GOT_PC_LO12"},
    {77, "R_LARCH_GOT64_PC_LO20"},
    {78, "R_LARCH_GOT64_PC_HI12"},
    {79, "R_LARCH_GOT_HI20"},
    {80, "R_LARCH_GOT_LO12"},
    {81, "R_LARCH_GOT64_LO20"},
    {82, "R_LARCH_GOT64_HI12"},
    {83, "R_LARCH_TLS_LE_HI20"},
    {84, "R_LARCH_TLS_LE_LO12"},
    {85, "R_LARCH_TLS_LE64_LO20"},
    {86, "R_LARCH_TLS_LE64_HI12"},
    {87, "R_LARCH_TLS_IE_PC_HI20"},
    {88, "R_LARCH_TLS_IE_PC_LO12"},
    {89, "R_LARCH_TLS_IE64_PC_LO20"},
    {90, "R_LARCH_TLS_IE64_PC_HI12"},
    {91, "R_LARCH_TLS_IE_HI20"},
    {92, "R_LARCH_TLS_IE_LO12"},
    {93, "R_LARCH_TLS_IE64_LO20"},
    {94, "R_LARCH_TLS_IE64_HI12"},
    {95, "R_LARCH_TLS_LD_PC_HI20"},
    {96, "R_LARCH_TLS_LD_HI20"},
    {97, "R_LARCH_TLS_GD_PC_HI20"},
    {98, "R_LARCH_TLS_GD_HI20"},
    {99, "R_LARCH_32_PCREL"},
    {100, "R_LARCH_RELAX"},
    {101, "R_LARCH_DELETE"},
    {102, "R_LARCH_ALIGN"},
    {103, "R_LARCH_PCREL20_S2"},
    {104, "R_LARCH_CFA"},
    {105, "R_LARCH_ADD6"},
    {106, "R_LARCH_SUB6"},
    {107, "R_LARCH_ADD_ULEB128"},
    {108, "R_LARCH_SUB_ULEB128"},
    {109, "R_LARCH_64_PCREL"},
    {110, "R_LARCH_CALL36"},
    {111, "R_LARCH_TLS_DESC_PC_HI20"},
    {112, "R_LARCH_TLS_DESC_PC_LO12"},
    {113, "R_LARCH_TLS_DESC64_PC_LO20"},
    {114, "R_LARCH_TLS_DESC64_PC_HI12"},
    {115, "R_LARCH_TLS_DESC_HI20"},
    {116, "R_LARCH_TLS_DESC_LO12"},
    {117, "R_LARCH_TLS_DESC64_LO20"},
    {118, "R_LARCH_TLS_DESC64_HI12"},
    {119, "R_LARCH_TLS_DESC_LD"},
    {120, "R_LARCH_TLS_DESC_CALL"},
    {121, "R_LARCH_TLS_LE_HI20_R"},
    {122, "R_LARCH_TLS_LE_ADD_R"},
    {123, "R_LARCH_TLS_LE_LO12_R"},
    {124, "R_LARCH_TLS_LD_PCREL20_S2"},
    {125, "R_LARCH_TLS_GD_PCREL20_S2"},
    {126, "R_LARCH_TLS_DESC_PCREL20_S2"}
};

const defines_map elf_ef_arc = {
    {0x000000ff, "EF_ARC_MACH_MSK"},
    {0x00000f00, "EF_ARC_OSABI_MSK"},
    {(0x000000ff | 0x00000f00), "EF_ARC_ALL_MSK"}
};

const defines_map elf_sht_arc = {
    {(0x70000000 + 1), "SHT_ARC_ATTRIBUTES"}
};

const defines_map elf_r_arc = {
    {0x0, "R_ARC_NONE"},
    {0x1, "R_ARC_8"},
    {0x2, "R_ARC_16"},
    {0x3, "R_ARC_24"},
    {0x4, "R_ARC_32"},
    {0x6, "R_ARC_B22_PCREL"},
    {0x7, "R_ARC_H30"},
    {0x8, "R_ARC_N8"},
    {0x9, "R_ARC_N16"},
    {0xA, "R_ARC_N24"},
    {0xB, "R_ARC_N32"},
    {0xC, "R_ARC_SDA"},
    {0xD, "R_ARC_SECTOFF"},
    {0xE, "R_ARC_S21H_PCREL"},
    {0xF, "R_ARC_S21W_PCREL"},
    {0x10, "R_ARC_S25H_PCREL"},
    {0x11, "R_ARC_S25W_PCREL"},
    {0x12, "R_ARC_SDA32"},
    {0x13, "R_ARC_SDA_LDST"},
    {0x14, "R_ARC_SDA_LDST1"},
    {0x15, "R_ARC_SDA_LDST2"},
    {0x16, "R_ARC_SDA16_LD"},
    {0x17, "R_ARC_SDA16_LD1"},
    {0x18, "R_ARC_SDA16_LD2"},
    {0x19, "R_ARC_S13_PCREL"},
    {0x1A, "R_ARC_W"},
    {0x1B, "R_ARC_32_ME"},
    {0x1C, "R_ARC_N32_ME"},
    {0x1D, "R_ARC_SECTOFF_ME"},
    {0x1E, "R_ARC_SDA32_ME"},
    {0x1F, "R_ARC_W_ME"},
    {0x20, "R_ARC_H30_ME"},
    {0x21, "R_ARC_SECTOFF_U8"},
    {0x22, "R_ARC_SECTOFF_S9"},
    {0x23, "R_AC_SECTOFF_U8"},
    {0x24, "R_AC_SECTOFF_U8_1"},
    {0x25, "R_AC_SECTOFF_U8_2"},
    {0x26, "R_AC_SECTOFF_S9"},
    {0x27, "R_AC_SECTOFF_S9_1"},
    {0x28, "R_AC_SECTOFF_S9_2"},
    {0x29, "R_ARC_SECTOFF_ME_1"},
    {0x2A, "R_ARC_SECTOFF_ME_2"},
    {0x2B, "R_ARC_SECTOFF_1"},
    {0x2C, "R_ARC_SECTOFF_2"},
    {0x2D, "R_ARC_SDA_12"},
    {0x30, "R_ARC_SDA16_ST2"},
    {0x31, "R_ARC_32_PCREL"},
    {0x32, "R_ARC_PC32"},
    {0x33, "R_ARC_GOTPC32"},
    {0x34, "R_ARC_PLT32"},
    {0x35, "R_ARC_COPY"},
    {0x36, "R_ARC_GLOB_DAT"},
    {0x37, "R_ARC_JMP_SLOT"},
    {0x38, "R_ARC_RELATIVE"},
    {0x39, "R_ARC_GOTOFF"},
    {0x3A, "R_ARC_GOTPC"},
    {0x3B, "R_ARC_GOT32"},
    {0x3C, "R_ARC_S21W_PCREL_PLT"},
    {0x3D, "R_ARC_S25H_PCREL_PLT"},
    {0x3F, "R_ARC_JLI_SECTOFF"},
    {0x42, "R_ARC_TLS_DTPMOD"},
    {0x43, "R_ARC_TLS_DTPOFF"},
    {0x44, "R_ARC_TLS_TPOFF"},
    {0x45, "R_ARC_TLS_GD_GOT"},
    {0x46, "R_ARC_TLS_GD_LD"},
    {0x47, "R_ARC_TLS_GD_CALL"},
    {0x48, "R_ARC_TLS_IE_GOT"},
    {0x49, "R_ARC_TLS_DTPOFF_S9"},
    {0x4A, "R_ARC_TLS_LE_S9"},
    {0x4B, "R_ARC_TLS_LE_32"},
    {0x4C, "R_ARC_S25W_PCREL_PLT"},
    {0x4D, "R_ARC_S21H_PCREL_PLT"},
    {0x4E, "R_ARC_NPS_CMEM16"}
};

const defines_map elf_r_or1k = {
    {0, "R_OR1K_NONE"},
    {1, "R_OR1K_32"},
    {2, "R_OR1K_16"},
    {3, "R_OR1K_8"},
    {4, "R_OR1K_LO_16_IN_INSN"},
    {5, "R_OR1K_HI_16_IN_INSN"},
    {6, "R_OR1K_INSN_REL_26"},
    {7, "R_OR1K_GNU_VTENTRY"},
    {8, "R_OR1K_GNU_VTINHERIT"},
    {9, "R_OR1K_32_PCREL"},
    {10, "R_OR1K_16_PCREL"},
    {11, "R_OR1K_8_PCREL"},
    {12, "R_OR1K_GOTPC_HI16"},
    {13, "R_OR1K_GOTPC_LO16"},
    {14, "R_OR1K_GOT16"},
    {15, "R_OR1K_PLT26"},
    {16, "R_OR1K_GOTOFF_HI16"},
    {17, "R_OR1K_GOTOFF_LO16"},
    {18, "R_OR1K_COPY"},
    {19, "R_OR1K_GLOB_DAT"},
    {20, "R_OR1K_JMP_SLOT"},
    {21, "R_OR1K_RELATIVE"},
    {22, "R_OR1K_TLS_GD_HI16"},
    {23, "R_OR1K_TLS_GD_LO16"},
    {24, "R_OR1K_TLS_LDM_HI16"},
    {25, "R_OR1K_TLS_LDM_LO16"},
    {26, "R_OR1K_TLS_LDO_HI16"},
    {27, "R_OR1K_TLS_LDO_LO16"},
    {28, "R_OR1K_TLS_IE_HI16"},
    {29, "R_OR1K_TLS_IE_LO16"},
    {30, "R_OR1K_TLS_LE_HI16"},
    {31, "R_OR1K_TLS_LE_LO16"},
    {32, "R_OR1K_TLS_TPOFF"},
    {33, "R_OR1K_TLS_DTPOFF"},
    {34, "R_OR1K_TLS_DTPMOD"}
};

template <typename T>
std::string print_elf_ei(const T v)
{
    return print_enum_entry(v, elf_ei);
}

template <typename T>
std::string print_elf_elfmag0(const T v)
{
    return print_enum_entry(v, elf_elfmag0);
}

template <typename T>
std::string print_elf_elfmag1(const T v)
{
    return print_enum_entry(v, elf_elfmag1);
}

template <typename T>
std::string print_elf_elfmag2(const T v)
{
    return print_enum_entry(v, elf_elfmag2);
}

template <typename T>
std::string print_elf_elfmag3(const T v)
{
    return print_enum_entry(v, elf_elfmag3);
}

template <typename T>
std::string print_elf_elfclass(const T v)
{
    return print_enum_entry(v, elf_elfclass);
}

template <typename T>
std::string print_elf_elfdata(const T v)
{
    return print_enum_entry(v, elf_elfdata);
}

template <typename T>
std::string print_elf_ev_current(const T v)
{
    return print_enum_entry(v, elf_ev_current);
}

template <typename T>
std::string print_elf_elfosabi(const T v)
{
    return print_enum_entry(v, elf_elfosabi);
}

template <typename T>
std::string print_elf_et(const T v)
{
    return print_enum_entry(v, elf_et);
}

template <typename T>
std::string print_elf_em(const T v)
{
    return print_enum_entry(v, elf_em);
}

template <typename T>
std::string print_elf_ev(const T v)
{
    return print_enum_entry(v, elf_ev);
}

template <typename T>
std::string print_elf_shn(const T v)
{
    return print_enum_entry(v, elf_shn);
}

template <typename T>
std::string print_elf_sht(const T v)
{
    return print_enum_entry(v, elf_sht);
}

template <typename T>
std::string print_elf_shf(const T v)
{
    return print_or_enum_entries(v, elf_shf);
}

template <typename T>
std::string print_elf_elfcompress(const T v)
{
    return print_enum_entry(v, elf_elfcompress);
}

template <typename T>
std::string print_elf_syminfo_bt(const T v)
{
    return print_enum_entry(v, elf_syminfo_bt);
}

template <typename T>
std::string print_elf_syminfo_flg(const T v)
{
    return print_or_enum_entries(v, elf_syminfo_flg);
}

template <typename T>
std::string print_elf_stb(const T v)
{
    return print_enum_entry(v, elf_stb);
}

template <typename T>
std::string print_elf_stt(const T v)
{
    return print_enum_entry(v, elf_stt);
}

template <typename T>
std::string print_elf_stv(const T v)
{
    return print_enum_entry(v, elf_stv);
}

template <typename T>
std::string print_elf_pn(const T v)
{
    return print_enum_entry(v, elf_pn);
}

template <typename T>
std::string print_elf_pt(const T v)
{
    return print_enum_entry(v, elf_pt);
}

template <typename T>
std::string print_elf_pf(const T v)
{
    return print_or_enum_entries(v, elf_pf);
}

template <typename T>
std::string print_elf_nt(const T v)
{
    return print_enum_entry(v, elf_nt);
}

template <typename T>
std::string print_elf_nt_version(const T v)
{
    return print_enum_entry(v, elf_nt_version);
}

template <typename T>
std::string print_elf_dt(const T v)
{
    return print_enum_entry(v, elf_dt);
}

template <typename T>
std::string print_elf_df(const T v)
{
    return print_or_enum_entries(v, elf_df);
}

template <typename T>
std::string print_elf_df_1(const T v)
{
    return print_or_enum_entries(v, elf_df_1);
}

template <typename T>
std::string print_elf_dtf_1(const T v)
{
    return print_or_enum_entries(v, elf_dtf_1);
}

template <typename T>
std::string print_elf_df_p1(const T v)
{
    return print_or_enum_entries(v, elf_df_p1);
}

template <typename T>
std::string print_elf_ver_def(const T v)
{
    return print_enum_entry(v, elf_ver_def);
}

template <typename T>
std::string print_elf_ver_flg(const T v)
{
    return print_enum_entry(v, elf_ver_flg);
}

template <typename T>
std::string print_elf_ver_ndx(const T v)
{
    return print_enum_entry(v, elf_ver_ndx);
}

template <typename T>
std::string print_elf_ver_need(const T v)
{
    return print_enum_entry(v, elf_ver_need);
}

template <typename T>
std::string print_elf_at(const T v)
{
    return print_enum_entry(v, elf_at);
}

template <typename T>
std::string print_elf_elf_note_pagesize_hint(const T v)
{
    return print_enum_entry(v, elf_elf_note_pagesize_hint);
}

template <typename T>
std::string print_elf_nt_gnu(const T v)
{
    return print_enum_entry(v, elf_nt_gnu);
}

template <typename T>
std::string print_elf_elf_note_os(const T v)
{
    return print_enum_entry(v, elf_elf_note_os);
}

template <typename T>
std::string print_elf_ef_cpu32(const T v)
{
    return print_enum_entry(v, elf_ef_cpu32);
}

template <typename T>
std::string print_elf_r_68k(const T v)
{
    return print_enum_entry(v, elf_r_68k);
}

template <typename T>
std::string print_elf_r_386(const T v)
{
    return print_enum_entry(v, elf_r_386);
}

template <typename T>
std::string print_elf_stt_sparc_register(const T v)
{
    return print_enum_entry(v, elf_stt_sparc_register);
}

template <typename T>
std::string print_elf_ef_sparc(const T v)
{
    return print_enum_entry(v, elf_ef_sparc);
}

template <typename T>
std::string print_elf_r_sparc32(const T v)
{
    return print_enum_entry(v, elf_r_sparc32);
}

template <typename T>
std::string print_elf_sparc64(const T v)
{
    return print_enum_entry(v, elf_sparc64);
}

template <typename T>
std::string print_elf_dt_sparc(const T v)
{
    return print_enum_entry(v, elf_dt_sparc);
}

template <typename T>
std::string print_elf_ef_mips(const T v)
{
    return print_or_enum_entries(v, elf_ef_mips);
}

template <typename T>
std::string print_elf_shn_mips(const T v)
{
    return print_enum_entry(v, elf_shn_mips);
}

template <typename T>
std::string print_elf_sht_mips(const T v)
{
    return print_enum_entry(v, elf_sht_mips);
}

template <typename T>
std::string print_elf_shf_mips(const T v)
{
    return print_or_enum_entries(v, elf_shf_mips);
}

template <typename T>
std::string print_elf_sto_mips(const T v)
{
    return print_enum_entry(v, elf_sto_mips);
}

template <typename T>
std::string print_elf_stb_mips(const T v)
{
    return print_enum_entry(v, elf_stb_mips);
}

template <typename T>
std::string print_elf_odk(const T v)
{
    return print_enum_entry(v, elf_odk);
}

template <typename T>
std::string print_elf_oex(const T v)
{
    return print_or_enum_entries(v, elf_oex);
}

template <typename T>
std::string print_elf_ohw(const T v)
{
    return print_or_enum_entries(v, elf_ohw);
}

template <typename T>
std::string print_elf_opad(const T v)
{
    return print_or_enum_entries(v, elf_opad);
}

template <typename T>
std::string print_elf_ohwa(const T v)
{
    return print_or_enum_entries(v, elf_ohwa);
}

template <typename T>
std::string print_elf_r_mips(const T v)
{
    return print_enum_entry(v, elf_r_mips);
}

template <typename T>
std::string print_elf_pt_mips(const T v)
{
    return print_enum_entry(v, elf_pt_mips);
}

template <typename T>
std::string print_elf_pf_mips(const T v)
{
    return print_or_enum_entries(v, elf_pf_mips);
}

template <typename T>
std::string print_elf_dt_mips(const T v)
{
    return print_enum_entry(v, elf_dt_mips);
}

template <typename T>
std::string print_elf_rhf(const T v)
{
    return print_or_enum_entries(v, elf_rhf);
}

template <typename T>
std::string print_elf_ll(const T v)
{
    return print_or_enum_entries(v, elf_ll);
}

template <typename T>
std::string print_elf_mips_afl_reg(const T v)
{
    return print_enum_entry(v, elf_mips_afl_reg);
}

template <typename T>
std::string print_elf_mips_afl_ase(const T v)
{
    return print_or_enum_entries(v, elf_mips_afl_ase);
}

template <typename T>
std::string print_elf_mips_afl_ext(const T v)
{
    return print_enum_entry(v, elf_mips_afl_ext);
}

template <typename T>
std::string print_elf_mips_afl_flags1(const T v)
{
    return print_or_enum_entries(v, elf_mips_afl_flags1);
}

template <typename T>
std::string print_elf_val_gnu_mips_abi_fp(const T v)
{
    return print_enum_entry(v, elf_val_gnu_mips_abi_fp);
}

template <typename T>
std::string print_elf_ef_parisc(const T v)
{
    return print_or_enum_entries(v, elf_ef_parisc);
}

template <typename T>
std::string print_elf_efa_parisc(const T v)
{
    return print_enum_entry(v, elf_efa_parisc);
}

template <typename T>
std::string print_elf_shn_parisc(const T v)
{
    return print_enum_entry(v, elf_shn_parisc);
}

template <typename T>
std::string print_elf_sht_parisc(const T v)
{
    return print_enum_entry(v, elf_sht_parisc);
}

template <typename T>
std::string print_elf_shf_parisc(const T v)
{
    return print_or_enum_entries(v, elf_shf_parisc);
}

template <typename T>
std::string print_elf_stt_parisc_hp(const T v)
{
    return print_enum_entry(v, elf_stt_parisc_hp);
}

template <typename T>
std::string print_elf_r_parisc(const T v)
{
    return print_enum_entry(v, elf_r_parisc);
}

template <typename T>
std::string print_elf_pt_parisc_hp(const T v)
{
    return print_enum_entry(v, elf_pt_parisc_hp);
}

template <typename T>
std::string print_elf_pf_parisc_hp(const T v)
{
    return print_or_enum_entries(v, elf_pf_parisc_hp);
}

template <typename T>
std::string print_elf_ef_alpha(const T v)
{
    return print_enum_entry(v, elf_ef_alpha);
}

template <typename T>
std::string print_elf_sht_alpha(const T v)
{
    return print_enum_entry(v, elf_sht_alpha);
}

template <typename T>
std::string print_elf_shf_alpha(const T v)
{
    return print_or_enum_entries(v, elf_shf_alpha);
}

template <typename T>
std::string print_elf_sto_alpha(const T v)
{
    return print_enum_entry(v, elf_sto_alpha);
}

template <typename T>
std::string print_elf_r_alpha(const T v)
{
    return print_enum_entry(v, elf_r_alpha);
}

template <typename T>
std::string print_elf_lituse_alpha(const T v)
{
    return print_enum_entry(v, elf_lituse_alpha);
}

template <typename T>
std::string print_elf_dt_alpha(const T v)
{
    return print_enum_entry(v, elf_dt_alpha);
}

template <typename T>
std::string print_elf_ef_ppc(const T v)
{
    return print_enum_entry(v, elf_ef_ppc);
}

template <typename T>
std::string print_elf_ef_ppc_relocatable(const T v)
{
    return print_enum_entry(v, elf_ef_ppc_relocatable);
}

template <typename T>
std::string print_elf_r_ppc(const T v)
{
    return print_enum_entry(v, elf_r_ppc);
}

template <typename T>
std::string print_elf_dt_ppc(const T v)
{
    return print_enum_entry(v, elf_dt_ppc);
}

template <typename T>
std::string print_elf_ppc_opt(const T v)
{
    return print_enum_entry(v, elf_ppc_opt);
}

template <typename T>
std::string print_elf_r_ppc64(const T v)
{
    return print_enum_entry(v, elf_r_ppc64);
}

template <typename T>
std::string print_elf_ef_ppc64(const T v)
{
    return print_enum_entry(v, elf_ef_ppc64);
}

template <typename T>
std::string print_elf_dt_ppc64(const T v)
{
    return print_enum_entry(v, elf_dt_ppc64);
}

template <typename T>
std::string print_elf_ppc64_opt(const T v)
{
    return print_or_enum_entries(v, elf_ppc64_opt);
}

template <typename T>
std::string print_elf_sto_ppc64_local_bit(const T v)
{
    return print_enum_entry(v, elf_sto_ppc64_local_bit);
}

template <typename T>
std::string print_elf_sto_ppc64_local_mask(const T v)
{
    return print_or_enum_entries(v, elf_sto_ppc64_local_mask);
}

template <typename T>
std::string print_elf_ef_arm(const T v)
{
    return print_or_enum_entries(v, elf_ef_arm);
}

template <typename T>
std::string print_elf_ef_arm_b01(const T v)
{
    return print_or_enum_entries(v, elf_ef_arm_b01);
}

template <typename T>
std::string print_elf_ef_arm_aaelf(const T v)
{
    return print_or_enum_entries(v, elf_ef_arm_aaelf);
}

template <typename T>
std::string print_elf_ef_arm_eabi(const T v)
{
    return print_enum_entry(v, elf_ef_arm_eabi);
}

template <typename T>
std::string print_elf_stt_arm(const T v)
{
    return print_enum_entry(v, elf_stt_arm);
}

template <typename T>
std::string print_elf_shf_arm(const T v)
{
    return print_or_enum_entries(v, elf_shf_arm);
}

template <typename T>
std::string print_elf_pf_arm(const T v)
{
    return print_or_enum_entries(v, elf_pf_arm);
}

template <typename T>
std::string print_elf_pt_arm(const T v)
{
    return print_enum_entry(v, elf_pt_arm);
}

template <typename T>
std::string print_elf_sht_arm(const T v)
{
    return print_enum_entry(v, elf_sht_arm);
}

template <typename T>
std::string print_elf_r_aarch64(const T v)
{
    return print_enum_entry(v, elf_r_aarch64);
}

template <typename T>
std::string print_elf_pt_aarch64(const T v)
{
    return print_enum_entry(v, elf_pt_aarch64);
}

template <typename T>
std::string print_elf_dt_aarch64(const T v)
{
    return print_enum_entry(v, elf_dt_aarch64);
}

template <typename T>
std::string print_elf_sto_aarch64(const T v)
{
    return print_enum_entry(v, elf_sto_aarch64);
}

template <typename T>
std::string print_elf_r_arm(const T v)
{
    return print_enum_entry(v, elf_r_arm);
}

template <typename T>
std::string print_elf_r_ckcore(const T v)
{
    return print_enum_entry(v, elf_r_ckcore);
}

template <typename T>
std::string print_elf_ef_csky(const T v)
{
    return print_enum_entry(v, elf_ef_csky);
}

template <typename T>
std::string print_elf_ef_csky_abiv(const T v)
{
    return print_enum_entry(v, elf_ef_csky_abiv);
}

template <typename T>
std::string print_elf_sht_csky(const T v)
{
    return print_enum_entry(v, elf_sht_csky);
}

template <typename T>
std::string print_elf_ef_ia_64(const T v)
{
    return print_enum_entry(v, elf_ef_ia_64);
}

template <typename T>
std::string print_elf_pt_ia_64(const T v)
{
    return print_enum_entry(v, elf_pt_ia_64);
}

template <typename T>
std::string print_elf_pf_ia_64(const T v)
{
    return print_or_enum_entries(v, elf_pf_ia_64);
}

template <typename T>
std::string print_elf_sht_ia_64(const T v)
{
    return print_enum_entry(v, elf_sht_ia_64);
}

template <typename T>
std::string print_elf_shf_ia_64(const T v)
{
    return print_or_enum_entries(v, elf_shf_ia_64);
}

template <typename T>
std::string print_elf_dt_ia_64(const T v)
{
    return print_enum_entry(v, elf_dt_ia_64);
}

template <typename T>
std::string print_elf_r_ia64(const T v)
{
    return print_enum_entry(v, elf_r_ia64);
}

template <typename T>
std::string print_elf_ef_sh(const T v)
{
    return print_enum_entry(v, elf_ef_sh);
}

template <typename T>
std::string print_elf_r_sh(const T v)
{
    return print_enum_entry(v, elf_r_sh);
}

template <typename T>
std::string print_elf_ef_s390(const T v)
{
    return print_or_enum_entries(v, elf_ef_s390);
}

template <typename T>
std::string print_elf_r_390(const T v)
{
    return print_enum_entry(v, elf_r_390);
}

template <typename T>
std::string print_elf_r_cris(const T v)
{
    return print_enum_entry(v, elf_r_cris);
}

template <typename T>
std::string print_elf_r_x86_64(const T v)
{
    return print_enum_entry(v, elf_r_x86_64);
}

template <typename T>
std::string print_elf_sht_x86_64(const T v)
{
    return print_enum_entry(v, elf_sht_x86_64);
}

template <typename T>
std::string print_elf_dt_x86_64(const T v)
{
    return print_enum_entry(v, elf_dt_x86_64);
}

template <typename T>
std::string print_elf_r_mn10300(const T v)
{
    return print_enum_entry(v, elf_r_mn10300);
}

template <typename T>
std::string print_elf_r_m32r(const T v)
{
    return print_enum_entry(v, elf_r_m32r);
}

template <typename T>
std::string print_elf_r_microblaze(const T v)
{
    return print_enum_entry(v, elf_r_microblaze);
}

template <typename T>
std::string print_elf_dt_nios2(const T v)
{
    return print_or_enum_entries(v, elf_dt_nios2);
}

template <typename T>
std::string print_elf_r_nios2(const T v)
{
    return print_enum_entry(v, elf_r_nios2);
}

template <typename T>
std::string print_elf_r_tilepro(const T v)
{
    return print_enum_entry(v, elf_r_tilepro);
}

template <typename T>
std::string print_elf_r_tilegx(const T v)
{
    return print_enum_entry(v, elf_r_tilegx);
}

template <typename T>
std::string print_elf_ef_riscv(const T v)
{
    return print_enum_entry(v, elf_ef_riscv);
}

template <typename T>
std::string print_elf_r_riscv(const T v)
{
    return print_enum_entry(v, elf_r_riscv);
}

template <typename T>
std::string print_elf_sto_riscv(const T v)
{
    return print_enum_entry(v, elf_sto_riscv);
}

template <typename T>
std::string print_elf_sht_riscv(const T v)
{
    return print_enum_entry(v, elf_sht_riscv);
}

template <typename T>
std::string print_elf_pt_riscv(const T v)
{
    return print_enum_entry(v, elf_pt_riscv);
}

template <typename T>
std::string print_elf_dt_riscv(const T v)
{
    return print_or_enum_entries(v, elf_dt_riscv);
}

template <typename T>
std::string print_elf_r_bpf(const T v)
{
    return print_enum_entry(v, elf_r_bpf);
}

template <typename T>
std::string print_elf_r_metag(const T v)
{
    return print_enum_entry(v, elf_r_metag);
}

template <typename T>
std::string print_elf_r_nds32(const T v)
{
    return print_enum_entry(v, elf_r_nds32);
}

template <typename T>
std::string print_elf_ef_larch(const T v)
{
    return print_enum_entry(v, elf_ef_larch);
}

template <typename T>
std::string print_elf_r_larch(const T v)
{
    return print_enum_entry(v, elf_r_larch);
}

template <typename T>
std::string print_elf_ef_arc(const T v)
{
    return print_or_enum_entries(v, elf_ef_arc);
}

template <typename T>
std::string print_elf_sht_arc(const T v)
{
    return print_enum_entry(v, elf_sht_arc);
}

template <typename T>
std::string print_elf_r_arc(const T v)
{
    return print_enum_entry(v, elf_r_arc);
}

template <typename T>
std::string print_elf_r_or1k(const T v)
{
    return print_enum_entry(v, elf_r_or1k);
}

template <typename T>
std::string print_elf_enum_eflags32(const T v)
{
    std::stringstream ss;
    const auto str1 = print_enum_entry(v, elf_ef_cpu32, elf_ef_sparc, elf_ef_mips, elf_ef_ppc,
                                       elf_ef_csky, elf_ef_sh,
                                       elf_ef_riscv, elf_ef_larch);
    ss << str1;
    if (const auto str2 = print_or_enum_entries(v, elf_ef_parisc, elf_ef_arm, elf_ef_arm_b01, elf_ef_arm_aaelf,
                                                elf_ef_s390,
                                                elf_ef_arc);
        !str2.empty())
    {
        ss << (str1.empty() ? "" : " | ") << str2;
        if (const auto str3 = print_enum_entry(v & EF_PARISC_ARCH, elf_efa_parisc); !str3.empty())
            ss << " | " << str3;
    }
    return ss.str();
}

template <typename T>
std::string print_elf_enum_eflags64(const T v)
{
    return print_enum_entry(v, elf_ef_sparc, elf_ef_alpha, elf_ef_ppc64, elf_ef_ia_64, elf_ef_riscv,
                            elf_ef_larch);
}

template <typename T>
std::string print_elf_enum_shtype32(const T v)
{
    return print_enum_entry(v, elf_sht, elf_sht_mips, elf_sht_parisc, elf_sht_arm, elf_sht_csky,
                            elf_sht_riscv, elf_sht_arc);
}

template <typename T>
std::string print_elf_enum_shflags32(const T v)
{
    return print_or_enum_entries(v, elf_shf, elf_shf_mips, elf_shf_parisc, elf_shf_arm);
}

template <typename T>
std::string print_elf_enum_shtype64(const T v)
{
    return print_enum_entry(v, elf_sht, elf_sht_alpha, elf_sht_ia_64, elf_sht_x86_64, elf_sht_riscv);
}

template <typename T>
std::string print_elf_enum_shflags64(const T v)
{
    return print_or_enum_entries(v, elf_shf, elf_shf_alpha, elf_shf_ia_64);
}

template <typename T>
std::string print_elf_enum_sttype32(const T v)
{
    return print_enum_entry(v, elf_stt, elf_stt_sparc_register, elf_stt_parisc_hp, elf_stt_arm);
}

template <typename T>
std::string print_elf_enum_stother32(const T v)
{
    return print_enum_entry(v, elf_sto_mips, elf_sto_riscv);
}

template <typename T>
std::string print_elf_enum_sttype64(const T v)
{
    return print_enum_entry(v, elf_stt, elf_stt_sparc_register, elf_stt_parisc_hp);
}

template <typename T>
std::string print_elf_enum_stother64(const T v)
{
    return print_enum_entry(v, elf_sto_alpha, elf_sto_aarch64, elf_sto_riscv);
}

template <typename T>
std::string print_elf_enum_stshndx(const T v)
{
    return print_enum_entry(v, elf_shn, elf_shn_mips, elf_shn_parisc);
}

template <typename T>
std::string print_elf_enum_rtype32(const T v)
{
    return print_enum_entry(v, elf_r_68k, elf_r_386, elf_r_sparc32, elf_r_mips, elf_r_parisc,
                            elf_r_ppc, elf_r_arm,
                            elf_r_ckcore, elf_r_sh, elf_r_390, elf_r_cris, elf_r_x86_64, elf_r_mn10300, elf_r_m32r,
                            elf_r_microblaze, elf_r_nios2, elf_r_tilepro, elf_r_riscv, elf_r_bpf, elf_r_metag,
                            elf_r_nds32,
                            elf_r_larch, elf_r_arc, elf_r_or1k);
}

template <typename T>
std::string print_elf_enum_rtype64(const T v)
{
    return print_enum_entry(v, elf_r_sparc32, elf_sparc64, elf_r_parisc, elf_r_alpha, elf_r_ppc64,
                            elf_r_aarch64, elf_r_ia64,
                            elf_r_x86_64, elf_r_tilegx, elf_r_riscv, elf_r_bpf, elf_r_larch, elf_r_or1k);
}

template <typename T>
std::string print_elf_enum_ptype32(const T v)
{
    return print_enum_entry(v, elf_pt, elf_pt_mips, elf_pt_parisc_hp, elf_pt_arm, elf_pt_riscv);
}

template <typename T>
std::string print_elf_enum_pflags32(const T v)
{
    return print_or_enum_entries(v, elf_pf, elf_pf_mips, elf_pf_parisc_hp, elf_pf_arm);
}

template <typename T>
std::string print_elf_enum_ptype64(const T v)
{
    return print_enum_entry(v, elf_pt, elf_pt_parisc_hp, elf_pt_aarch64, elf_pt_ia_64, elf_pt_riscv);
}

template <typename T>
std::string print_elf_enum_pflags64(const T v)
{
    return print_or_enum_entries(v, elf_pf, elf_pf_parisc_hp, elf_pf_ia_64);
}

template <typename T>
std::string print_elf_enum_dtag32(const T v)
{
    return print_or_enum_entries(v, elf_dt, elf_pf_mips, elf_dt_ppc, elf_dt_nios2, elf_dt_riscv);
}

template <typename T>
std::string print_elf_enum_dtag64(const T v)
{
    return print_enum_entry(v, elf_dt, elf_dt_sparc, elf_dt_alpha, elf_dt_ppc64, elf_dt_aarch64,
                            elf_dt_ia_64, elf_dt_x86_64, elf_dt_riscv);
}

template <typename T>
std::string print_elf_enum_ntype(const T v)
{
    return print_enum_entry(v, elf_nt, elf_nt_version, elf_elf_note_pagesize_hint, elf_nt_gnu);
}
}

using namespace abii;

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Ehdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    // TODO: e_ident should print in the form e_ident[EI_* (elf_enum1)]: NNN [ELF_* (elf_enum2-elf_enum9)] {'c'}
    abii_args->push_arg(new ArgPrinter(obj.e_ident, "e_ident", &os));

    auto printer = new ArgPrinter(obj.e_type, "e_type", &os);
    printer->set_enum_printer(print_elf_et, obj.e_type);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.e_machine, "e_machine", &os);
    printer1->set_enum_printer(print_elf_em, obj.e_machine);
    abii_args->push_arg(printer1);

    auto printer2 = new ArgPrinter(obj.e_version, "e_version", &os);
    printer2->set_enum_printer(print_elf_ev, obj.e_version);
    abii_args->push_arg(printer2);

    abii_args->push_arg(new ArgPrinter(obj.e_entry, "e_entry", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_phoff, "e_phoff", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_shoff, "e_shoff", &os));

    auto printer3 = new ArgPrinter(obj.e_flags, "e_flags", &os);
    printer3->set_enum_printer(print_elf_enum_eflags32, obj.e_flags);
    abii_args->push_arg(printer3);

    auto arm_eabi_version = EF_ARM_EABI_VERSION(obj.e_flags);
    auto printer4 = new ArgPrinter(arm_eabi_version, "\t(EF_ARM_EABI_VERSION)", &os);
    printer4->set_enum_printer(print_elf_ef_arm_eabi, arm_eabi_version);
    abii_args->push_arg(printer4);

    auto csky_abi = obj.e_flags & EF_CSKY_ABIMASK;
    auto printer5 = new ArgPrinter(csky_abi, "\t(EF_CSKY_ABI)", &os);
    printer5->set_enum_printer(print_elf_ef_csky_abiv, csky_abi);
    abii_args->push_arg(printer5);

    auto csky_other = obj.e_flags & EF_CSKY_OTHER;
    abii_args->push_arg(new ArgPrinter(csky_other, "\t(EF_CSKY_OTHER)", &os));

    auto csky_processor = obj.e_flags & EF_CSKY_PROCESSOR;
    abii_args->push_arg(new ArgPrinter(csky_processor, "\t(EF_CSKY_PROCESSOR)", &os));

    abii_args->push_arg(new ArgPrinter(obj.e_ehsize, "e_ehsize", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_phentsize, "e_phentsize", &os));

    auto printer6 = new ArgPrinter(obj.e_phnum, "e_phnum", &os);
    printer6->set_enum_printer(print_elf_pn, obj.e_phnum);
    abii_args->push_arg(printer6);

    abii_args->push_arg(new ArgPrinter(obj.e_shentsize, "e_shentsize", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_shnum, "e_shnum", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_shstrndx, "e_shstrndx", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf64_Ehdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    // TODO: e_ident should print in the form e_ident[EI_* (elf_enum1)]: NNN [ELF_* (elf_enum2-elf_enum9)] {'c'}
    abii_args->push_arg(new ArgPrinter(obj.e_ident, "e_ident", &os));

    auto printer = new ArgPrinter(obj.e_type, "e_type", &os);
    printer->set_enum_printer(print_elf_et, obj.e_type);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.e_machine, "e_machine", &os);
    printer1->set_enum_printer(print_elf_em, obj.e_machine);
    abii_args->push_arg(printer1);

    auto printer2 = new ArgPrinter(obj.e_version, "e_version", &os);
    printer2->set_enum_printer(print_elf_ev, obj.e_version);
    abii_args->push_arg(printer2);

    abii_args->push_arg(new ArgPrinter(obj.e_entry, "e_entry", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_phoff, "e_phoff", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_shoff, "e_shoff", &os));

    auto printer3 = new ArgPrinter(obj.e_flags, "e_flags", &os);
    printer3->set_enum_printer(print_elf_enum_eflags64, obj.e_flags);
    abii_args->push_arg(printer3);

    auto ia_64_maskos = obj.e_flags & EF_IA_64_MASKOS;
    abii_args->push_arg(new ArgPrinter(ia_64_maskos, "\t(EF_IA_64_OS)", &os));

    auto ia_64_arch = obj.e_flags & EF_IA_64_ARCH;
    abii_args->push_arg(new ArgPrinter(ia_64_arch, "\t(EF_IA_64_ARCH)", &os));

    abii_args->push_arg(new ArgPrinter(obj.e_ehsize, "e_ehsize", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_phentsize, "e_phentsize", &os));

    auto printer4 = new ArgPrinter(obj.e_phnum, "e_phnum", &os);
    printer4->set_enum_printer(print_elf_pn, obj.e_phnum);
    abii_args->push_arg(printer4);

    abii_args->push_arg(new ArgPrinter(obj.e_shentsize, "e_shentsize", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_shnum, "e_shnum", &os));
    abii_args->push_arg(new ArgPrinter(obj.e_shstrndx, "e_shstrndx", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Shdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.sh_name, "sh_name", &os));

    auto printer = new ArgPrinter(obj.sh_type, "sh_type", &os);
    printer->set_enum_printer(print_elf_enum_shtype32, obj.sh_type);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.sh_flags, "sh_flags", &os);
    printer1->set_enum_printer(print_elf_enum_shflags32, obj.sh_flags);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.sh_addr, "sh_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_offset, "sh_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_size, "sh_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_link, "sh_link", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_info, "sh_info", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_addralign, "sh_addralign", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_entsize, "sh_entsize", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf64_Shdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.sh_name, "sh_name", &os));

    auto printer = new ArgPrinter(obj.sh_type, "sh_type", &os);
    printer->set_enum_printer(print_elf_enum_shtype64, obj.sh_type);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.sh_flags, "sh_flags", &os);
    printer1->set_enum_printer(print_elf_enum_shflags64, obj.sh_flags);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.sh_addr, "sh_addr", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_offset, "sh_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_size, "sh_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_link, "sh_link", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_info, "sh_info", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_addralign, "sh_addralign", &os));
    abii_args->push_arg(new ArgPrinter(obj.sh_entsize, "sh_entsize", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Chdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.ch_type, "ch_type", &os);
    printer->set_enum_printer(print_elf_elfcompress, obj.ch_type);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.ch_size, "ch_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.ch_addralign, "ch_addralign", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf64_Chdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.ch_type, "ch_type", &os);
    printer->set_enum_printer(print_elf_elfcompress, obj.ch_type);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.ch_reserved, "ch_reserved", &os));
    abii_args->push_arg(new ArgPrinter(obj.ch_size, "ch_size", &os));
    abii_args->push_arg(new ArgPrinter(obj.ch_addralign, "ch_addralign", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Sym>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.st_name, "st_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_value, "st_value", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_size, "st_size", &os));

    auto printer = new ArgPrinter(obj.st_info, "st_info", &os);
    printer->set_enum_printer(print_elf_stb_mips, obj.st_info);
    abii_args->push_arg(printer);

    auto st_bind = ELF32_ST_BIND(obj.st_info);
    auto printer1 = new ArgPrinter(st_bind, "\t(ST_BIND)", &os);
    printer1->set_enum_printer(print_elf_stb, st_bind);
    abii_args->push_arg(printer1);

    auto st_type = ELF32_ST_TYPE(obj.st_info);
    auto printer2 = new ArgPrinter(st_type, "\t(ST_TYPE)", &os);
    printer2->set_enum_printer(print_elf_enum_sttype32, st_type);
    abii_args->push_arg(printer2);

    auto printer3 = new ArgPrinter(obj.st_other, "st_other", &os);
    printer3->set_enum_printer(print_elf_enum_stother32, obj.st_other);
    abii_args->push_arg(printer3);

    auto st_visibility = ELF32_ST_VISIBILITY(obj.st_other);
    auto printer4 = new ArgPrinter(st_visibility, "\t(ST_VISIBILITY)", &os);
    printer4->set_enum_printer(print_elf_stv, st_visibility);
    abii_args->push_arg(printer4);

    auto printer5 = new ArgPrinter(obj.st_shndx, "st_shndx", &os, RECURSE);
    printer5->set_enum_printer(print_elf_enum_stshndx, obj.st_shndx);
    abii_args->push_arg(printer5);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf64_Sym>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.st_name, "st_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_info, "st_info", &os));

    auto st_bind = ELF64_ST_BIND(obj.st_info);
    auto printer = new ArgPrinter(st_bind, "\t(ST_BIND)", &os);
    printer->set_enum_printer(print_elf_stb, st_bind);
    abii_args->push_arg(printer);

    auto st_type = ELF64_ST_TYPE(obj.st_info);
    auto printer1 = new ArgPrinter(st_type, "\t(ST_TYPE)", &os);
    printer1->set_enum_printer(print_elf_enum_sttype64, st_type);
    abii_args->push_arg(printer1);

    auto printer2 = new ArgPrinter(obj.st_other, "st_other", &os);
    printer2->set_enum_printer(print_elf_enum_stother64, obj.st_other);
    abii_args->push_arg(printer2);

    auto st_visibility = ELF64_ST_VISIBILITY(obj.st_other);
    auto printer3 = new ArgPrinter(st_visibility, "\t(ST_VISIBILITY)", &os);
    printer3->set_enum_printer(print_elf_stv, st_visibility);
    abii_args->push_arg(printer3);

    auto printer4 = new ArgPrinter(obj.st_shndx, "st_shndx", &os);
    printer4->set_enum_printer(print_elf_enum_stshndx, obj.st_shndx);
    abii_args->push_arg(printer4);

    abii_args->push_arg(new ArgPrinter(obj.st_value, "st_value", &os));
    abii_args->push_arg(new ArgPrinter(obj.st_size, "st_size", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Syminfo>
    || std::is_same_v<std::remove_cvref_t<T>, Elf64_Syminfo>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.si_boundto, "si_boundto", &os);
    printer->set_enum_printer(print_elf_syminfo_bt, obj.si_boundto);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.si_flags, "si_flags", &os, RECURSE);
    printer1->set_enum_printer(print_elf_syminfo_flg, obj.si_flags);
    abii_args->push_arg(printer1);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Rel>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.r_offset, "r_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.r_info, "r_info", &os));

    auto r_sym = ELF32_R_SYM(obj.r_info);
    abii_args->push_arg(new ArgPrinter(r_sym, "\t(R_SYM)", &os));

    auto r_type = ELF32_R_TYPE(obj.r_info);
    auto printer = new ArgPrinter(r_type, "\t(R_TYPE)", &os, RECURSE);
    printer->set_enum_printer(print_elf_enum_rtype32, r_type);
    abii_args->push_arg(printer);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf64_Rel>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.r_offset, "r_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.r_info, "r_info", &os, RECURSE));

    auto r_sym = ELF64_R_SYM(obj.r_info);
    abii_args->push_arg(new ArgPrinter(r_sym, "\t(R_SYM)", &os));

    auto r_type = ELF64_R_TYPE(obj.r_info);
    auto printer = new ArgPrinter(r_type, "\t(R_TYPE)", &os, RECURSE);
    printer->set_enum_printer(print_elf_enum_rtype64, r_type);
    abii_args->push_arg(printer);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Rela>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.r_offset, "r_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.r_info, "r_info", &os));

    auto r_sym = ELF32_R_SYM(obj.r_info);
    abii_args->push_arg(new ArgPrinter(r_sym, "\t(R_SYM)", &os));

    auto r_type = ELF32_R_TYPE(obj.r_info);
    auto printer = new ArgPrinter(r_type, "\t(R_TYPE)", &os, RECURSE);
    printer->set_enum_printer(print_elf_enum_rtype32, r_type);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.r_addend, "r_addend", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf64_Rela>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.r_offset, "r_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.r_info, "r_info", &os));

    auto r_sym = ELF64_R_SYM(obj.r_info);
    abii_args->push_arg(new ArgPrinter(r_sym, "\t(R_SYM)", &os));

    auto r_type = ELF64_R_TYPE(obj.r_info);
    auto printer = new ArgPrinter(r_type, "\t(R_TYPE)", &os, RECURSE);
    printer->set_enum_printer(print_elf_enum_rtype64, r_type);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.r_addend, "r_addend", &os, RECURSE);
    if (r_type == R_ALPHA_LITUSE)
        printer1->set_enum_printer(print_elf_lituse_alpha, obj.r_addend);
    abii_args->push_arg(printer);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Phdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.p_type, "p_type", &os);
    printer->set_enum_printer(print_elf_enum_ptype32, obj.p_type);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.p_offset, "p_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_vaddr, "p_vaddr", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_paddr, "p_paddr", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_filesz, "p_filesz", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_memsz, "p_memsz", &os));

    auto printer1 = new ArgPrinter(obj.p_flags, "p_flags", &os);
    printer1->set_enum_printer(print_elf_enum_pflags32, obj.p_flags);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.p_align, "p_align", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf64_Phdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.p_type, "p_type", &os);
    printer->set_enum_printer(print_elf_enum_ptype64, obj.p_type);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.p_flags, "p_flags", &os);
    printer1->set_enum_printer(print_elf_enum_pflags64, obj.p_flags);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.p_offset, "p_offset", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_vaddr, "p_vaddr", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_paddr, "p_paddr", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_filesz, "p_filesz", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_memsz, "p_memsz", &os));
    abii_args->push_arg(new ArgPrinter(obj.p_align, "p_align", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Dyn>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.d_tag, "d_tag", &os);
    printer->set_enum_printer(print_elf_enum_dtag32, obj.d_tag);
    abii_args->push_arg(printer);

    pre_fmtd_str str = "d_un: (" + get_type(obj.d_un) + ")";
    abii_args->push_arg(new ArgPrinter(str, "", &os));

    auto printer1 = new ArgPrinter(obj.d_un.d_val, "\td_val", &os);
    if (obj.d_tag == DT_FLAGS)
        printer1->set_enum_printer(print_elf_df, obj.d_un.d_val);
    else if (obj.d_tag == DT_FLAGS_1)
        printer1->set_enum_printer(print_elf_df_1, obj.d_un.d_val);
    else if (obj.d_tag == DT_FEATURE_1)
        printer1->set_enum_printer(print_elf_dtf_1, obj.d_un.d_val);
    else if (obj.d_tag == DT_POSFLAG_1)
        printer1->set_enum_printer(print_elf_df_p1, obj.d_un.d_val);
    else if (obj.d_tag == DT_MIPS_FLAGS)
        printer1->set_enum_printer(print_elf_rhf, obj.d_un.d_val);
    else if (obj.d_tag == DT_PPC_OPT)
        printer1->set_enum_printer(print_elf_ppc_opt, obj.d_un.d_val);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.d_un.d_ptr, "\td_ptr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf64_Dyn>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.d_tag, "d_tag", &os);
    printer->set_enum_printer(print_elf_enum_dtag64, obj.d_tag);
    abii_args->push_arg(printer);

    pre_fmtd_str str = "d_un: (" + get_type(obj.d_un) + ")";
    abii_args->push_arg(new ArgPrinter(str, "", &os));

    auto printer1 = new ArgPrinter(obj.d_un.d_val, "\td_val", &os);
    if (obj.d_tag == DT_FLAGS)
        printer1->set_enum_printer(print_elf_df, obj.d_un.d_val);
    else if (obj.d_tag == DT_FLAGS_1)
        printer1->set_enum_printer(print_elf_df_1, obj.d_un.d_val);
    else if (obj.d_tag == DT_FEATURE_1)
        printer1->set_enum_printer(print_elf_dtf_1, obj.d_un.d_val);
    else if (obj.d_tag == DT_POSFLAG_1)
        printer1->set_enum_printer(print_elf_df_p1, obj.d_un.d_val);
    else if (obj.d_tag == DT_PPC64_OPT)
        printer1->set_enum_printer(print_elf_ppc64_opt, obj.d_un.d_val);
    abii_args->push_arg(printer1);

    abii_args->push_arg(new ArgPrinter(obj.d_un.d_ptr, "\td_ptr", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Verdef>
    || std::is_same_v<std::remove_cvref_t<T>, Elf64_Verdef>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.vd_version, "vd_version", &os);
    printer->set_enum_printer(print_elf_ver_def, obj.vd_version);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.vd_flags, "vd_flags", &os);
    printer1->set_enum_printer(print_elf_ver_flg, obj.vd_flags);
    abii_args->push_arg(printer1);

    auto printer2 = new ArgPrinter(obj.vd_ndx, "vd_ndx", &os);
    printer2->set_enum_printer(print_elf_ver_ndx, obj.vd_ndx);
    abii_args->push_arg(printer2);

    abii_args->push_arg(new ArgPrinter(obj.vd_cnt, "vd_cnt", &os));
    abii_args->push_arg(new ArgPrinter(obj.vd_hash, "vd_hash", &os));
    abii_args->push_arg(new ArgPrinter(obj.vd_aux, "vd_aux", &os));
    abii_args->push_arg(new ArgPrinter(obj.vd_next, "vd_next", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Verdaux>
    || std::is_same_v<std::remove_cvref_t<T>, Elf64_Verdaux>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.vda_name, "vd_aux", &os));
    abii_args->push_arg(new ArgPrinter(obj.vda_next, "vd_next", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Verneed>
    || std::is_same_v<std::remove_cvref_t<T>, Elf64_Verneed>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.vn_version, "vn_version", &os);
    printer->set_enum_printer(print_elf_ver_need, obj.vn_version);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.vn_cnt, "vn_cnt", &os));
    abii_args->push_arg(new ArgPrinter(obj.vn_file, "vn_file", &os));
    abii_args->push_arg(new ArgPrinter(obj.vn_aux, "vn_aux", &os));
    abii_args->push_arg(new ArgPrinter(obj.vn_next, "vn_next", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Vernaux>
    || std::is_same_v<std::remove_cvref_t<T>, Elf64_Vernaux>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.vna_hash, "vna_hash", &os));

    auto printer = new ArgPrinter(obj.vna_flags, "vna_flags", &os);
    printer->set_enum_printer(print_elf_ver_flg, obj.vna_flags);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.vna_other, "vna_other", &os));
    abii_args->push_arg(new ArgPrinter(obj.vna_name, "vna_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.vna_next, "vna_next", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_auxv_t>
    || std::is_same_v<std::remove_cvref_t<T>, Elf64_auxv_t>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.a_type, "a_type", &os);
    printer->set_enum_printer(print_elf_at, obj.a_type);
    abii_args->push_arg(printer);

    pre_fmtd_str str = "a_un: (" + get_type(obj.a_un) + ")";
    abii_args->push_arg(new ArgPrinter(str, "", &os));

    abii_args->push_arg(new ArgPrinter(obj.a_un.a_val, "\ta_val", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Nhdr>
    || std::is_same_v<std::remove_cvref_t<T>, Elf64_Nhdr>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.n_namesz, "n_namesz", &os));
    abii_args->push_arg(new ArgPrinter(obj.n_descsz, "n_descsz", &os));

    auto printer = new ArgPrinter(obj.n_type, "n_type", &os, RECURSE);
    printer->set_enum_printer(print_elf_enum_ntype, obj.n_type);
    abii_args->push_arg(printer);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Move>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.m_value, "m_value", &os));
    abii_args->push_arg(new ArgPrinter(obj.m_info, "m_info", &os));

    auto m_size = ELF32_M_SIZE(obj.m_info);
    abii_args->push_arg(new ArgPrinter(m_size, "\t(M_SIZE)", &os));

    auto m_sym = ELF32_M_SYM(obj.m_info);
    abii_args->push_arg(new ArgPrinter(m_sym, "\t(M_SYM)", &os));

    abii_args->push_arg(new ArgPrinter(obj.m_poffset, "m_poffset", &os));
    abii_args->push_arg(new ArgPrinter(obj.m_repeat, "m_repeat", &os));
    abii_args->push_arg(new ArgPrinter(obj.m_stride, "m_stride", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf64_Move>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.m_value, "m_value", &os));
    abii_args->push_arg(new ArgPrinter(obj.m_info, "m_info", &os));

    auto m_size = ELF64_M_SIZE(obj.m_info);
    abii_args->push_arg(new ArgPrinter(m_size, "\t(M_SIZE)", &os));

    auto m_sym = ELF64_M_SYM(obj.m_info);
    abii_args->push_arg(new ArgPrinter(m_sym, "\t(M_SYM)", &os));

    abii_args->push_arg(new ArgPrinter(obj.m_poffset, "m_poffset", &os));
    abii_args->push_arg(new ArgPrinter(obj.m_repeat, "m_repeat", &os));
    abii_args->push_arg(new ArgPrinter(obj.m_stride, "m_stride", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_gptab>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    pre_fmtd_str str = "gt_header: (" + get_type(obj.gt_header) + ")";
    abii_args->push_arg(new ArgPrinter(str, "", &os));

    abii_args->push_arg(new ArgPrinter(obj.gt_header.gt_current_g_value, "\tgt_current_g_value", &os));
    abii_args->push_arg(new ArgPrinter(obj.gt_header.gt_unused, "\tgt_unused", &os));

    pre_fmtd_str str1 = "gt_entry: (" + get_type(obj.gt_entry) + ")";
    abii_args->push_arg(new ArgPrinter(str1, "", &os));

    abii_args->push_arg(new ArgPrinter(obj.gt_entry.gt_g_value, "\tgt_g_value", &os));
    abii_args->push_arg(new ArgPrinter(obj.gt_entry.gt_bytes, "\tgt_bytes", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_RegInfo>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.ri_gprmask, "ri_gprmask", &os));
    abii_args->push_arg(new ArgPrinter(obj.ri_cprmask, "ri_cprmask", &os));
    abii_args->push_arg(new ArgPrinter(obj.ri_gp_value, "ri_gp_value", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf_Options>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    auto printer = new ArgPrinter(obj.kind, "kind", &os);
    printer->set_enum_printer(print_elf_odk, obj.kind);
    abii_args->push_arg(printer);

    abii_args->push_arg(new ArgPrinter(obj.size, "size", &os));
    abii_args->push_arg(new ArgPrinter(obj.section, "section", &os));

    auto printer1 = new ArgPrinter(obj.info, "info", &os, RECURSE);
    if (obj.kind == ODK_EXCEPTIONS)
        printer1->set_enum_printer(print_elf_oex, obj.info);
    else if (obj.kind == ODK_HWPATCH)
        printer1->set_enum_printer(print_elf_ohw, obj.info);
    else if (obj.kind == ODK_HWAND || obj.kind == ODK_HWOR)
        printer1->set_enum_printer(print_elf_ohwa, obj.info);
    abii_args->push_arg(printer1);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf_Options_Hw>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.hwp_flags1, "hwp_flags1", &os));
    abii_args->push_arg(new ArgPrinter(obj.hwp_flags2, "hwp_flags2", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf32_Lib>
    || std::is_same_v<std::remove_cvref_t<T>, Elf64_Lib>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.l_name, "l_name", &os));
    abii_args->push_arg(new ArgPrinter(obj.l_time_stamp, "l_time_stamp", &os));
    abii_args->push_arg(new ArgPrinter(obj.l_checksum, "l_checksum", &os));
    abii_args->push_arg(new ArgPrinter(obj.l_version, "l_version", &os));

    auto printer = new ArgPrinter(obj.l_flags, "l_flags", &os, RECURSE);
    printer->set_enum_printer(print_elf_ll, obj.l_flags);
    abii_args->push_arg(printer);
    OVERRIDE_STREAM_SUFFIX
}

template <typename T> requires std::is_same_v<std::remove_cvref_t<T>, Elf_MIPS_ABIFlags_v0>
std::ostream& operator<<(std::ostream& os, T&& obj)
{
    OVERRIDE_STREAM_PREFIX
    abii_args->push_arg(new ArgPrinter(obj.version, "version", &os));
    abii_args->push_arg(new ArgPrinter(obj.isa_level, "isa_level", &os));
    abii_args->push_arg(new ArgPrinter(obj.isa_rev, "isa_rev", &os));

    auto printer = new ArgPrinter(obj.gpr_size, "gpr_size", &os);
    printer->set_enum_printer(print_elf_mips_afl_reg, obj.gpr_size);
    abii_args->push_arg(printer);

    auto printer1 = new ArgPrinter(obj.cpr1_size, "cpr1_size", &os);
    printer1->set_enum_printer(print_elf_mips_afl_reg, obj.cpr1_size);
    abii_args->push_arg(printer1);

    auto printer2 = new ArgPrinter(obj.cpr2_size, "cpr2_size", &os);
    printer2->set_enum_printer(print_elf_mips_afl_reg, obj.cpr2_size);
    abii_args->push_arg(printer2);

    abii_args->push_arg(new ArgPrinter(obj.fp_abi, "fp_abi", &os));

    auto printer3 = new ArgPrinter(obj.isa_ext, "isa_ext", &os);
    printer3->set_enum_printer(print_elf_mips_afl_ext, obj.isa_ext);
    abii_args->push_arg(printer3);

    auto printer4 = new ArgPrinter(obj.ases, "ases", &os);
    printer4->set_enum_printer(print_elf_mips_afl_ase, obj.ases);
    abii_args->push_arg(printer4);

    auto printer5 = new ArgPrinter(obj.flags1, "flags1", &os);
    printer5->set_enum_printer(print_elf_mips_afl_flags1, obj.flags1);
    abii_args->push_arg(printer5);

    abii_args->push_arg(new ArgPrinter(obj.flags2, "flags2", &os, RECURSE));
    OVERRIDE_STREAM_SUFFIX
}

#endif //ABII_C_LOGGING_PLUGIN_ELF_H
