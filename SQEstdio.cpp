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

    LIGHT_PURPLE;
    printf("Coefficient number - %d: ", n_coefficient);

    int flag_exit = 1;
    while(flag_exit)
    {
        while (scanf("%lf", coefficient) != 1)
        {
            ClearStatusBuffer();
            LIGHT_RED;
            printf("Input number. For example, 4 or 5,25. \n");

            LIGHT_PURPLE;
            printf("Coefficient number - %d: ", n_coefficient);
        }

        if (ClearStatusBuffer())
        {
            LIGHT_RED;
            printf("Input only number and only one!\n");

            LIGHT_PURPLE;
            printf("Coefficient number - %d: ", n_coefficient);
        }
        else
        {
            flag_exit = 0;
        }
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
        }
        break;

    case(ONE):
        {
            LIGHT_GOLYBOI;
            printf("One root %.5lf.\n", x1);
        }
        break;

    case(TWO):
        {
            LIGHT_GOLYBOI;
            printf("Two roots %.5lf and %.5lf.\n", x1, x2);
        }
        break;

    case(INFINITELY):
        {
            LIGHT_GOLYBOI;
            printf("Infinite roots.\n");
        }
        break;

    default:
        {
            LIGHT_RED;
            printf("ERROR: nSolutions = %d", nSolutions);
        }
    }
}
