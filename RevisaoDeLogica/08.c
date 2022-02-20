#include <stdio.h>
#include<stdlib.h>

int main(){
    int numero;
    int fatorial=1;
    
    printf("Digite um numero : ");
    scanf("%d",& numero);

    for(int i= 1;i<=numero;i++){
        fatorial*=i;
    }

    printf("fatorial: %d", fatorial);

    return 0;
}