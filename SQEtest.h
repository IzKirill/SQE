#pragma once

struct TestData
{
    double a, b, c;
    double x1, x2;
    Solutions nroots;
};

int SQEtest(int* n_of_tests);
int test_n(TestData* ref, const int IDtest);
void failed_test(const double a, const double b, const double c, const int number_test);

void sort_roots (double* x1, double* x2);
