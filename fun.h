#define fun_h
#include "list.h"
#include <stdbool.h>

typedef struct{

 int fichasEnJuego;
 int fichasGanadoras;  
 int fichasEnBase;

}tipoEstado;

typedef struct
{
  char color[10];
  tipoEstado fichas;
  int turno;
  bool activo;
}tipoJugador;

//void VisualizacionTablero(List *);
int lanzarDado();
void ModalidadTradicional(List *, char* arreglo[225],tipoJugador* arregloTurno); 
//void ModalidadAlternativa(List *); 
void imprimirMatriz(char* matriz[15][15],int);
void imprimirTablero (char* arreglo[225]);
void mostrarTurno(int , int );
void enJuego();
void consultaGanador();
int primerJugador(int);
void esGanador();
void EnJuego(char * arreglo[225], List *, int);