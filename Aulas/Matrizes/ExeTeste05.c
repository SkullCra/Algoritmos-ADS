#include <stdio.h>
#include <string.h>

int main()
{
    float notas[5][4], matrizSoma[5][4];

    printf("Calculo de médias com matriz:\n\n");
    for (int l = 0; l < 5; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("Informe a %dº nota do %dº estudante: ", c + 1, l + 1);
            scanf("%f", &notas[l][c]);
        }
        notas[l][3] = ((notas[l][0] + notas[l][1] + notas[l][2]) / 3);
    }
    printf("\nAs notas e médias calculadas foram:\n\n");
    for (int l = 0; l < 5; l++)
    {
        printf("Aluno %d: ", l + 1);
        printf("\nNota 1\tNota 2\tNota 3\tMédia\n");
        for (int c = 0; c < 4; c++)
        {
            printf("[%.2f]\t ", notas[l][c]);
        }
        printf("\n");
    }
    return 0;
}