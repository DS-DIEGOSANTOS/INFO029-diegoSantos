/* 10) --> Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um número natural N.
Por exemplo, o dígito 2 ocorre 3 vezes em 762021192 */
#include <stdio.h>
#include <stdlib.h>

int qtdDeOcorrencia(int n, int k, int i);

int main(){
    int k=0,n=0,i=0;

    printf("Digite o numero K: ");
    scanf("%d", & k);
    getchar();

    printf("Digite o numero N: ");
    scanf("%d", & n);
    getchar();    

    printf("o digito %d ocorre %d vezes em %d", k , qtdDeOcorrencia(n,k,i),n);

}

int qtdDeOcorrencia(int n, int k, int i) {
	if(n % 10 == k) {
		i++;
	}
	if(n % 10 == n) {
		return i;
	}
	qtdDeOcorrencia(n / 10, k, i);
}