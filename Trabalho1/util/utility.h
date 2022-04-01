#ifndef UTILITY_H 

    #define UTILITY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define quantidadeDeJogadores 2
    #define MAX_NAME_LEN 255
 

    #if defined(_WIN32) || defined(_WIN64)
        #include <windows.h>
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
        #include <unistd.h>
    #endif

#endif