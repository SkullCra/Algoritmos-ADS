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

    int opcao, opcao2;

    printf("\n------ Controle de Grupo da Copa do Mundo ------\n");

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

    printf("\nCadastro concluído!\n");
    printf("Nome do Grupo: %s\n\n", grupo);
    for (int e = 0; e < 4; e++)
    {
        printf("Equipe %d: %s\n", e + 1, equipes[e]);
    }

    for (int e = 0; e < 4; e++)
    {
        for (int d = 0; d < 8; d++)
        {
            dados[e][d] = 0;
        }
    }

    for (int e1 = 0; e1 < 4; e1++)
    {
        for (int e2 = e1 + 1; e2 < 4; e2++)
        {
            int golse1, golse2;
            printf("\n%s x %s\n", equipes[e1], equipes[e2]);
            do
            {
                printf("Gols do(a) %s: ", equipes[e1]);
                scanf("%d", &golse1);
                limparBuffer();

                if (golse1 < 0)
                {
                    printf("ERRO: Quantidade de gols não pode ser negativo!\n");
                }

            } while (golse1 < 0);

            do
            {
                printf("Gols do(a) %s: ", equipes[e2]);
                scanf("%d", &golse2);
                limparBuffer();

                if (golse2 < 0)
                {
                    printf("ERRO: Quantidade de gols não pode ser negativo!\n");
                }

            } while (golse2 < 0);

            if (golse1 > golse2)
            {
                printf("Vitória do(a): %s!\n", equipes[e1]);
                dados[e1][0] = dados[e1][0] + 3;
                dados[e1][1] = dados[e1][1] + 1;
                dados[e2][1] = dados[e2][1] + 1;
                dados[e1][2] = dados[e1][2] + 1;
                dados[e2][4] = dados[e2][4] + 1;
                dados[e1][5] = dados[e1][5] + golse1;
                dados[e2][5] = dados[e2][5] + golse2;
                dados[e1][6] = dados[e1][6] + golse2;
                dados[e2][6] = dados[e2][6] + golse1;
                dados[e1][7] = dados[e1][7] + (golse1 - golse2);
                dados[e2][7] = dados[e2][7] + (golse2 - golse1);
            }
            if (golse1 < golse2)
            {
                printf("Vitória do(a): %s!\n", equipes[e2]);
                dados[e2][0] = dados[e2][0] + 3;
                dados[e2][1] = dados[e2][1] + 1;
                dados[e1][1] = dados[e1][1] + 1;
                dados[e2][2] = dados[e2][2] + 1;
                dados[e1][4] = dados[e1][4] + 1;
                dados[e1][5] = dados[e1][5] + golse1;
                dados[e2][5] = dados[e2][5] + golse2;
                dados[e1][6] = dados[e1][6] + golse2;
                dados[e2][6] = dados[e2][6] + golse1;
                dados[e2][7] = dados[e2][7] + (golse2 - golse1);
                dados[e1][7] = dados[e1][7] + (golse1 - golse2);
            }
            if (golse1 == golse2)
            {
                printf("Empate!\n");
                dados[e1][0] = dados[e1][0] + 1;
                dados[e2][0] = dados[e2][0] + 1;
                dados[e1][1] = dados[e1][1] + 1;
                dados[e2][1] = dados[e2][1] + 1;
                dados[e1][3] = dados[e1][3] + 1;
                dados[e2][3] = dados[e2][3] + 1;
                dados[e1][5] = dados[e1][5] + golse1;
                dados[e2][5] = dados[e2][5] + golse2;
                dados[e1][6] = dados[e1][6] + golse2;
                dados[e2][6] = dados[e2][6] + golse1;
                dados[e1][7] = dados[e1][7] + (golse1 - golse2);
                dados[e2][7] = dados[e2][7] + (golse2 - golse1);
            }
        }
    }
    do
    {
        do
        {
            printf("\n==== RELATÓRIOS DO GRUPO ====\n");
            printf("1 - Exibir tabela geral\n");
            printf("2 - Exibir pontuação das equipes\n");
            printf("3 - Exibir relatório de gols\n");
            printf("4 - Exibir resumo de uma equipe\n");
            printf("0 - Sair\n");
            printf("Sua escolha: ");
            scanf("%d", &opcao);
            limparBuffer();

            if (opcao < 0 || opcao > 4)
            {
                printf("Opção inválida, tente novamente!\n");
            }
        } while (opcao < 0 || opcao > 4);

        switch (opcao)
        {
        case 1:
            printf("\n");
            printf("\n========== TABELA GERAL - %s ==========\n", grupo);
            printf("--------------------------------------------\n");
            printf("EQUIPE\tPts | PJ | VIT | E | DER | GM | GC | SG \n");
            printf("--------------------------------------------\n");
            for (int l = 0; l < 4; l++)
            {
                printf("%-10s %d | %d | %d | %d | %d | %d | %d | %d\n", equipes[l], dados[l][0], dados[l][1], dados[l][2], dados[l][3], dados[l][4], dados[l][5], dados[l][6], dados[l][7]);
            }
            printf("--------------------------------------------\n");
            break;
        case 2:
            printf("\n");
            printf("\n===== PONTUAÇÃO DAS EQUIPES =====\n");
            for (int e = 0; e < 4; e++)
            {
                printf("%s: %d ponto(s).\n", equipes[e], dados[e][0]);
            }
            break;
        case 3:
            printf("\n");
            printf("\n===== RELATÓRIO DE GOLS =====\n");
            for (int e = 0; e < 4; e++)
            {
                printf("%s - GM: %d | GC: %d | SG: %d\n", equipes[e], dados[e][5], dados[e][6], dados[e][7]);
            }
            printf("\n");
            printf("Legenda: GM(Gols marcados) | GC(Gols contra) | SG(Saldo de gols)\n");
            break;
        case 4:
            printf("\n===== RESUMO POR EQUIPE =====\n");
            do
            {
                printf("Escolha uma equipe:\n");
                for (int e = 0; e < 4; e++)
                {
                    printf("%d - %s\n", e + 1, equipes[e]);
                }
                printf("Sua escolha: ");
                scanf("%d", &opcao2);
                limparBuffer();

                if (opcao2 < 1 || opcao2 > 4)
                {
                    printf("Opção inválida, tente novamente!\n\n");
                }
            } while (opcao2 < 1 || opcao2 > 4);

            switch (opcao2)
            {
            case 1:
                printf("\n");
                printf("====== RESUMO DA EQUIPE ======\n");
                printf("Equipe: %s\n", equipes[0]);
                printf("Pontos: %d\n", dados[0][0]);
                printf("Partidas Jogadas: %d\n", dados[0][1]);
                printf("Vitórias: %d\n", dados[0][2]);
                printf("Empates: %d\n", dados[0][3]);
                printf("Derrotas: %d\n", dados[0][4]);
                printf("Gols marcados: %d\n", dados[0][5]);
                printf("Gols contra: %d\n", dados[0][6]);
                printf("Saldo de gols: %d\n", dados[0][7]);
                break;

            case 2:
                printf("\n");
                printf("====== RESUMO DA EQUIPE ======\n");
                printf("Equipe: %s\n", equipes[1]);
                printf("Pontos: %d\n", dados[1][0]);
                printf("Partidas Jogadas: %d\n", dados[1][1]);
                printf("Vitórias: %d\n", dados[1][2]);
                printf("Empates: %d\n", dados[1][3]);
                printf("Derrotas: %d\n", dados[1][4]);
                printf("Gols marcados: %d\n", dados[1][5]);
                printf("Gols contra: %d\n", dados[1][6]);
                printf("Saldo de gols: %d\n", dados[1][7]);
                break;

            case 3:
                printf("\n");
                printf("====== RESUMO DA EQUIPE ======\n");
                printf("Equipe: %s\n", equipes[2]);
                printf("Pontos: %d\n", dados[2][0]);
                printf("Partidas Jogadas: %d\n", dados[2][1]);
                printf("Vitórias: %d\n", dados[2][2]);
                printf("Empates: %d\n", dados[2][3]);
                printf("Derrotas: %d\n", dados[2][4]);
                printf("Gols marcados: %d\n", dados[2][5]);
                printf("Gols contra: %d\n", dados[2][6]);
                printf("Saldo de gols: %d\n", dados[2][7]);
                break;

            case 4:
                printf("\n");
                printf("====== RESUMO DA EQUIPE ======\n");
                printf("Equipe: %s\n", equipes[3]);
                printf("Pontos: %d\n", dados[3][0]);
                printf("Partidas Jogadas: %d\n", dados[3][1]);
                printf("Vitórias: %d\n", dados[3][2]);
                printf("Empates: %d\n", dados[3][3]);
                printf("Derrotas: %d\n", dados[3][4]);
                printf("Gols marcados: %d\n", dados[3][5]);
                printf("Gols contra: %d\n", dados[3][6]);
                printf("Saldo de gols: %d\n", dados[3][7]);
                break;

            default:
                printf("Opção inválida, tente novamente!\n");
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}