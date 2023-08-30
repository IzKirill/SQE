#include "SQEcommand.h"
#include "Color.h"
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    if (argc == 1)
    {
        return main_menu();
    }

    else if (!strcmp(argv[1], "--test"))
    {
        test(default_file);
    }

    else if (!strcmp(argv[1], "--square"))
    {
        solve_square();
    }

    else if (!strcmp(argv[1], "--linear"))
    {
        solve_linear();
    }

    else if (!strcmp(argv[1], "--file"))
    {
        if (argc < 3)
        {
            LIGHT_RED;
            printf("Input name of your file after -file.");
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
    }
    return 0;
}
