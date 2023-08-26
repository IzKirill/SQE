#pragma once

struct TestData
{
    double a, b, c;
    double x1, x2;
    Solutions nroots;
};

int SQEtest(int* n_of_tests);

void sort_roots (double* x1, double* x2);
