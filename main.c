#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "fun.h"
#include <math.h>
#include <string.h>

int main(void) 
{
  //Arreglo que contiene todas las posiciones de el tablero
  char* arreglo[225];
  crearTablero(arreglo);
  //Arreglo que contiene las posiciones por donde se pueden mover las fichas
  tipoRecorrido* arregloRecorrido = malloc(52*sizeof(tipoRecorrido));
  crearRecorrido(arregloRecorrido);
  //Arreglo que guarda el orden de turno de los jugadores
  tipoJugador* arregloTurnos = calloc(4,sizeof(tipoJugador)); 
  //Lista que guarda los jugadores de la partida
  List *listJugadores = createList(); 
  printf("MENÚ\n\n");

  //Presentación de el juego
  printf("BIENVENIDO A LUDO 2.0, A CONTINUACIÓN TE PRESENTAREMOS LAS REGLAS BÁSICAS DEL JUEGO\n\n");
  printf("Reglas del juego:\n\n");
  printf("Cada jugador escogerá su color y tendrá sus 4 fichas con las cuales deberá jugar estratégicamente para conseguir la victoria.\n\n");
  printf("Para salir de la base, se requiere que al lanzar el dado, el valor obtenido corresponda a un número par en el rango de 2 a 6.\n\n");
  printf("Para enviar una ficha de tu contrincante de vuelta a su base, una ficha tuya debe caer en una casilla donde ya se encuentre una ficha de tu contrincante. En caso de que la casilla en la que se cae contenga una ficha propia, esta se enviará de vuelta a la base.\n\n");
  printf("Ganas un punto por cada ficha comida PERO CUIDADO!!! si te comes una ficha de tu propiedad perderás un punto.\n\n");
  printf("Si se obtiene un 6, se puede volver a lanzar el dado con un máximo de 3 lanzamientos consecutivos,en caso que en el tercer lanzamiento se obtenga un 6, el jugador pierde el turno.\n\n");
  printf("No se permite el salto de turnos.\n\n");
  printf("Por favor ingrese los datos necesarios para configurar su partida\n\n");


  Menu(listJugadores, arreglo,arregloTurnos, arregloRecorrido);  
  
  return 0;
}

