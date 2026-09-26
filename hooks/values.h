//
// Created by Trent Tanchin on 9/26/26.
//

#ifndef ABII_C_LOGGING_PLUGIN_VALUES_H
#define ABII_C_LOGGING_PLUGIN_VALUES_H

#include <values.h>
#include <abii/libabii.h>

namespace abii
{
const defines_map values_bits = {
    {(sizeof(char) * 8), "CHARBITS"},
    {(sizeof(short int) * 8), "SHORTBITS"},
    {(sizeof(int) * 8), "INTBITS"},
    {(sizeof(long int) * 8), "LONGBITS"},
    {(sizeof(char*) * 8), "PTRBITS"},
    {(sizeof(double) * 8), "DOUBLEBITS"},
    {(sizeof(float) * 8), "FLOATBITS"}
};

const defines_map<short> values_short = {
    {(-0x7fff - 1), "MINSHORT"},
    {0x7fff, "MAXSHORT"},
    {(-0x7fff - 1), "HIBITS"}
};

const defines_map<int> values_int = {
    {(-0x7fffffff - 1), "MININT"},
    {0x7fffffff, "MAXINT"}
};

const defines_map<long> values_long = {
    {(-0x7fffffffffffffffL - 1L), "MINLONG"},
    {0x7fffffffffffffffL, "MAXLONG"},
    {(-0x7fffffffffffffffL - 1L), "HIBITL"}
};

const defines_map<double> values_double = {
    {static_cast<double>(1.79769313486231570814527423731704357e+308L), "MAXDOUBLE"},
    {static_cast<double>(2.22507385850720138309023271733240406e-308L), "MINDOUBLE"}
};

const defines_map<float> values_float = {
    {3.40282346638528859811704183484516925e+38F, "MAXFLOAT"},
    {1.17549435082228750796873653722224568e-38F, "MINFLOAT"}
};

const defines_map values_dexp = {
    {(-1021), "DMINEXP"},
    {1024, "DMAXEXP"}
};

const defines_map values_fexp = {
    {(-125), "FMINEXP"},
    {128, "FMAXEXP"}
};

const defines_map values_bitsperbyte = {
    {8, "BITSPERBYTE"}
};

template <typename T>
std::string print_values_bits(const T v)
{
    return print_enum_entry(v, values_bits);
}

template <typename T>
std::string print_values_short(const T v)
{
    return print_enum_entry(v, values_short);
}

template <typename T>
std::string print_values_int(const T v)
{
    return print_enum_entry(v, values_int);
}

template <typename T>
std::string print_values_long(const T v)
{
    return print_enum_entry(v, values_long);
}

template <typename T>
std::string print_values_double(const T v)
{
    return print_enum_entry(v, values_double);
}

template <typename T>
std::string print_values_float(const T v)
{
    return print_enum_entry(v, values_float);
}

template <typename T>
std::string print_values_dexp(const T v)
{
    return print_enum_entry(v, values_dexp);
}

template <typename T>
std::string print_values_fexp(const T v)
{
    return print_enum_entry(v, values_fexp);
}

template <typename T>
std::string print_values_bitsperbyte(const T v)
{
    return print_enum_entry(v, values_bitsperbyte);
}
}

#endif //ABII_C_LOGGING_PLUGIN_VALUES_H
