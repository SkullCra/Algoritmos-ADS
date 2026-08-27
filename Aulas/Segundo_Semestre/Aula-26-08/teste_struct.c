#include <stdio.h>
#include <string.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

enum SituacaoAluno
{
    MATRICULADO = 1,
    TRANCADO = 2,
    FORMADO = 3
};

struct Aluno
{
    int matricula;
    char nome[50];
    float media;
    enum SituacaoAluno situacao;
};

int main()
{
    struct Aluno alunos[30];
    int qtd_desejada = 0;
    enum SituacaoAluno situacao[30];
    int opcao_situacao = 0;

    printf("Quantos alunos deseja cadastrar?\n");
    scanf("%d", &qtd_desejada);
    limparBuffer();

    for (int i = 0; i < qtd_desejada; i++)
    {
        struct Aluno aluno[i];
        printf("Aluno %d\n", i + 1);

        int matriculaRepetida = 0;
        do
        {
            matriculaRepetida = 0;
            printf("Insira a matricula do aluno: ");
            scanf("%d", &alunos[i].matricula);

            for (int j = 0; j < 1; j++)
            {
                if (alunos[i].matricula == alunos[j].matricula)
                {
                    matriculaRepetida = 1;
                    printf("ERRO: Matricula já cadastrada!\n");
                    break;
                }
            }
        } while (matriculaRepetida);
        limparBuffer();

        do
        {
            printf("Insira o nome do aluno: ");
            fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
            alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
            if (strcmp(alunos[i].nome, alunos[i + 1].nome) == 0)
            {
                printf("ERRO: Nome do aluno já cadastrado!\n");
            }
        } while (strcmp(alunos[i].nome, alunos[i + 1].nome) == 0);

        printf("Insira a média do aluno: ");
        scanf("%f", &alunos[i].media);
        limparBuffer();

        do
        {
            printf("Informe a situação do aluno:\n");
            printf("1 - Matriculado\n");
            printf("2 - Trancado\n");
            printf("3 - Formado\n");
            printf("Situação do aluno: ");
            scanf("%d", &opcao_situacao);
            if (opcao_situacao < MATRICULADO || opcao_situacao > FORMADO)
            {
                printf("ERRO: Opção inválida!\n");
            }
        } while (opcao_situacao < MATRICULADO || opcao_situacao > FORMADO);
        situacao[i] = (enum SituacaoAluno)opcao_situacao;
        limparBuffer();
        printf("\n");
    }

    for (int i = 0; i < qtd_desejada; i++)
    {
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Nome do aluno: %s\n", alunos[i].nome);
        printf("Média: %.2f\n", alunos[i].media);
        switch (situacao[i])
        {
        case MATRICULADO:
            printf("O aluno está matriculado.\n");
            break;
        case TRANCADO:
            printf("O aluno está com a matricula trancada.\n");
            break;
        case FORMADO:
            printf("O aluno está formado.\n");
            break;
        default:
            printf("ERRO\n");
        }
    }

    return 0;
}