#define fun_h
#include "list.h"
#include <stdbool.h>



typedef struct{
  int posicion1;
  int posicion2;
  int posicion3;
  int posicion4;  
}tipoPosicionFicha;

typedef struct
{
  char color[10];
  int turno;
  bool activo;
  tipoPosicionFicha posiciones;

}tipoJugador;

typedef struct
{
  int posicion_arreglo;
}tipoRecorrido;

typedef struct
{
  int contRojo;
  int contAzul;
  int contVerde;
  int contAmarillo;
  

}puntos;

typedef struct
{
  int puntosJugador;
  char color[10];

}ganador;



//void VisualizacionTablero(List *);
int lanzarDado();
void Menu(List *, char* arreglo[225],tipoJugador* arregloTurno, tipoRecorrido*); 
//void ModalidadAlternativa(List *); 
void imprimirMatriz(char* matriz[15][15],int);
void imprimirTablero (char* arreglo[225]);
void mostrarTurno(int , int, tipoJugador* );
//void enJuego();
void consultaGanador();
int primerJugador(tipoJugador *,int);
void esGanador();
void EnJuego(char * arreglo[225], List *, int, tipoJugador*,tipoRecorrido*);
void crearRecorrido(tipoRecorrido* arregloRecorrido);
void editarTablero(int, int, char* arreglo[225], tipoJugador*, tipoRecorrido*, int,puntos *);
void crearTablero(char* arreglo[225]);
int turno(tipoJugador *,int );
void eliminarFicha(int, int, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int,int,puntos *);
void rectaFinal(int);

//Eliminar fichas
void eliminarFicha1(int, int, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int,int,puntos *);
void eliminarFicha2(int, int, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int,int,puntos *);
void eliminarFicha3(int, int, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int,int,puntos *);
void eliminarFicha4(int, int, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int,int,puntos *);

void MostrarGanadores(puntos *,int );