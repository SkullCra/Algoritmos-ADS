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
    char ingressos[4][30];
    float preco_ingresso[4];
    float dados[4][2];
    int opcao_ingresso, ingressos_cadastrados = 0, opcao_relatorio;
    int indice_ingresso, quantidade_vendida = 0, vendas_registradas = 0;
    int indice_mais_vendido;
    int mais_vendido;
    int opcao_resumo;

    printf("\n==== MOVIE ARTE CINEMAS VERANOPOLIS ====\n");
    printf("Realize o cadastro dos ingressos disponíveis abaixo:\n");
    ingressos_cadastrados = 0;
    for (int i = 0; i < 4; i++)
    {

        do
        {
            printf("Nome do %dº ingresso: ", i + 1);
            fgets(ingressos[i], sizeof(ingressos[i]), stdin);
            ingressos[i][strcspn(ingressos[i], "\n")] = '\0';

            if (strlen (ingressos[i]) == 0)
            {
                printf("ERRO: Nome do ingresso não pode estar em branco!\n");
            }
        } while (strlen (ingressos[i]) == 0);

        do
        {
            printf("Preço do %dº ingresso: R$ ", i + 1);
            scanf("%f", &preco_ingresso[i]);
            limparBuffer();
            if (preco_ingresso[i] <= 0)
            {
                printf("ERRO: Preço do ingresso deve ser positivo!\n");
            }
        } while (preco_ingresso[i] <= 0);

        printf("\n");
    }
    printf("\nIngressos cadastrados!\n");
    ingressos_cadastrados = 1;

    for (int i = 0; i < 4; i++)
    {
        for (int d = 0; d < 2; d++)
        {
            dados[i][d] = 0;
        }
    }

    vendas_registradas = 0;
    for (int v = 0; v < 12; v++)
    {
        do
        {
            printf("\n===== VENDA %d de 12 =====\n", v + 1);
            for (int i = 0; i < 4; i++)
            {
                printf("%d - %s\n", i + 1, ingressos[i]);
            }
            printf("Escolha uma opção: ");
            scanf("%d", &opcao_ingresso);
            limparBuffer();

            if (opcao_ingresso < 1 || opcao_ingresso > 4)
            {
                printf("ERRO: Opção inválida!\n");
            }
        } while (opcao_ingresso < 1 || opcao_ingresso > 4);

        indice_ingresso = (opcao_ingresso - 1);

        do
        {
            printf("Informe a quantidade vendida: ");
            scanf("%d", &quantidade_vendida);
            limparBuffer();

            if (quantidade_vendida <= 0)
            {
                printf("ERRO: Deve haver ao menos 1 ingresso vendido!\n");
            }
        } while (quantidade_vendida <= 0);

        dados[indice_ingresso][0] = dados[indice_ingresso][0] + quantidade_vendida;
        dados[indice_ingresso][1] = dados[indice_ingresso][1] + (preco_ingresso[indice_ingresso] * quantidade_vendida);
    }
    printf("Todas as vendas registradas!\n");
    vendas_registradas = 1;

    do
    {
        do
        {
            printf("\n===== RELATÓRIOS DA SESSÃO =====\n");
            printf("1 - Exibir tabela geral\n");
            printf("2 - Exibir ticket médio por tipo\n");
            printf("3 - Exibir tipo mais vendido\n");
            printf("4 - Exibir resumo de um tipo\n");
            printf("0 - Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao_relatorio);
            limparBuffer();

            if (opcao_relatorio < 0 || opcao_relatorio > 4)
            {
                printf("ERRO: Opção inválida!\n");
            }
        } while (opcao_relatorio < 0 || opcao_relatorio > 4);

        switch (opcao_relatorio)
        {
        case 0:
            printf("Saindo...\n");
            break;

        case 1:
            printf("\n====== TABELA GERAL ======\n");
            printf("[TIPO DE INGRESSO] | [QTD VENDIDA] | [FATURAMENTO TOTAL]\n");
            for (int i = 0; i < 4; i++)
            {
                printf("[%d - %s] | [%.2f] | [R$ %.2f]\n", i + 1, ingressos[i], dados[i][0], dados[i][1]);
            }
            break;

        case 2:
            printf("\n===== TICKET MÉDIO POR TIPO =====\n");
            for (int i = 0; i < 4; i++)
            {
                if (dados[i][0] > 0)
                {
                    float ticket_medio = dados[i][1] / dados[i][0];
                    printf("%d - %s: R$ %.2f.\n", i + 1, ingressos[i], ticket_medio);
                }
                else
                {
                    printf("%s: Nenhum ingresso vendido deste tipo.\n", ingressos[i]);
                }
            }
            break;

        case 3:
            indice_mais_vendido = 0;
            mais_vendido = dados[0][0];

            for (int i = 1; i < 4; i++)
            {
                if (dados[i][0] > mais_vendido)
                {
                    mais_vendido = dados[i][0];
                    indice_mais_vendido = i;
                }
            }
            printf("\n==== INGRESSO MAIS VENDIDO ====\n");
            printf("Tipo: %d - %s.\n", indice_mais_vendido + 1, ingressos[indice_mais_vendido]);
            printf("Quantidade: %.2f\n", dados[indice_mais_vendido][0]);
            break;

        case 4:
            indice_ingresso = 0;
            do
            {
                printf("\n===== RESUMO POR TIPO DE INGRESSO =====\n");
                printf("Selecione um tipo de ingresso abaixo:\n");
                for (int i = 0; i < 4; i++)
                {
                    printf("%d - %s\n", i + 1, ingressos[i]);
                }
                printf("Escolha uma opção: ");
                scanf("%d", &opcao_resumo);
                limparBuffer();
                indice_ingresso = (opcao_resumo - 1);

                if (opcao_resumo < 1 || opcao_resumo > 4)
                {
                    printf("ERRO: Opção inválida!\n");
                }
            } while (opcao_resumo < 1 || opcao_resumo > 4);

            printf("Nome do ingresso: %s.\n", ingressos[indice_ingresso]);
            printf("Preço do ingresso: R$ %.2f.\n", preco_ingresso[indice_ingresso]);
            printf("Quantidade vendida: %.2f.\n", dados[indice_ingresso][0]);
            printf("Faturamento total: R$ %.2f.\n", dados[indice_ingresso][1]);
            break;

        default:
            printf("ERRO: Opção inválida!\n");
            break;
        }
    } while (opcao_relatorio != 0);

    return 0;
}