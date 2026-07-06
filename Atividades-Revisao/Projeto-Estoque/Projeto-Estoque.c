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
    char produtos[4][30];
    float preco_custo[4];
    float preco_venda[4];
    float dados[4][4];
    int opcao, escolha, opcao_menu;

    printf("\n==== SISTEMAS LOJAS BENOIT ====\n");
    printf("Cadastramento de produtos:\n");
    for (int p = 0; p < 4; p++)
    {
        do
        {
            printf("Produto %d: ", p + 1);
            printf("\nNome: ");
            fgets(produtos[p], sizeof(produtos[p]), stdin);
            produtos[p][strcspn(produtos[p], "\n")] = '\0';
            if (strlen(produtos[p]) == 0)
            {
                printf("ERRO: Nome do produto não pode estar em branco!\n");
            }
        } while (strlen(produtos[p]) == 0);
        do
        {
            printf("Preço de custo: ");
            scanf("%f", &preco_custo[p]);
            limparBuffer();
            if (preco_custo[p] == 0)
            {
                printf("ERRO: Preço de custo não pode ser zero!\n");
            }
        } while (preco_custo[p] == 0);

        do
        {
            printf("Preço de venda: ");
            scanf("%f", &preco_venda[p]);
            limparBuffer();
            if (preco_venda[p] == 0)
            {
                printf("ERRO: Preço de custo não pode ser zero!\n");
            }
        } while (preco_venda[p] == 0);
    }

    for (int p = 0; p < 4; p++)
    {
        for (int d = 0; d < 4; d++)
        {
            dados[p][d] = 0;
        }
    }

    for (int v = 0; v < 10; v++)
    {
        do
        {
            printf("=== Venda %d de 10 ===\n", v + 1);
            for (int p = 0; p < 4; p++)
            {
                printf("%d - %s\n", p + 1, produtos[p]);
            }
            printf("Sua venda: ");
            scanf("%d", &opcao);
            limparBuffer();

            if (opcao < 1 || opcao > 4)
            {
                printf("ERRO: Opção inválida!\n");
            }
        } while (opcao < 1 || opcao > 4);

        if (opcao == 1)
        {
            printf("\n");
            printf("Quantidade vendida: ");
            int quantidade;
            scanf("%d", &quantidade);

            dados[0][0] = dados[0][0] + 1;
            dados[0][1] = dados[0][1] + ((quantidade)*preco_venda[0]);
            dados[0][2] = dados[0][2] + ((quantidade)*preco_custo[0]);
            dados[0][3] = dados[0][3] + ((dados[0][1]) - (dados[0][2]));
        }

        if (opcao == 2)
        {
            printf("\n");
            printf("Quantidade vendida: ");
            int quantidade;
            scanf("%d", &quantidade);

            dados[1][0] = dados[1][0] + 1;
            dados[1][1] = dados[1][1] + ((quantidade)*preco_venda[1]);
            dados[1][2] = dados[1][2] + ((quantidade)*preco_custo[1]);
            dados[1][3] = dados[1][3] + ((dados[1][1]) - (dados[1][2]));
        }

        if (opcao == 3)
        {
            printf("\n");
            printf("Quantidade vendida: ");
            int quantidade;
            scanf("%d", &quantidade);

            dados[2][0] = dados[2][0] + 1;
            dados[2][1] = dados[2][1] + ((quantidade)*preco_venda[2]);
            dados[2][2] = dados[2][2] + ((quantidade)*preco_custo[2]);
            dados[2][3] = dados[2][3] + ((dados[2][1]) - (dados[2][2]));
        }

        if (opcao == 4)
        {
            printf("\n");
            printf("Quantidade vendida: ");
            int quantidade;
            scanf("%d", &quantidade);

            dados[3][0] = dados[3][0] + 1;
            dados[3][1] = dados[3][1] + ((quantidade)*preco_venda[3]);
            dados[3][2] = dados[3][2] + ((quantidade)*preco_custo[3]);
            dados[3][3] = dados[3][3] + ((dados[3][1]) - (dados[3][2]));
        }
    }

    do
    {
        printf("==== RELATÓRIOS DE VENDAS ====\n");
        printf("1 - Exibir tabela geral\n");
        printf("2 - Exibir faturamento dos protudos\n");
        printf("3 - Exibir relatório de lucro\n");
        printf("4 - Exibir resumo de um produto\n");
        printf("0 - Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao_menu);
        limparBuffer();

        if (opcao_menu < 0 || opcao_menu > 4)
        {
            printf("ERRO: Opção inválida!\n");
        }
    } while (opcao_menu < 0 || opcao_menu > 4);

    switch (opcao_menu)
    {
    case 0:
        printf("\n");
        printf("Saindo...\n");
        break;

    case 1:
        printf("\n====== TABELA GERAL DE VENDAS ======\n");
        printf("Produto\tQtd | Faturamento | Custo | Lucro\n");
        for (int p = 0; p < 4; p++)
        {
            printf("%-10s %.6f | %.2f | %.2f | %.2f\n", produtos[p], dados[p][0], dados[p][1], dados[p][2], dados[p][3]);
        }
        break;

    case 2:
        printf("\n==== FATURAMENTO DOS PRODUTOS ====\n");
        for (int p = 0; p < 4; p++)
        {
            printf("%s: R$ %.2f\n", produtos[p], dados[p][1]);
        }
        break;

    case 3:
        printf("\n==== RELATÓRIO DE LUCRO ====\n");
        for (int p = 0; p < 4; p++)
        {
            printf("%s - Faturamento: R$ %.2f | Custo: R$ %.2f | Lucro: R$ %.2f\n", produtos[p], dados[p][1], dados[p][2], dados[p][3]);
        }
        break;
    }
}