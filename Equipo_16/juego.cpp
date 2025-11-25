#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "rlutil.h"
#include "juego.h"
#include "funciones.h"

using namespace std;



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


int tirarDado(int posx, int posy){
    int dado = rand()%6 + 1;

    for(int i=0; i<20; i++){
        dibujarDado(rand()%6+1, posx, posy, rand()%16, 15);
        rlutil::msleep(10);
    }
    dibujarDado(dado, posx, posy, 15, 0);

    return dado;
}

void lanzamiento(int dados[]){

    for(int i=1;i<=6;i++){
        dados[i] = tirarDado(i*10,rand()%10 + 5); ///Tira los dados y Guarda el valor de los dados en un vector

    }
}

void lanzamientoForzado(int dados[],int posx, int posy){

    cout<<"Dado 1: "<<endl;
    cin>>dados[1];
    cout<<"Dado 2: "<<endl;
    cin>>dados[2];
    cout<<"Dado 3: "<<endl;
    cin>>dados[3];
    cout<<"Dado 4: "<<endl;
    cin>>dados[4];
    cout<<"Dado 5: "<<endl;
    cin>>dados[5];
    cout<<"Dado 6: "<<endl;
    cin>>dados[6];
    for(int i=1;i<=6;i++){
        dibujarDado(dados[i],posx*i*10,posy+5, 15, 0);
    }

}
void mostrarValorDados(int dados[]){
//    int suma=0;
    for(int i=0;i<=5;i++){  ///Muestra el valor de los dados guardados en el vector
        cout<<dados[i+1]<<"\t";
//        suma+=dados[i+1]; ///Suma el valor de los dados
//        cout<<suma<<"\t";
    }
}

