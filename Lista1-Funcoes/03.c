#include <stdio.h>
#include <stdlib.h>

int fatorial(int valor);

int main(){
    int valor, resultado;

    printf("Digite um valor: ");
    scanf("%d", & valor);

    resultado = fatorial(valor);

    if(!resultado){
        printf("nao existe fatorial do numero %d", valor);
    }else{
        printf("fatorial de %d e %d ", valor, resultado);
    }

    return 0 ;
}

int fatorial(int valor){

    if(valor < 0){
        return 0;
    }else if(valor==0 || valor == 1){
        return 1;
    }else{
        return valor * fatorial(valor-1);
    }
}