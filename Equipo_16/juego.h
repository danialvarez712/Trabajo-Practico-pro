#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED


void dibujarCuadrado(int posx, int posy);
void dibujarDado(int numero, int posx, int posy, int color=15, int colorPoint=0);
void dibujarSombra(int posx, int posy);
void dibujarPuntos(int numero, int posx, int posy);
int tirarDado(int posx, int posy);
void lanzamiento(int dados[]);
void lanzamientoForzado(int dados[],int posx, int pcosy);
void mostrarValorDados(int dados[]);
void juego(const std::string& jugador1, int& puntuacion);
void juegoforzado(const std::string& jugador1, int& puntuacion);


#endif // JUEGO_H_INCLUDED
