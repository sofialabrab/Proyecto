#include "fun.h"
#include "list.h"


void ModalidadTradicional(List * listJugadores, char* arreglo[225], tipoJugador* arregloTurno)
{
  for(int j= 0 ; j<4 ;j++)
  {
    arregloTurno[j].activo = false;
  }
  int cantJugadores;
  int color;
  
  tipoJugador * jugador = (tipoJugador*)malloc(sizeof(tipoJugador));
  while(true)
  {
    printf("Inserte la cantidad de jugadores\n");
    printf("El mínimo deben ser 2 y el máximo 4\n");
    scanf("%d", &cantJugadores);
    if(cantJugadores > 1 && cantJugadores < 5)
    {
      printf("Elección de colores: \n\n");
      printf("1 .- Amarillo\n");
      printf("2 .- Azul\n");
      printf("3 .- Rojo\n");
      printf("4 .- Verde\n");
      break;
    }
    else
    {
      printf("\nInserte otra cantidad\n");
    }
      
    
    printf("Elección de colores: \n\n");
    printf("1 .- Amarillo\n");
    printf("2 .- Azul\n");
    printf("3 .- Rojo\n");
    printf("4 .- Verde\n");

  }
    
  for(int i = 0; i < cantJugadores; i++)
  {
    while(true)
    {
    printf("\nJugador %d\n", i + 1);
    printf("Elija el color (ingrese número de la opcion): ");
    scanf("%d", &color);

      if(color == 1 && arregloTurno[3].activo == false)
      {
        printf("Color : Amarillo\n");
        arregloTurno[3].activo = true;
        strcpy(jugador->color, "amarillo");
        pushBack(listJugadores, jugador->color);
        break;
      }
      else if(color ==1) printf("Color ocupado, elija otro color \n"); 
  
      if(color == 2 && arregloTurno[1].activo == false)
      {
        printf("Color : Azul\n");
        arregloTurno[1].activo = true;
        strcpy(jugador->color, "azul");
        pushBack(listJugadores, jugador->color);
        break;
      }
      else if(color==2) printf("Color ocupado, elija otro color\n"); 
      
      if(color == 3 && arregloTurno[0].activo == false)
      {
        printf("Color : Rojo\n");
        arregloTurno[0].activo = true;

        strcpy(jugador->color, "rojo");
        pushBack(listJugadores, jugador->color);
        break;
      }
      else if(color==3) printf("Color ocupado, elija otro color \n");
      if(color == 4 && arregloTurno[2].activo == false)
      {
        printf("Color : Verde\n");
        arregloTurno[2].activo = true;

        strcpy(jugador->color, "verde");
        pushBack(listJugadores, jugador->color);
        break;
      }
      else if(color==4) printf("Color ocupado, elija otro color \n");
    }
  }
  for(int i = 0 ; i < 4 ; i++)
    {
      printf("%i\n", arregloTurno[i].activo);
    }
  EnJuego(arreglo , listJugadores, cantJugadores);
}
void mostrarTurno(int cantJugadores, int turnoDe)
{
  if(turnoDe == 0)
  {
    printf("Turno del Rojo"); return;
  }
  if(turnoDe == 1)
  {
    printf("Turno del Azul"); return;
  }if(turnoDe == 2)
  {
    printf("Turno del Verde"); return;
  }if(turnoDe == 3)
  {
    printf("Turno del Amarillo"); return;
  }
}

void EnJuego(char * arreglo[225], List * listJugadores, int cantJugadores)
{
  bool ganador = false;
  int dado = 0;
  //Qué color parte
  int turnoDe = primerJugador(cantJugadores);
 
  imprimirTablero(arreglo);

  //Turno
   /*while(cantJugadores > 1) 
  {
    //mostrar quien juega
    ///*mostrarTurno(cantJugadores, turnoDe);

    printf("Se lanza el dado\n");
    dado = lanzarDado();
    printf("%d\n",dado);
    //mostrar tablero
    imprimirTablero(arreglo);

    //avanzar ficha escogida
    
    //verificar ganador
    //quien sigue
    cantJugadores = cantJugadores-1;
  } */
  //Mostrar ganadores
}

