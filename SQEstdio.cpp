#include "SQEstdio.h"

void clear_buf()
{
    int ch = 0;
    while((ch = getchar()) != '\n')
        ;
}

void input_coef (double* coefficient)
{
    while (scanf("%lf", coefficient) != 1)
    {
        clear_buf();
        printf("Input correct nubmer. For example, 4 or 5,25. \n");
    }
}

void output_solveQE (solutions nSolutions, const double x1, const double x2)
{

    GAssert(isfinite(x1));
    GAssert(isfinite(x2));
    GAssert(isfinite(nSolutions));
    GAssert(nSolutions == ZERO || nSolutions == ONE ||
            nSolutions == TWO || nSolutions == INFINITELY);

    switch (nSolutions)
    {
    case(ZERO):
        printf("Zero roots.\n");
        break;
    case(ONE):
        printf("One root %.5lf.\n", x1);
        break;
    case(TWO):
        printf("Two roots %.5lf and %.5lf.\n", x1, x2);
        break;
    case(INFINITELY):
        printf("Infinite roots.\n");
        break;
    default:
        printf("ERROR: nSolutions = %d", nSolutions);
    }
}