void juego(const string& jugador1, int& puntuacion){

        int puntajeTotal=0;
        int ronda=1;

    while(puntajeTotal<=100){

        int dados[7]{};
        int sexteto=0;
        bool escalera=true;
        int nroRep;
        int maxPuntajeRonda=0;
        int puntajeLanzamiento=0;

        for(int i=1;i<=3;i++){
            lanzamiento(dados);
    //        cout<<endl<<endl<<endl<<endl<<endl<<endl;
    //        mostrarValorDados(dados);
            cout<<endl<<endl;

            for(int i=1;i<=6;i++){ ///CUENTA LA CANTIDAD DE REPETICIONES DE CADA NRO

    //            cout<<i<<"("<<contarNumerosRepetidos(dados,i,7)<<")"<<endl;

                if((contarNumerosRepetidos(dados,i,7))!=1){ ///  ///EVALUA QUE HAYA UNO DE CADA NRO, y que haya una unidad distinta dentro del vector de dados con los 6 valores, utiliza la funcion contarNumerosRepetidos y dice != 1 para evaluar de que los dados que vayan pasando sea un numero distinto cada uno
                    escalera=false;
                }
   //             else { /// aca los 6 valores son iguales entre si, con lo que no es escalera
   //                 escalera = true;

                 if((contarNumerosRepetidos(dados,i,7))==6){ ///SI HAY 6 NUMEROS IGUALES ES SEXTETO DE X NUMERO
                    nroRep=i;       /// almacena en la variable nroRep el numero repetido del sexteto
                    sexteto=i*10;   ///SI HAY SEXTETO DE X NUMERO MULTIPLICA X*10 EL NRO REPETIDO
                    rlutil::locate(1,23);
                    cout<<"SEXTETO DE "<<nroRep<<endl;
                }
            }

            if(escalera){  ///SI HAY UNO DE CADA NRO DEVUELVE "ESCALERA", SI DA ESCALERA QUIERE DECIR QUE HAY NUMEROS ENTRE EL 1 AL 6 O DEL 6 AL 1 POR LO TANTO MOSTRARA ESCALERA GANANDO LA PARTIDA
            rlutil::locate(1,23);
            cout<<"ESCALERA"<<endl;
            puntajeTotal=200;
            rlutil::locate(1,24);
            cout<<"FIN DE LA PARTIDA"<<endl;
            rlutil::locate(1,25);
            cout<<"ESCALERA "<< " PUNTAJE: " << puntajeTotal<<endl;
            rlutil::locate(1,28);
            system("pause");
            system("cls");
            break;
            }
// cout<<
            if(sexteto==0){                                             /// SI EL SEXTETO ES IGUAL A 0 QUIERE DECIR QUE NO HAY SEXTETO POR LO QUE SUMA LOS PUNTOS PARA ACUMULAR EL PUNTAJE
    //            cout<<"TOTAL LANZAMIENTO: "<<sumarVector(dados,7)<<"\t"<<endl; ///SUMA EL TOTAL DE LOS DADOS DEL LANZAMIENTO
                puntajeLanzamiento=sumarVector(dados,7);
            }
            else if(sexteto>puntajeLanzamiento){                        /// SI HAY SEXTETO Y EL PUNTAJE DE SEXTETO ES MAYOR AL PUNTAJE PREVIO ACUMULADO EL SEXTETO DE 6 NUMEROS SE REINICIA A 0.
//                cout<<"TOTAL LANZAMIENTO: "<<sexteto<<"\t"<<endl;
                puntajeLanzamiento=sexteto;
                sexteto=0;
            }
            if(maxPuntajeRonda==0){
                maxPuntajeRonda=puntajeLanzamiento;
            }
            else if(puntajeLanzamiento>maxPuntajeRonda){
                maxPuntajeRonda=puntajeLanzamiento;             /// POR CADA LANZAMIENTO, BUSCA EL MAXIMO PUNTAJE POR RONDA Y EL JUGADOR CON LA MAYOR PUNTUACION.
            }

            if(maxPuntajeRonda==60){
            puntajeLanzamiento=0;
            puntajeTotal=0;
            maxPuntajeRonda=0;      /// SI EL MAXIMO PUNTAJE DE RONDA DA 60 QUIERE DECIR QUE HUBO SEXTETO DE 6, POR LO QUE EL PUNTAJE TOTAL SE REINICIA A 0
            }
            cout<<endl<<endl<<endl<<endl<<endl<<endl;
            rlutil::locate(1,25);
            cout<<"TURNO DE "<<jugador1<<" | RONDA N§ "<<ronda<<" | PUNTAJE LANZAMIENTO: "<<puntajeLanzamiento<<" PUNTOS"<<" | PUNTAJE TOTAL: "<<puntajeTotal<<" PUNTOS"<<endl;
            cout<<"------------------------------------------------------------------------------------------"<<endl;
            cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<maxPuntajeRonda<<" PUNTOS"<<endl;
            cout<<"LANZAMIENTO "<<i<<endl;
            system("pause");
            system("cls");


            if(i==3){
                puntajeTotal+=maxPuntajeRonda; /// ACUMULA EL PUNTAJE TOTAL CON EL MAXIMO PUNTAJE QUE HAYA DE TODAS LAS RONDAS

            }


            rlutil::setColor(rlutil::LIGHTGREEN);
            rlutil::locate(41,10);
            cout <<  "-----------------------------------" <<endl;
            rlutil::locate(54,12);
            cout << "RONDA N: " << ronda << endl;
            rlutil::locate(45,14);
            cout << "PROXIMO TURNO: " << jugador1 << endl;
            rlutil::locate(45,16);
            cout << "PUNTAJE " << jugador1 << ": " << puntajeTotal << endl;
            rlutil::locate(41,18);
            cout << "------------------------------------" << endl;
            rlutil::locate(1,29);
            system("pause");
            system("cls");


        }


        ronda++; /// CUENTA EL NUMERO DE RONDAS

        if(puntajeTotal>=200){      /// SI EL PUNTAJE TOTAL ES MAYOR O IGUAL A 200 QUIERE DECIR QUE EL JUGADOR GANA CON ESCALERA
            rlutil::locate(50,12);
            cout<<"FELICITACIONES!!!"<<endl;
            rlutil::locate(50,14);
            cout<<jugador1<<endl;
            rlutil::locate(50,16);
            cout<<"FIN DE LA PARTIDA"<<endl;
            rlutil::locate(50,18);
            cout<<"ESCALERA "<<puntajeTotal<<endl;
            rlutil::locate(1,30);
            system("pause");
        }
        else if(puntajeTotal>=100){ /// SI EL PUNTAJE ES MAYOR O IGUAL A 100 GANO LLEGANDO AL PUNTAJE REQUERIDO, 100 PUNTOS
            rlutil::locate(50,12);
            cout<<"FELICITACIONES!!!"<<endl;
            rlutil::locate(50,14);
            cout<<jugador1<<endl;
            rlutil::locate(50,16);
            cout<<"FIN DE LA PARTIDA"<<endl;
            rlutil::locate(50,18);
            cout<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
            rlutil::locate(50,20);
            cout<<"CANTIDAD DE RONDAS QUE LLEVO GANAR: "<<ronda<<endl;
            rlutil::locate(1,30);
            system("pause");
        }
        if(puntajeTotal>puntuacion){    /// ASIGNA LA PUNTUACION MAS ALTA, QUE ESTA EN EL MENU APRETANDO LA TECLA 5
            puntuacion=puntajeTotal;
        }
    }
}

