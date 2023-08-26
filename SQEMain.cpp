#include "SQEsolver.h"
#include "SQEtest.h"
#include "MyAssert.h"
#include "SQEchoice.h"
#include "SQEstdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("\t\t" "Hello, enter the number:\n"
           "1: Solve quadratic equation.\t"
           "2: test code." "\t" "3: quit" "\n");

    int your_choice = 0;
    User_Choice(&your_choice);

    GAssert(your_choice == 1 || your_choice == 2 ||
            your_choice == 3);

    if (your_choice == 2)
    {
        int n_of_tests = 0;
        int nOK = SQEtest(&n_of_tests);
        printf("%d/%d successfully completed tests.", nOK, n_of_tests);
    }

    else if (your_choice == 1)
    {
        printf("\n" "Enter the coefficients of the quadratic equation(a, b, c):\n");
        double a = 0, b = 0, c = 0;
        input_coef(&a);
        input_coef(&b);
        input_coef(&c);

        GAssert(isfinite(a));
        GAssert(isfinite(b));
        GAssert(isfinite(c));

        double x1 = 0, x2 = 0;
        Solutions nSolutions = square_solver(a, b, c, &x1, &x2);

        output_solveQE(nSolutions, x1, x2);
    }

    else if (your_choice == 3)
    {
        return 0;
    }

    return 0;
}
