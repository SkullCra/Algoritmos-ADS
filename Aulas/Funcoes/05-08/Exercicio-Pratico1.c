#include <stdio.h>

// Void é usado porque a função apenas imprime na tela
// não "devolve" nenhum valor
void imprimir_tabuada(int a)
{
    printf("Tabuada do %d:\n", a);
    printf("------------\n");

    // Loop de 1 a 10 para calcular e imprimir
    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", a, i, a * i);
    }
    printf("\n");
}

int main()
{
    int valor;

    printf("Digite um número de 1 a 9 para ver sua tabuada:\n");
    printf("Sua escolha: ");
    scanf("%d", &valor);

    // Chama a função e entrega a ela o valor digitado
    imprimir_tabuada(valor);

    return 0;
}

// código do Corino
void imprimeTabuada()
{
    int numero;
    printf("Digite um número de 1 a 9: ");
    scanf("%d", &numero);

    for (int i = 1; i < 10; i++)
    {
        printf("%d * %d = %d\n", numero, i, numero * i);
    }
    printf("\n");
}

int main () {
    imprimeTabuada();
}
// fim do código do Corino