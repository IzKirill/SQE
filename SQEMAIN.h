#ifndef __SQEMAIN_H__
#define __SQEMAIN_H__

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

const int amount_Tests = 15;

int SQEtest (void);

void MyAssert(int expression, const int nline, const char file[]);

solutions square_solve (const double a, const double b, const double c, double* root1, double* root2);

void User_Choice (int* your_choice);

void input_coef (double* coefficient);
void output_solveQE (solutions nSolutions, const double root1, const double root2);

#endif
