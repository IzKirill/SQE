#include "SQEsolver.h"
#include "SQEstdio.h"
#include "Clear_Buffer.h"
#include "MyAssert.h"
#include "Color.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_coef (double* coefficient, int n_coefficient)
{
    GAssert(coefficient != NULL);

    begin:
    LIGHT_PURPLE;
    printf("Coefficient number - %d: ", n_coefficient);

    WHITE;

    while (scanf("%lf", coefficient) != 1)
    {
        clear_buffer();
        LIGHT_RED;
        printf("Input number. For example, 4 or 5,25. \n");

        LIGHT_PURPLE;
        printf("Coefficient number - %d: ", n_coefficient);

        WHITE;
    }
    if (status_buffer())
    {                                                                  // ����
        LIGHT_RED;
        printf("Input only number and only one!\n");

        WHITE;

        goto begin;
    }
}

void output_solveQE (Solutions nSolutions, const double x1, const double x2)
{
    GAssert(isfinite(x1));
    GAssert(isfinite(x2));
    GAssert(nSolutions == ZERO || nSolutions == ONE ||
            nSolutions == TWO || nSolutions == INFINITELY);

    switch (nSolutions)
    {
    case(ZERO):
        {
            LIGHT_GOLYBOI;
            printf("Zero roots.\n");

            WHITE;
        }
        break;

    case(ONE):
        {
            LIGHT_GOLYBOI;
            printf("One root %.5lf.\n", x1);

            WHITE;
        }
        break;

    case(TWO):
        {
            LIGHT_GOLYBOI;
            printf("Two roots %.5lf and %.5lf.\n", x1, x2);

            WHITE;
        }
        break;

    case(INFINITELY):
        {
            LIGHT_GOLYBOI;
            printf("Infinite roots.\n");

            WHITE;
        }
        break;

    default:
        {
            LIGHT_RED;
            printf("ERROR: nSolutions = %d", nSolutions);

            WHITE;
        }
    }
}
