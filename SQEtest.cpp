#include "SQEtest.h"

int SQEtest(void)
{
    static TestData TInputData[amount_Tests] =
    {{.a = 0,  .b = 0,    .c = 0,        .x1 = 0,       .x2 = 0,   .nroots = INFINITELY,.number_test = 1},
     {.a = 5,  .b = 0,    .c = 10,       .x1 = 0,       .x2 = 0,   .nroots = ZERO,      .number_test = 2},
     {.a = 0,  .b = 0,    .c = 15,       .x1 = 0,       .x2 = 0,   .nroots = ZERO,      .number_test = 3},
     {.a = 0,  .b = 10,   .c = 20,       .x1 = -2,      .x2 = 0,   .nroots = ONE,       .number_test = 4},
     {.a = -5, .b = 0,    .c = 0,        .x1 = 0,       .x2 = 0,   .nroots = ONE,       .number_test = 5},
     {.a = 5,  .b = 0,    .c = -125,     .x1 = -5,      .x2 = 5,   .nroots = TWO,       .number_test = 6},
     {.a = 10, .b = 10,   .c = 0,        .x1 = -1,      .x2 = 0,   .nroots = TWO,       .number_test = 7},
     {.a = 2,  .b = -1,   .c = 4,        .x1 = 0,       .x2 = 0,   .nroots = ZERO,      .number_test = 8},
     {.a = 1,  .b = 2,    .c = 1,        .x1 = -1,      .x2 = 0,   .nroots = ONE,       .number_test = 9},
     {.a = 1,  .b = -6,   .c = 5,        .x1 = 1,       .x2 = 5,   .nroots = TWO,       .number_test = 10},
     {.a = 4,  .b = 5,    .c = -9,       .x1 = -2.25,   .x2 = 1,   .nroots = TWO,       .number_test = 11},
     {.a = 1,  .b = -4,   .c = 3.75,     .x1 = 1.5,     .x2 = 2.5, .nroots = TWO,       .number_test = 12},
     {.a = 1,  .b = 7.25, .c = -24.375,  .x1 = -9.75,   .x2 = 2.5, .nroots = TWO,       .number_test = 13},
     {.a = 0,  .b = 1,    .c = -DBL_MAX, .x1 = DBL_MAX, .x2 = 0,   .nroots = ONE,       .number_test = 14},
     {.a = 0,  .b = 1,    .c = -DBL_MIN, .x1 = DBL_MIN, .x2 = 0,   .nroots = ONE,       .number_test = 15}};
    int nOK = 0;
    for (int i = 0; i < amount_Tests; i++, nOK++)
        test_n(&TInputData[i]);

    return nOK;
}

int test_n(TestData* ref)
{

    GAssert(isfinite(ref->a));
    GAssert(isfinite(ref->b));
    GAssert(isfinite(ref->c));
    GAssert(isfinite(ref->number_test));

    double  x1 = 0, x2 = 0;
    solutions nSolutions = square_solve(ref->a, ref->b, ref->c, &x1, &x2);

    GAssert(isfinite(x1));
    GAssert(isfinite(x2));
    GAssert(ref->nroots == ZERO || ref->nroots == ONE ||
            ref->nroots == TWO  || ref->nroots == INFINITELY);

    switch (ref->nroots)
    {
    case(ZERO):
        if (nSolutions != ref->nroots)
        {
            failed_test(ref->a, ref->b, ref->c, ref->number_test);
            printf("\n" "Correct output: nSolutions = ZERO" "\n");
            printf("\n" "Your code output: nSolutions = %d" "\n", nSolutions);
            return 0;
        }
        break;

    case(ONE):
        if(nSolutions != ref->nroots || cmp_doubles(x1, ref->x1))
        {
            failed_test(ref->a, ref->b, ref->c, ref->number_test);
            printf("\n" "Correct output: nSolutions = ONE, x1 = %lf" "\n", ref->x1);
            printf("\n" "Your code output: nSolutions = %d, x1 = %lf" "\n", nSolutions, x1);
            return 0;
        }
        break;

    case(TWO):
        sort_roots(&x1, &x2);
        if (nSolutions != ref->nroots || cmp_doubles(x1, ref->x1) || cmp_doubles(x2, ref->x2))
        {
            failed_test(ref->a, ref->b, ref->c, ref->number_test);
            printf("\n" "Correct output: nSolutions = ONE, x1 = %lf, x2 = %lf" "\n", ref->x1, ref->x2);
            printf("\n" "Your code output: nSolutions = %d, x1 = %lf, x2 = %lf" "\n", nSolutions, x1, x2);
            return 0;
        }
        break;

    case(INFINITELY):
        if (nSolutions != ref->nroots)
        {
            failed_test(ref->a, ref->b, ref->c, ref->number_test);
            printf("\n" "Correct output: nSolutions = INFINITELY" "\n");
            printf("\n" "Your code output: nSolutions = %d" "\n", nSolutions);
            return 0;
        }
        break;

    default:
        printf("ERROR: nSolutions = %d \n", nSolutions);
        return 0;
    }

    return 1;
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

void failed_test (const double a, const double b, const double c, const int number_test)
{

    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));
    GAssert(isfinite(number_test));

    printf("Failed test #%d of %d. Wrong answer.\n", number_test, amount_Tests);
    printf("\n" "Test input: a = %lf, b = %lf, c = %lf" "\n", a, b, c);
}

