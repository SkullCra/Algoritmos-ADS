#include <stdio.h>

int main(){
    int matriz[4][4], maiorQdez = 0;

    for (int l = 0; l < 4; l++){
        for(int c = 0; c < 4; c++){
            printf("Informe o elemento [%d][%d] da matriz:", l,c);
            scanf("%d", &matriz[l][c]);
            if(matriz[l][c]>10){
                maiorQdez++;
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
    printf("Na matriz existem %d valores maiores que 10.\n\n", maiorQdez);
}