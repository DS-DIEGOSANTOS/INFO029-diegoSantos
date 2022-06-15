/* 08) máximo divisor comum dos inteiros x e y é o maior inteiro que é divisível por x e y. Escreva uma função recursiva mdc em C,
que retorna o máximo divisor comum de x e y. O mdc de x e y é definido como segue: se y é igual a 0, então mdc(x,y) é x;
caso contrário, mdc(x,y) é mdc (y, x%y), onde % é o operador resto.*/
#include <stdio.h>
#include <stdlib.h>

int maxDivCom(int a, int b);

int main(){
  int x , y;

  printf("Digite o valor de X: ");
  scanf("%d", & x);
  getchar();

  printf("Digite o valor de y: ");
  scanf("%d", & y);
  getchar();

  printf("Resultado %d", maxDivCom(x,y) );

}

int maxDivCom(int a, int b) {
	if( b == 0) {
		return a;
	}
	maxDivCom(b, a % b);
}