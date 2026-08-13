#include <stdio.h>

float media_elementos(int v[], int tamanho)
{
    float soma_elementos = 0;
    float media_elementos = 0;

    for (int i = 0; i < tamanho; i++) {
        soma_elementos = soma_elementos + v[i];
    }
    return media_elementos = soma_elementos / tamanho;
}

float media;

int main()
{
    int vetor[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %d valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    media = media_elementos(vetor, 10);
    printf("A média dos elementos é %.2f.\n", media);

    return 0;
}