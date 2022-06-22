#include "fun.h"
#include "list.h"
// arreglo de 225 posiciones, es el tablero
void crearTablero(char *arreglo[225]) {
  // ciclo posiciona los jugadores en sus bases iniciales
  for (int j = 0; j < 225; j++) {
    if (j == 32)
      arreglo[j] = "R1";
    else if (j == 33)
      arreglo[j] = "R2";
    else if (j == 47)
      arreglo[j] = "R3";
    else if (j == 48)
      arreglo[j] = "R4";
    else if (j == 41)
      arreglo[j] = "V1";
    else if (j == 42)
      arreglo[j] = "V2";
    else if (j == 56)
      arreglo[j] = "V3";
    else if (j == 57)
      arreglo[j] = "V4";
    else if (j == 176)
      arreglo[j] = "AM1";
    else if (j == 177)
      arreglo[j] = "AM2";
    else if (j == 191)
      arreglo[j] = "AM3";
    else if (j == 192)
      arreglo[j] = "AM4";
    else if (j == 167)
      arreglo[j] = "AZ1";
    else if (j == 168)
      arreglo[j] = "AZ2";
    else if (j == 182)
      arreglo[j] = "AZ3";
    else if (j == 183)
      arreglo[j] = "AZ4";
    else
      // Espacios en blanco en las bases de el tablero
      arreglo[j] = " ";
  }
  // doble ciclo guarda los "0"
  for (int i = 0; i < 15; i++) {
    for (int k = 0; k < 15; k++) {
      if (k == 6 || k == 8)
        arreglo[i * 15 + k] = "0";
      else if (i == 6 || i == 8)
        arreglo[i * 15 + k] = "0";
    }
  }
  // Posiciones especificas etapa final de cada jugador
  arreglo[7] = "0";
  arreglo[105] = "0";
  arreglo[119] = "0";
  arreglo[217] = "0";
  arreglo[97] = " ";
  arreglo[127] = " ";

  // Casos especificos de el tablero
  arreglo[96] = " ";
  arreglo[111] = " ";
  arreglo[126] = " ";
  arreglo[98] = " ";
  arreglo[113] = " ";
  arreglo[128] = " ";
  int contador=0;
  for (int o=0 ; o<15 ;o++)
    {
      for(int p=0; p<15 ; p++)
        {
          printf(" %3d ", contador );
          contador++;
        }
      printf("\n");
    }
 
}

