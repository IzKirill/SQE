#include "SQEchoice.h"
#include "MyAssert.h"
#include "Clear_Buffer.h"
#include <stdio.h>

void User_Choice (int* your_choice)
{
    int OK = 0;
    while (scanf("%d", your_choice) != 1 || status_buffer() ||
          (*your_choice != 1 && *your_choice != 2 && *your_choice != 3) )
    {
        clear_buf();
        printf("Please, write a correct number: 1, 2 or 3! \n");
    }
}
