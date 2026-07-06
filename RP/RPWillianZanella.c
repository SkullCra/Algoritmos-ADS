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
    char produtos[5][50];
    float itens[5][3];
    int opcao, escolha_telefone, opcao_menu, opcao_inserir, vendas, vendas_finais, opcao_pagamento;
    int opcao_relatorio;
    int quantidade_vendida;
    float valor_unitario;
    char CNPJ[15], razao_social[101];
    char rua[41], numero[3], bairro[41], cidade[41], estado[26], cep[10], telefone[11], celular[12];
    float valor_total, total_dia;
    int maior_venda, menor_venda;

    do
    {
        do
        {
            do
            {
                printf("\n===== SISTEMA DE PDV - SUPERMERCADO =====\n");
                printf("\n");
                printf("1 - Configurar dados da empresa\n");
                printf("2 - Vendas\n");
                printf("3 - Relatórios\n");
                printf("0 - Sair\n");
                printf("Sua escolha: ");
                scanf("%d", &opcao);
                limparBuffer();

                if (opcao < 0 || opcao > 4)
                {
                    printf("ERRO: Opção inválida!\n");
                    printf("Tente novamente!\n");
                }
            } while (opcao < 0 || opcao > 4);

            switch (opcao)
            {
            case 0:
                printf("\n");
                printf("Saindo...\n");

            case 1:
                printf("\n=== Configurar dados da empresa ===\n");
                do
                {
                    printf("Informe o CNPJ da empresa: ");
                    fgets(CNPJ, sizeof(CNPJ), stdin);
                    CNPJ[strcspn(CNPJ, "\n")] = '\0';

                    if (strlen(CNPJ) == 0 || strlen(CNPJ) > 14)
                    {
                        printf("ERRO: CNPJ deve possuir 14 dígitos!\n");
                    }
                } while (strlen(CNPJ) == 0 || strlen(CNPJ) > 14);
                limparBuffer();

                do
                {
                    printf("Informe a sua Razão Social: ");
                    fgets(razao_social, sizeof(razao_social), stdin);
                    razao_social[strcspn(razao_social, "\n")] = '\0';

                    if (strlen(razao_social) == 0)
                    {
                        printf("ERRO: Razão Social não pode estar em branco!\n");
                    }
                } while (strlen(razao_social) == 0);

                printf("Informe seu endereço abaixo:\n");
                do
                {
                    printf("Rua: ");
                    fgets(rua, sizeof(rua), stdin);
                    rua[strcspn(rua, "\n")] = '\0';
                    if (strlen(rua) == 0)
                    {
                        printf("ERRO: Rua não pode estar em branco!\n");
                    }
                } while (strlen(rua) == 0);

                do
                {
                    printf("Número: ");
                    fgets(numero, sizeof(numero), stdin);
                    numero[strcspn(numero, "\n")] = '\0';
                    if (strlen(numero) == 0)
                    {
                        printf("ERRO: Número não pode estar em branco!\n");
                    }
                } while (strlen(numero) == 0);
                limparBuffer();

                do
                {
                    printf("Bairro: ");
                    fgets(bairro, sizeof(bairro), stdin);
                    bairro[strcspn(bairro, "\n")] = '\0';
                    if (strlen(bairro) == 0)
                    {
                        printf("ERRO: Bairro não pode estar em branco!\n");
                    }
                } while (strlen(bairro) == 0);

                do
                {
                    printf("Cidade: ");
                    fgets(cidade, sizeof(cidade), stdin);
                    cidade[strcspn(cidade, "\n")] = '\0';

                    if (strlen(cidade) == 0)
                    {
                        printf("ERRO: Cidade não pode estar em branco!\n");
                    }
                } while (strlen(cidade) == 0);

                do
                {
                    printf("Estado: ");
                    fgets(estado, sizeof(estado), stdin);
                    estado[strcspn(estado, "\n")] = '\0';
                    if (strlen(estado) == 0)
                    {
                        printf("ERRO: Estado não pode estar em branco!\n");
                    }
                } while (strlen(estado) == 0);

                do
                {
                    printf("CEP: ");
                    fgets(cep, sizeof(cep), stdin);
                    cep[strcspn(cep, "\n")] = '\0';

                    if (strlen(cep) != 8)
                    {
                        printf("ERRO: CEP não pode estar em branco!\n");
                    }
                } while (strlen(cep) != 8);

                do
                {
                    printf("\nQual tipo de telefone você possui?\n");
                    printf("1 - Celular\n");
                    printf("2 - Telefone Fixo\n");
                    printf("3 - Ambos\n");
                    printf("Sua escolha: ");
                    scanf("%d", &escolha_telefone);
                    limparBuffer();

                    if (escolha_telefone < 1 || escolha_telefone > 3)
                    {
                        printf("ERRO: Opção inválida!\n");
                    }
                } while (escolha_telefone < 1 || escolha_telefone > 3);

                if (escolha_telefone == 1)
                {
                    do
                    {
                        printf("\nInforme o número do seu celular(Apenas Dígitos, com DDD)\n");
                        printf("Celular: ");
                        fgets(celular, sizeof(celular), stdin);
                        celular[strcspn(celular, "\n")] = '\0';

                        if (strlen(celular) != 11)
                        {
                            printf("ERRO: Número de celular com DDD deve possuir 11 dígitos!\n");
                        }
                    } while (strlen(celular) != 11);
                }

                if (escolha_telefone == 2)
                {
                    do
                    {
                        printf("\nInforme o número do seu telefone(Apenas Dígitos, com DDD)\n");
                        printf("Telefone: ");
                        fgets(telefone, sizeof(telefone), stdin);
                        telefone[strcspn(telefone, "\n")] = '\0';

                        if (strlen(telefone) != 10)
                        {
                            printf("ERRO: Número de telefone com DDD deve possuir 12 dígitos!\n");
                        }
                    } while (strlen(telefone) != 10);
                }

                if (escolha_telefone == 3)
                {
                    do
                    {
                        printf("\nInforme o número do seu celular(Apenas Dígitos, com DDD)\n");
                        printf("Celular: ");
                        fgets(celular, sizeof(celular), stdin);
                        celular[strcspn(celular, "\n")] = '\0';
                        limparBuffer();

                        if (strlen(celular) != 11)
                        {
                            printf("ERRO: Número de celular com DDD deve possuir 11 dígitos!\n");
                        }
                    } while (strlen(celular) != 11);

                    do
                    {
                        printf("\nInforme o número do seu telefone(Apenas Dígitos, com DDD)\n");
                        printf("Telefone: ");
                        fgets(telefone, sizeof(telefone), stdin);
                        telefone[strcspn(telefone, "\n")] = '\0';
                        limparBuffer();

                        if (strlen(telefone) != 10)
                        {
                            printf("ERRO: Número de telefone com DDD deve possuir 10 dígitos!\n");
                        }
                    } while (strlen(telefone) != 10);
                }

                printf("\nDados da empresa cadastrados com sucesso!\n");
                break;

            case 2:
                if (strlen(cep) == 0)
                {
                    printf("ERRO: Primeiro cadastre sua empresa!\n");
                    break;
                }
                for (int v = 0; v < 5; v++)
                {
                    for (int d = 0; d < 3; d++)
                    {
                        itens[v][d] = 0;
                    }
                }
                do
                {
                    do
                    {
                        printf("\n=== REGISTRAR VENDAS ===\n");
                        printf("Quantas vendas deseja registrar?\n");
                        printf("Quantidade de vendas(1 a 5): ");
                        scanf("%d", &vendas);
                        limparBuffer();
                        if (vendas < 1 || vendas > 5)
                        {
                            printf("ERRO: Quantidade de vendas deve ser no máximo 5!\n");
                        }
                    } while (vendas < 1 || vendas > 5);

                    for (int v = 0; v < vendas; v++)
                    {
                        do
                        {
                            printf("\nInforme o nome do produto: ");
                            fgets(produtos[v], sizeof(produtos[v]), stdin);
                            produtos[v][strcspn(produtos[v], "\n")] = '\0';
                            if (strlen(produtos[v]) == 0)
                            {
                                printf("ERRO: Nome do produto não pode estar em branco!\n");
                            }
                        } while (strlen(produtos[v]) == 0);

                        do
                        {
                            printf("Informe a quantidade vendida: ");
                            scanf("%d", &quantidade_vendida);
                            limparBuffer();
                            if (quantidade_vendida <= 0)
                            {
                                printf("ERRO: Quantidade vendida não pode ser zero ou menor que zero!\n");
                            }
                        } while (quantidade_vendida <= 0);
                        itens[v][0] = itens[v][0] + quantidade_vendida;

                        do
                        {
                            printf("Informe o valor unitário: ");
                            scanf("%f", &valor_unitario);
                            limparBuffer();

                            if (valor_unitario <= 0)
                            {
                                printf("ERRO: Valor unitário não pode ser zero ou menor que zero!\n");
                            }
                        } while (valor_unitario <= 0);

                        itens[v][1] = valor_unitario;
                        itens[v][2] = (quantidade_vendida * valor_unitario);
                    }
                    do
                    {
                        printf("Deseja inserir outro ítem? 1 - Sim | 0 - Não\n");
                        printf("Sua escolha: ");
                        scanf("%d", &opcao_inserir);
                        limparBuffer();

                        if (opcao_inserir < 0 || opcao_inserir > 1)
                        {
                            printf("ERRO: Opção inválida!\n");
                        }
                    } while (opcao_inserir < 0 || opcao_inserir > 1);

                    if (opcao_inserir == 1)
                    {
                        for (int v = vendas; v < 5; v++)
                        {
                            do
                            {
                                printf("\nInforme o nome do produto: ");
                                fgets(produtos[v], sizeof(produtos[v]), stdin);
                                produtos[v][strcspn(produtos[v], "\n")] = '\0';
                                if (strlen(produtos[v]) == 0)
                                {
                                    printf("ERRO: Nome do produto não pode estar em branco!\n");
                                }
                            } while (strlen(produtos[v]) == 0);

                            do
                            {
                                printf("Informe a quantidade vendida: ");
                                scanf("%d", &quantidade_vendida);
                                limparBuffer();
                                if (quantidade_vendida <= 0)
                                {
                                    printf("ERRO: Quantidade vendida não pode ser zero ou menor que zero!\n");
                                }
                            } while (quantidade_vendida <= 0);
                            itens[v][0] = itens[v][0] + quantidade_vendida;

                            do
                            {
                                printf("Informe o valor unitário: ");
                                scanf("%f", &valor_unitario);
                                limparBuffer();

                                if (valor_unitario <= 0)
                                {
                                    printf("ERRO: Valor unitário não pode ser zero ou menor que zero!\n");
                                }
                            } while (valor_unitario <= 0);

                            itens[v][1] = valor_unitario;
                            itens[v][2] = (quantidade_vendida * valor_unitario);
                            vendas_finais = vendas + 1;
                        }
                        printf("Ítens cadastrados com sucesso!\n");
                    }
                    if (opcao_inserir == 0)
                    {
                        vendas_finais = vendas;
                        printf("Ítens cadastrados com sucesso!\n");
                    }

                    maior_venda = itens[0][2];
                    for (int v = 1; v < vendas_finais; v++)
                    {
                        if (itens[v][2] > maior_venda)
                        {
                            maior_venda = v;
                        }
                    }
                    menor_venda = itens[0][2];
                    for (int v = 1; v < vendas_finais; v++)
                    {
                        if (itens[v][2] < menor_venda)
                        {
                            menor_venda = v;
                        }
                    }
                    valor_total = 0;
                    for (int v = 0; v < vendas_finais; v++)
                    {
                        valor_total = valor_total + itens[v][2];
                    }
                    printf("VALOR TOTAL DA VENDA: R$: %.2f\n", valor_total);
                    do
                    {
                        printf("\nComo deseja realizar o pagamento?\n");
                        printf("1 - Dinheiro\n");
                        printf("2 - Cartão de Débito\n");
                        printf("3 - Cartão de Crédito\n");
                        printf("4 - PIX\n");
                        printf("Sua escolha: ");
                        scanf("%d", &opcao_pagamento);
                        limparBuffer();

                        if (opcao_pagamento < 1 || opcao_pagamento > 4)
                        {
                            printf("ERRO: Opção inválida!\n");
                        }
                    } while (opcao_pagamento < 1 || opcao_pagamento > 4);

                    if (opcao_pagamento == 1)
                    {
                        printf("\n========== CUPOM FISCAL==========\n");
                        printf("\n");
                        printf("CNPJ: %s\n", CNPJ);
                        printf("Endereço: %s, %s - Bairro %s\n", rua, numero, bairro);
                        printf("Cidade: %s - Telefone: %s - Celular: %s\n", cidade, telefone, celular);
                        printf("\n");
                        printf("------------------------------------\n");
                        printf("Ítem\t | Produto | QTD | Vlr Unit. | Total\n");
                        for (int p = 0; p < 5; p++)
                        {
                            printf("%d\t| %s | %.2f | %.2f | %.2f\n", p + 1, produtos[p], itens[p][0], itens[p][1], itens[p][2]);
                        }
                        printf("------------------------------------\n");
                        printf("TOTAL DA VENDA: %.2f\n", valor_total);
                        printf("Forma de pagamento: Dinheiro\n");
                        printf("\n");
                        printf("Obrigado pela preferência!\n");
                    }
                    if (opcao_pagamento == 2)
                    {
                        printf("\n========== CUPOM FISCAL==========\n");
                        printf("\n");
                        printf("CNPJ: %s\n", CNPJ);
                        printf("Endereço: %s, %s - Bairro %s\n", rua, numero, bairro);
                        printf("Cidade: %s - Telefone: %s - Celular: %s\n", cidade, telefone, celular);
                        printf("\n");
                        printf("------------------------------------\n");
                        printf("Ítem\t | Produto | QTD | Vlr Unit. | Total\n");
                        for (int p = 0; p < 5; p++)
                        {
                            printf("%d\t| %s | %.2f | %.2f | %.2f\n", p + 1, produtos[p], itens[p][0], itens[p][1], itens[p][2]);
                        }
                        printf("------------------------------------\n");
                        printf("TOTAL DA VENDA: %.2f\n", valor_total);
                        printf("Forma de pagamento: Cartão de Débito\n");
                        printf("\n");
                        printf("Obrigado pela preferência!\n");
                    }
                    if (opcao_pagamento == 3)
                    {
                        printf("\n========== CUPOM FISCAL==========\n");
                        printf("\n");
                        printf("CNPJ: %s\n", CNPJ);
                        printf("Endereço: %s, %s - Bairro %s\n", rua, numero, bairro);
                        printf("Cidade: %s - Telefone: %s - Celular: %s\n", cidade, telefone, celular);
                        printf("\n");
                        printf("------------------------------------\n");
                        printf("Ítem\t | Produto | QTD | Vlr Unit. | Total\n");
                        for (int p = 0; p < 5; p++)
                        {
                            printf("%d\t| %s | %.2f | %.2f | %.2f\n", p + 1, produtos[p], itens[p][0], itens[p][1], itens[p][2]);
                        }
                        printf("------------------------------------\n");
                        printf("TOTAL DA VENDA: %.2f\n", valor_total);
                        printf("Forma de pagamento: Cartão de Crédito\n");
                        printf("\n");
                        printf("Obrigado pela preferência!\n");
                    }
                    if (opcao_pagamento == 4)
                    {
                        printf("\n========== CUPOM FISCAL==========\n");
                        printf("\n");
                        printf("CNPJ: %s\n", CNPJ);
                        printf("Endereço: %s, %s - Bairro %s\n", rua, numero, bairro);
                        printf("Cidade: %s - Telefone: %s - Celular: %s\n", cidade, telefone, celular);
                        printf("\n");
                        printf("------------------------------------\n");
                        printf("Ítem\t | Produto | QTD | Vlr Unit. | Total\n");
                        for (int p = 0; p < 5; p++)
                        {
                            printf("%d\t| %s | %.2f | %.2f | %.2f\n", p + 1, produtos[p], itens[p][0], itens[p][1], itens[p][2]);
                        }
                        printf("------------------------------------\n");
                        printf("TOTAL DA VENDA: %.2f\n", valor_total);
                        printf("Forma de pagamento: PIX\n");
                        printf("\n");
                        printf("Obrigado pela preferência!\n");
                    }
                    do
                    {
                        printf("Deseja realizar outra venda? 1 - Sim | 0 - Voltar ao menu principal\n");
                        printf("Sua escolha: ");
                        scanf("%d", &opcao_menu);
                        limparBuffer();
                        if (opcao_menu < 0 || opcao_menu > 1)
                        {
                            printf("ERRO: Opção inválida!\n");
                        }
                    } while (opcao_menu < 0 || opcao_menu > 1);
                } while (opcao_menu == 1);
                break;

            case 3:
                do
                {
                    do
                    {
                        printf("\n==== RELATÓRIOS ====\n");
                        printf("1 - Valor em vendas do dia\n");
                        printf("2 - Cupom de maior valor\n");
                        printf("3 - Cupom de menor valor\n");
                        printf("4 - Média em R$ por venda\n");
                        printf("0 - Voltar ao menu principal\n");
                        printf("Sua escolha: ");
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
                        printf("\nVoltando...\n");
                        break;

                    case 1:
                        printf("\nO valor total em vendas do dia foi %.2f\n", valor_total);
                        break;

                    case 2:
                        printf("\nO maior valor de venda registrado foi %.2f, do produto %s.\n", itens[maior_venda][2], produtos[maior_venda]);
                        break;

                    case 3:
                        printf("\nO menor valor de venda registrado foi %.2f, do produto %s.\n", itens[menor_venda][2], produtos[menor_venda]);
                        break;
                    case 4:
                        float media;
                        media = (vendas_finais / valor_total);
                        printf("\nA média por venda é de R$ %.2f", media);
                        break;

                    default:
                        printf("Opção inválida!\n");
                        break;
                    }
                } while (opcao_relatorio != 0);
                break;
            default:
                printf("Opção inválida!\n");
            }
        } while (opcao_relatorio == 0);
    } while (opcao != 0);
}