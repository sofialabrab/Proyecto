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
  int contador = 0;
  
}

void Menu(List *listJugadores, char *arreglo[225],
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
        strcpy(jugador->color, "Amarillo");
        // Se guarda el jugador en la lista de jugadores
        pushBack(listJugadores, strdup(jugador->color));
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
        strcpy(jugador->color, "Azul");
        // Se guarda el jugador en la lista de jugadores
        pushBack(listJugadores, strdup(jugador->color));
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
        strcpy(jugador->color, "Rojo");
        pushBack(listJugadores, strdup(jugador->color));
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
        printf("%s\n", jugador->color);
        // Se guarda el jugador en la lista de jugadores
        strcpy(jugador->color, "Verde");
        pushBack(listJugadores, strdup(jugador->color));
        cont--;
        break;
      } else if (color == 4)
        printf("Color ocupado, elija otro color \n");
    }
  }

  EnJuego(arreglo, listJugadores, cantJugadores, arregloTurno,
          arregloRecorrido);
}
void mostrarTurno(int cantJugadores, int turnoDe, tipoJugador *arregloTurno) {
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


  while (tmp[i + 1] != '\0') {
    if (tmp[i] == '\"') {
      if (k == j)
        ret[i - ini_i] = 0;
      open_mark = 1 - open_mark;
    
      
      if (open_mark)
        ini_i = i + 1;
      
      i++;
      continue;
    }
   
    if (open_mark || tmp[i] != ',') {
   
      if (k == j)
        ret[i - ini_i] = tmp[i];
      
      i++;
      continue;
    }

   
    if (tmp[i] == ',') {
      
      if (k == j) {
        

        ret[i - ini_i] = '\0';
        return ret;
      }

      j++;
      ini_i = i + 1;
    }

    i++;
  }

  if (k == j) {
  
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
int turno(tipoJugador *arregloTurno, int jugador) {
  while (true) {
    if (jugador + 1 == 4)
      jugador = 0;
    else
      jugador++;
    do {
      if (arregloTurno[jugador].activo == true) {
        return jugador;
      } else if(jugador+1==4){
        jugador=0;
      }
      else{ jugador++;
      }
    } while (arregloTurno[jugador].activo == false);
    return jugador;
  }
}

void EnJuego(char *arreglo[225], List *listJugadores, int cantJugadores,
             tipoJugador *arregloTurno, tipoRecorrido *arregloRecorrido)
{
  bool ganador = false;
  int dado = 0;
  int fichaMover;
  int lanzamiento;
  int contadorSeis;
  int sentido=0;
  
  puntos * puntosJugador  = calloc(1,sizeof(puntos));
  int turnoDe = 0;
  List* listRectaFinal = createList();
  int vueltas =10; 
  
  tipoJugador *jugadores = (tipoJugador *)malloc(sizeof(tipoJugador));

  printf("----JUGADORES EN ESTA PARTIDA----\n\n");
  jugadores = firstList(listJugadores);
  int i = 1;
  while(jugadores != NULL)
  {
    printf("Jugador %i : %s\n", i, jugadores->color);
    jugadores = nextList(listJugadores);
    i++;
  }
  printf("\nCOMIENZA LA PARTIDA, BUENA SUERTE A TODOS!!!\n\n");
  turnoDe = primerJugador(arregloTurno, cantJugadores);
  imprimirTablero(arreglo); // solo se llama al inicio, es el tablero base.
  // vueltas
  while (vueltas > 0) 
  {
    printf("\nQUEDAN %d VUELTAS\n",vueltas);
    int contadorTurno = 0;
    while(contadorTurno <= cantJugadores)
    { 
      mostrarTurno(cantJugadores, turnoDe, arregloTurno);
      
      printf("Presione 0 para lanzar el dado\n");
      scanf("%d", &lanzamiento);
      printf("Se lanza el dado, Buena suerte!!!\n");
      dado = lanzarDado();
      contadorSeis=0;
      while(dado ==6 && contadorSeis <2){
        printf("Obtuvo un %d\n", dado);
        printf("Ingrese un 0 si desea mover su dado en sentido horario o ingrese 1 si desea mover su ficha en sentido antihorario\n");
        scanf(" %d",&sentido);
        if(sentido == 1) dado=dado*-1;
         printf("Seleccione el número de la ficha que desea mover: ");
      scanf("%d", &fichaMover);
        printf("\n\n");
        editarTablero(fichaMover, turnoDe, arreglo, arregloTurno,
                        arregloRecorrido, dado,puntosJugador);
        imprimirTablero(arreglo);
          contadorSeis++;
          if(contadorSeis<=2){
            printf("Presione 0 para lanzar el dado\n");
            scanf("%d", &lanzamiento);
            dado=lanzarDado();
            }
          
          
        }
      if(dado<6){
      printf("Obtuvo un %d\n", dado);
      printf("Ingrese un 0 si desea mover su dado en sentido horario o ingrese 1 si desea mover su ficha en sentido antihorario\n");
        scanf(" %d",&sentido);
        if(sentido == 1) dado=dado*-1;
      printf("Seleccione el número de la ficha que desea mover: ");
      scanf("%d", &fichaMover);
        printf("\n\n");
      editarTablero(fichaMover, turnoDe, arreglo, arregloTurno,
                      arregloRecorrido, dado,puntosJugador);
      imprimirTablero(arreglo);
        }
      turnoDe = turno(arregloTurno, turnoDe);
  
      contadorTurno++;
    }
    vueltas--;
  }
  MostrarGanadores(puntosJugador, cantJugadores);

  if(vueltas == 0)
    printf("Se acabó el juego, veamos los resultados finales! :)\n\n");
  
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

int lanzarDado() 
{
  int dado; 
  srand(time(NULL));
  dado = (rand() % (6 - 1 + 1) + 1);
  
  return dado;
}

int primerJugador(tipoJugador *arregloTurno, int cantJugadores) 
{
  int primero; // = (rand % 6)
  srand(time(NULL));
  do {
    primero = rand() % 4;
  } while (arregloTurno[primero].activo == false);
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
}

void MostrarGanadores(puntos * puntosJugador,int cantJugadores)
{
  
  ganador puntos[4];
  
  puntos[0].puntosJugador = puntosJugador->contRojo;
  strcpy(puntos[0].color, "Rojo") ;
  
  puntos[1].puntosJugador = puntosJugador->contAzul;
  strcpy(puntos[1].color, "Azul") ;
  
  puntos[2].puntosJugador = puntosJugador->contVerde;
  strcpy(puntos[2].color, "Verde") ;
  
  puntos[3].puntosJugador = puntosJugador->contAmarillo;
  strcpy(puntos[3].color, "Amarillo") ;
  ganador aux;

  for (int i = 0; i < (cantJugadores - 1); i++) 
  { 
    for (int j = i + 1; j < cantJugadores; j++) 
    { 
      if (puntos[j].puntosJugador > puntos[i].puntosJugador) 
      { 
        aux = puntos[j]; 
        puntos[j] = puntos[i]; 
        puntos[i] = aux; 
      } 
    } 
  } 
  printf("Posiciones:\n\n");
  for (int i = 0; i < (cantJugadores ); i++) 
  {
     printf("(%d) %s : %d\n",i+1, puntos[i].color , puntos[i].puntosJugador); 
  }
  if(puntos[0].color == puntos[1].color)
  {
    printf("Hubo empate en las primeras posiciones, mejor suerte la próxima vez\n");
  }
  else{
      printf("\n\nFELICIDADES AL GANADOR!!!\n%s : %d\n",puntos[0].color , puntos[0].puntosJugador);
  }
}