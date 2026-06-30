#include <stdio.h>
#include <string.h>

int main()
{
    int matriz[5][5];

    printf("Informe os valores da matriz identidade 5x5\n");

    for (int l = 0; l < 5; l++)
    {
        for (int c = 0; c < 5; l++)
        {
            if (l==c)
                matriz[l][c]=1;
            
            else
                matriz[l][c]=0;
        }
    }
    for (int l = 0; l < 5; l++)
    {
        for (int c = 0; c < 5; c++)
        {
            printf("[%d] ", matriz[l][c]);
        }
    }
}