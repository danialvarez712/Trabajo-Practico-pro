#ifndef DISENIOODADOS_H_INCLUDED
#define DISENIOODADOS_H_INCLUDED
#include <vector>

using namespace std;

void dibujarCuadrado(int posx, int posy);
void dibujarDado(int numero, int posx, int posy, int color=15, int colorPoint=0);
void dibujarSombra(int posx, int posy);
void dibujarPuntos(int numero, int posx, int posy);
int tirarDado(int posx, int posy);
void lanzamiento(int dados[]);
void dadosDisenio (vector<int>& dados);

#endif // DISENIODADOS_H_INCLUDED
