#include <iostream>
#include <vector>
#include "combinaciones.h"

using namespace std;


// juego de 1
int combinacion_JuegoDe1 (int dados[]){
    int resultado,contador=0;

    for (int i=0;i<5;i++){

        if (dados[i] == 1){
            contador++;
        }

    }

    if(contador>0){
        resultado= 2 * contador;
    }
    else{
        return 0;
    }
    return resultado;
}

//juego de 2
int combinacion_JuegoDe2 (int dados[]){
    int resultado,contador=0;

    for (int i=0;i<5;i++){

        if (dados[i] == 2){
            contador++;
        }

    }

    if(contador>0){
        resultado= 2 * contador;
    }
    else{
        return 0;
    }
    return resultado;
}

//juego de 3
int combinacion_JuegoDe3 (int dados[]){
    int resultado,contador=0;

    for (int i=0;i<5;i++){

        if (dados[i] == 3){
            contador++;
        }

    }

    if(contador>0){
        resultado= 3 * contador;
    }
    else{
        return 0;
    }
    return resultado;
}

//juego de 4
int combinacion_JuegoDe4 (int dados[]){
    int resultado,contador=0;

    for (int i=0;i<5;i++){

        if (dados[i] == 4){
            contador++;
        }

    }

    if(contador>0){
        resultado= 4 * contador;
    }
    else{
        return 0;
    }
    return resultado;
}

//juego de 5
int combinacion_JuegoDe5 (int dados[]){
    int resultado,contador=0;

    for (int i=0;i<5;i++){

        if (dados[i] == 5){
            contador++;
        }

    }

    if(contador>0){
        resultado= 5 * contador;
    }
    else{
        return 0;
    }
    return resultado;
}


//juego de 6
int combinacion_JuegoDe6 (int dados[]){
    int resultado,contador=0;

    for (int i=0;i<5;i++){

        if (dados[i] == 6){
            contador++;
        }

    }

    if(contador>0){
        resultado= 6 * contador;
    }
    else{
        return 0;
    }
    return resultado;
}


//juego de poker
int combinacion_JuegoDePoker (int dados[]){
    int resultado,contador=0,numero=1,contador2=0;


    while(numero != 7 ){
    for (int i=0;i<5;i++){

        if (dados[i] == numero){
            contador++;
        }
    }

    if(contador == 4){
        contador2++;
    }
    contador=0;
    numero++;
    }


    if(contador2>0){
        resultado = 40 ;
    }
    else{
        return 0;
    }
    return resultado;
}


//Juego de Escalera
int combinacion_JuegoDeEscalera (int dados[]){
    int numero,dadosCopiados[5];
    bool bandera=true,bandera2=true;

    for ( int i=0;i<5;i++ ){
        dadosCopiados[i] = dados[i];
    }

    for (int j=0;j<5;j++){

        for(int i=0;i<4;i++){

            if( dadosCopiados[i] > dadosCopiados[i + 1] ){
                numero = dadosCopiados[i];
                dadosCopiados[i] = dadosCopiados[i + 1];
                dadosCopiados[i + 1] = numero;
            }
        }
    }

    for (int i = 1; i < 5; i++) {
        if (dadosCopiados[i] != dadosCopiados[i - 1] + 1) {
            return 0;
        }
    }

    return 25;
}


//Juego de full
int combinacion_JuegoDeFull(int dados[]){
    int contador[7] = {0},valor;
    bool trio = false,pareja = false;

    for (int i = 0; i < 5; i++) {
        valor = dados[i];
        contador[valor]++;
    }

    for (int i = 1; i <= 6; i++) {
        if (contador[i] == 3) trio = true;
        if (contador[i] == 2) pareja = true;
    }

    if (trio && pareja) return 30;

    return 0;
}

//Juego de Generala
int combinacion_JuegoDeGenerala( int dados[]){
    int resultado,numero,contador=0;
    bool bandera = true;

    for(int i=0;i<5;i++){

    if(bandera){
        numero = dados[i];

        bandera=false;
    }else if( numero == dados[i] ){

        contador++;
    }

    }

    if( contador == 4 ){
        resultado = 50 ;
        return resultado;
    }else{
        return 0;
    }
}

//Juego de generala Servida

int combinacion_JuegoDeGeneralaServida(int dados[],int tirada){
    int resultado,numero,contador=0;
    bool bandera = true;

    for(int i=0;i<5;i++){

    if(bandera){
        numero = dados[i];

        bandera=false;
    }else if( numero == dados[i] ){

        contador++;
    }

    }

    if( contador == 4 && tirada == 1 ){
        resultado = 100000 ;
        return resultado;
    }else{
        return 0;
    }

}






