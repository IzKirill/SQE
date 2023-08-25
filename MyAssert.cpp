#include "MyAssert.h"
#include <stdio.h>
#include <stdlib.h>

void MyAssert(int expression, const int nline, const char file[], const char func[])
{
    if(expression == 0)
    {
        printf("%s:%d: error in function %s.", file, nline, func);
        exit(5);
    }
}
