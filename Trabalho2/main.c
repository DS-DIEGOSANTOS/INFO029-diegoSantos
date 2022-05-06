#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
    #include <unistd.h>
#endif

void menu();
void MenuCriarEstruturaAuxiliar();

int main(){
    inicializar();
    menu();
    finalizar();
}

void menu(){
    int op;

    do{
        printf("---------------------------\n");
        printf("        Trabalho 2         ");
        printf("\n---------------------------\n");

        printf("1 - Criar estrutura auxiliar");
        printf("escolha uma opcao:");
        scanf("%d",& op);
        getchar();

        system(CLEAR);
    }while(op<0 || op>1);
}

void MenuCriarEstruturaAuxiliar(){
    int posicao, tamanho, validacao;

    printf("Digite uma posicao:");
    scanf("%d", & posicao);
    getchar();

    printf("Digite um tamanho");
    scanf("%d", & tamanho);
    getchar();

    validacao = criarEstruturaAuxiliar(posicao, tamanho);

    if(validacao == JA_TEM_ESTRUTURA_AUXILIAR){
        printf("ja existi estrutura Auxiliar!\n\naperte qualquer tecla para continua...");
    }else if(validacao ==POSICAO_INVALIDA){
        printf("posicao invalida!\n\naperte qualquer tecla para continua...");
    }else if(validacao == SEM_ESPACO_DE_MEMORIA){
        printf("Sem espaço de menoria\n\naperte qualquer tecla para continua...");
    }else if(validacao == TAMANHO_INVALIDO){
        printf("Tamanho invalido\n\naperte qualquer tecla para continua...");
    }else{
        printf("Estrutura auxiliar criada como sucesso!!\n\naperte qualquer tecla para continua...");
    }

    getchar();
    menu();
}