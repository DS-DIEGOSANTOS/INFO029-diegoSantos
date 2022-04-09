#include "../model/menu.h"
#include "../model/game.h"

void ship(){
    char t[] = "\t\t\t\t\t\t";
    printf("%s         |\\\n",t);
    printf("%s         |_\\\n",t);
    printf("%s         |__\\\n",t);
    printf("%s         |___\\\n",t);
    printf("%s         |____\\\n",t);
    printf("%s         |_____\\\n",t);
    printf("%s         |______\\\n",t);
    printf("%s __________|_______________\n",t);
    printf("%s \\______________________/\n\n",t);
}


void startup(){
    system(CLEAR);
    ship();
    logo();

    for (int i = 1; i <= 50; i++){
      printf ("  %d%%\r", i*2);
      fflush (stdout);

        for (int j = 0; j < i; j++){
            if (!j)
            printf("  ");

            printf ("%c", 2);
            #if defined(_WIN32) || defined(_WIN64)
                Sleep(0.1); 
            #else
                usleep(0.1*1000);  
            #endif
        }
    }

    system(CLEAR);
}

void logo(){

    printf("\n-------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                  Batalha Naval                                                  |" );
    printf("\n-------------------------------------------------------------------------------------------------------------------\n\n\n");
}

void LeaveTheGame(){

    system(CLEAR);
    ship();
    logo();

    printf("\nFim Do Jogo!\n");

    exit(0);

}

void startMenu(){
    
    int option;
    do{
        system(CLEAR);
        logo();
        printf("1 - inicia jogo\n");
        printf("2 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", & option);
        getchar();

        if(option<1 || option>2){
            printf("digite uma opcao valida\n");
            printf("digite qualquer caracter para continua");
            getchar();
        }
    }while(option<1 || option>2);

    switch (option){
        case 1: startGame(); break;
        case 2: LeaveTheGame(); break;
    }

}


