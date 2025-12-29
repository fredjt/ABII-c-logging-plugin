//
// Created by Trent Tanchin on 6/1/25.
//

#ifndef ABII_C_LOGGING_PLUGIN_STDINT_H
#define ABII_C_LOGGING_PLUGIN_STDINT_H

#include <csignal>
#include <abii/libabii.h>

namespace abii
{
const defines_map<int8_t> stdint_int8 = {
    {(-128), "INT8_MIN"},
    {127, "INT8_MAX"}
};

const defines_map<int16_t> stdint_int16 = {
    {(-32767 - 1), "INT16_MIN"},
    {32767, "INT16_MAX"}
};

const defines_map<int32_t> stdint_int32 = {
    {(-2147483647 - 1), "INT32_MIN"},
    {2147483647, "INT32_MAX"}
};

const defines_map<int64_t> stdint_int64 = {
#ifdef BIT32
    {(-9223372036854775807LL - 1), "INT64_MIN"},
    {9223372036854775807LL, "INT64_MAX"}
#else
    {(-9223372036854775807L - 1), "INT64_MIN"},
    {9223372036854775807L, "INT64_MAX"}
#endif
};

const defines_map<uint8_t> stdint_uint8 = {
    {255, "UINT8_MAX"}
};

const defines_map<uint16_t> stdint_uint16 = {
    {65535, "UINT16_MAX"},
};

const defines_map<uint32_t> stdint_uint32 = {
    {4294967295U, "UINT32_MAX"},
};

const defines_map<uint64_t> stdint_uint64 = {
#ifdef BIT32
    {18446744073709551615ULL, "UINT64_MAX"}
#else
    {18446744073709551615UL, "UINT64_MAX"}
#endif
};

const defines_map<int_least8_t> stdint_int_least8 = {
    {(-128), "INT_LEAST8_MIN"},
    {127, "INT_LEAST8_MAX"}
};

const defines_map<int_least16_t> stdint_int_least16 = {
    {(-32767 - 1), "INT_LEAST16_MIN"},
    {32767, "INT_LEAST16_MAX"},
};

const defines_map<int_least32_t> stdint_int_least32 = {
    {(-2147483647 - 1), "INT_LEAST32_MIN"},
    {2147483647, "INT_LEAST32_MAX"},
};

const defines_map<int_least64_t> stdint_int_least64 = {
#ifdef BIT32
    {(-9223372036854775807LL - 1), "INT_LEAST64_MIN"},
    {9223372036854775807LL, "INT_LEAST64_MAX"}
#else
    {(-9223372036854775807L - 1), "INT_LEAST64_MIN"},
    {9223372036854775807L, "INT_LEAST64_MAX"}
#endif
};

const defines_map<uint_least8_t> stdint_uint_least8 = {
    {255, "UINT_LEAST8_MAX"}
};

const defines_map<uint_least16_t> stdint_uint_least16 = {
    {65535, "UINT_LEAST16_MAX"},
};

const defines_map<uint_least32_t> stdint_uint_least32 = {
    {4294967295U, "UINT_LEAST32_MAX"},
};

const defines_map<uint_least64_t> stdint_uint_least64 = {
#ifdef BIT32
    {18446744073709551615ULL, "UINT_LEAST64_MAX"}
#else
    {18446744073709551615UL, "UINT_LEAST64_MAX"}
#endif
};

const defines_map<int_fast8_t> stdint_int_fast8 = {
    {(-128), "INT_FAST8_MIN"},
    {127, "INT_FAST8_MAX"}
};

const defines_map<int_fast16_t> stdint_int_fast16 = {
#ifdef BIT32
    {(-2147483647 - 1), "INT_FAST16_MIN"},
    {2147483647, "INT_FAST16_MAX"}
#else
    {(-9223372036854775807L - 1), "INT_FAST16_MIN"},
    {9223372036854775807L, "INT_FAST16_MAX"}
#endif
};

const defines_map<int_fast32_t> stdint_int_fast32 = {
#ifdef BIT32
    {(-2147483647 - 1), "INT_FAST32_MIN"},
    {2147483647, "INT_FAST32_MAX"}
#else
    {(-9223372036854775807L - 1), "INT_FAST32_MIN"},
    {9223372036854775807L, "INT_FAST32_MAX"}
#endif
};

const defines_map<int_fast64_t> stdint_int_fast64 = {
#ifdef BIT32
    {(-9223372036854775807LL - 1), "INT_FAST64_MIN"},
    {9223372036854775807LL, "INT_FAST64_MAX"}
#else
    {(-9223372036854775807L - 1), "INT_FAST64_MIN"},
    {9223372036854775807L, "INT_FAST64_MAX"}
#endif
};

const defines_map<uint_fast8_t> stdint_uint_fast8 = {
    {255, "UINT_FAST8_MAX"}
};

const defines_map<uint_fast16_t> stdint_uint_fast16 = {
#ifdef BIT32
    {4294967295U, "UINT_FAST16_MAX"}
#else
    {18446744073709551615UL, "UINT_FAST16_MAX"}
#endif
};

const defines_map<uint_fast32_t> stdint_uint_fast32 = {
#ifdef BIT32
    {4294967295U, "UINT_FAST32_MAX"}
#else
    {18446744073709551615UL, "UINT_FAST32_MAX"}
#endif
};

const defines_map<uint_fast64_t> stdint_uint_fast64 = {
#ifdef BIT32
    {18446744073709551615ULL, "UINT_FAST64_MAX"}
#else
    {18446744073709551615UL, "UINT_FAST64_MAX"}
#endif
};

const defines_map<intptr_t> stdint_intptr = {
#ifdef BIT32
    {(-2147483647 - 1), "INTPTR_MIN"},
    {2147483647, "INTPTR_MAX"}
#else
    {(-9223372036854775807L - 1), "INTPTR_MIN"},
    {9223372036854775807L, "INTPTR_MAX"}
#endif
};

const defines_map<uintptr_t> stdint_uintptr = {
#ifdef BIT32
    {4294967295U, "UINTPTR_MAX"}
#else
    {18446744073709551615UL, "UINTPTR_MAX"}
#endif
};

const defines_map<intmax_t> stdint_intmax = {
#ifdef BIT32
    {(-9223372036854775807LL - 1), "INTMAX_MIN"},
    {9223372036854775807LL, "INTMAX_MAX"}
#else
    {(-9223372036854775807L - 1), "INTMAX_MIN"},
    {9223372036854775807L, "INTMAX_MAX"}
#endif
};

const defines_map<uintmax_t> stdint_uintmax = {
#ifdef BIT32
    {18446744073709551615ULL, "UINTMAX_MAX"}
#else
    {18446744073709551615UL, "UINTMAX_MAX"}
#endif
};

const defines_map<ptrdiff_t> stdint_ptrdiff = {
#ifdef BIT32
    {(-2147483647 - 1), "PTRDIFF_MIN"},
    {2147483647, "PTRDIFF_MAX"}
#else
    {(-9223372036854775807L - 1), "PTRDIFF_MIN"},
    {9223372036854775807L, "PTRDIFF_MAX"}
#endif
};

const defines_map<sig_atomic_t> stdint_sig_atomic = {
    {(-2147483647 - 1), "SIG_ATOMIC_MIN"},
    {2147483647, "SIG_ATOMIC_MAX"}
};

const defines_map<size_t> stdint_size = {
#ifdef BIT32
    {4294967295U, "SIZE_MAX"}
#else
    {18446744073709551615UL, "SIZE_MAX"}
#endif
};

const defines_map<wchar_t> stdint_wchar = {
    {1, "WCHAR_MIN"},
#ifdef BIT32
    {0x7fffffffL, "WCHAR_MAX"}
#else
    {0x7fffffff, "WCHAR_MAX"}
#endif
};

const defines_map<wint_t> stdint_wint = {
    {0u, "WINT_MIN"},
    {4294967295u, "WINT_MAX"}
};

const defines_map stdint_width = {
    {8, "INT8_WIDTH"},
    {8, "UINT8_WIDTH"},
    {16, "INT16_WIDTH"},
    {16, "UINT16_WIDTH"},
    {32, "INT32_WIDTH"},
    {32, "UINT32_WIDTH"},
    {64, "INT64_WIDTH"},
    {64, "UINT64_WIDTH"},
    {8, "INT_LEAST8_WIDTH"},
    {8, "UINT_LEAST8_WIDTH"},
    {16, "INT_LEAST16_WIDTH"},
    {16, "UINT_LEAST16_WIDTH"},
    {32, "INT_LEAST32_WIDTH"},
    {32, "UINT_LEAST32_WIDTH"},
    {64, "INT_LEAST64_WIDTH"},
    {64, "UINT_LEAST64_WIDTH"},
    {8, "INT_FAST8_WIDTH"},
    {8, "UINT_FAST8_WIDTH"},
#ifdef BIT32
    {32, "INT_FAST16_WIDTH"},
    {32, "UINT_FAST16_WIDTH"},
    {32, "INT_FAST32_WIDTH"},
    {32, "UINT_FAST32_WIDTH"},
#else
    {64, "INT_FAST16_WIDTH"},
    {64, "UINT_FAST16_WIDTH"},
    {64, "INT_FAST32_WIDTH"},
    {64, "UINT_FAST32_WIDTH"},
#endif
    {64, "INT_FAST64_WIDTH"},
    {64, "UINT_FAST64_WIDTH"},
#ifdef BIT32
    {32, "INTPTR_WIDTH"},
    {32, "UINTPTR_WIDTH"},
#else
    {64, "INTPTR_WIDTH"},
    {64, "UINTPTR_WIDTH"},
#endif
    {64, "INTMAX_WIDTH"},
    {64, "UINTMAX_WIDTH"},
#ifdef BIT32
    {32, "PTRDIFF_WIDTH"},
#else
    {64, "PTRDIFF_WIDTH"},
#endif
    {32, "SIG_ATOMIC_WIDTH"},
#ifdef BIT32
    {32, "SIZE_WIDTH"},
#else
    {64, "SIZE_WIDTH"},
#endif
    {32, "WCHAR_WIDTH"},
    {32, "WINT_WIDTH"}
};

template <typename T>
std::string print_stdint_int8(const T v)
{
    return print_enum_entry(v, stdint_int8);
}

template <typename T>
std::string print_stdint_int16(const T v)
{
    return print_enum_entry(v, stdint_int16);
}

template <typename T>
std::string print_stdint_int32(const T v)
{
    return print_enum_entry(v, stdint_int32);
}

template <typename T>
std::string print_stdint_int64(const T v)
{
    return print_enum_entry(v, stdint_int64);
}

template <typename T>
std::string print_stdint_uint8(const T v)
{
    return print_enum_entry(v, stdint_uint8);
}

template <typename T>
std::string print_stdint_uint16(const T v)
{
    return print_enum_entry(v, stdint_uint16);
}

template <typename T>
std::string print_stdint_uint32(const T v)
{
    return print_enum_entry(v, stdint_uint32);
}

template <typename T>
std::string print_stdint_uint64(const T v)
{
    return print_enum_entry(v, stdint_uint64);
}

template <typename T>
std::string print_stdint_int_least8(const T v)
{
    return print_enum_entry(v, stdint_int_least8);
}

template <typename T>
std::string print_stdint_int_least16(const T v)
{
    return print_enum_entry(v, stdint_int_least16);
}

template <typename T>
std::string print_stdint_int_least32(const T v)
{
    return print_enum_entry(v, stdint_int_least32);
}

template <typename T>
std::string print_stdint_int_least64(const T v)
{
    return print_enum_entry(v, stdint_int_least64);
}

template <typename T>
std::string print_stdint_uint_least8(const T v)
{
    return print_enum_entry(v, stdint_uint_least8);
}

template <typename T>
std::string print_stdint_uint_least16(const T v)
{
    return print_enum_entry(v, stdint_uint_least16);
}

template <typename T>
std::string print_stdint_uint_least32(const T v)
{
    return print_enum_entry(v, stdint_uint_least32);
}

template <typename T>
std::string print_stdint_uint_least64(const T v)
{
    return print_enum_entry(v, stdint_uint_least64);
}

template <typename T>
std::string print_stdint_int_fast8(const T v)
{
    return print_enum_entry(v, stdint_int_fast8);
}

template <typename T>
std::string print_stdint_int_fast16(const T v)
{
    return print_enum_entry(v, stdint_int_fast16);
}

template <typename T>
std::string print_stdint_int_fast32(const T v)
{
    return print_enum_entry(v, stdint_int_fast32);
}

template <typename T>
std::string print_stdint_int_fast64(const T v)
{
    return print_enum_entry(v, stdint_int_fast64);
}

template <typename T>
std::string print_stdint_uint_fast8(const T v)
{
    return print_enum_entry(v, stdint_uint_fast8);
}

template <typename T>
std::string print_stdint_uint_fast16(const T v)
{
    return print_enum_entry(v, stdint_uint_fast16);
}

template <typename T>
std::string print_stdint_uint_fast32(const T v)
{
    return print_enum_entry(v, stdint_uint_fast32);
}

template <typename T>
std::string print_stdint_uint_fast64(const T v)
{
    return print_enum_entry(v, stdint_uint_fast64);
}

template <typename T>
std::string print_stdint_intptr(const T v)
{
    return print_enum_entry(v, stdint_intptr);
}

template <typename T>
std::string print_stdint_uintptr(const T v)
{
    return print_enum_entry(v, stdint_uintptr);
}

template <typename T>
std::string print_stdint_intmax(const T v)
{
    return print_enum_entry(v, stdint_intmax);
}

template <typename T>
std::string print_stdint_uintmax(const T v)
{
    return print_enum_entry(v, stdint_uintmax);
}

template <typename T>
std::string print_stdint_ptrdiff(const T v)
{
    return print_enum_entry(v, stdint_ptrdiff);
}

template <typename T>
std::string print_stdint_sig_atomic(const T v)
{
    return print_enum_entry(v, stdint_sig_atomic);
}

template <typename T>
std::string print_stdint_size(const T v)
{
    return print_enum_entry(v, stdint_size);
}

template <typename T>
std::string print_stdint_wchar(const T v)
{
    return print_enum_entry(v, stdint_wchar);
}

template <typename T>
std::string print_stdint_wint(const T v)
{
    return print_enum_entry(v, stdint_wint);
}

template <typename T>
std::string print_stdint_width(const T v)
{
    return print_enum_entry(v, stdint_width);
}
}

#endif //ABII_C_LOGGING_PLUGIN_STDINT_H
