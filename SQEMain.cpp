#include "SQEcommand.h"
#include "Color.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        return main_menu();
    }

    else if (!strcmp(argv[1], "--test"))
    {
        test("Tests.csv");
    }

    else if (!strcmp(argv[1], "--square"))
    {
        square();
    }

    else if (!strcmp(argv[1], "--linear"))
    {
        linear();
    }

    else if (!strcmp(argv[1], "--file"))
    {
        if (argc < 3)
        {
            LIGHT_RED;
            printf("Input name of your file after -file.");

            WHITE;
        }
        else
        {
            test(argv[2]);
        }
    }

    else if (!strcmp(argv[1], "--help"))
    {
        help_menu();
    }

    else
    {
        LIGHT_RED;
        printf("Unknown command, write --help.\n");

        WHITE;
    }
    return 0;
}
