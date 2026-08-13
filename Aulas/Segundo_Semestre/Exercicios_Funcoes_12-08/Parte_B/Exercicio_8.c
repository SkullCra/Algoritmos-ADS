#include <stdio.h>

int verifica_iguais(int v[], int tamanho, int numero)
{
    int flag = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (v[i] == numero)
        {
            printf("Posição %d = Número: %d.\n", i + 1, v[i]);
            flag++;
        }
    }
    if (flag = 0) {
        printf("O valor não foi encontrado!\n");
    }
}

int numero;

int main()
{
    int vetor[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Informe o valor da %dª posição: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("Informe um número que deseja que deseja verificar: ");
    scanf("%d", &numero);

    verifica_iguais(vetor, 10, numero);

    return 0;
}