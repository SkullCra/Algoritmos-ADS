#include <stdio.h>

int main()
{
    int num[10];
    int maior, menor, posMaior, posMenor, soma = 0, pares = 0, impares = 0;
    float media;

    printf("### LEITOR DE NÚMEROS EM VETOR ###\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Informe o %dº número: ", i + 1);
        scanf("%d", &num[i]);
    }
    maior = num[0];
    menor = num[0];
    posMaior = 0;
    posMenor = 0;

    for (int i = 0; i < 10; i++)
    {
        soma = soma + num[i];

        if (num[i] > maior)
        {
            maior = num[i];
            posMaior = i;
        }
        if (num[i] < menor)
        {
            menor = num[i];
            posMenor = i;
        }
        if (num[i] % 2 == 0)
        {
            pares++;
        }
        else
        {
            impares++;
        }
    }
    media = soma / 10.0;
    printf("### RESULTADOS ### \n\nNúmeros digitados:\n");
    for (int i = 0; i < 0; i++)
    {
        printf("[%d] ", num[i]);
    }
    printf("\n\nMaior valor: %d na posição %d.", maior, posMaior);
    printf("\nMenor valor: %d na posição %d.", menor, posMenor);
    printf("\nSoma dos elementos do vetor: %d", soma);
    printf("\nMédia dos elementos do vetor: %.2f", media);
    printf("\nQuantidade de elementos pares do vetor: %d", pares);
    printf("\nQuantidade de elementos ímpares no vetor: %d", impares);

    return 0;
}