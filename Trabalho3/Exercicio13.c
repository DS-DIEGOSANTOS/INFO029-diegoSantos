/* 15) Faça uma função recursiva que receba um número inteiro positivo par N e imprima todos os números pares
de 0 até N em ordem decrescente. */

#include <stdio.h>
#include <stdlib.h>

int numSeqParDec(int n);
int numSeqParDecSig(int n);

int main(){
    int n;
    printf("Digite o numero N: ");
    scanf("%d", & n);
    getchar();
    numSeqParDecSig(n);
}

int numSeqParDec(int n) {
	if(n == 0) {
		printf("%d ", 0);
		return 0;
	}
	if(n % 2 == 0) {
		printf("%d ", n);
	}
	numSeqParDec(n - 1);
}
int numSeqParDecSig(int n) {
	if(n < 0) {
		return -1 * numSeqParDec(n);
	}
	return numSeqParDec(n);
}