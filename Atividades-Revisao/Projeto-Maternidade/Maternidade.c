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
    char setor[30];
    char enfermeiras[4][30];
    int dados[4][6];
    int escolha_parto, condicao, opcao;

    printf("\n#### MATERNIDADE MUNICIPAL ####\n");
    do
    {
        printf("Informe o nome do setor da maternidade: ");
        fgets(setor, sizeof(setor), stdin);
        setor[strcspn(setor, "\n")] = '\0';
        if (strlen(setor) == 0)
        {
            printf("ERRO: Nome do setor em branco.\n");
        }
    } while (strlen(setor) == 0);

    for (int e = 0; e < 4; e++)
    {
        do
        {
            printf("Informe o nome da %dª enfermeira: ", e + 1);
            fgets(enfermeiras[e], sizeof(enfermeiras[e]), stdin);
            enfermeiras[e][strcspn(enfermeiras[e], "\n")] = '\0';
            if (strlen(enfermeiras[e]) == 0)
            {
                printf("ERRO: Nome da enfermeira em branco.\n");
            }
        } while (strlen(enfermeiras[e]) == 0);
    }

    for (int e = 0; e < 4; e++)
    {
        for (int d = 0; d < 6; d++)
        {
            dados[e][d] = 0;
        }
    }

    for (int a = 0; a < 8; a++)
    {
        printf("\n--- ATENDIMENTO %d de 8 ---\n", a + 1);
        int opcao;
        do
        {
            printf("Escolha a enfermeia responsável:\n");
            for (int e = 0; e < 4; e++)
            {
                printf("%d - %s\n", e + 1, enfermeiras[e]);
            }
            printf("Sua escolha: ");
            scanf("%d", &opcao);
            limparBuffer();
            if (opcao < 1 || opcao > 4)
            {
                printf("OPÇÃO INVÁLIDA!\n");
            }
        } while (opcao < 1 || opcao > 4);

        switch (opcao)
        {
        case 1:
            do
            {
                printf("\nEnfermeira %s selecionada.\n", enfermeiras[0]);
                printf("Informe o tipo de parto:\n");
                printf("1 - Normal\n");
                printf("2 - Cesáreo\n");
                printf("Sua escolha: ");
                scanf("%d", &escolha_parto);
                limparBuffer();
                if (escolha_parto < 1 || escolha_parto > 2)
                {
                    printf("OPÇÃO INVÁLIDA!\n");
                }
            } while (escolha_parto < 1 || escolha_parto > 2);

            if (escolha_parto == 1)
            {
                dados[0][0]++;
                dados[0][1]++;
                dados[0][5] = dados[0][5] + 2;
            }
            if (escolha_parto == 2)
            {
                dados[0][0]++;
                dados[0][2]++;
                dados[0][5] = dados[0][5] + 3;
            }
            do
            {
                printf("\nInforme a condição do recém-nascido\n");
                printf("1 - Saudável\n");
                printf("2 - Em observação\n");
                printf("Sua escolha: ");
                scanf("%d", &condicao);
                limparBuffer();
                if (condicao < 1 || condicao > 2)
                {
                    printf("OPÇÃO INVÁLIDA!\n");
                }
            } while (condicao < 1 || condicao > 2);

            if (condicao == 1)
            {
                dados[0][3]++;
                dados[0][5] = dados[0][5] + 1;
            }
            if (condicao == 2)
            {
                dados[0][4]++;
                dados[0][5] = dados[0][5] + 0;
            }
            break;

        case 2:
            do
            {
                printf("\nEnfermeira %s selecionada.\n", enfermeiras[1]);
                printf("Informe o tipo de parto:\n");
                printf("1 - Normal\n");
                printf("2 - Cesáreo\n");
                printf("Sua escolha: ");
                scanf("%d", &escolha_parto);
                limparBuffer();
                if (escolha_parto < 1 || escolha_parto > 2)
                {
                    printf("OPÇÃO INVÁLIDA!\n");
                }
            } while (escolha_parto < 1 || escolha_parto > 2);

            if (escolha_parto == 1)
            {
                dados[1][0]++;
                dados[1][1]++;
                dados[1][5] = dados[1][5] + 2;
            }
            if (escolha_parto == 2)
            {
                dados[1][0]++;
                dados[1][2]++;
                dados[1][5] = dados[1][5] + 3;
            }
            do
            {
                printf("\nInforme a condição do recém-nascido\n");
                printf("1 - Saudável\n");
                printf("2 - Em observação\n");
                printf("Sua escolha: ");
                scanf("%d", &condicao);
                limparBuffer();
                if (condicao < 1 || condicao > 2)
                {
                    printf("OPÇÃO INVÁLIDA!\n");
                }
            } while (condicao < 1 || condicao > 2);

            if (condicao == 1)
            {
                dados[1][3]++;
                dados[1][5] = dados[1][5] + 1;
            }
            if (condicao == 2)
            {
                dados[1][4]++;
                dados[1][5] = dados[1][5] + 0;
            }
            break;
        case 3:
            do
            {
                printf("\nEnfermeira %s selecionada.\n", enfermeiras[2]);
                printf("Informe o tipo de parto:\n");
                printf("1 - Normal\n");
                printf("2 - Cesáreo\n");
                printf("Sua escolha: ");
                scanf("%d", &escolha_parto);
                limparBuffer();
                if (escolha_parto < 1 || escolha_parto > 2)
                {
                    printf("OPÇÃO INVÁLIDA!\n");
                }
            } while (escolha_parto < 1 || escolha_parto > 2);

            if (escolha_parto == 1)
            {
                dados[2][0]++;
                dados[2][1]++;
                dados[2][5] = dados[2][5] + 2;
            }
            if (escolha_parto == 2)
            {
                dados[2][0]++;
                dados[2][2]++;
                dados[2][5] = dados[2][5] + 3;
            }
            do
            {
                printf("\nInforme a condição do recém-nascido\n");
                printf("1 - Saudável\n");
                printf("2 - Em observação\n");
                printf("Sua escolha: ");
                scanf("%d", &condicao);
                limparBuffer();
                if (condicao < 1 || condicao > 2)
                {
                    printf("OPÇÃO INVÁLIDA!\n");
                }
            } while (condicao < 1 || condicao > 2);

            if (condicao == 1)
            {
                dados[2][3]++;
                dados[2][5] = dados[2][5] + 1;
            }
            if (condicao == 2)
            {
                dados[2][4]++;
                dados[2][5] = dados[2][5] + 0;
            }
            break;
        case 4:
            do
            {
                printf("\nEnfermeira %s selecionada.\n", enfermeiras[3]);
                printf("Informe o tipo de parto:\n");
                printf("1 - Normal\n");
                printf("2 - Cesáreo\n");
                printf("Sua escolha: ");
                scanf("%d", &escolha_parto);
                limparBuffer();
                if (escolha_parto < 1 || escolha_parto > 2)
                {
                    printf("OPÇÃO INVÁLIDA!\n");
                }
            } while (escolha_parto < 1 || escolha_parto > 2);

            if (escolha_parto == 1)
            {
                dados[3][0]++;
                dados[3][1]++;
                dados[3][5] = dados[3][5] + 2;
            }
            if (escolha_parto == 2)
            {
                dados[3][0]++;
                dados[3][2]++;
                dados[3][5] = dados[3][5] + 3;
            }
            do
            {
                printf("\nInforme a condição do recém-nascido\n");
                printf("1 - Saudável\n");
                printf("2 - Em observação\n");
                printf("Sua escolha: ");
                scanf("%d", &condicao);
                limparBuffer();
                if (condicao < 1 || condicao > 2)
                {
                    printf("OPÇÃO INVÁLIDA!\n");
                }
            } while (condicao < 1 || condicao > 2);

            if (condicao == 1)
            {
                dados[3][3]++;
                dados[3][5] = dados[3][5] + 1;
            }
            if (condicao == 2)
            {
                dados[3][4]++;
                dados[3][5] = dados[3][5] + 0;
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    do
    {
        printf("\n##### RELATÓRIO DO SETOR %s #####\n", setor);
        printf("1 - Exibir tabela geral\n");
        printf("2 - Exibir pontuação das enfermeiras\n");
        printf("3 - Exibir relatório de partos\n");
        printf("4 - Exibir resumo de uma enfermeira\n");
        printf("0 - Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);
        limparBuffer();
        if (opcao < 0 || opcao > 4)
        {
            printf("Opção inválida!\n");
        }
        switch (opcao)
        {
        case 0:
            printf ("Saindo...\n");
            break;
        case 1:
            printf("\n====== TABELA GERAL - MATERNIDADE SETOR %s ======\n", setor);
            printf("---------------------------------------------------\n");
            printf("[Enfermeira]\t[AT] [PN] [PC] [RS] [RO] [Pontos]\n");
            for (int e = 0; e < 4; e++)
            {
                printf("[%-10s][%d][%d][%d][%d][%d][%d]\n", enfermeiras[e], dados[e][0], dados[e][1], dados[e][2], dados[e][3], dados[e][4], dados[e][5]);
            }
            printf("---------------------------------------------------\n");
            printf("Legenda: AT = Atendimentos | PN = Partos Normais |\n");
            printf("PC = Partos Cesáreos | RS = Recém-Nascidos Saudáveis |\n");
            printf("RO = Recém-nascidos em Observação.\n");
            break;
        case 2:
            printf("\n====== PONTUAÇÃO DAS ENFERMEIRAS ======\n");
            for (int e = 0; e < 4; e++)
            {
                printf("%s: %d ponto(s)\n", enfermeiras[e], dados[e][5]);
            }
            printf("-----------------------------------------\n");
            break;
        case 3:
            printf("\n==== RELATÓRIO DE PARTOS ====\n");
            for (int e = 0; e < 4; e++)
            {
                printf("%s - Normais: %d | Cesáreos: %d | Total: %d\n", enfermeiras[e], dados[e][1], dados[e][2], dados[e][0]);
            }
            printf("--------------------------------\n");
            break;
        case 4:
            printf("\n==== RESUMO DE UMA ENFERMEIRA ====\n");
            do
            {
                printf("Selecione uma enfermeira abaixo:\n");
                for (int e = 0; e < 4; e++)
                {
                    printf("%d - %s\n", e + 1, enfermeiras[e]);
                }
                printf("Sua escolha: ");
                scanf("%d", &opcao);
                limparBuffer();

                if (opcao < 1 || opcao > 4)
                {
                    printf("Opção inválida!\n");
                }
            } while (opcao < 1 || opcao > 4);

            switch (opcao)
            {
            case 1:
                printf("\nEnfermeira %s selecionada.\n", enfermeiras[0]);
                printf("---------------------------------------------------\n");
                printf("[Enfermeira]\t[AT] [PN] [PC] [RS] [RO] [Pontos]\n");
                printf("[%-10s][%d][%d][%d][%d][%d][%d]\n", enfermeiras[0], dados[0][0], dados[0][1], dados[0][2], dados[0][3], dados[0][4], dados[0][5]);
                break;
            case 2:
                printf("\nEnfermeira %s selecionada.\n", enfermeiras[1]);
                printf("---------------------------------------------------\n");
                printf("[Enfermeira]\t[AT] [PN] [PC] [RS] [RO] [Pontos]\n");
                printf("[%-10s][%d][%d][%d][%d][%d][%d]\n", enfermeiras[1], dados[1][0], dados[1][1], dados[1][2], dados[1][3], dados[1][4], dados[1][5]);
                break;
            case 3:
                printf("\nEnfermeira %s selecionada.\n", enfermeiras[2]);
                printf("---------------------------------------------------\n");
                printf("[Enfermeira]\t[AT] [PN] [PC] [RS] [RO] [Pontos]\n");
                printf("[%-10s][%d][%d][%d][%d][%d][%d]\n", enfermeiras[2], dados[2][0], dados[2][1], dados[2][2], dados[2][3], dados[2][4], dados[2][5]);
                break;
            case 4:
                printf("\nEnfermeira %s selecionada.\n", enfermeiras[3]);
                printf("---------------------------------------------------\n");
                printf("[Enfermeira]\t[AT] [PN] [PC] [RS] [RO] [Pontos]\n");
                printf("[%-10s][%d][%d][%d][%d][%d][%d]\n", enfermeiras[3], dados[3][0], dados[3][1], dados[3][2], dados[3][3], dados[3][4], dados[3][5]);
                break;
            default:
                printf("Opção inválida!\n");
            }
        }
    } while (opcao != 0);
}