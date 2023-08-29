#include "SQEchoice.h"
#include "MyAssert.h"
#include "Clear_Buffer.h"
#include "Color.h"
#include <stdio.h>

void user_choice (int* your_choice)
{
    GAssert(your_choice != NULL);
    begin:
    while (scanf("%d", your_choice) != 1 ||
          (*your_choice != 1 && *your_choice != 2 && *your_choice != 3) )
    {
        clear_buffer();
        LIGHT_RED;
        printf("Please, write a correct number: 1, 2 or 3! \n");

        WHITE;
    }
    if (status_buffer())
    {
        LIGHT_RED;
        printf("Input only number(1, 2 or 3) and only one!\n");

        WHITE;
        goto begin;
    }
}
