#include <stdio.h>
#include <stdlib.h>
#define TAM 4

typedef struct valor{
    float numero;
}Valor;

Valor * lernumero();

int main(){

    Valor * valor = lernumero();

    for (int i = 0; i < TAM; i++){
       printf("posicao %d resultado %.1f\n", i+1 , valor[i].numero);
    }
    
    return 0;
}

Valor * lernumero(){

    Valor* numero= (Valor*) calloc (TAM, sizeof (Valor));

    for(int i = 0; i <TAM ; i++){
        printf("Digite o numero %d : ",i+1);
        scanf("%f", & numero[i].numero);
    }

    return numero;
}