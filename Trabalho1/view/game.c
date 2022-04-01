#include "../model/game.h"

char **subscription(){
    int ln;

    char** jogador= (char**) calloc (quantidadeDeJogadores, sizeof (char*));
    for(int i = 0; i < quantidadeDeJogadores ; i++ ){
        jogador[i] = (char*) calloc (MAX_NAME_LEN, sizeof (char));
    }
    
    

    for(int i = 0; i < quantidadeDeJogadores ; i++){
        system(CLEAR);
        printf("\n----------------------------------------------------\n");
        printf("                   Cadastro Jogador %d                             ", i+1);
        printf("\n-----------------------------------------------------\n\n\n");  
        
        printf("Nome: ");
        fgets(jogador[i],MAX_NAME_LEN,stdin);
        ln = strlen(jogador[i]) - 1;
        if (jogador[i][ln] == '\n')
            jogador[i][ln] = '\0';
  
    }

    return jogador;

}