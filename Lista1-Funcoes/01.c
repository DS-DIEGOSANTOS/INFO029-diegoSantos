#include <stdio.h>
#include <stdlib.h>

float soma(float a , float b);

int main(){
    float a,b, resultado;

    printf("Digite o valor 01: ");
    scanf("%f", & a);
    printf("Digite o valor 02: ");
    scanf("%f", & b);

    resultado = soma(a,b);

    printf("resultado da soma: %.1f", resultado);

    return 0;
}

float soma(float a , float b){
    return a+b;
}
