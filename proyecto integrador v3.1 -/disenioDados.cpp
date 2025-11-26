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

    for(int i=1;i<=6;i++){
        dados[i] = tirarDado(i*10,rand()%10 + 5); ///Tira los dados y Guarda el valor de los dados en un vector

    }
}
