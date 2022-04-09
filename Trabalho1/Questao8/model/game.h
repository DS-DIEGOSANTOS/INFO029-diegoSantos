#ifndef GAME_H 

    #define GAME_H
    #include "../util/utility.h"
    
    /* funcao 01: inicio do jogo */
    void startGame();

    /* funcao 02: inscricao dos jogadores */
    void subscription();

    /* funcao 03: inicialização o jogo*/
    void initialize();

    /* funcao 04: inicialização do tabuleiro */
    void initializeBoard();

    /* funcao 05: tabuleiro do jogador 1 e jogador2 */
    void toStringBoard(int playerBoard);

    /* funcao 06: tabuleiro do jogador individual */
    void toStringBoardPlayer(int playerBoard);

    /* funcao 07: posiciona os navios */
    void coordinateShip();

    /* funcao 08: retorna as coordenada e verifica se e valida */
    playerCoordinate verificationBoard(int gamester, char coordinate[]);

    /* funcao 09: verifica se esta vazio o caracter*/
    int isempty(int x, int y, int gamester);

    /* funcao 10: valida a colocação do navio */
    int validationFillInBoard(playerCoordinate Player,int posicao, int gamester);

    /* funcao 11: logo do navio */
    void fillWithShip(int y , int x , int gamester);

    /* funcao 12: tabuleiro principal e aplicacao de todos as fucoes */
    void Board();

    /* funcao 13: verifica se o ataque foi validado */
    int  attackValidation(int gamester, char coordinate[]);

    /* funcao 14: atacar o navio inimigo */
    int attack(int y, int x,int gamester);

    /* funcao 15: verifica se tem ganhador */
    int isWinner(int gamester);

#endif