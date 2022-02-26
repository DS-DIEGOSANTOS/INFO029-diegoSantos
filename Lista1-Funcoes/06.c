#include <stdio.h>
#include <stdlib.h>
#define TAM 3

char * lerLetras();

int main(){
    
    char * letras = lerLetras();

    for (int i = 0; i < TAM; i++){
       printf("posicao %d resultado %c\n", i+1 , letras[i]);
    }
    
    return 0;
}

char * lerLetras(){

    char* letras= (char*) calloc (TAM, sizeof (char));

    for(int i = 0; i <TAM ; i++){
        printf("Digite a letra %d : ",i+1);
        scanf("%c", & letras[i]);
        getchar();
    }

    return letras;
}

