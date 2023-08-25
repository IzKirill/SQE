#include "SQEMAIN.h"

int main()
{
    printf("\t\t" "Hello, enter the number:\n"
           "1: Solve quadratic equation.\t"
           "2: test code." "\t" "3: quit" "\n");

    int your_choice = 0;
    User_Choice(&your_choice);

    GAssert(your_choice == 1 || your_choice == 2 || your_choice == 3);
    GAssert(isfinite(your_choice));


    if (your_choice == 2)
    {
        int nOK = SQEtest();
        printf("%d/%d successfully completed tests.", nOK, amount_Tests);
    }

    if (your_choice == 1)
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
        solutions nSolutions = square_solve(a, b, c, &x1, &x2);

        GAssert(isfinite(nSolutions));

        output_solveQE(nSolutions, x1, x2);
    }

    if (your_choice == 3)
    {
        return 0;
    }

    return 0;
}
