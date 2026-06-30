#include <stdio.h>

int main(){
    int matriz[3][3], valorProcurado, encontrouValor = 0, linVal, colVal;

    for (int l = 0; l < 3; l++){
        for (int c = 0; c < 3; c++){
            printf("Informe o elemento [%d][%d] da matriz:", l, c);
            scanf("%d", &matriz[l][c]);
        }
    }
    printf("A matriz informada foi:\n\n");
    for (int l = 0; l < 3; l++){
        for (int c = 0; c < 3; c++){
            printf("[%d] ", matriz[l][c]);
        }
        printf("\n");
    }

    printf("Informe o valor que deseja procurar:");
    scanf("%d", &valorProcurado);

    for (int l = 0; l < 3; l++){
        for (int c = 0; c < 3; c++){
            if (matriz[l][c] == valorProcurado){
                linVal = l;
                colVal = c;
                encontrouValor = 1;
                printf("O valor %d foi encontrado na linha %d, coluna %d.\n", valorProcurado, linVal, colVal);
            }
        }
    }
    if (encontrouValor != 1){
        printf("Valor não encontrado.\n\n");
    }
    return 0;
}