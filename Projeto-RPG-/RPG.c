#include <stdio.h>
#include <string.h>
#include <math.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main () {
    char nome_personagem[30];
    int historico[5][4];
    int monstros_derrotados = 0;

    printf ("\n**** BEM-VINDO A DUNGEONS & DRAGONS 0.5 ****\n");
    printf ("O que você deseja fazer?\n");
    int opcao;
    printf ("1 - Jogar o jogo.\n");
    printf ("2 - Saber mais.\n");
    printf ("0 - Sair.\n");
    printf ("Sua escolha: ");
    scanf ("%d", &opcao);
    limparBuffer();

    switch (opcao) {
        case 1:
        printf ("Informe o nome do seu personagem: ");
        fgets(nome_personagem, sizeof(nome_personagem), stdin);
        nome_personagem[strcspn(nome_personagem, "\n")] = '\0';
        int vida_atual = 20;
        int comida_atual = 10;
        int ouro_atual = 0;

        for (int d = 0; d < 5; d++) {
            for (int e = 0; e < 4; e++){
                historico[d][e] = 0;
            }
        }

        for (int d = 0; d < 5; d++) {
            printf ("==== DIA %d ====\n", d + 1);
            printf ("Vida: %d | Comida: %d | Ouro: %d\n", vida_atual, comida_atual, ouro_atual);
            printf ("O que você deseja fazer hoje?\n");
            printf ("1 - Explorar a masmorra (Risco de combate, chance de obter ouro.)\n");
            printf ("2 - Caçar comida na floresta (Recupera comida, sem ganhar ouro)\n");
            printf ("3 - Descansar no acampamento (Recupera vida, consome 1 de comida extra)\n");
            int opcao;
            scanf ("%d", &opcao);
            limparBuffer();

            switch (opcao) {
                case 1:
                printf ("Você está explorando a masmorra...\n");
                printf ("ESPERE! UM MONSTRO!\n");
                printf ("O que deseja fazer?\n");
                printf ("1 - Atacar o monstro.\n");
                printf ("2 - Fugir!\n");
                int escolha;
                printf ("Sua escolha (1 ou 2): ");
                scanf ("%d", &escolha);
                limparBuffer();

                if (escolha == 1) {

                    printf ("Você destrava uma batalha ferroz contra o monstro!\n");
                    printf ("Você conseguiu 5 de ouro!");
                }
                if (escolha == 2) {
                    printf ("Você tenta fugir...\n");
                    printf ("Mas o monstro consegue te atacar!\n");
                    printf ("Você perdeu 4 PV...\n");
                }
            }
        }

        case 2:
        printf ("Este jogo de RPG foi criado para treinar matrizes.\n");
        printf ("O criador deste jogo não possui nenhuma ligação com a Wizards of the Coast.\n");
        printf ("Criador: Wíllian Zanella \t Data: 06/2026\n");
    }
    
}
