#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int matriz[3][3];

    printf("## Matriz 3x3 com 1 e 0 ##\n\n");
    printf("A matriz resultante é:\n");
    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (l != c)
            {
                matriz[l][c] = 0;
            }
            else
                matriz[l][c] = 1;
            printf("[%d] ", matriz[l][c]);
        }
        printf("\n");
    }
    
}