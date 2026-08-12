#include <stdio.h>

int main() {
    float matriz[5][4];
    int i;
    float maiorNotaFinal = -1;
    float matriculaMaiorNota = 0;
    float somaNotasFinais = 0;

    for (i = 0; i < 5; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Digite o numero de matricula: ");
        scanf("%f", &matriz[i][0]);

        printf("Digite a media das provas: ");
        scanf("%f", &matriz[i][1]);

        printf("Digite a media dos trabalhos: ");
        scanf("%f", &matriz[i][2]);

        matriz[i][3] = (matriz[i][1] + matriz[i][2])/2;
        somaNotasFinais += matriz[i][3];

        if (matriz[i][3] > maiorNotaFinal) {
            maiorNotaFinal = matriz[i][3];
            matriculaMaiorNota = matriz[i][0];
        }
        printf("\n");
    }

    printf("Matricula do aluno com maior nota final: %.0f\n", matriculaMaiorNota);

    float mediaNotasFinais = somaNotasFinais / 5.0;
    printf("Media das notas finais: %.2f\n", mediaNotasFinais);

    return 0;
}
