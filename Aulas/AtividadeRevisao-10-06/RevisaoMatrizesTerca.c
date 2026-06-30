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
    int opcao;
    char razao_social[201], CNPJ[15], rua[101], numero[11], bairro[56];
    char cidade[101], estado[101], CEP[9], mes_ref[3], cliente[101];
    char CPF[12], plano[51], opcao_2;
    float valor_mensal, consumo_real, franquia, gb_exc, extra, total_cobrado;

    do
    {
        printf("\n### SISTEMA DE FATURAMENTO - WILLNET TELECOM ###\n");
        printf("\tSelecione uma opção abaixo.\n");
        printf("1 - Configurar dados da empresa.\n");
        printf("2 - Calcular fatura do cliente.\n");
        printf("3 - Sair.\n");
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
                if (strlen(razao_social) == 0)
                {
                    printf("ERRO: RAZÃO SOCIAL EM BRANCO.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
            } while (strlen(razao_social) == 0);

            do
            {
                printf("Informe o CNPJ da empresa: ");
                fgets(CNPJ, sizeof(CNPJ), stdin);
                CNPJ[strcspn(CNPJ, "\n")] = '\0';
                if (strlen(CNPJ) == 0)
                {
                    printf("ERRO: CNPJ EM BRANCO.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
                else if (strlen(CNPJ) > 0 && strlen(CNPJ) < 14 || strlen(CNPJ) > 14)
                {
                    printf("ERRO: CNPJ PRECISA CONTER 14 DÍGITOS.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
            } while (strlen(CNPJ) == 0 || strlen(CNPJ) > 0 && strlen(CNPJ) < 14 || strlen(CNPJ) > 14);

            limparBuffer();

            printf("Informe o endereço de forma individual abaixo:\n");
            do
            {
                printf("Rua: ");
                fgets(rua, sizeof(rua), stdin);
                rua[strcspn(rua, "\n")] = '\0';
                if (strlen(rua) == 0)
                {
                    printf("ERRO: RUA EM BRANCO.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
            } while (strlen(rua) == 0);

            do
            {
                printf("Número: ");
                fgets(numero, sizeof(numero), stdin);
                numero[strcspn(numero, "\n")] = '\0';
                if (strlen(numero) == 0)
                {
                    printf("ERRO: NÚMERO EM BRANCO.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
            } while (strlen(numero) == 0);

            do
            {
                printf("Bairro: ");
                fgets(bairro, sizeof(bairro), stdin);
                bairro[strcspn(bairro, "\n")] = '\0';
                if (strlen(bairro) == 0)
                {
                    printf("ERRO: BAIRRO EM BRANCO.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
            } while (strlen(bairro) == 0);

            do
            {
                printf("Cidade: ");
                fgets(cidade, sizeof(cidade), stdin);
                cidade[strcspn(cidade, "\n")] = '\0';
                if (strlen(cidade) == 0)
                {
                    printf("ERRO: CIDADE EM BRANCO.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
            } while (strlen(cidade) == 0);

            do
            {
                printf("Estado: ");
                fgets(estado, sizeof(estado), stdin);
                estado[strcspn(estado, "\n")] = '\0';
                if (strlen(estado) == 0)
                {
                    printf("ERRO: ESTADO EM BRANCO.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
            } while (strlen(estado) == 0);

            do
            {
                printf("CEP(apenas números): ");
                fgets(CEP, sizeof(CEP), stdin);
                CEP[strcspn(CEP, "\n")] = '\0';
                if (strlen(CEP) == 0)
                {
                    printf("ERRO: CEP EM BRANCO.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
                else if (strlen(CEP) > 0 && strlen(CEP) < 8 || strlen(CEP) > 8)
                {
                    printf("ERRO: CEP DEVE POSSUIR 8 DÍGITOS.\n");
                    printf("Por favor, preencha os dados corretamente.\n");
                }
            } while (strlen(estado) == 0 || strlen(CEP) > 0 && strlen(CEP) < 8 || strlen(CEP) > 8);

            limparBuffer();
        }
        break;

        case 2:
        {
            do
            {
                do
                {
                    printf("Informe o Mês de Referência(1 a 12): ");
                    fgets(mes_ref, sizeof(mes_ref), stdin);
                    mes_ref[strcspn(mes_ref, "\n")] = '\0';
                    if (strlen(mes_ref) == 0)
                    {
                        printf("ERRO: MÊS DE REFERÊNCIA EM BRANCO.\n");
                        printf("Por favor, preencha os dados corretamente.\n");
                    }
                } while (strlen(mes_ref) == 0);

                limparBuffer();

                do
                {
                    printf("Informe o nome do cliente: ");
                    fgets(cliente, sizeof(cliente), stdin);
                    cliente[strcspn(cliente, "\n")] = '\0';
                    if (strlen(cliente) == 0)
                    {
                        printf("ERRO: NOME DO CLIENTE EM BRANCO.\n");
                        printf("Por favor, preencha os dados corretamente.\n");
                    }
                } while (strlen(cliente) == 0);

                do
                {
                    printf("Informe o CPF do cliente: ");
                    fgets(CPF, sizeof(CPF), stdin);
                    CPF[strcspn(CPF, "\n")] = '\0';
                    if (strlen(CPF) == 0)
                    {
                        printf("ERRO: CPF DO CLIENTE EM BRANCO.\n");
                        printf("Por favor, preencha os dados corretamente.\n");
                    }

                    else if (strlen(CPF) > 0 && strlen(CPF) < 11 || strlen(CPF) > 11)
                    {
                        printf("ERRO: CPF DEVE POSSUIR 11 DÍGITOS!\n");
                        printf("Por favor, preencha os dados corretamente.\n");
                    }
                } while (strlen(CPF) == 0 || strlen(CPF) > 0 && strlen(CPF) < 11 || strlen(CPF) > 11);

                limparBuffer();

                do
                {
                    printf("Informe o Plano contratado: ");
                    fgets(plano, sizeof(plano), stdin);
                    plano[strcspn(plano, "\n")] = '\0';
                    if (strlen(plano) == 0)
                    {
                        printf("ERRO: PLANO EM BRANCO.\n");
                        printf("Por favor, preencha os dados corretamente.\n");
                    }
                } while (strlen(plano) == 0);

                do
                {
                    printf("Informe a franquia de dados do plano em GB: ");
                    scanf("%f", &franquia);
                    if (franquia <= 0)
                    {
                        printf("ERRO: GB DA FRANQUIA DEVE SER POSITIVO!\n");
                        printf("Por favor, preencha os dados corretamente.\n");
                    }
                } while (franquia <= 0);

                limparBuffer();

                do
                {
                    printf("Informe o consumo real do mês (em GB): ");
                    scanf("%f", &consumo_real);
                    if (consumo_real <= 0)
                    {
                        printf("ERRO: CONSUMO DEVE SER ACIMA DE 0.\n");
                        printf("Por favor, preencha os dados corretamente.\n");
                    }
                } while (consumo_real <= 0);

                limparBuffer();

                do
                {
                    printf("Informe o valor mensal do plano: ");
                    scanf("%f", &valor_mensal);
                    if (valor_mensal <= 0)
                    {
                        printf("ERRO: VALOR DEVE SER MAIOR QUE ZERO.\n");
                        printf("Por favor, preencha os dados corretamente.\n");
                    }
                } while (valor_mensal <= 0);

                limparBuffer();

                gb_exc = consumo_real - franquia;
                if (gb_exc <= 0)
                {
                    extra = 0;
                }
                else if (gb_exc > 0 && gb_exc <= 10)
                {
                    extra = gb_exc * 2.50;
                }
                else if (gb_exc > 10 && gb_exc <= 30)
                {
                    extra = gb_exc * 4.00;
                }
                else if (gb_exc > 30)
                {
                    extra = gb_exc * 7.00;
                }
                total_cobrado = valor_mensal + extra;

                printf("============================================\n");
                printf("\tFATURA INTERNET MÊS: %s/2026\n", mes_ref);
                printf("============================================\n");
                printf("EMPRESA: %s\tCNPJ: %s\n", razao_social, CNPJ);
                printf("ENDEREÇO: %s, %s, %s, %s, %s, %s\n", rua, numero, bairro, cidade, estado, CEP);
                printf("--------------------------------------------\n");
                printf("CLIENTE: %s\tCPF: %s\n", cliente, CPF);
                printf("PLANO: %s\n", plano);
                printf("--------------------------------------------\n");
                printf("FRANQUIA: %.2fGB\tCONSUMO: %.2fGB\n", franquia, consumo_real);
                printf("GB EXCEDENTE: %.2fGB\n", gb_exc);
                printf("--------------------------------------------\n");
                printf("VENCIMENTOS\n");
                printf("--------------------------------------------\n");
                printf("VALOR PLANO: R$ %.2f\tEXCEDENTE: R$ %.2f\n", valor_mensal, extra);
                printf("--------------------------------------------\n");
                printf("TOTAL A PAGAR: R$ %.2f\n", total_cobrado);
                printf("============================================\n\n");

                printf("Deseja calcular outra fatura? (S/N): ");
                scanf(" %c", &opcao_2);

                limparBuffer();

            } while (opcao_2 == 'S' || opcao_2 == 's');
        }
        default: {
            printf ("ERRO: OPÇÃO INVÁLIDA!\n");
        }
        }
    } while (opcao != 3);
}