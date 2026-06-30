// Desenvolver um jogo onde o usuário tenta adivinhar um número secreto. Ex: 42.
// A cada tentativa o programa informa se o palpite é maior, menor ou igual ao número.
// O jogo continua até o usuário acertar ou desistir digitando -1.
// Palpites entre 1 e 100 (exceto -1 que significa desistência).
// Limite de 10 tentativas, se exceder, exibir "Fim de jogo", e mostrar o número.

#include <stdio.h>
int main()
{
    int tentativas = 0, secreto = 42, numero, pontos = 0, errou = 0, acertou = 0;
    char opcao;

    do
    {
        printf("\n\n### JOGO DA ADIVINHACAO ###\n\n");
        printf("Bem-vindo ao jogo da adivinhação.\n");
        printf("Neste jogo seu objetivo será advinhar o número secreto.\n");
        printf("Você tem 10 tentativas para advinhar o número secreto.\n");
        printf("Os palpites devem ser entre 1 e 100.\n");
        printf("Para desistir, digite: -1.\n");
        printf("Deseja começar? S/N\n\n");
        scanf(" %c", &opcao);

        if (opcao == 'S' || opcao == 's')
        {
            printf("Vamos começar...\n");
            do
            {
                do
                {
                    printf("Informe um número: ");
                    scanf("%d", &numero);
                    if (numero < 1 || numero > 100)
                    {
                        printf("Número inválido! Digite novamente!\n");
                    }
                } while ((numero < 1 || numero > 100) && numero != -1);
                if (numero == -1)
                {
                    printf("Você escolheu desistir...");
                    return 0;
                }
                tentativas = tentativas + 1;
                if (numero == secreto)
                {
                    printf("Parabéns, você acertou!\n");
                    acertou = acertou + 1;

                    if (tentativas == 1)
                    {
                        printf("Você ganhou 100 pontos.\n");
                        pontos = pontos + 100;
                    }
                    if (tentativas >= 2 && tentativas <= 3)
                    {
                        printf("Você ganhou 70 pontos.\n");
                        pontos = pontos + 70;
                    }
                    if (tentativas >= 4 && tentativas <= 6)
                    {
                        printf("Você ganhou 40 pontos.\n");
                        pontos = pontos + 40;
                    }
                    if (tentativas >= 7 & tentativas <= 10)

                    {
                        printf("Você ganhou 10 pontos.\n");
                        pontos = pontos + 10;
                    }
                }
                if (numero > secreto)
                {
                    printf("Errou!\n");
                    printf("O número é maior que o número secreto.\n");
                    errou = errou + 1;
                }
                if (numero < secreto)
                {
                    printf("Errou!\n");
                    printf("O número é menor que o número secreto.\n");
                    errou = errou + 1;
                }
                printf("Deseja jogar novamente? S/N\n");
                scanf(" %c", &opcao);
                if (opcao == 'N' || opcao == 'n')
                {
                    printf("Que pena...\n");
                    printf ("Você fez %d tentativas.\n", tentativas);
                    printf("Você fez %d pontos.\n", pontos);
                    printf ("Acertou %d palpite(s).\n", acertou);
                    printf ("Errou %d palpite(s).\n", errou);

                    return 0;
                };

            } while ((opcao == 'S' || opcao == 's') && (tentativas < 10));

            if (tentativas == 10)
            {
                printf("Acabou as chances, que pena!\n");
                printf("O número secreto era %d.\n\n", secreto);
            }

            printf("Deseja jogar mais uma vez? S/N\n");
            scanf(" %c", &opcao);
        }

        if (opcao == 'N' || opcao == 'n')
        {
            printf("Que pena...\n");
            printf("Saindo...\n");
            return 0;
        }
    } while (opcao == 'S' || opcao == 's');

    return 0;
}