#include <stdio.h>

int main()
{
    float temperatura, maior, menor, amplitude, media = 0, somaTemp = 0;
    int totalTemp = 0, qtdCongelante = 0, qtdFria = 0, qtdAmena = 0, qtdQuente = 0, qtdMtoQuente = 0, qtdMedicoes = 0;
    char resposta;

    printf("### Classificador de Temperaturas ###\n\n");
    printf("Neste programa, será lido as temperaturas registradas em graus celsius, e lhe daremos inúmeras informações.\n\n");
    printf("INFORME QUANTAS MEDIÇÕES DESEJA REALIZAR\n");
    scanf("%d", &qtdMedicoes);

    if (qtdMedicoes <= 0)
    {
        printf("Nenhuma medição solicitada. Programa encerrado.\n");
        return 0;
    }

    while (totalTemp < qtdMedicoes)
    {
        do
        {
            printf("Informe uma temperatura: ");
            scanf("%f", &temperatura);

            if (temperatura < -50 || temperatura > 60)
            {
                printf("Valor inválido! Digite novamente.\n");
            }

        } while (temperatura < -50 || temperatura > 60);

        if (temperatura < 0)
        {
            printf("Congelante!\n");
            qtdCongelante = qtdCongelante + 1;
        }
        else if (temperatura >= 0 && temperatura < 15.00)
        {
            printf("Fria!\n");
            qtdFria = qtdFria + 1;
        }
        else if (temperatura >= 15.0 && temperatura < 25.00)
        {
            printf("Amena!\n");
            qtdAmena = qtdAmena + 1;
        }
        else if (temperatura >= 25.0 && temperatura < 35.00)
        {
            printf("Quente!\n");
            qtdQuente = qtdQuente + 1;
        }
        else if (temperatura >= 35.00)
        {
            printf("Muito quente!\n");
            qtdMtoQuente = qtdMtoQuente + 1;
        }

        if (totalTemp == 0)
        {
            menor = temperatura;
            maior = temperatura;
        }
        else
        {
            if (temperatura < menor)
            {
                menor = temperatura;
            }
            if (temperatura > maior)
            {
                maior = temperatura;
            }
        }
        totalTemp = totalTemp + 1;
        somaTemp = somaTemp + temperatura;
    }

    media = somaTemp / totalTemp;
    amplitude = maior - menor;

    printf("Deseja visualizar o relatório atual? (S/N)");
    scanf(" %c", &resposta);
    if (resposta == 'S' || resposta == 's')
    {
        printf("O total de medições realizadas foi de: %d medições.\n", totalTemp);
        printf("A temperatura média do período foi de %.2f graus celsius.\n", media);
        printf("A maior temperatura registrada foi de %.2f graus celsius.\n", maior);
        printf("A menor temperatura registrada foi de %.2f graus celsius.\n", menor);
        printf("Tivemos as seguintes quantidades de medições por classificação:\n");
        printf("Fria: %d medições.\n", qtdFria);
        printf("Amena: %d medições.\n", qtdAmena);
        printf("Quente: %d medições.\n", qtdQuente);
        printf("Muito quente: %d medições.\n\n", qtdMtoQuente);
        printf("A amplitute térmica desse período foi de: %.2f graus celsius.\n", amplitude);
    }
    else
    {
        printf("Você escolheu não visualizar o relatório, saindo...");
    }
    return 0;
}