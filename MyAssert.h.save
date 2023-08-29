#ifndef __MYASSERT_H__
#define __MYASSERT_H__

#ifndef OFFASSERT
    #define GAssert(expression) MyAssert(expression, __LINE__, __FILE__, __FUNCTION__)
#else
    #define GAssert(expression)
#endif

void MyAssert(int expression, const int nline, const char file[], const char func[]);

#endif
