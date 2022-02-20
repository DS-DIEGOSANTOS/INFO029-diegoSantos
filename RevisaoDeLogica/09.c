#include <stdio.h>
#include<stdlib.h>
#define qtdnumero 10

int main(){
    int numero[qtdnumero];
    int soma=0, cont = 1 , aux = 0;

    for(int i= 0;i<qtdnumero;i++){
        printf("Digite o numero %d:",i+1);
        scanf("%d",& numero[i]);  
    }

    for(int i= 0;i<qtdnumero;i++){
        while (cont<=qtdnumero){
            if(numero[i]%cont ==0){
                aux++;
            }
            cont++;
        }

        if(aux == 2){
            printf("numero primo : %d\n", numero[i]);
            soma+=numero[i];
        }

        aux = 0;
        cont = 1;       
    }

    printf("soma: %d", soma);

    return 0;
}