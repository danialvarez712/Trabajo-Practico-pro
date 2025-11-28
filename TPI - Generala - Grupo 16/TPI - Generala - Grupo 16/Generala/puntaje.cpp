#include <iostream>
#include <vector>
#include "puntaje.h"
#include "combinaciones.h"

using namespace std;



int puntaje (int dados[]){
    int opcion[10], combinacionUsada;
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

    for( int i=0;i<10;i++ ){

        if( opcion[i] > resultado ){

            resultado = opcion[i];
            combinacionUsada = i + 1;
        }

}

     switch (combinacionUsada) {
        case 1: cout << "---- Usaste Juego de 1 ----" << endl; break;
        case 2: cout << "---- Usaste Juego de 2 ----" << endl; break;
        case 3: cout << "---- Usaste Juego de 3 ----" << endl; break;
        case 4: cout << "---- Usaste Juego de 4 ----" << endl; break;
        case 5: cout << "---- Usaste Juego de 5 ----" << endl; break;
        case 6: cout << "---- Usaste Juego de 6 ----" << endl; break;
        case 7: cout << "----- Usaste Escalera -----" << endl; break;
        case 8: cout << "----- Usaste Full -----" << endl; break;
        case 9: cout << "----- Usaste Poker -----" << endl; break;
        case 10: cout << "----- Usaste Generala -----" << endl; break;
        case 11: cout << "----- Usaste Generala servida -----" << endl; break;
    }


    return resultado;
}
