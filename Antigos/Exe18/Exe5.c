#include <stdio.h>
#include <math.h>

int main (){
    float alturaChico, alturaJuca;
    int qtdAnos;

    alturaChico = 170;
    alturaJuca = 110;
    qtdAnos = 0;

    while (alturaJuca < alturaChico) {
        alturaJuca = alturaJuca + 3;
        alturaChico = alturaChico +2;
        qtdAnos = qtdAnos + 1;
    }

    printf ("Juca ficou maior que chico em %d anos.\n", qtdAnos);
    alturaJuca = alturaJuca / 100;
    alturaChico = alturaChico / 100; 
    printf ("A altura de Juca agora é de %.2f metros.\n", alturaJuca);
    printf ("E a altura de Chico agora é de %.2f metros.\n", alturaChico);
}