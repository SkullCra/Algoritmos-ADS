#include <stdio.h>

int main()
{
    int num[7];
    int maior, menor, posMaior, posMenor, soma = 0;
    float media;

    printf("Maior, menor e média de vetores.\n\n");

    for (int i = 0; i < 7; i++)
    {
        printf("Informe o %dº número: ", i + 1);
        scanf("%d", &num[i]);
    }
    maior = num[0];
    menor = num[0];

    for (int i = 0; i < 7; i++)
    {
        soma = soma + num[i];

        if (num[i] > maior)
        {
            maior = num[i];
        }
        if (num[i] < menor)
        {
            menor = num[i];
        }
    }
    media = soma / 7.0;
    printf("\n### RESULTADOS ###\n\n");
    printf("Números digitados:\n");
    for (int i = 0; i < 7; i++)
    {
        printf("[%d] ", num[i]);
    }
    printf("\n\nMenor valor: %d.\n", menor);
    printf("Maior valor: %d.\n", maior);
    printf("Média dos elementos: %.2f", media);
    return 0;
}