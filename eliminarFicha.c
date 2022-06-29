#include "fun.h"
#include "list.h"
//El jugador se comió a alguien con su ficha 1
void eliminarFicha1(int fichaMover, int turnoDe, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int dado, int i,puntos * puntosJugador)
{
  // jugador rojo 
  if (turnoDe == 0) 
    {
      if ((i + dado) < 52 )
      {
        //Caso 1: jugador se come sus propias fichas
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))
        {
          printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contRojo--;}
          return;
  
        }
        else
        {
          //Caso 2: jugador se come una ficha contrincante
          printf("Rojo 1 se come a: %s\n", arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          //Si es Azul
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contRojo++;}

          //Si es verde
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0)) { arreglo[41] = "V1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contRojo++;}
          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contRojo++;}
          
          return;
        }
      }
      else 
      { // Caso especifico: Sucede lo mismo de arriba, pero aquí se reinician posiciones
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R4") == 0)) 
        {
          printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contRojo--;}
          printf("Contador rojo \n %d",puntosJugador->contRojo);
          
          return;
        }
        else
        {
          printf("Rojo 1 se come a: %s\n", arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo]);
          //Si es Azul
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contRojo++;}

          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contRojo++;}

          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM1") == 0)) { arreglo[176] = "AM1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contRojo++;}
          
          return;
        }
      }

    }
  //Jugador Azul
    if (turnoDe == 1) 
    {
      if ((i+ dado) < 52 )
      {
        //mismas fichas 
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))
        {
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
           //Si es Azul
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0)) { arreglo[183] = "AZ4";puntosJugador->contAzul--;}
          return;
        }
        else
        {
          
          printf("Azul 1 se come a: %s\n", arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          //Si es verde
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAzul++;}
          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAzul++;}
          //Si es Rojo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
          "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0)) { arreglo[47] = "R3";puntosJugador->contAzul++;}
         else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0)) { arreglo[48] = "R4";puntosJugador->contAzul++;}
          return;

        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ4") == 0)) 
        {
          
                     //Si es Azul
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAzul--;}
          return;
        }
        else
        {
          
          //Si es verde
           printf("Azul 1 se come a: %s\n", arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo]);
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAzul++;}
          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAzul++;}
          //Si es Rojo
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
          "R1") == 0)) { arreglo[32] = "R1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R2") == 0)) { arreglo[33] = "R2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAzul++;}
          return;
        }
      }
      
    }
  //jugador verde
    if (turnoDe == 2) 
    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))
        {
          
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
                     //Si es verde
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0)) { arreglo[42] = "V2";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contVerde--;}

          return;
        }
        else
        {
          printf("Verde 1 se come a: %s\n", arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          //Si es Rojo
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
          "R1") == 0)) { arreglo[32] = "R1";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0)) { arreglo[48] = "R4";puntosJugador->contVerde++;}
                    //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0)) { arreglo[192] = "AM4";puntosJugador->contVerde++;}
                    //Si es Azul
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contVerde++;}
          return;
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V4") == 0)) 
        {
          
            printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n");
                     //Si es verde
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contVerde--;}
          return;
        }
        else
        {
          
          printf("Verde 1 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
                     //Si es Rojo
            if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contVerde++;}
                      //Si es Amarillo
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contVerde++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ3") == 0)) { arreglo[182] = "AZ3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contVerde++;}
          return;
          
        }
      }

    }
    //Jugador amarillo
    if (turnoDe == 3)
    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))
        {
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
            if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAmarillo--;}
          return;
        }
        else
        {
          
           printf("Amarillo 1 se come a: %s\n", arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
            if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAmarillo++;}
          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {{arreglo[56] = "V3";puntosJugador->contAmarillo++;}}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAmarillo++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ1") == 0)) { arreglo[167] = "AZ1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAmarillo++;}
          return;
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM4") == 0)) 
        {
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
             if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                    "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                    "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                    "AM4") == 0)) { arreglo[192] = "AM4";puntosJugador->contAmarillo--;}
 
          return;
        }
        else
        {
          
           printf("Amarillo 1 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
                      //Si es Rojo
            if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R4") == 0)) { arreglo[48] = "R4";puntosJugador->contAmarillo++;}
          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0)) { arreglo[42] = "V2";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAmarillo++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ3") == 0)) { {arreglo[182] = "AZ3";puntosJugador->contAmarillo++;}}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAmarillo++;}
          return;
          //printf("En la posición queda: %s \n",arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
        }
      }
    }

  }

