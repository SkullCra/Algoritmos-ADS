#include <stdio.h>
#include <string.h>

// Função do menu: apenas imprime as opções e retorna a letra escolhida
char exibir_menu()
{
    char opcao;
    printf("\n--- CAIXA NUBANK ---\n");
    printf("Escolha uma opção:\n");
    printf("(a) Consultar saldo\n");
    printf("(b) Saque\n");
    printf("(c) Deposito\n");
    printf("(d) Sair\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &opcao);
    return opcao;
}

// Função de consulta: não altera o saldo, então retorna vazio (void)
void consultar_saldo(float saldo)
{
    printf("\n Seu saldo atual é de: R$ %.2f.\n", saldo);
}

float realizar_deposito(float saldo)
{
    float valor;
    printf("\nDigite o valor para depósito: R$ ");
    scanf("%f", &valor);

    if (valor > 0)
    {
        saldo = saldo + valor;
        printf("Depósito de R$ %.2f realizado com sucesso!\n", valor);
    }
    else
    {
        printf("Valor inválido para depósito!\n");
    }

    return saldo;
}

// Função de saque: recebe o saldo, subtrai se possível, e retorna o novo saldo
float realizar_saque(float saldo)
{
    int valor_saque, resto;
    int n200, n100, n50, n20, n10, n5 = 0, n2;

    printf("\nDigite o valor inteiro para saque: R$ ");
    scanf("%d", &valor_saque);

    // Validação 1: Valor negativo ou zero
    if (valor_saque <= 0)
    {
        printf(">>> Valor invalido para saque.\n");
        return saldo; // Retorna o saldo sem alterações
    }

    // Validação 2: Saldo insuficiente
    if (valor_saque > saldo)
    {
        printf(">>> Erro: Saldo insuficiente. Seu saldo e R$ %.2f\n", saldo);
        return saldo;
    }

    // --- LÓGICA DAS NOTAS ---
    resto = valor_saque;

    n200 = resto / 200;
    resto = resto % 200;

    n100 = resto / 100;
    resto = resto % 100;

    n50 = resto / 50;
    resto = resto % 50;

    n20 = resto / 20;
    resto = resto % 20;

    n10 = resto / 10;
    resto = resto % 10;

    // TRUQUE MATEMÁTICO PARA NOTAS DE 5 E 2:
    // Se usarmos notas de 5 para números pares (ex: 6), vai sobrar 1 real, que não tem nota.
    // Solução: Só usamos uma nota de 5 se o resto atual for ÍMPAR. Assim, o que sobrar vira par e resolvemos com notas de 2.
    if (resto % 2 != 0 && resto >= 5)
    {
        n5 = 1;
        resto = resto - 5;
    }

    n2 = resto / 2;
    resto = resto % 2;

    // Validação 3: Se sobrou algo (ex: tentou sacar R$ 1 ou R$ 3), o caixa não consegue entregar.
    if (resto != 0)
    {
        printf(">>> Erro: Nao e possivel entregar o valor com as notas disponiveis (menor nota e R$ 2).\n");
        return saldo; // Cancela o saque
    }

    // Se chegou até aqui, o saque é válido!
    // Atualizamos o saldo descontando o valor
    saldo = saldo - valor_saque;

    printf("\n>>> Saque de R$ %d realizado com sucesso!\n", valor_saque);
    printf("Cedulas entregues:\n");
    if (n200 > 0)
        printf("- %d nota(s) de R$ 200\n", n200);
    if (n100 > 0)
        printf("- %d nota(s) de R$ 100\n", n100);
    if (n50 > 0)
        printf("- %d nota(s) de R$ 50\n", n50);
    if (n20 > 0)
        printf("- %d nota(s) de R$ 20\n", n20);
    if (n10 > 0)
        printf("- %d nota(s) de R$ 10\n", n10);
    if (n5 > 0)
        printf("- %d nota(s) de R$ 5\n", n5);
    if (n2 > 0)
        printf("- %d nota(s) de R$ 2\n", n2);

    return saldo; // Devolve o saldo com o desconto feito
}

// --- FUNÇÃO PRINCIPAL ---
int main()
{
    float saldo = 0.0;
    char opcao_escolhida;

    do
    {
        opcao_escolhida = exibir_menu(); // Chama o menu e guarda a letra

        switch (opcao_escolhida)
        {
        case 'a':
            consultar_saldo(saldo);
            break;
        case 'b':
            // O saldo antigo recebe o valor retornado pela função de saque
            saldo = realizar_saque(saldo);
            break;
        case 'c':
            // O saldo antigo recebe o valor retornado pela função de depósito
            saldo = realizar_deposito(saldo);
            break;
        case 'd':
            printf("\n>>> Encerrando o sistema. Obrigado!\n");
            break;
        default:
            printf("\n>>> Opcao invalida! Tente novamente.\n");
        }

    } while (opcao_escolhida != 'd'); // O laço só quebra se o usuário digitar 'd'

    return 0;
}
