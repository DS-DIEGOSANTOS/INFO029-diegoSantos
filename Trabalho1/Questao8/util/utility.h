#ifndef UTILITY_H 

    #define UTILITY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <math.h>

    #define MAX_PLAYER 2
    #define MAX_LEN_NAME 255
    #define MAX_DIMENSIONS 10
    #define MAX_COORDINATE 4
    #define MAX_SHIP 5

    char namePlayer[MAX_PLAYER][MAX_LEN_NAME];
    char navalBattleBoardPlayer1[MAX_DIMENSIONS][MAX_DIMENSIONS];
    char navalBattleBoardPlayer2[MAX_DIMENSIONS][MAX_DIMENSIONS];

    enum direction{NORTE,LESTE,SUL,OESTE} direction;

    typedef struct playerCoordinate{
        int x;
        int y;
        int Validation;
        int Direction;
    }playerCoordinate;


    #if defined(_WIN32) || defined(_WIN64)
        #include <windows.h>
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
        #include <unistd.h>
    #endif

#endif