#include <stdio.h>

// meu código = atribuição
int verificar_positivo(int a)
{
    if (a >= 0)
    {
        return 1;
    }
    if (a < 0)
    {
        return 0;
    }
}

int main()
{
    int numero;
    int resultado;

    printf("Digite um número: ");
    scanf("%d", &numero);

    resultado = verificar_positivo(numero);

    if (resultado == 1)
    {
        printf("O número %d é positivo!\n", numero);
    }
    if (resultado == 0)
    {
        printf("O número %d não é positivo!\n", numero);
    }

    return 0;
}

// código do Corino = Passagem de parâmetro.
void ePositivo (int a) {
    if (a >= 0) {
        printf ("O número é positivo!\n");
    }
    else printf("O número é negativo!\n");
}

int main () {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    ePositivo(numero);
}
// fim do Código do Corino