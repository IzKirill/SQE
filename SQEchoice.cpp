#include "SQEchoice.h"
#include "MyAssert.h"
#include "Clear_Buffer.h"
#include "Color.h"
#include <stdio.h>

int user_choice ()
{
    int your_choice = 0, flag_exit = 1;

    while(flag_exit)
    {
        while (scanf("%d", &your_choice) != 1 ||
            (your_choice != 1 && your_choice != 2 && your_choice != 3))
        {
            ClearStatusBuffer();
            LIGHT_RED;
            printf("Please, write a correct number: 1, 2 or 3! \n");

            WHITE;
        }

        if (ClearStatusBuffer())
        {
            LIGHT_RED;
            printf("Input only number(1, 2 or 3) and only one!\n");

            WHITE;
        }
        else
        {
            flag_exit = 0;
        }
    }

    return your_choice;
}