//el jugador se comió a alguien con la ficha 2
void eliminarFicha2(int fichaMover, int turnoDe, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int dado, int i,puntos * puntosJugador)
{
  if (turnoDe == 0) 
    {
      if ((i + dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R1") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))
        {
          
          printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n");
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))  arreglo[48] = "R4";puntosJugador->contRojo--;
          return;

          
        }
        else
        {
          
          printf("Rojo 2 se come a: %s\n", arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          //Si es Azul
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contRojo++;}

          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contRojo++;}

          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contRojo++;}
          
          return;
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R1") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R4") == 0)) 
        {
          
          printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n");
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contRojo--;}
          return;

        }
        else
        {
          
          printf("Rojo 2 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          //Si es Azul
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ2") == 0)){  arreglo[168] = "AZ2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ3") == 0)) {arreglo[182] = "AZ3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ4") == 0)) { arreglo[183] = "AZ4";puntosJugador->contRojo++;}

          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contRojo++;}

          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM1") == 0)) { arreglo[176] = "AM1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contRojo++;}

          return;
        }
      }

    }
    if (turnoDe == 1) 
    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))
        {
          
            //Si es Azul
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0)) { arreglo[183] = "AZ4";puntosJugador->contAzul--;}
          
          return;
        }
        else
        {
          
           //Si es verde
          printf("Azul 2 se come a: %s\n", arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0)) { arreglo[56] = "V3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0)) { arreglo[57] = "V4";puntosJugador->contAzul++;}
          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0)) { arreglo[191] = "AM3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAzul++;}
          //Si es Rojo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
          "R1") == 0)) { arreglo[32] = "R1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0)) { arreglo[33] = "R2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAzul++;}
          return;

        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ1") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ4") == 0)) 
        {
          
                     //Si es Azul
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
           if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAzul--;}
          return;
        }
        else
        {
          
          printf("Azul 2 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          //Si es verde
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0)) { arreglo[56] = "V3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAzul++;}
          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM2") == 0)) { arreglo[177] = "AM2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAzul++;}
          //Si es Rojo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
          "R1") == 0)) { arreglo[32] = "R1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R2") == 0)) { arreglo[33] = "R2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R4") == 0)) { arreglo[48] = "R4";puntosJugador->contAzul++;}

          return;
        }
      }
      
    }
    if (turnoDe == 2) 
    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))
        {
          
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
                     //Si es verde
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0)) { arreglo[41] = "V1";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contVerde--;}
          return;
        }
        else
        {
          
          printf("Verde 2 se come a: %s\n", arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          //Si es Rojo
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
          "R1") == 0)){  arreglo[32] = "R1";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0)) { arreglo[33] = "R2";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0)) { arreglo[48] = "R4";puntosJugador->contVerde++;}
                    //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0)) { arreglo[176] = "AM1";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contVerde++;}
                    //Si es Azul
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0)) { arreglo[168] = "AZ2";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0)){  arreglo[182] = "AZ3";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contVerde++;}
          return;
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V1") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V4") == 0)) 
        {
          
            printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
                     //Si es verde
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0)) { arreglo[41] = "V1";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0)) { arreglo[56] = "V3";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0)) { arreglo[57] = "V4";puntosJugador->contVerde--;}
          return;
        }
        else
        {
          
          printf("Verde 2 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
                     //Si es Rojo
            if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R2") == 0)) { arreglo[33] = "R2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R3") == 0)) { arreglo[47] = "R3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R4") == 0)) { arreglo[48] = "R4";puntosJugador->contVerde++;}
                      //Si es Amarillo
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM1") == 0)) { arreglo[176] = "AM1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM3") == 0)) { arreglo[191] = "AM3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contVerde++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ2") == 0)) { arreglo[168] = "AZ2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contVerde++;}
          return;
        }
      }

    }
    
    
    if (turnoDe == 3)

    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))
        {
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
            if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM1") == 0)) { arreglo[176] = "AM1";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAmarillo--;}
          return;
        }
        else
        {
         
          printf("Amarillo 2 se come a: %s\n", arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
            if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1"; puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2"; puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R3") == 0)) { arreglo[47] = "R3"; puntosJugador->contAmarillo++;}
            if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R4") == 0)) { arreglo[48] = "R4"; puntosJugador->contAmarillo++;}
          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0)) { arreglo[41] = "V1"; puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0)) { arreglo[42] = "V2"; puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0)) { arreglo[56] = "V3"; puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0)) { arreglo[57] = "V4"; puntosJugador->contAmarillo++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ1") == 0)) { arreglo[167] = "AZ1"; puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2"; puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ3") == 0))  {arreglo[182] = "AZ3"; puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4"; puntosJugador->contAmarillo++;}
          return;
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM1") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM4") == 0)) 
        {
            printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
            if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM3") == 0)) { arreglo[191] = "AM3";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAmarillo--;}
          return;
        }

        else
        {
          
          printf("Amarillo 2 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
                               //Si es Rojo
            if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                    "R4") == 0)) { arreglo[48] = "R4";puntosJugador->contAmarillo++;}
          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                  "V4") == 0)) { arreglo[57] = "V4";puntosJugador->contAmarillo++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                    "AZ1") == 0)) { arreglo[167] = "AZ1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                    "AZ3") == 0)) { arreglo[182] = "AZ3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado) - 52].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAmarillo++;}
          return;
        }
      }
    }

  }
