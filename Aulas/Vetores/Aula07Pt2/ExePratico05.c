#include <stdio.h>
#include <string.h>

int main()
{
    char texto[21];
    int i;
    int tamanho;

    printf("### Leitor e contador de texto ###\n\n");
    printf("Digite abaixo um texto com até 20 caracteres.\n");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';

    tamanho = 0;
    for (i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] != ' ')
        {
            tamanho++;
        }
    }
    printf("O texto digitado foi %s.\n", texto);
    printf("A quantidade de caracteres digitada foi de %d caracteres.\n", tamanho);

    return 0;
}