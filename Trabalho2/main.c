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
void menuDadosEstruturaAuxiliar(int ordenado);
void menuDadosDeTodasEstruturasAuxiliares(int ordenado);
void menuModificarTamanhoEstruturaAuxiliar();
void menuInformacaoDaEstrutura();
void menuVerificacao(int validacao);
void sair();

int main(){

    inicializar();
    menu();
    return 0;
}

void menu(){
    int op = 0,posicao = 0, tamanho = 0;

    do{
    printf("---------------------------\n");
    printf("        Trabalho 2         ");
    printf("\n---------------------------\n");

    printf("\n1 - Criar estrutura auxiliar");
    printf("\n2 - Inserir o valor na estrutura"); 
    printf("\n3 - Excluir numero final da estrutura");
    printf("\n4 - Excluir numero especifico da estrutura");
    printf("\n5 - Mostra dados da estrutura auxiliar");
    printf("\n6 - Mostra dados da estrutura auxiliar ordenado");
    printf("\n7 - Mostra todos os dados das estruturas auxiliares");
    printf("\n8 - Mostra todos os dados das estruturas auxliares ordenados");
    printf("\n9 - Mostra quantidade de tamanho e elementos");
    printf("\n10 - Modificar o tamanho da estrutura auxiliar");
    printf("\n11 - Sair");
    printf("\n\nescolha uma opcao:");
    scanf("%d",& op);
    getchar();

    if(op<1 || op>11){
        printf("opcao invalida \n\naperte qualquer tecla para continua...");
        getchar();
    }
    system(CLEAR);
    }while(op < 1 || op > 11);

    switch (op){
    case 1: menuCriarEstruturaAuxiliar(); break;
    case 2: menuInserirValorNaEstrutura(); break;
    case 3: menuExcluirNumeroDoFinaldaEstrutura(); break;
    case 4: menuExcluirNumeroEspecificoDeEstrutura();break;
    case 5: menuDadosEstruturaAuxiliar(0);break;
    case 6: menuDadosEstruturaAuxiliar(1);break;
    case 7: menuDadosDeTodasEstruturasAuxiliares(0);break;
    case 8: menuDadosDeTodasEstruturasAuxiliares(1);break;
    case 9: menuInformacaoDaEstrutura();break;
    case 10: menuModificarTamanhoEstruturaAuxiliar();break;
    case 11: sair(); break;
    }
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

    if(validacao == SUCESSO)
    printf("Estrutura auxiliar criada com sucesso!!\n\naperte qualquer tecla para continua...");
    else
    menuVerificacao(validacao);


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
        printf("Numero inserido com sucesso!!\n\naperte qualquer tecla para continua...");
    }else if(validacao == SEM_ESTRUTURA_AUXILIAR){
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

            if(validacao == SUCESSO){
                printf("Estrutura auxiliar criada com sucesso!!\n\naperte qualquer tecla para continua...");
                getchar();
                validacao = inserirNumeroEmEstrutura(posicao, valor);
              
            if(validacao == SUCESSO){
                printf("Numero inserido com sucesso!!\n\naperte qualquer tecla para continua...");
            }else{
                menuVerificacao(validacao);
            }
              
            }else{
                menuVerificacao(validacao);
            }
          
        }else{
            printf("voce sera encaminhado para o menu principal!\n\naperte qualquer tecla para continua...");
        }
    }else{
        menuVerificacao(validacao);
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

    validacao = excluirNumeroDoFinaldaEstrutura(posicao);

    if(validacao == SUCESSO)
    printf("Numero excluido com sucesso\n\naperte qualquer tecla para continua...");
    else
    menuVerificacao(validacao);


    getchar();
    system(CLEAR);
    menu();
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
    
    if(validacao == SUCESSO)
    printf("Numero excluido com sucesso\n\naperte qualquer tecla para continua...");
    else
    menuVerificacao(validacao);

    getchar();
    system(CLEAR);
    menu();
}

