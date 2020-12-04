/*
*	Archivo: proyecto2.0.c
*	Autores: Rubén Lozano Larrea
*			 Wilson Enriquez Saldana
*			 Irwin Viteri Rambay 			
*	Fecha de creación:	2010-08-15 
*	Fecha de modificacion:	2010-09-02
*	HORA: 01:51 am
*	Descripcion:
*	El juego de mesa conocido como serpientes y escaleras es un juego de azar jugado sobre un 
*	tablero con casillas ilustrado sobre el que los participantes compiten por llegar en primer lugar a
*	la meta. Su principal característica son los dibujos de escaleras  y de serpientes que indican si
*	el participante ha de subir o bajar, respectivamente, dependiendo si su turno, al mover su ficha,
*	lo ha llevado a caer en una casilla que indica el inicio de la escalera o una casilla que coincide
*	con el extremo de una de las serpientes.
*/



												/************************************
												*			LIBRERIAS				*
												************************************/

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>

												/************************************
												*			CONSTANTES				*
												************************************/


#define MAX 2 //número de jugadores
#define MAX2 20//numero maximo que acepta la cadena nombre
#define GANA 50//Ultimo número del tablero
#define ESCALERA_UNO 4//Avanza a la cassilla 12
#define ESCALERA_DOS 8//Avanza a la cassilla 30
#define ESCALERA_TRES 15//Avanza a la cassilla 45
#define SERPIENTE_UNO 31//Retrocede a la casilla 13
#define SERPIENTE_DOS 46//Retrocede a la casilla 43
#define SERPIENTE_TRES 48//Retrocede a la casilla 6
#define NUM_SoE  6  //Numeros de casillas con comodines
#define PARTIDAS 5	//Numero de turnos para que el usuario pueda pedir salir o no

typedef enum
{
	false,true
}bool;
typedef enum
{
	UN_JUG=1,DOS_JUG
}jugadoresT;
typedef enum
{
	DEFINIR=1,SORTEAR,NUEVO,CONTINUAR,SALIR
}menuPrincipalT;
typedef{s[80];};


												/************************************
												*			PROTOTIPOS				*
												************************************/

void mostrar_posiciones(int valor[],int casilla);//Muestra las posiciones y el jugador que mas haya avanzado en el tablero. 
void ganador(int turno,int jugadas,char *s);//Muestra el ganador del juego.
void mostrar_dados(int dado_1,int dado_2);
void encerar(int valor[],int casilla);//Llena el tablero con 1.
void posicionJugador(int jugador);//Indica La posicion donde cae cada jugador ya sea sepiente o escalera.
void mostrar_dado(int dado_1);
void dibujaTablero(void);
void menuPrincipal(void);
void bienvenido(void);
void Continuar(void);
void Guardar(void);
void dibujo_EyS();

bool esEsc_SER(int casilla);//Verifica si el jugador se encuentra en una casilla de serpiente o una de escalera

int aumentar_jugada(int turno,int tam,int num_jug);//Cuenta el numero de jugadas realizadas por los jugadores
int sgt_turno(int turno,int tam);//Verifica quien es el jugador que comienza
int primerJugador(void);
int lanzarDado(void);
int pasos();

												/************************************
												*	  PROGRAMA PRINCIPAL        *
												************************************/

