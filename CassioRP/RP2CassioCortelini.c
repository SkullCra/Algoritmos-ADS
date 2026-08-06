#include <stdio.h>
#include <string.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{

    char nome_aluno[81], matricula[31], disciplina[81], ano[5];
    float dados[3][4], media_final = 0, soma_notas = 0;
    int opcao, verificacao = 0;

    printf("===== GERENCIAMENTO DE NOTAS =====\n");

    do
    {
        printf("Digite o nome do aluno (Máximo 80 caracteres): ");
        fgets(nome_aluno, sizeof(nome_aluno), stdin);
        nome_aluno[strcspn(nome_aluno, "\n")] = '\0';

        if (nome_aluno[0] == '\0')
        {
            printf("ERRO: O nome do aluno deve ser preenchido!\n");
        }

    } while (nome_aluno[0] == '\0');

    do
    {
        printf("Digite a matrícula do aluno (Máximo 30 caracteres): ");
        fgets(matricula, sizeof(matricula), stdin);
        matricula[strcspn(matricula, "\n")] = '\0';

        if (matricula[0] == '\0')
        {
            printf("ERRO: A matrícula deve ser inserida!\n");
        }

    } while (matricula[0] == '\0');

    do
    {
        printf("Digite o nome da Disciplina (Máximo 80 caracteres): ");
        fgets(disciplina, sizeof(disciplina), stdin);
        disciplina[strcspn(disciplina, "\n")] = '\0';

        if (disciplina[0] == '\0')
        {
            printf("ERRO: A Disciplina deve ser inserida!\n");
        }

    } while (disciplina[0] == '\0');

    do
    {
        printf("Digite o ano (Máximo 4 caracteres): ");
        fgets(ano, sizeof(ano), stdin);
        ano[strcspn(ano, "\n")] = '\0';

        if (ano[0] == '\0')
        {
            printf("O ano deve ser inserido!\n");
        }

    } while (ano[0] == '\0');

    /*FIM CADASTRO ALUNO*/

    /*ZERANDO UMA CASA DA MATRIZ, PARA VALIDAR*/
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dados[2][2] = 0;
        }
    }

    do
    {
        printf("\nEscolha uma das opções:\n\n1- Inserir Notas\n2- Calcular Médias dos trimestres\n3- Emitir Boletim\n4- Sair do programa\n\n Sua opção: ");
        scanf("%d", &opcao);

        limparBuffer();

        switch (opcao)
        {
        case 1:

            /*LAÇO PRA ZERAR A MATRIZ ANTES*/
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    dados[i][j] = 0;
                }
            }
            /*FIM LAÇO PRA ZERAR MATRIZ*/

            /*COMEÇO FOR DE TRIMESTRE*/
            for (int i = 0; i < 3; i++)
            {
                printf("==== TRIMESTRE [%d°] de 3 ====\n", i + 1);

                do
                {
                    printf("Digite a primeira nota do aluno: ");
                    scanf("%f", &dados[i][0]);

                    if (dados[i][0] < 0 || dados[i][0] > 10)
                    {
                        printf("As notas devem estar no intervalo de 0 a 10.\n");
                    }

                } while (dados[i][0] < 0 || dados[i][0] > 10);

                do
                {
                    printf("Digite a segunda nota do aluno: ");
                    scanf("%f", &dados[i][1]);

                    if (dados[i][1] < 0 || dados[i][1] > 10)
                    {
                        printf("As notas devem estar no intervalo de 0 a 10.\n");
                    }

                } while (dados[i][1] < 0 || dados[i][1] > 10);

                do
                {
                    printf("Digite a terceira nota do aluno: ");
                    scanf("%f", &dados[i][2]);

                    if (dados[i][2] < 0 || dados[i][2] > 10)
                    {
                        printf("As notas devem estar no intervalo de 0 a 10.\n");
                    }

                } while (dados[i][2] < 0 || dados[i][2] > 10);
            }
            /*FIM FOR DE TRIMESTRE*/

            break;

        case 2:

            media_final = 0;
            soma_notas = 0;

            if (dados[2][2] == 0)
            {
                printf("Deve ser inseridas as notas antes de calcular a média!\n");
                break;
            }

            for (int i = 0; i < 3; i++)
            {
                dados[i][3] = (dados[i][0] + dados[i][1] + dados[i][2]) / 3;
                soma_notas += dados[i][3];
            }

            media_final = soma_notas / 3;
            verificacao = 1;

            printf("Notas calculadas com sucesso!\n");

            break;

        case 3:

            if (verificacao != 1)
            {
                printf("ERRO: Deve-se primeiro inserir as notas, posteriormente deve-se calcular suas médias para por fim, emitir o Boletim!\nSelecione Primeiro a opção 1 e posteriormente a opção 2!\n");
                break;
            }
            printf("======== BOLETIM DE APROVEITAMENTO ========\n");
            printf("Nome: [%s]\t\t Matrícula: [%s]\n", nome_aluno, matricula);
            printf("Disciplina: [%s]\t\t Ano: [%s]\n", disciplina, ano);

            printf("\n--- 1° TRIMESTRE ----------------------------\n\n");
            printf("Avaliação 1 | Avaliação 2 | Avaliação 3 | Média Trimestral\n");
            printf("[%.2f] | [%.2f] | [%.2f] = [%.2f]\n", dados[0][0], dados[0][1], dados[0][2], dados[0][3]);
            printf("\n--- 2° TRIMESTRE ----------------------------\n\n");
            printf("Avaliação 1 | Avaliação 2 | Avaliação 3 | Média Trimestral\n");
            printf("[%.2f] | [%.2f] | [%.2f] = [%.2f]\n", dados[1][0], dados[1][1], dados[1][2], dados[1][3]);
            printf("\n--- 3° TRIMESTRE ----------------------------\n\n");
            printf("Avaliação 1 | Avaliação 2 | Avaliação 3 | Média Trimestral\n");
            printf("[%.2f] | [%.2f] | [%.2f] = [%.2f]\n", dados[2][0], dados[2][1], dados[2][2], dados[2][3]);
            printf("\n---RESUTADO FINAL ---------------------------\n\n");
            printf("Média Final: [%.2f]\n", media_final);
            printf("Situação: ");
            if (media_final >= 7)
            {
                printf("Aprovado!\n");
            }
            else
            {
                printf("Reprovado!\n");
            }

            break;

        case 4:
            printf("Saindo...");
            break;

        default:
            printf("Opção selecionada incorreta!\nTente novamente.\n");
            break;
        }
    } while (opcao != 4);

    return 0;
}
