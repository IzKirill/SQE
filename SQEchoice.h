#ifndef __SQECMPDOUBLES_H__
#define __SQECMPDOUBLES_H__

#ifndef OFFASSERT
    #define GAssert(expression) MyAssert(expression, __LINE__, __FILE__)
#else
    #define GAssert(expression)
#endif

#include <stdio.h>

void clear_buf (void);

void User_Choice (int* your_choice);

void MyAssert(int expression, const int nline, const char file[]);

#endif
