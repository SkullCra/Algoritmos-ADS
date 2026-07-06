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
    char livros[4][30];
    int dados[4][3];
    int opcao, escolha, opcao_relatorio;
    int mais_emprestado, escolha_livro;

    printf("\n==== Biblioteca Pública Municipal ====\n");
    printf("Cadastre abaixo os livros da biblioteca:\n");
    for (int l = 0; l < 4; l++)
    {
        do
        {
            printf("Informe o nome do %dº livro: ", l + 1);
            fgets(livros[l], sizeof(livros[l]), stdin);
            livros[l][strcspn(livros[l], "\n")] = '\0';

            if (strlen(livros[l]) == 0)
            {
                printf("ERRO: Nome do livro não pode estar em branco!\n");
            }
        } while (strlen(livros[l]) == 0);
    }

    for (int l = 0; l < 4; l++)
    {
        for (int d = 0; d < 3; d++)
        {
            dados[l][d] = 0;
        }
    }

    for (int e = 0; e < 10; e++)
    {
        do
        {
            printf("\n=== Empréstimo %d de 10\n", e + 1);
            printf("Escolha o livro emprestado:\n");
            for (int l = 0; l < 4; l++)
            {
                printf("%d - %s\n", l + 1, livros[l]);
            }
            printf("Sua escolha: ");
            scanf("%d", &opcao);
            limparBuffer();

            if (opcao < 1 || opcao > 4)
            {
                printf("ERRO: Opção inválida!\n");
                printf("Tente novamente!\n\n");
            }
        } while (opcao < 1 || opcao > 4);

        switch (opcao)
        {
        case 1:
            do
            {
                printf("\nA devolução foi feita:\n");
                printf("1 - No prazo\n");
                printf("2 - Com atraso\n");
                printf("Sua escolha: ");
                scanf("%d", &escolha);
                limparBuffer();

                if (escolha < 1 || escolha > 2)
                {
                    printf("ERRO: Opção inválida!\n");
                    printf("Tente novamente!\n\n");
                }
            } while (escolha < 1 || escolha > 2);

            if (escolha == 1)
            {
                dados[0][0] = dados[0][0] + 1;
                dados[0][1] = dados[0][1] + 1;
            }

            if (escolha == 2)
            {
                dados[0][0] = dados[0][0] + 1;
                dados[0][2] = dados[0][2] + 1;
            }
            break;
        case 2:
            do
            {
                printf("\nA devolução foi feita:\n");
                printf("1 - No prazo\n");
                printf("2 - Com atraso\n");
                printf("Sua escolha: ");
                scanf("%d", &escolha);
                limparBuffer();

                if (escolha < 1 || escolha > 2)
                {
                    printf("ERRO: Opção inválida!\n");
                    printf("Tente novamente!\n\n");
                }
            } while (escolha < 1 || escolha > 2);

            if (escolha == 1)
            {
                dados[1][0] = dados[1][0] + 1;
                dados[1][1] = dados[1][1] + 1;
            }

            if (escolha == 2)
            {
                dados[1][0] = dados[1][0] + 1;
                dados[1][2] = dados[1][2] + 1;
            }
            break;
        case 3:
            do
            {
                printf("\nA devolução foi feita:\n");
                printf("1 - No prazo\n");
                printf("2 - Com atraso\n");
                printf("Sua escolha: ");
                scanf("%d", &escolha);
                limparBuffer();

                if (escolha < 1 || escolha > 2)
                {
                    printf("ERRO: Opção inválida!\n");
                    printf("Tente novamente!\n\n");
                }
            } while (escolha < 1 || escolha > 2);

            if (escolha == 1)
            {
                dados[2][0] = dados[2][0] + 1;
                dados[2][1] = dados[2][1] + 1;
            }

            if (escolha == 2)
            {
                dados[2][0] = dados[2][0] + 1;
                dados[2][2] = dados[2][2] + 1;
            }
            break;
        case 4:
            do
            {
                printf("\nA devolução foi feita:\n");
                printf("1 - No prazo\n");
                printf("2 - Com atraso\n");
                printf("Sua escolha: ");
                scanf("%d", &escolha);
                limparBuffer();

                if (escolha < 1 || escolha > 2)
                {
                    printf("ERRO: Opção inválida!\n");
                    printf("Tente novamente!\n\n");
                }
            } while (escolha < 1 || escolha > 2);

            if (escolha == 1)
            {
                dados[3][0] = dados[3][0] + 1;
                dados[3][1] = dados[3][1] + 1;
            }

            if (escolha == 2)
            {
                dados[3][0] = dados[3][0] + 1;
                dados[3][2] = dados[3][2] + 1;
            }
            break;

        default:
            printf("ERRO: Opção inválida!\n");
            printf("Tente novamente!\n");
            break;
        }
    }

    do
    {
        do
        {
            printf("\n==== RELATÓRIOS DO ACERTO ====\n");
            printf("1 - Exibir tabela geral\n");
            printf("2 - Exibir total de empréstimos por livro\n");
            printf("3 - Exibir o livro mais emprestado\n");
            printf("4 - Exibir resumo de um livro\n");
            printf("0 - Sair\n");
            printf("Sua escolha: ");
            scanf("%d", &opcao_relatorio);
            limparBuffer();

            if (opcao_relatorio < 0 || opcao_relatorio > 4)
            {
                printf("ERRO: Opção inválida!\n");
                printf("Tente novamente!\n");
            }
        } while (opcao_relatorio < 0 || opcao_relatorio > 4);

        switch (opcao_relatorio)
        {
        case 0:
            printf("Você escolheu sair...\n");
            break;

        case 1:
            printf("\n====== Tabela Geral do Acervo ======\n");
            printf("-------------------------------------\n");
            printf("Livro\tTotal | No prazo | Com atraso\n");
            for (int l = 0; l < 4; l++)
            {
                printf("%-10s %d | %d | %d\n", livros[l], dados[l][0], dados[l][1], dados[l][2]);
            }
            printf("-------------------------------------\n");
            break;

        case 2:
            printf("\n==== Total de Empréstimos ====\n");
            for (int l = 0; l < 4; l++)
            {
                printf("%s: %d empréstimo(s)\n", livros[l], dados[l][0]);
            }
            break;

        case 3:
            mais_emprestado = 0;
            for (int l = 1; l < 4; l++)
            {
                if (dados[l][0] > dados[mais_emprestado][0])
                {
                    mais_emprestado = l;
                }
            }
            printf("\n==== Livro mais emprestado ====\n");
            printf("O livro mais emprestado foi: %s, com %d empréstimo(s)\n", livros[mais_emprestado], dados[mais_emprestado][0]);
            break;

        case 4:
            do
            {
                printf("\n==== Resumo por livro ====\n");
                printf("Escolha um livro abaixo:\n");
                {
                    for (int l = 0; l < 4; l++)
                    {
                        printf("%d - %s\n", l + 1, livros[l]);
                    }
                }
                printf("Sua escolha: ");
                scanf("%d", &escolha_livro);
                limparBuffer();

                if (escolha_livro < 1 || escolha_livro > 4)
                {
                    printf("ERRO: Opção inválida!\n");
                }
            } while (escolha_livro < 1 || escolha_livro > 4);

            switch (escolha_livro)
            {
            case 1:
                printf("Livro\tTotal | No prazo | Com atraso\n");
                printf("%-10s %d | %d | %d\n", livros[0], dados[0][0], dados[0][1], dados[0][2]);
                printf("-------------------------------------\n");
                break;

            case 2:
                printf("Livro\tTotal | No prazo | Com atraso\n");
                printf("%-10s %d | %d | %d\n", livros[1], dados[1][0], dados[1][1], dados[1][2]);
                printf("-------------------------------------\n");
                break;

            case 3:
                printf("Livro\tTotal | No prazo | Com atraso\n");
                printf("%-10s %d | %d | %d\n", livros[2], dados[2][0], dados[2][1], dados[2][2]);
                printf("-------------------------------------\n");
                break;

            case 4:
                printf("Livro\tTotal | No prazo | Com atraso\n");
                printf("%-10s %d | %d | %d\n", livros[3], dados[3][0], dados[3][1], dados[3][2]);
                printf("-------------------------------------\n");
                break;

            default:
                printf("ERRO: Opção inválida!\n");
                break;
            }
            break;

        default:
            printf("ERRO: Opção inválida!\n");
            printf("Tente novamente!\n");
        }
    } while (opcao_relatorio != 0);

    return 0;
}