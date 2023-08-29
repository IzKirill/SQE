#include "MyAssert.h"
#include "Color.h"
#include <stdio.h>
#include <stdlib.h>

void MyAssert(int expression, const int nline, const char file[], const char func[])
{
    if(expression == 0)
    {
        LIGHT_RED;
        printf("%s:%d: error in function %s.", file, nline, func);

        WHITE;

        exit(3);
    }
}
