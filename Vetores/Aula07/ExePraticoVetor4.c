#include <stdio.h>

int main () {
    float num[5], soma=0, media=0;

    printf ("## CALCULADORA DE MÉDIA DE VETORES ##\n\n");
    for (int i=0; i<5; i++)
    {
        printf("Informe o %dº número: ", i + 1);
        scanf("%f", &num[i]);
    }
    for (int i=0; i<5; i++) {
        soma += num[i];
    }
    media = soma / 5.0;
    printf ("Soma: %.2f.\n", soma);
    printf ("Média: %.2f.\n", media);
    return 0;
}