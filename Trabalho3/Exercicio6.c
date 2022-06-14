#include <stdio.h>
#include <stdlib.h>

int pontencializacao(int k, int n);

int main(){
  int k,N, resultado;
  
  printf("Digite o valor de (K):");
  scanf("%d", & k);
  getchar();
  
  printf("Digete o valor de (N):");
  scanf("%d", & N);
  getchar();

  printf("Resultado: %d", pontencializacao(k,N));
  
}

int pontencializacao(int k, int n){

  if(n == 1)
    return k;
  else
    return k*pontencializacao(k,n-1);
}