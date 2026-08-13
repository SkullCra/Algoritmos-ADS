#include <stdio.h>

void cadastro_cliente(void)
{
    printf("## Cadastro de Clientes ##\n");
    printf("X - Fim\n");
    printf("I - Inclui\n");
    printf("A - Altera\n");
    printf("E - Exclui\n");
    printf("C - Consulta\n");
    printf("Opção: ");
}

char opcao_menu;

int main () {
    printf("#### SISTEMAS ADYLNET TELECOM ####\n");
    cadastro_cliente();
    scanf(" %c", &opcao_menu);
    printf("Você escolheu: %c.", opcao_menu);

    return 0;
}