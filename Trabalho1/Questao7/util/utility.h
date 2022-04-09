#ifndef UTILITY_H 

    #define UTILITY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
   

    char namePlayer[2][255];
    char chessboard[3][3];
    char coordinate[3];


    #if defined(_WIN32) || defined(_WIN64)
        #include <windows.h>
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
        #include <unistd.h>
    #endif

#endif