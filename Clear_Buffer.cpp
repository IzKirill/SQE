#pragma once

#include "Clear_Buffer.h"
#include <stdio.h>

void clear_buf()
{
    int ch = 0;
    while((ch = getchar()) != '\n')
        ;
}
