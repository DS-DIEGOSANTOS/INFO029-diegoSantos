#include "../model/game.h"
#include "../model/menu.h"

void startGame(){
    int option;
    subscription();
    initialize();

    do{    
        printf("\nDeseja joga novamente Digite (0-sim  1-nao):");
        scanf("%d", &option);
        getchar();
        
        if(option <0 || option > 1){

            printf("\nopcao invalida!\n Digite qualquer tecla para continua...");
            getchar();
        }

    }while(option <0 || option > 1);

    switch (option){
        case 0:initialize(); break;
        
        case 1: startMenu();break;
    }

}
void initialize(){
    initializeBoard();
    system(CLEAR);
    logo();
    Board();
}
void subscription(){


    for(int i=0; i<2;i++){
        system(CLEAR);
        logo();
        printf("jogador %d digite seu nome: ", i+1);
        fgets(namePlayer[i],255,stdin);
        int ln = strlen(namePlayer[i])-1;
        if (namePlayer[i][ln] == '\n')
            namePlayer[i][ln] = '\0';

    }

}

void toStringBoard(){
    system(CLEAR);
    logo();

    printf("   1     2     3 \n");
    printf("A  %c  |  %c  |  %c\n",chessboard[0][0], chessboard[0][1] , chessboard[0][2]);
    printf("B  %c  |  %c  |  %c\n",chessboard[1][0], chessboard[1][1] , chessboard[1][2]);
    printf("C  %c  |  %c  |  %c\n",chessboard[2][0], chessboard[2][1] , chessboard[2][2]);
}

void Board(){
    
    int validation, validation2, winner = 0, tied = 0;

    while (!winner && !tied){
        for(int i = 0 ; i<2 && (!winner && !tied); i++){
       
            do{
                toStringBoard();

                printf("\nJogado: %s \ndigite sua coordenada: ", namePlayer[i]); 
                fgets(coordinate,3,stdin);
                int ln = strlen(coordinate)-1;
                if (coordinate[ln]== '\n')
                    coordinate[ln] = '\0';
                coordinate[0] = toupper(coordinate[0]);   
                getchar();
    
                validation = verificationBoard(i);

                if(!validation){
                    printf("\ncoordenada invalida!\n Digite qualquer tecla para continua...");
                    getchar();
                }
            }while(!validation);

            winner = isWinner(i);
            tied = istied();

            if(winner){
                toStringBoard();  
                printf("\nParabens jogador %s! voce venceu!\n", namePlayer[i]);
                printf("Digite qualquer tecla para continua...\n");
                getchar();
            }else if(tied){
                toStringBoard();  
                printf("\nFim de Jogo! empate\n");
                printf("Digite qualquer tecla para continua...\n");
                getchar();
            }

        }
       
    }
    
}

