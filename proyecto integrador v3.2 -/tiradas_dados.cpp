#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "rlutil.h"
#include "combinaciones.h"
#include "tiradas_dados.h"
#include "puntaje.h"
#include "disenioDados.h"

using namespace std;

void tirada2(vector<int>& dados,int cantidad,int tiradas){
    rlutil::setColor(rlutil::LIGHTGREEN);
    int b,numero,numeroDePosicion,contador=0;
    int cambiar[5];

    for(int i = 0; i < cantidad;i++){
    cout << "CUAL DADO QUIERE VOLVER A TIRAR?: ";
    cin>> b;


    cambiar[contador]= b-1;
    contador++;
    }

    cout<< endl;
    cout<< "-------------------------------------------------------------------------"<<endl;
    cout<< " Lanzamiento N-"<< tiradas <<endl;
    cout<< "-------------------------------------------------------------------------"<<endl;

    for(int i=0 ; i<contador ; i++){

        numeroDePosicion = cambiar[i];

        if (numeroDePosicion >= 0 && numeroDePosicion < 5) {
            dados[numeroDePosicion] = 1 + rand() % 6;
        }
    }

    rlutil::setColor(rlutil::GREY);
    dadosDisenio(dados);
    cout << endl;
}



int tirada(){
    int numero,cantidad2=1,tiradas=1,resultado=0,puntajeTotal,generalaServida=0;
    bool bandera = true;
    char a,b;
    vector <int> dado;
  for (int i = 0; i < 5; i++) {
        numero = 1 + rand() % 6;
        dado.push_back(numero);
    }
    rlutil::setColor(rlutil::GREY);
    dadosDisenio(dado);

    generalaServida = combinacion_JuegoDeGeneralaServida(dado,tiradas);

    if(generalaServida<0){
        return generalaServida;
    }

    cout<<endl;

    while(bandera){

    if (tiradas <= 2){
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout<< "CONTINUAR LANZANDO? (S/N): ";
    cin>> a;
    if( a != 'S' && a != 's' && a != 'N' && a != 'n'  ){

    cout<< "SELECCIONE UN CARACTER CORRECTO! "<<endl;
    cout<< "CONTINUAR LANZANDO? (S/N): ";
    cin>> a;

    }
    }
    else{
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout<< "YA NO SE PUEDE VOLVER A TIRAR.";

        puntajeTotal = puntaje(dado);

        bandera=false;
    }

    if (( a == 'S' || a == 's') && tiradas <= 2 ){

    cout << "CUANTOS DADOS QUIERE TIRAR?: ";
    cin>> cantidad2;
    tiradas++;

    tirada2(dado,cantidad2,tiradas);

    }

    else if( a == 'N' || a == 'n' || tiradas >= 2 ){

    puntajeTotal = puntaje(dado);

    bandera=false;

    }


    cout << endl;
}

return puntajeTotal;

}
