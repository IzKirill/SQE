#pragma once

#ifndef OFFASSERT
    #define GAssert(expression) MyAssert(expression, __LINE__, __FILE__)
#else
    #define GAssert(expression)
#endif

void MyAssert(int expression, const int nline, const char file[]);

