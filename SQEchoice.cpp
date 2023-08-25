#include "SQEchoice.h"
#include "MyAssert.h"
#include "Clear_Buffer.h"
#include <stdio.h>

void User_Choice (int* your_choice)
{
    int OK = 1;
    while (OK)
    {
        if (scanf("%d", your_choice) != 1)
        {
            clear_buf();
            printf("Please, write a number. \n");
        }
        else if (*your_choice != 1 && *your_choice != 2 && *your_choice != 3)
        {
            GAssert(*your_choice == 1 || *your_choice != 2 || *your_choice != 3);

            clear_buf();
            printf("Make correct choice: 1, 2 or 3! \n");
        }
        else
        {
            OK = 0;
        }
    }
}
