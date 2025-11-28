#include <iostream>
#include <string>
#include <vector>
#include "rlutil.h"
#include "tiradas_dados.h"
#include "EntreTurnos.h"
#include "PuntajeMaximo.h"

int modoUnJugador ( string& nombre ){
    int op;
    int puntajeTotal = 0;
    system ("cls");
    rlutil::locate(30,10);
    cout<< "Que modalidad desea jugar:";
    rlutil::locate(30,11);
    cout<< "----------------------------";
    rlutil::locate(30,12);
    cout<< "1. Modo normal.";
    rlutil::locate(30,13);
    cout<< "2. Modo Forzado.";
    rlutil::locate(30,14);
    cout<< "----------------------------";
    rlutil::locate(30,15);
    cout<< "Selecione una opcion";
    rlutil::locate(51,15);
    cin>>op;

 if (op == 1){

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

            cout<<endl;
            system("cls");
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout<< "TURNO DE "<< nombre << " | RONDA NUMERO " << i + 1 << " | PUNTAJE TOTAL: "<< puntajeTotal <<endl;
            cout<< "-------------------------------------------------------------------------"<<endl;
            cout<< " Lanzamiento N-1"<<endl;

            puntajeTotal += tirada();

                if( i == 1 && puntajeTotal == 100000 ){

                cout<<endl;
                system("pause");
                entreTurnos(i+1,nombre,puntajeTotal);
                break;
                }

                cout<<endl;
                system("pause");
                entreTurnos(i+1,nombre,puntajeTotal);

            }

            return puntajeTotal;

 }else{
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

            cout<<endl;
            system("cls");
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout<< "TURNO DE "<< nombre << " | RONDA NUMERO " << i + 1 << " | PUNTAJE TOTAL: "<< puntajeTotal <<endl;
            cout<< "-------------------------------------------------------------------------"<<endl;
            cout<< " Lanzamiento N-1"<<endl;

            puntajeTotal += tiradaF();

                if( i == 1 && puntajeTotal == 100000 ){

                cout<<endl;
                system("pause");
                entreTurnos(i+1,nombre,puntajeTotal);
                break;
                }

                cout<<endl;
                system("pause");
                entreTurnos(i+1,nombre,puntajeTotal);

            }

            return puntajeTotal;



           }
}


/*
        int puntajeTotal = 0;

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

            cout<<endl;
            system("cls");
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout<< "TURNO DE "<< nombre << " | RONDA NUMERO " << i + 1 << " | PUNTAJE TOTAL: "<< puntajeTotal <<endl;
            cout<< "-------------------------------------------------------------------------"<<endl;
            cout<< " Lanzamiento N-1"<<endl;

            puntajeTotal += tirada();

                if( i == 1 && puntajeTotal == 100000 ){

                cout<<endl;
                system("pause");
                entreTurnos(i+1,nombre,puntajeTotal);
                break;
                }

                cout<<endl;
                system("pause");
                entreTurnos(i+1,nombre,puntajeTotal);

            }

            return puntajeTotal;
}
*/
