#include <stdio.h>

int encontra_menor(int a, int b)
{
    int menor;
    if (a < b)
    {
        menor = a;
    }
    else if (a > b)
    {
        menor = b;
    }

    return menor;
}

int num_a, num_b, menor_num;

int main()
{
    printf("Exercício 7 de funções!\n");
    printf("Funções com retorno!\n");
    printf("Menor entre dois valores!\n\n");
    printf("Informe o primeiro número: ");
    scanf("%d", &num_a);
    do
    {
        printf("Informe o segundo número: ");
        scanf("%d", &num_b);

        if (num_a == num_b)
        {
            printf("Os números são iguais!\n");
        }
    } while (num_a == num_b);
    printf("Descobrindo...\n");

    menor_num = encontra_menor(num_a, num_b);
    printf("O menor número é %d!\n", menor_num);
    return 0;
}