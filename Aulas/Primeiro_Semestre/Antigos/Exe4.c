// Conversor de Unidades com Menus//
// Desenvolva um programa que funcione como um conversor de unidades.//
// O programa exibe o menu, e dependendo da escolha, pede o valor a converter e exibe o resultado.//
// O programa continua até o usuário escolher sair. Ao final exibir estatísticas de uso.//

#include <stdio.h>

int main()
{
    float temp, km, milhas, distancia, reais, dolares, cotacao, fahrenheit, celsius;
    int opcao, conversoes = 0, qtd1 = 0, qtd2 = 0, qtd3 = 0, qtd4 = 0, qtd5 = 0, maiorQtd = 0, maisUsada = 0;

    do
    {
        printf("\n\n### CONVERSOR DE UNIDADES ###\n\n");
        printf("Escolha uma opção para converter:\n");
        printf("1 - Celsius para Fahrenheit\n");
        printf("2 - Fahrenheit para Celsius\n");
        printf("3 - Quilômetros para milhas\n");
        printf("4 - Milhas para quilômetros\n");
        printf("5 - Reais para Dólares\n");
        printf("0 - Sair\n");

        printf("Qual a opção desejada? ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            do
            {
                printf("Informe o valor em Celsius: ");
                scanf("%f", &temp);
                if (temp < -273 || temp > 1000)
                {
                    printf("Valor inválido, tente novamente!\n");
                }
            } while (temp < -273 || temp > 1000);

            fahrenheit = (temp * 1.8) + 32;
            printf("A temperatura de %.2f graus celsius é de %.2f graus Fahrenheit.\n", temp, fahrenheit);
            conversoes = conversoes + 1;
            qtd1 = qtd1 + 1;

            break;

        case 2:
            do
            {
                printf("Informe o valor em Fahrenheit: ");
                scanf("%f", &temp);
                if (temp < -459 || temp > 1832)
                {
                    printf("Valor inválido, tente novamente!\n");
                }
                celsius = (temp - 32) / 1.8;
                printf("A temperatura de %.2f graus Fahrenheit é de %.2f graus Celsius.\n", temp, celsius);
                conversoes = conversoes + 1;
                qtd2 = qtd2 + 1;
            } while (temp < -459 || temp > 1832);

            break;

        case 3:
            do
            {
                printf("Informe o valor em quilômetros: ");
                scanf("%f", &distancia);
                if (distancia <= 0)
                {
                    printf("Valor inválido, tente novamente!\n");
                }
                milhas = distancia / 1.609;
                printf("%.3F quilômetros é quivalente a %.3f milhas.\n", distancia, milhas);
                conversoes = conversoes + 1;
                qtd3 = qtd3 + 1;
            } while (distancia <= 0);

            break;

        case 4:
            do
            {
                printf("Informe o valor em milhas: ");
                scanf("%f", &distancia);
                if (distancia <= 0)
                {
                    printf("Valor inválido, tente novamente!\n");
                }
                km = distancia * 1.609;
                printf("%.3F milhas é quivalente a %.3f quilômetros.\n", distancia, km);
                conversoes = conversoes + 1;
                qtd4 = qtd4 + 1;
            } while (distancia <= 0);

            break;

        case 5:
            do
            {
                printf("Informe o valor em reais: ");
                scanf("%f", &reais);
                if (reais <= 0)
                {
                    printf("Valor inválido, tente novamente!\n");
                }
            } while (reais < 0);
            printf("Informe a cotação atual do dólar: ");
            scanf("%f", &cotacao);
            dolares = reais / cotacao;
            printf("%.2f reais é equivalente a %.2f dólares na cotação atual.\n", reais, dolares);
            conversoes = conversoes + 1;
            qtd5 = qtd5 + 1;

            break;

        case 0:
            if (qtd1 > maiorQtd)
            {
                maiorQtd = qtd1;
                maisUsada = 1;
            }
            if (qtd2 > maiorQtd)
            {
                maiorQtd = qtd2;
                maisUsada = 2;
            }
            if (qtd3 > maiorQtd)
            {
                maiorQtd = qtd3;
                maisUsada = 3;
            }
            if (qtd4 > maiorQtd)
            {
                maiorQtd = qtd4;
                maisUsada = 4;
            }
            if (qtd5 > maiorQtd)
            {
                maiorQtd = qtd5;
                maisUsada = 5;
            }

            if (conversoes == 0)
            {
                printf("Você escolheu sair...\n");
                printf("Nenhuma operação foi realizada.\n");
                return 0;
            }

            else
            {
                printf("Você escolheu sair...\n");
                printf("O total de conversões realizadas foi de %d.\n", conversoes);
                printf("O tipo de conversão mais utilizado foi a %d.\n", maisUsada);
                return 0;
            }

            break;

        default:
            printf("Opção inválida, tente novamente!\n");
        }

    } while (opcao != 0);
}