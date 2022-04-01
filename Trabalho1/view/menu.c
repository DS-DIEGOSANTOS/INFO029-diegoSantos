#include "../model/menu.h"

void startup(){
    
    printf("     jjjj    oooooo     GGGGGGGGGG     oooooo    \n");
    printf("     j::j   o::oo::o   G::GGGGGGGGG   o::oo::o     \n");
    printf("     j::j  o::o   o:o  G::G          o::o   o:o  \n");
    printf("     j::j  o::o   o:o  G::G   GGGGGG o::o   o:o      \n");
    printf("     j::j  o::o   o:o  G::G   GGGG:G o::o   o:o\n");
    printf("jjj  j::j  o::o   o:o  G::G      G:G o::o   o:o \n");
    printf("j::jj:::j   O::oo::o   G:::GGGGGG::G  O::oo::o       \n");
    printf("jjjjjjjjj    oooooo     GGGGGGGG G     oooooo   \n");
    printf("\n----------------------------------------------------\n");
    printf("\t\t\tDA VELHA                            ");
    printf("\n-----------------------------------------------------\n");
    

    for (int i = 1; i <= 50; i++){
      printf ("  %d%%\r", i*2);
      fflush (stdout);

        for (int j = 0; j < i; j++){
            if (!j)
            printf("  ");

            printf ("%c", 2);
            Sleep(0.1);
        }
    }

    system(CLEAR);
}


void LeaveTheGame(){

    system(CLEAR);
      
    printf("     jjjj    oooooo     GGGGGGGGGG     oooooo    \n");
    printf("     j::j   o::oo::o   G::GGGGGGGGG   o::oo::o     \n");
    printf("     j::j  o::o   o:o  G::G          o::o   o:o  \n");
    printf("     j::j  o::o   o:o  G::G   GGGGGG o::o   o:o      \n");
    printf("     j::j  o::o   o:o  G::G   GGGG:G o::o   o:o\n");
    printf("jjj  j::j  o::o   o:o  G::G      G:G o::o   o:o \n");
    printf("j::jj:::j   O::oo::o   G:::GGGGGG::G  O::oo::o       \n");
    printf("jjjjjjjjj    oooooo     GGGGGGGG G     oooooo   \n");
    printf("\n----------------------------------------------------\n");
    printf("\t\t\tDA VELHA                            ");
    printf("\n-----------------------------------------------------\n");
    printf("\nFim Do Jogo!\n");

    exit(0);

}

void logo(){
    printf("\n----------------------------------------------------\n");
    printf("                   JOGO DA VELHA                            ");
    printf("\n-----------------------------------------------------\n\n\n"); 
}


void startMenu(){
    
    int option;
    do{
        system(CLEAR);
        logo();
        printf("1 - inicia jogo\n");
        printf("2 - Sair\n");
        printf("Digite uma opçao: ");
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
