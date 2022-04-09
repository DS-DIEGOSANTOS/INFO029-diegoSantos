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

        switch (option){
        case 0:initialize(); break;
        case 1: startMenu();break;
        }

    }while((option <0 || option > 1)|| (option==0) );

}

void subscription(){

    for(int i=0; i<2;i++){
        system(CLEAR);
        logo();
        printf("jogador %d digite seu nome: ", i+1);
        fgets(namePlayer[i],MAX_LEN_NAME,stdin);
        int ln = strlen(namePlayer[i])-1;
        if (namePlayer[i][ln] == '\n')
            namePlayer[i][ln] = '\0';
    }
}

void initialize(){
    initializeBoard();
    system(CLEAR);
    logo();
    coordinateShip();
    Board();
}

void toStringBoard(int playerBoard){
    system(CLEAR);
    char navalBattleBoard = ' ';
    logo();

    printf("\t\t    Inimigo ");
    printf("\t\t\t\t\t\t\t Meu Tabuleiro\n");

    if(playerBoard == 0){

        for(int i = 0, c = 65; i < MAX_DIMENSIONS ; i++,c++){
      
        if( i == 0){
            for(int l = 0; l< MAX_DIMENSIONS ; l++){
                printf("    %d", l+1);
            }
            printf("\t\t");
        }

        if( i == 0){
            for(int l = 0; l< MAX_DIMENSIONS ; l++){
                printf("    %d", l+1);
            }
            printf("\n");
        }

        printf("%c",c);
        for(int j = 0 ;j<MAX_DIMENSIONS; j++ ){
            if(navalBattleBoardPlayer2[i][j] == 'N'){
                printf("  {%c}", navalBattleBoard);
            }else{
                printf("  {%c}", navalBattleBoardPlayer2[i][j] );
            }
            
        }
        printf("\t\t");

        printf("%c",c);
        for(int j = 0 ;j<MAX_DIMENSIONS; j++ ){
            printf("  {%c}", navalBattleBoardPlayer1[i][j] );
        }
        printf("\n");
        }

    }else{
        
        for(int i = 0, c = 65; i < MAX_DIMENSIONS ; i++,c++){
      
        if( i == 0){
            for(int l = 0; l< MAX_DIMENSIONS ; l++){
                printf("    %d", l+1);
            }
            printf("\t\t");
        }

        if( i == 0){
            for(int l = 0; l< MAX_DIMENSIONS ; l++){
                printf("    %d", l+1);
            }
            printf("\n");
        }

        printf("%c",c);
        for(int j = 0 ;j<MAX_DIMENSIONS; j++ ){
            if(navalBattleBoardPlayer1[i][j] == 'N'){
                printf("  {%c}", navalBattleBoard );
            }else{
                printf("  {%c}", navalBattleBoardPlayer1[i][j] );
            }    
            
        }
        printf("\t\t");

        printf("%c",c);
        for(int j = 0 ;j<MAX_DIMENSIONS; j++ ){
            printf("  {%c}", navalBattleBoardPlayer2[i][j] );
        }
        printf("\n");
        }
    }
    
}

void toStringBoardPlayer(int playerBoard){
    system(CLEAR);
    logo();

    if(!playerBoard ){

        for(int i = 0, c = 65; i < MAX_DIMENSIONS ; i++,c++){
      
            if( i == 0){
                for(int l = 0; l< MAX_DIMENSIONS ; l++){
                    printf("    %d", l+1);
                }
                printf("\n");
            }

            printf("%c",c);
            for(int j = 0 ;j<MAX_DIMENSIONS; j++ ){
                printf("  {%c}", navalBattleBoardPlayer1[i][j] );
            }
            printf("\n");
        }

    }else{
        for(int i = 0, c = 65; i < MAX_DIMENSIONS ; i++,c++){
      
        if( i == 0){
            for(int l = 0; l< MAX_DIMENSIONS ; l++){
                printf("    %d", l+1);
            }
            printf("\n");
        }

        printf("%c",c);
        for(int j = 0 ;j<MAX_DIMENSIONS; j++ ){
            printf("  {%c}", navalBattleBoardPlayer2[i][j] );
        }
        printf("\n");
        }
    }
}

