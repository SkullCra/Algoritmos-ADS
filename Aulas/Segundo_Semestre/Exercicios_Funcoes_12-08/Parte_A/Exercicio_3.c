#include <stdio.h>

void classificar_numero(int numero)
{
    if (numero < 0)
    {
        printf("É um número negativo!\n");
    }
    else if (numero == 0)
    {
        printf("É igual a zero!\n");
    }
    else
    {
        printf("É um número positivo!\n");
    }
}

int numero_desejado;

int main()
{
    printf("Exercício 3 de funções!\n");
    printf("Funções sem retorno!\n");
    printf("Classificação de número!\n\n");
    printf("Informe um número: ");
    scanf("%d", &numero_desejado);
    printf("Vamos verificar se é positivo, negativo, ou igual zero...\n");

    classificar_numero(numero_desejado);
    return 0;
}