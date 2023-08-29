#ifndef __SQETEST_H__
#define __SQETEST_H__

struct TestData
{
    double a, b, c;
    double x1, x2;
    Solutions nroots;
};

int SQEtest(int* n_of_tests, char file[]);

void sort_roots (double* x1, double* x2);

#endif
