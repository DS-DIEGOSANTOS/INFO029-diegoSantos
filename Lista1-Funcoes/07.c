#include <stdio.h>
#include <stdlib.h>
#define TAM 3
#define CARACTERES 60

char ** lerLetras();

int main(){

    char **palavras = lerLetras();

    for (int i = 0; i < TAM; i++){
       printf("posicao %d resultado %s\n", i+1 , palavras[i]);
    }
    
    return 0;
}

char ** lerLetras(){

    char** palavras= (char**) calloc (TAM, sizeof (char*));
    for(int i = 0; i < TAM ; i++ ){
        palavras[i] = (char*) calloc (CARACTERES, sizeof (char));
    }

    for(int i = 0;  i <TAM ; i++){

        printf("Digite a palavra %d:",i+1);

        fgets(palavras[i],CARACTERES,stdin);
        int ln = strlen(palavras[i]) - 1;
        if (palavras[i][ln] == '\n')
            palavras[i][ln] = '\0';
    }

    return palavras;
}