#ifndef __SQESTDIO_H__
#define __SQESTDIO_H__

#ifndef OFFASSERT
    #define GAssert(expression) MyAssert(expression, __LINE__, __FILE__)
#else
    #define GAssert(expression)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum solutions {ZERO = 0,
                ONE  = 1,
                TWO  = 2,
                INFINITELY = 3};

void clear_buf (void);
void input_coef (double* coefficient);
void output_solveQE (solutions nSolutions, const double root1, const double root2);

void MyAssert(int expression, const int nline, const char file[]);

#endif
