/*
    2) Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência
    Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
*/

#include <stdio.h>
#include <stdlib.h>

int fatorialFibpnacci(int num);

main(){
    int num;
    printf("Digite a quantidade de termos da sequencia de Fibonacci: ");
    scanf("%d", &num);
    getchar();

    printf("\nA sequência de Fibonacci e: \n");
   for(int i=0; i<num; i++)
       printf("%d ", fibonacci(i));

}

int fibonacci(int num){
    if (num == 0)
        return 0;
    else if(num==1 || num==2)
        return 1;
    else
        return fibonacci(num-1) + fibonacci(num-2);
}