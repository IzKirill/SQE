#pragma once

const double EPS = 1e-9;

enum cmp_double {DOUBLE_EQUALS_ZERO = 0,
                 DOUBLE_MORE_ZERO = 1,
                 DOUBLE_LESS_ZERO = 2};

cmp_double cmpz_doubles (const double double_number);
int cmp_doubles (const double double_number1, const double double_numbr2);
bool equal_zero(const double coefficient);



