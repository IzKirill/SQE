#include "Clear_Buffer.h"
#include <stdio.h>

void clear_buf()
{
    int ch = 0;
    while((ch = getchar()) != '\n')
        ;
}

int status_buffer()
{
    int ch = 0;
    while((ch = getchar()) != '\n')
    {
        if (ch != ' ' && ch != '\n')
            return 1;
    }
}
