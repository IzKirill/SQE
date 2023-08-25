#ifndef __SQECMPDOUBLES_H__
#define __SQECMPDOUBLES_H__

#ifndef OFFASSERT
    #define GAssert(expression) MyAssert(expression, __LINE__, __FILE__)
#else
    #define GAssert(expression)
#endif

#include <stdio.h>
#include <math.h>

const double EPS = 1e-9;

enum cmp_double {DOUBLE_EQUALS_ZERO = 0,
                 DOUBLE_MORE_ZERO = 1,
                 DOUBLE_LESS_ZERO = 2};

cmp_double cmpz_doubles (const double double_number);
int cmp_doubles (const double double_number1, const double double_numbr2);
bool equal_zero(const double coefficient);

void MyAssert(int expression, const int nline, const char file[]);

#endif
