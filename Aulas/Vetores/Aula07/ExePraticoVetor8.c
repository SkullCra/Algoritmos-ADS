#include <stdio.h>

int main () {
    int num[8], encontrou = 0, busca;

    printf ("## LEITOR DE VETORES EXISTENTES ##\n\n");
    for (int i = 0; i < 8; i++) {
        printf ("Informe o %dº número: ", i + 1);
        scanf ("%d", &num[i]);
    }
    printf ("\nInforme um número para verificar se é existente: ");
    scanf ("%d", &busca);

    printf ("\nResultado da busca:\n");
    for (int i = 0; i < 8; i++) {
        if (num[i] == busca) {
            printf ("Encontrado na posição %d.\n", i);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf ("Número %d não está no vetor.\n", busca);
    }
    return 0;
}