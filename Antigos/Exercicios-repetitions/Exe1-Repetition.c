#include <stdio.h>
#include <math.h>

int main () {
    float media, nota1, nota2;
    int estudantes, i = 0;

    printf ("****Programa para cálculo de média de estudantes***\n\n");
    printf ("Qual a quantidade de estudantes que deseja calcular a nota?\n");
    scanf ("%d", &estudantes);

    while (i < estudantes) {
        printf ("Insira a primeira nota: ");
        scanf ("%f", &nota1);

        printf ("Insira a segunda nota: ");
        scanf ("%f", &nota2);

        media = (nota1 + nota2) / 2;

        printf ("A média é de: %.2f.\n\n", media);

        i++;
    }

    return 0;
}