#include "MyAssert.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HANDLE console_assert = GetStdHandle(STD_OUTPUT_HANDLE);

void MyAssert(int expression, const int nline, const char file[], const char func[])
{
    if(expression == 0)
    {
        SetConsoleTextAttribute(console_assert, (0 << 4) | 12);
        printf("%s:%d: error in function %s.", file, nline, func);

        SetConsoleTextAttribute(console_assert, (0 << 4) | 12);

        exit(5);
    }
}
