// Desenvolver um programa que calcule imposto de renda de várias pessoas.
// O usuário informa quantas pessoas serão calculadas (Entre 1 e 50)
// Para cada pessoa, informa o salário mensal e a quantidade de dependentes.
// Quantidade de pessoas entre 1 e 50 | Salário Maior que 0 | Dependentes entre 0 e 15.
// Calculos:
// Base de cálculo = Salário - (Dependentes x 189,59)
// Faixa 1: Base até 2.259.20 -> Isento
// Faixa 2: Base de 2.259,21 até 2.826,65 → 7,5% − 169,44
// Faixa 3: base de 2.826,66 até 3.751,05 → 15% − 381,44
// Faixa 4: base de 3.751,06 até 4.664,68 → 22,5% − 662,77
// Faixa 5: base acima de 4.664,68 → 27,5% − 896,00
//(Se o cálculo der negativo, imposto é 0)
// Para cada pessoa, exibir o valor do imposto e a faixa.
// Relatório final:
// Total de pessoas processadas
// Quantidade de pessoas em cada faixa
// Total arrecadado em impostos
// Imposto médio por pessoa
// Maior imposto pago e em qual pessoa (nº 1, 2...)
// Menor imposto pago (entre os não isentos) e em qual pessoa
// Quantidade de pessoas isentas

#include <stdio.h>

int main()
{
    float salario, impostosTotais = 0, impostoMedio, maior = 0, menor = 0, base, imposto;
    int pessoas, qtdIsentas = 0, dependentes = 0, i = 0, qtd1 = 0, qtd2 = 0, qtd3 = 0, qtd4 = 0, qtd5 = 0, pessoaMaior = 0, pessoaMenor = 0;

    printf("\n\n### PROGRAMA DO LEAOZINHO ###\n\n");
    printf("Neste programa iremos calcular o imposto de renda.\n");

    do
    {
        printf("Informe quantas pessoas você deseja calcular: ");
        scanf("%d", &pessoas);

        if (pessoas < 1 || pessoas > 50)
        {
            printf("Valor inválido, tente novamente!");
        }
    } while (pessoas < 1 || pessoas > 50);

    while (i != pessoas)
    {
        do
        {
            printf("Informe o salário mensal: ");
            scanf("%f", &salario);
            if (salario <= 0)
            {
                printf("Valor inválido. Insira novamente.\n");
            }
        } while (salario <= 0);

        do
        {
            printf("Informe a quantidade de dependentes: ");
            scanf("%d", &dependentes);
            if (dependentes < 0 || dependentes > 15)
            {
                printf("Valor inválido. Insira novamente.\n");
            }
        } while (dependentes < 0 || dependentes > 15);
        base = salario - (dependentes * 189.59);

        if (base <= 2259.20)
        {
            imposto = 0;
            printf("Faixa 1: Isento de imposto de renda.\n");
            qtdIsentas = qtdIsentas + 1;
            qtd1 = qtd1 + 1;
        }
        else if (base >= 2259.21 && base <= 2826.65)
        {
            imposto = (base * 0.075) - 169.44;
            if (imposto < 0)
            {
                imposto = 0;
                printf("Isento de imposto de renda.\n");
            }
            else
            {
                printf("Faixa 2: Imposto de 7,5 por cento.\n");
                printf("Valor do imposto de %.2f reais.\n\n", imposto);
            }
            qtd2 = qtd2 + 1;
        }
        else if (base >= 2826.66 && base <= 3751.05)
        {
            imposto = (base * 0.15) - 381.44;
            if (imposto < 0)
            {
                imposto = 0;
                printf("Isento de imposto de renda.\n");
            }
            else
            {
                printf("Faixa 3: Imposto de 15 por cento.\n");
                printf("Valor do imposto de %.2f reais.\n\n", imposto);
            }
            qtd3 = qtd3 + 1;
        }
        else if (base >= 3751.06 && base <= 4664.68)
        {
            imposto = (base * 0.225) - 662.77;
            if (imposto < 0)
            {
                imposto = 0;
                printf("Isento de imposto de renda.\n");
            }
            else
            {
                printf("Faixa 4: Imposto de 22.5 por cento.\n");
                printf("Valor do imposto de %.2f reais.\n\n", imposto);
            }
            qtd4 = qtd4 + 1;
        }
        else if (base > 4664.68)
        {
            imposto = (base * 0.275) - 896.00;
            if (imposto < 0)
            {
                imposto = 0;
                printf("Isento de imposto de renda.\n");
            }
            else
            {
                printf("Faixa 5: Imposto de 27.5 por cento.\n");
                printf("Valor do imposto de %.2f reais.\n\n", imposto);
            }
            qtd5 = qtd5 + 1;
        }
        impostosTotais = impostosTotais + imposto;
        impostoMedio = impostosTotais / pessoas;
        if (imposto > maior)
        {
            maior = imposto;
            pessoaMaior = i + 1;
        }
        if (imposto > 0)
        {
            if (menor == 0 || imposto < menor)
            {
                menor = imposto;
                pessoaMenor = i + 1;
            }
        }

        i = i + 1;
    }
    printf("### Relatório final ###\n\n");
    printf("O total de pessoas processadas foi de: %d\n", pessoas);
    printf("A quantidade de pessoas da Faixa 1 foi de: %d.\n", qtd1);
    printf("A quantidade de pessoas da Faixa 2 foi de: %d.\n", qtd2);
    printf("A quantidade de pessoas da Faixa 3 foi de: %d.\n", qtd3);
    printf("A quantidade de pessoas da Faixa 4 foi de: %d.\n", qtd4);
    printf("A quantidade de pessoas da Faixa 5 foi de: %d.\n", qtd5);
    printf("A quantidade de pessoas isentas é de %d.\n", qtdIsentas);
    printf("A quantidade total de impostos foi de R$ %.2f.\n", impostosTotais);
    printf("O maior imposto foi de %.2f, da pessoa %d.\n", maior, pessoaMaior);
    printf("O menor imposto (Não isentos) foi de R$ %.2f, da pessoa %d.\n", menor, pessoaMenor);
    printf("O imposto médio foi de R$ %.2f.", impostoMedio);
}