void VisualizacionTablero(List * listJugadores)
{
  
}
void imprimirTablero(char* arreglo[225])
{
  int i,k;
  for(i = 0 ; i<15 ; i++)
    {
      for(k = 0 ; k<15 ; k++)
        {
          if(i<6 && k>8)
          {
            printf(" 1 ");
          }
          else
          {
            if(i<6 && k<6)
            {
              printf(" 1 ");
            }
            else
            {
              if(i>8 && k<6)
              {
                printf(" 1 ");
              }
              else
              {
                if(i>8 && k>8)
                {
                  printf(" 1 ");
                }
                else{
                  printf(" 0 ");
                }
              }
            }
            
          }
        }
      printf("\n");
    }
  
}

/*void imprimirMatriz(char* matriz[15][15],int cantJugadores)
{
  printf("\n");
  printf("\n");

  printf("                       |  TABLERO  |\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  int array[54] = {};
  printf("\n");
  
  for(int i = 0; i < 54; i++)
    printf("%d ",array[i]);
  printf("\n");
  
  for(int i = 0; i < 15; i++)
    {
      
      for(int j = 0; j < 15; j++)
        {
          if((i<6 && j < 6) || (i>8 && j < 6) || (i > 8 && j > 8) || (i < 6 && j > 8))
            matriz[i][j] = "  ";
          else 
            matriz[i][j] = "00";
        }
    }
  
  matriz[2][2] = "A1";
  matriz[2][3] = "A2";
  matriz[3][2] = "A3";
  matriz[3][3] = "A4";

  matriz[11][11] = "v1";
  matriz[11][12] = "v2";
  matriz[12][11] = "v3";
  matriz[12][12] = "v4";

  matriz[2][11] = "r1";
  matriz[2][12] = "r2";
  matriz[3][11] = "r3";
  matriz[3][12] = "r4";

  matriz[11][2] = "a1";
  matriz[11][3] = "a2";
  matriz[12][2] = "a3";
  matriz[12][3] = "a4";    

  for(int i = 0; i < 15; i++)
  {
    
    for(int j = 0; j < 15; j++)
      {
        printf(" %s ",matriz[i][j]); 
      }
    printf("\n");
    printf("\n");
  }
}*/
int lanzarDado()
{
  int dado;// = (rand % 6)
  srand(time(NULL));
  dado = (rand () % (6-1+1) + 1);
  printf("%d \n", dado);
  return dado;
}


int primerJugador(int cantJugadores)
{
  int primero;// = (rand % 6)
  srand(time(NULL));
  primero = (rand () % (cantJugadores-1+1) + 1);
  if(primero==0) printf("COMIENZA EL JUGADOR ROJO");
  if(primero==1) printf("COMIENZA EL JUGADOR AZUL");
  if(primero==2) printf("COMIENZA EL JUGADOR VERDE");
  if(primero==3) printf("COMIENZA EL JUGADOR AMARILLO");
  //printf("\n\nComienza el jugador numero %d \n", primero);
printf("\n");
  return primero;
  // ROJO AZUL VERDE AMARILLO 
}

/*void esGanador()
{
  
  
}*/
/*
 VOID FUNCION PARA INSULTAR(SOFIA, SEBA, MAITE, JAVIER)
{
PORFAVOR ANOTE SU NOMBRE ANTES DE SU MENSAJE
Javier: SOFIA VAS A CLASES MAÑANA? 
SOFia: no ir
javier:  opina
Sofia: pa que si ni me pescan
javier: estamos todo,s ahora pendientes a tu
Sofia: ve arriba
Arturo: ola arreglé todo
Javier: deja de pelarte
)
RETURN AMOR Y PAZ;

}
*/

