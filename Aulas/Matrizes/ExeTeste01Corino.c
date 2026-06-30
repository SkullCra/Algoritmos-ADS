#include <stdio.h>
#include <string.h>

int main()
{
    int matriz[3][3];
    int l, c;

    printf("Informe os valores da matriz 3x3\n\n");

    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("Informe o elemento [%d][%d]:", l + 1, c + 1);
            scanf("%d", &matriz[l][c]);
        }
    }

    printf("\nA matriz informada foi:\n\n");
    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("[%d]:", matriz[l][c]);
        }
        printf("\n");
    }
    return 0;
}