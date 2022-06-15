/* 18) O superfatorial de um número N é definida pelo produto dos N primeiros fatoriais de N. Assim, o superfatorial de 4 é
sf(4) = 1! * 2! * 3! * 4! = 288. Faça uma função recursiva que receba um número inteiro positivo N e retorne o superfatorial
desse número. */

#include <stdio.h>
#include <stdlib.h>

int superFat(int n);
int fat(int n);

int main(){
    int n;
    printf("Digite um numero : ");
    scanf("%d", & n);
    getchar();
    
    printf("Resultado: %d", superFat(n));
}

int superFat(int n) {
	if(n == 0 || n == 1) {
		return 1;
	}
	
	return fat(n) * superFat(n - 1);

}

int fat(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return n * fat(n - 1);
}