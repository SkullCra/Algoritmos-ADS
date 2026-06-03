#include <stdio.h>

int main()
{
    float nota1, nota2, media, maior = 0, menor = 0, mediaGeral = 0, frequencia, somaMedia = 0;
    int matricula, faltas, opcao, situacao, aprovados = 0, reprovados = 0, recuperacao = 0, matriculados = 0, alunoOuro = 0, alunoCouro = 0;

    do
    {
        printf("\n\n### COLÉGIO SÃO LUIZ GONZAGA ###\n\n");
        printf("1 - Cadastrar aluno.\n");
        printf("2 - Exibir relatório parcial.\n");
        printf("0 - Encerrar o programa.\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            do
            {
                printf("Informe a matrícula do aluno: ");
                scanf("%d", &matricula);
                if (matricula <= 0)
                {
                    printf("Opção inválida! Digite novamente!\n\n");
                }
            } while (matricula <= 0);

            do
            {
                printf("Informe o número de faltas: ");
                scanf("%d", &faltas);
                if (faltas < 0 || faltas > 20)
                {
                    printf("Opção inválida! Digite novamente!\n\n");
                }
            } while (faltas < 0 || faltas > 20);

            do
            {
                printf("Informe a primeira nota: ");
                scanf("%f", &nota1);
                if (nota1 < 0 || nota1 > 10)
                {
                    printf("Opção inválida! Digite novamente!\n\n");
                }
            } while (nota1 < 0 || nota1 > 10);

            do
            {
                printf("Informe a segunda nota: ");
                scanf("%f", &nota2);
                if (nota2 < 0 && nota2 > 10)
                {
                    printf("Opção inválida! Digite novamente!\n\n");
                }
            } while (nota2 < 0 && nota2 > 10);

            media = (nota1 + nota2) / 2;
            if (matriculados == 0)
            {
                maior = media;
                alunoOuro = matricula;
                menor = media;
                alunoCouro = matricula;
            }
            else
            {
                if (media > maior)
                {
                    maior = media;
                    alunoOuro = matricula;
                }
                if (media < menor)
                {
                    menor = media;
                    alunoCouro = matricula;
                }
            }

            frequencia = ((20 - faltas) * 100.0) / 20;
            matriculados = matriculados + 1;
            somaMedia = somaMedia + media;

            if (media >= 7.0 && frequencia >= 75.00)
            {

                printf("Aprovado! A sua média foi de %.2f, e a frequência de %.2f por cento.\n", media, frequencia);
                aprovados = aprovados + 1;
            }
            else if (media >= 5.0 && frequencia >= 75.00)
            {

                printf("Aluno em recuperação! A sua média foi de %.2f, e a frequência de %.2f por cento.\n", media, frequencia);
                recuperacao = recuperacao + 1;
            }
            else
            {
                printf("Reprovado! A sua média foi de %.2f, e a frequência de %.2f por cento.\n", media, frequencia);
                reprovados = reprovados + 1;
            }
            break;

        case 2:
            if (matriculados > 0)
                mediaGeral = somaMedia / matriculados;

            printf("Você escolheu exibir relatório parcial.\n\n");
            printf("O total de alunos cadastrados é de %d alunos.\n", matriculados);
            printf("A média geral da turma é de %.2f.\n", mediaGeral);
            printf("A quantidade de aprovados é de %d, alunos aprovados.\n", aprovados);
            printf("A quantidade de alunos em recuperação é de %d, alunos em recuperação.\n", recuperacao);
            printf("A quantidade de alunos reprovados é de %d, alunos reprovados.\n", reprovados);
            printf("A maior média da turma é de %.2f, do aluno matriculado com número %d.\n", maior, alunoOuro);
            printf("A menor média da turma é de %.2f, do aluno matriculado com número %d.\n", menor, alunoCouro);


            break;

        case 0:
            printf("0 - Encerrar o programa.\n");
            printf("Você escolheu exibir relatório parcial.\n\n");
            printf("O total de alunos cadastrados é de %d alunos.\n", matriculados);
            printf("A média geral da turma é de %.2f.\n", mediaGeral);
            printf("A quantidade de aprovados é de %d, alunos aprovados.\n", aprovados);
            printf("A quantidade de alunos em recuperação é de %d, alunos em recuperação.\n", recuperacao);
            printf("A quantidade de alunos reprovados é de %d, alunos reprovados.\n", reprovados);
            printf("A maior média da turma é de %.2f, do aluno matriculado com número %d.\n", maior, alunoOuro);
            printf("A menor média da turma é de %.2f, do aluno matriculado com número %d.\n", menor, alunoCouro);
            break;

        default:
            printf("Opção inválida!.\n");
        }

    } while (opcao != 0);

    return 0;
}