void main()
{	

												/************************************
												*	      VARIABLES	            *
												************************************/

	int opcion,turno,avanza,num_jugadas,fin;
	int jugador[MAX];
	int contador[MAX];
	int a=0,b=0,c=0;
	char nom_jugador[MAX2];
	char nom_jugador2[MAX2];
												/************************************
												*	CUERPO DEL PROGRAMA         *
												************************************/


srand(time(NULL));
bienvenido();
do{
	do{
			system("cls");
			menuPrincipal();
			scanf("%d",& opcion);
	}while(opcion<UN_JUG || opcion>SALIR);

switch(opcion)
{
	
case DEFINIR://Opcion que define el numero de jugadores
		a=definirJugadores();
	break;

case SORTEAR://Sortea entre dos juagadores 
	
		if((a==0) && (b==0) && (c==0))
		{	
			system("cls");
			printf("No se puede sortear mientras no defina jugadores");
		}else{
			c=primerJugador();
			if(a==2 && c!=0)
			{
				printf("EL SORTEO SALIO: %d\n",c);
				printf("\nEl jugador %d sera el primero en tirar",c);
			}else{
				if(c==0)
				{	
					system("cls");
				printf("EL SORTEO SALIO: %d\n",c);
				printf("\nVUELVAN A SORTEAR");
				}
			}
			if(a==1)
			{	
				system("cls");
				printf("\n\tNO SE SORTEA TURNO PARA UN JUGADOR");	
			}
			
		}
			getch();
				break;

case NUEVO://Opcion inicia el juego

			do{
		switch(a)
		{		
									/***********CASO DE SER 1 JUGADOR**************/
			case UN_JUG:
					turno=0;
					encerar(jugador,a);
					num_jugadas=1;
					printf("\n\t\t\tJUGARAN %d PERSONAS",a);
					printf("\n\n\t\t\tIngrese nombre del jugador:");
					scanf("%s",nom_jugador);
					getch();
						do	
						{
							system("cls");
							printf("\t\tjugada numero:%d\n\n",num_jugadas);
							mostrar_posiciones(jugador,a);
							printf("\nJUGADOR:%d, %s\n",turno+1,nom_jugador);
								
if(jugador[turno]!=4 && jugador[turno]!=8 && jugador[turno]!=15 && jugador[turno]!=31 && jugador[turno]!=46 && jugador[turno]!=48)
								{													 
								//Si esta en una de estás casillas la variable con dicho nombre está con el valor de 1
									contador[turno]=0;
									printf("\nTirar DADO\n");
									getch();
									avanza=pasos();
									printf("\navance %d\n\n",avanza);
									jugador[turno]=jugador[turno]+avanza;
									posicionJugador(jugador[turno]);
									switch(jugador[turno])//Identifica la casilla en la que se encuentra el jugador 
									{					  //poniendo la penitencia correspondiente
									
									case ESCALERA_UNO:
										jugador[turno]=12;
										break;
									case ESCALERA_DOS:
										jugador[turno]=30;
										break;
									case ESCALERA_TRES:
										jugador[turno]=45;
										break;
									case SERPIENTE_UNO:
										jugador[turno]=13;
										break;
									case SERPIENTE_DOS:
										jugador[turno]=43;
										break;
									case SERPIENTE_TRES:
										jugador[turno]=6;
										break;
									default:
										break;								
									}						
								}
							getch();
							
							if((jugador[turno]<GANA))//verifico si el jugador esta en la última casilla
							{						
								turno=sgt_turno(turno,a);//si no lo está se pasa el turno al siguiente jugador	
							num_jugadas=aumentar_jugada(turno,a,num_jugadas);//Si estoy en la último casilla jugador se aumenta el número de jugadas realizadas
							}
							
						}while(jugador[turno]<GANA);//Si el jugador en turno no está en la última casilla se repite el juego dando el turno al siguiente jugador
							ganador(turno,num_jugadas,nom_jugador);						
				break;
				
				
										/***********CASO DE SER 2 JUGADORES************/
			  case DOS_JUG:
				  	turno=0;
					encerar(jugador,a);
					num_jugadas=1;
		if(c==0)
		{	
            printf("\n\t\tNO SE PUEDE JUGAR MIENTRAS NO REALICE EL SORTEO");	
            }else{	
				    printf("\n\t\t\tJUGARAN %d PERSONAS\n",a);	
				    do{
						system("cls");
						printf("\nIngrese nombre 1er jugador:");
						scanf("%s",nom_jugador);
						printf("\nIngrese nombre 2do jugador:");
						scanf("%s",nom_jugador2);
					}while(strstr(nom_jugador,nom_jugador2)!=NULL);
					getch();
						do	
						{
						
							system("cls");
							printf("\t\tjugada numero:%d\n\n",num_jugadas);
							mostrar_posiciones(jugador,a);
							if(c==1)
							{
								b=turno+1;
								if(b==1)
								{
									printf("\nJUGADOR:%d, %s\n",b,nom_jugador);
								}else{
									printf("\nJUGADOR:%d, %s\n",b,nom_jugador2);
								}
							}else{
								if(c==2)
								{
									b=turno+c;
									if(b==2)
									{
										printf("\nJUGADOR:%d, %s\n",b,nom_jugador2);
									}else{
										printf("\nJUGADOR:%d, %s\n",b-2,nom_jugador);
									}
								}
							}
if(jugador[turno]!=4 && jugador[turno]!=8 && jugador[turno]!=15 && jugador[turno]!=31 && jugador[turno]!=46 && jugador[turno]!=48)
					//se verifica si está en las casillas Escalera o Serpiente
								{
									//si esta en una de estás casillas la variable con dicho nombre está con el valor de 1
									contador[turno]=0;
									printf("\nTirar DADO\n");
									getch();
									avanza=pasos();
									printf("\navance %d\n\n",avanza);
									jugador[turno]=jugador[turno]+avanza;
									posicionJugador(jugador[turno]);
									switch(jugador[turno])//identifica la casilla en la que se encuentra el jugador 
									{					  //poniendo la penitencia correspondiente
									
									case ESCALERA_UNO:
										jugador[turno]=12;
										break;
									case ESCALERA_DOS:
										jugador[turno]=30;
										break;
									case ESCALERA_TRES:
										jugador[turno]=45;
										break;
									case SERPIENTE_UNO:
										jugador[turno]=13;
										break;
									case SERPIENTE_DOS:
										jugador[turno]=43;
										break;
									case SERPIENTE_TRES:
										jugador[turno]=6;
										break;
									default:
										break;									
									}						
								}
							getch();
							
							if((jugador[turno]<GANA))//verifico si el jugador esta en la última casilla
							{						
								turno=sgt_turno(turno,a);//si no lo está se pasa el turno al siguiente jugador	
								num_jugadas=aumentar_jugada(turno,a,num_jugadas);//si estoy en el último jugador se aumenta el número de jugadas realizadas
							}
						
						}while(jugador[turno]<GANA);//si el jugador en turno no está en la última casilla se repite el juego dando el turno al siguiente jugador

								if(c==1)				
								{
									   ganador(turno,num_jugadas,nom_jugador);
								}else{
									   if(c==2)
									{
   										turno=b;
   										if(turno==2)
										   {
										ganador(b-1,num_jugadas,nom_jugador2);					
										}else{
										ganador(b-turno,num_jugadas,nom_jugador);
										}
									}
								 }	
         
         
         }					
	
				break;
			default:
				system("cls");
				printf("\n\t\tNo se puede jugar mientras no defina jugadores");
				break;
			
		}		
}while((a<0 || a>MAX) && (c<0 || c>MAX));
			break;

case CONTINUAR://carga los datos del archivo juegoSyE.ptd y continua la partida
				break;
		
case SALIR://Opcion salir del juego
			printf("\n\n\n\n\t\t\tGRACIAS POR USAR EL PROGRAMA\n");
		default:
				break;
}
	getch();
	}while(opcion!=SALIR);
}

												/************************************
												*	      FUNCIONES             *
												************************************/

