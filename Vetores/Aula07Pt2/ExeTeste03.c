#include <stdio.h>
#include <string.h>

int main () {
    char string[10];
    int tamanho;

    printf ("Digite uma palavra: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    printf ("A palavra digitada foi: %s.\n", string);
    printf ("A palavra digitada inversa é: ");
    for (int i = strlen(string); i>=0; i--){
        printf ("%c", string[i]);
    }
}