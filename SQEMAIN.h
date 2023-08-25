#ifndef __SQEMAIN_H__
#define __SQEMAIN_H__

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

const int amount_Tests = 15;

void MyAssert(int expression, const int nline, const char file[]);

void User_Choice (int* your_choice);

int SQEtest (void);

solutions square_solve (const double a, const double b, const double c, double* root1, double* root2);

void input_coef (double* coefficient);
void output_solveQE (solutions nSolutions, const double x1, const double x2);

#endif
