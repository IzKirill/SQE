//Hello, this program solves a quadratic equation of the form: a*x^2 + b*x + c = 0;

#include <stdio.h>
#include <math.h>
#include <assert.h>

enum solutions{ ZERO = 0,                   // 0 roots
                ONE  = 1,                    // 1 roots
                TWO  = 2,                    // 2 roots
                INFINITELY = 3};            // infinity roots
enum cmp_double {DOUBLE_EQUALS_ZERO = 0,    // the nubmer = 0
                 DOUBLE_MORE_ZERO = 1,      // the nubmer > 0
                 DOUBLE_LESS_ZERO = 2};     // the nubmer < 0
const double EPS = 1e-9;                    // double precision

int test(void);
bool test1(void);
void clear_buf(void);
void input (double* coefficient);
cmp_double cmpz_doubles (const double double_nubmer);  // comparing a nubmer with zero
bool equalzero(const double coefficient);
solutions square_solve (const double a, const double b, const double c, double* root1, double* root2);
solutions lin_solver (const double b, const double c, double* x1);
void output (const int nSolutions, const double root1, const double root2);

int main()
{
    printf("\t\t" "Hello, enter the number:\n"
    "1: Solve quadratic equation." "\t"  "2: test code." "\t" "3: quit" "\n");
    int number = 0;
    scanf("%d", &number);
    if (number = 1)
    {
    printf("Enter the coefficients of the quadratic equation(a, b, c):\n");
    double a = 0, b = 0, c = 0;
    input(&a);
    input(&b);
    input(&c);

    double x1 = 0, x2 = 0;
    int nSolutions = square_solve(a, b, c, &x1, &x2);

    output(nSolutions, x1, x2);
    }
    return 0;
}

void clear_buf()
{
    char ch;
        while((ch = getchar()) != '\n')
            ;
}
void input (double* coefficient)
{
    while (scanf("%lf", coefficient) != 1)
    {
        clear_buf();
        printf("Input correct nubmer. \n");
    }
}

cmp_double cmpz_doubles (const double n)
{
    if (fabs(n) < EPS)
        return DOUBLE_EQUALS_ZERO;
    else if (n > EPS)
            return DOUBLE_MORE_ZERO;
         else
            return DOUBLE_LESS_ZERO;
}

bool equalzero(const double coefficient)
{
    return cmpz_doubles(coefficient) == DOUBLE_EQUALS_ZERO;
}

solutions square_solve (const double a,const double b,const double c, double* x1, double* x2)
{
    assert (x1!=x2);
    assert (x1!=nullptr);
    assert (x2!=nullptr);

    if (equalzero(a))
    {
      return lin_solver (b, c, x1);
    }
    else
    {
      if (equalzero(b))
      {
        if (equalzero(c))
        {
            *x1 = 0;
            return ONE;
        }
        else if (cmpz_doubles(c) == DOUBLE_MORE_ZERO)
        {
                return ZERO;
        }
        else
        {
                double root_of_c = sqrt(-c);
                *x1 = root_of_c;
                *x2 = -root_of_c;
                return TWO;
        }
       }
       else if (equalzero(c))
       {
            *x1 = 0;
            *x2 = -b/a;
            return TWO;
       }
       else
       {
            double D = b*b - 4*a*c;
            if (cmpz_doubles(D) == DOUBLE_LESS_ZERO)
            {
                return ZERO;
            }
            else if (equalzero(D))
            {
                *x1 = - b/(2*a);
                return ONE;
            }
            else
            {
                double root_of_disciminant = sqrt(D);
                *x1 = (-b + root_of_disciminant) / (2*a);
                *x2 = (-b - root_of_disciminant) / (2*a);
                return TWO;
            }
       }
    }
}

solutions lin_solver (const double b, const double c, double* x1)
{
    if (equalzero(b))
    {
        if (equalzero(c))
        {
            return ZERO;
        }
        else
        {
            return ZERO;
        }
    }
    else
    {
        *x1 = -c/b;
        return ONE;
    }
}

void output (const int nSolutions, const double x1, const double x2)
{
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
