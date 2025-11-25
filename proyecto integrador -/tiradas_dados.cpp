#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "combinaciones.h"
#include "tiradas_dados.h"
#include "puntaje.h"

using namespace std;

void tirada2(vector<int>& dados,int cantidad,int tiradas){
    int b,numero,nuevosDados;
    vector <int> cambiar;

    for(int i = 0; i < cantidad;i++){
    cout << "CUALES DADOS QUIERE VOLVER A TIRAR?: ";
    cin>> b;
    cambiar.push_back(b-1);
    }

    cout<< endl;
    cout<< "-------------------------------------------------------------------------"<<endl;
    cout<< " Lanzamiento N-"<< tiradas <<endl;
    cout<< "-------------------------------------------------------------------------"<<endl;

    for(int i=0 ; i<5 ; i++){

        nuevosDados = cambiar[i];

        if (nuevosDados >= 0 && nuevosDados < 5) {
            dados[nuevosDados] = 1 + rand() % 6;
        }
    }
     for (int i = 0; i < 5; i++) {
        switch (dados[i]) {
            case 1: cout << "⚀ "; break;
            case 2: cout << "⚁ "; break;
            case 3: cout << "⚂ "; break;
            case 4: cout << "⚃ "; break;
            case 5: cout << "⚄ "; break;
            case 6: cout << "⚅ "; break;
        }
    }
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
        switch (numero) {
            case 1: cout << "⚀ ";
            break;
            case 2: cout << "⚁ ";
            break;
            case 3: cout << "⚂ ";
            break;
            case 4: cout << "⚃ ";
            break;
            case 5: cout << "⚄ ";
            break;
            case 6: cout << "⚅ ";
            break;
        }
    }

    generalaServida = combinacion_JuegoDeGeneralaServida(dado,tiradas);

    if(generalaServida<0){
        return generalaServida;
    }

    cout<<endl;

    while(bandera){

    if (tiradas <= 2){
    cout<< "CONTINUAR LANZANDO? (S/N): ";
    cin>> a;
    }
    else{
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
