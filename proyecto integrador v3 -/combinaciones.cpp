#include <iostream>
#include <vector>
#include "combinaciones.h"

using namespace std;


// juego de 1
int combinacion_JuegoDe1 (vector <int>& dados ){
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
int combinacion_JuegoDe2 (vector <int>& dados ){
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
int combinacion_JuegoDe3 (vector <int>& dados ){
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
int combinacion_JuegoDe4 (vector <int>& dados ){
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
int combinacion_JuegoDe5 (vector <int>& dados ){
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
int combinacion_JuegoDe6 (vector <int>& dados ){
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
int combinacion_JuegoDePoker (vector <int>& dados ){
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
int combinacion_JuegoDeEscalera (vector <int>& dados ){
    int numero,resultado;
    bool bandera=true,bandera2=true;

    for (int j=0;j<5;j++){

        for(int i=0;i<4;i++){

            if( dados[i] > dados[i + 1] ){
                numero = dados[i];
                dados[i] = dados[i + 1];
                dados[i + 1] = numero;
            }
        }
    }

    for(int i=0;i<5;i++){

    if(bandera){
        numero = dados[i];
        bandera = false;
    }else{

    if( numero < dados[i] ){
        bandera2=false;
    }

    numero=dados[i];

    }
    }

    if(bandera2){
        resultado = 25;
        return resultado;
    }else{
        return 0;
    }
}


//Juego de full
int combinacion_JuegoDeFull (vector<int>& dados) {

    int contador1 = 0, contador2 = 0;
    bool hay3 = false, hay2 = false;

    for (int numero = 1; numero <= 6; numero++) {

        contador1 = 0;
        for (int i = 0; i < 5; i++) {
            if (dados[i] == numero) {
                contador1++;
            }
        }

        if (contador1 == 3) {
            hay3 = true;
        }

        if (contador1 == 2) {
            hay2 = true;
        }
    }

    if (hay3 && hay2) {
        return 30;
    }

    return 0;
}

//Juego de Generala
int combinacion_JuegoDeGenerala( vector <int>& dados ){
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

    if( contador == 5 ){
        resultado = 50 ;
        return resultado;
    }else{
        return 0;
    }
}

//Juego de generala Servida

int combinacion_JuegoDeGeneralaServida(vector<int>& dados,int tirada){
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

    if( contador == 5 && tirada == 1 ){
        resultado = 100000 ;
        return resultado;
    }else{
        return 0;
    }

}






