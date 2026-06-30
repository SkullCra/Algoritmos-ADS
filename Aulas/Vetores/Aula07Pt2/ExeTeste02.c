#include <stdio.h>
#include <string.h>
#include <math.h>

//Função que serve para limpar o buffer, essencial.
void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
int main () {
    char nome[30], matricula[7], curso[20];
    int tamanho;

    puts("### Leitura de Strings ###");
    
    //puts é um printf que não permite alteração
    //ele não precisa do \n no final, já pula linha automaticamente
    puts("Digite seu nome completo:");
    //Fgets deve ser usado ao invés do scanf
    //matriz, tamanho(matriz), stdin
    fgets (nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] ='\0';
    //aqui ele busca o \n na string e substitui por \0 que é nulo
    
    puts("Digite sua matrícula:");
    fgets (matricula, sizeof(matricula), stdin);
    limparBuffer();
    
    puts("Digite seu curso:");
    fgets (curso, sizeof(curso), stdin);

    tamanho = strlen(nome);

    printf ("O nome digitado é %s.\n", nome);
    printf ("O nome digitado possui %d caracteres.\n", tamanho);
    printf ("A metrícula informada é %s.\n", matricula);
    printf ("O curso informado é %s.\n", curso);

    return 0;
}