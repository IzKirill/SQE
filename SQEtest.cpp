#include "SQEsolver.h"
#include "SQEtest.h"
#include "MyAssert.h"
#include "SQEcmpdoubles.h"
#include "SQEstdio.h"
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <windows.h>

HANDLE console_test = GetStdHandle(STD_OUTPUT_HANDLE);

static int test_n(const double a, const double b, const double c,
                  const double refx1, const double refx2,
                  Solutions refnroots, const int IDtest);
static int failed_test (const double a, const double b, const double c,
                        const int IDtest,
                        const double refx1, const double refx2, Solutions refnroots,
                        const double x1, const double x2, Solutions nroots);


int SQEtest(int* n_of_tests, char file[])
{
    double a = 0, b = 0, c = 0;
    double refx1 = 0, refx2 = 0;
    Solutions refnroots = ZERO;

    FILE *Tests = NULL;

    if ((Tests = fopen(file, "r")) == NULL)
    {
        SetConsoleTextAttribute(console_test, (0 << 4) | 12);
        printf("Cannot open file.\n");

        SetConsoleTextAttribute(console_test, (0 << 4) | 15);

        exit(1);
    }

    int nOK = 0;
    int Suc_Scan = fscanf(Tests,"%lf%lf%lf%lf%lf%d",
                     &a, &b, &c, &refx1, &refx2, &refnroots);

    while(Suc_Scan != EOF)
    {
        if(Suc_Scan != 6)
        {
            SetConsoleTextAttribute(console_test, (0 << 4) | 12);
            printf("Test failed: Incorrect input. ");

            SetConsoleTextAttribute(console_test, (0 << 4) | 15);

            exit(1);
        }

        nOK += test_n(a, b, c, refx1, refx2, refnroots, *n_of_tests+1);
        (*n_of_tests)++;

        Suc_Scan = fscanf(Tests,"%lf%lf%lf%lf%lf%d",
                     &a, &b, &c, &refx1, &refx2, &refnroots);
    }

    fclose(Tests);

    return nOK;
}

static int test_n(const double a, const double b, const double c,
                  const double refx1, const double refx2, Solutions refnroots,
                  const int IDtest)
{
    GAssert(IDtest > 0);
    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));

    double  x1 = 0, x2 = 0;
    Solutions nSolutions = square_solver(a, b, c, &x1, &x2);

    GAssert(isfinite(x1));
    GAssert(isfinite(x2));
    GAssert(refnroots == ZERO || refnroots == ONE ||
            refnroots == TWO  || refnroots == INFINITELY);

    switch (refnroots)
    {
    case(ZERO):
    case(INFINITELY)
        {
            if (nSolutions != refnroots)
            {
                return failed_test(a, b, c, IDtest,
                        refx1, refx2,refnroots,
                        x1, x2, nSolutions);
            }
            return 1;
        }
        break;

    case(ONE):
        {
            if(nSolutions != refnroots || cmp_doubles(x1, refx1))
            {
                return failed_test(a, b, c, IDtest,
                            refx1, refx2, refnroots,
                            x1, x2, nSolutions);
            }
            return 1;
        }
        break;

    case(TWO):
        {
            sort_roots(&x1, &x2);
            if (nSolutions != refnroots || cmp_doubles(x1, refx1) ||
                cmp_doubles(x2, refx2))
            {
                return failed_test(a, b, c, IDtest,
                            refx1, refx2,refnroots,
                            x1, x2, nSolutions);
            }
            return 1;
        }
        break;

    default:
        {
        SetConsoleTextAttribute(console_test, (0 << 4) | 12);
        printf("ERROR: nSolutions = %d \n", nSolutions);

        SetConsoleTextAttribute(console_test, (0 << 4) | 15);

        return 0;
        }
    }
}

void sort_roots (double* x1, double* x2)
{
    GAssert(isfinite(*x1));
    GAssert(isfinite(*x2));
    GAssert(x1 != NULL);
    GAssert(x2 != NULL);

    if (*x1 > *x2)
    {
        double temp = 0;
        temp = *x1;
        *x1 = *x2;
        *x2 = temp;
    }
}

static int failed_test (const double a, const double b, const double c,
                         const int IDtest,
                         const double refx1, const double refx2, Solutions refnroots,
                         const double x1, const double x2, Solutions nroots)
{
    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));
    GAssert(isfinite(x1));
    GAssert(isfinite(x2));
    GAssert(isfinite(refx1));
    GAssert(isfinite(refx2));

    SetConsoleTextAttribute(console_test, (0 << 4) | 12);
    printf("Failed test #%d. Wrong answer.\n", IDtest);

    SetConsoleTextAttribute(console_test, (0 << 4) | 6);
    printf("\n" "Test input: a = %lf, b = %lf, c = %lf" "\n", a, b, c);


    SetConsoleTextAttribute(console_test, (0 << 4) | 10);
    printf("\n" "Correct output:");

    output_solveQE(refnroots, refx1, refx2);

    SetConsoleTextAttribute(console_test, (0 << 4) | 13);
    printf("\n" "Your code output:");
    output_solveQE(nroots, x1, x2);

    SetConsoleTextAttribute(console_test, (0 << 4) | 15);

    return 0;
}

