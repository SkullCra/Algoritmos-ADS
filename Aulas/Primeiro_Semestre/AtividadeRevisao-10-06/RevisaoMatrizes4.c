#include <stdio.h>
#include <string.h>
#include <math.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n')
        ;
}

int main()
{
    int opcao, qtd_depositos, qtd_categorias, deposito[101][101];
    int total_categoria[101], total_deposito[101], limite, depositos_abaixo[101];
    int dados_lancados = 0, encontrou = 0, qtd_abaixo = 0;
    char distribuidora[51], CNPJ[15];

    do {
    printf("\n======== SISTEMA DE CONTROLE DE ESTOQUE ========\n");
    printf("Selecione uma opção abaixo.\n");
    printf("1 - Configurar Empresa e Estoque.\n");
    printf("2 - Gerar Relatório de Inventário.\n");
    printf("3 - Sair.\n");
    printf("Sua opção: ");
    scanf("%d", &opcao);

    limparBuffer();

    switch (opcao)
    {
    case 1:
    {
        printf("Informe o nome da Distribuidora: ");
        fgets(distribuidora, sizeof(distribuidora), stdin);
        distribuidora[strcspn(distribuidora, "\n")] = '\0';

        printf("Informe o CNPJ da Distribuidora: ");
        fgets(CNPJ, sizeof(CNPJ), stdin);
        CNPJ[strcspn(CNPJ, "\n")] = '\0';

        limparBuffer();

        printf("Informe a Quantidade de Depósitos: ");
        scanf("%d", &qtd_depositos);

        limparBuffer();

        printf("Informe a Quantidade de Categorias de Produtos: ");
        scanf("%d", &qtd_categorias);

        limparBuffer();

        printf("--- Insira os dados dos produtos ---\n");
        for (int l = 0; l < qtd_depositos; l++)
        {
            for (int c = 0; c < qtd_categorias; c++)
            {
                printf("Informe a quantidade de ítens da %dª categoria\npresente no depósito [%d]: ", c + 1, l + 1);
                scanf("%d", &deposito[l][c]);
            }
        }

        printf("Informe o Limite Mínimo dos produtos: ");
        scanf("%d", &limite);

        limparBuffer();

        dados_lancados = 1;
        printf("\nDados salvos com sucesso!\n");
        break;
    }

    case 2:
    {
        if (dados_lancados == 0)
        {
            printf("Você deve preencher os dados antes de exibir relatório.\n");
            break;
        }
        for (int l = 0; l < qtd_depositos; l++)
        {
            total_deposito[l] = 0;

            for (int c = 0; c < qtd_categorias; c++)
            {
                total_deposito[l] = total_deposito[l] + deposito[l][c];
            }
        }
        for (int c = 0; c < qtd_categorias; c++)
        {
            total_categoria[c] = 0;

            for (int l = 0; l < qtd_depositos; l++)
            {
                total_categoria[c] = total_categoria[c] + deposito[l][c];
            }
        }
        qtd_abaixo = 0;
        for (int l = 0; l < qtd_depositos; l++)
        {
            if (total_deposito[l] < limite)
            {
                depositos_abaixo[qtd_abaixo] = l + 1;
                qtd_abaixo = qtd_abaixo + 1;
            }
        }
        printf("\n---------------------------------------\n");
        printf("EMPRESA: %s\t| CNPJ: %s\n", distribuidora, CNPJ);
        printf("\n---------------------------------------\n");
        for (int l = 0; l < qtd_depositos; l++)
        {
            printf("Depósitdo %d: %d itens\n", l + 1, total_deposito[l]);
        }
        printf("\n---------------------------------------\n");

        for (int c = 0; c < qtd_categorias; c++) {
            printf("TOTAL CATEGORIA %d: %d itens\n", c + 1, total_categoria[c]);
        }
        printf("\n---------------------------------------\n");
        printf("DEPÓSITOS ABAIXO DO LIMITE (%d itens):\n", limite);
        if (qtd_abaixo == 0)
        {
            printf("Nenhum depósito abaixo do limite.\n");
        }
        else
        {
            for (int k = 0; k < qtd_abaixo; k++)
            {
                printf("Depósito %d\n", depositos_abaixo[k]);
            }
        }
        printf("\n---------------------------------------\n");
        break;
        }

    case 3:
    {
        printf("Saindo...\n");
        break;
    }

    default:
    {
        printf("Opção inválida!\n");
    }
    
    }
} while (opcao != 3);
}