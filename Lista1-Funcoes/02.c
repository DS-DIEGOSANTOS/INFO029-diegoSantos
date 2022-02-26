#include <stdio.h>
#include <stdlib.h>

float subtrai(float a , float b, float c);

int main(){
    float a,b,c, resultado;

    printf("Digite o valor 01: ");
    scanf("%f", & a);
    printf("Digite o valor 02: ");
    scanf("%f", & b);
    printf("Digite o valor 03: ");
    scanf("%f", & c);

    resultado = subtrai(a,b,c);

    printf("resultado da soma: %.1f", resultado);

    return 0;  
}

float subtrai(float a , float b, float c){
    float resultado = a - b - c;
    return resultado;
}