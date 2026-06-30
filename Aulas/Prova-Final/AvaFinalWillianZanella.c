#include <stdio.h>
#include <math.h>
#include <string.h>

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
    int opcao, opcao2;

    printf("\n------- Controle de Grupo da Copa do Mundo -------\n");

    do
    {
        printf("Informe o nome do grupo: ");
        fgets(grupo, sizeof(grupo), stdin);
        grupo[strcspn(grupo, "\n")] = '\0';
        if (strlen(grupo) == 0)
        {
            printf("ERRO: NOME DO GRUPO EM BRANCO!\n");
        }
    } while (strlen(grupo) == 0);

    for (int e = 0; e < 4; e++)
    {
        for (int d = 0; d < 1; d++)
        {
            do
            {
                printf("Informe o nome da equipe %d: ", e + 1);
                fgets(equipes[e], sizeof(equipes[e]), stdin);
                equipes[e][strcspn(equipes[e], "\n")] = '\0';
                if (strlen(equipes[e]) == 0)
                {
                    printf("ERRO: NOME DA EQUIPE EM BRANCO!\n");
                }
            } while (strlen(equipes[e]) == 0);
        }
    }

    for (int e = 0; e < 4; e++)
    {
        for (int d = 0; d < 8; d++)
        {
            dados[e][d] = 0;
        }
    }

    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (l < c) {

            printf("Informe o resultado do %dº jogo: ", c + 1);
            printf("%s vs %s:\n", equipes[l], equipes[l+1]);
            printf("Gols do(a) %s: ", equipes[l]);
            scanf("%d", &dados[l][c]);
            limparBuffer();

            printf("Gols do(a) %s: ", equipes[l+1]);
            scanf("%d", &dados[l][c]);
            limparBuffer();
            }
            
        }
    }

    printf("\n--------- RELATÓRIOS DO GRUPO ---------\n");
    printf("Selecione uma opção para exibir o relatório.\n");
    printf("1 - Exibir tabela geral.\n");
    printf("2 - Exibir pontuação das equipes.\n");
    printf("3 - Exibir relatório de gols.\n");
    printf("4 - Exibir resumo de uma equipe.\n");
    printf("0 - Sair.\n");
    printf("Sua opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {
        printf("\n");
        printf("========== TABELA GERAL - Grupo A ==========\n");
        printf("--------------------------------------------\n");
        printf("EQUIPE\tPts | PJ | VIT | E | DER | GM | GC | SG \n");
        printf("--------------------------------------------\n");
        for (int l = 0; l < 4; l++)
        {
            for (int c = 0; c < 8; c++)
            {
                printf("%s\t%d | %d | %d | %d | %d | %d | %d | %d\n");
            }
        }
        printf("--------------------------------------------\n");
        break;
    }
    case 2:
    {
        printf("\n");
        printf("========== PONTUAÇÃO DAS EQUIPES ==========\n");
        for (int l = 0; l < 4; l++)
        {
            printf("%s: %d ponto(s).\n");
        }
        break;
    }
    case 3:
    {
        printf("\n");
        printf("========== RELATÓRIO DE GOLS ==========\n");
        for (int l = 0; l < 4; l++)
        {
            printf("%s - GM: %d | GC: %d | SG: %d\n");
        }
        printf("Legenda: GM(Gols marcados) | GC(Gols contra) | SG(Saldo de gols)\n");
        break;
    }
    case 4:
    {
        printf("### EXIBIR RESUMO DE UMA EQUIPE ###\n");
        printf("Escolha uma equipe:\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d - %s");
        }
        printf("Sua escolha: ");
        scanf("%d", &opcao2);

        switch (opcao2)
        {
        case 1:
        {
        }
        }

        break;
    }
    }
}