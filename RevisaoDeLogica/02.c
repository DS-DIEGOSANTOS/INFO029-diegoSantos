#include <stdio.h>
#include<stdlib.h>
#define qtdIdade 2

int main(){
    int idade[qtdIdade];
    int soma=0;

    for(int i= 0;i<qtdIdade;i++){
        printf("Digite a idade %d:",i+1);
        scanf("%d",& idade[i]);
        soma+= idade[i];
    }

    printf("soma: %d", soma);

    return 0;
}