#include <stdio.h>

int verifica_iguais(int v[], int tamanho)
{
    int contador = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int l = 0; l < i; l++)
        {
            if (v[i] == v[l])
            {
                printf("Posição %d | Posição %d = Número: %d.\n", i + 1, l + 1, v[i]);
                contador++;
            }
        }
    }

    if (contador == 0)
    {
        printf("\nNão houve valores repetidos!\n");
    }
    else
    {
        printf("A quantidade de números repetidos é de %d.\n", contador);
    }
}

int main()
{
    int vetor[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Informe o valor da %dª posição: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    verifica_iguais(vetor, 10);

    return 0;
}