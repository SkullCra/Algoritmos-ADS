#include <stdio.h>
#include <math.h>
#include <string.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n')
        ;
}

int main()
{
    int opcao, filial;
    float vendas_diarias[10][7], total_vendas = 0;
    char razao_social[120], CNPJ[15];

    printf("=========================================\n");
    printf("SISTEMA DE ANÁLISE DE VENDAS - RETAILCORP\n");
    printf("=========================================\n");
    do
    {
        printf("Selecione um opcao abaixo\n");
        printf("1 - Configurar Empresa e Cadastrar Vendas\n");
        printf("2 - Gerar Relatório de Desempenho\n");
        printf("3 - Sair\n");
        printf("Sua opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
        {
            do
            {
                printf("Informe a Razão Social da empresa: ");
                fgets(razao_social, sizeof(razao_social), stdin);
                razao_social[strcspn(razao_social, "\n")] = '\0';
                if (strlen(razao_social) <= 0)
                {
                    printf("Erro: A razão social não pode ser deixada em branco.\n");
                }
            } while (strlen(razao_social) <= 0);

            do
            {
                printf("Informe o CNPJ da empresa: ");
                fgets(CNPJ, sizeof(CNPJ), stdin);
                CNPJ[strcspn(CNPJ, "\n")] = '\0';
                if (strlen(CNPJ) < 14 || strlen(CNPJ) > 14)
                {
                    printf("Erro: O CNPJ deve possuir 14 dígitos!\n");
                }
            } while (strlen(CNPJ) < 14 || strlen(CNPJ) > 14);

            do
            {
                printf("Informe a quantidade de filiais a serem cadastradas (1 a 10): ");
                scanf("%d", &filial);
                if (filial < 1 || filial > 10)
                {
                    printf("Erro: O número de filiais deve ser de 1 a 10.\n");
                }
            } while (filial < 1 || filial > 10);

            for (int l = 0; l < filial; l++)
            {
                for (int c = 0; c < 7; c++)
                {
                    do
                    {
                        printf("Informe as vendas diárias do %dº dia da Filial %d: ", c + 1, l + 1);
                        scanf("%f", &vendas_diarias[l][c]);
                        if (vendas_diarias[l][c] < 0)
                        {
                            printf("ERRO: Valor de vendas negativo.\n");
                        }
                    } while (vendas_diarias[l][c] < 0);
                }
            }
            printf("\nDados cadastrados com sucesso!\n");
        }
        break;

        case 2:
        {
            printf("\n-------------- RELATÓRIO --------------\n");
            printf("\n---------------------------------------\n");
            printf("EMPRESA: %s\n", razao_social);
            printf("CNPJ: %s\n", CNPJ);
            printf("\n---------------------------------------\n");
            for (int l = 0; l < filial; l++) {
                total_vendas = 0;
               
                for (int c = 0; c < 7; c++) {
                    total_vendas = total_vendas + vendas_diarias[l][c];
                }
                printf("Filial %d\t TOTAL: %.2f\n", l + 1, total_vendas);
            }
            for 

            break;

        case 3:
        {
            printf("Saindo...\n");
            return 0;
        }

        break;

        default:
        {
            printf("Opção inválida!\n");
        }
        }
        }
        
    } while (opcao != 3);
}