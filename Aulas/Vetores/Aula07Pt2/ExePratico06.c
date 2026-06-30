#include <stdio.h>
#include <string.h>

int main()
{
    char texto1[21], texto2[21];

    printf("### Leitor e copiador de strings ###\n\n");
    printf("Digite um texto abaixo para ser copiado para a segunda string.\n");
    fgets(texto1, sizeof(texto1), stdin);
    texto1[strcspn(texto1, "\n")] = '\0';

    strcpy(texto2, texto1);

    printf("A string 1 possui o texto %s.\n", texto1);
    printf("A string 2 recebeu o texto \"%s\".\n", texto2);

    return 0;
}