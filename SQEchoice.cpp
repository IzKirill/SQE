#include "SQEchoice.h"
#include "MyAssert.h"
#include "Clear_Buffer.h"
#include <stdio.h>

void User_Choice (int* your_choice)
{
    while (1)
    {
        int ch = 0, error = 0;
        if (scanf("%d", your_choice) != 1)
        {
            clear_buf();
            printf("Please, write a number. \n");
            error++;
        }
        else if (*your_choice != 1 && *your_choice != 2 && *your_choice != 3)
        {
            clear_buf();
            printf("Make correct choice: 1, 2 or 3! \n");
            error++;
        }
        else
        {
            while((ch = getchar()) != '\n' && error == 0)
            {
                if (ch != ' ' && ch != '\n')
                {
                    printf("Input correct nubmer. For example, 4 or 5,25. \n");
                    error++;
                }
            }
        }
        if (error == 0)
            return;
    }
}
