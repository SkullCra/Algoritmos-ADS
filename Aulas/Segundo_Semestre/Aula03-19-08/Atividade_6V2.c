#include <stdio.h>
#include <string.h>

void limparBuffer() {                       // Função usada para limpar o buffer do teclado.
    int c;                                  
    while ((c = getchar()) != '\n' && c != EOF);
}

void limpar_strings(char string) {
    string[strcspn(string, "\n")] = '\0';
}

void cadastro_empresa() {
    char razao_social[100];
    char CNPJ[30];
    char endereco[150];

    printf("\nDigite a razão social da empresa: ");
    printf("")
}