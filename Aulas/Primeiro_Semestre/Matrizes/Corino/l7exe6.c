#include <stdio.h>

int main(){
    int matriz[2][2], detMatriz;

     for (int l = 0; l < 2; l++){
        for (int c = 0; c < 2; c++){
            printf("Informe o elemento [%d][%d] da matriz:", l, c);
            scanf("%d", &matriz[l][c]);
        }
    }
    printf("A matriz informada foi:\n\n");
    for (int l = 0; l < 2; l++){
        for (int c = 0; c < 2; c++){
            printf("[%d] ", matriz[l][c]);
        }
        printf("\n");
    }
    detMatriz = (matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]);

    printf("O determinante da matriz é %d.\n\n", detMatriz);
}