void ModalidadTradicional(List *listJugadores, char *arreglo[225],
                          tipoJugador *arregloTurno,
                          tipoRecorrido *arregloRecorrido) {
  // arreglo turno: arreglo que contiene el orden de turno de los jugadores
  // arregloRecorrido: arreglo que contiene las posiciones donde se pueden mover
  // los jugadores
  // Todos los jugadores se inicializan inactivos previo a la partida
  for (int j = 0; j < 4; j++) {
    arregloTurno[j].activo = false;
  }
  int cantJugadores;
  int color;
  tipoJugador *jugador = (tipoJugador *)malloc(sizeof(tipoJugador));
  // Elegir cantidad y color de los jugadores
  while (true) {
    printf("Inserte la cantidad de jugadores\n");
    printf("El mínimo deben ser 2 y el máximo 4\n");
    scanf("%d", &cantJugadores);
    if (cantJugadores > 1 && cantJugadores < 5) {
      printf("Elección de colores: \n\n");
      printf("1 .- Amarillo\n");
      printf("2 .- Azul\n");
      printf("3 .- Rojo\n");
      printf("4 .- Verde\n");
      break;
    } else {
      printf("\nInserte otra cantidad\n");
    }
    printf("Elección de colores: \n\n");
    printf("1 .- Amarillo\n");
    printf("2 .- Azul\n");
    printf("3 .- Rojo\n");
    printf("4 .- Verde\n");
  }
  int cont = cantJugadores;

  for (int i = 0; i < cantJugadores; i++) {

    while (cont > 0) {
      printf("\nJugador %d\n", i + 1);
      printf("Elija el color (ingrese número de la opcion): ");
      scanf("%d", &color);

      if (color == 1 && arregloTurno[3].activo == false) {
        printf("Color : Amarillo\n");
        // Se inicializa el color como activo y se asignan sus posiciones bases
        arregloTurno[3].activo = true;
        arregloTurno[3].posiciones.posicion1 = 176;
        arregloTurno[3].posiciones.posicion2 = 177;
        arregloTurno[3].posiciones.posicion3 = 191;
        arregloTurno[3].posiciones.posicion4 = 192;
        strcpy(jugador->color, "amarillo");
        // Se guarda el jugador en la lista de jugadores
        pushBack(listJugadores, jugador->color);
        cont--;
        break;
      } else if (color == 1)
        printf("Color ocupado, elija otro color \n");

      if (color == 2 && arregloTurno[1].activo == false) {
        printf("Color : Azul\n");
        // Se inicializa el color como activo y se asignan sus posiciones bases
        arregloTurno[1].activo = true;
        arregloTurno[1].posiciones.posicion1 = 167;
        arregloTurno[1].posiciones.posicion2 = 168;
        arregloTurno[1].posiciones.posicion3 = 182;
        arregloTurno[1].posiciones.posicion4 = 183;
        strcpy(jugador->color, "azul");
        // Se guarda el jugador en la lista de jugadores
        pushBack(listJugadores, jugador->color);
        cont--;
        break;
      } else if (color == 2)
        printf("Color ocupado, elija otro color\n");

      if (color == 3 && arregloTurno[0].activo == false) {
        printf("Color : Rojo\n");
        // Se inicializa el color como activo y se asignan sus posiciones bases
        arregloTurno[0].activo = true;
        arregloTurno[0].posiciones.posicion1 = 32;
        arregloTurno[0].posiciones.posicion2 = 33;
        arregloTurno[0].posiciones.posicion3 = 47;
        arregloTurno[0].posiciones.posicion4 = 48;
        // Se guarda el jugador en la lista de jugadores
        strcpy(jugador->color, "rojo");
        pushBack(listJugadores, jugador->color);
        cont--;
        break;
      } else if (color == 3)
        printf("Color ocupado, elija otro color \n");
      if (color == 4 && arregloTurno[2].activo == false) {
        printf("Color : Verde\n");
        arregloTurno[2].activo = true;
        arregloTurno[2].posiciones.posicion1 = 41;
        arregloTurno[2].posiciones.posicion2 = 42;
        arregloTurno[2].posiciones.posicion3 = 56;
        arregloTurno[2].posiciones.posicion4 = 57;
        strcpy(jugador->color, "verde");
        // Se guarda el jugador en la lista de jugadores
        pushBack(listJugadores, jugador->color);
        cont--;
        break;
      } else if (color == 4)
        printf("Color ocupado, elija otro color \n");
    }
  }
  for (int i = 0; i < 4; i++) {
    printf("%i\n", arregloTurno[i].activo);
  }
  EnJuego(arreglo, listJugadores, cantJugadores, arregloTurno,
          arregloRecorrido);
}
void mostrarTurno(int cantJugadores, int turnoDe, tipoJugador *arregloTurno) {
  // nota : avanzar en el turno
  if (turnoDe == 0) {
    printf("Turno del Rojo\n");
    return;
  }
  if (turnoDe == 1) {
    printf("Turno del Azul\n");
    return;
  }
  if (turnoDe == 2) {
    printf("Turno del Verde\n");
    return;
  }
  if (turnoDe == 3) {
    printf("Turno del Amarillo\n");
    return;
  }
}
// Función que lee el archivo
char *get_csv_field(char *tmp, int k) {
  int open_mark = 0;
  char *ret = (char *)malloc(100 * sizeof(char));
  int ini_i = 0, i = 0;
  int j = 0;

  // tmp: string de llegada
  // k: subcampo a obtener
  // mientras el siguiente caracter no sea nulo
  while (tmp[i + 1] != '\0') {
    // si el caracter es comilla
    if (tmp[i] == '\"') {
      if (k == j)
        ret[i - ini_i] = 0;
      // da vuelta openMark
      open_mark = 1 - open_mark;
      // si es la primer comilla
      // guardamos en ini_i el inicio despues
      // de la comilla
      if (open_mark)
        ini_i = i + 1;
      // avanzamos
      i++;
      continue;
    }
    // si estamos dentro de una comilla ó
    // la casilla actual NO es una coma
    if (open_mark || tmp[i] != ',') {
      // si el subcampo a obtener es el que
      // buscamos
      //      guardamos la letra en la posicion actual menos
      //      la posicion de la comilla
      if (k == j)
        ret[i - ini_i] = tmp[i];
      // avanzamos
      i++;
      continue;
    }

    // si estamos en una coma
    if (tmp[i] == ',') {
      // si estamos en el subcampo que queremos
      if (k == j) {
        // terminamos el string y lo retornamos

        ret[i - ini_i] = '\0';
        return ret;
      }

      // avanzamos el subcampo actual (j)
      // avanzamos ini_i una posicion despues de la coma

      j++;
      ini_i = i + 1;
    }

    i++;
  }
  //  si estamos en el subcampo que queremos
  if (k == j) {
    // devolvemos el string
    ret[i - ini_i] = 0;
    return ret;
  }

  return NULL;
}
// Crea el arreglo con las posiciones donde se pueden mover los jugadores
void crearRecorrido(tipoRecorrido *arregloRecorrido) {
  FILE *recorrido = fopen("recorrido.csv", "r");
  char linea[1024];
  int posicion;
  int cont = 0;
  
  while (fgets(linea, 1023, recorrido) != NULL) {
    for (int i = 0; i < 52; i = i + 1) {
      char *aux = get_csv_field(linea, i);
      posicion = atoi(aux);
      arregloRecorrido[cont].posicion_arreglo = posicion;
      cont++;
    }
  }
  fclose(recorrido);
}
void editarTablero(int fichaMover, int turnoDe, char *arreglo[225],
                   tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido,
                   int dado) {
  int dondeEsta;
  int diferencia = 0;
  // printf("%d   DADOO\n", dado);
  // printf("%d  TURNOOO\n", turnoDe);

  // Si el jugador decide mover su ficha "1"
  if (fichaMover == 1) {
    // CASOS ESPECIFICOS, salir de la base
    if ((turnoDe == 0) && (strcmp(arreglo[32], "R1") == 0) && (dado == 6)) {
      arreglo[32] = "0";
      arreglo[91] = "R1";
      arregloTurno[turnoDe].posiciones.posicion1 = 91;
      return;

    } else if ((turnoDe == 1) && (strcmp(arreglo[167], "AZ1") == 0) &&
               (dado == 6)) {
      arreglo[167] = "0";
      arreglo[201] = "AZ1";
      arregloTurno[turnoDe].posiciones.posicion1 = 201;
      return;
    } else if ((turnoDe == 2) && (strcmp(arreglo[41], "V1") == 0) &&
               (dado == 6)) {
      arreglo[41] = "0";
      arreglo[23] = "V1";
      arregloTurno[turnoDe].posiciones.posicion1 = 23;
      return;
    } else if ((turnoDe == 3) && (strcmp(arreglo[176], "AM1") == 0) &&
               (dado == 6)) {
      arreglo[176] = "0";
      arreglo[133] = "AM1";
      arregloTurno[turnoDe].posiciones.posicion1 = 133;
      return;
      // hola
    }
    // Casos en juego
    dondeEsta = arregloTurno[turnoDe].posiciones.posicion1;
    for (int i = 0; i < 52; i++) {
      // Compara en que posicion del arreglo del recorrido estoy
      if (arregloRecorrido[i].posicion_arreglo == dondeEsta) {
        // actualiza la casilla de donde sali a "0"
        arreglo[arregloTurno[turnoDe].posiciones.posicion1] = "0";
        // Si entra al if, se sabe que existe alguna ficha en la posición
        /*if(arregloRecorrido[i + dado].posicion_arreglo != 0)
        {
          //Moviendo ficha 1 de el azul
          if(turnoDe == 1)
          {
            //Sabemos que en la posicion a mover hay una ficha de el mismo
        jugador \
            //i+dado == AZ
            // poner AZ1,2
            char *ficha[2];
            for(int i = 0; i < 3; i++)
            {
              strcpy(ficha[i], arreglo[arregloRecorrido[i +
        dado].posicion_arreglo]);
            }
            int numficha = atoi(ficha[2]);
            printf("%d numero\n",numficha);
            if(strcmp(ficha[1], "Z") == 0 )
            {
              //Extraer el numero de ficha
              printf("En la casilla marcada como - AZ1,2 - se encuentran sus
        fichas AZ1 y AZ2\n"); printf("Elija que ficha desea mover\n");
              scanf("%i", &fichaMover);
              if(fichaMover == 1)
              {

              }
            }
           }
          }*/

        // Muevo a el jugador la cantidad de casillas que me dijo el dado
        arregloTurno[turnoDe].posiciones.posicion1 =
            arregloRecorrido[i + dado].posicion_arreglo;
        // Dependiendo de quien haya sido el jugador, se actualiza la casilla
        // con el jugador en la posicion
        if (turnoDe == 0 && i+dado<52)
        {arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "R1";
          return;}
        if (turnoDe == 1 && i+dado<52)
        {arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AZ1";
          return;}
        
        if (turnoDe == 2 && i+dado<52)
        {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "V1";
          return;
        }
      
        if (turnoDe == 3 && i+dado<52)
          {arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AM1";
          return;}
        break;
      }
    }
  }
  // Si el jugador decide mover su ficha "2"
  if (fichaMover == 2) {
    // CASOS ESPECIFICOS, salir de la base
    if ((turnoDe == 0) && (strcmp(arreglo[33], "R2") == 0) && dado == 6) {
      arreglo[33] = "0";
      arreglo[91] = "R2";
      arregloTurno[turnoDe].posiciones.posicion2 = 91;
      return;
    } else if ((turnoDe == 1) && (strcmp(arreglo[168], "AZ2") == 0) &&
               dado == 6) {
      arreglo[168] = "0";
      arreglo[201] = "AZ2";
      arregloTurno[turnoDe].posiciones.posicion2 = 201;
      return;
    } else if ((turnoDe == 2) && (strcmp(arreglo[42], "V2") == 0) &&
               dado == 6) {
      arreglo[42] = "0";
      arreglo[23] = "V2";
      arregloTurno[turnoDe].posiciones.posicion2 = 23;
      return;
    } else if ((turnoDe == 3) && (strcmp(arreglo[177], "AM2") == 0) &&
               dado == 6) {
      arreglo[177] = "0";
      arreglo[133] = "AM2";
      arregloTurno[turnoDe].posiciones.posicion2 = 133;
      return;
    }
    dondeEsta = arregloTurno[turnoDe].posiciones.posicion2;
    // Casos en juego
    for (int i = 0; i <52; i++) {
      if (arregloRecorrido[i].posicion_arreglo == dondeEsta) {
        arreglo[arregloTurno[turnoDe].posiciones.posicion2] = "0";
        arregloTurno[turnoDe].posiciones.posicion2 =
            arregloRecorrido[i + dado].posicion_arreglo;
        if (turnoDe == 0 && i+dado<52)
        {arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "R2";
          return;}

        if (turnoDe == 1 && i+dado<52)
        {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AZ2";
          return;
        }

        if (turnoDe == 2 && i+dado<52)
        {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "V2";
          return;
          }
       if (turnoDe == 3 && i+dado<52)
        {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AM2";
          return;
          }

        break;
      }
    }
  }
  // Si el jugador decide mover su ficha "3"
  if (fichaMover == 3) {
    // CASOS ESPECIFICOS, salir de la base
    if ((turnoDe == 0) && (strcmp(arreglo[47], "R3") == 0) && dado == 6) {
      arreglo[47] = "0";
      arreglo[91] = "R3";
      arregloTurno[turnoDe].posiciones.posicion3 = 91;
      return;
    } else if ((turnoDe == 1) && (strcmp(arreglo[182], "AZ3") == 0) &&
               dado == 6) {
      arreglo[182] = "0";
      arreglo[201] = "AZ3";
      arregloTurno[turnoDe].posiciones.posicion3 = 201;
      return;
    } else if ((turnoDe == 2) && (strcmp(arreglo[56], "V3") == 0) &&
               dado == 6) {
      arreglo[56] = "0";
      arreglo[23] = "V3";
      arregloTurno[turnoDe].posiciones.posicion3 = 23;
      return;
    } else if ((turnoDe == 3) && (strcmp(arreglo[191], "AM3") == 0) &&
               dado == 6) {
      arreglo[191] = "0";
      arreglo[133] = "AM3";
      arregloTurno[turnoDe].posiciones.posicion3 = 133;
      return;
    }

    dondeEsta = arregloTurno[turnoDe].posiciones.posicion3;
    // Casos en juego
    for (int i = 0; i < 52; i++) {
      if (arregloRecorrido[i].posicion_arreglo == dondeEsta) {
        arreglo[arregloTurno[turnoDe].posiciones.posicion3] = "0";
        arregloTurno[turnoDe].posiciones.posicion3 =
            arregloRecorrido[i + dado].posicion_arreglo;
        if (turnoDe == 0 && i+dado<52)
        {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "R3";
          return;
          }

        if (turnoDe == 1 && i+dado<52)
        {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AZ3";
          return;
          }

        if (turnoDe == 2 && i+dado<52)
        {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "V3";
          return;
          }

        if (turnoDe == 3 && i+dado<52) 
        { 
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AM3";
          return;
          }
        break;
      }
    }
  }
  // Si el jugador decide mover su ficha "4"
  if (fichaMover == 4) {
    // CASOS ESPECIFICOS, salir de la base
    if ((turnoDe == 0) && (strcmp(arreglo[48], "R4") == 0) && dado == 6) {
      arreglo[48] = "0";
      arreglo[91] = "R4";
      arregloTurno[turnoDe].posiciones.posicion4 = 91;
      return;
    } else if ((turnoDe == 1) && (strcmp(arreglo[183], "AZ4") == 0) &&
               dado == 6) {
      arreglo[183] = "0";
      arreglo[201] = "AZ4";
      arregloTurno[turnoDe].posiciones.posicion4 = 201;
      return;
    } else if ((turnoDe == 2) && (strcmp(arreglo[57], "V4") == 0) &&
               dado == 6) {
      arreglo[57] = "0";
      arreglo[23] = "V4";
      arregloTurno[turnoDe].posiciones.posicion4 = 23;
      return;
    } else if ((turnoDe == 3) && (strcmp(arreglo[192], "AM4") == 0) &&
               dado == 6) {
      arreglo[192] = "0";
      arreglo[133] = "AM4";
      arregloTurno[turnoDe].posiciones.posicion4 = 133;
      return;
    }
    dondeEsta = arregloTurno[turnoDe].posiciones.posicion4;
    // Casos en juego
    for (int i = 0; i < 52; i++) {
      if (arregloRecorrido[i].posicion_arreglo == dondeEsta) {
        arreglo[arregloTurno[turnoDe].posiciones.posicion4] = "0";
        arregloTurno[turnoDe].posiciones.posicion4 =
            arregloRecorrido[i + dado].posicion_arreglo;
        if (turnoDe == 0 && i+dado<52 )
        {  
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "R4";
        return;
          }
      
        if (turnoDe == 1 && i+dado<52 )
        {
          arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AZ4";
          return;
          }
      
        if (turnoDe == 2 && i+dado<52)
        {arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "V4";
          return;}
      
        if (turnoDe == 3 && i+dado<52)
        {arreglo[arregloRecorrido[i + dado].posicion_arreglo] = "AM4";
          return;}
            
        break;
      }
    }
  }
}

