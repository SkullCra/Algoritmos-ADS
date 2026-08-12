#include <stdio.h>

float calcular_media(float n1, float n2, float n3)
{
    float media = ((n1 + n2 + n3) / 3);
    return media;
}

float nota1, nota2, nota3, media_final;

int main()
{
    printf("Exercício 8 de funções!\n");
    printf("Funções com retorno!\n");
    printf("Média aritmética!\n\n");
    printf("Informe a primeira nota: ");
    scanf("%f", &nota1);
    printf("Informe a segunda nota: ");
    scanf("%f", &nota2);
    printf("Informe a terceira nota: ");
    scanf("%f", &nota3);
    printf("Calculando...\n");
    media_final = calcular_media(nota1, nota2, nota3);

    printf("A média final foi de %.2f.\n", media_final);
    if (media_final >= 6.0)
    {
        printf("O aluno foi aprovado!\n");
    }
    else
    {
        printf("O aluno foi reprovado!\n");
    }

    return 0;
}