/* 05) Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a N */

#include <stdio.h>
#include <stdlib.h>

int somaN(int n);

int main(){
  int num, resultado;
  printf("Digite o numero um numero");
  scanf("%d", & num);
  getchar();

  printf("Resultado: %d", somaN(num));
}

int somaN(int n){
  if(n == 1)
    return n;
  else
    return n + somaN(n-1);
}