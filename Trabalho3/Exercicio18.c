/* 22) Os números tetranacci iniciam com quatro termos pré-determinados e a partir daí todos os demais números são
obtidos pela soma dos quatro números anteriores. Os primeiros números tetranacci são:
0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108, 208... Faça uma função recursiva que receba um número N e retorne o
N-ésimo termo da sequência de tetranacci. */
#include <stdio.h>
#include <stdlib.h>

int tetranacci(int n);

int main(){
    int n;
    printf("Digite um numero : ");
    scanf("%d", & n);
    getchar();
    
    printf("Resultado: %d", tetranacci(n-1));
}

int tetranacci(int n) {
	if(n == 0 || n == 1 || n == 2) {
		return 0;
	}
	if(n == 3) {
		return 1;
	}
	return tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
}