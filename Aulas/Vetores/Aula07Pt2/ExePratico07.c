#include <stdio.h>
#include <string.h>

int main()
{
    char texto1[31], texto2[31], concatenado[62];
    int tamanho;

    printf("### Comparador e Concatenador de Strings ###\n\n");
    printf("Digite abaixo o primeiro texto (até 30 caracteres):\n");
    fgets(texto1, sizeof(texto1), stdin);
    texto1[strcspn(texto1, "\n")] = '\0';

    printf("Digite abaixo o segundo texto (até 30 caracteres):\n");
    fgets(texto2, sizeof(texto2), stdin);
    texto2[strcspn(texto2, "\n")] = '\0';

    if (strcmp(texto1, texto2) == 0)
    {
        printf("As strings são iguais.\n");
    }
    else
    {
        printf("As strings são diferentes.\n");
        printf("Concatenando strings...\n");

        concatenado[0] = '\0';
        strcat(concatenado, texto1);
        strcat(concatenado, texto2);
        for (int i = 0; concatenado[i] != '\0'; i++)
        {

            if (concatenado[i] >= 'a' && concatenado[i] <= 'z')
            {
                concatenado[i] = concatenado[i] - 32;
            }
        }
        printf("O resultado é %s.\n", concatenado);
    }
    return 0;
}