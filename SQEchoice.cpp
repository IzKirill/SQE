#include "SQEchoice.h"
#include "MyAssert.h"
#include "Clear_Buffer.h"
#include <stdio.h>

void User_Choice (int* your_choice)
{
    GAssert(your_choice != NULL);
    begin:
    while (scanf("%d", your_choice) != 1 ||
          (*your_choice != 1 && *your_choice != 2 && *your_choice != 3) )
    {
        status_buffer();
        printf("Please, write a correct number: 1, 2 or 3! \n");
    }
    if (status_buffer())
    {
        printf("Input only number and only one!\n");
        goto begin;
    }
}
