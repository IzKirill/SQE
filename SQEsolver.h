#pragma once

enum Solutions {ZERO = 0,
                ONE  = 1,
                TWO  = 2,
                INFINITELY = 3};

Solutions square_solver (const double a, const double b, const double c, double* root1, double* root2);
Solutions lin_solver (const double b, const double c, double* root1);


