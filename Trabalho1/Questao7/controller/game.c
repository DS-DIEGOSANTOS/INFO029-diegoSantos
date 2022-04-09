#include "../model/game.h"
#include "../util/utility.h"

    
void initializeBoard(){

    for(int i = 0 ; i<3;i++){
        for(int j = 0 ; j<3;j++){
            chessboard[i][j] = ' ';
        }
    }
    
}

int verificationBoard(int jogador){
    int y;
    int x;

    switch (coordinate[0]){
        case 'A': y = 0; break;
        case 'B': y = 1; break;
        case 'C': y = 2; break;   
        default: return 0;
    }

    switch (coordinate[1]){
        case '1': x = 0; break;
        case '2': x = 1; break;
        case '3': x = 2; break;   
        default: return 0;
    }

    if(isVazio(y,x)){
       setTabuleiro(y, x,jogador);  
    }else{
        return 0;
    }
     

}

void setTabuleiro(int y, int x, int  jogador){
    if(jogador == 0) chessboard[y][x] = 'X';
    else if(jogador == 1) chessboard[y][x] = 'O';
}

int isWinner(int jogador){
    char valor;

    if(jogador == 0) valor = 'X';
    else if(jogador == 1) valor = 'O';

    if( isWinnweColumn(valor) || isWinnerLine(valor) || isWinnerDiagonal(valor)){
        return 1;
    }else{
        return 0;
    }

}

int isWinnweColumn(char valor){
    for(int i = 0;i<3;i++){
        if(chessboard[0][i] == valor &&
            chessboard[1][i] == valor &&
            chessboard[2][i] == valor){
                return 1;
            } 
    }

    return 0;
}

int isWinnerLine(char valor){
    for(int i = 0;i<3;i++){
        if(chessboard[i][0] == valor &&
            chessboard[i][1] == valor &&
            chessboard[i][2] == valor){
                return 1;
            } 
    }

    return 0;
}

int isWinnerDiagonal(char valor){
    if(chessboard[0][0] == valor &&
        chessboard[1][1] == valor &&
        chessboard[2][2] == valor){
            return 1;
    }else if(chessboard[2][0] == valor &&
        chessboard[1][1] == valor &&
        chessboard[0][2] == valor){
            return 1;
    }else{
        return 0;
    }
}

int istied(){
    int validacao = 1;
    for(int i = 0 ; i<3;i++){
        for(int j = 0 ; j<3;j++){
            if(chessboard[i][j] == ' '){
                validacao = 0;
            }
        }
    }

    return validacao;
}

int isVazio(int y,int x){
    
    if(chessboard[y][x]== ' '){
        return 1;
    }else{
        return 0;
    }

}