void EnJuego(char *arreglo[225], List *listJugadores, int cantJugadores,
             tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido) {
  bool ganador = false;
  int dado = 0;
  int fichaMover;
  int lanzamiento;
  int contadorSeis;
  int turnoDe = 0;
  // Qué color parte
  turnoDe = primerJugador(arregloTurno, cantJugadores);
  imprimirTablero(arreglo); // solo se llama al inicio, es el tablero base.
  // Turno
  while (cantJugadores > 1) {
    // mostrar quien juega
    mostrarTurno(cantJugadores, turnoDe, arregloTurno);
    printf("Presione 0 para lanzar el dado\n");
    scanf("%d", &lanzamiento);
    printf("Se lanza el dado, Buena suerte!!!\n");
    dado = lanzarDado();
    // printf("Obtuvo un %d\n", dado);

    contadorSeis = 0;
    // Caso 1 -> Especifico, para salir de base y poder repetir turno
    while (dado == 6 && contadorSeis < 2) {
      printf("Obtuvo un %d\n", dado);
      printf("Seleccione el número de la ficha que desea mover, si esta se "
             "encuentra en la base, saldrá de ella\n");
      scanf("%d", &fichaMover);
      contadorSeis++;
      editarTablero(fichaMover, turnoDe, arreglo, arregloTurno,
                    arregloRecorrido, dado);
      imprimirTablero(arreglo);
      printf("Presione 0 para lanzar el dado\n");
      scanf("%d", &lanzamiento);
      dado = lanzarDado();
      if (dado != 6)
        break;
    }

    // Caso 2 -> Caso comun, dado es >= 1 o < a 6
    if (dado < 6) {
      printf("Obtuvo un %d\n", dado);
      printf("Seleccione el número de la ficha que desea mover ");
      if (turnoDe == 0)
        printf("R1, R2, R3, R4\n");
      if (turnoDe == 1)
        printf("AZ1, AZ2, AZ3, AZ4\n");
      if (turnoDe == 2)
        printf("V1, V2, V3, V4\n");
      if (turnoDe == 3)
        printf("AM1, AM2, AM3, AM4\n");
    }
    scanf("%d", &fichaMover);
    editarTablero(fichaMover, turnoDe, arreglo, arregloTurno, arregloRecorrido,
                  dado);
    // printf("PASO EDITAR TABLERO\n");
    imprimirTablero(arreglo);

    // avanzar ficha escogida

    // verificar ganador

    // quien sigue
    turnoDe = turno(arregloTurno, turnoDe);
  }
  // Mostrar ganadores
}
int turno(tipoJugador *arregloTurno, int jugador) {
  while (true) {
    if (jugador + 1 == 4)
      jugador = 0;
    else
      jugador++;
    if (arregloTurno[jugador].activo == 1) {
      return jugador;
      break;
    }
  }
  return jugador;
}
void imprimirTablero(char *arreglo[225]) {
  int contadorLinea = 0;
  for (int k = 0; k < 225; k++) {
    printf("  %3s ", arreglo[k]);
    contadorLinea++;
    if (contadorLinea == 15) {
      printf("\n");
      contadorLinea = 0;
    }
  }
}

int lanzarDado() {
  int dado; // = (rand % 6)
  srand(time(NULL));
  dado = (rand() % (6 - 1 + 1) + 1);
  // printf("%d  \n", dado);
  return dado;
}

int primerJugador(tipoJugador *arregloTurno, int cantJugadores) {
  int primero; // = (rand % 6)
  srand(time(NULL));
  do {
    primero = (rand() % (cantJugadores - 1 + 1) + 1);
    }while (arregloTurno[primero].activo == false);
      // primero = turno(arregloTurno, primero);
      if (primero == 0)
        printf("COMIENZA EL JUGADOR ROJO");
    if (primero == 1)
      printf("COMIENZA EL JUGADOR AZUL");
    if (primero == 2)
      printf("COMIENZA EL JUGADOR VERDE");
    if (primero == 3)
      printf("COMIENZA EL JUGADOR AMARILLO");

    printf("\n");
    return primero;
    // ROJO AZUL VERDE AMARILLO
  }

  //void comerFicha(tipoJugador * arregloTurno, char *arreglo[225]) {}
  //void esGanador()
 
