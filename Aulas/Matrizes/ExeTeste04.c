#include <stdio.h>
#include <string.h>

int main()
{
    int matrizA[3][3], matrizB[3][3], matrizSoma[3][3];

    printf("Informe os valores da matriz A 3x3: \n\n");

    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("Informe o elemento [%d][%d]: ", l + 1, c + 1);
            scanf("%d", &matrizA[l][c]);
        }
    }

    printf("Informe os valores da matriz B 3x3: \n\n");
    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("Informe o elemento [%d][%d]: ", l + 1, c + 1);
            scanf("%d", &matrizB[l][c]);
        }
    }

    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            matrizSoma[l][c] = matrizA[l][c] + matrizB[l][c];
        }
    }
    printf("A matriz resultante da soma de A e B foi:\n\n");
    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("[%d]", matrizSoma[l][c]);
        }
        printf("\n");
    }
    return 0;
}