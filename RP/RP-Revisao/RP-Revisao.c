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
    char CNPJ[16], razao_social[101], endereco[201], cidade[51], telefone[12];
    char produtos[5][50];
    float itens[5][3], valor_unitario, valor_venda;
    int opcao, escolha_menu, opcao_final, opcao_item, opcao_relatorio;
    int empresa_cadastrada = 0;
    int vendas_feitas = 0, itens_vendidos = 0;
    float menor_venda, maior_venda, total_vendido = 0;
    float quantidade_vendida;

    do
    {
        do
        {
            printf("\n===== SISTEMA DE PDV - SUPERMERCADO =====\n");
            printf("1 - Configurar dados da empresa\n");
            printf("2 - Vendas\n");
            printf("3 - Relatórios\n");
            printf("0 - Sair\n");
            printf("\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);
            limparBuffer();

            if (opcao < 0 || opcao > 3)
            {
                printf("ERRO: Opção inválida!\n");
            }
        } while (opcao < 0 || opcao > 3);

        switch (opcao)
        {
        case 0:
            printf("Saindo...\n");
            break;

        case 1:
            do
            {
                printf("\nInforme o CNPJ da empresa: ");
                fgets(CNPJ, sizeof(CNPJ), stdin);
                CNPJ[strcspn(CNPJ, "\n")] = '\0';

                if (strlen(CNPJ) == 0 || strlen(CNPJ) != 14)
                {
                    printf("ERRO: CNPJ deve possuir 14 dígitos!\n");
                }
            } while (strlen(CNPJ) == 0 || strlen(CNPJ) != 14);

            do
            {
                printf("\nInforme a Razão Social da empresa: ");
                fgets(razao_social, sizeof(razao_social), stdin);
                razao_social[strcspn(razao_social, "\n")] = '\0';

                if (strlen(razao_social) == 0)
                {
                    printf("ERRO: Razão Social não pode estar em branco!\n");
                }
            } while (strlen(razao_social) == 0);

            do
            {
                printf("\nInforme o Endereço: ");
                fgets(endereco, sizeof(endereco), stdin);
                endereco[strcspn(endereco, "\n")] = '\0';

                if (strlen(endereco) == 0)
                {
                    printf("ERRO: Endereço não pode estar em branco!\n");
                }
            } while (strlen(endereco) == 0);

            do
            {
                printf("\nInforme a Cidade: ");
                fgets(cidade, sizeof(cidade), stdin);
                cidade[strcspn(cidade, "\n")] = '\0';

                if (strlen(cidade) == 0)
                {
                    printf("ERRO: Cidade não pode estar em branco!\n");
                }
            } while (strlen(cidade) == 0);

            do
            {
                printf("\nInforme o Telefone: ");
                fgets(telefone, sizeof(telefone), stdin);
                telefone[strcspn(telefone, "\n")] = '\0';

                if (strlen(telefone) == 0 || strlen(telefone) != 10)
                {
                    printf("ERRO: Telefone deve possuir 10 dígitos!\n");
                }
            } while (strlen(telefone) == 0 || strlen(telefone) != 10);

            printf("\nDados da empresa cadastrados com sucesso!\n");
            empresa_cadastrada = 1;
            break;

        case 2:
            do
            {
                if (empresa_cadastrada != 1)
                {
                    printf("ERRO: Para poder registrar vendas,\né necessário cadastrar a empresa.\n");
                    break;
                }

                for (int v = 0; v < 5; v++)
                {
                    for (int d = 0; d < 3; d++)
                    {
                        itens[v][d] = 0;
                    }
                }
                printf("\n==== REGISTRO DOS ITENS DA VENDA ====\n");
                printf("Limite de 5 ítens\n");
                itens_vendidos = 0;
                for (int v = 0; v < 5; v++)
                {
                    itens_vendidos = itens_vendidos + 1;
                    do
                    {
                        printf("\nProduto %d:\n", v + 1);
                        printf("Informe o nome do produto: ");
                        fgets(produtos[v], sizeof(produtos[v]), stdin);
                        produtos[v][strcspn(produtos[v], "\n")] = '\0';
                        if (strlen(produtos[v]) == 0)
                        {
                            printf("ERRO: Nome do produto não pode estar em branco.\n");
                        }
                    } while (strlen(produtos[v]) == 0);

                    do
                    {
                        printf("Informe a quantidade vendida: ");
                        scanf("%f", &quantidade_vendida);
                        limparBuffer();

                        if (quantidade_vendida <= 0)
                        {
                            printf("ERRO: Quantidade vendida não pode ser zero.\n");
                        }
                    } while (quantidade_vendida <= 0);

                    do
                    {
                        printf("Informe o valor unitário: ");
                        scanf("%f", &valor_unitario);
                        limparBuffer();

                        if (valor_unitario <= 0)
                        {
                            printf("ERRO: Valor unitário não pode ser zero.\n");
                        }
                    } while (valor_unitario <= 0);

                    itens[v][0] = quantidade_vendida;
                    itens[v][1] = valor_unitario;
                    itens[v][2] = (valor_unitario * quantidade_vendida);

                    if (itens_vendidos < 5)
                    {
                        do
                        {
                            printf("\nDeseja inserir um novo item? 1 - Sim | 0 - Não\n");
                            printf("Escolha uma opção: ");
                            scanf("%d", &opcao_item);
                            limparBuffer();

                            if (opcao_item < 0 || opcao_item > 1)
                            {
                                printf("ERRO: Opção inválida!\n");
                            }
                        } while (opcao_item < 0 || opcao_item > 1);
                    }
                    if (itens_vendidos == 5)
                    {
                        printf("Máximo de ítens atingido!\n");
                    }

                    if (opcao_item == 0)
                    {
                        break;
                    }
                }
                valor_venda = 0;
                for (int v = 0; v < itens_vendidos; v++)
                {
                    valor_venda = valor_venda + itens[v][2];
                }
                if (vendas_feitas == 0)
                {
                    maior_venda = valor_venda;
                    menor_venda = valor_venda;
                }
                else
                {
                    if (valor_venda > maior_venda)
                    {
                        maior_venda = valor_venda;
                    }
                    if (valor_venda < menor_venda)
                    {
                        menor_venda = valor_venda;
                    }
                }
                vendas_feitas = vendas_feitas + 1;
                total_vendido = total_vendido + valor_venda;

                do
                {
                    printf("\nForma de pagamento:\n");
                    printf("1 - Dinheiro\n");
                    printf("2 - Cartão de Débito\n");
                    printf("3 - Cartão de Crédito\n");
                    printf("4 - PIX\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao_final);
                    limparBuffer();

                    if (opcao_final < 1 || opcao_final > 4)
                    {
                        printf("ERRO: Opção inválida!\n");
                    }
                } while (opcao_final < 1 || opcao_final > 4);

                switch (opcao_final)
                {
                case 1:
                    printf("\n================ CUPOM FISCAL ================\n");
                    printf("%s\n", razao_social);
                    printf("%s\n", CNPJ);
                    printf("Endereço: %s\n", endereco);
                    printf("Cidade: %s - Telefone: %s\n", cidade, telefone);
                    printf("------------------------------------------------\n");
                    printf("Item | Produto | Qtd | Vlr Unit. | Total\n");
                    for (int v = 0; v < itens_vendidos; v++)
                    {
                        printf("%d | %s | %.2f | %.2f | %.2f\n", v + 1, produtos[v], itens[v][0], itens[v][1], itens[v][2]);
                    }
                    printf("------------------------------------------------\n");
                    printf("TOTAL DA VENDA: R$ %.2f\n", valor_venda);
                    printf("Forma de pagamento: Dinheiro\n");
                    printf("\n");
                    printf("Obrigado pela preferência!\n");
                    printf("===============================================\n");
                    break;

                case 2:
                    printf("\n================ CUPOM FISCAL ================\n");
                    printf("%s\n", razao_social);
                    printf("%s\n", CNPJ);
                    printf("Endereço: %s\n", endereco);
                    printf("Cidade: %s - Telefone: %s\n", cidade, telefone);
                    printf("------------------------------------------------\n");
                    printf("Item | Produto | Qtd | Vlr Unit. | Total\n");
                    for (int v = 0; v < itens_vendidos; v++)
                    {
                        printf("%d | %s | %.2f | %.2f | %.2f\n", v + 1, produtos[v], itens[v][0], itens[v][1], itens[v][2]);
                    }
                    printf("------------------------------------------------\n");
                    printf("TOTAL DA VENDA: R$ %.2f\n", valor_venda);
                    printf("Forma de pagamento: Cartão de Débito\n");
                    printf("\n");
                    printf("Obrigado pela preferência!\n");
                    printf("===============================================\n");
                    break;

                case 3:
                    printf("\n================ CUPOM FISCAL ================\n");
                    printf("%s\n", razao_social);
                    printf("%s\n", CNPJ);
                    printf("Endereço: %s\n", endereco);
                    printf("Cidade: %s - Telefone: %s\n", cidade, telefone);
                    printf("------------------------------------------------\n");
                    printf("Item | Produto | Qtd | Vlr Unit. | Total\n");
                    for (int v = 0; v < itens_vendidos; v++)
                    {
                        printf("%d | %s | %.2f | %.2f | %.2f\n", v + 1, produtos[v], itens[v][0], itens[v][1], itens[v][2]);
                    }
                    printf("------------------------------------------------\n");
                    printf("TOTAL DA VENDA: R$ %.2f\n", valor_venda);
                    printf("Forma de pagamento: Cartão de Crédito\n");
                    printf("\n");
                    printf("Obrigado pela preferência!\n");
                    printf("===============================================\n");
                    break;

                case 4:
                    printf("\n================ CUPOM FISCAL ================\n");
                    printf("%s\n", razao_social);
                    printf("%s\n", CNPJ);
                    printf("Endereço: %s\n", endereco);
                    printf("Cidade: %s - Telefone: %s\n", cidade, telefone);
                    printf("------------------------------------------------\n");
                    printf("Item | Produto | Qtd | Vlr Unit. | Total\n");
                    for (int v = 0; v < itens_vendidos; v++)
                    {
                        printf("%d | %s | %.2f | %.2f | %.2f\n", v + 1, produtos[v], itens[v][0], itens[v][1], itens[v][2]);
                    }
                    printf("------------------------------------------------\n");
                    printf("TOTAL DA VENDA: R$ %.2f\n", valor_venda);
                    printf("Forma de pagamento: PIX\n");
                    printf("\n");
                    printf("Obrigado pela preferência!\n");
                    printf("===============================================\n");
                    break;

                default:
                    printf("ERRO: Opção inválida!\n");
                    break;
                }
                do
                {
                    printf("\nDeseja registrar outra venda? 1 - Sim | 0 - Voltar ao menu principal:\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &escolha_menu);
                    limparBuffer();
                    if (escolha_menu < 0 || escolha_menu > 1)
                    {
                        printf("ERRO: Opção inválida!\n");
                    }
                    if (escolha_menu == 0)
                    {
                        printf("Voltando ao menu principal...\n");
                    }
                } while (escolha_menu < 0 || escolha_menu > 1);
            } while (escolha_menu != 0);
            break;

        case 3:
            if (vendas_feitas == 0)
            {
                printf("Nenhuma venda foi registrada até o momento.\n");
                break;
            }
            do
            {
                do
                {
                    printf("\n===== RELATÓRIOS =====\n");
                    printf("1 - Valor em vendas do dia\n");
                    printf("2 - Cupom de maior valor\n");
                    printf("3 - Cupom de menor valor\n");
                    printf("4 - Média em R$ por venda\n");
                    printf("0 - Voltar ao menu principal\n");
                    printf("\nEscolha uma opção: ");
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
                    printf("Voltando...\n");
                    break;

                case 1:
                    printf("O total em vendas do dia é de R$: %.2f.\n", total_vendido);
                    break;

                case 2:
                    printf("O cupom de maior valor, possui valor de R$ %.2f.\n", maior_venda);
                    break;

                case 3:
                    printf("O cupom de menor valor, possui valor de R$ %.2f.\n", menor_venda);
                    break;

                case 4:
                    float media_venda;
                    media_venda = total_vendido / vendas_feitas;
                    printf("A média em R$ por venda é de R$ %.2f.\n", media_venda);
                    break;

                default:
                    printf("ERRO: Opção inválida!\n");
                    break;
                }
            } while (opcao_relatorio != 0);
            break;
        default:
            printf("ERRO: Opção inválida!\n");
            break;
        }
    } while (opcao != 0);
}