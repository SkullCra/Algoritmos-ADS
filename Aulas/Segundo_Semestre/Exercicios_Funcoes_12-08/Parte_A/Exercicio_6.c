#include <stdio.h>

int calcular_dobro(int numero)
{
    int dobro = (numero * 2);
    return dobro;
}

int num_desejado, num_dobrado;

int main()
{
    printf("Exercício 6 de funções!\n");
    printf("Funções com retorno!\n");
    printf("Dobro de um número!\n\n");
    printf("Informe um número que deseja dobrar: ");
    scanf("%d", &num_desejado);
    num_dobrado = calcular_dobro(num_desejado);
    printf("O número dobrado de %d, é %d!\n", num_desejado, num_dobrado);
    return 0;
}