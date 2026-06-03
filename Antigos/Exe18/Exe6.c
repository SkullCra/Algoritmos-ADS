#include <stdio.h>
#include <math.h>

int main (){
    float paisA, paisB;
    int qtdAnos;

    paisA = 5000000;
    paisB = 7000000;
    qtdAnos = 0;

    while (paisA < paisB) {
        paisA = (paisA * 0.03) + paisA;
        paisB = (paisB * 0.02) + paisB;
        qtdAnos = qtdAnos + 1;
    }

    printf ("País A ultrapassou País B em %d anos.\n", qtdAnos);
    printf ("A população de país A é de %.0f pessoas.\n", paisA);
    printf ("A população de país B é de %.0f pessoas.\n", paisB);
}