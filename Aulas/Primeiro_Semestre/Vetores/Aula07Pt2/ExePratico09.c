#include <stdio.h>
#include <string.h>

int main()
{
    char nome[31], inverso[31];
    int tamanho;

    printf("### INVERSOR DE NOMES ###\n\n");
    printf("Digite seu nome (até 30 caracteres): ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("O nome digitado foi %s.\n", nome);
    tamanho = strlen(nome);

    printf("Nome invertido:\n");
    for (int i = tamanho - 1; i >= 0; i--)
    {
        printf("%c", nome[i]);
    }
    return 0;
}