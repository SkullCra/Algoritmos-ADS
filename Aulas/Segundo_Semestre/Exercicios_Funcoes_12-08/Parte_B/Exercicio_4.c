#include <stdio.h>

int pares_impares(int v[], int tamanho)
{
    int pares = 0, impares = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (v[i] % 2 == 0)
        {
            pares++;
        }
        else
            impares++;
    }
    printf("Quantidade de pares: %d.\n", pares);
    printf("Quantidade de ímpares: %d.\n", impares);
}

int main()
{
    int vetor[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %d valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    pares_impares(vetor, 10);

    return 0;
}