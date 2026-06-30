#include <stdio.h>
#include <string.h>

int main()
{
    int matriz[3][3], valor, encontrou = 0, linValor, colValor;

    printf("### Buscador de valores em matrizes ###\n\n");
    printf("Informe os valores de uma matriz 3x3\n");

    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("Informe o valor do elemento [%d][%d]: ", l, c);
            scanf("%d", &matriz[l][c]);
        }
    }
    printf("Informe o valor que deseja encontrar na matriz: ");
    scanf("%d", &valor);

    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (valor == matriz[l][c])
            {
                linValor = l;
                colValor = c;
                encontrou = 1;
                printf("O valor %d foi encontrado na linha %d, coluna %d.\n", valor, linValor, colValor);
            }
        }
    }
    if (encontrou != 1)
    {
        printf("Valor não encontrado.\n\n");
    }
    return 0;
}