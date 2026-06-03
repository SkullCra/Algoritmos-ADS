/*Faça um programa em C (com a estrutura do.while) que leia valores inteiros. A cada leitura, exibir a seguinte mensagem: Deseja informar novo número(S/N)?
Se a resposta for S ou s o programa deverá realizar nova leitura. Caso N ou n, avançar para a etapa de cálculos. Qualquer outro caractere deverá informar
mensagem de erro e solicitar nova entrada.
Para cada série de números:
    – Encontre e mostre o maior valor;
    – Encontre e mostre o menor valor;
    – Calcule e mostre a média dos números lidos;
Ao final do programa deve ser impressa a seguinte mensagem: Você deseja avaliar nova série de números (S/N)?
Se a resposta for S ou s o programa deverá retornar ao começo, N ou n encerrar sua execução. Qualquer outro caractere deverá informar mensagem de erro e solicitar nova entrada. */

#include <stdio.h>

int main()
{
    int numero, maior, menor, soma, contador;
    char opcao, novaSerie;

    do
    {
        // Inicialização de variáveis para nova série
        soma = 0;
        contador = 0;
        maior = 0;
        menor = 0;

        printf("\n--- Nova Série de Números ---\n");

        do
        {
            printf("Digite um número inteiro: ");
            scanf("%d", &numero);

            // Atualiza estatísticas
            if (contador == 0)
            {
                maior = menor = numero;
            }
            else
            {
                if (numero > maior)
                    maior = numero;
                if (numero < menor)
                    menor = numero;
            }

            soma += numero;
            contador++;

            // Pergunta se deseja informar novo número
            do
            {
                printf("Deseja informar novo número (S/N)? ");
                scanf(" %c", &opcao);
                if (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N')
                {
                    printf("Opção inválida. Tente novamente.\n");
                }
            } while (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N');

        } while (opcao == 's' || opcao == 'S');

        // Exibe os resultados
        if (contador > 0)
        {
            float media = (float)soma / contador;
            printf("\nResultados da Série:\n");
            printf("Maior número: %d\n", maior);
            printf("Menor número: %d\n", menor);
            printf("Média: %.2f\n", media);
        }
        else
        {
            printf("Nenhum número foi informado.\n");
        }

        // Pergunta se deseja iniciar nova série
        do
        {
            printf("\nVocê deseja avaliar nova série de números (S/N)? ");
            scanf(" %c", &novaSerie);
            if (novaSerie != 's' && novaSerie != 'S' && novaSerie != 'n' && novaSerie != 'N')
            {
                printf("Opção inválida. Tente novamente.\n");
            }
        } while (novaSerie != 's' && novaSerie != 'S' && novaSerie != 'n' && novaSerie != 'N');

    } while (novaSerie == 's' || novaSerie == 'S');

    printf("Programa encerrado.\n");
}
