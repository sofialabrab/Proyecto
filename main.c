#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "fun.h"
#include <math.h>
#include <string.h>


int main(void) 
{
  char* matriz[15][15] = {};
  char* arreglo[225];
  crearTablero(arreglo);
  tipoRecorrido* arregloRecorrido = malloc(52*sizeof(tipoRecorrido));
  crearRecorrido(arregloRecorrido);
  tipoJugador* arregloTurnos = calloc(4, sizeof(tipoJugador)); //0-Rojo,1-Azul,2-Verde,3-Amarillo
  int modalidad;
  List *listJugadores = createList(); 
  //lanzarDado();
  printf("MENÚ\n\n");
  printf("Modalidades:\n");
  printf("1.- Modalidad Tradicional\n (Partida tradicional, cada jugador jugara con un color y sus 4 fichas, ademas de un dado de 6 caras)\n\n");
  printf("2.- Modalidad Alternativa\n(Partida Alternativa, cada jugador jugara con un personaje asociado a un color, sus 4 fichas y su dado  especial de 8 caras, el cual contiene una ventaja y un castigo) \n\n");
  printf("Elija su modalidad de juego: ");
  scanf("%d", &modalidad);
  if(modalidad == 1) ModalidadTradicional(listJugadores, arreglo,arregloTurnos, arregloRecorrido);  
  //else ModalidadAlternativa();
  //imprimirMatriz(matriz);
  //imprimirTablero(arreglo);
  return 0;
}
// gdb main
// r
//q para salirse

