#include <iostream>
#include "rlutil.h"
#include "disenioDados.h"
using namespace std;

void dadosDisenio (int dados[]) {

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
