#include <iostream>
#include "juego.h"
#include <string>
#include "rlutil.h"
using namespace std;



void menu(){

    int opcion;
    string jugador1="";
    int puntuacionMasAlta=0;


    while(true){
        system("cls");
        rlutil::locate(45,10);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "     MENU PRINCIPAL             "<<endl;
        rlutil::locate(45,11);
        cout << "        GENERALA                "<<endl;
        rlutil::locate(37,12);
        cout <<"---------------------------------------    "<<endl;
        rlutil::locate(48,13);
        cout<<"1 - 1 JUGADOR                               "<<endl;
        rlutil::locate(48,14);
        cout <<"2 - JUEGO FORZADO                        "<<endl;
        rlutil::locate(48,15);
        cout <<"3 - PUNTUACION MAS ALTA                "<<endl;
        rlutil::locate(37,16);
        cout <<"---------------------------------------    "<<endl;
        rlutil::locate(48,17);
        cout <<"0 - SALIR DEL JUEGO              "<<endl;
        rlutil::locate(48,20);
        cout <<"Ingrese Opci¢n:                  "<<endl;



        rlutil::locate(63,20);
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1:
                rlutil::locate(35,12);
                cout<<"Ingrese Nombre del Jugador 1: ";
                cin.ignore();
                getline(cin, jugador1);
                system("cls");
                juego(jugador1, puntuacionMasAlta);
                break;
            case 2:
                rlutil::locate(35,12);
                cout<<"Ingrese Nombre del Jugador 1: ";
                cin.ignore();
                getline(cin, jugador1);
                system("cls");
                juegoforzado(jugador1, puntuacionMasAlta);
                break;
            case 3:
                if (puntuacionMasAlta==0){
                        cout <<"NO HAY PUNTUACION"<<endl;
                        system("pause");
                    }
                    else {
                    cout << "EL JUGADOR CON MAYOR PUNTUACION: " << jugador1 << endl;
                    cout << "LA PUNTUACION ES: " <<puntuacionMasAlta<<" PUNTOS"<<endl;
                    system("pause");
                    }
                break;
            case 0:
                system("cls");
                rlutil::locate(25,12);
                cout<<"======================================================================"<<endl;
                rlutil::locate(25,14);
                cout<<"                             FIN DEL JUEGO "                           <<endl;
                rlutil::locate(25,16);
                cout<<"======================================================================"<<endl;
                return;
                break;
        }
    }

}


