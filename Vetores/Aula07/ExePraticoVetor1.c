#include <stdio.h>

int main () {
    int num[5];

    for (int i=0; i<5; i++)
    {
        printf("Informe o %dº número: ", i + 1);
        scanf("%d", &num[i]);
    }
    printf ("\n### Números digitados ###\n");
    for (int i=0; i<5; i++) {
        printf ("[%d] ", num[i]);
    }
    printf ("\n\n");
    printf ("### Números em ordem inversa ###\n");
    for (int i=4; i>=0; i--) {
        printf ("[%d] ", num[i]);
    }
}