#include <stdio.h>
#include<stdlib.h>

int main(){
    int numero;
    int aux=0, cont =1;
 
    printf("digite um numero: ");
    scanf("%d", & numero);

    while (cont<=numero){
        if(numero%cont ==0){
            aux++;
        }
        cont++;
    }

    if(aux == 2){
        printf("ele e primo");
    }else{
        printf("nao e primo");
    }

    return 0;
}