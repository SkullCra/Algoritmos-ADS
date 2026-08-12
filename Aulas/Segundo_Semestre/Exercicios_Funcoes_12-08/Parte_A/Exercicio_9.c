#include <stdio.h>

int eh_par(int numero)
{
    if (numero % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int num, retorno;

int main()
{
    printf("Exercício 9 de funções!\n");
    printf("Funções com retorno!\n");
    printf("Verificação de número par!\n\n");
    printf("Informe um número: ");
    scanf("%d", &num);
    retorno = eh_par(num);
    printf("Verificando...\n");

    if (retorno == 1)
    {
        printf("O número é par!");
    }
    else
    {
        printf("O número é impar!");
    }
    return 0;
}