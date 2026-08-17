#include <stdio.h>
#include <string.h>

int comparadora_strings(char string1[], char string2[])
{
    int contador = 0;

    while (string1[contador] == string2[contador] && string1[contador] != '\0')
    {
        contador++;
    }

    if (string1[contador] != string2[contador])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char string_1[30];
char string_2[30];
int sao_iguais;

int main()
{
    printf("Comparador de strings.\n");
    do
    {
        printf("Informe a primeira string: ");
        fgets(string_1, sizeof(string_1), stdin);
        string_1[strcspn(string_1, "\n")] = '\0';
        if (strlen(string_1) == 0)
        {
            printf("Erro: A string não pode estar vazia.\n");
        }
    } while (strlen(string_1) == 0);

    do
    {
        printf("Informe a segunda string: ");
        fgets(string_2, sizeof(string_2), stdin);
        string_2[strcspn(string_2, "\n")] = '\0';
        if (strlen(string_2) == 0)
        {
            printf("Erro: A string não pode estar vazia.\n");
        }
    } while (strlen(string_2) == 0);

    sao_iguais = comparadora_strings(string_1, string_2);

    if (sao_iguais == 0)
    {
        printf("As strings são diferentes!\n");
    }
    if (sao_iguais == 1)
    {
        printf("As strings são iguais!\n");
    }

    return 0;
}