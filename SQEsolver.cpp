#include "SQEsolver.h"

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

      GAssert(a == 0);

      return lin_solver (b, c, x1);
    }
    else
    {
      if (equal_zero(b))
      {
        if (equal_zero(c))
        {

            GAssert(b == 0);
            GAssert(c == 0);
            GAssert(a != 0);

            *x1 = 0;

            GAssert(isfinite(*x1));

            return ONE;
        }
        else if (cmpz_doubles(c) == DOUBLE_MORE_ZERO)
        {

                GAssert(b == 0);
                GAssert(a != 0);
                GAssert(c > 0);

                return ZERO;
        }
        else
        {

                GAssert(b == 0);
                GAssert(a != 0);
                GAssert(c < 0);

                double root_of_c = sqrt(-c/a);
                *x1 = root_of_c;
                *x2 = -root_of_c;

                GAssert(*x1 != *x2);
                GAssert(isfinite(*x1));
                GAssert(isfinite(*x2));

                return TWO;
        }
       }
       else if (equal_zero(c))
       {

            GAssert(c == 0);
            GAssert(a != 0);
            GAssert(b != 0);

            *x1 = 0;
            lin_solver (a, b, x2);

            GAssert(*x1 != *x2);
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

            GAssert(c == 0);
            GAssert(b == 0);

            return INFINITELY;
        }
        else
        {

            GAssert(c != 0);
            GAssert(b == 0);

            return ZERO;
        }
    }
    else
    {

        GAssert(b != 0);

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
    GAssert(b != 0);
    GAssert(a != 0);
    GAssert(c != 0);

    double D = b*b - 4*a*c;

    GAssert(isfinite(D));

    if (cmpz_doubles(D) == DOUBLE_LESS_ZERO)
    {

        GAssert(D < 0);
        GAssert(isfinite(D));

        return ZERO;
    }
    else if (equal_zero(D))
    {

        GAssert(D == 0);
        GAssert(isfinite(D));

        *root1 = - b/(2*a);
        return ONE;
    }
    else
    {

        GAssert(D > 0);
        GAssert(isfinite(D));

        double root_of_disciminant = sqrt(D);
        *root1 = (-b + root_of_disciminant) / (2*a);
        *root2 = (-b - root_of_disciminant) / (2*a);

        GAssert(*root1 != *root2);
        GAssert(isfinite(*root1));
        GAssert(isfinite(*root2));

        return TWO;
    }
}
