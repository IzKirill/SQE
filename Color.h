#ifndef __COLOR_H__
#define __COLOR_H__

#include <windows.h>
#include <stdio.h>

extern HANDLE console;

#define BLUE SetConsoleTextAttribute          (console, (0 << 4) | 1)
#define GREEN SetConsoleTextAttribute         (console, (0 << 4) | 2)
#define GOLYBOI SetConsoleTextAttribute       (console, (0 << 4) | 3)
#define RED SetConsoleTextAttribute           (console, (0 << 4) | 4)
#define PURPLE SetConsoleTextAttribute        (console, (0 << 4) | 5)
#define BROWN SetConsoleTextAttribute         (console, (0 << 4) | 6)
#define LIGHT_GREY SetConsoleTextAttribute    (console, (0 << 4) | 7)
#define DARK_GREY SetConsoleTextAttribute     (console, (0 << 4) | 8)
#define LIGHT_BLUE SetConsoleTextAttribute    (console, (0 << 4) | 9)
#define LIGHT_GREEN SetConsoleTextAttribute   (console, (0 << 4) | 10)
#define LIGHT_GOLYBOI SetConsoleTextAttribute (console, (0 << 4) | 11)
#define LIGHT_RED SetConsoleTextAttribute     (console, (0 << 4) | 12)
#define LIGHT_PURPLE SetConsoleTextAttribute  (console, (0 << 4) | 13)
#define YELLOW SetConsoleTextAttribute        (console, (0 << 4) | 14)
#define WHITE SetConsoleTextAttribute         (console, (0 << 4) | 15)

#define printf(args...) do {    printf(args);       \
                                WHITE;     }        \
                                while(0)            \

#endif
