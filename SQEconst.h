#ifndef __SQECONST_H__
#define __SQECONST_H__

enum solutions {ZERO = 0,
                ONE  = 1,
                TWO  = 2,
                INFINITELY = 3};

enum cmp_double {DOUBLE_EQUALS_ZERO = 0,
                 DOUBLE_MORE_ZERO = 1,
                 DOUBLE_LESS_ZERO = 2};

struct TestData
{
    double a, b, c;
    double x1, x2;
    solutions nroots;
    int number_test;
};

const double EPS = 1e-9;
const int amount_Tests = 15;

#endif
