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
void menuCriarEstruturaAuxiliar();
void menuInserirValorNaEstrutura();
void menuExcluirNumeroDoFinaldaEstrutura();
void menuExcluirNumeroEspecificoDeEstrutura();
void menuDadosEstruturaAuxiliar();


int main(){
    inicializar();
    menu();
    finalizar();
}

void menu(){
    int op,posicao, tamanho;

    do{
        printf("---------------------------\n");
        printf("        Trabalho 2         ");
        printf("\n---------------------------\n");

        printf("\n1 - Criar estrutura auxiliar");
        printf("\n2 - Inserir o valor na estrutura"); 
        printf("\n3 - Excluir numero final da estrutura");
        printf("\n4 - Excluir numero especifico da estrutura");
        printf("\n5 - mostra dados da estrutura auxiliar");
        printf("\nescolha uma opcao:");
        scanf("%d",& op);
        getchar();

        system(CLEAR);
    }while(op<1 || op>2);
}

void menuCriarEstruturaAuxiliar(){
    int posicao, tamanho, validacao;

    printf("Digite uma posicao:");
    scanf("%d", & posicao);
    getchar();

    printf("Digite um tamanho:");
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
    system(CLEAR);
    menu();
}

void menuInserirValorNaEstrutura(){

    int posicao, valor, validacao,op, tamanho;

    printf("Digite uma posicao:");
    scanf("%d", & posicao);
    getchar();

    printf("Digite um valor:");
    scanf("%d", & valor);
    getchar();

    validacao = inserirNumeroEmEstrutura(posicao, valor);

    if(validacao == SUCESSO){
        printf("Numero inserido criada como sucesso!!\n\naperte qualquer tecla para continua...");
    }else if(validacao == SEM_ESPACO){
        printf("sem espaco!!\n\naperte qualquer tecla para continua...");
    }else if(posicao == POSICAO_INVALIDA){
        printf("posicao invalida!\n\naperte qualquer tecla para continua...");
    }else{
        printf("Sem estrutura auxiliar!");

        do{
            system(CLEAR);
            printf("deseja criar um estrutura auxiliar\n1 - Sim\n2 - Nao\nEscolha uma opcao:");
            scanf("%d", & op);
        }while(op<1 || op>2);

        if(op == 1){

            printf("Digite um tamanho:");
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
          
        }else{
          printf("voce sera encaminhado para o menu principal!\n\naperte qualquer tecla para continua...");
        }
    }

    getchar();
    system(CLEAR);
    menu();

}

void menuExcluirNumeroDoFinaldaEstrutura(){
 
  int posicao,validacao;
  
  printf("Digite uma posicao:");
  scanf("%d", & posicao);
  getchar();

  validao = excluirNumeroDoFinaldaEstrutura(posicao);

}

void menuExcluirNumeroEspecificoDeEstrutura(){
    int posicao, valor, validacao;

    printf("Digite uma posicao:");
    scanf("%d", & posicao);
    getchar();

    printf("Digite um valor:");
    scanf("%d", & valor);
    getchar();

    validacao = excluirNumeroEspecificoDeEstrutura(posicao,valor);

}

void menuDadosEstruturaAuxiliar(){
  int posicao, tamanho;
  
  printf("Digite uma posicao:");
  scanf("%d", & posicao);
  getchar();
  
  tamanho = getQuantidadeElementosEstruturaAuxiliar(posicao);

  int vetor[tamanho];
}