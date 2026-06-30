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
    char razaoSocial[101], CNPJ[16], endereco[501], nome[41], diaNasc[4], mesNasc[4], anoNasc[6], cargo[41], mesReferencia[3];
    int dependentes, opcao, adicional;
    float horaTrabalhada, valorHora, salarioBase, salarioBruto, horaExtra, valorExtra, valorFaixa1, valorFaixa2, valor_INSS, baseIRPF, IRPF, salarioLiquido, valorHoraExtra;

    do
    {
        printf("\n\n### PROGRAMA FOLHA DE PAGAMENTO ###\n\n");
        printf("Selecione a opção desejada.\n");
        printf("1 - Configurar dados da empresa.\n");
        printf("2 - Calcular salário mensal.\n");
        printf("3 - Sair.\n\n");
        printf("Sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 2 && (strlen(razaoSocial) == 0 || strlen(CNPJ) == 0 || strlen(endereco) == 0))
        {
            printf("Por favor, configure os dados da empresa antes de calcular o salário mensal.\n");
            continue;
        }

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
            do
            {
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
                    printf("Informe a sua data de nascimento:\n");
                    printf("Dia: ");
                    fgets(diaNasc, sizeof(diaNasc), stdin);
                    diaNasc[strcspn(diaNasc, "\n")] = '\0';
                    if (strlen(diaNasc) == 0)
                    {
                        printf("Não é permitido deixar opções em branco.\n");
                    }
                    if (strlen(diaNasc) != 2)
                    {
                        printf("O dia deve possuir 2 digitos.\n");
                    }

                } while (strlen(diaNasc) == 0 || strlen(diaNasc) != 2);

                do
                {
                    printf("Mês: ");
                    fgets(mesNasc, sizeof(mesNasc), stdin);
                    mesNasc[strcspn(mesNasc, "\n")] = '\0';
                    if (strlen(mesNasc) == 0)
                    {
                        printf("Não é permitido deixar opções em branco.\n");
                    }
                    if (strlen(mesNasc) != 2)
                    {
                        printf("O mês deve possuir 2 digitos.\n");
                    }

                } while (strlen(mesNasc) == 0 || strlen(mesNasc) != 2);

                do
                {
                    printf("Ano: ");
                    fgets(anoNasc, sizeof(anoNasc), stdin);
                    anoNasc[strcspn(anoNasc, "\n")] = '\0';
                    if (strlen(anoNasc) == 0)
                    {
                        printf("Não é permitido deixar opções em branco.\n");
                    }
                    if (strlen(anoNasc) != 4)
                    {
                        printf("O ano deve possuir 4 digitos.\n");
                    }

                } while (strlen(anoNasc) == 0 || strlen(anoNasc) != 4);

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
                horaExtra = 0;
                adicional = 0;
                valorHoraExtra = 0;
                valorExtra = 0;

                if (horaTrabalhada >= 221 && horaTrabalhada <= 240)
                {
                    horaExtra = horaTrabalhada - 220;
                    valorHoraExtra = horaExtra * 1.25;
                    adicional = 25;
                    valorExtra = valorHora + valorHoraExtra;
                }
                else if (horaTrabalhada >= 241)
                {
                    horaExtra = horaTrabalhada - 220;
                    valorHoraExtra = horaExtra * 1.5;
                    adicional = 50;
                    valorExtra = valorHora + valorHoraExtra;
                }

                salarioBruto = salarioBase + valorExtra;

                if (salarioBruto <= 1621)
                {
                    valor_INSS = salarioBruto * 0.075;
                }
                else if (salarioBruto <= 2902.84)
                {
                    valor_INSS = (1621 * 0.075) + ((salarioBruto - 1621) * 0.09);
                }
                else if (salarioBruto <= 4354.27)
                {
                    valor_INSS = (1621 * 0.075) + ((salarioBruto - 1621) * 0.09) + ((salarioBruto - 2902.84) * 0.12);
                }
                else if (salarioBruto <= 8475.55 || salarioBruto >= 8475.55)
                {
                    valor_INSS = (1621 * 0.075) + ((salarioBruto - 1621) * 0.09) + ((salarioBruto - 2902.84) * 0.12) + ((salarioBruto - 4354.27) * 0.14);
                }

                baseIRPF = salarioBruto - valor_INSS - (189.59 * dependentes);

                if (baseIRPF <= 2428.80)
                {
                    IRPF = 0;
                }
                else if (baseIRPF >= 2428.81 && baseIRPF <= 2826.65)
                {
                    IRPF = (baseIRPF * 0.075) - 182.16;
                }
                else if (baseIRPF >= 2826.66 && baseIRPF <= 3751.05)
                {
                    IRPF = (baseIRPF * 0.15) - 394.16;
                }
                else if (baseIRPF >= 3751.06 && baseIRPF <= 4664.68)
                {
                    IRPF = (baseIRPF * 0.225) - 675.49;
                }
                else if (baseIRPF >= 4664.68)
                {
                    IRPF = (baseIRPF * 0.275) - 908.73;
                }

                salarioLiquido = salarioBruto - valor_INSS - IRPF;

                printf("\n");
                printf("Segue abaixo seu contracheque do mês %s.\n", mesReferencia);
                printf("================================================================\n");
                printf("\t\t CONTRACHEQUE - %s/2026\t\t\n", mesReferencia);
                printf("================================================================\n");
                printf("EMPRESA: %s\t\t CNPJ: %s\n", razaoSocial, CNPJ);
                printf("ENDEREÇO: %s\n", endereco);
                printf("----------------------------------------------------------------\n");
                printf("FUNCIONÁRIO: %s\t\t DATA DE NASCIMENTO: %s/%s/%s\n", nome, diaNasc, mesNasc, anoNasc);
                printf("CARGO: %s\n", cargo);
                printf("----------------------------------------------------------------\n");
                printf("HORAS TRABALHADAS: %.2f\t\tVALOR DA HORA: R$ %.2f\n", horaTrabalhada, valorHora);
                printf("HORAS EXTRAS: %.2f\t\tADICIONAL APLICADO: %d%%\n", horaExtra, adicional);
                printf("----------------------------------------------------------------\n");
                printf("VENCIMENTOS\n");
                printf("----------------------------------------------------------------\n");
                printf("SALÁRIO BASE: R$ %.2f\t\tHORAS EXTRAS: R$ %.2f\n", salarioBase, valorHoraExtra);
                printf("----------------------------------------------------------------\n");
                printf("TOTAL VENCIMENTOS: R$ %.2f\n", salarioBruto);
                printf("----------------------------------------------------------------\n");
                printf("DESCONTOS\n");
                printf("----------------------------------------------------------------\n");
                printf("INSS: R$ %.2f\t\tIRPF: R$ %.2f\n", valor_INSS, IRPF);
                printf("----------------------------------------------------------------\n");
                printf("TOTAL DESCONTOS: R$ %.2f\t\tSALÁRIO LÍQUIDO: R$ %.2f\n", valor_INSS + IRPF, salarioLiquido);
                printf("================================================================\n");
                printf("Deseja calcular o salário de outro funcionário? (1 - Sim / 2 - Não): ");
                scanf("%d", &opcao);
            } while (opcao == 1);

        case 3:
            printf("Saindo do programa...\n");
            return 0;
            break;

        default:
            printf("Opção inválida. Por favor, selecione uma opção válida.\n");
            break;
        }

    } while (opcao != 3);
}
