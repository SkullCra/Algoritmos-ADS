#include <stdio.h>

int main () {
    int num[10];

    for (int i=0; i<10; i++)
    {
        printf("Informe o %dº número: ", i + 1);
        scanf("%d", &num[i]);
    }
    printf ("\n### Números digitados ###\n");
    for (int i=0; i<10; i++) {
        printf ("[%d] ", num[i]);
    }
    printf ("\n\n");
    printf ("### Posições dos números digitados ###\n");
    for (int i=0; i<10; i++) {
        printf ("[%d] ", i);
    }
}