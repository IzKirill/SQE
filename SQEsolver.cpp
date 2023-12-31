#include "SQEsolver.h"
#include "SQEcmpdoubles.h"
#include "MyAssert.h"
#include <stdio.h>
#include <math.h>

static Solutions QE_part_discriminant (const double a, const double b, const double c,
                                       double* root1, double* root2);


Solutions square_solver (const double a,const double b,const double c,
                         double* root1, double* root2)
{
    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));
    GAssert(isfinite(*root1));
    GAssert(isfinite(*root2));
    GAssert(root1 != NULL);
    GAssert(root2 != NULL);

    if (equal_zero(a))   // a=0
    {
      return lin_solver (b, c, root1);
    }
    else    // a!=0
    {
      if (equal_zero(b))
      {
        if (equal_zero(c))    // a!=0 b=0 c=0
        {
            GAssert(!(equal_zero(a)));

            *root1 = 0;

            GAssert(isfinite(*root1));

            return ONE;
        }
        else if (cmpz_doubles(c) == DOUBLE_MORE_ZERO)  // a!=0 b=0 c>0
        {
                GAssert(equal_zero(b));
                GAssert(!(equal_zero(a)));

                return ZERO;
        }
        else     // a!=0 b=0 c<0
        {
                GAssert(equal_zero(b));
                GAssert(!(equal_zero(a)));
                GAssert(cmpz_doubles(c) == DOUBLE_LESS_ZERO);

                double root_of_c = sqrt(-c/a);
                *root1 = root_of_c;
                *root2 = -root_of_c;

                GAssert(cmp_doubles(*root1, *root2) != DOUBLE_EQUALS_ZERO);
                GAssert(isfinite(*root1));
                GAssert(isfinite(*root2));

                return TWO;
        }
       }
       else if (equal_zero(c))   // a!=0 b!=0 c=0
       {
            GAssert(!(equal_zero(a)));
            GAssert(!(equal_zero(b)));

            *root1 = 0;
            lin_solver (a, b, root2);

            GAssert(cmp_doubles(*root1, *root2) != DOUBLE_EQUALS_ZERO);
            GAssert(isfinite(*root2));
            GAssert(isfinite(*root1));

            return TWO;
       }
       else   // a!=0 b!=0 c!=0
       {
            return QE_part_discriminant(a, b, c, root1, root2);
       }
    }
}

Solutions lin_solver (const double b, const double c, double* root1)
{
    GAssert(isfinite(b));
    GAssert(isfinite(c));
    GAssert(root1 != NULL);

    if (equal_zero(b))
    {
        if (equal_zero(c))    // b=0 c=0
        {
            return INFINITELY;
        }
        else  // b=0 c!=0
        {
            return ZERO;
        }
    }
    else  //b!=0 c!=0
    {
        *root1 = -c/b;

        GAssert(isfinite(*root1));

        return ONE;
    }
}

static Solutions QE_part_discriminant (const double a, const double b, const double c,
                                       double* root1, double* root2)
{
    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));
    GAssert(isfinite(*root1));
    GAssert(isfinite(*root2));
    GAssert(!(equal_zero(a)));
    GAssert(!(equal_zero(b)));
    GAssert(!(equal_zero(c)));
    GAssert(root1 != NULL);
    GAssert(root2 != NULL);

    double D = b*b - 4*a*c;

    GAssert(isfinite(D));

    if (cmpz_doubles(D) == DOUBLE_LESS_ZERO)   // D<0
    {
        GAssert(isfinite(D));

        return ZERO;
    }
    else if (equal_zero(D))   // D=0
    {
        GAssert(isfinite(D));

        *root1 = - b/(2*a);
        return ONE;
    }
    else      // D>0
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
