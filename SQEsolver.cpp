#include "SQEsolver.h"
#include "SQEcmpdoubles.h"
#include "MyAssert.h"
#include <stdio.h>
#include <math.h>

static solutions discriminant (const double a, const double b, const double c,
                               double* root1, double* root2);


solutions square_solve (const double a,const double b,const double c, double* x1, double* x2)
{
    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));
    GAssert(isfinite(*x1));
    GAssert(isfinite(*x2));

    if (equal_zero(a))
    {
      return lin_solver (b, c, x1);
    }
    else
    {
      if (equal_zero(b))
      {
        if (equal_zero(c))
        {
            GAssert(!(equal_zero(a)));

            *x1 = 0;

            GAssert(isfinite(*x1));

            return ONE;
        }
        else if (cmpz_doubles(c) == DOUBLE_MORE_ZERO)
        {

                GAssert(equal_zero(b));
                GAssert(!(equal_zero(a)));

                return ZERO;
        }
        else
        {

                GAssert(equal_zero(b));
                GAssert(!(equal_zero(a)));
                GAssert(cmpz_doubles(c) == DOUBLE_LESS_ZERO);

                double root_of_c = sqrt(-c/a);
                *x1 = root_of_c;
                *x2 = -root_of_c;

                GAssert(cmp_doubles(*x1, *x2) != DOUBLE_EQUALS_ZERO);
                GAssert(isfinite(*x1));
                GAssert(isfinite(*x2));

                return TWO;
        }
       }
       else if (equal_zero(c))
       {

            GAssert(!(equal_zero(a)));
            GAssert(!(equal_zero(b)));

            *x1 = 0;
            lin_solver (a, b, x2);

            GAssert(cmp_doubles(*x1, *x2) != DOUBLE_EQUALS_ZERO);
            GAssert(isfinite(*x2));
            GAssert(isfinite(*x1));

            return TWO;
       }
       else
       {
            return discriminant(a, b, c, x1, x2);
       }
    }
}

solutions lin_solver (const double b, const double c, double* root1)
{

    GAssert(isfinite(b));
    GAssert(isfinite(c));

    if (equal_zero(b))
    {
        if (equal_zero(c))
        {
            return INFINITELY;
        }
        else
        {
            return ZERO;
        }
    }
    else
    {
        *root1 = -c/b;

        GAssert(isfinite(*root1));

        return ONE;
    }
}

static solutions discriminant (const double a, const double b, const double c,
                               double* root1, double* root2)
{

    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));
    GAssert(!(equal_zero(a)));
    GAssert(!(equal_zero(b)));
    GAssert(!(equal_zero(c)));

    double D = b*b - 4*a*c;

    GAssert(isfinite(D));

    if (cmpz_doubles(D) == DOUBLE_LESS_ZERO)
    {
        GAssert(isfinite(D));

        return ZERO;
    }
    else if (equal_zero(D))
    {
        GAssert(isfinite(D));

        *root1 = - b/(2*a);
        return ONE;
    }
    else
    {
        GAssert(isfinite(D));

        double root_of_disciminant = sqrt(D);
        *root1 = (-b + root_of_disciminant) / (2*a);
        *root2 = (-b - root_of_disciminant) / (2*a);

        GAssert(cmp_doubles(*root1, *root2) != DOUBLE_EQUALS_ZERO);
        GAssert(isfinite(*root1));
        GAssert(isfinite(*root2));

        return TWO;
    }
}
