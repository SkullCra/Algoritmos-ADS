#include <stdio.h>
#include <string.h>

int main()
{
    char string1[30], string2[30];

    printf("Informe a primeira palavra: ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Informe a segunda palavra: ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0';

    if (strcmp(string1, string2) == 0)
    {
        puts("São iguais");
    }
    else
    {
        puts("São diferentes");
    }

    return 0;
}