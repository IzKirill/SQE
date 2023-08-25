#ifndef __SQESOLVER_H__
#define __SQESOLVER_H__

#ifndef OFFASSERT
    #define GAssert(expression) MyAssert(expression, __LINE__, __FILE__)
#else
    #define GAssert(expression)
#endif

#include <stdio.h>
#include <math.h>

enum solutions {ZERO = 0,
                ONE  = 1,
                TWO  = 2,
                INFINITELY = 3};

enum cmp_double {DOUBLE_EQUALS_ZERO = 0,
                 DOUBLE_MORE_ZERO = 1,
                 DOUBLE_LESS_ZERO = 2};

void MyAssert(int expression, const int nline, const char file[]);

cmp_double cmpz_doubles (const double double_number);
bool equal_zero(const double coefficient);

solutions square_solve (const double a, const double b, const double c, double* root1, double* root2);
solutions lin_solver (const double b, const double c, double* root1);

#endif
