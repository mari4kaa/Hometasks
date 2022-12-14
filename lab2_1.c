#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define rows 8
#define columns 5

int main()
{
    float X;
    int flag = 0;
    float arr[rows][columns] = { {1, 2, 3, 4, 0},
                               {1, 2, 3, 4, 3},
                               {5, 6, 7, 8, 10},
                               {5, 6, 7, 8, 10},
                               {5, 6, 7, 8, 10},
                               {6, 6, 7, 9, 11},
                               {6, 6, 8, 9, 12},
                               {8, 8, 9, 305, 13}};

    printf("Your matrix: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%4.f", arr[i][j]);
        }
        printf("\n");
    }

    printf("Input your X: ");
    scanf_s("%f", &X);

    for(int i = 0; i < columns; i++) 
    {
        int top = 0;
        int bottom = rows;
        for (int k = 0; k <= rows/2; k++)
        {
            int m = (top + bottom)/2;
            if (arr[m][i] > X)
            {
                bottom = m - 1;
            }
            else if (arr[m][i] < X)
            {
                top = m + 1;
            }
            else
            {
                printf("Coordinats of X (%d, %d)\n", m + 1, i + 1);
                flag = 10;
                break;
            }
        }
        if (flag == 10)
        {
            break;
        }
    }
    if (flag != 10)
    {
        printf("There is no such X in matrix\n");
    }
}

