#include <stdio.h>

int main () {
    float num[10], quadrado[10];

    for (int i = 0; i < 10; i++){
        printf ("Informe o %dº número: ", i + 1);
        scanf ("%f", &num[i]);
        quadrado[i] = num[i] * num[i];
    }
    printf ("\n## RESULTADOS ##\n\n");
    
    for (int i = 0; i < 10; i++) {
        printf ("Vetor original: %.2f.\n", num[i]);
        printf ("Quadrado do vetor: %.2f.\n", quadrado[i]);
    }
    return 0;
}