#include <stdio.h>

int main()
{
    float soma, sub, multi, divi, num1, num2;
    int opcao, qtdSoma = 0, qtdSub = 0, qtdMulti = 0, qtdDivi = 0, totalOp = 0;
    char opcao2;

    do
    {
        printf("\n\n### Calculadora simples ###\n\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicao\n");
        printf("4 - Divisao\n");
        printf("0 - Sair\n");

        do
        {
            printf("Escolha uma operacao para realizar\n\n");
            scanf("%d", &opcao);
            if (opcao < 0 || opcao > 4)
            {
                printf("Opcao invalida, tente novamente!\n");
            }
        } while (opcao < 0 || opcao > 4);

        switch (opcao)
        {
        case 1:
            printf("Você escolheu SOMA\n");
            printf("Informe o primeiro numero: ");
            scanf("%f", &num1);
            printf("Informe o segundo numero: ");
            scanf("%f", &num2);
            soma = num1 + num2;
            printf("A soma dos dois numeros é de %.2f.\n", soma);
            qtdSoma = qtdSoma + 1;

            break;

        case 2:
            printf("Você escolheu SUBTRACAO\n");
            printf("Informe o primeiro numero: ");
            scanf("%f", &num1);
            printf("Informe o segundo numero: ");
            scanf("%f", &num2);
            sub = num1 - num2;
            printf("A subtracao dos dois numeros é de %.2f.\n", sub);
            qtdSub = qtdSub + 1;

            break;

        case 3:
            printf("Você escolheu MULTIPLICACAO\n");
            printf("Informe o primeiro numero: ");
            scanf("%f", &num1);
            printf("Informe o segundo numero: ");
            scanf("%f", &num2);
            multi = num1 * num2;
            printf("A multiplicacao dos dois numeros é de %.2f.\n", multi);
            qtdMulti = qtdMulti + 1;

            break;

        case 4:
            printf("Você escolheu DIVISAO\n");
            printf("Informe o primeiro numero: ");
            scanf("%f", &num1);
            do
            {
                printf("Informe o segundo numero: ");
                scanf("%f", &num2);
                if (num2 == 0)
                {
                    printf("Divisão por zero é impossível!\n");
                }
                else
                {
                    divi = num1 / num2;
                    printf("A divisão dos dois numeros é de %.2f.\n", divi);
                }
            } while (num2 == 0);
            qtdDivi = qtdDivi + 1;

            break;

        case 0:
            printf("Voce escolheu sair...\n");

            return 0;
        }

        totalOp = totalOp + 1;
        printf("Deseja realizar uma nova operação? (S/N)\n");
        scanf(" %c", &opcao2);
        if (opcao2 == 'n' || opcao2 == 'N')
        {
            printf("Você escolheu sair...\n");
            printf("Foram realizadas %d somas.\n", qtdSoma);
            printf("Foram realizadas %d subtracoes.\n", qtdSub);
            printf("Foram realizadas %d multiplicacoes.\n", qtdMulti);
            printf("Foram realizadas %d divisoes.\n", qtdDivi);
            printf("O total de operacoes realizadas foi de %d operacoes.\n", totalOp);
            printf("Saindo agora...\n\n");
            return 0;
        }

    } while (opcao2 == 'S' || opcao2 == 's');

    return 0;
}