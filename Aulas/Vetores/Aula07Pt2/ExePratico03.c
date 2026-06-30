#include <stdio.h>
#include <string.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    char nome[30];
    int tamanho;

    printf("### Calculadora de nomes ###\n");
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    tamanho = strlen(nome);
    printf("\n\nO nome digitado foi %s, e possui %d letras.", nome, tamanho);

    return 0;
}