#include <stdio.h>

int main () {
    int num[10], soma=0;

    for (int i=0; i<10; i++)
    {
        printf("Informe o %dº número: ", i + 1);
        scanf("%d", &num[i]);
    }
    for (int i=0; i<10; i++) {
        soma += num[i];
    }
    printf ("Soma: %d.\n", soma);
    return 0;
}