#include "MyAssert.h"
#include <stdio.h>
#include <stdlib.h>

void MyAssert(int expression, const int nline, const char file[], const char func[])
{
    if(expression == 0)
    {
        printf("Error(: Line - %d, File(%s), Function - %s\n", nline, file, func);
        exit(5);
    }
}
