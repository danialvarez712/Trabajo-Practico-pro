#include <iostream>
#include "rlutil.h"
#include "disenioDados.h"
using namespace std;

int tirarDado(int posx, int posy){
    int dado = rand()%6 + 1;

    for(int i=0; i<20; i++){
        dibujarDado(rand()%6+1, posx, posy, rand()%16, 15);
        rlutil::msleep(10);
    }
    dibujarDado(dado, posx, posy, 15, 0);

    return dado;
}

void dibujarDado(int numero, int posx, int posy, int color, int colorPoint){
    rlutil::setColor(color);
    dibujarCuadrado(posx, posy);

    rlutil::setColor(colorPoint);
    rlutil::setBackgroundColor(color);
    dibujarPuntos(numero, posx, posy);

    rlutil::setColor(rlutil::DARKGREY);
    rlutil::setBackgroundColor(rlutil::BLACK);
    dibujarSombra(posx, posy);
}

void dibujarPuntos(int numero, int posx, int posy){

    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

    switch(numero){
        case 1:
        rlutil::locate(posx+3, posy+1);
        cout<<char(254);
        break;

        case 2:
        rlutil::locate(posx+1, posy);
        cout<<char(220);
        rlutil::locate(posx+5, posy+2);
        cout<<char(223);
        break;

        case 3:
        rlutil::locate(posx+3, posy+1);
        cout<<char(254);
        rlutil::locate(posx+1, posy);
        cout<<char(220);
        rlutil::locate(posx+5, posy+2);
        cout<<char(223);
        break;

        case 4:
        rlutil::locate(posx+1, posy);
        cout<<char(220);
        rlutil::locate(posx+5, posy);
        cout<<char(220);
        rlutil::locate(posx+1, posy+2);
        cout<<char(223);
        rlutil::locate(posx+5, posy+2);
        cout<<char(223);
        break;

        case 5:
        rlutil::locate(posx+1, posy);
        cout<<char(220);
        rlutil::locate(posx+5, posy);
        cout<<char(220);
        rlutil::locate(posx+1, posy+2);
        cout<<char(223);
        rlutil::locate(posx+5, posy+2);
        cout<<char(223);
        rlutil::locate(posx+3, posy+1);
        cout<<char(254);
        break;

    }
}

void dibujarSombra(int posx, int posy){

    ///rlutil::setColor(rlutil::GREY);
    ///rlutil::setBackgroundColor(rlutil::BLACK);

    for(int y=posy; y<=posy+2; y++){
        rlutil::locate(posx+7,y);
        if(y==posy){
            cout<<char(220);
        }
        else{
           cout<<char(219);
        }
    }
    for(int x=posx+1; x<=posx+7; x++){
        rlutil::locate(x, posy+3);
        cout<<char(223);
    }
}

void dibujarCuadrado(int posx, int posy){
    ///rlutil::setColor(rlutil::WHITE);
    for(int x=posx;x<=posx+6;x++){
        for(int y=posy;y<=posy+2;y++){
            rlutil::locate(x,y);
            cout<<char(219);
        }
    }
}

void lanzamiento(int dados[]){

    for(int i=0;i<=5;i++){
        dados[i] = tirarDado(i*10,rand()%10 + 5); ///Tira los dados y Guarda el valor de los dados en un vector

    }
}

void dadosDisenio (vector<int>& dados) {

    string fila1[5], fila2[5], fila3[5], fila4[5], fila5[5];

for(int i = 0; i < 5; i++){
    int d = dados[i];

    if(d == 1){
        fila1[i] = " ------- ";
        fila2[i] = "|       |";
        fila3[i] = "|   o   |";
        fila4[i] = "|       |";
        fila5[i] = " ------- ";
    }
    else if(d == 2){
        fila1[i] = " ------- ";
        fila2[i] = "| o     |";
        fila3[i] = "|       |";
        fila4[i] = "|     o |";
        fila5[i] = " ------- ";
    }
    else if(d == 3){
        fila1[i] = " ------- ";
        fila2[i] = "| o     |";
        fila3[i] = "|   o   |";
        fila4[i] = "|     o |";
        fila5[i] = " ------- ";
    }
    else if(d == 4){
        fila1[i] = " ------- ";
        fila2[i] = "| o   o |";
        fila3[i] = "|       |";
        fila4[i] = "| o   o |";
        fila5[i] = " ------- ";
    }
    else if(d == 5){
        fila1[i] = " ------- ";
        fila2[i] = "| o   o |";
        fila3[i] = "|   o   |";
        fila4[i] = "| o   o |";
        fila5[i] = " ------- ";
    }
    else if(d == 6){
        fila1[i] = " ------- ";
        fila2[i] = "| o   o |";
        fila3[i] = "| o   o |";
        fila4[i] = "| o   o |";
        fila5[i] = " ------- ";
    }
}


for(int i = 0; i < 5; i++){
    cout << fila1[i];
}
cout << endl;

for(int i = 0; i < 5; i++){
    cout << fila2[i];
}
cout << endl;

for(int i = 0; i < 5; i++) {
    cout << fila3[i];
}
cout << endl;

for(int i = 0; i < 5; i++){
    cout << fila4[i];
}
cout << endl;

for(int i = 0; i < 5; i++){
    cout << fila5[i];
}
cout << endl;

}
