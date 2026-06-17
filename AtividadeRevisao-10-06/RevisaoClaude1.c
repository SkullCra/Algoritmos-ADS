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
    int opcao, qtdAlunos;
    float notas[20][4], media;
    char;

    printf("\n### SISTEMA DE BOLETIM ESCOLAR ###\n\n");
    printf("Selecione uma opção abaixo.\n");
    printf("1 - Lançar notas\n");
    printf("2 - Gerar boletim\n");
    printf("3 - Sair\n");
    printf("Sua opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {

        printf("Informe a quantidade de alunos da turma:(Máximo 20): ");
        scanf("%d", &qtdAlunos);
        for (int l = 0; l < qtdAlunos; l++)
        {
            printf("Informe as notas do aluno %d\n", l + 1);
            for (int c = 0; c < 3; c++)
            {
                do
                {
                    printf("Informe a nota da %dª prova: ", c + 1);
                    scanf("%f", &notas[l][c]);
                    if (notas[l][c] < 0 || notas[l][c] > 10)
                    {
                        printf("Valor inválido!\n");
                        printf("Notas devem estar entre 0 e 10.\n");
                    }
                } while (notas[l][c] < 0 || notas[l][c] > 10);
            }
            media = (notas[l][0] + notas[l][1] + notas[l][2]) / 3.0;
        }
        printf ("Notas lançadas!\n");
    }
    case 2: { 
        printf ("=================================\n");
        printf ("\tBOLETIM ESCOLAR\t\n");
        printf ("ALUNO\tPROVA 1\tPROVA 2\tPROVA 3\t MEDIA\tSITUAÇÃO");

    }
    }
}