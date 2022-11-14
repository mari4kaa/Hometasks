// lab1_6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
VOID WINAPI Sleep(DWORD dwMilliseconds);


int main()
{
    const int columns = 80;
    const int rows = 24;
    const int right = columns - 1;
    const int bottom = rows - 1;
    const int delay = 20;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD Pos;
    Pos.X = columns - 1;
    Pos.Y = 0;

    SetConsoleCursorPosition(hout, Pos);

    for (int p = 0; p < rows / 2; p++) {
        for (int i = p; i < bottom - p; i++)              //↓
        {
            Pos.Y = i;
            SetConsoleCursorPosition(hout, Pos);
            printf("#");
            Sleep(delay);
        }
        Pos.Y++;
        for (int j = right - p; j > p; j--)       // <-
        {
            Pos.X = j;
            SetConsoleCursorPosition(hout, Pos);
            printf("&");
            Sleep(delay);
        }
        Pos.X--;
        for (int i = bottom - p; i > p; i--)     //↑
        {
            Pos.Y = i;
            SetConsoleCursorPosition(hout, Pos);
            printf("5");
            Sleep(delay);
        }
        Pos.Y--;
        for (int j = p; j < right - p; j++)      // ->
        {
            Pos.X = j;
            SetConsoleCursorPosition(hout, Pos);
            printf("@");
            Sleep(delay);
        }
    }
    _getch();
}
