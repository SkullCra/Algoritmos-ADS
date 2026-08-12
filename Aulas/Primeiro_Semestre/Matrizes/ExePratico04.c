#include <stdio.h>
#include <string.h>

int main()
{
    int matriz[4][4], maior = 0, linMaior, colMaior;

    printf("### Verificador de posições de matrizes ###\n");
    printf("Informe uma matriz de 4 posições\n");

    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("Informe o valor do elemento [%d][%d]: ", l, c);
            scanf("%d", &matriz[l][c]);
            if (matriz[l][c] > maior)
            {
                maior = matriz[l][c];
                linMaior = l;
                colMaior = c;
            }
        }
    }
    printf("\nA matriz informada foi:\n");
    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("[%d]", matriz[l][c]);
        }
        printf("\n");
    }
    printf("\nO maior valor da matriz é %d na posição [%d][%d].\n\n", maior, linMaior, colMaior);
}