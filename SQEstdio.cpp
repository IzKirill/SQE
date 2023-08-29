#include "SQEsolver.h"
#include "SQEstdio.h"
#include "Clear_Buffer.h"
#include "MyAssert.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

HANDLE console_stdio = GetStdHandle(STD_OUTPUT_HANDLE);

void input_coef (double* coefficient, int n_coefficient)
{
    GAssert(coefficient != NULL);

    begin:
    SetConsoleTextAttribute(console_stdio, (0 << 4) | 13);
    printf("Coefficient number - %d: ", n_coefficient);

    SetConsoleTextAttribute(console_stdio, (0 << 4) | 15);

    while (scanf("%lf", coefficient) != 1)
    {
        clear_buffer();
        SetConsoleTextAttribute(console_stdio, (0 << 4) | 12);
        printf("Input number. For example, 4 or 5,25. \n");

        SetConsoleTextAttribute(console_stdio, (0 << 4) | 13);
        printf("Coefficient number - %d: ", n_coefficient);

        SetConsoleTextAttribute(console_stdio, (0 << 4) | 15);
    }
    if (status_buffer())
    {
        SetConsoleTextAttribute(console_stdio, (0 << 4) | 12);
        printf("Input only number and only one!\n");

        SetConsoleTextAttribute(console_stdio, (0 << 4) | 15);

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
        SetConsoleTextAttribute(console_stdio, (0 << 4) | 11);
        printf("Zero roots.\n");

        SetConsoleTextAttribute(console_stdio, (0 << 4) | 15);

        break;

    case(ONE):
        SetConsoleTextAttribute(console_stdio, (0 << 4) | 11);
        printf("One root %.5lf.\n", x1);

        SetConsoleTextAttribute(console_stdio, (0 << 4) | 15);

        break;

    case(TWO):
        SetConsoleTextAttribute(console_stdio, (0 << 4) | 11);
        printf("Two roots %.5lf and %.5lf.\n", x1, x2);

        SetConsoleTextAttribute(console_stdio, (0 << 4) | 15);

        break;

    case(INFINITELY):
        SetConsoleTextAttribute(console_stdio, (0 << 4) | 11);
        printf("Infinite roots.\n");

        SetConsoleTextAttribute(console_stdio, (0 << 4) | 15);
        break;

    default:
        SetConsoleTextAttribute(console_stdio, (0 << 4) | 12);
        printf("ERROR: nSolutions = %d", nSolutions);

        SetConsoleTextAttribute(console_stdio, (0 << 4) | 15);
    }
}
