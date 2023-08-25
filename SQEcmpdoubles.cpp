#include "SQEcmpdoubles.h"
#include "MyAssert.h"
#include <stdio.h>
#include <math.h>


cmp_double cmpz_doubles (const double double_number)
{

    GAssert(isfinite(double_number));

    if (fabs(double_number) < EPS)
        return DOUBLE_EQUALS_ZERO;
    else if (double_number > EPS)
        return DOUBLE_MORE_ZERO;
    else
        return DOUBLE_LESS_ZERO;
}

bool equal_zero(const double coefficient)
{

    GAssert(isfinite(coefficient));

    return cmpz_doubles(coefficient) == DOUBLE_EQUALS_ZERO;
}

int cmp_doubles (const double double_number1, const double double_number2)
{

    GAssert(isfinite(double_number1));
    GAssert(isfinite(double_number2));

    return cmpz_doubles(double_number1 - double_number2);
}