void coordinateShip(){

    playerCoordinate Player;
    int ln,validationDirection, validation,adds;
    char coordinatePlayer[MAX_COORDINATE];
    
    for(int i = 0 ; i<MAX_PLAYER ; i++ ){

        do{
            do{
                toStringBoardPlayer(i);
                printf("Jogador %s\n",namePlayer[i]);
                printf("Digite sua coordenada para o navio de 4 posicoes:");
                fgets(coordinatePlayer,MAX_COORDINATE,stdin);
                ln = strlen(coordinatePlayer)-1;
                if (coordinatePlayer[ln]== '\n')
                    coordinatePlayer[ln] = '\0'; 
                Player = verificationBoard(i, coordinatePlayer);

                if(!Player.Validation){
                    printf("coordenada invalida!!");
                    printf("\n Digite qualquer tecla para continua");
                    getchar();
                }

            }while(!Player.Validation);

            do{
                printf("1-Norte\n2-Leste\n3-Sul\n4-Oeste\nescolha uma Direcao:");
                scanf("%d", & validationDirection);
                getchar();

                if(validationDirection<1 || validationDirection>4){
                    printf("Direcao invalida!!");
                    printf("\n Digite qualquer tecla para continua");
                    getchar();
                }else{
                    Player.Direction = validationDirection;
                }
            }while(validationDirection<1 || validationDirection>4);

            validation = validationFillInBoard(Player,4, i);

            if(!validation){
                printf("Nao e possivel coloca o Navio!!");
                printf("\n Digite qualquer tecla para continua");
                getchar();
            }

        }while(!validation);

        do{
            do{
                toStringBoardPlayer(i);
                printf("Jogador %s\n",namePlayer[i]);
                printf("Digite sua coordenada para o navio de 3 posicoes:");
                fgets(coordinatePlayer,MAX_COORDINATE,stdin);
                ln = strlen(coordinatePlayer)-1;
                if (coordinatePlayer[ln]== '\n')
                    coordinatePlayer[ln] = '\0'; 
                Player = verificationBoard(i, coordinatePlayer);

                if(!Player.Validation){
                    printf("coordenada invalida!!");
                    printf("\n Digite qualquer tecla para continua");
                    getchar();
                }

            }while(!Player.Validation);

            do{
                printf("1-Norte\n2-Leste\n3-Sul\n4-Oeste\nescolha uma Direcao:");
                scanf("%d", & validationDirection);
                getchar();

                if(validationDirection<1 || validationDirection>4){
                    printf("Direcao invalida!!");
                    printf("\n Digite qualquer tecla para continua");
                    getchar();
                }else{
                    Player.Direction = validationDirection;
                }
            }while(validationDirection<1 || validationDirection>4);

            validation = validationFillInBoard(Player,3, i);

            if(!validation){
                printf("Nao e possivel coloca o Navio!!");
                printf("\n Digite qualquer tecla para continua");
                getchar();
            }

        }while(!validation);

        for(int j = 0 ; j < 3 ; j++){

            do{
                do{
                    toStringBoardPlayer(i);
                    printf("Jogador %s\n",namePlayer[i]);
                    printf("Digite sua coordenada para o navio de 1 posicoes:");
                    fgets(coordinatePlayer,MAX_COORDINATE,stdin);
                    ln = strlen(coordinatePlayer)-1;
                    if (coordinatePlayer[ln]== '\n')
                        coordinatePlayer[ln] = '\0'; 
                    Player = verificationBoard(i, coordinatePlayer);

                    if(!Player.Validation){
                        printf("coordenada invalida!!");
                        printf("\n Digite qualquer tecla para continua");
                        getchar();
                    }else{
                        Player.Direction = 1;
                    }

                }while(!Player.Validation);

                validation = validationFillInBoard(Player,1, i);

                if(!validation){
                    printf("Nao e possivel coloca o Navio!!");
                    printf("\n Digite qualquer tecla para continua");
                    getchar();
                }

            }while(!validation);
        }

        do{
            toStringBoardPlayer(i);
            printf("Deseja acrecenta mais navio\n0 - Nao \n1 - Sim\nDigite sua opcao:");
            scanf("%d", & adds);
            getchar();

            if(adds<0 || adds>1){
                printf("Nao e possivel coloca o Navio!!");
                printf("\n Digite qualquer tecla para continua");
                getchar();
            }else if(adds == 1){
                adds++;
                do{
                    do{
                        toStringBoardPlayer(i);
                        printf("Jogador %s\n",namePlayer[i]);
                        printf("Digite sua coordenada para o navio de 2 posicoes:");
                        fgets(coordinatePlayer,MAX_COORDINATE,stdin);
                        ln = strlen(coordinatePlayer)-1;
                        if (coordinatePlayer[ln]== '\n')
                            coordinatePlayer[ln] = '\0'; 
                        Player = verificationBoard(i, coordinatePlayer);

                        if(!Player.Validation){
                            printf("coordenada invalida!!");
                            printf("\n Digite qualquer tecla para continua");
                            getchar();
                        }

                    }while(!Player.Validation);

                    do{
                        printf("1-Norte\n2-Leste\n3-Sul\n4-Oeste\nescolha uma Direcao:");
                        scanf("%d", & validationDirection);
                        getchar();

                        if(validationDirection<1 || validationDirection>4){
                            printf("Direcao invalida!!");
                            printf("\n Digite qualquer tecla para continua");
                            getchar();
                        }else{
                            Player.Direction = validationDirection;
                        }
                    }while(validationDirection<1 || validationDirection>4);

                    validation = validationFillInBoard(Player,2, i);

                    if(!validation){
                        printf("Nao e possivel coloca o Navio!!");
                        printf("\n Digite qualquer tecla para continua");
                        getchar();
                    }

                }while(!validation);

            }

        }while(adds<0 || adds>1);
          
    }
}

void Board(){

    int winner = 0,ln, validation;
    char coordinatePlayer[MAX_COORDINATE];

    while(!winner){

        for(int i = 0; i<2 && !winner;i++){
            
            do{
                toStringBoard(i);
                printf("Jogador %s\n",namePlayer[i]);
                printf("Digite uma coordenada para atacar:");
                fgets(coordinatePlayer,MAX_COORDINATE,stdin);
                ln = strlen(coordinatePlayer)-1;
                if (coordinatePlayer[ln]== '\n')
                    coordinatePlayer[ln] = '\0'; 
                validation = attackValidation(i, coordinatePlayer);

                if(!validation){
                    printf("ataque invalida!!");
                    printf("\n Digite qualquer tecla para continua");
                    getchar();
                }

            }while(!validation);

            winner = isWinner(i);

            if(winner){
                toStringBoard(i);
                printf("\nParabens jogador %s! voce venceu!\n", namePlayer[i]);
                printf("Digite qualquer tecla para continua...\n");
                getchar();
            }
        }
    }

}
