#include <stdio.h>

int main()
{
    float saldo = 0, deposito, saque, depositado = 0, sacado = 0, taxas = 0, maiorSaque = 0, maiorDeposito = 0, taxa = 2.5;
    int opcao, depositos = 0, saques = 0;

    do
    {
        printf("### CAIXA ECONOMICA FEDERAL ###\n\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Consultar saldo\n");
        printf("4 - Consultar extrato resumido\n");
        printf("0 - Sair\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            do
            {
                printf("Informe o valor que deseja depositar: ");
                scanf("%f", &deposito);
                if (deposito <= 0)
                {
                    printf("Valor inválido, insira novamente");
                }

            } while (deposito <= 0);

            saldo = saldo + deposito;
            depositado = depositado + deposito;
            depositos = depositos + 1;
            if (maiorDeposito < deposito)
            {
                maiorDeposito = deposito;
            }

            printf("Valor depositado. Saldo atual é de R$ %.2f.\n", saldo);
            break;

        case 2:

            do
            {
                printf("Informe o valor que deseja sacar: ");
                scanf("%f", &saque);
                if (saque > saldo)
                {
                    printf("Saldo insuficiente! Insira um novo valor!\n\n");
                }
                else if (saque > 500)
                {
                    saque = saque - taxa;
                    saldo = (saldo - saque) - taxa;
                    taxas = taxas + 1;
                    printf("Valor acima de R$ 500,00. Foi aplicado uma taxa de R$ 2.50 no seu saque.\n");
                    printf("Valor sacado final é de R$ %.2f.\n", saque);
                    printf("Seu saldo atual é de R$ %.2f.\n", saldo);
                }

            } while (saque > saldo);

            sacado = sacado + saque;
            saques = saques + 1;
            saldo = saldo - saque;
            if (maiorSaque < saque)
            {
                maiorSaque = saque;
            }

            break;

        case 3:
            printf("Seu saldo atual é de: R$ %.2f reais.\n", saldo);

            break;

        case 4:
            printf("A quantidade de depósitos realizados é de: %d.\n", depositos);
            printf("A quantidade de saques realizados é de: %d.\n", saques);
            printf("O valor total depositado é de: R$ %.2f reais\n.", depositado);
            printf("O valor total sacado é de: R$ %.2f reais\n.", sacado);
            printf("O total de taxas pagas é de R$ %.2f.\n", taxas);
            printf("O saldo atual é de R$ %.2f reais.\n", saldo);
            printf("O maior depósito realizado foi de R$ %.2f.\n", maiorDeposito);
            printf("O maior saque realizado foi de: R$ %.2f.\n", maiorSaque);

            break;

        case 0:
            printf("Você escolheu sair...\n\n");

            break;

        default:
            printf("Opção inválida!\n\n");
        }
    } while (opcao != 0);

    return 0;
}