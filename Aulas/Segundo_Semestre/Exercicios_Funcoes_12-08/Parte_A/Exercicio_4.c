#include <stdio.h>

void exibir_tabuada(int numero)
{
    printf("Tabuada do %d:\n", numero);
    printf("-------------\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
    printf("\n");
}

int numero_desejado;

int main()
{
    printf("Exercício 4 de funções!\n");
    printf("Funções sem retorno!\n");
    printf("Tabuada!\n\n");
    printf("Informe um número para exibir a tabuada: ");
    scanf("%d", &numero_desejado);
    printf("Calculando a tabuada do %d...\n", numero_desejado);
    exibir_tabuada(numero_desejado);
    return 0;
}