/* 14) Faça uma função recursiva que receba um número inteiro positivo par N e imprima todos os números pares
de 0 até N em ordem crescente. */

#include <stdio.h>
#include <stdlib.h>

int numSeqPar(int n);
int numSeqParSig(int n) ;

int main(){
    int n;
    printf("Digite o numero N: ");
    scanf("%d", & n);
    getchar();
    numSeqParSig(n);
}

int numSeqPar(int n) {
	if(n < 0) {
		return 0;
	}
	2 + numSeqPar(n - 2);
	printf("%d ", n);
}

int numSeqParSig(int n) {
	if(n < 0) {
		return -1 * numSeqPar(n);
	}
	return numSeqPar(n);
}