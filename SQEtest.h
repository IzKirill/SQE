#pragma once


struct TestData
{
    double a, b, c;
    double x1, x2;
    solutions nroots;
    int number_test;
};

const int amount_Tests = 15;

int SQEtest (void);
int test_n (TestData* ref);
void failed_test(const double a, const double b, const double c, const int number_test);

void sort_roots (double* x1, double* x2);
