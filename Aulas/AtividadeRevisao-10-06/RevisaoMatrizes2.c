#include <stdio.h>
#include <math.h>
#include <string.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n')
        ;
}

int main () {
    int matriz[5][5], menor = 0;

    for (int l = 0; l < 5; l++){
        for (int c = 0; c < 5; c++) {
            printf ("Informe o número da posição [%d][%d]: ", l, c);
            scanf ("%d", &matriz[l][c]);
            if (matriz[l][c] < 0) {
                menor = menor++;
            }
        }
    }
    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {
            printf("[%d] ", matriz[l][c]);
        }
    }
    printf ("\nA quantidade de valores menores que 0 é de: %d.\n", menor);
    return 0;
}