#include <stdio.h>
#include <string.h>

int main()
{
    int matriz[4][4], maiores = 0;

    printf("## Verificador de valores maiores que 10 ##\n");
    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("Informe o valor do elemento [%d][%d]: ", l + 1, c + 1);
            scanf("%d", &matriz[l][c]);
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
    printf("\nOs valores maiores que 10 são:\n");
    for (int l = 0; l < 4; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (matriz[l][c] > 10)
            {
                maiores = maiores + 1;
                printf("[%d]", matriz[l][c]);
            }
        }
    }
    printf("\n\nA quantidade de números maiores que 10 é de %d.\n", maiores);
    return 0;
}