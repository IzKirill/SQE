#include "SQEsolver.h"
#include "SQEtest.h"
#include "MyAssert.h"
#include "SQEchoice.h"
#include "SQEstdio.h"
#include "SQEcommand.h"
#include <stdio.h>
#include <math.h>

int main_menu()
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
        test("Tests.csv");
    }

    else if (your_choice == 1)
    {
        square();
    }

    else if (your_choice == 3)
    {
        return 0;
    }
}

void test(char file[])
{
    int n_of_tests = 0;
    int nOK = SQEtest(&n_of_tests, file);
    printf("%d/%d successfully completed tests.", nOK, n_of_tests);
}

void square()
{
    printf("\n" "Enter the coefficients of the quadratic equation(a, b, c):\n");
    double a = 0, b = 0, c = 0;
    input_coef(&a, 1);
    input_coef(&b, 2);
    input_coef(&c, 3);

    GAssert(isfinite(a));
    GAssert(isfinite(b));
    GAssert(isfinite(c));

    double x1 = 0, x2 = 0;
    Solutions nSolutions = square_solver(a, b, c, &x1, &x2);

    output_solveQE(nSolutions, x1, x2);
}

void linear()
{
    printf("\n" "Enter the coefficients of the quadratic equation(a, b):\n");
    double a = 0, b = 0;
    input_coef(&a, 1);
    input_coef(&b, 2);

    GAssert(isfinite(a));
    GAssert(isfinite(b));

    double x = 0;
    Solutions nSolutions = lin_solver(a, b, &x);

    output_solveQE(nSolutions, x, 0);
}

void help_menu()
{
    printf("-help \t\t     Gives the necessary information.\n");
    printf("-linear \t     Solve linear equation.\n");
    printf("-square \t     Solve square equation.\n");
    printf("-test \t\t     Testing solver square equation.\n");
    printf("-file name_of_file   Testing solver square equation with your tests.\n");
}
