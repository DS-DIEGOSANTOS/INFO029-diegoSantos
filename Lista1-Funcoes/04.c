#include <stdio.h>
#include <stdlib.h>
#define TAM 3

float * lernumero();

int main(){

    float * numero = lernumero();

    for (int i = 0; i < TAM; i++){
       printf("posicao %d resultado %.1f\n", i+1 , numero[i]);
    }
    
    return 0;
}

float * lernumero(){

    float* numero= (float*) calloc (TAM, sizeof (float));

    for(int i = 0; i <TAM ; i++){
        printf("Digite o numero %d : ",i+1);
        scanf("%f", & numero[i]);
    }

    return numero;
}