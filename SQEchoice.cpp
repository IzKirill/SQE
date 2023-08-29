#include "SQEchoice.h"
#include "MyAssert.h"
#include "Clear_Buffer.h"
#include <stdio.h>
#include <windows.h>

HANDLE console_choice = GetStdHandle(STD_OUTPUT_HANDLE);

void user_choice (int* your_choice)
{
    GAssert(your_choice != NULL);
    begin:
    while (scanf("%d", your_choice) != 1 ||
          (*your_choice != 1 && *your_choice != 2 && *your_choice != 3) )
    {
        clear_buffer();
        SetConsoleTextAttribute(console_choice, (0 << 4) | 12);
        printf("Please, write a correct number: 1, 2 or 3! \n");

        SetConsoleTextAttribute(console_choice, (0 << 4) | 15);
    }
    if (status_buffer())
    {
        SetConsoleTextAttribute(console_choice, (0 << 4) | 12);
        printf("Input only number(1, 2 or 3) and only one!\n");

        SetConsoleTextAttribute(console_choice, (0 << 4) | 15);
        goto begin;
    }
}
