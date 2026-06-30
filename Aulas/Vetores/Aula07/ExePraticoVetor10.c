#include <stdio.h>

int main()
{
    float num[10], maior, menor, soma = 0, media;
    int opcao, continuar, posMaior, posMenor;

    printf("## MENU DE OPERAÇÕES ##\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Informe o %dº número: ", i + 1);
        scanf("%f", &num[i]);
    }
    do
    {
        printf("\n ## MENU ##\n");
        printf("0 - Sair\n");
        printf("1 - Mostrar vetor (ordem direta)\n");
        printf("2 - Mostrar vetor (ordem inverna)\n");
        printf("3 - Maior e menor elemento\n");
        printf("4 - Media dos valores\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("Encerrando...\n");
            return 0;

            break;

        case 1:
            printf("\nOrdem direta: ");
            for (int i = 0; i < 10; i++)
            {
                printf("[%.2f] ", num[i]);
            }
            break;

        case 2:
            printf("\nOrdem inversa: ");
            for (int i = 9; i >= 0; i--)
            {
                printf("[%.2f] ", num[i]);
            }
            break;

        case 3:
            maior = num[0];
            menor = num[0];
            posMaior = 0;
            posMenor = 0;

            for (int i = 1; i < 10; i++)
            {
                if (num[i] > maior)
                {
                    maior = num[i];
                    posMaior = i;
                }
                if (num[i] < menor)
                {
                    menor = num[i];
                    posMenor = i;
                }
            }
            printf("\nMaior valor: %.2f, posição [%d].\n", maior, posMaior + 1);
            printf("Menor valor: %.2f, posição [%d].\n", menor, posMenor + 1);
            break;

        case 4:
        {
            for (int i = 0; i < 10; i++)
            {
                soma += num[i];
            }
            media = soma / 10.0;
            printf("\nMédia dos valores: %.2f.\n", media);
        }
        break;

        default:
            printf("\nCódigo inválido! Tente novamente!\n");
            continue;
        }
        printf("\nDeseja realizar outra operação? (1 - Sim / 0 - Não): ");
        scanf("%d", &continuar);
    } while (continuar == 1);

    printf("Encerrando...\n");
    return 0;
}