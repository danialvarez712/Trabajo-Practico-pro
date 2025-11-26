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