void menuDadosEstruturaAuxiliar(int ordenado){
    int posicao, tamanho = 0, validacao = 0;
    
    printf("Digite uma posicao:");
    scanf("%d", & posicao);
    getchar();

    tamanho = getQuantidadeElementosEstruturaAuxiliar(posicao);
    
    if(tamanho<0){
        menuVerificacao(tamanho);
    }else{

        int vetor[tamanho];

        if(ordenado) validacao = getDadosOrdenadosEstruturaAuxiliar(posicao,vetor);
        else validacao = getDadosEstruturaAuxiliar(posicao,vetor);

        if(validacao == SUCESSO){
            printf("---------------------------\n");
            printf("     DADOS DA POSICAO %d ", posicao);
            printf("\n---------------------------\n");
           
            for(int i = 0; i<tamanho;i++){
                printf("%d ",vetor[i]);
            }

            printf("\n\naperte qualquer tecla para continua...");
        }else{
            menuVerificacao(validacao);
        }
    }
    
    getchar();
    system(CLEAR);
    menu();
}

void menuDadosDeTodasEstruturasAuxiliares(int ordenado){
    
    int tamanho = 0, aux = 0, validacao;

    for(int i = 0 ; i< TAM; i++){
        aux =  getQuantidadeElementosEstruturaAuxiliar(i);
        if(aux>0){
            tamanho += aux;
        }
    }

    if(tamanho<=0){
        validacao = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        menuVerificacao(validacao);
    }else{

        int vetor[tamanho];

        if(ordenado) validacao = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetor);
        else validacao = getDadosDeTodasEstruturasAuxiliares(vetor);

        if(validacao == SUCESSO){
            printf("---------------------------\n");
            printf(" DADOS DE TODAS AS ESTRUTURAS" );
            printf("\n---------------------------\n");

            for(int i = 0; i<tamanho;i++){
                printf("%d ",vetor[i]);
            }

            printf("\n\naperte qualquer tecla para continua...");
        }else{
            menuVerificacao(validacao);
        }
    }

    getchar();
    system(CLEAR);
    menu();
}

void menuModificarTamanhoEstruturaAuxiliar(){
    int posicao, tamanho, validacao;

    printf("Digite uma posicao:");
    scanf("%d", & posicao);
    getchar();

    printf("Digite um tamanho:");
    scanf("%d", & tamanho);
    getchar();

    validacao = modificarTamanhoEstruturaAuxiliar(posicao, tamanho);

    if(validacao == SUCESSO)
    printf("Estrutura auxiliar atualizada com sucesso!!\n\naperte qualquer tecla para continua...");
    else
    menuVerificacao(validacao);


    getchar();
    system(CLEAR);
    menu();
}

void menuInformacaoDaEstrutura(){
    int Tamanho =0, Quantidade = 0, posicao;
    printf("Digite uma posicao:");
    scanf("%d", & posicao);
    getchar();

    Tamanho = getTamanhoDaEstruturaAuxilia(posicao-1);
    Quantidade = getQuantidadeElementosEstruturaAuxiliar(posicao);

    if(Quantidade >= 0 && Tamanho >= 0){
        printf("Tamanho da estrutura: %d\n", Tamanho);
        printf("Quantidade de elementos: %d\n",Quantidade);
        printf("\n\naperte qualquer tecla para continua...");
    }else{
        menuVerificacao(Quantidade);
    }

    getchar();
    system(CLEAR);
    menu();

}

void menuVerificacao(int validacao){
  
  if(validacao == JA_TEM_ESTRUTURA_AUXILIAR){
      printf("ja existi estrutura Auxiliar!!\n\naperte qualquer tecla para continua...");
  }else if(validacao ==POSICAO_INVALIDA){
      printf("posicao invalida!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == SEM_ESPACO_DE_MEMORIA){
      printf("Sem espaço de menoria!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == TAMANHO_INVALIDO){
      printf("Tamanho invalido!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == SEM_ESPACO){
      printf("sem espaco!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS){
      printf("Todas as estruturas auxiliares estao vazias!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == NOVO_TAMANHO_INVALIDO){
      printf("Novo tamanho invalido!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == NUMERO_INEXISTENTE){
      printf("Numero Inexistente!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == SEM_ESTRUTURA_AUXILIAR){
      printf("Sem estrutura auxiliar!!\n\naperte qualquer tecla para continua...");
  }
  
}

void sair(){
    finalizar();

    printf("-----------------------\n");
    printf("    FIM DO PROGRAMA    \n");
    printf("-----------------------\n");
}
