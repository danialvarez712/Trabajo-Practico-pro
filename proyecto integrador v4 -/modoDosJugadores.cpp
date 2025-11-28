#include <iostream>
#include <string>
#include <vector>
#include "rlutil.h"
#include "tiradas_dados.h"
#include "EntreTurnos.h"
#include "PuntajeMaximo.h"

using namespace std;

int ModoDosJugadores(string& nombreGanador){
     int puntajeTotal1=0,puntajeTotal2=0,puntajeMax=0;
     string nombrejugador1,nombrejugador2,nombrePuntajeMax;
     bool bandera=true,bandera2=false;

    system("cls");

            rlutil::locate(10,1);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            rlutil::locate(41,2);
            cout<< "ingrese el nombre del jugador 1:";
            rlutil::locate(10,3);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            rlutil::locate(73,2);
            cin>> nombrejugador1;

            system("cls");
            rlutil::locate(10,1);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            rlutil::locate(41,2);
            cout<< "ingrese el nombre del jugador 2:";
            rlutil::locate(10,3);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            rlutil::locate(73,2);
            cin>> nombrejugador2;



            system("cls");
            rlutil::locate(10,1);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            rlutil::locate(33,2);
            cout<< "Bienvenidos al juego "<< nombrejugador1 << " y "<< nombrejugador2 << ", empecemos a jugar. "<<endl;
            rlutil::locate(10,3);
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;

            rlutil::locate(10,4);
            system("pause");
            system("cls");

            int ronda=1;
            for(int i=0; i<20; i++){

            if(bandera){
            cout<<endl;
            system("cls");
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout<< "TURNO DE "<< nombrejugador1 << " | RONDA NUMERO " << ronda << " | PUNTAJE TOTAL: "<< puntajeTotal1 <<endl;
            cout<< "-------------------------------------------------------------------------"<<endl;
            cout<< " Lanzamiento N-1"<<endl;

                puntajeTotal1 += tirada();

                if ( puntajeMax < puntajeTotal1){
                    puntajeMax = puntajeTotal1;
                    nombreGanador = nombrejugador1;
                }

                if( i == 0 && puntajeTotal1 == 100000 ){

                cout<<endl;
                system("pause");
                entreTurnosModoDosJugadores(ronda,i,nombrejugador1,nombrejugador2,puntajeTotal1,puntajeTotal2,bandera);
                return puntajeMax;
                }

                cout<<endl;
                system("pause");
                entreTurnosModoDosJugadores(ronda,i,nombrejugador1,nombrejugador2,puntajeTotal1,puntajeTotal2,bandera);
                bandera = false;
            }

            else{
            cout<<endl;
            system("cls");
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout<< "TURNO DE "<< nombrejugador2 << " | RONDA NUMERO " << ronda << " | PUNTAJE TOTAL: "<< puntajeTotal2 <<endl;
            cout<< "-------------------------------------------------------------------------"<<endl;
            cout<< " Lanzamiento N-1"<<endl;

                puntajeTotal2 += tirada();

                if ( puntajeMax < puntajeTotal2){
                    puntajeMax = puntajeTotal2;
                    nombreGanador = nombrejugador2;
                }

                if( (i-1) == 0 && puntajeTotal2 == 100000 ){

                cout<<endl;
                system("pause");
                entreTurnosModoDosJugadores(ronda,i,nombrejugador1,nombrejugador2,puntajeTotal1,puntajeTotal2,bandera);

                return puntajeMax;
                }

                cout<<endl;
                system("pause");
                entreTurnosModoDosJugadores(ronda,i,nombrejugador1,nombrejugador2,puntajeTotal1,puntajeTotal2,bandera);

                bandera=true;
                ronda++;
            }

            }

            return puntajeMax;

}
