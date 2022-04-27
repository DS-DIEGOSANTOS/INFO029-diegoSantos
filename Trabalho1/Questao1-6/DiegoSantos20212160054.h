// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Diego Santos Dos SAntos
//  email: ds86897443@gmail.com
//  Matrícula: 20212160054
//  Semestre: 2122.1

//  Copyright © 2016 Renato Novais. All rights reserved.

// #################################################
#ifndef DiegoSantos20212160054_H
    #define DiegoSantos20212160054_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>

typedef struct DQ{
    int iDia;
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

}DataQuebrada;

typedef struct Qtd{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

}DiasMesesAnos;


    int q1(char Data[]); //verifica se a data e valida
    DataQuebrada quebraData(char data[]); //verifica e recupera o dia , mes e ano
    int isValidoDiaMesAno(DataQuebrada data);//verifica se o dia , mes e ano sao valido
    int isValidoDia(int dia, int mes, int ano);// valida o dia correspondente ao mes e ano 
    int validaSomenteNumero(char c);
  
    DiasMesesAnos q2(char dataInicial[],char dataFinal[]);
    int qtdDeDiaDeuMmes(int mes,int ano);
    int q3(char *texto, char caracter , int isCaseSensitive);
    int q4(char *strTexto, char *strBusca, int posicoes[30]);
    int q5(int num);
    int q6(int numerobase, int numerobusca);
    int qtdDeDigitos(int numero);
    void removeAcentuacao(char strTexto[] , char strTextoCopia[]);
        


#endif
