#include <stdio.h>

int main()
{
    int num[10];
    int jaVerificado, encontrouDuplicado = 0;

    printf("## VERIFICADOR DE DUPLICADOS ##\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Informe o %dº número: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("\nValores duplicados encontrados: \n");
    for (int i = 0; i < 10; i++)
    {
        int jaVerificado = 0;
        for (int j = 0; j < i; j++)
        {
            if (num[i] == num[j])
            {
                jaVerificado = 1;
                break;
            }
        }
        if (!jaVerificado) {
            for (int j = i + 1; j < 10; j++) {
                if (num[i] == num[j]) {
                    printf ("[%d] ", num[i]);
                    encontrouDuplicado = 1;
                    break;
                }
            }
        }
    }
    if (!encontrouDuplicado) {
        printf ("Nenhum valor duplicado encontrado.\n");
        return 0;
    }
}