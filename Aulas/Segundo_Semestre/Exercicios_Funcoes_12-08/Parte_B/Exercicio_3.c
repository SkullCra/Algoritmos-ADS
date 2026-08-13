#include <stdio.h>

int comparador_valores(int num1, int num2)
{
    if (num1 == num2)
    {
        printf("São iguais!\n");
    }
    else if (num1 < num2)
    {
        printf("%d é maior que %d.", num2, num1);
    }
    else
    {
        printf("%d é maior que %d.", num1, num2);
    }
}

int numero1, numero2;

int main()
{
    printf("Comparador de números\n");
    printf("Informe o primeiro número: ");
    scanf("%d", &numero1);
    printf("Informe o segundo número: ");
    scanf("%d", &numero2);
    comparador_valores(numero1, numero2);

    return 0;
}