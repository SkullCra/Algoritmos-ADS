#include <stdio.h>

void imprimir_linha(char caractere, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        printf("%c", caractere);
    }
}

char caractere_desejado;
int quantidade_desejada;

int main()
{
    printf("Exercício 2 de funções!\n");
    printf("Funções sem retorno!\n");
    printf("Linha separadora!\n\n");
    printf("Informe o caractere desejado: ");
    scanf("%c", &caractere_desejado);
    printf("\n");
    printf("Informe a quantidade desejada: ");
    scanf("%d", &quantidade_desejada);

    imprimir_linha(caractere_desejado, quantidade_desejada);
    return 0;
}