#include <stdio.h>
#include <string.h>
#include <math.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    char string[30];
    int i;

    printf("## Leitura de Strings ##\n");
    printf("Digite uma palavra: ");
    fgets(string, sizeof(string), stdin);
    // matriz, tamanho(matriz), stdin
    string[strcspn(string, "\n")] = '\0';
    // aqui ele busca o \n na string e substitui por \0 que é nulo

    for (i = 0; string[i] != '\0'; i++)
    {
        printf("[%c]", string[i]);

        if (string[i + 1] != '\0')
        {
            printf("-");
        }
    }
    printf("\n");

    return 0;
}