#include <stdio.h>
#include <math.h>
#include <string.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n')
        ;
}

int main()
{
    char razaoSocial[101], CNPJ[12], endereco[200], nome[41], dataNascimento[9], cargo, mesReferencia[3];
    int dependentes, opcao;
    float horaTrabalhada, salario;

    printf("\n\n### PROGRAMA FOLHA DE PAGAMENTO ###\n\n");
    printf("Selecione a opção desejada.\n");
    printf("1 - Configurar dados da empresa.\n");
    printf("2 - Calcular salário mensal.\n");
    printf("3 - Sair.\n\n");
    scanf("%d", &opcao);
    limparBuffer();

    switch (opcao)
    {
    case 1:
        do
        {
            printf("Informe a Razão Social da empresa: ");
            fgets(razaoSocial, sizeof(razaoSocial), stdin);
            razaoSocial[strcspn(razaoSocial, "\n")] = '\0';
            if (strlen(razaoSocial) == 0)
            {
                printf("Não é permitido deixar opções em branco.\n");
            }
        } while (strlen(razaoSocial) == 0);

        do
        {
            printf("Informe o CNPJ da empresa (apenas digitos): ");
            fgets(CNPJ, sizeocf(CNPJ), stdin);
            CNPJ[strcspn(CNPJ, "\n")] = '\0';
            if (strlen(CNPJ) == 0)
            {
                printf("Não é permitido deixar opções em branco.\n");
            }
        } while (strlen(CNPJ) == 0);

        do
        {
            printf("Informe o seu endereço completo(Rua, Número, Bairro, Cidade, Estado, CEP): ");
            fgets(endereco, sizeof(endereco), stdin);
            endereco[strcspn(endereco, "\n")] = '\0';
            if (strlen(endereco) == 0)
            {
                printf("Não é permitido deixar opções em branco.\n");
            }
        } while (strlen(endereco) == 0);
    }
}