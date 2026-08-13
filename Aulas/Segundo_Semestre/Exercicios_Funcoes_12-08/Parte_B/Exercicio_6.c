#include <stdio.h>

int maior(int v[], int tamanho)
{
    int maior = v[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (maior < v[i])
        {
            maior = v[i];
        }
    }
    return maior;
}

int menor(int v[], int tamanho)
{
    int menor = v[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (menor > v[i])
        {
            menor = v[i];
        }
    }
    return menor;
}

float media_elementos(int v[], int tamanho)
{
    float soma_elementos = 0;
    float media_elementos = 0;

    for (int i = 0; i < tamanho; i++)
    {
        soma_elementos = soma_elementos + v[i];
    }
    return media_elementos = soma_elementos / tamanho;
}

int menor_num;
int maior_num;
float media_nums;

int main()
{
    int vetor[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Informe o %dº valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    menor_num = menor(vetor, 10);
    maior_num = maior(vetor, 10);
    media_nums = media_elementos(vetor, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("Posição %d: Vetor [%d].\n", i, vetor[i]);
    }
    printf("O menor número digitado foi %d.\n", menor_num);
    printf("O maior número digitado foi %d.\n", maior_num);
    printf("A média dos números é de %.2f.\n", media_nums);

    return 0;
}