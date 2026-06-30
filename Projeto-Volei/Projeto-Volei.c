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
    int dados[4][7];
    int opcao, opcao_menu, escolha;

    do
    {
        printf("\n==== CAMPEONATO DE VÔLEI MUNICIPAL ====\n");
        do
        {
            printf("Informe o nome do grupo: ");
            fgets(grupo, sizeof(grupo), stdin);
            grupo[strcspn(grupo, "\n")] = '\0';
            if (strlen(grupo) == 0)
            {
                printf("ERRO: Nome das equipes não podem estar em branco!\n");
            }
        } while (strlen(grupo) == 0);

        for (int e = 0; e < 4; e++)
        {
            do
            {
                printf("Informe o nome da %dª equipe: ", e + 1);
                fgets(equipes[e], sizeof(equipes[e]), stdin);
                equipes[e][strcspn(equipes[e], "\n")] = '\0';

                if (strlen(equipes[e]) == 0)
                {
                    printf("ERRO: Nome das equipes não podem estar em branco!\n");
                }
            } while (strlen(equipes[e]) == 0);
        }

        for (int e = 0; e < 4; e++)
        {
            for (int d = 0; d < 7; d++)
            {
                dados[e][d] = 0;
            }
        }

        printf("\n==== RESULTADOS DOS JOGOS ====\n");
        int setsE1;
        int setsE2;
        for (int e1 = 0; e1 < 4; e1++)
        {
            for (int e2 = e1 + 1; e2 < 4; e2++)
            {
                do
                {
                    printf("\n%s x %s\n", equipes[e1], equipes[e2]);
                    do
                    {
                        printf("Sets ganhos por %s: ", equipes[e1]);
                        scanf("%d", &setsE1);
                        limparBuffer();

                        if (setsE1 < 0 || setsE1 > 25)
                        {
                            printf("RESULTADO IMPOSSÍVEL!\n");
                        }
                    } while (setsE1 < 0 || setsE1 > 25);

                    do
                    {
                        printf("Sets ganhos por %s: ", equipes[e2]);
                        scanf("%d", &setsE2);
                        limparBuffer();

                        if (setsE2 < 0 || setsE2 > 25)
                        {
                            printf("RESULTADO IMPOSSÍVEL!\n");
                        }
                    } while (setsE2 < 0 || setsE2 > 25);

                    if (setsE1 == setsE2)
                    {
                        printf("RESULTADO IMPOSSÍVEL!\n");
                    }
                } while (setsE1 == setsE2);

                if (setsE1 > setsE2)
                {
                    dados[e1][0] = dados[e1][0] + 2;
                    dados[e1][1] = dados[e1][1] + 1;
                    dados[e2][1] = dados[e2][1] + 1;
                    dados[e1][2] = dados[e1][2] + 1;
                    dados[e2][3] = dados[e2][3] + 1;
                    dados[e1][4] = dados[e1][4] + setsE1;
                    dados[e2][4] = dados[e2][4] + setsE2;
                    dados[e1][5] = dados[e1][5] + setsE2;
                    dados[e2][5] = dados[e2][5] + setsE1;
                    dados[e1][6] = dados[e1][6] + (setsE1 - setsE2);
                }
                if (setsE2 > setsE1)
                {
                    dados[e2][0] = dados[e2][0] + 2;
                    dados[e1][1] = dados[e1][1] + 1;
                    dados[e2][1] = dados[e2][1] + 1;
                    dados[e2][2] = dados[e2][2] + 1;
                    dados[e1][3] = dados[e1][3] + 1;
                    dados[e1][4] = dados[e1][4] + setsE1;
                    dados[e2][4] = dados[e2][4] + setsE2;
                    dados[e1][5] = dados[e1][5] + setsE2;
                    dados[e2][5] = dados[e2][5] + setsE1;
                    dados[e2][6] = dados[e2][6] + (setsE2 - setsE1);
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
                printf("3 - Exibir relatório de sets\n");
                printf("4 - Exibir resumo de uma equipe\n");
                printf("0 - Sair\n");
                printf("Sua escolha: ");
                scanf("%d", &opcao);
                limparBuffer();

                if (opcao < 0 || opcao > 4)
                {
                    printf("ERRO: Opção inválida!\n");
                }
            } while (opcao < 0 || opcao > 4);

            switch (opcao)
            {
            case 0:
                printf("Saindo...\n");
                break;

            case 1:
                printf("\n====== TABELA GERAL - GRUPO %s ======\n", grupo);
                printf("--------------------------------------\n");
                printf("Equipe\tPTS | PJ | VIT | DER | SG | SP | SS\n");
                for (int e = 0; e < 4; e++)
                {
                    printf("%-10s %d | %d | %d | %d | %d | %d | %d\n", equipes[e], dados[e][0], dados[e][1], dados[e][2], dados[e][3], dados[e][4], dados[e][5], dados[e][6]);
                }
                printf("--------------------------------------------\n");
                printf("Legenda: SG = Sets Ganhos | SP = Sets Perdidos | SS = Saldo de Sets\n");
                break;

            case 2:
                printf("\n==== PONTUAÇÃO DAS EQUIPES ====\n");
                for (int e = 0; e < 4; e++)
                {
                    printf("%s: %d ponto(s)\n", equipes[e], dados[e][0]);
                }
                printf("--------------------------------------------\n");
                break;

            case 3:
                printf("\n==== RELATÓRIO DE SETS ====\n");
                for (int e = 0; e < 4; e++)
                {
                    printf("%s - SG: %d | SP: %d | SS: %d\n", equipes[e], dados[e][4], dados[e][5], dados[e][6]);
                }
                printf("--------------------------------------------\n");
                printf("Legenda: SG = Sets Ganhos | SP = Sets Perdidos | SS = Saldo de Sets\n");
                break;

            case 4:
                printf("\n==== EXIBIR RELATÓRIO POR EQUIPE ====\n");
                for (int e = 0; e < 4; e++)
                {
                    printf("%d - %s\n", e + 1, equipes[e]);
                }
                do
                {
                    printf("Sua escolha: ");
                    scanf("%d", &escolha);
                    limparBuffer();

                    if (escolha < 1 || escolha > 4)
                    {
                        printf("ERRO: Opção inválida!\n");
                    }
                } while (escolha < 1 || escolha > 4);

                switch (escolha)
                {
                case 1:
                    printf("Equipe\tPTS | PJ | VIT | DER | SG | SP | SS\n");
                    printf("%-10s %d | %d | %d | %d | %d | %d | %d\n", equipes[0], dados[0][0], dados[0][1], dados[0][2], dados[0][3], dados[0][4], dados[0][5], dados[0][6]);
                    break;

                case 2:
                    printf("Equipe\tPTS | PJ | VIT | DER | SG | SP | SS\n");
                    printf("%-10s %d | %d | %d | %d | %d | %d | %d\n", equipes[1], dados[1][0], dados[1][1], dados[1][2], dados[1][3], dados[1][4], dados[1][5], dados[1][6]);
                    break;

                case 3:
                    printf("Equipe\tPTS | PJ | VIT | DER | SG | SP | SS\n");
                    printf("%-10s %d | %d | %d | %d | %d | %d | %d\n", equipes[2], dados[2][0], dados[2][1], dados[2][2], dados[2][3], dados[2][4], dados[2][5], dados[2][6]);
                    break;

                case 4:
                    printf("Equipe\tPTS | PJ | VIT | DER | SG | SP | SS\n");
                    printf("%-10s %d | %d | %d | %d | %d | %d | %d\n", equipes[3], dados[3][0], dados[3][1], dados[3][2], dados[3][3], dados[3][4], dados[3][5], dados[3][6]);
                    break;

                default:
                    printf("ERRO: Opção inválida!\n");
                    break;
                }
                break;

            default:
                printf("ERRO: Opção inválida!\n");
                break;
            }
        } while (opcao != 0);

        do
        {
            printf("\nDeseja rodar o programa novamente?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            printf("Sua escolha: ");
            scanf("%d", &opcao_menu);
            limparBuffer();

            if (opcao_menu < 1 || opcao_menu > 2)
            {
                printf("ERRO: Opção inválida!\n");
            }

        } while (opcao_menu < 1 || opcao_menu > 2);
    } while (opcao_menu == 1);
}