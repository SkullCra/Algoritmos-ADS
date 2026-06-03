#include <stdio.h>

int main () {
    int num[10], x, y;

    printf ("## SOMA POR ÍNDICE ##\n\n");
    for (int i = 0; i < 10; i++) {
        printf ("Informe o %dº número: ", i + 1);
        scanf ("%d", &num[i]);
    }
    printf ("\nInforme o índice X (1 a 10): ");
    scanf ("%d", &x);
    printf ("\nInforme o índice Y (1 a 10): ");
    scanf ("%d", &y);

    x = x - 1;
    y = y - 1;

    if (x < 0 || x > 9 || y < 0 || y > 9) {
        printf ("\nErro: índices devem estar entre 1 e 10.\n");
        return 1;
    }

    int soma = num[x] + num[y];
    printf ("\nÍndice X [%d] = %d.\n", x + 1, num[x]);
    printf ("Índice Y [%d] = %d.\n", y + 1, num[y]);
    printf ("Soma dos índices: %d.\n", soma);

    return 0;
}