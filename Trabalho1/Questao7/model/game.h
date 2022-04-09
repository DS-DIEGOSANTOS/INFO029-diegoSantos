#ifndef GAME_H 

    #define GAME_H
    #include "../util/utility.h"
    
    void startGame();
    void subscription();
    void initializeBoard();
    void Board();
    void toStringBoard();
    int verificationBoard(int jogador);
    void setTabuleiro(int y, int x, int  jogador);
    int isWinner(int jogador);
    int isWinnweColumn(char valor);
    int isWinnerLine(char valor);
    int isWinnerDiagonal(char valor);
    int istied();
    int isVazio(int y,int x);
    void initialize();
    



#endif