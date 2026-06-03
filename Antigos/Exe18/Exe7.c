#include <stdio.h>

int main () {
    int numero, maior, menor, i = 0;
    float media, soma = 0;

    printf ("Digite um número inteiro (Digite 0 para encerrar): ");
    scanf ("%d", &numero);

    if (numero == 0) {
        printf ("Nenhum número foi digitado.\n");
        return 0;
    }

    maior = numero;
    menor = numero;

    while (numero != 0) {
        soma += numero;
        i++;

        if (numero > maior)
        maior = numero;
        if (numero < menor)
        menor = numero;

        printf ("Digite um numero inteiro (Digite 0 para encerrar): ");
        scanf ("%d", &numero);
    }

    media = soma / i;
    printf ("\n --- Resultados ---\n");
    printf ("Maior valor: %d\n", maior);
    printf ("Menor valor: %d\n", menor);
    printf ("Media dos valores: %.2f\n", media);

    return 0;
}