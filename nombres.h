#ifndef NOMBRES_H_INCLUDED
#define NOMBRES_H_INCLUDED
using namespace std;


void mezclar();

int  mezclarCartas(int tam);

void repartirCartas(int &ronda ,string vPalo[4],string vValor[5],int vPaloj1[5], int vPaloj2[5], int vValorj1[5], int vValorj2[5],string &jugador1,string &jugador2, int vPuntajeCartas[5],int &puntajeTotalj1,int &puntajeTotalj2);

void mostrarManos(int vPaloj1[5],int vPaloj2[5],int vValorj1[5],int vValorj2[5],string vPalo[4],string vValor[5]);

void mostrarEmbaucadora(string vPalo[4],int &embaucadora);

void guardarNombres(string &jugador1,string &jugador2) ;

int cambioEmbaucadora(bool &bandera, int &embaucadora,string vPalo[4], string &jugador1,string jugador2, int &puntajeTotalj1,int &puntajeTotalj2);

void calcularPuntaje( int &embaucadora,int vPaloj1[5],int vPaloj2[5],int vValorj1[5],int vValorj2[5],int vPuntajeCartas[5],int vPuntajeRondaj1[5],int vPuntajeRondaj2[5]);

void puntajeXronda(int &ronda,int vpuntajeRondaj1[5], int vpuntajeRondaj2[5],int vpuntajeXrondaj1[3], int vpuntajeXrondaj2[3]);

void mostrarPuntaje(int &ronda, string &jugador1,string &jugador2,int vPuntajeRondaj1[5], int vPuntajeRondaj2[5], int vpuntajeXrondaj1[3],int vpuntajeXrondaj2[3]);

void mostrarPuntajesTotales(int &puntajeTotalj1, int &puntajeTotalj2, string &jugador1, string &jugador2,int vPuntajeXrondaj1[3], int vPuntajeXrondaj2[3]);

void funcionEstadisticas(string &jugador1, string &jugador2,int &acuPuntajeTotalj1,int &acuPuntajeTotalj2);

void funcionReglas();
#endif // NOMBRES_H_INCLUDED


