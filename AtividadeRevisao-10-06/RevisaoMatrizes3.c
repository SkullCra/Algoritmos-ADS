#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int matriz[4][4];

    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (l + c == 3)
            {
                matriz[l][c] = 1;
            }
            else
            {
                matriz[l][c] = 0;
            }
        }
    }
    printf("\n### MATRIZ FINAL ###\n");
    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("[%d] ", matriz[l][c]);
        }
        printf("\n");
    }
    return 0;
}