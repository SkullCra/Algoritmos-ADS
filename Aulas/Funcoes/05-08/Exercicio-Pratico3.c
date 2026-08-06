#include <stdio.h>

int menor_valor(int a, int b)
{

    if (a < b)
    {
        return 1;
    }
    if (b < a)
    {
        return 0;
    }
    if (a == b)
    {
        return -1;
    }
}

int primeiro, segundo, menor;
int main()
{
    printf("Informe dois números para verificar qual o menor:\n");
    printf("Primeiro número: ");
    scanf("%d", &primeiro);
    printf("Segundo número: ");
    scanf("%d", &segundo);

    menor = menor_valor(primeiro, segundo);

    if (menor == 1)
    {
        printf("O menor valor é %d.\n", primeiro);
    }

    if (menor == 0)
    {
        printf("O menor valor é %d.\n", segundo);
    }

    if (menor == -1)
    {
        printf("Os valores são iguais.\n");
    }

    return 0;
}