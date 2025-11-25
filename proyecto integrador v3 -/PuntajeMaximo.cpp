#include <iostream>
#include <string>
#include "rlutil.h"
#include "PuntajeMaximo.h"


using namespace std;

void PuntajeMaximo(int puntajeTotal,string nombre){
    int puntajeMasAlto;
    string nombrePuntajeMaximo;



    if( puntajeMasAlto < puntajeTotal ){

        puntajeMasAlto = puntajeTotal;
        nombrePuntajeMaximo = nombre;
        }


if( puntajeMasAlto > 0 ){
            system("cls");
            rlutil::setColor(rlutil::LIGHTGREEN);

            rlutil::locate(30,8);
            cout<< "------------------------------------------------------" <<endl;

            for (int i=9;i<=21;i++){
            rlutil::locate(29,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(43,14);
            cout<< "el puntaje maximo es de "<< nombrePuntajeMaximo ;

            rlutil::locate(46,15);
            cout<< "y su puntaje es de "<< puntajeMasAlto;

            for (int i=9;i<=21;i++){
            rlutil::locate(84,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(30,22);
            cout<< "------------------------------------------------------" <<endl;

            rlutil::locate(30,23);
            system("pause");

            }


            else{
            system("cls");
            rlutil::setColor(rlutil::LIGHTRED);

            rlutil::locate(30,8);
            cout<< "------------------------------------------------------" <<endl;

            for (int i=9;i<=21;i++){
            rlutil::locate(29,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(40,14);
            cout<< "No Hay puntaje maximo Actualmente," ;

            rlutil::locate(40,15);
            cout<< "inicie una partida para recibirlo" ;

            for (int i=9;i<=21;i++){
            rlutil::locate(84,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(30,22);
            cout<< "------------------------------------------------------" <<endl;

            rlutil::locate(30,23);
            system("pause");

            };

}
