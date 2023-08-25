#ifndef __SQETEST_H__
#define __SQETEST_H__

#ifndef OFFASSERT
    #define GAssert(expression) MyAssert(expression, __LINE__, __FILE__)
#else
    #define GAssert(expression)
#endif

#include <stdio.h>
#include <math.h>
#include <float.h>

enum solutions {ZERO = 0,
                ONE  = 1,
                TWO  = 2,
                INFINITELY = 3};

struct TestData
{
    double a, b, c;
    double x1, x2;
    solutions nroots;
    int number_test;
};

const int amount_Tests = 15;


int SQEtest (void);
int test_n (TestData* ref);
void failed_test(const double a, const double b, const double c, const int number_test);

void MyAssert(int expression, const int nline, const char file[]);

solutions square_solve (const double a, const double b, const double c, double* root1, double* root2);
void sort_roots (double* x1, double* x2);

int cmp_doubles (const double double_number1, const double double_number2);

#endif
