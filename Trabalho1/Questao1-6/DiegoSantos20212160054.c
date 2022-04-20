#include "DiegoSantos20212160054.h"

int q1(char data[]){
   
    Data Data = quebraData(data);
    
    if(Data.valido==0){
      return Data.valido; 
    }else if(isValidoDiaMesAno(Data)){
       Data.valido = 1;
    }else{ 
       Data.valido = 0;
    } 
   return Data.valido;
}

Data quebraData(char data[]){

    Data Data;
    char dia[3];
    char mes[3];
    char ano[5];
    int aux = 0, i;
    
    for(i = 0;data[aux] != '/';aux++, i++){
        dia[i] = data[aux]; 
    }

    if(aux <=2){
        dia[i] = '\0';
        Data.Dia= atoi(dia);
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
        Data.Mes= atoi(mes);
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
        Data.Ano= atoi(ano);
    }else{
        Data.valido = 0;
        return Data;
    }
    Data.valido = 1;
    return Data;
}

int isValidoDiaMesAno(Data data){
   
    if(data.Ano < 0) return 0;
    else if(data.Mes <= 0 || data.Mes > 12 ) return 0;
    else if(data.Dia <= 0 || data.Dia > 31) return 0;
    else if(!isValidoDia( data.Dia, data.Mes, data.Ano)) return 0;
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

diaMesAno q2(char dataInicial[],char dataFinal[]){

    diaMesAno dma;
 
    if(!q1(dataInicial)){
        dma.retorno = 2;      
    }else if(!q1(dataFinal)){
        dma.retorno = 3;       
    }else{

        Data dInicial = quebraData(dataInicial);
        Data dFinal = quebraData(dataFinal);

        if(dInicial.Ano > dFinal.Ano){
            dma.retorno = 4;      
        }else if(dInicial.Ano >= dFinal.Ano && dInicial.Mes > dFinal.Mes ){
            dma.retorno = 4;
        }else if(dInicial.Ano >= dFinal.Ano && dInicial.Mes >= dFinal.Mes &&  dInicial.Dia > dFinal.Dia ){
            dma.retorno = 4;
        }else{
            dma.Qano = dFinal.Ano - dInicial.Ano;
            dma.Qmes = dFinal.Mes - dInicial.Mes;
            dma.Qdia = dFinal.Dia - dInicial.Dia;
            dma.retorno = 1;                 
        }
    }
    
    return dma;

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

    int posicao = 0, verificacao, acentuacao =0;
    
    for(int i = 0; i< strlen(strTexto) ; i++){
        
        verificacao = 1;

        for(int j=0; j< strlen(strBusca) && verificacao;j++){
            
            if(strTexto[i] <0){
            acentuacao ++;
            }

            if(strTexto[i+j] != strBusca[j]){
                verificacao = 0;
            }
        }

        if(verificacao){
            posicoes[posicao] = i- acentuacao +1;
            posicao++;
            posicoes[posicao] = i+strlen(strBusca) - acentuacao ;
            posicao++;
           
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
    
    for(int i = 1; i <= digito ; i++){
        aux*=10;
    }
    
    numerobase = q5(numerobase);
    numerobusca = q5(numerobusca);

    while(numerobase != 0){

        restoDaDivisao = numerobase % aux;

        if(restoDaDivisao == numerobusca){
            qtdDeOcorrencia++;
        }

        numerobase /=aux;

    }    

    return qtdDeOcorrencia;
}

int qtdDeDigitos(int numero){
    int digitos = 0; 

    if(numero < 10){
        digitos = 1;
        return digitos;
    }else{   
        while(numero != 0){    
            digitos++;
            numero /=10;    
        }   
        return  digitos;
    }

}
