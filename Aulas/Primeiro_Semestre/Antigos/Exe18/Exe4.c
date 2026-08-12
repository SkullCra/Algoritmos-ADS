#include <stdio.h>

int main()
{
    int numQtd = 0, numTotal = 0, num, par = 0, impar = 0, somaPar = 0;
    float mediaPar, mediaGeral;
   do {
        printf("Informe um número positivo(Ou 0 para encerrar): ");
        scanf("%d", &num);

        if (num !=0) {
        if (num % 2 == 0)
        {
            par = par + 1;
            somaPar = somaPar + num;
        }
        else
        {
            impar = impar + 1;
        }
    }
        numQtd = numQtd + 1;
        numTotal = numTotal + num;
    } while (num != 0);

    mediaPar = somaPar / par;
    mediaGeral = numTotal / numQtd;

    printf("A quantidade de números pares é de: %d.\n", par);
    printf("A quantidade de número ímpares é de: %d.\n", impar);
    printf("A média dos números pares é de: %.2f\n", mediaPar);
    printf("A média geral dos números lidos é de: %.2f\n", mediaGeral);

    return 0;
}