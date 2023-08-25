#ifndef __SQELIBR_H__
#define __SQELIBR_H__

#ifndef OFFASSERT
    #define GAssert(expression) MyAssert(expression, __LINE__, __FILE__)
#else
    #define GAssert(expression)
#endif

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>

#endif
