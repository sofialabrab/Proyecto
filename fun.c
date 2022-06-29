#include "fun.h"
#include "list.h"

void editarTablero(int fichaMover, int turnoDe, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int dado, puntos *puntosJugador) {
  int dondeEsta;
  int diferencia = 0;
 

  // Si el jugador decide mover su ficha "1"
  if (fichaMover == 1) {
    // CASOS ESPECIFICOS, salir de la base
    if ((turnoDe == 0) && (strcmp(arreglo[32], "R1") == 0) &&
        ((dado % 2) == 0)) {
      arreglo[32] = "0";
      if (strcmp(arreglo[91], "0") != 0) {
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 0, puntosJugador);
      }
      arreglo[91] = "R1";
      arregloTurno[turnoDe].posiciones.posicion1 = 91;
      return;

    } else if ((turnoDe == 1) && (strcmp(arreglo[167], "AZ1") == 0) &&
               (dado % 2) == 0) {
      arreglo[167] = "0";
      if (strcmp(arreglo[201], "0") != 0) {
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 39, puntosJugador);
      }
      arreglo[201] = "AZ1";
      arregloTurno[turnoDe].posiciones.posicion1 = 201;

      return;
    } else if ((turnoDe == 2) && (strcmp(arreglo[41], "V1") == 0) &&
               (dado % 2 == 0)) {
      arreglo[41] = "0";
      if (strcmp(arreglo[23], "0") != 0) {
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 13, puntosJugador);
      }
      arreglo[23] = "V1";
      arregloTurno[turnoDe].posiciones.posicion1 = 23;
      return;
    } else if ((turnoDe == 3) && (strcmp(arreglo[176], "AM1") == 0) &&
               (dado % 2 == 0)) {
      arreglo[176] = "0";
      if (strcmp(arreglo[133], "0") != 0) {
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 26, puntosJugador);
      }
      arreglo[133] = "AM1";
      arregloTurno[turnoDe].posiciones.posicion1 = 133;
      return;
    }
    
    else if (turnoDe == 0 && (strcmp(arreglo[32], "R1") == 0) && ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    }
    else if (turnoDe == 1 && (strcmp(arreglo[167], "AZ1") == 0) &&
             ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    } else if (turnoDe == 2 && (strcmp(arreglo[41], "V1") == 0) &&
               ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    } else if (turnoDe == 3 && (strcmp(arreglo[176], "AM1") == 0) &&
               ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    }

    // Casos en juego
    dondeEsta = arregloTurno[turnoDe].posiciones.posicion1;
    for (int i = 0; i < 52; i++) {
      // Compara en que posicion del arreglo del recorrido estoy
      if (arregloRecorrido[i].posicion_arreglo == dondeEsta) {
        // actualiza la casilla de donde sali a "0"
        arreglo[arregloTurno[turnoDe].posiciones.posicion1] = "0";

       
        if (i + dado < 52) {
           // Si entra al if, se sabe que existe alguna ficha en la posición
          if (arregloRecorrido[i + dado].posicion_arreglo != 0) {
            
            eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                          arregloRecorrido, dado, i, puntosJugador);
          }
        } else {
          diferencia = (i + dado) - 52;
          if (arregloRecorrido[diferencia].posicion_arreglo != 0) {
            eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                          arregloRecorrido, dado, i, puntosJugador);
          }
        }
        diferencia = 0;

        // Muevo a el jugador la cantidad de casillas que me dijo el dado
        arregloTurno[turnoDe].posiciones.posicion1 =
            arregloRecorrido[i + dado].posicion_arreglo;

        if (i + dado >= 52)
          arregloTurno[turnoDe].posiciones.posicion1 =
              arregloRecorrido[i + dado - 52].posicion_arreglo;

        // Dependiendo de quien haya sido el jugador, se actualiza la casilla
        // con el jugador en la posicion
        if (turnoDe == 0 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "R1";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 0) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "R1";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 1 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AZ1";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 1) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "AZ1";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 2 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "V1";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 2) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "V1";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 3 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AM1";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 3) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "AM1";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        break;
      }
    }
  }

  // Si el jugador decide mover su ficha "2"
  if (fichaMover == 2) {
    // CASOS ESPECIFICOS, salir de la base
    if ((turnoDe == 0) && (strcmp(arreglo[33], "R2") == 0) && dado % 2 == 0) {
      arreglo[33] = "0";
      if (strcmp(arreglo[91], "0") != 0) {

        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 0, puntosJugador);
      }
      arreglo[91] = "R2";
      arregloTurno[turnoDe].posiciones.posicion2 = 91;
      return;
    } else if ((turnoDe == 1) && (strcmp(arreglo[168], "AZ2") == 0) &&
               (dado % 2) == 0) {
      arreglo[168] = "0";
       // Si entra al if, se sabe que existe alguna ficha en la posición
      if (strcmp(arreglo[201], "0") != 0) {
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 39, puntosJugador);
      }
      arreglo[201] = "AZ2";
      arregloTurno[turnoDe].posiciones.posicion2 = 201;
      return;
    } else if ((turnoDe == 2) && (strcmp(arreglo[42], "V2") == 0) &&
               dado == 6) {
      arreglo[42] = "0";
      if (strcmp(arreglo[23], "0") != 0) {
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 13, puntosJugador);
      }
      arreglo[23] = "V2";
      arregloTurno[turnoDe].posiciones.posicion2 = 23;
      return;
    } else if ((turnoDe == 3) && (strcmp(arreglo[177], "AM2") == 0) &&
               ((dado % 2) == 0)) {
      arreglo[177] = "0";
      if (strcmp(arreglo[133], "0") != 0) {
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 26, puntosJugador);
      }
      arreglo[133] = "AM2";
      arregloTurno[turnoDe].posiciones.posicion2 = 133;
      return;
    }
    if (turnoDe == 0 && (strcmp(arreglo[33], "R2") == 0) && ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    }
    else if (turnoDe == 1 && (strcmp(arreglo[168], "AZ2") == 0) &&
             ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    } else if (turnoDe == 2 && (strcmp(arreglo[42], "V2") == 0) &&
               ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    } else if (turnoDe == 3 && (strcmp(arreglo[177], "AM2") == 0) &&
               ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    }
    dondeEsta = arregloTurno[turnoDe].posiciones.posicion2;
    // Casos en juego
    for (int i = 0; i < 52; i++) {
      if (arregloRecorrido[i].posicion_arreglo == dondeEsta) {

        arreglo[arregloTurno[turnoDe].posiciones.posicion2] = "0";
        if (i + dado < 52) {
           // Si entra al if, se sabe que existe alguna ficha en la posición
          if (arregloRecorrido[i + dado].posicion_arreglo != 0) {
            eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                          arregloRecorrido, dado, i, puntosJugador);
          }
        } else {
          diferencia = ((i + dado) - 52);
           // Si entra al if, se sabe que existe alguna ficha en la posición
          if (arregloRecorrido[diferencia].posicion_arreglo != 0) {
           
            eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                          arregloRecorrido, dado, i, puntosJugador);
          }
        }
        diferencia = 0;

        arregloTurno[turnoDe].posiciones.posicion2 =
            arregloRecorrido[i + dado].posicion_arreglo;
        printf("En la posición queda: %s \n",
               arreglo[arregloRecorrido[i + dado].posicion_arreglo]);

        if (i + dado >= 52)
          arregloTurno[turnoDe].posiciones.posicion2 =
              arregloRecorrido[i + dado - 52].posicion_arreglo;

        if (turnoDe == 0 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "R2";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 0) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "R2";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 1 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AZ2";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 1) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "AZ2";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        else if (turnoDe == 2 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "V2";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 2) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "V2";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 3 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AM2";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 3) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "AM2";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }
        break;
      }
    }
  }
  // Si el jugador decide mover su ficha "3"
  if (fichaMover == 3) {
    // CASOS ESPECIFICOS, salir de la base
    if ((turnoDe == 0) && (strcmp(arreglo[47], "R3") == 0) &&
        ((dado % 2) == 0)) {
      arreglo[47] = "0";
       // Si entra al if, se sabe que existe alguna ficha en la posición
      if (strcmp(arreglo[91], "0") != 0) {
        printf("ENTRA A ESTO\n");
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 0, puntosJugador);
      }
      arreglo[91] = "R3";
      arregloTurno[turnoDe].posiciones.posicion3 = 91;
      return;
    } else if ((turnoDe == 1) && (strcmp(arreglo[182], "AZ3") == 0) &&
               (dado % 2) == 0) {
      arreglo[182] = "0";
      if (strcmp(arreglo[201], "0") != 0) {
        printf("ENTRA A ESTO\n");
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 39, puntosJugador);
      }
      arreglo[201] = "AZ3";
      arregloTurno[turnoDe].posiciones.posicion3 = 201;
      return;
    } else if ((turnoDe == 2) && (strcmp(arreglo[56], "V3") == 0) &&
               dado % 2 == 0) {
      arreglo[56] = "0";
      if (strcmp(arreglo[23], "0") != 0) {
        printf("ENTRA A ESTO\n");
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 13, puntosJugador);
      }
      arreglo[23] = "V3";
      arregloTurno[turnoDe].posiciones.posicion3 = 23;
      return;
    } else if ((turnoDe == 3) && (strcmp(arreglo[191], "AM3") == 0) &&
               dado % 2 == 0) {
      arreglo[191] = "0";
      if (strcmp(arreglo[133], "0") != 0) {
        printf("ENTRA A ESTO\n");
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 26, puntosJugador);
      }
      arreglo[133] = "AM3";
      arregloTurno[turnoDe].posiciones.posicion3 = 133;
      return;
    }
    else if(turnoDe == 0 && (strcmp(arreglo[47], "R3") == 0) && ((dado % 2) == 1))
    {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return; 
    }
     
    else if(turnoDe == 1 && (strcmp(arreglo[182], "AZ3") == 0) && ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
      }
    else if(turnoDe == 2 && (strcmp(arreglo[56], "V3") == 0) && ((dado % 2) == 1))
    {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    }
    else if(turnoDe == 3 && (strcmp(arreglo[191], "AM3") == 0) && ((dado % 2) == 1)) 
    {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    }

    dondeEsta = arregloTurno[turnoDe].posiciones.posicion3;
    // Casos en juego
    for (int i = 0; i < 52; i++) {
      if (arregloRecorrido[i].posicion_arreglo == dondeEsta) {
        printf("En la posición queda: %s \n",
               arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
        arreglo[arregloTurno[turnoDe].posiciones.posicion3] = "0";
        if (i + dado < 52) {
           // Si entra al if, se sabe que existe alguna ficha en la posición
          if (arregloRecorrido[i + dado].posicion_arreglo != 0) {
            eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                          arregloRecorrido, dado, i, puntosJugador);
          }
        } else {
          diferencia = ((i + dado) - 52);
           // Si entra al if, se sabe que existe alguna ficha en la posición
          if (arregloRecorrido[diferencia].posicion_arreglo != 0) {
            eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                          arregloRecorrido, dado, i, puntosJugador);
          }
        }
        diferencia = 0;
        arregloTurno[turnoDe].posiciones.posicion3 =
            arregloRecorrido[i + dado].posicion_arreglo;

        if (i + dado >= 52)
          arregloTurno[turnoDe].posiciones.posicion3 =
              arregloRecorrido[i + dado - 52].posicion_arreglo;

        if (turnoDe == 0 && i + dado < 52) {

          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "R3";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 0) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "R3";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 1 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AZ3";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 1) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "AZ3";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 2 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "V3";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 2) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "V3";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }
        if (turnoDe == 3 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AM3";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 3) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "AM3";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }
        break;
      }
    }
  }
  // Si el jugador decide mover su ficha "4"
  if (fichaMover == 4) {
    // CASOS ESPECIFICOS, salir de la base
    if ((turnoDe == 0) && (strcmp(arreglo[48], "R4") == 0) && dado % 2 == 0) {
      if (strcmp(arreglo[91], "0") != 0) {
        printf("ENTRA A ESTO\n");
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 0, puntosJugador);
      }
      arreglo[48] = "0";
      arreglo[91] = "R4";
      arregloTurno[turnoDe].posiciones.posicion4 = 91;
      return;
    } else if ((turnoDe == 1) && (strcmp(arreglo[183], "AZ4") == 0) &&
               dado % 2 == 0) {
      if (strcmp(arreglo[201], "0") != 0) {
        printf("ENTRA A ESTO\n");
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 39, puntosJugador);
      }
      arreglo[183] = "0";
      arreglo[201] = "AZ4";
      arregloTurno[turnoDe].posiciones.posicion4 = 201;
      return;
    } else if ((turnoDe == 2) && (strcmp(arreglo[57], "V4") == 0) &&
               dado % 2 == 0) {
      if (strcmp(arreglo[23], "0") != 0) {
        printf("ENTRA A ESTO\n");
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 13, puntosJugador);
      }
      arreglo[57] = "0";
      arreglo[23] = "V4";
      arregloTurno[turnoDe].posiciones.posicion4 = 23;
      return;
    } else if ((turnoDe == 3) && (strcmp(arreglo[192], "AM4") == 0) &&
               dado % 2 == 0) {
      if (strcmp(arreglo[133], "0") != 0) {
        printf("ENTRA A ESTO\n");
        eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado, 26, puntosJugador);
      }
      arreglo[192] = "0";

      arreglo[133] = "AM4";
      arregloTurno[turnoDe].posiciones.posicion4 = 133;
      return;
    }
     else if(turnoDe == 0 && (strcmp(arreglo[48], "R4") == 0) && ((dado % 2) == 1))
    {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return; 
    }
     
    else if(turnoDe == 1 && (strcmp(arreglo[183], "AZ4") == 0) && ((dado % 2) == 1)) {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
      }
    else if(turnoDe == 2 && (strcmp(arreglo[57], "V4") == 0) && ((dado % 2) == 1))
    {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    }
    else if(turnoDe == 3 && (strcmp(arreglo[192], "AM4") == 0) && ((dado % 2) == 1)) 
    {
      printf(" NO PUEDES SACAR ESTA FICHA, PIERDES EL TURNO\n\n");
      return;
    }
    dondeEsta = arregloTurno[turnoDe].posiciones.posicion4;
    // Casos en juego
    for (int i = 0; i < 52; i++) {
      if (arregloRecorrido[i].posicion_arreglo == dondeEsta) {
        arreglo[arregloTurno[turnoDe].posiciones.posicion4] = "0";
        // arregloTurno[turnoDe].posiciones.posicion4=0;
        if (i + dado < 52) {
           // Si entra al if, se sabe que existe alguna ficha en la posición
          if (arregloRecorrido[i + dado].posicion_arreglo != 0) {
            eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                          arregloRecorrido, dado, i, puntosJugador);
          }
        } else {
          diferencia = ((i + dado) - 52);
           // Si entra al if, se sabe que existe alguna ficha en la posición
          if (arregloRecorrido[diferencia].posicion_arreglo != 0) {
            eliminarFicha(fichaMover, turnoDe, arreglo, arregloTurno,
                          arregloRecorrido, dado, i, puntosJugador);
          }
        }
        diferencia = 0;
        arregloTurno[turnoDe].posiciones.posicion4 =
            arregloRecorrido[i + dado].posicion_arreglo;
        printf("En la posición queda: %s \n",
               arreglo[arregloRecorrido[i + dado].posicion_arreglo]);

        if (i + dado >= 52)
          arregloTurno[turnoDe].posiciones.posicion4 =
              arregloRecorrido[i + dado - 52].posicion_arreglo;

        if (turnoDe == 0 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "R4";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 0) {
          diferencia = (52 - (i + dado));
          arreglo[arregloRecorrido[diferencia - 1].posicion_arreglo] = "R4";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 1 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AZ4";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 1) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "AZ4";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 2 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "V4";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 2) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "V4";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }

        if (turnoDe == 3 && i + dado < 52) {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AM4";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[i + dado].posicion_arreglo]);
          return;
        } else if (turnoDe == 3) {
          diferencia = ((i + dado) - 52);
          arreglo[arregloRecorrido[diferencia].posicion_arreglo] = "AM4";
          printf("En la posición queda: %s \n",
                 arreglo[arregloRecorrido[diferencia].posicion_arreglo]);
          return;
        }
        break;
      }
    }
  }
}

void eliminarFicha(int fichaMover, int turnoDe, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int dado, int i, puntos *puntosJugador) {
  int dondeEsta;

  // Si el jugador decide mover su ficha "1"
  if (fichaMover == 1) {

    eliminarFicha1(fichaMover, turnoDe, arreglo, arregloTurno, arregloRecorrido,
                   dado, i, puntosJugador);
  }
  // Si el jugador decide mover su ficha "2"
  if (fichaMover == 2) {
    eliminarFicha2(fichaMover, turnoDe, arreglo, arregloTurno, arregloRecorrido,
                   dado, i, puntosJugador);
  }
  // Si el jugador decide mover su ficha "3"
  if (fichaMover == 3) {
    eliminarFicha3(fichaMover, turnoDe, arreglo, arregloTurno, arregloRecorrido,
                   dado, i, puntosJugador);
  }
  // Si el jugador decide mover su ficha "4"
  if (fichaMover == 4) {
    eliminarFicha4(fichaMover, turnoDe, arreglo, arregloTurno, arregloRecorrido,
                   dado, i, puntosJugador);
  }
}
