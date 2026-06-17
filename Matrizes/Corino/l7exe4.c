#include <stdio.h>

int main(){
    int matriz[4][4], maiorValor = -99999, linMaior, colMaior;

    for (int l = 0; l < 4; l++){
        for(int c = 0; c < 4; c++){
            printf("Informe o elemento [%d][%d] da matriz:", l,c);
            scanf("%d", &matriz[l][c]);
            if(matriz[l][c] > maiorValor){
                maiorValor = matriz[l][c];
                linMaior = l;
                colMaior = c;
            }
        }
    }
    printf("A matriz informada foi:\n\n");
    for (int l = 0; l < 4; l++){
        for(int c = 0; c < 4; c++){
            printf("[%d] ", matriz[l][c]);
        }
    printf("\n");
    }
    printf("\n O maior valor da matriz é %d na posição [%d][%d].\n\n", maiorValor, linMaior,colMaior);
}