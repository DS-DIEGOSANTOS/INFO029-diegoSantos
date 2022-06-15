/* 13) --> Faça uma função recursiva que receba um número inteiro positivo N e imprima todos os números naturais de
0 até N em ordem decrescente */
#include <stdio.h>
#include <stdlib.h>

int numNaturaisDec(int n);
int retNaturaisDecSig(int n);

int main(){
    int n;
    printf("Digite o numero N: ");
    scanf("%d", & n);
    getchar();
    retNaturaisDecSig(n);
}

int numNaturaisDec(int n) {
	if(n == -1) {
		return 0;
	}
	printf("%d ", n);
	numNaturaisDec(n - 1);
}

int retNaturaisDecSig(int n) {
	if(n < 0) {
		return numNaturaisDec(n * -1);
	}
	return numNaturaisDec(n);
}