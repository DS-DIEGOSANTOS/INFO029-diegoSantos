/* 12) Faça uma função recursiva que receba um número inteiro positivo N e imprima todos os números naturais de 0
até N em ordem crescente. */
#include <stdio.h>
#include <stdlib.h>

int numNaturais(int num);
int retNaturaisSig(int num);

int main(){
    int n;
    printf("Digite o numero N: ");
    scanf("%d", & n);
    getchar();

    retNaturaisSig(n);
}

int numNaturais(int n) {
	if(n == -1) {
		return 0;
	}
	1 + numNaturais(n - 1);
	printf("%d ", n);
}

int retNaturaisSig(int n) {
	if(n < 0) {
		return numNaturais(n * -1);
	}
	return numNaturais(n);
}