//jugador se comio a alguien con ficha 3
void eliminarFicha3(int fichaMover, int turnoDe, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int dado, int i,puntos * puntosJugador)
{
  if (turnoDe == 0) 
    {
      if ((i + dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R1") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))
        {
          
          printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
           if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contRojo--;}
          
          return;
        }
        else
        {
           printf("Rojo 3 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          //Si es Azul
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contRojo++;}

          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0)) { arreglo[42] = "V2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contRojo++;}

          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contRojo++;}
          return;
   
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R1") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R4") == 0)) 
        {
          
          printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
           if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contRojo--;}
          return;

        }
        else
        {
           printf("Rojo 3 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          //Si es Azul
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contRojo++;}

          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contRojo++;}

          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contRojo++;}
          return;
        }
      }

    }
    if (turnoDe == 1) 
    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))
        {
          
            //Si es Azul
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
           if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAzul--;}
          return;
        }
        else
        {
           printf("Azul 3 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
           //Si es verde
           if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0)) { arreglo[56] = "V3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAzul++;}
          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAzul++;}
          //Si es Rojo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
          "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAzul++;}
          return;

        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ1") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ4") == 0)) 
        {
          
                     //Si es Azul
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
           if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAzul--;}
          return;
        }
        else
        {
           printf("Azul 3 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          //Si es verde
           if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAzul++;}
          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAzul++;}
          //Si es Rojo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
          "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAzul++;}
          return;
        }
      }
      
    }
    if (turnoDe == 2) 
    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))
        {
          
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
                     //Si es verde
           if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contVerde--;}
          
          return;
        }
        else
        {
           printf("Verde 3 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          //Si es Rojo
           if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
          "R1") == 0))  {arreglo[32] = "R1"; puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2"; puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3"; puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4"; puntosJugador->contVerde++;}
                    //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1"; puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2"; puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3"; puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4"; puntosJugador->contVerde++;}
                    //Si es Azul
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1"; puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2"; puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3"; puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4"; puntosJugador->contVerde++;}
          return;
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V1") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V4") == 0)) 
        {
          
            printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
                     //Si es verde
           if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contVerde--;}
          return;
        }
        else
        {
           printf("Verde 3 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          
                     //Si es Rojo
             if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contVerde++;}
                      //Si es Amarillo
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM1") == 0)) { arreglo[176] = "AM1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contVerde++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contVerde++;}
          return;
        }
      }

    }
    
    
    if (turnoDe == 3)

    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))
        {
          printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
             if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM2") == 0)) { arreglo[177] = "AM2";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM4") == 0)) { arreglo[192] = "AM4";puntosJugador->contAmarillo--;}
          return;
        }
        else
        {
           printf("Amarillo 3 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          
            if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R4") == 0)) { arreglo[48] = "R4";puntosJugador->contAmarillo++;}
          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0)) { arreglo[57] = "V4";puntosJugador->contAmarillo++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAmarillo++;}
          return;
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM1") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM4") == 0)) 
        {
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
          
           if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAmarillo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAmarillo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM4") == 0))  {arreglo[57192] = "AM4";puntosJugador->contAmarillo--;}
          
          return;
          
        }
        else
        {
           printf("Amarillo 3 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
                               //Si es Rojo
             if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAmarillo++;}
          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0)) { arreglo[41] = "V1";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0)) { arreglo[56] = "V3";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAmarillo++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ1") == 0)) { arreglo[167] = "AZ1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ4") == 0)) { arreglo[183] = "AZ4";puntosJugador->contAmarillo++;}
          return;
        }
      }
    }

  }
