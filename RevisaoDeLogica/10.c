#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct pessoa{
    char nome[31];
    char sexo;
    int idade;
    char cpf[16];
} Pessoa;


int main(){

    Pessoa pessoa[TAM];

    for(int i = 0; i < TAM ;i++ ){
        printf("cadastro %d \n", i+1);

        printf("digite seu nome:");
        fgets(pessoa[i].nome,31,stdin);

        size_t ln = strlen(pessoa[i].nome) - 1;
        if (pessoa[i].nome[ln] == '\n')
            pessoa[i].nome[ln] = '\0';    

        printf("digite seu sexo:");
        scanf("%c",& pessoa[i].sexo);

        printf("digite sua idade:");
        scanf("%d",& pessoa[i].idade);

        getchar();

        printf("digite seu cpf:");
        fgets(pessoa[i].cpf,15,stdin);
        ln = strlen(pessoa[i].nome) - 1;
        if (pessoa[i].cpf[ln] == '\n')
            pessoa[i].cpf[ln] = '\0'; 

    }

    for(int i = 0; i <5 ; i++){
 
        printf("cadastro %d \n", i+1);   
        printf("nome: %s\n", pessoa[i].nome);
        printf("sexo: %c\n", pessoa[i].sexo);
        printf("idade: %d\n", pessoa[i].idade);
        printf("CPF: %s\n", pessoa[i].cpf);
        printf("----------------------------------\n");

    }

}