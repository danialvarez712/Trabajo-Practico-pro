#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "rlutil.h"
#include "tiradas_dados.h"
#include "combinaciones.h"

using namespace std;

int main(){

    SetConsoleOutputCP(CP_UTF8);

    int puntajeMaximo=0;
    int opcion,a,dado,puntajeTotal = 0;
    vector <int> numeros;
    string nombre,nombrePuntajeMaximo;

    do
    {
        system("cls");
        cout<< "------------------------------------------------------" <<endl;
        cout<< "             BIENVENIDOS AL JUEGO GENERALA"              <<endl;
        cout<< "------------------------------------------------------" <<endl;
        cout<<endl;
        cout<< "          Selecciona una opcion para empezar  "          <<endl;
        cout<<endl;
        cout<< " 1. Juego modo un jugador. " <<endl;
        cout<< " 2. Juego modo dos jugadores. " <<endl;
        cout<< " 3. ver puntuacion mas alta. " <<endl;
        cout<< " 4. ver creditos. "<<endl;
        cout<< " 0. salir "<< endl;
        cout<< "------------------------------------------------------" <<endl;
        cout<< endl;

        cin>> opcion;

        switch (opcion)
        {
        case 1:

            system("cls");
            cout<< "-------------------------------------------------------------------------"<<endl;
            cout<< "                       ingrese su nombre:";
            cin>> nombre;

            system("cls");
            cout<< "-------------------------------------------------------------------------"<<endl;
            cout<< "       Bienvenido al juego "<< nombre << ", empecemos a jugar. "<<endl;
            cout<< "-------------------------------------------------------------------------"<<endl;

            system("pause");
            system("cls");

            for(int i=0; i<10; i++)
            {
            cout<<endl;
            system("cls");
            cout<< "TURNO DE "<< nombre << " | RONDA NUMERO " << i + 1 << " | PUNTAJE TOTAL: "<< puntajeTotal <<endl;
            cout<< "-------------------------------------------------------------------------"<<endl;
            cout<< " Lanzamiento N-1"<<endl;

                puntajeTotal += tirada();

                if( i == 1 && puntajeTotal == 100000 ){

                    break;
                }

                if( puntajeMaximo < puntajeTotal ){

                    puntajeMaximo = puntajeTotal;
                    nombrePuntajeMaximo = nombre;

                }
                cout<<endl;
                system("pause");

            }

            break;
        case 2:
            break;
        case 3:
            if( puntajeMaximo > 0 ){
            system("cls");
            cout<< "   ----------------------------------------------------------------------   "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                 el puntaje maximo es de "<< nombrePuntajeMaximo <<"                           |  "<<endl;
            cout<< "  |                     y su puntaje es de "<< puntajeMaximo <<"                            |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "   ----------------------------------------------------------------------   "<<endl;
            }else{
            system("cls");
            cout<< "   ----------------------------------------------------------------------   "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                No Hay puntaje maximo Actualmente,                    |  "<<endl;
            cout<< "  |       inicie una partida para recibir el puntaje maximo actual       |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "   ----------------------------------------------------------------------   "<<endl;

            };

            break;
        case 4:
            system("cls");
            cout<< "   ----------------------------------------------------------------------   "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                los creadores de este juego son:                      |  "<<endl;
            cout<< "  |                   - Martin Biera Olivera                             |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "  |                                                                      |  "<<endl;
            cout<< "   ----------------------------------------------------------------------   "<<endl;

            break;
        case 0:
            cout<< "saliendo del programa..."  ;
            break;
        default:
            cout << "Opcion no valida ";
            break;

        }
        system("pause");
    }
    while(opcion != 0);



    return 0;
}