//Jugador se comio a alguien con la ficha 4
void eliminarFicha4(int fichaMover, int turnoDe, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int dado, int i,puntos * puntosJugador)
{
  if (turnoDe == 0) 
    {
      if ((i + dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R1") == 0))
        {
          
          printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
           if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contRojo--;}
          return;

          
        }
        else
        {
           printf("Rojo 4 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          //Si es Azul
           if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0)) { arreglo[183] = "AZ4";puntosJugador->contRojo++;}

          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contRojo++;}

          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contRojo++;}
          
          
            return;
         
          
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "R1") == 0)) 
        {
          
          printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contRojo--;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contRojo--;}
          return;

        }
        else
        {
           printf("Rojo 4 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          
          //Si es Azul
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contRojo++;}

          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contRojo++;}
         else  if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contRojo++;}

          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contRojo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contRojo++;}
          return;
          
        }
      }

    }
    if (turnoDe == 1) 
    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))
        {
          
            //Si es Azul
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
           if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contAzul--;}
          return;
        }
        else
        {
           printf("Azul 4 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
           //Si es verde
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAzul++;}
          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAzul++;}
          //Si es Rojo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
          "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAzul++;}
          return;

        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AZ1") == 0)) 
        {
          
                     //Si es Azul
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
          if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAzul--;}
          else if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[183] = "AZ1";puntosJugador->contAzul--;}
          return;
        }
        else
        {
           printf("Azul 4 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          //Si es verde
          if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0)) { arreglo[56] = "V3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAzul++;}
          //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contAzul++;}
          //Si es Rojo
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
          "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R4") == 0))  {arreglo[47] = "R3";puntosJugador->contAzul++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAzul++;}
          
          return;
        }
      }
      
    }
    if (turnoDe == 2) 
    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))
        {
          
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
                     //Si es verde
           if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contVerde--;}
          return;
        }
        else
        {
           printf("Verde 4 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
          //Si es Rojo
          if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
          "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contVerde++;}
                    //Si es Amarillo
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contVerde++;}
                    //Si es Azul
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contVerde++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contVerde++;}
          return;
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "V1") == 0)) 
        {
          
            printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
                     //Si es verde
           if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contVerde--;}
          else if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contVerde--;}
          
          return;
        }
        else
        {
           printf("Verde 4 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
                     //Si es Rojo
             if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contVerde++;}
            else  if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contVerde++;}
                      //Si es Amarillo
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AM4") == 0))  {arreglo[192] = "AM4";puntosJugador->contVerde++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contVerde++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contVerde++;}
          return;
        }
      }

    }
    
    
    if (turnoDe == 3)

    {
      if ((i+ dado) < 52 )
      {
        if ((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM2") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM3") == 0) ||
          (strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "AM1") == 0))
        {
           printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados! \n\n");
             if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM3") == 0))  {arreglo[191] = "AM3";puntosJugador->contAmarillo--;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAmarillo--;}
          
          return;
        }
        else
        {
           printf("Amarillo 4 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
             if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
            "R1") == 0))  {arreglo[32] = "R1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAmarillo++;}
           else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAmarillo++;}
           else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAmarillo++;}
          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V1") == 0)) { arreglo[41] = "V1";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V2") == 0)) { arreglo[42] = "V2";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                  "V4") == 0))  {arreglo[57] = "V4";puntosJugador->contAmarillo++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAmarillo++;}
          
          return;
        }
      }
      else 
      { 
        if ((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM2") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM3") == 0) ||
                 (strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                         "AM1") == 0)) 

          {
            
            printf("\nTe haz comido una de tus fichas :(  pierdes un punto en tus eliminados!\n \n");
           if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                  "AM2") == 0))  {arreglo[177] = "AM2";puntosJugador->contAmarillo--;}
          else if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                  "AM3") == 0)) { arreglo[191] = "AM3";puntosJugador->contAmarillo--;}
          else if((strcmp(arreglo[arregloRecorrido[((i + dado) - 52)].posicion_arreglo],
                  "AM1") == 0))  {arreglo[176] = "AM1";puntosJugador->contAmarillo--;}
            return;
        }
        else
        {
           printf("Amarillo 4 se come a: %s\n", arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo]);
                               //Si es Rojo
             if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
            "R1") == 0)) { arreglo[32] = "R1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R2") == 0))  {arreglo[33] = "R2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R3") == 0))  {arreglo[47] = "R3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "R4") == 0))  {arreglo[48] = "R4";puntosJugador->contAmarillo++;}
          //Si es verde
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V1") == 0))  {arreglo[41] = "V1";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V2") == 0))  {arreglo[42] = "V2";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V3") == 0))  {arreglo[56] = "V3";puntosJugador->contAmarillo++;}
          else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                  "V4") == 0)) { arreglo[57] = "V4";puntosJugador->contAmarillo++;}
                      //Si es Azul
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ1") == 0))  {arreglo[167] = "AZ1";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ2") == 0))  {arreglo[168] = "AZ2";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[(i + dado)-52].posicion_arreglo],
                    "AZ3") == 0))  {arreglo[182] = "AZ3";puntosJugador->contAmarillo++;}
            else if((strcmp(arreglo[arregloRecorrido[i + dado].posicion_arreglo],
                    "AZ4") == 0))  {arreglo[183] = "AZ4";puntosJugador->contAmarillo++;}
          return;
        }
      }
    }

  }



