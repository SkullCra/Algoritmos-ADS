#include <stdio.h>

float somar(float a, float b)
{
    return a + b;
}

float subtrair(float a, float b)
{
    return a - b;
}

float multiplicacao(float a, float b)
{
    return a * b;
}

float divisao(float a, float b)
{
    return a / b;
}

float num1, num2;
int opcao;
float somado, subtraido, multiplicado, dividido;

int main()
{
    printf("Exercício 10 de funções!\n");
    printf("Funções com retorno!\n");
    printf("Calculadora modular!\n\n");
    do
    {
        do
        {
            printf("\nEscolha uma opção abaixo:\n");
            printf("1 - Somar\n");
            printf("2 - Subtrair\n");
            printf("3 - Multiplicação\n");
            printf("4 - Divisão\n");
            printf("0 - Sair\n");
            printf("Sua escolha: ");
            scanf("%d", &opcao);

            if (opcao < 0 || opcao > 4)
            {
                printf("Opção inválida!\n");
            }
        } while (opcao < 0 || opcao > 4);
        switch (opcao)
        {

        case 0:
            printf("\n");
            printf("Saindo...\n");
            break;
        case 1:
        printf("\n");    
        printf("Soma!\n");
            printf("Informe o primeiro número: ");
            scanf("%f", &num1);
            printf("Informe o segundo número: ");
            scanf("%f", &num2);
            somado = somar(num1, num2);
            printf("O valor somado é de %.2f!\n", somado);
            break;
        case 2:
            printf("\n");
            printf("Subtração!\n");
            printf("Informe o primeiro número: ");
            scanf("%f", &num1);
            printf("Informe o segundo número: ");
            scanf("%f", &num2);
            subtraido = subtrair(num1, num2);
            printf("O valor subtraído é de %.2f!\n", subtraido);
            break;
        case 3:
            printf("\n");
            printf("Multiplicação!\n");
            printf("Informe o primeiro número: ");
            scanf("%f", &num1);
            printf("Informe o segundo número: ");
            scanf("%f", &num2);
            multiplicado = multiplicacao(num1, num2);
            printf("O valor multiplicado é de %.2f!\n", multiplicado);
            break;
        case 4:
            printf("\n");
            printf("Divisão!\n");
            do
            {
                printf("Informe o primeiro número: ");
                scanf("%f", &num1);
                if (num1 == 0)
                {
                    printf("ERRO: Impossível dividir por zero!\n");
                }
            } while (num1 == 0);
            do
            {
                printf("Informe o segundo número: ");
                scanf("%f", &num2);
                if (num2 == 0)
                {
                    printf("ERRO: Impossível dividir por zero!\n");
                }
            } while (num2 == 0);
            dividido = divisao(num1, num2);
            printf("O valor dividido é de %.2f!\n", dividido);
            break;
        default:
            printf("\n");
            printf("ERRO: Opção inválida!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}