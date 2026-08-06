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
    char nome_oficina[31];
    char CNPJ[16];
    char endereco[101];
    char servicos[5][40];
    float valorServico[5];
    float total_faturado = 0, maior, menor, ordens_registradas = 0;
    int opcao_principal, opcao_servico;
    int cadastro_concluido = 0;
    int qtd_servicos, continuar_ordem = 0;

    printf("\n===== SISTEMA DA OFICINA =====\n");
    printf("1 - Configurar dados da oficina\n");
    printf("2 - Registrar ordem de serviço\n");
    printf("3 - Relatórios\n");
    printf("0 - Sair\n");
    printf("Sua escolha: ");
    scanf("%d", &opcao_principal);
    limparBuffer();

    switch (opcao_principal)
    {
    case 0:
        printf("Saindo...\n");

        break;

    case 1:
        do
        {
            printf("Informe o nome da oficina: ");
            fgets(nome_oficina, sizeof(nome_oficina), stdin);
            nome_oficina[strcspn(nome_oficina, "\n")] = '\0';

            if (strlen(nome_oficina) == 0)
            {
                printf("ERRO: Nome da oficina não pode estar em branco!\n");
            }
        } while (strlen(nome_oficina) == 0);

        do
        {
            printf("Informe o CNPJ da oficina: ");
            fgets(CNPJ, sizeof(CNPJ), stdin);
            CNPJ[strcspn(CNPJ, "\n")] = '\0';

            if (strlen(CNPJ) == 0 || strlen(CNPJ) != 14)
            {
                printf("ERRO: CNPJ deve conter 14 dígitos!\n");
            }
        } while (strlen(CNPJ) == 0 || strlen(CNPJ) != 14);

        do
        {
            printf("Informe o endereço da oficina: ");
            fgets(endereco, sizeof(endereco), stdin);
            endereco[strcspn(endereco, "\n")] = '\0';

            if (strlen(endereco) == 0)
            {
                printf("ERRO: Endereço não pode estar em branco!\n");
            }
        } while (strlen(endereco) == 0);

        printf("Dados da oficina cadastrados com sucesso!\n");
        cadastro_concluido = 1;
        break;

    case 2:
        if (cadastro_concluido != 1)
        {
            printf("ERRO: Configure os dados da oficina antes de registrar uma ordem de serviço!\n");
            break;
        }
        do
        {
            printf("\n=== Registrar ordem de serviço ===\n");
            int s = 0;

            do
            {
                do
                {
                    printf("Informe o nome do %dº serviço: ", s + 1);
                    fgets(servicos[s], sizeof(servicos[s]), stdin);
                    servicos[s][strcspn(servicos[s], "\n")] = '\0';

                    if (strlen(servicos[s]) == 0)
                    {
                        printf("ERRO: Nome do serviço não pode estar em branco!\n");
                    }
                } while (strlen(servicos[s]) == 0);

                do
                {
                    printf("Informe o valor do %dº serviço: ", s + 1);
                    scanf("%f", &valorServico[s]);
                    limparBuffer();
                    if (valorServico[s] <= 0)
                    {
                        printf("ERRO: Valor do serviço não pode ser menor ou igual a zero.\n");
                    }
                } while (valorServico[s] <= 0);

                s++;

                if (s < 5)
                {
                    printf("Deseja inserir outro serviço? 1 - Sim | 0 - Não\n");
                    printf("Sua escolha: ");
                    scanf("%d", &opcao_servico);
                    limparBuffer();
                }
                if (s == 5)
                {
                    printf("Limite máximo de 5 serviços atingido para esta ordem.\n");
                    opcao_servico = 0;
                }
            } while (opcao_servico == 1 && s < 5);

            float total_ordem = 0;

            for (int i = 0; i < s; i++)
            {
                total_faturado += valorServico[i];
            }

            float desconto = 0;
            if (total_ordem > 300.0)
            {
                desconto = total_ordem * 0.05;
            }

            float total_final = total_ordem - desconto;
            total_faturado += total_final;
            ordens_registradas = ordens_registradas + 1;

            if (ordens_registradas == 1)
            {
                maior = total_final;
                menor = total_final;
            }
            else
            {
                // Compara com as ordens anteriores
                if (total_final > maior)
                {
                    maior = total_final;
                }
                if (total_final < menor)
                {
                    menor = total_final;
                }
            }
            /* PASSO 4: Emissão do Recibo */
            printf("\n========== ORDEM DE SERVIÇO ==========\n");
            printf("Oficina: %s\n", nome_oficina);
            printf("CNPJ: %s\n", CNPJ);
            printf("--------------------------------------\n");
            printf("%-30s %10s\n", "Serviço", "Valor");

            for (int i = 0; i < s; i++)
            {
                printf("%-30s %10.2f\n", servicos[i], valorServico[i]);
            }

            printf("--------------------------------------\n");
            printf("Total bruto: R$ %.2f\n", total_ordem);
            printf("Desconto (5%%): R$ %.2f\n", desconto);
            printf("TOTAL: R$ %.2f\n", total_final);
            printf("\nDeseja registrar outra ordem de serviço? 1 - Sim | 0 - Voltar ao menu principal\n");
            printf("Sua escolha: ");
            scanf("%d", &continuar_ordem);
            limparBuffer();

        } while (continuar_ordem == 1);
    }
}