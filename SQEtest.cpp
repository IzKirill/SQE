#include "SQEsolver.h"
#include "SQEtest.h"
#include "MyAssert.h"
#include "SQEcmpdoubles.h"
#include "SQEstdio.h"
#include <stdio.h>
#include <math.h>
#include <float.h>

int SQEtest(void)
{
    static TestData TInputData[amount_Tests] =
    {{.a = 0,  .b = 0,    .c = 0,        .x1 = 0,       .x2 = 0,   .nroots = INFINITELY,},
     {.a = 5,  .b = 0,    .c = 10,       .x1 = 0,       .x2 = 0,   .nroots = ZERO,      },
     {.a = 0,  .b = 0,    .c = 15,       .x1 = 0,       .x2 = 0,   .nroots = ZERO,      },
     {.a = 0,  .b = 10,   .c = 20,       .x1 = -2,      .x2 = 0,   .nroots = ONE,       },
     {.a = -5, .b = 0,    .c = 0,        .x1 = 0,       .x2 = 0,   .nroots = ONE,       },
     {.a = 5,  .b = 0,    .c = -125,     .x1 = -5,      .x2 = 5,   .nroots = TWO,       },
     {.a = 10, .b = 10,   .c = 0,        .x1 = -1,      .x2 = 0,   .nroots = TWO,       },
     {.a = 2,  .b = -1,   .c = 4,        .x1 = 0,       .x2 = 0,   .nroots = ZERO,      },
     {.a = 1,  .b = 2,    .c = 1,        .x1 = -1,      .x2 = 0,   .nroots = ONE,       },
     {.a = 1,  .b = -6,   .c = 5,        .x1 = 1,       .x2 = 5,   .nroots = TWO,       },
     {.a = 4,  .b = 5,    .c = -9,       .x1 = -2.25,   .x2 = 1,   .nroots = TWO,       },
     {.a = 1,  .b = -4,   .c = 3.75,     .x1 = 1.5,     .x2 = 2.5, .nroots = TWO,       },
     {.a = 1,  .b = 7.25, .c = -24.375,  .x1 = -9.75,   .x2 = 2.5, .nroots = TWO,       },
     {.a = 0,  .b = 1,    .c = -DBL_MAX, .x1 = DBL_MAX, .x2 = 0,   .nroots = ONE,       },
     {.a = 0,  .b = 1,    .c = -DBL_MIN, .x1 = DBL_MIN, .x2 = 0,   .nroots = ONE,       },
     {.a = 1,  .b = 2,    .c = 1,        .x1 = -1,      .x2 = 0,   .nroots = ONE,       }};
    int nOK = 0;
    for (int i = 0; i < amount_Tests; i++)
        nOK += test_n(&TInputData[i], i+1);

    return nOK;
}

int test_n(TestData* ref, const int IDtest)
{
    GAssert(isfinite(ref->a));
    GAssert(isfinite(ref->b));
    GAssert(isfinite(ref->c));

    double  x1 = 0, x2 = 0;
    Solutions nSolutions = square_solver(ref->a, ref->b, ref->c, &x1, &x2);

    GAssert(isfinite(x1));
    GAssert(isfinite(x2));
    GAssert(ref->nroots == ZERO || ref->nroots == ONE ||
            ref->nroots == TWO  || ref->nroots == INFINITELY);

    switch (ref->nroots)
    {
    case(ZERO):
        if (nSolutions != ref->nroots)
        {
            failed_test(ref->a, ref->b, ref->c, IDtest);
            printf("\n" "Correct output:");
            output_solveQE(ref->nroots, ref->x1, ref->x2);
            printf("\n" "Your code output:");
            output_solveQE(nSolutions, x1, x2);
            return 0;
        }
        return 1;
        break;

    case(ONE):
        if(nSolutions != ref->nroots || cmp_doubles(x1, ref->x1))
        {
            failed_test(ref->a, ref->b, ref->c, IDtest);
            printf("\n" "Correct output:");
            output_solveQE(ref->nroots, ref->x1, ref->x2);
            printf("\n" "Your code output:");
            output_solveQE(nSolutions, x1, x2);
            return 0;
        }
        return 1;
        break;

    case(TWO):
        sort_roots(&x1, &x2);
        if (nSolutions != ref->nroots || cmp_doubles(x1, ref->x1) ||
            cmp_doubles(x2, ref->x2))
        {
            failed_test(ref->a, ref->b, ref->c, IDtest);
            printf("\n" "Correct output:");
            output_solveQE(ref->nroots, ref->x1, ref->x2);
            printf("\n" "Your code output:");
            output_solveQE(nSolutions, x1, x2);
            return 0;
        }
        return 1;
        break;

    case(INFINITELY):
        if (nSolutions != ref->nroots)
        {
            failed_test(ref->a, ref->b, ref->c, IDtest);
            printf("\n" "Correct output:");
            output_solveQE(ref->nroots, ref->x1, ref->x2);
            printf("\n" "Your code output:");
            output_solveQE(nSolutions, x1, x2);
            return 0;
        }
        return 1;
        break;

    default:
        printf("ERROR: nSolutions = %d \n", nSolutions);
        return 0;
    }
}

void sort_roots (double* x1, double* x2)
{

    GAssert(isfinite(*x1));
    GAssert(isfinite(*x2));

    if (*x1 > *x2)
    {
        double temp = 0;
        temp = *x1;
        *x1 = *x2;
        *x2 = temp;
    }
}

void failed_test (const double a, const double b, const double c, const int IDtest)
{

    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));

    printf("Failed test #%d of %d. Wrong answer.\n", IDtest, amount_Tests);
    printf("\n" "Test input: a = %lf, b = %lf, c = %lf" "\n", a, b, c);
}

