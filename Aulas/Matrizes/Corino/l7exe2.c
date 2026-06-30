#include <stdio.h>
int main(){
    int matriz[3][3];
    for(int L = 0; L < 3; L++){
        for(int C = 0; C < 3; C++){
            if(L==C){
                matriz[L][C] = 1;
            }
            else{
                matriz[L][C] = 0;
            }
        }
    }
    printf("A matriz identidade é:\n\n");
    for(int L = 0; L < 3; L++){
        for(int C = 0; C < 3; C++){
           printf("[%d] ", matriz[L][C]);
        }
        printf("\n");
    }

}