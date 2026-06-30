#include <stdio.h>
#include <math.h>

int main () {
    int n, i, fat;

    printf ("***Programa de sequência de valores fatoriais***\n\n");
    printf ("Informe um valor inicial: ");
    scanf ("%d", &n);

    if (n < 0) {
        printf ("Erro! Fatorial de número negativo não existe.\n");
    } 
    else {
        for (fat = 1; n > 1; n = n -1) {
            fat = fat * n;
        } 
    }
    printf ("O valor fatorial é de %d.\n", fat);
    return 0;
}