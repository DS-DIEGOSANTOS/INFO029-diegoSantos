/* 04)Faça uma função recursiva que permita somar os elementos de um vetor de inteiros. */

#include <stdio.h>
#include <stdlib.h>

int somaVetor(int vet[] , int n);

int main(){
  int vet[5] = {1,5,20,30,4};
  int tamanho = sizeof(vet)/sizeof(int);
  int soma = somaVetor(vet,tamanho);
  printf("Soma: %d", soma);

  return 0;
}

int somaVetor(int vet[] , int n){

  if(n == 1)
    return vet[0];
  else 
    return vet[n-1] + somaVetor(vet,n-1);
}