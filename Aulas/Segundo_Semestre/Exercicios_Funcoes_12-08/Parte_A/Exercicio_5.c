#include <stdio.h>

void exibir_conversao(float celsius)
{
    float fahrenheit = celsius * 1.8 + 32;

    printf("A temperatura informada é de %.1f graus Celsius.\n", celsius);
    if (celsius < 0)
    {
        printf("Está abaixo de zero!\n");
    }
    else if (celsius == 0)
    {
        printf("A temperatura informada é igual a zero!\n");
    }
    else
    {
        printf("A temperatura informada é acima de zero!\n");
    }
    printf("A temperatura em Fahrenheit é de %.1f graus.\n", fahrenheit);
}

float temperatura;

int main()
{
    printf("Exercício 5 de funções!\n");
    printf("Funções sem retorno!\n");
    printf("Conversão de temperatura para Fahrenheit!\n\n");
    printf("Informe a temperatura em graus Celsius: ");
    scanf("%f", &temperatura);
    printf("Calculando...\n");
    exibir_conversao(temperatura);
    return 0;
}