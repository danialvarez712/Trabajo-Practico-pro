#include <iostream>
#include <string>
#include <vector>
#include "rlutil.h"

using namespace std;

void Creditos (){

    system("cls");
        rlutil::setColor(rlutil::LIGHTGREEN);

        rlutil::locate(30,8);
        cout<< "------------------------------------------------------" <<endl;

        for (int i=9;i<=21;i++){
        rlutil::locate(29,i);
        cout<< "|"<<endl;
        }

        rlutil::locate(38,12);
        cout<< "ESTE JUEGO FUE CREADO POR EL GRUPO 16" ;

        rlutil::locate(43,13);
        cout<< "ESTOS SON SUS INTEGRANTES:";

        rlutil::locate(35,15);
        cout<< "- Martin Alejandro Biera Olivera ( 29711 )";

        rlutil::locate(35,16);
        cout<< "- Geronimo Nahuel Flores ";

        for (int i=9;i<=21;i++){
        rlutil::locate(84,i);
        cout<< "|"<<endl;
        }

        rlutil::locate(30,22);
        cout<< "------------------------------------------------------" <<endl;

        rlutil::locate(30,23);
        system("pause");

    }
