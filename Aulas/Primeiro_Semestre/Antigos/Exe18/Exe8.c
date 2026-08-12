#include <stdio.h>

int main() {
    int num1, num2;
    char op, resposta;

    do {
        printf("Informe um numero inteiro: ");
        scanf("%d", &num1);

        printf("Informe um novo numero inteiro: ");
        scanf("%d", &num2);

        printf("\nEscolha a operacao:\n");
        printf("a -> Divisao\n");
        printf("b -> Multiplicacao\n");
        printf("c -> Soma\n");
        printf("d -> Subtracao\n");
        printf("\nDigite a operacao desejada: ");
        scanf(" %c", &op);

        switch (op) {
            case 'a':
                if (num2 == 0) {
                    printf("\nErro: divisao por zero nao e permitida!\n");
                } else {
                    printf("\nResultado: %d / %d = %d\n", num1, num2, num1 / num2);
                }
                break;

            case 'b':
                printf("\nResultado: %d * %d = %d\n", num1, num2, num1 * num2);
                break;

            case 'c':
                printf("\nResultado: %d + %d = %d\n", num1, num2, num1 + num2);
                break;

            case 'd':
                printf("\nResultado: %d - %d = %d\n", num1, num2, num1 - num2);
                break;

            default:
                printf("\nErro: opcao invalida!\n");
                break;
        }

        // Loop para validar a resposta S/N
        do {
            printf("\nVoce deseja realizar novo calculo (S/N)? ");
            scanf(" %c", &resposta);

            if (resposta != 'S' && resposta != 's' &&
                resposta != 'N' && resposta != 'n') {
                printf("Erro: caractere invalido! Digite apenas S ou N.\n");
            }

        } while (resposta != 'S' && resposta != 's' &&
                 resposta != 'N' && resposta != 'n');

    } while (resposta == 'S' || resposta == 's');

    printf("\nEncerrando o programa. Ate logo!\n");

    return 0;
}