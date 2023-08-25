#pragma once

enum solutions {ZERO = 0,
                ONE  = 1,
                TWO  = 2,
                INFINITELY = 3};

solutions square_solve (const double a, const double b, const double c, double* root1, double* root2);
solutions lin_solver (const double b, const double c, double* root1);


