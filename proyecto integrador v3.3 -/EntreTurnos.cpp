#include <iostream>
#include <string>
#include "rlutil.h"

using namespace std;

void entreTurnos (int numeroRonda,string nombre,int puntaje){

    if ( numeroRonda < 10 && puntaje != 100000 ){
            rlutil::setColor(rlutil::LIGHTGREEN);

            system("cls");

            rlutil::locate(30,8);
            cout<< "------------------------------------------------------" <<endl;

            for (int i=9;i<=21;i++){
            rlutil::locate(29,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(49,13);
            cout<< "RONDA NUMERO "<<numeroRonda;

            rlutil::locate(47,15);
            cout<< "PUNTAJE "<<nombre<<" : "<<puntaje;

            for (int i=9;i<=21;i++){
            rlutil::locate(84,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(30,22);
            cout<< "------------------------------------------------------" <<endl;

            rlutil::locate(30,23);
            system("pause");

    }else {

        system("cls");

            rlutil::setColor(rlutil::LIGHTGREEN);

            rlutil::locate(30,8);
            cout<< "------------------------------------------------------" <<endl;

            for (int i=9;i<=21;i++){
            rlutil::locate(29,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(49,13);
            cout<< "JUEGO TERMINADO ";

            rlutil::locate(41,15);
            cout<< "EL PUNTAJE TOTAL DE "<<nombre<<" ES: "<<puntaje;

            for (int i=9;i<=21;i++){
            rlutil::locate(84,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(30,22);
            cout<< "------------------------------------------------------" <<endl;

            rlutil::locate(30,23);
            system("pause");

    }
}

void entreTurnosModoDosJugadores (int numeroRonda,int numeroDeRondasTotales,string nombre,string nombre2,int puntaje,int puntaje2,bool bandera){
    int puntajeGanador;
    string jugadorGanador;


    if ( numeroDeRondasTotales < 19 && puntaje != 100000 && bandera){
            rlutil::setColor(rlutil::LIGHTGREEN);

            system("cls");

            rlutil::locate(30,8);
            cout<< "------------------------------------------------------" <<endl;

            for (int i=9;i<=21;i++){
            rlutil::locate(29,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(49,13);
            cout<< "RONDA NUMERO "<<numeroRonda;

            rlutil::locate(47,15);
            cout<< "PROXIMA RONDA: "<<nombre2;

            rlutil::locate(47,17);
            cout<< "PUNTAJE DE "<<nombre<<" : "<<puntaje;

            rlutil::locate(47,18);
            cout<< "PUNTAJE DE "<<nombre2<<" : "<<puntaje2;

            for (int i=9;i<=21;i++){
            rlutil::locate(84,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(30,22);
            cout<< "------------------------------------------------------" <<endl;

            rlutil::locate(30,23);
            system("pause");

    } else if ( numeroDeRondasTotales < 19 && puntaje2 != 100000 && bandera==false){
            rlutil::setColor(rlutil::LIGHTGREEN);

            system("cls");

            rlutil::locate(30,8);
            cout<< "------------------------------------------------------" <<endl;

            for (int i=9;i<=21;i++){
            rlutil::locate(29,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(49,13);
            cout<< "RONDA NUMERO "<<numeroRonda;

            rlutil::locate(47,15);
            cout<< "PROXIMA RONDA: "<<nombre;

            rlutil::locate(47,17);
            cout<< "PUNTAJE DE "<<nombre<<" : "<<puntaje;

            rlutil::locate(47,18);
            cout<< "PUNTAJE DE "<<nombre2<<" : "<<puntaje2;

            for (int i=9;i<=21;i++){
            rlutil::locate(84,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(30,22);
            cout<< "------------------------------------------------------" <<endl;

            rlutil::locate(30,23);
            system("pause");

    } else if( numeroDeRondasTotales == 19 || puntaje == 100000 || puntaje2 == 100000 ){

        if (  puntaje < puntaje2  ){
            puntajeGanador = puntaje2;
            jugadorGanador = nombre2;
        }else{
            puntajeGanador = puntaje;
            jugadorGanador = nombre;
        }

        system("cls");

            rlutil::setColor(rlutil::LIGHTGREEN);

            rlutil::locate(30,8);
            cout<< "------------------------------------------------------" <<endl;

            for (int i=9;i<=21;i++){
            rlutil::locate(29,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(49,13);
            cout<< "JUEGO TERMINADO ";

            rlutil::locate(38,15);
            cout<< "EL GANADOR FUE "<< jugadorGanador <<" CON: "<< puntajeGanador << " PUNTOS ";

            rlutil::locate(46,16);
            cout<< "Y GANO EN "<<numeroRonda<< " RONDAS ";


            for (int i=9;i<=21;i++){
            rlutil::locate(84,i);
            cout<< "|"<<endl;
            }

            rlutil::locate(30,22);
            cout<< "------------------------------------------------------" <<endl;

            rlutil::locate(30,23);
            system("pause");

    }
}
