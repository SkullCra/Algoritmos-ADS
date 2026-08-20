#include <stdio.h>
#include <string.h>

int calculadora_strings(char string[])
{
    int contador = 0;

    while (string[contador] != '\0')
    {
        contador++;
    }

    return contador;
}

char nome[30];
int tamanho = 0;

int main()
{
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    tamanho = calculadora_strings(nome);
    printf("A quantidade de caracteres é de %d.\n", tamanho);

    return 0;
}
