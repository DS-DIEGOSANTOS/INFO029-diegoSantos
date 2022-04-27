#include "DiegoSantos20212160054.h"

int validaSomenteNumero(char c){

    if(isalpha(c) || ispunct(c)) return 0;
    return 1;
}

int q1(char data[]){
   
    DataQuebrada Data = quebraData(data);
    if(Data.valido==0){
      return Data.valido; 
    }else if(isValidoDiaMesAno(Data)){
       Data.valido = 1;
    }else{ 
       Data.valido = 0;
    } 
   return Data.valido;
}

DataQuebrada quebraData(char data[]){
    DataQuebrada Data;
    char dia[3];
    char mes[3];
    char ano[5];
    int aux = 0, i;
    
    for(i = 0;data[aux] != '/';aux++, i++){
        dia[i] = data[aux]; 
    }

    if(aux <=2){
        dia[i] = '\0';
        Data.iDia= atoi(dia);
    }else{
        Data.valido = 0;
        return Data;
    }

    aux++;

    for( i = 0;data[aux] != '/';aux++, i++){
        mes[i] = data[aux]; 
    }

    if(aux>=1 && aux<=5){
        mes[i] = '\0';
        Data.iMes= atoi(mes);
    }else{
        Data.valido = 0;
        return Data;
    }


    aux++;

    for(i = 0;data[aux] != '\0';aux++,i++){
        ano[i] = data[aux]; 
    }

    if(aux >= 3 && aux<=10){
        ano[i] = '\0';
        Data.iAno= atoi(ano);
    }else{
        Data.valido = 0;
        return Data;
    }
    Data.valido = 1;
    return Data;
}

int isValidoDiaMesAno(DataQuebrada data){
   
    if(data.iAno < 0) return 0;
    else if(data.iMes <= 0 || data.iMes > 12 ) return 0;
    else if(data.iDia <= 0 || data.iDia > 31) return 0;
    else if(!isValidoDia( data.iDia, data.iMes, data.iAno)) return 0;
    else return 1;
}

int isValidoDia(int dia, int mes, int ano){

    int isLeapYear;

    if(ano%400 == 0 || (ano%4 == 0 && ano%100 != 0)) isLeapYear = 1;
    else isLeapYear = 0;

    if(
        mes == 1 || 
        mes == 3 ||
        mes == 5 || 
        mes == 7 ||
        mes == 8 || 
        mes == 10||
        mes == 12
    ){
        if(dia <=31) return 1;
        else return 0;
         
    }else if(mes == 2 && isLeapYear ){
        if(dia <=29) return 1;
        else return 0;          
    }else if(mes == 2 && !isLeapYear){
        if(dia <= 28) return 1;
        else return 0;
    }else{
        if(dia <= 30) return 1;
        else return 0;
    }

}

DiasMesesAnos q2(char dataInicial[],char dataFinal[]){

    DiasMesesAnos dma;
 
    if(!q1(dataInicial)){
        dma.retorno = 2;      
    }else if(!q1(dataFinal)){
        dma.retorno = 3;       
    }else{

        DataQuebrada dInicial = quebraData(dataInicial);
        DataQuebrada dFinal = quebraData(dataFinal);



        if(dInicial.iAno > dFinal.iAno){
            dma.retorno = 4;      
        }else if(dInicial.iAno >= dFinal.iAno && dInicial.iMes > dFinal.iMes ){
            dma.retorno = 4;
        }else if(dInicial.iAno >= dFinal.iAno && dInicial.iMes >= dFinal.iMes &&  dInicial.iDia > dFinal.iDia ){
            dma.retorno = 4;
        }else{
            dma.qtdAnos = dFinal.iAno - dInicial.iAno;
            dma.qtdMeses = dFinal.iMes - dInicial.iMes;
            dma.qtdDias = dFinal.iDia - dInicial.iDia;
            dma.retorno = 1;         

            if (dma.qtdMeses < 0){
                dma.qtdAnos--;
                dma.qtdMeses += 12;
            }         

            if (dma.qtdDias < 0){
            if(dma.qtdMeses == 0){
                dma.qtdAnos--;
                dma.qtdMeses = 11;
            }else
                dma.qtdMeses--;
            dma.qtdDias = qtdDeDiaDeuMmes(dFinal.iMes, dFinal.iAno) - dInicial.iDia + dFinal.iDia;
        }      
        }
    }
    
    return dma;

} 

int qtdDeDiaDeuMmes(int mes,int ano){
    mes--;
    int isLeapYear;

    if(ano%400 == 0 || (ano%4 == 0 && ano%100 != 0)) isLeapYear = 1;
    else isLeapYear = 0;

    if(
        mes == 1 || 
        mes == 3 ||
        mes == 5 || 
        mes == 7 ||
        mes == 8 || 
        mes == 10||
        mes == 12
    ){
        return 31;      
    }else if(mes == 2 && isLeapYear ){
        return 29;          
    }else if(mes == 2 && !isLeapYear){
        return 28;
    }else{
         return 30;
    }
}


int q3(char *texto, char caracter , int isCaseSensitive){

    int qtdDeOcorrencia = 0;

    for(int i = 0 ; i < strlen(texto); i++){

        if(!isCaseSensitive && toupper(texto[i]) == toupper(caracter) ){
            qtdDeOcorrencia++;
            
        }else if(isCaseSensitive && texto[i] == caracter){
            qtdDeOcorrencia++;
        }
    }

    return qtdDeOcorrencia;
}

int q4(char *strTexto, char *strBusca,int *posicoes){

    int posicao = 0, verificacao, acentuacao =0, aux=0;

    
    for(int i = 0; i< strlen(strTexto) ; i++){
        
        verificacao = 1;

        if(strTexto[i] ==-61){
            acentuacao ++;
        }

        if(strTexto[i] == strBusca[0]){
            for(int j = 1 ; strBusca[j] !='\0' && verificacao; j++ ){

                if(strTexto[i+j] != strBusca[j]){
                    verificacao =0;
                }
            }


            if(verificacao){
                posicoes[posicao] = i+1-acentuacao;
                posicao++;
                posicoes[posicao] = i+strlen(strBusca)-acentuacao;
                posicao++;
                i += strlen(strBusca) -1;
            }
        }

    }

    return posicao/2;
}

int q5(int num){
    
    int inverso = 0, aux;    

    while(num != 0){    
        aux = num % 10;
        inverso = inverso * 10 + aux;    
        num /=10;    
    }   

    return inverso;
}

int q6(int numerobase, int numerobusca){

    int restoDaDivisao,aux =1, qtdDeOcorrencia = 0;
    int digito = qtdDeDigitos(numerobusca);
    
    for(int i = 0; i < digito ; i++){
        aux*=10;
    }
   

    while(numerobase != 0){


        if(numerobase % aux == numerobusca){
            qtdDeOcorrencia++;
            numerobase/=aux;
        }else{
            numerobase/=10;
        }

        

    }    

    return qtdDeOcorrencia;
}

int qtdDeDigitos(int numero){
    int qtdDigito = 0;

    while(numero > 0){
        qtdDigito++;
        numero /= 10;
        
    }
    return qtdDigito;

}
