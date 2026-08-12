#include <stdio.h>

int main () {
    int numero, i;

    printf ("*** Programa de contagem regressiva de números inteiros e positivos ***\n\n");
    printf ("Informe um número inteiro positivo: ");
    scanf ("%d", &numero);

    i = numero;

    for (i = numero; i >= 0; i--) {
        printf ("Contagem regressiva, %d...\n", i);
    }

    printf ("Contagem regressiva concluída!");

    return 0;
}