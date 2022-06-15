/* 16) O fatorial quádruplo de um número N é dado por (2n)!/n! Faça uma função recursiva que receba um número
inteiro positivo N e retorne o fatorial quádruplo desse número. */
#include <stdio.h>
#include <stdlib.h>

int fatQuadruplo(int n);
int fat(int n, int k);

int main(){
    int n;
    printf("Digite um numero : ");
    scanf("%d", & n);
    getchar();
    
    printf("Resultado: %d", fatQuadruplo(n));
}

int fatQuadruplo(int n) {
	
	return fat(2 * n, n + 1);
}

int fat(int n, int k){
    if(n == k) {
        return  k;
    }
    return n * fat(n - 1, k);
}