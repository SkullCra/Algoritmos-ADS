#include <stdio.h>
#include <string.h>

int main()
{
    int matriz[4][4];
    int l, c, somaMatriz = 0;

    printf("Informe os valores da matriz 4x4 para soma\n\n");

    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("Informe o elemento [%d][%d]:", l + 1, c + 1);
            scanf("%d", &matriz[l][c]);
        }
    }

    printf("\nA matriz informada foi:\n\n");
    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("[%d]", matriz[l][c]);
        }
        printf("\n");
    }
    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            somaMatriz += matriz[l][c];
        }
    }
    printf("\nA soma dos elementos da matriz informada é %d.\n\n", somaMatriz);
    return 0;
}