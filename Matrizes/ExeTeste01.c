#include <stdio.h>
#include <string.h>

int main()
{
    int matriz[3][3];
    int l, c;

    for (l = 0; l < matriz[l]; l++)
    {
        printf("Informe o valor da %d linha:\n", l + 1);
        for (c = 0; matriz[c]; c++)
        {
            printf("Informe o valor da %d coluna:\n", l + 1);
            scanf("%d", &matriz[l][c]);
        }
    }

    for (l = 0; l < matriz[l]; l++)
    {
        printf("A linha informada foi: %d linha:\n", l + 1);
        for (c = 0; matriz[c]; c++)
        {
            printf("A coluna informada foi: %d coluna:\n", l + 1);
        }
        printf("\n");
    }

    return 0;
}