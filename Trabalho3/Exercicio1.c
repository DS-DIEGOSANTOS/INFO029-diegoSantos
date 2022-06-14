//1) Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.

#include <stdio.h>
#include <stdlib.h>

double fatorial(int n);

int main(void){
  int numero;
  double f;
  
  printf("Digite o numero que deseja calcular o fatorial: ");
  scanf("%d",&numero);
  getch();

  f = fatorial(numero);
  
  printf("Fatorial de %d = %.0lf",numero,f);
  
  return 0;
}


double fatorial(int n){
  double fat;
  
  if ( n <= 1 ){
    return (1);
  }else{
    fat = n * fatorial(n - 1);
    return (fat);
  }
}