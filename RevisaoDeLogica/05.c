#include <stdio.h>
#include<stdlib.h>

int main(){
    int idade;
    printf("digite sua idade: ");
    scanf("%d", & idade);

    if(idade>=18){
        printf("e maior de idade");
    }else{
        printf("nao e maior de idade");
    }

    return 0;
}