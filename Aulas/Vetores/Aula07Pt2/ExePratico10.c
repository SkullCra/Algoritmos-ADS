#include <stdio.h>
#include <string.h>

void limpaBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
int main()
{
    char nome1[31], nome2[32];
    int tamanho1, tamanho2;

    printf("## CONTADOR DE POSIÇÕES DE NOMES ##\n");
    printf("Digite o primeiro nome: ");
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = '\0';
    tamanho1 = strlen(nome1);

    printf("Digite o segundo nome: ");
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = '\0';
    tamanho2 = strlen(nome2);

    for (int i = 0; nome1[i] != '\0'; i++)
    {
        printf("\n### Nome 1 ###\n");
        printf("Posição %d: %c.\n", i, nome1[i]);
    }
    for (int i = 0; nome2[i] != '\0'; i++)
    {
        printf("\n### Nome 2 ###\n");
        printf("Posição %d: %c.\n", i, nome2[i]);
    }

    return 0;
}