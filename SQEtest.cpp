#include "SQEsolver.h"
#include "SQEtest.h"
#include "MyAssert.h"
#include "SQEcmpdoubles.h"
#include "SQEstdio.h"
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

static const int ntests = 13;

static int test_n(TestData* ref, const int IDtest);
static void failed_test(const double a, const double b, const double c,
                        const int number_test);

int SQEtest(int* n_of_tests)
{
    *n_of_tests = ntests;
    static TestData TInputData[ntests];

    FILE *Tests;

    if ((Tests = fopen("Tests.csv", "r")) == NULL)
    {
        printf("Cannot open file.\n");
        exit(1);
    }

    for(int i = 0; fscanf(Tests,"%lf%lf%lf%lf%lf%d", &(TInputData[i].a),
    &(TInputData[i].b), &(TInputData[i].c), &(TInputData[i].x1), &(TInputData[i].x2),
    &(TInputData[i].nroots)) != EOF; i++)
        ;

    fclose(Tests);

    int nOK = 0;
    for (int i = 0; i < ntests; i++)
        nOK += test_n(&TInputData[i], i+1);

    return nOK;
}

static int test_n(TestData* ref, const int IDtest)
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

static void failed_test (const double a, const double b, const double c, const int IDtest)
{
    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));

    printf("Failed test #%d of %d. Wrong answer.\n", IDtest, ntests);
    printf("\n" "Test input: a = %lf, b = %lf, c = %lf" "\n", a, b, c);
}

