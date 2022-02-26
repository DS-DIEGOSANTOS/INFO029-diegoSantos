#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 255
#define MAX_CPF 15

typedef struct nascimento{
    int dia;
    int mes;
    int ano;
} Nascimento;
 
typedef struct pessoa{
    char nome[MAX_NOME];
    Nascimento nascimento;
    char sexo;
    char cpf[MAX_CPF];
} Pessoa;

Pessoa cadastroCliente();

int main(){

    Pessoa pessoa = cadastroCliente();
   
        printf("----------------------------------\n"); 
        printf("Cadastro\n");   
        printf("----------------------------------\n");

        printf("nome: %s\n", pessoa.nome);
        printf("Data de nascimento: %d / %d / %d\n",
         pessoa.nascimento.dia,
         pessoa.nascimento.mes,
         pessoa.nascimento.ano);
        printf("Sexo: %c\n", pessoa.sexo);
        printf("CPF: %s\n", pessoa.cpf);
        printf("----------------------------------\n");

    return 0;
}

Pessoa cadastroCliente(){
    Pessoa cadastro;
    printf("----------------------------------\n");
    printf("Cadastro\n");
    printf("----------------------------------\n");

    printf("digite seu nome: ");
    fgets(cadastro.nome,MAX_NOME,stdin);

    size_t ln = strlen(cadastro.nome) - 1;
    if (cadastro.nome[ln] == '\n')
        cadastro.nome[ln] = '\0';    

    printf("digite sua data de nascimento(## ## ####): ");
    scanf("%d %d %d",
    & cadastro.nascimento.dia,
    & cadastro.nascimento.mes,
    & cadastro.nascimento.ano);

    getchar();

    printf("digite seu sexo: ");
    scanf("%c",& cadastro.sexo);

    getchar();

    printf("digite seu cpf(###.###.###-##): ");
    fgets(cadastro.cpf,MAX_CPF,stdin);
    ln = strlen(cadastro.cpf) - 1;
    if (cadastro.cpf[ln] == '\n')
        cadastro.cpf[ln] = '\0';

    return cadastro;     
}
