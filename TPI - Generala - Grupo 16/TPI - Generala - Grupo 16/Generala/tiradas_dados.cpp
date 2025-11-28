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

void tirada2(int dados[] ,int cantidad,int tiradas){
    rlutil::setColor(rlutil::LIGHTGREEN);
    bool bandera=false;
    int b,numero,numeroDePosicion,contador=0;
    int cambiar[5];

    for(int i = 0; i < cantidad;i++){
    cout << "CUAL DADO QUIERE VOLVER A TIRAR? (1-5): ";
    cin>> b;

    while ( b > 5 || b < 1 ){

    rlutil::setColor(rlutil::LIGHTRED);
    cout<< "SELECCIONE UN CARACTER CORRECTO! "<<endl;

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "CUAL DADO QUIERE VOLVER A TIRAR? (1-5): ";
    cin>> b;
    }

    //Esta linea de codigo es para que no se repita el dado que quiere volver a tirar.
    for( int a=0;a<contador;a++ ){
     if (cambiar[a] == b-1 ){
            bandera = true;
        }
    }
            while(bandera){

            rlutil::setColor(rlutil::LIGHTRED);
            cout<< "NO REPITAS EL MISMO DADO! "<<endl;

            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "CUAL DADO QUIERE VOLVER A TIRAR? (1-5): ";
            cin>> b;

            bandera = false;
            for( int a=0;a<contador;a++ ){
            if (cambiar[a] == b-1 ){
            bandera = true;
        }
    }
}



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

void tirada2F(int dados[] ,int cantidad,int tiradas){
    rlutil::setColor(rlutil::LIGHTGREEN);
    bool bandera=false;
    int b,numero,numeroDePosicion,contador=0;
    int cambiar[5];

    for(int i = 0; i < cantidad;i++){
    cout << "CUAL DADO QUIERE VOLVER A TIRAR? (1-5): ";
    cin>> b;

    while ( b > 5 || b < 1 ){

    rlutil::setColor(rlutil::LIGHTRED);
    cout<< "SELECCIONE UN CARACTER CORRECTO! "<<endl;

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "CUAL DADO QUIERE VOLVER A TIRAR? (1-5): ";
    cin>> b;
    }

    //Esta linea de codigo es para que no se repita el dado que quiere volver a tirar.
    for( int a=0;a<contador;a++ ){
     if (cambiar[a] == b-1 ){
            bandera = true;
        }
    }
            while(bandera){

            rlutil::setColor(rlutil::LIGHTRED);
            cout<< "NO REPITAS EL MISMO DADO! "<<endl;

            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "CUAL DADO QUIERE VOLVER A TIRAR? (1-5): ";
            cin>> b;

            bandera = false;
            for( int a=0;a<contador;a++ ){
            if (cambiar[a] == b-1 ){
            bandera = true;
        }
    }
}



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



            cout<<"Ingrese nuevos valores para los dados a cambiar:";
            cin>>dados[numeroDePosicion];


        }
    }

    rlutil::setColor(rlutil::GREY);
    dadosDisenio(dados);
    cout << endl;
}


int tirada(){
    int puntos, jugada, numero,cantidad=1,tiradas=1,resultado=0,puntajeTotal,generalaServida=0;
    bool bandera = true,usadas[12] = {false};;
    char a,b;
    int dado[5];
    for (int i = 0; i < 5; i++) {
        numero = 1 + rand() % 6;
        dado[i] = numero;
    }
    rlutil::setColor(rlutil::GREY);
    dadosDisenio(dado);

    generalaServida = combinacion_JuegoDeGeneralaServida(dado,tiradas);

    if(generalaServida>0){
        return generalaServida;
    }

    cout<<endl;

    while(bandera){

    if (tiradas <= 2){
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout<< "CONTINUAR LANZANDO? (S/N): ";
    cin>> a;
    while( a != 'S' && a != 's' && a != 'N' && a != 'n'  ){
    rlutil::setColor(rlutil::LIGHTRED);
    cout<< "SELECCIONE UN CARACTER CORRECTO! "<<endl;

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout<< "CONTINUAR LANZANDO? (S/N): ";
    cin>> a;

    }
    }
    else{
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout<< "YA NO SE PUEDE VOLVER A TIRAR..";

        puntajeTotal = puntaje(dado);

        bandera=false;
    }

    if (( a == 'S' || a == 's') && tiradas <= 2 ){

    cout << "CUANTOS DADOS QUIERE TIRAR?: ";
    cin>> cantidad;

    while ( cantidad < 1 || cantidad > 5 ){

    rlutil::setColor(rlutil::LIGHTRED);
    cout<< "SELECCIONE UNA CANTIDAD CORRECTA!"<<endl;

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "CUANTOS DADOS QUIERE TIRAR?: ";
    cin>> cantidad;

    }

    tiradas++;
    tirada2(dado,cantidad,tiradas);

    }

    else if( a == 'N' || a == 'n' || tiradas < 2 ){

    puntajeTotal = puntaje(dado);

    bandera=false;

    }


    cout << endl;
}

return puntajeTotal;

}

int tiradaF(){
    int numero,cantidad=1,tiradas=1,resultado=0,puntajeTotal,generalaServida=0;
    bool bandera = true;
    char a,b;
    int dado[5];
    for (int i = 0; i < 5; i++) {
        cout<<"INGRESE EL DADO " << i+1 << " ( 1-5 ):";
        cin>>numero;

        dado[i] = numero;
    }
    rlutil::setColor(rlutil::GREY);
    dadosDisenio(dado);

    generalaServida = combinacion_JuegoDeGeneralaServida(dado,tiradas);

    if(generalaServida>0){
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< "----- HICISTE GENERALA SERVIDA---- ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        return generalaServida;
    }

    cout<<endl;

    while(bandera){

    if (tiradas <= 2){
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout<< "CONTINUAR LANZANDO? (S/N): ";
    cin>> a;
    while( a != 'S' && a != 's' && a != 'N' && a != 'n'  ){
    rlutil::setColor(rlutil::LIGHTRED);
    cout<< "SELECCIONE UN CARACTER CORRECTO! "<<endl;

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout<< "CONTINUAR LANZANDO? (S/N): ";
    cin>> a;

    }
    }
    else{
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout<< "YA NO SE PUEDE VOLVER A TIRAR.."<<endl;

        puntajeTotal = puntaje(dado);

        bandera=false;
    }

    if (( a == 'S' || a == 's') && tiradas <= 2 ){

    cout << "CUANTOS DADOS QUIERE TIRAR?: ";
    cin>> cantidad;

    while ( cantidad < 1 || cantidad > 5 ){

    rlutil::setColor(rlutil::LIGHTRED);
    cout<< "SELECCIONE UNA CANTIDAD CORRECTA!"<<endl;

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "CUANTOS DADOS QUIERE TIRAR?: ";
    cin>> cantidad;

    }

    tiradas++;
    tirada2F(dado,cantidad,tiradas);

    }

    else if( a == 'N' || a == 'n' || tiradas < 2 ){

    puntajeTotal = puntaje(dado);

    bandera=false;

    }


    cout << endl;
}

return puntajeTotal;

}
