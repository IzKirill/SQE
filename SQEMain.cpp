#include "SQEcommand.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

HANDLE console_main = GetStdHandle(STD_OUTPUT_HANDLE);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        return main_menu();
    }

    else if (!strcmp(argv[1], "-test"))
    {
        test("Tests.csv");
    }

    else if (!strcmp(argv[1], "-square"))
    {
        square();
    }

    else if (!strcmp(argv[1], "-linear"))
    {
        linear();
    }

    else if (!strcmp(argv[1], "-file"))
    {
        if (argc < 3)
        {
            SetConsoleTextAttribute(console_main, (0 << 4) | 12);
            printf("Input name of your file after -file.");

            SetConsoleTextAttribute(console_main, (0 << 4) | 15);
        }
        else
        {
            test(argv[2]);
        }
    }

    else if (!strcmp(argv[1], "-help"))
    {
        help_menu();
    }
    else
    {
        SetConsoleTextAttribute(console_main, (0 << 4) | 12);
        printf("Unknown command, write -help.\n");

        SetConsoleTextAttribute(console_main, (0 << 4) | 15);
    }
    return 0;
}
