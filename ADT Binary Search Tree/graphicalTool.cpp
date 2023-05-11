#include <iostream>
#include<stdio.h>
#include<windows.h>
#include "graphicalTool.h"
using namespace std;

void graphicalTool::goToXY(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(h,c);
}

int graphicalTool::getY()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int y;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        y = csbi.dwCursorPosition.Y;
    }
    return y;
}