void juegoforzado(const string& jugador1, int& puntuacion){

        int puntajeTotal=0;
        int ronda=1;

    while(puntajeTotal<=100){

        int dados[7]{};
        int sexteto=0;
        bool escalera=true;
        int nroRep;
        int maxPuntajeRonda=0;
        int puntajeLanzamiento=0;

        for(int i=1;i<=3;i++){
            lanzamientoForzado(dados,1,10);
//            cout<<endl<<endl<<endl<<endl<<endl<<endl;
//            mostrarValorDados(dados);
            cout<<endl<<endl;

            for(int i=1;i<=6;i++){ ///CUENTA LA CANTIDAD DE REPETICIONES DE CADA NRO

//                cout<<i<<"("<<contarNumerosRepetidos(dados,i,7)<<")"<<endl;

                if((contarNumerosRepetidos(dados,i,7))!=1){ ///EVALUA QUE HAYA UNO DE CADA NRO
                    escalera=false;
                }

                if((contarNumerosRepetidos(dados,i,7))==6){ ///SI HAY 6 NUMEROS IGUALES ES SEXTETO
                    nroRep=i;       /// almacena en la variable nroRep el numero repetido del sexteto
                    sexteto=i*10;   ///SI HAY SEXTETO MULTIPLICA *10 EL NRO REPETIDO
                    rlutil::locate(1,23);
                    cout<<"SEXTETO DE "<<nroRep<<endl;
                }
            }

            if(escalera){  ///SI HAY UNO DE CADA NRO DEVUELVE "ESCALERA"
            rlutil::locate(1,23);
            cout<<"ESCALERA"<<endl;
            puntajeTotal=200;
            rlutil::locate(1,24);
            cout<<"FIN DE LA PARTIDA"<<endl;
            rlutil::locate(1,25);
            cout<<"ESCALERA "<< " PUNTAJE: " << puntajeTotal<<endl;
            rlutil::locate(1,28);
            system("pause");
            system("cls");
            break;
            }

            if(sexteto==0){
    //            cout<<"TOTAL LANZAMIENTO: "<<sumarVector(dados,7)<<"\t"<<endl; ///SUMA EL TOTAL DE LOS DADOS DEL LANZAMIENTO
                puntajeLanzamiento=sumarVector(dados,6);
            }
            else if (sexteto>puntajeLanzamiento){
//                cout<<"TOTAL LANZAMIENTO: "<<sexteto<<"\t"<<endl;
                puntajeLanzamiento=sexteto;
                sexteto=0;
            }
            if(maxPuntajeRonda==0){
                maxPuntajeRonda=puntajeLanzamiento;
            }
            else if(puntajeLanzamiento>maxPuntajeRonda){
                maxPuntajeRonda=puntajeLanzamiento;
            }

            if(maxPuntajeRonda==60){
            puntajeLanzamiento=0;
            puntajeTotal=0;
            maxPuntajeRonda=0;
            }

            cout<<endl<<endl<<endl<<endl<<endl<<endl;
            rlutil::locate(1,25);
            cout<<"TURNO DE "<<jugador1<<" | RONDA N§ "<<ronda<<" | PUNTAJE LANZAMIENTO: "<<puntajeLanzamiento<<" PUNTOS"<<" | PUNTAJE TOTAL: "<<puntajeTotal<<" PUNTOS"<<endl;
            cout<<"------------------------------------------------------------------------------------------"<<endl;
            cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<maxPuntajeRonda<<" PUNTOS"<<endl;
            cout<<"LANZAMIENTO "<<i<<endl;
            system("pause");
            system("cls");

        if(i==3){
            puntajeTotal+=maxPuntajeRonda;
        }

            rlutil::setColor(rlutil::LIGHTGREEN);
            rlutil::locate(41,10);
            std::cout << "------------------------------------" <<endl;
            rlutil::locate(54,12);
            cout << "RONDA N: " << ronda << endl;
            rlutil::locate(45,14);
            cout << "PROXIMO TURNO: " << jugador1 << endl;
            rlutil::locate(45,16);
            cout << "PUNTAJE " << jugador1 << ": " << puntajeTotal << endl;
            rlutil::locate(41,18);
            std::cout <<  "------------------------------------" <<endl;
            rlutil::locate(1,29);
            system("pause");
            system("cls");
        }



        ronda++;

        if(puntajeTotal>=200){
            rlutil::locate(50,12);
            cout<<"FELICITACIONES!!!"<<endl;
            rlutil::locate(50,14);
            cout<<jugador1<<endl;
            rlutil::locate(50,16);
            cout<<"LOGRASTE ESCALERA"<<endl;
            rlutil::locate(50,18);
            cout<<"FIN DE LA PARTIDA"<<endl;
            rlutil::locate(1,30);
            system("pause");
        }
        else if(puntajeTotal>=100){
            rlutil::locate(50,12);
            cout<<"FELICITACIONES!!!"<<endl;
            rlutil::locate(50,14);
            cout<<jugador1<<endl;
            rlutil::locate(50,16);
            cout<<"FIN DE LA PARTIDA"<<endl;
            rlutil::locate(50,18);
            cout<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
            rlutil::locate(50,20);
            cout<<"CANTIDAD DE RONDAS QUE LLEVO GANAR: "<<ronda<<endl;
            rlutil::locate(1,30);
            system("pause");
            break;
        }

    }
}
