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
    char skatistas[4][30];
    float notas[4][5];
    int opcao, escolha;
    char opcao_final;
    int vencedor;

    do
    {
        printf("\n==== TONINHO FALCÃO PRO SKATER ====\n");
        printf("Hora de cadastrar os skatistas participantes!\n");
        for (int s = 0; s < 4; s++)
        {
            do
            {
                printf("Informe o nome do %dº Skatista: ", s + 1);
                fgets(skatistas[s], sizeof(skatistas[s]), stdin);
                skatistas[s][strcspn(skatistas[s], "\n")] = '\0';
                if (strlen(skatistas[s]) == 0)
                {
                    printf("ERRO: Nome do Skatistas não pode estar em branco!\n");
                }
            } while (strlen(skatistas[s]) == 0);
        }

        for (int s = 0; s < 4; s++)
        {
            for (int n = 0; n < 5; n++)
            {
                notas[s][n] = 0;
            }
        }

        printf("\nBora pras notas dos jurados!\n");
        for (int s = 0; s < 4; s++)
        {
            printf("\n--- Skatista: %s ---\n", skatistas[s]);
            for (int n = 0; n < 3; n++)
            {
                do
                {
                    printf("Nota da %dª Run: ", n + 1);
                    scanf("%f", &notas[s][n]);
                    limparBuffer();

                    if (notas[s][n] < 0 || (notas[s][n] > 10))
                    {
                        printf("Impossível bro!\n");
                        printf("A nota não pode ser menor que zero, ou maior que 10!\n");
                    }
                } while (notas[s][n] < 0 || (notas[s][n] > 10));
            }
        }

        for (int s = 0; s < 4; s++)
        {
            notas[s][3] = notas[s][0];
            for (int n = 1; n < 3; n++)
            {
                if (notas[s][n] > notas[s][3])
                {
                    notas[s][3] = notas[s][n];
                }
            }
        }
        for (int s = 0; s < 4; s++)
        {
            notas[s][4] = (notas[s][0] + notas[s][1] + notas[s][2]) / 3;
        }

        vencedor = 0;
        for (int s = 1; s < 4; s++)
        {
            if (notas[s][4] > notas[vencedor][4])
            {
                vencedor = s;
            }
        }

        do
        {
            do
            {
                printf("\n===== RELATÓRIOS DA ETAPA =====\n");
                printf("1 - Exibir tabela geral de notas\n");
                printf("2 - Exibir ranking por melhor nota\n");
                printf("3 - Exibir média dos skatistas\n");
                printf("4 - Exibir resumo de um skatista\n");
                printf("0 - Sair\n");
                printf("Informe a sua escolha: ");
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
                printf("\nSaindo...\n");
                break;

            case 1:
                printf("\n=============== NOTAS DA ETAPA ================\n");
                printf("-----------------------------------------------\n");
                printf("|Skatista|----------|Run 1|---|Run 2|---|Run 3|\n");
                for (int s = 0; s < 4; s++)
                {
                    printf("|%s|----------|%.2f|---|%.2f|---|%.2f|\n", skatistas[s], notas[s][0], notas[s][1], notas[s][2]);
                }
                printf("Vencedor: %s, com média %.2f\n", skatistas[vencedor], notas[vencedor][4]);
                printf("-----------------------------------------------\n");
                break;

            case 2:
                printf("\n==== MELHOR NOTA DE CADA SKATISTA ====\n");
                for (int s = 0; s < 4; s++)
                {
                    printf("%s: %.2f\n", skatistas[s], notas[s][3]);
                }
                break;

            case 3:
                printf("\n==== MÉDIA DE CADA SKATISTA ====\n");
                for (int s = 0; s < 4; s++)
                {
                    printf("%s: %.2f\n", skatistas[s], notas[s][4]);
                }
                break;

            case 4:
                printf("\n==== RESUMO POR SKATISTA ====\n");
                do
                {
                    printf("Selecione um Skatista para exibir seu resumo\n");
                    for (int s = 0; s < 4; s++)
                    {
                        printf("%d - %s\n", s + 1, skatistas[s]);
                    }
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
                    printf("\n==== RESUMO DO SKATISTA ====\n");
                    printf("Nome: %s\n", skatistas[0]);
                    for (int n = 0; n < 3; n++)
                    {
                        printf("Run %d: %.2f\n", n + 1, notas[0][n]);
                    }
                    printf("Melhor nota: %.2f\n", notas[0][3]);
                    printf("Média: %.2f\n", notas[0][4]);
                    break;

                case 2:
                    printf("\n==== RESUMO DO SKATISTA ====\n");
                    printf("Nome: %s\n", skatistas[1]);
                    for (int n = 0; n < 3; n++)
                    {
                        printf("Run %d: %.2f\n", n + 1, notas[1][n]);
                    }
                    printf("Melhor nota: %.2f\n", notas[1][3]);
                    printf("Média: %.2f\n", notas[1][4]);
                    break;

                case 3:
                    printf("\n==== RESUMO DO SKATISTA ====\n");
                    printf("Nome: %s\n", skatistas[2]);
                    for (int n = 0; n < 3; n++)
                    {
                        printf("Run %d: %.2f\n", n + 1, notas[2][n]);
                    }
                    printf("Melhor nota: %.2f\n", notas[2][3]);
                    printf("Média: %.2f\n", notas[2][4]);
                    break;

                case 4:
                    printf("\n==== RESUMO DO SKATISTA ====\n");
                    printf("Nome: %s\n", skatistas[3]);
                    for (int n = 0; n < 3; n++)
                    {
                        printf("Run %d: %.2f\n", n + 1, notas[3][n]);
                    }
                    printf("Melhor nota: %.2f\n", notas[3][3]);
                    printf("Média: %.2f\n", notas[3][4]);
                    break;

                default:
                    printf("\nERRO: Opção inválida!\n");
                    break;
                }

                break;
            default:
                printf("\nERRO: Opção inválida!\n");
                break;
            }
        } while (opcao != 0);
        do
        {
            printf("\nDeseja realizar uma nova competição?(S/N)\n");
            printf("Sua escolha: ");
            scanf(" %c", &opcao_final);
            limparBuffer();
            if (opcao_final != 's' && opcao_final != 'S' && opcao_final != 'n' && opcao_final != 'N')
            {
                printf("ERRO: Opção inválida!\n");
            }
        } while (opcao_final != 's' && opcao_final != 'S' && opcao_final != 'n' && opcao_final != 'N');

    } while (opcao_final == 's' || opcao_final == 'S');

    return 0;
}