/*
* Funcion:esEsc_SER
* Uso:esEsc_SER(jugador[turno]);
* ----------------------------------------------------------
* Descripción:Esta función retorna true si la casilla enviada como parametro representa una
			  escalera o una sepiente caso contrario retorna false
*/
bool esEsc_SER(int casilla)
{	
	int i;
	int Comodin[NUM_SoE]={4,8,15,31,46,48};
	for (i=0;i<NUM_SoE;i++)
	{
		if(casilla==Comodin[i])
			return true;
            	
	}
	return false;
	
}


/*
* Funcion:pasos()
* Uso:pasos();
* ----------------------------------------------------------
* Descripción:Esta función retorna el número de casillas que el jugador en turno tiene que avanzar.
*/
int pasos()
{	
	int dado_1;
	dado_1=1+rand()%6;
	mostrar_dado(dado_1);
	return (dado_1);
}

/*
* Funcion:lanzarDado
* Uso:lanzarDado();
* ----------------------------------------------------------
* Descripción:Esta Retorna un valor valor aleatorio entre 1 y 6 .
*/
int lanzarDado(void)
{
	int dado;	
	dado=1+rand()%6;
	return dado;

}

/*
* Funcion:sgt_turno
* Uso:sgt_turno(turno,sel);	
* ----------------------------------------------------------
* Descripción:Esta función retorna el turno correspondiente al siguiente jugador
*/
int sgt_turno(int turno,int tam)
{
	if(turno==tam-1)
		return 0;		
	else
		return turno+1;
}
/*
* Funcion:aumentar_jugada
* Uso:aumentar_jugada(turno,sel,num_jugadas);
* ----------------------------------------------------------
* Descripción:Esta función retorna el número de la jugada actual aumentada en 1.
*/
int aumentar_jugada(int turno,int tam,int num_jug)
{
	if(turno==0)
		return num_jug+1;
	return num_jug;
}


/*
* Funcion:definirJugadores
* Uso:definirJugadores(void);
* ----------------------------------------------------------
* Descripción:Retorna un entero que en este caso puede ser 1 o 2, que es el número de jugadores definidos por el usuario.
*/
int definirJugadores(void)
{	
	int numjugador;
	do{
		system("cls");
	printf("\n\nInserte el numero de jugadores:");
	scanf("%d",& numjugador);
	}while(numjugador<0 || numjugador>MAX);
	if(numjugador==1)
	{
		return 1;
		}
		else
		{
		if(numjugador==MAX)
		{
		return 2;
		
		}
	}
}

