#define fun_h
#include "list.h"
#include <stdbool.h>

typedef struct{

 int fichasEnJuego;
 int fichasGanadoras;  
 int fichasEnBase;
 

}tipoEstado;
typedef struct{
  int posicion1;
  int posicion2;
  int posicion3;
  int posicion4;  
}tipoPosicionFicha;
typedef struct
{
  char color[10];
  tipoEstado fichas;
  int turno;
  bool activo;
  tipoPosicionFicha posiciones;
  
}tipoJugador;

typedef struct
{
  int amarillo;
  int azul;
  int rojo;
  int verde;
  int posicion_arreglo;
}tipoRecorrido;

//void VisualizacionTablero(List *);
int lanzarDado();
void ModalidadTradicional(List *, char* arreglo[225],tipoJugador* arregloTurno, tipoRecorrido*); 
//void ModalidadAlternativa(List *); 
void imprimirMatriz(char* matriz[15][15],int);
void imprimirTablero (char* arreglo[225]);
void mostrarTurno(int , int, tipoJugador* );
void enJuego();
void consultaGanador();
int primerJugador(tipoJugador *,int);
void esGanador();
void EnJuego(char * arreglo[225], List *, int, tipoJugador*,tipoRecorrido*);
void crearRecorrido(tipoRecorrido* arregloRecorrido);
void editarTablero(int, int, char* arreglo[225], tipoJugador*, tipoRecorrido*, int);
void crearTablero(char* arreglo[225]);
int turno(tipoJugador *,int );