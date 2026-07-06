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
    char bicicletas[4][30];
    float valor_hora[4];
    float dados[4][4];
    int opcao_modelo, opcao_relatorio, opcao_individual;
    int horas_usadas;
    float faturamento_bruto, desconto_condecido, faturamento_liquido;
    float maior_modelo;

    printf("\n===== SISTEMA CALOI BICICLETAS =====\n");
    printf("Registre os valores e os modelos disponíveis para locação:\n");
    for (int b = 0; b < 4; b++)
    {
        do
        {
            printf("Informe o nome do %d modelo: ", b + 1);
            fgets(bicicletas[b], sizeof(bicicletas[b]), stdin);
            bicicletas[b][strcspn(bicicletas[b], "\n")] = '\0';
            if (strlen(bicicletas[b]) == 0)
            {
                printf("ERRO: Nome do modelo em branco!\n");
            }
        } while (strlen(bicicletas[b]) == 0);

        do
        {
            printf("Informe o valor por hora: ");
            scanf("%f", &valor_hora[b]);
            limparBuffer();

            if (valor_hora[b] <= 0)
            {
                printf("ERRO: Valor não pode ser zero, ou menor que zero.\n");
            }
        } while (valor_hora[b] <= 0);
    }

    for (int b = 0; b < 4; b++)
    {
        for (int d = 0; d < 4; d++)
        {
            dados[b][d] = 0;
        }
    }

    for (int l = 0; l < 8; l++)
    {
        do
        {
            printf("\n--- Locação %d de 8 ---\n", l + 1);
            for (int b = 0; b < 4; b++)
            {
                printf("%d - %s\n", b + 1, bicicletas[b]);
            }
            printf("Escolha um modelo: ");
            scanf("%d", &opcao_modelo);
            limparBuffer();

            if (opcao_modelo < 1 || opcao_modelo > 4)
            {
                printf("ERRO: Modelo inválido!\n");
            }
        } while (opcao_modelo < 1 || opcao_modelo > 4);

        do
        {
            printf("Horas uso: ");
            scanf("%d", &horas_usadas);
            limparBuffer();

            if (horas_usadas <= 0)
            {
                printf("ERRO: Tempo inválido!\n");
            }
        } while (horas_usadas <= 0);

        switch (opcao_modelo)
        {
        case 1:
            faturamento_bruto = (horas_usadas * valor_hora[0]);
            if (horas_usadas > 5)
            {
                desconto_condecido = faturamento_bruto * 0.10;
            }
            if (horas_usadas <= 5)
            {
                desconto_condecido = 0;
            }
            dados[0][0] = dados[0][0] + horas_usadas;
            dados[0][1] = dados[0][1] + faturamento_bruto;
            dados[0][2] = dados[0][2] + desconto_condecido;
            dados[0][3] = dados[0][3] + (faturamento_bruto - desconto_condecido);
            break;

        case 2:
            faturamento_bruto = (horas_usadas * valor_hora[1]);
            if (horas_usadas > 5)
            {
                desconto_condecido = faturamento_bruto * 0.10;
            }
            if (horas_usadas <= 5)
            {
                desconto_condecido = 0;
            }
            dados[1][0] = dados[1][0] + horas_usadas;
            dados[1][1] = dados[1][1] + faturamento_bruto;
            dados[1][2] = dados[1][2] + desconto_condecido;
            dados[1][3] = dados[1][3] + (faturamento_bruto - desconto_condecido);
            break;

        case 3:
            faturamento_bruto = (horas_usadas * valor_hora[2]);
            if (horas_usadas > 5)
            {
                desconto_condecido = faturamento_bruto * 0.10;
            }
            if (horas_usadas <= 5)
            {
                desconto_condecido = 0;
            }
            dados[2][0] = dados[2][0] + horas_usadas;
            dados[2][1] = dados[2][1] + faturamento_bruto;
            dados[2][2] = dados[2][2] + desconto_condecido;
            dados[2][3] = dados[2][3] + (faturamento_bruto - desconto_condecido);
            break;

        case 4:
            faturamento_bruto = (horas_usadas * valor_hora[3]);
            if (horas_usadas > 5)
            {
                desconto_condecido = faturamento_bruto * 0.10;
            }
            if (horas_usadas <= 5)
            {
                desconto_condecido = 0;
            }
            dados[3][0] = dados[3][0] + horas_usadas;
            dados[3][1] = dados[3][1] + faturamento_bruto;
            dados[3][2] = dados[3][2] + desconto_condecido;
            dados[3][3] = dados[3][3] + (faturamento_bruto - desconto_condecido);
            break;

        default:
            printf("ERRO: Modelo inválido!\n");
            break;
        }
    }

    do
    {
        do
        {
            printf("\n==== RELATÓRIOS DA LOCADORA ====\n");
            printf("1 - Exibir tabela geral\n");
            printf("2 - Exibir faturamento líquido por modelo\n");
            printf("3 - Exibir modelo com mais horas alugadas\n");
            printf("4 - Exibir resumo de um modelo\n");
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
            printf("\n-------------------------------\n");
            printf("Modelo | Horas Alugadas | Fat. Bruto | Desc. Aplicados | Fat. Líquido\n");
            for (int b = 0; b < 4; b++)
            {
                printf("%d - %s | %.2f | %.2f | %.2f | %.2f\n", b + 1, bicicletas[b], dados[b][0], dados[b][1], dados[b][2], dados[b][3]);
            }
            printf("\n-------------------------------\n");
            break;

        case 2:
            for (int b = 0; b < 4; b++)
            {
                printf("Modelo: %s | Faturamento Líquido: %.2f\n", bicicletas[b], dados[b][3]);
            }
            break;

        case 3:
            maior_modelo = dados[0][0];
            int indice_maior = 0;
            for (int b = 1; b < 4; b++)
            {
                if (dados[b][0] > maior_modelo)
                {
                    maior_modelo = dados[b][0];
                    indice_maior = b;
                }
            }
            printf("O modelo mais alugado foi %d - %s.\n", indice_maior + 1, bicicletas[indice_maior]);
            break;

        case 4:
            do
            {
                printf("\n==== RESUMO POR MODELO ====\n");
                for (int b = 0; b < 4; b++)
                {
                    printf("%d - %s\n", b + 1, bicicletas[b]);
                }
                printf("Escolha uma opção: ");
                scanf("%d", &opcao_individual);
                limparBuffer();

                if (opcao_individual < 1 || opcao_individual > 4)
                {
                    printf("ERRO: Opção inválida!\n");
                }
            } while (opcao_individual < 1 || opcao_individual > 4);

            switch (opcao_individual)
            {
            case 1:
                printf("Nome: %s\n", bicicletas[0]);
                printf("Valor da hora: %.2f\n", valor_hora[0]);
                printf("Horas alugadas: %.2f\n", dados[0][0]);
                printf("Faturamento Bruto: %.2f\n", dados[0][1]);
                printf("Descontos Aplicados: %.2f\n", dados[0][2]);
                printf("Faturamento Líquido: %.2f\n", dados[0][3]);
                break;

            case 2:
                printf("Nome: %s\n", bicicletas[1]);
                printf("Valor da hora: %.2f\n", valor_hora[1]);
                printf("Horas alugadas: %.2f\n", dados[1][0]);
                printf("Faturamento Bruto: %.2f\n", dados[1][1]);
                printf("Descontos Aplicados: %.2f\n", dados[1][2]);
                printf("Faturamento Líquido: %.2f\n", dados[1][3]);
                break;

            case 3:
                printf("Nome: %s\n", bicicletas[2]);
                printf("Valor da hora: %.2f\n", valor_hora[2]);
                printf("Horas alugadas: %.2f\n", dados[2][0]);
                printf("Faturamento Bruto: %.2f\n", dados[2][1]);
                printf("Descontos Aplicados: %.2f\n", dados[2][2]);
                printf("Faturamento Líquido: %.2f\n", dados[2][3]);
                break;

            case 4:
                printf("Nome: %s\n", bicicletas[3]);
                printf("Valor da hora: %.2f\n", valor_hora[3]);
                printf("Horas alugadas: %.2f\n", dados[3][0]);
                printf("Faturamento Bruto: %.2f\n", dados[3][1]);
                printf("Descontos Aplicados: %.2f\n", dados[3][2]);
                printf("Faturamento Líquido: %.2f\n", dados[3][3]);
                break;

            default:
                printf("ERRO: Opção inválida!\n");
                break;
            }
        }
    } while (opcao_relatorio != 0);

    return 0;
}