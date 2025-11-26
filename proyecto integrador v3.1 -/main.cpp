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

using namespace std;

int main(){

    SetConsoleOutputCP(CP_UTF8);

    int opcion,a,dado,puntajeTotal = 0;
    vector <int> numeros;
    string nombre;

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

        switch (opcion)
        {


        case 1:

            system("cls");
            rlutil::locate(10,1);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            rlutil::locate(45,2);
            cout<< "ingrese su nombre:";
            rlutil::locate(10,3);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            rlutil::locate(63,2);
            cin>> nombre;



            system("cls");
            rlutil::locate(10,1);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            rlutil::locate(38,2);
            cout<< "Bienvenido al juego "<< nombre << ", empecemos a jugar. "<<endl;
            rlutil::locate(10,3);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;

            rlutil::locate(10,4);
            system("pause");
            system("cls");

            for(int i=0; i<10; i++){
            rlutil::setColor(rlutil::GREY);

            cout<<endl;
            system("cls");
            cout<< "TURNO DE "<< nombre << " | RONDA NUMERO " << i + 1 << " | PUNTAJE TOTAL: "<< puntajeTotal <<endl;
            cout<< "-------------------------------------------------------------------------"<<endl;
            cout<< " Lanzamiento N-1"<<endl;

                puntajeTotal += tirada();

                if( i == 1 && puntajeTotal == 100000 ){

                    break;
                }

                cout<<endl;
                system("pause");
                entreTurnos(i+1,nombre,puntajeTotal);
            }
            break;

        case 2:




            break;


        case 3:

            PuntajeMaximo(puntajeTotal,nombre);

            break;


        case 4:

            Creditos();

            break;


        case 0:
            cout<< "saliendo del programa..."  ;
            break;
        default:
            cout << "Opcion no valida ";
            break;

        }
    }
    while(opcion != 0);



    return 0;
}
