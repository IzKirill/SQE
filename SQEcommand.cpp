#include "SQEsolver.h"
#include "SQEtest.h"
#include "SQEcommand.h"
#include "MyAssert.h"
#include "SQEchoice.h"
#include "SQEstdio.h"
#include "Color.h"
#include <stdio.h>
#include <math.h>

int main_menu()
{
    int n_menu = 1;
    while (1)
    {
        switch(n_menu)
        {
        case(1):
            {
                BROWN;
                printf("\n*-----------------------------------------------*\n");

                YELLOW;
                printf("\t\t" "Enter the number:\n");

                LIGHT_BLUE;
                printf("1: Solve equation.\t");

                LIGHT_PURPLE;
                printf("2: test code.\t");

                RED;
                printf("3: quit" "\n");
            }
            break;

        case(2):
            {
                YELLOW;
                printf("\t" " What type of equation do you want to solve?\n");

                LIGHT_GOLYBOI;
                printf("1: Linear.\t");

                LIGHT_GREY;
                printf("2: Square.\t");

                RED;
                printf("3: Back to menu.\t\n");
            }
            break;

        default:
            {
                LIGHT_RED;
                printf("ERROR: Inccorect value.");

                return 0;
            }
        }

        switch (user_choice())
        {
        case(1):
            {
                if(n_menu == 1)
                {
                    n_menu = 2;
                }
                else
                {
                    solve_linear();

                    n_menu = 1;
                }
            }
            break;

        case(2):
            {
                if(n_menu == 1)
                {
                    test(default_file);
                }
                else
                {
                    solve_square();

                    n_menu = 1;
                }
            }
            break;

        case(3):
            {
                if(n_menu == 1)
                {
                    return 0;
                }
                else
                {
                    n_menu = 1;
                }
            }
            break;

        default:
            {
                LIGHT_RED;
                printf("ERROR: Inccorect value.");

                return 0;
            }
        }
    }
    return 0;
}

void test(const char file[])
{
    GAssert(file != NULL);

    int n_of_tests = 0;
    int nOK = SQEtest(&n_of_tests, file);

    LIGHT_GREEN;
    printf("[%d/%d] successfully completed tests.\n", nOK, n_of_tests);
}

void solve_square()
{
    BROWN;
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

void solve_linear()
{
    BROWN;
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
    YELLOW;
    printf("--help \t\t     Gives the necessary information.\n"
           "--linear \t     Solve linear equation.\n"
           "--square \t     Solve square equation.\n"
           "--test \t\t     Testing solver square equation.\n"
           "--file name_of_file  Testing solver square equation with your tests.\n");
}
