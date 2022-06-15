/* 24) Os números de Pell são definidos pela seguinte recursão: P(n) = 0 se n = 0; P(n) = 1 se n = 1;
P(n) = 2P(n - 1) + P(n - 2) Alguns números desta sequência são: 0, 1, 2, 5, 12, 29, 70, 169, 408, 985...
Faça uma função recursiva que receba um número N e retorne o N-ésimo número de Pell.*/

int pell(int n);

int main(){
    int n;
    printf("Digite um numero : ");
    scanf("%d", & n);
    getchar();
    
    printf("Resultado: %d", pell(n-1));
}

int pell(int n) {
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	return 2 * pell(n - 1) + pell(n - 2);
}