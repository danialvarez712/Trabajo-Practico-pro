#include <iostream>
#include <vector>
#include "puntaje.h"
#include "combinaciones.h"

using namespace std;

int puntaje (vector <int>& dados){
    vector <int> opcion(10);
    int resultado = 0;


    opcion[0] = combinacion_JuegoDe1(dados);
    opcion[1] = combinacion_JuegoDe2(dados);
    opcion[2] = combinacion_JuegoDe3(dados);
    opcion[3] = combinacion_JuegoDe4(dados);
    opcion[4] = combinacion_JuegoDe5(dados);
    opcion[5] = combinacion_JuegoDe6(dados);
    opcion[6] = combinacion_JuegoDeEscalera(dados);
    opcion[7] = combinacion_JuegoDeFull(dados);
    opcion[8] = combinacion_JuegoDePoker(dados);
    opcion[9] = combinacion_JuegoDeGenerala(dados);

    for( int i=0;i<5;i++ ){

        if( opcion[i] > resultado ){

            resultado= opcion[i];
        }
    }

    return resultado;
}

