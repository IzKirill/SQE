#ifndef __SQEPRFUN_H__
#define __SQEPRFUN_H__

void MyAssert(int expression, const int nline, const char file[]);

int SQEtest (void);
int test_n (TestData* ref);
void failed_test(const double a, const double b, const double c, const int number_test);

void sort_roots (double* x1, double* x2);
void clear_buf (void);

void User_Choice (int* your_choice);
void input_coef (double* coefficient);

cmp_double cmpz_doubles (const double double_number);
int cmp_doubles (const double double_number1, const double double_numbr2);
bool equal_zero(const double coefficient);

solutions square_solve (const double a, const double b, const double c, double* root1, double* root2);
solutions lin_solver (const double b, const double c, double* root1);

void output_solveQE (solutions nSolutions, const double root1, const double root2);

#endif
