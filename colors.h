#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

enum Colors {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARKGREY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

void setColor(int);

#endif // COLORS_H_INCLUDED
