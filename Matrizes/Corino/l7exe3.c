#include <stdio.h>

int main()
{
    int nLinhas, nColunas;
    printf("Informe o número de linhas da matriz: ");
    scanf("%d", &nLinhas);
    printf("Informe o número de colunas da matriz: ");
    scanf("%d", &nColunas);

    int matriz[nLinhas][nColunas], soma = 0;
    

    for (int L = 0; L < nLinhas; L++){
        for (int C = 0; C < nColunas; C++){
            if(L==C){
                matriz[L][C] = 1;
            }
            else{
                matriz[L][C] = 0;
            }
        }
    }
    printf("A matriz informada foi:\n\n");
    for (int L = 0; L < nLinhas; L++){
        for (int C = 0; C < nColunas; C++){
            printf(" [%d] ", matriz[L][C]);
        }
        printf("\n");
    }
    printf("A soma dos elementos é %d.\n\n", soma);
}