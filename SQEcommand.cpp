#include "SQEsolver.h"
#include "SQEtest.h"
#include "SQEcommand.h"
#include "MyAssert.h"
#include "SQEchoice.h"
#include "SQEstdio.h"
#include "Color.h"
#include <stdio.h>
#include <math.h>


void test(char file[])
{
    int n_of_tests = 0;
    int nOK = SQEtest(&n_of_tests, file);

    LIGHT_GREEN;
    printf("[%d/%d] successfully completed tests.", nOK, n_of_tests);

    WHITE;
}

void square()
{
    BROWN;
    printf("\n" "Enter the coefficients of the quadratic equation(a, b, c):\n");

    WHITE;

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
    BROWN;
    printf("\n" "Enter the coefficients of the quadratic equation(a, b):\n");

    WHITE;

    double a = 0, b = 0;
    input_coef(&a, 1);
    input_coef(&b, 2);

    GAssert(isfinite(a));
    GAssert(isfinite(b));

    double x = 0;
    Solutions nSolutions = lin_solver(a, b, &x);

    output_solveQE(nSolutions, x, 0);
}

int main_menu()
{
    YELLOW;
    printf("\t\t" "Hello, enter the number:\n");

    LIGHT_BLUE;
    printf("1: Solve equation.\t");

    LIGHT_PURPLE;
    printf("2: test code.\t");

    RED;
    printf("3: quit" "\n");

    WHITE;

    switch (user_choice())
    {
    case(1):
        {
            YELLOW;
            printf("\t" " What type of equation do you want to solve?\n");

            LIGHT_GOLYBOI;
            printf("1: Linear.\t");

            LIGHT_GREY;
            printf("2: Square.\t");

            RED;
            printf("3: Back to menu.\t\n");

            WHITE;
            switch(user_choice())
            {
            case(1):
                {
                    linear();
                }
                break;
            case(2):
                {
                    square();
                }
                break;
            case(3):
                {
                    main_menu();
                }
                break;
            default:
                {
                    LIGHT_RED;
                    printf("ERROR: Inccorect value.");

                    WHITE;
                }
            }
        }
        break;

    case(2):
        {
            test("Tests.csv");
        }
        break;

    case(3):
        {
            return 0;
        }
        break;

    default:
        {
            LIGHT_RED;
            printf("ERROR: Inccorect value.");

            WHITE;
        }
    }
}

void help_menu()
{
    YELLOW;
    printf("--help \t\t     Gives the necessary information.\n");
    printf("--linear \t     Solve linear equation.\n");
    printf("--square \t     Solve square equation.\n");
    printf("--test \t\t     Testing solver square equation.\n");
    printf("--file name_of_file  Testing solver square equation with your tests.\n");

    WHITE;
}
