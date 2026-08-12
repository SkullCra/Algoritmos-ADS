#include <stdio.h>
#include <string.h>

void limpaBuffer () {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main()
{
    char caracter, string[31];

    printf("### VERIFICADOR DE CARACTER EM STRING ###\n\n");
    printf("Digite um caractere de \"A\" a \"Z\": ");
    scanf(" %c", &caracter);
    limpaBuffer();

    printf("Agora informe a palavra: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    
    if (strchr(string, caracter) != '\0')
    {
        printf("SIM!\n");
    }
    else
    {
        printf("NÃO!\n");
    }
    return 0;
}