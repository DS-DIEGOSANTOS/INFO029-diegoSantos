/* 11) A multiplicação de dois números inteiros pode ser feita através de somas sucessivas. Proponha um algoritmo recursivo
Multip_Rec(n1,n2) que calcule a multiplicação de dois inteiros */
#include <stdio.h>
#include <stdlib.h>

int multiplicacaoRec(int a, int b);

int main(){
    int N1,N2;

    printf("Digite o numero N1: ");
    scanf("%d", & N1);
    getchar();

    printf("Digite o numero N2: ");
    scanf("%d", & N2);
    getchar();    

    printf("Resultado %d", multiplicacaoRec(N1, N2));

}

int multiplicacaoRec(int a, int b) {
	if(a == 0 || b == 0) {
		return 0;
	}
	if(b == 1) {
		return a;
	}
	return a + multiplicacaoRec(a, b - 1);
}