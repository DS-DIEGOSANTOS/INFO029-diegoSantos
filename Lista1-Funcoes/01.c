#include <stdio.h>
#include <stdlib.h>

float soma(float a , float b){
    float soma = a + b;
    return soma;
}

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