#include "SQEsolver.h"
#include "SQEtest.h"
#include "MyAssert.h"
#include "SQEchoice.h"
#include "SQEstdio.h"
#include "SQEcommand.h"
#include <stdio.h>
#include <math.h>
#include <windows.h>

HANDLE console_command = GetStdHandle(STD_OUTPUT_HANDLE);

int main_menu()
{
    SetConsoleTextAttribute(console_command, (0 << 4) | 14);
    printf("\t\t" "Hello, enter the number:\n");

    SetConsoleTextAttribute(console_command, (0 << 4) | 1);
    printf("1: Solve quadratic equation.\t");

    SetConsoleTextAttribute(console_command, (0 << 4) | 5);
    printf("2: test code.\t");

    SetConsoleTextAttribute(console_command, (0 << 4) | 4);
    printf("3: quit" "\n");

    SetConsoleTextAttribute(console_command, (0 << 4) | 15);

    int your_choice = 0;
    User_Choice(&your_choice);

    GAssert(your_choice == 1 || your_choice == 2 ||
                your_choice == 3);

    if (your_choice == 2)
    {
        char default_file[] = "Tests.csv";
        test(default_file);
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

    SetConsoleTextAttribute(console_command, (0 << 4) | 2);
    printf("%d/%d successfully completed tests.", nOK, n_of_tests);

    SetConsoleTextAttribute(console_command, (0 << 4) | 15);
}

void square()
{
    SetConsoleTextAttribute(console_command, (0 << 4) | 6);
    printf("\n" "Enter the coefficients of the quadratic equation(a, b, c):\n");

    SetConsoleTextAttribute(console_command, (0 << 4) | 15);

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
