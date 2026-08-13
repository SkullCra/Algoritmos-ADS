#include <stdio.h>

float salarios_minimos(float salario, float minimo)
{
    float qtd_minimos = (salario / minimo);
    return qtd_minimos;
}

float salario_pessoa;
float minimo_atual;
float quantidade;

int main()
{
    printf("Informe o seu salário: ");
    scanf("%f", &salario_pessoa);
    printf("Informe o salário mínino atual: ");
    scanf("%f", &minimo_atual);
    quantidade = salarios_minimos(salario_pessoa, minimo_atual);
    printf("A quantidade de salários é %.2f.\n", quantidade);

    return 0;
}