/*
* Funcion:primerJugador
* Uso:primerJugador(a,b);
* ----------------------------------------------------------
* Descripción:Recibe los dos valores de dado que cada jugador recibió al sortear los turnos. 
*/
int primerJugador(void)
{
	int a; 
	int b;
	system("cls");
	a=lanzarDado();
	b=lanzarDado();
	mostrar_dados(a,b);
	if(a==b)
	{
		return 0;
	}
	else
		{
		if(a>b)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
}




												/************************************
												*	      PROCEDIMIENTOS        *
												************************************/



/*
* Procedimiento:mostrar_dados
* Uso:mostrar_dados(dado_1,dado_2);
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra en pantalla el valor de cada dado lanzado.
*/
void mostrar_dados(int dado_1,int dado_2)
{
	printf("\n\t***************************************\n");
	printf("\t*\tDADO 1\t   *\tDADO 2        *\n");
	printf("\t*\tJUGADOR 1  *\tJUGADOR 2     *\n");
	printf("\t*\t=======\t   *\t=======       *\n");
	printf("\t*\t=  %d  =\t   *\t=  %d  =       * \n",dado_1,dado_2);
	printf("\t*\t=======\t   *\t=======       *\n");
	printf("\t***************************************\n");
	return;

}


/*
* Procedimiento:ganador
* Uso:ganador(fin,turno,num_jugadas);
* ----------------------------------------------------------
* Descripción: Este procedimiento Muestra en pantalla el ganador del juego.
*/
void ganador(int turno,int jugadas,char *s)
{
		
		printf("  EL GANADOR ES EL\a\a\n");
		printf("  ======================\n");
		printf("   JUGADOR %d, %s\n",turno+1,s);
		printf("  ======================\n");
		printf("\nSE REALIZARON %d JUGADAS",jugadas);
return;
}


/*
* Procedimiento:posicionJugador
* Uso:posicionJugador(jugador[turno]);
* ----------------------------------------------------------
* Descripción: Este procedimiento Muestra en pantalla un mensaje que indica la posición del jugador en pantalla. 
*			   Si la posición en el tablero tiene alguna representación (Serpiente o escalera) el mensaje también lo 
*			   indicará.
*/
void posicionJugador(int jugador)
{
	int n; 
	printf("Posicion actual %d\n\n",jugador);
	if(esEsc_SER(jugador))
	{
	switch(jugador)
		{	
	case ESCALERA_UNO:
		n=12;
		printf("\nUsted ha caido en una escalera, avanza hasta la casilla %d :)\n",n);
		break;
	case ESCALERA_DOS:
		n=30;
		printf("\nUsted ha caido en una escalera, avanza hasta la casilla %d :)\n",n);
		break;
	case ESCALERA_TRES:
		n=45;
		printf("\nUsted ha caido en una escalera, avanza hasta la casilla %d :)\n",n);
		break;
	case SERPIENTE_UNO:
		n=13;
		printf("\nUsted ha caido en una serpiente, retrocede hasta la casilla %d :(\n",n);
		break;
	case SERPIENTE_DOS:
		n=43;
		printf("\nUsted ha caido en una serpiente, retrocede hasta la casilla %d :(\n",n);
		break;
	case SERPIENTE_TRES:
		n=6;
		printf("\nUsted ha caido en una serpiente, retrocede hasta la casilla %d :(\n",n);
		break;
	default:
		break;
			}
	}
	return;
}




/*
* Procedimiento:mostrar_dado
* Uso:mostrar_dados(dado_1);
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra en pantalla el valor del dado lanzado.
*/
void mostrar_dado(int dado_1)
{
	printf("\n");
	printf("  DADO  \t   \n");
	printf(" =======\t   \n");
	printf(" =  %d  =\t    \n",dado_1);
	printf(" =======\t   \n");
	return;

}


/*
* Procedimiento:encerar
* Uso:encerar(jugador,seleccion);
* ----------------------------------------------------------
* Descripción:Esta Procedimiento llena de ceros un arreglo de tamaño n enviado como parametro.
*/
void encerar(int *valor,int casillas)
{
	int i;
	for(i=0;i<casillas;i++)
		valor[i]=1;
	return;
}


/*
* Procedimiento:tablero
* Uso:tablero();
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra en pantalla un tablero del juego
*/
void dibujaTablero(void)
{
printf("\n  =============================================================\n");
printf("  ||  1||   2||   3||   4||   5||   6||   7||   8||   9||  10||\n");
printf("  ||   ||    ||    || %c%c%c||    ||   %c||    || %c%c%c||    ||    ||\n",35,31,17,21,35,31,16);
printf("  || 11||  12||  13||  14||  15||  16||  17||  18||  19||  20||\n");
printf("  ||   ||   %c||   %c||    ||  %c%c||    ||    ||    ||    ||    ||\n",35,21,35,31);
printf("  || 21||  22||  23||  24||  25||  26||  27||  28||  29||  30||\n");
printf("  ||   ||    ||    ||    ||    ||    ||    ||    ||    ||   %c||\n",35);
printf("  || 31||  32||  33||  34||  35||  36||  37||  38||  39||  40||\n");
printf("  ||%c%c%c||    ||    ||    ||    ||    ||    ||    ||    ||    ||\n",21,30,16);
printf("  || 41||  42||  43||  44||  45||  46||  47||  48||  49||  50||\n");
printf("  ||   ||    ||   %c||    ||   %c||  %c%c||    || %c%c%c||    ||   %c||\n",21,35,21,174,21,17,30,1);
printf("  =============================================================\n");	
}

/*
* Procedimiento:bienvenido
* Uso:bienvenido();
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra en pantalla el nombre del juego
*/
void bienvenido(void)
{
printf(" =========================================================================\n");
printf(" ||\t\tBIENVENIDO AL JUEGO SERPIENTES Y ESCALERA\t\t||\n");
printf(" ========================================================================= \n");
dibujo_EyS();
printf("\n\n\t\tPresione cualquier tecla para continuar");	
getch();
}




/*
* Procedimiento:mostrar_posiciones
* Uso:mostrar_posiciones(jugador,sel);
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra por pantalla los jugadores y sus posiciones en el tablero.
*/
void mostrar_posiciones(int valor[],int casilla)
{
	int i;
		dibujaTablero();
		printf("\n\t\tJUGADOR\tCASILLA\n");
		for(i=0;i<casilla;i++)
			printf("\t\t%d\t%d\n",i+1,valor[i]);
return;
}


/*
* Procedimiento:menuPrincipal
* Uso:menuPrincipal();
* ----------------------------------------------------------
* Descripción:Muestra las opciones del menú
*/

void menuPrincipal(void)
{
	system("cls");
	printf("\t	========================================\n");
	printf("\t	============== \t  MENU\t  ==============\n");
	printf("\t	====      \t          \t    ====\n");
	printf("\t\t====    1. Definir Jugadores  \t    ====\n");
	printf("\t\t====    2. Sortear Turno \t    ====\n");
	printf("\t\t====    3. Nueva Partida \t    ====\n");
	printf("\t\t====    4. Continuar Partida  \t    ====\n");
	printf("\t\t====    5. Salir \t\t    ====\n");
	printf("\t	====      \t          \t    ====\n");
	printf("\t	========================================\n\n");
	printf("\t\t        Escoja una opcion: ");
}


/*
* Procedimiento:Continuar()
* Uso:salir();
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra un menú para seleccionar si continua el juego anterior o juega uno nuevo.
*/
void salir(void)
{
	printf("DESEA CONTINUAR LA PARTIDA ANTERIOR\n\n");
	printf("1.Si\n2.No\n\n");
	printf("escoja una opcion:");

	return;
}
/*
* Procedimiento:Guardar()
* Uso:salir();
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra un menú para seleccionar si guarda o no el juego.
*/

void Guardar(void)
{
	FILE *GUARDA,*CIERRA;
	GUARDA=fopen("juegoSyE.ptd","w");
        	if(GUARDA==NULL)
        	{
        		printf("Error al abrir el archivo\n");
        		getch();
        		exit(1);
        	}
	
}
/*
* Procedimiento:void dibujo_EyS(void)
* Uso:dibujo_EyS();
* ----------------------------------------------------------
* Descripción:Imprime una imagen en ascii de una escalera i una serpiente.
*/
void dibujo_EyS()
{
printf("\t\t\t\t||      ||  **    \n");
printf("\t\t\t\t||      ||  00*	\n");  
printf("\t\t\t\t|////////|  Ç***\n");
printf("\t\t\t\t||      ||    ***	\n");
printf("\t\t\t\t||      ||   ****	\n");
printf("\t\t\t\t|////////|  ****	\n");
printf("\t\t\t\t||      || ****		\n");
printf("\t\t\t\t||      ||  ****	\n");
printf("\t\t\t\t|////////|    ***	\n");
printf("\t\t\t\t||      ||     **	\n");
printf("\t\t\t\t||      ||      *	\n");
}
