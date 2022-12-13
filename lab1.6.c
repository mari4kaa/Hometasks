#include "stdafx.h"
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

int minimum(int, int);

int main()
{
    _getch();
    int columns, rows;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hout, &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top;

    int right = columns - 1;
    int bottom = rows - 1;
    int delay = 20;
    int min = minimum(columns, rows);

    COORD Pos;
    Pos.X = columns - 1;
    Pos.Y = 0;

    SetConsoleCursorPosition(hout, Pos);

    for (int p = 0; p < min/2; p++) {
        for (int i = p; i < bottom - p; i++)              //↓
        {
            Pos.Y = i;
            SetConsoleCursorPosition(hout, Pos);
            SetConsoleTextAttribute(hout, FOREGROUND_GREEN);
            printf("#");
            Sleep(delay);
        }
        Pos.Y++;
        for (int j = right - p; j > p; j--)       // <-
        {
            Pos.X = j;
            SetConsoleCursorPosition(hout, Pos);
            SetConsoleTextAttribute(hout, FOREGROUND_BLUE);
            printf("#");
            Sleep(delay);
        }
        Pos.X--;
        for (int i = bottom - p; i > p; i--)     //↑
        {
            Pos.Y = i;
            SetConsoleCursorPosition(hout, Pos);
            SetConsoleTextAttribute(hout, FOREGROUND_GREEN);
            printf("#");
            Sleep(delay);
        }
        Pos.Y--;
        for (int j = p; j < right - p; j++)      // ->
        {
            Pos.X = j;
            SetConsoleCursorPosition(hout, Pos);
            SetConsoleTextAttribute(hout, FOREGROUND_BLUE);
            printf("#");
            Sleep(delay);
        }
    }
    if (min % 2 != 0)
    {
        if (min == columns)
        {
            for (int i = Pos.Y; i <= bottom - min / 2; i++)
            {
                Pos.Y = i;
                SetConsoleCursorPosition(hout, Pos);
                SetConsoleTextAttribute(hout, FOREGROUND_GREEN);
                printf("#");
                Sleep(delay);
            }
        }
        else
        {
            Pos.Y++;
            for (int j = right - min/2; j >= min/2; j--)
            {
                Pos.X = j;
                SetConsoleCursorPosition(hout, Pos);
                SetConsoleTextAttribute(hout, FOREGROUND_GREEN);
                printf("#");
                Sleep(delay);
            }

        }
    }
    _getch();
}

int minimum(int one, int two)
{
    if (one > two) return two;
    else return one;
}
