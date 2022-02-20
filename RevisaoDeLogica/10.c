#include <stdio.h>
#include <stdlib.h>

struct pessoa{
    char nome[30];
    char sexo[20];
    int idade;
    int cpf;
};


int main(){

    struct pessoa pessoa[5];

    for(int i = 0; i < 5 ;i++ ){
        printf("cadastro %d \n", i+1);

        printf("digite seu nome:");
        scanf("%s", & pessoa[i].nome);
        
        printf("digite seu sexo:");
        scanf("%s", & pessoa[i].sexo);

        printf("digite sua idade:");
        scanf("%d",& pessoa[i].idade);

        printf("digite seu cpf:");
        scanf("%d",& pessoa[i].cpf);

    }

    for(int i = 0; i <5 ; i++){
 
        printf("cadastro %d \n", i+1);   
        printf("nome: %s\n", pessoa[i].nome);
        printf("sexo: %s\n", pessoa[i].sexo);
        printf("idade: %d\n", pessoa[i].idade);
        printf("CPF: %d\n", pessoa[i].cpf);
        printf("----------------------------------\n");

    }

}