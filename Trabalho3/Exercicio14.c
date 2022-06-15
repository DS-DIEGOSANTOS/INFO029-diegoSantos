/* 16) A função fatorial duplo é definida como o produto de todos os números naturais ímpares de 1 até algum
número natural ímpar N. Assim, o fatorial duplo de 5 é 5!! = 1 * 3 * 5 = 15 */

#include <stdio.h>
#include <stdlib.h>
int fatDuplo(int n);

int main(){
    int n;
    printf("Digite um numero : ");
    scanf("%d", & n);
    getchar();
    
    printf("Resultado: %d", fatDuplo(n));
}

int fatDuplo(int n){
	if(n == 1) {
		return 1;
	}
	if(n % 2 == 0) {
		return 0;
	}
	return n * fatDuplo(n - 2);
}