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
    char grupo[30];
    char equipes[4][30];
    int dados[4][8];

    int opcao;

    printf("\n------- Controle de Grupo da Copa do Mundo -------\n");

    do
    {
        printf("Informe o nome do grupo: ");
        fgets(grupo, sizeof(grupo), stdin);
        grupo[strcspn(grupo, "\n")] = '\0';
        if (strlen(grupo) == 0)
        {
            printf("ERRO: Nome do grupo em branco!\n");
        }
    } while (strlen(grupo) == 0);

    for (int e = 0; e < 4; e++)
    {
        do
        {
            printf("Informe o nome da equipe %d: ", e + 1);
            fgets(equipes[e], sizeof(equipes[e]), stdin);
            equipes[e][strcspn(equipes[e], "\n")] = '\0';

            if (strlen(equipes[e]) == 0)
            {
                printf("ERRO: Nome da equipe em branco!\n");
            }
        } while (strlen(equipes[e]) == 0);
    }

    printf("\nCadastro concluido!\n");
    printf("Grupo: %s\n", grupo);
    for (int e = 0; e < 4; e++)
    {
        printf("Equipe %d: %s\n", e + 1, equipes[e]);
    }

    for (int e = 0; e < 4; e++) {
        for (int d = 0; d < 8; d++) {
            dados[e][d] = 0;
        }
    }

    
}