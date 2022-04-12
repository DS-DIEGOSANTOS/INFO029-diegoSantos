#include "../model/game.h"

void initializeBoard(){

    for(int i = 0 ; i<MAX_DIMENSIONS;i++){
        for(int j = 0 ; j<MAX_DIMENSIONS;j++){
            navalBattleBoardPlayer1[i][j] = ' ';
        }
    }

    for(int i = 0 ; i<MAX_DIMENSIONS;i++){
        for(int j = 0 ; j<MAX_DIMENSIONS;j++){
            navalBattleBoardPlayer2[i][j] = ' ';
        }
    }
    
}

playerCoordinate verificationBoard(int gamester, char coordinate[]){

    playerCoordinate Player;
    int y = 0, x =0;
    coordinate[0] = toupper(coordinate[0]);

    if(isalpha(coordinate[0]) && coordinate[0] < MAX_DIMENSIONS + 65){
        y = coordinate[0] - 65;
    }else{
        Player.Validation = 0;
        return Player;
    }

    for(int i = 1 ; coordinate[i]!='\0'; i++){
        
        if(isdigit(coordinate[i])){
            if(i >1){
                x*= 10;
            }
            x+= (coordinate[i] - 48);
        }else{
            Player.Validation = 0;
            return Player;
        }
    }
    x--;

    if(x<0 || x>MAX_DIMENSIONS){
        Player.Validation = 0;
        return Player;;
    }else if(!isempty(y,x,gamester)){
        printf("c%d\n", x);
        Player.Validation = 0;
        return Player;
    }else{
        Player.x = x;
        Player.y = y;
        Player.Validation = 1;
        return Player;
    }
    

}

int isempty(int y, int x, int gamester){

    if(!gamester){
        if(navalBattleBoardPlayer1[y][x] == ' '){
            return 1;
        }else{
            return  0;
        }
    }else{
        if(navalBattleBoardPlayer2[y][x] == ' '){
            return 1;
        }else{
            return  0;
        }
    }
}

int validationFillInBoard(playerCoordinate Player,int posicao, int gamester){
    
    int validation = 1 , aux;
    posicao--;
    switch (Player.Direction){
    case 1:

        aux = Player.y- posicao;
        if(aux >= 0 ){
            for(int i = Player.y ; i >= Player.y- posicao && validation;i--){

                if(!isempty(i, Player.x, gamester)){
                    validation = 0;
                }
            }
        }else{
            return 0;
        }
   
        if(!validation){
            return 0;
        }else{
            for(int i = Player.y ; i >= Player.y- posicao && validation;i--){
                fillWithShip(i, Player.x, gamester);
            }
        }

        break;
    case 2:

        aux = Player.x + posicao;
        if(aux < MAX_DIMENSIONS ){
            for(int i = Player.x ; i <= Player.x + posicao && validation;i++){

                if(!isempty(Player.y, i, gamester)){
                    validation = 0;
                }
            }
        }else{
            return 0;
        }

        if(!validation){
            return 0;
        }else{
            for(int i = Player.x ; i <= Player.x + posicao && validation;i++){
                fillWithShip(Player.y, i, gamester);
            }
        }

        break;

    case 3:

        aux = Player.y + posicao;
        if(aux < MAX_DIMENSIONS ){
            for(int i = Player.y ; i <= Player.y + posicao && validation;i++){

                if(!isempty(i, Player.x, gamester)){
                    validation = 0;
                }
            }
        }else{
            return 0;
        }

        if(!validation){
            return 0;
        }else{
            for(int i = Player.y ; i <= Player.y + posicao && validation;i++){
                fillWithShip(i, Player.x, gamester);
            }
        }

        break;

    case 4:

       aux = Player.x- posicao;
        if(aux >= 0 ){
            for(int i = Player.x ; i >= Player.x- posicao && validation;i--){

                if(!isempty(Player.y, i, gamester)){
                    validation = 0;
                }
            }
        }else{
            return 0;
        }
   
        if(!validation){
            return 0;
        }else{
            for(int i = Player.x ; i >= Player.x- posicao && validation;i--){
                fillWithShip(Player.y, i, gamester);
            }
        }

        break;
   
    }

    return 1;
}

void fillWithShip(int y , int x , int gamester){
    
    if(!gamester){
        navalBattleBoardPlayer1[y][x] = 'N';
    }else{
        navalBattleBoardPlayer2[y][x] = 'N';
    } 
}

int isWinner(int gamester){

    int validation = 1;

    if(!gamester){
        
        for(int i = 0 ; i<MAX_DIMENSIONS && validation;i++){
            for(int j = 0 ; j<MAX_DIMENSIONS && validation;j++){
               
                if(navalBattleBoardPlayer2[i][j] == 'N'){
                    validation = 0;
                }
                
            }
        }

    }else{
        for(int i = 0 ; i<MAX_DIMENSIONS && validation;i++){
            for(int j = 0 ; j<MAX_DIMENSIONS && validation;j++){
               
                if(navalBattleBoardPlayer1[i][j] == 'N'){
                    validation = 0;
                }
                
            }
        }
    }
    
    return validation;
}

int attackValidation(int gamester, char coordinate[]){
    int y = 0, x =0;
    coordinate[0] = toupper(coordinate[0]);

    if(isalpha(coordinate[0]) && coordinate[0] < MAX_DIMENSIONS + 65){
        y = coordinate[0] - 65;
    }else{
        return 0;
    }

    for(int i = 1 ; coordinate[i]!='\0'; i++){
        
        if(isdigit(coordinate[i])){
            if(i >1){
                x*= 10;
            }
            x+= (coordinate[i] - 48);
        }else{
            return 0;
        }
    }
    x--;

    if( x<0  || x> MAX_DIMENSIONS){
        return 0;
    }else if(!attack(y, x,gamester)){
        return 0; 
    }else{
        return 1;
    }

}

int attack(int y, int x,int gamester){
    
    if(!gamester){
        if(navalBattleBoardPlayer2[y][x] == 'X'){
            return 0;
        }else{
            if(navalBattleBoardPlayer2[y][x] == ' '){
                navalBattleBoardPlayer2[y][x] = 'X';
            }else{
                navalBattleBoardPlayer2[y][x] = 'O';
            }
        }
    }else{
        
        if(navalBattleBoardPlayer1[y][x] == 'X'){
            return 0;
        }else{
            if(navalBattleBoardPlayer1[y][x] == ' '){
                navalBattleBoardPlayer1[y][x] = 'X';
            }else{
                navalBattleBoardPlayer1[y][x] = 'O';
            }
           
        }
    }

    return 1;
}