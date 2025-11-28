#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "rlutil.h"
#include "tiradas_dados.h"
#include "combinaciones.h"
#include "PuntajeMaximo.h"
#include "Creditos.h"
#include "EntreTurnos.h"
#include "modoDosJugadores.h"
#include "modoUnJugador.h"

using namespace std;

int main(){


    int opcion,puntajeModoUnJugador = 0,puntajeMaxModoDosJugadores=0,puntajeMaxActual=0;
    string nombreModoUnJugador,nombreGanador,nombrePuntajeMaxActual;
    bool bandera = false;

    do
    {

        system("cls");
        rlutil::locate(30,10);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout<< "------------------------------------------------------" <<endl;
        rlutil::locate(30,11);
        cout<< "             BIENVENIDOS AL JUEGO GENERALA"              <<endl;
        rlutil::locate(30,12);
        cout<< "------------------------------------------------------" <<endl;

        rlutil::locate(30,13);
        cout<< " 1. Juego modo un jugador. " <<endl;
        rlutil::locate(30,14);
        cout<< " 2. Juego modo dos jugadores. " <<endl;
        rlutil::locate(30,15);
        cout<< " 3. ver puntuacion mas alta. " <<endl;
        rlutil::locate(30,16);
        cout<< " 4. ver creditos. "<<endl;
        rlutil::locate(30,17);
        cout<< "------------------------------------------------------" <<endl;
        rlutil::locate(30,18);
        cout<< " 0. salir "<< endl;

        rlutil::locate(40,21);
        cout<< "Selecciona una opcion para empezar:"<<endl;
        rlutil::locate(75,21);
        cin>> opcion;

        switch (opcion){



        case 1:

            puntajeModoUnJugador = modoUnJugador(nombreModoUnJugador);
            ActualizarPuntajeMaximo(puntajeMaxActual,nombrePuntajeMaxActual,puntajeModoUnJugador,nombreModoUnJugador);

            break;

        case 2:

            puntajeMaxModoDosJugadores = ModoDosJugadores(nombreGanador);
            ActualizarPuntajeMaximo(puntajeMaxActual,nombrePuntajeMaxActual,puntajeMaxModoDosJugadores,nombreGanador);

            break;


        case 3:

            PuntajeMasAltoDisenio(puntajeMaxActual,nombrePuntajeMaxActual);


            break;


        case 4:

            Creditos();

            break;


        case 0:
            cout<< "saliendo del programa..."  ;
            break;

        default:
            rlutil::setColor(rlutil::LIGHTRED);
            rlutil::locate(34,23);
            cout << "Opcion no valida selecione un numero entre ( 0-4 )";
            rlutil::locate(39,25);
            system("pause");
            break;

        }
    }
    while(opcion != 0);



    return 0;
}
