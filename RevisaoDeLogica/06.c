#include <stdio.h>
#include<stdlib.h>

int main(){
    int idade;

    while (idade>=0){
        printf("digite sua idade: ");
        scanf("%d", & idade);

        if(idade<0){
            return 0;
        }if(idade>=18){
            printf("e maior de idade");
        }else{
            printf("nao e maior de idade");
        }
    }

}