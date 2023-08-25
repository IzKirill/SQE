#include "MyAssert.h"

void MyAssert(int expression, const int nline, const char file[])
{
    if(expression == 0)
    {
        printf("Error(: Line - %d, File(%s)\n", nline, file);
        exit(5);
    }
}
