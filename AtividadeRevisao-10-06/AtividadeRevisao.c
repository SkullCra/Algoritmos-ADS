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
    char razaoSocial[101], CNPJ[16], endereco[201], nome[41], dataNascimento[11], cargo[41], mesReferencia[3];
    int dependentes, opcao;
    float horaTrabalhada, valorHora, salarioBase, horaExtra, valorExtra, valorFaixa1, valorFaixa2, valor_INSS;

    do
    {
        printf("\n\n### PROGRAMA FOLHA DE PAGAMENTO ###\n\n");
        printf("Selecione a opção desejada.\n");
        printf("1 - Configurar dados da empresa.\n");
        printf("2 - Calcular salário mensal.\n");
        printf("3 - Sair.\n\n");
        printf("Sua opção: ");
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
                fgets(CNPJ, sizeof(CNPJ), stdin);
                CNPJ[strcspn(CNPJ, "\n")] = '\0';
                if (strlen(CNPJ) == 0)
                {
                    printf("Não é permitido deixar opções em branco.\n");
                }
                if (strlen(CNPJ) != 14)
                {
                    printf("O CNPJ deve possuir 14 dígitos.\n");
                }

            } while (strlen(CNPJ) == 0 || strlen(CNPJ) != 14);

            do
            {
                printf("Informe o endereço completo(Rua, Número, Bairro, Cidade, Estado, CEP): ");
                fgets(endereco, sizeof(endereco), stdin);
                endereco[strcspn(endereco, "\n")] = '\0';
                if (strlen(endereco) == 0)
                {
                    printf("Não é permitido deixar opções em branco.\n");
                }

            } while (strlen(endereco) == 0);

            break;
        case 2:
            printf("Informe seus dados.\n");
            do
            {
                printf("Informe o seu nome completo: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                if (strlen(nome) == 0)
                {
                    printf("Não é permitido deixar opções em branco.\n");
                }

            } while (strlen(nome) == 0);

            do
            {
                printf("Informe o seu cargo: ");
                fgets(cargo, sizeof(cargo), stdin);
                cargo[strcspn(cargo, "\n")] = '\0';
                if (strlen(cargo) == 0)
                {
                    printf("Não é permitido deixar opções em branco.\n");
                }

            } while (strlen(cargo) == 0);

            do
            {
                printf("Informe a sua data de nascimento (XX/XX/XXXX): ");
                fgets(dataNascimento, sizeof(dataNascimento), stdin);
                dataNascimento[strcspn(dataNascimento, "\n")] = '\0';
                if (strlen(dataNascimento) == 0)
                {
                    printf("Não é permitido deixar opções em branco.\n");
                }
                if (strlen(dataNascimento) != 10)
                {
                    printf("A data de nascimento deve possuir 10 digitos.\n");
                }

            } while (strlen(dataNascimento) == 0 || strlen(dataNascimento) != 10);

            do
            {
                printf("Informe o número de dependentes: ");
                scanf("%d", &dependentes);
            
                if (dependentes < 0)
                {
                    printf("Número de dependentes não pode ser negativo.\n");
                }

            } while (dependentes < 0);

            limparBuffer();

            do
            {
                printf("Informe o mês de referencia (XX): ");
                fgets(mesReferencia, sizeof(mesReferencia), stdin);
                mesReferencia[strcspn(mesReferencia, "\n")] = '\0';
                if (strlen(mesReferencia) == 0)
                {
                    printf("Não é permitido deixar opções em branco.\n");
                }

            } while (strlen(mesReferencia) == 0);

            do
            {
                printf("Informe o número de horas trabalhadas: ");
                scanf("%f", &horaTrabalhada);

                if (horaTrabalhada < 0)
                {
                    printf("Número de horas trabalhadas não pode ser negativo.\n");
                }

            } while (horaTrabalhada < 0);

            limparBuffer();

            do
            {
                printf("Informe o valor da hora trabalhada: ");
                scanf("%f", &valorHora);

                if (valorHora <= 0)
                {
                    printf("Valor de horas trabalhadas não pode ser zero, ou negativo.\n");
                }

            } while (valorHora <= 0);

            limparBuffer();

            salarioBase = horaTrabalhada * valorHora;
            if (horaTrabalhada > 220 && horaTrabalhada < 240)
            {
                horaExtra = horaTrabalhada - 220;
                horaExtra = horaExtra * 1.25;
                valorExtra = valorHora + horaExtra;
            }
            if (horaTrabalhada >= 240)
            {
                horaExtra = horaTrabalhada - 220;
                horaExtra = horaExtra * 1.5;
                valorExtra = valorHora + horaExtra;
            }
            else
            {
                horaExtra = 0;
            }

            if (salarioBase <= 1621)
            {
                valor_INSS = salarioBase * 0.075;
            }
            else if (salarioBase <= 2902.84)
            {
                valor_INSS = (1621 * 0.075) + ((salarioBase - 1621) * 0.09);
            }
            else if (salarioBase <= 4354.27) {
                valor_INSS = (1621 * 0.075) + ((salarioBase - 1621) * 0.09) + ((salarioBase - 2902.84) * 0.12);
            }
            else if (salarioBase <= )
        }

    } while (opcao != 3);
}
